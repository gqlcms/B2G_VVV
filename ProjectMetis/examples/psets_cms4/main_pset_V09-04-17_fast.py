import FWCore.ParameterSet.Config as cms

# https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideAboutPythonConfigFile#VarParsing_Documentation
# Allow command line options like
#     cmsRun main_pset.py data=True prompt=True   # prompt data
#     cmsRun main_pset.py data=False               # MC
#     cmsRun main_pset.py fastsim=True             # fastsim
import FWCore.ParameterSet.VarParsing as VarParsing
opts = VarParsing.VarParsing('python')
vpbool = VarParsing.VarParsing.varType.bool
vpstring = VarParsing.VarParsing.varType.string
opts.register('data'    , False  , mytype=vpbool)
opts.register('prompt'  , False  , mytype=vpbool)
opts.register('fastsim' , False , mytype=vpbool)
opts.register('relval'  , False , mytype=vpbool)
opts.register('triginfo'  , False , mytype=vpbool)
opts.register('name'  , "" , mytype=vpstring) # hacky variable to override name for samples where last path/process is "DQM"
opts.parseArguments()

# be smart. if fastsim, it's obviously MC
# if it's MC, it's obviously not prompt
if opts.fastsim: opts.data = False
if not opts.data: opts.prompt = False
print """PSet is assuming:
   data? {}
   prompt? {}
   fastsim? {}
   relval? {}
   triginfo? {}
   name = {}
""".format(bool(opts.data), bool(opts.prompt), bool(opts.fastsim), bool(opts.relval), bool(opts.triginfo), str(opts.name))

import CMS3.NtupleMaker.configProcessName as configProcessName
configProcessName.name="PAT"
if opts.data and opts.prompt:
    configProcessName.name="RECO"

configProcessName.name2="RECO"

if opts.relval:
    if opts.data:
        configProcessName.name="reRECO"
        configProcessName.name2="reRECO"
    else:
        configProcessName.name="RECO"
        configProcessName.name2="RECO"

if opts.fastsim:
    configProcessName.fastSimName="HLT"
    configProcessName.name2=configProcessName.fastSimName
configProcessName.isFastSim=opts.fastsim

if str(opts.name).strip():
    configProcessName.name = str(opts.name).strip()

# CMS3
process = cms.Process("CMS3")

# Version Control For Python Configuration Files
process.configurationMetadata = cms.untracked.PSet(
        version    = cms.untracked.string('$Revision: 1.11 $'),
        annotation = cms.untracked.string('CMS3'),
        name       = cms.untracked.string('CMS3 test configuration')
)

from Configuration.EventContent.EventContent_cff   import *

# load event level configurations
process.load('Configuration/EventContent/EventContent_cff')
process.load("Configuration.StandardSequences.Services_cff")
process.load('Configuration.Geometry.GeometryRecoDB_cff')
# process.load("Configuration.StandardSequences.MagneticField_cff")
# process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
# process.load("Configuration.StandardSequences.GeometryRecoDB_cff")

# services
process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.GlobalTag.globaltag = "80X_mcRun2_asymptotic_2016_miniAODv2_v0" #80X
#process.GlobalTag.globaltag = "91X_upgrade2017_realistic_v5" #MC
#process.GlobalTag.globaltag = "91X_dataRun2_relval_v6" #data
# process.GlobalTag.globaltag = "94X_mc2017_realistic_v14"
process.MessageLogger.cerr.FwkReport.reportEvery = 100
process.MessageLogger.cerr.threshold  = ''
process.MessageLogger.suppressWarning = cms.untracked.vstring('ecalLaserCorrFilter','manystripclus53X','toomanystripclus53X')
# process.options = cms.untracked.PSet( allowUnscheduled = cms.untracked.bool(True),SkipEvent = cms.untracked.vstring('ProductNotFound') )
process.options = cms.untracked.PSet( allowUnscheduled = cms.untracked.bool(False) )

process.out = cms.OutputModule("PoolOutputModule",
                               fileName     = cms.untracked.string('ntuple.root'),
                               # fileName     = cms.untracked.string('ntuple2.root'),
                               dropMetaData = cms.untracked.string("ALL"),
                               # basketSize = cms.untracked.int32(16384*150)
                               # basketSize = cms.untracked.int32(16384*10)
                               basketSize = cms.untracked.int32(16384*23)
)

########    override the GT for MC     ########
### ESPrefer for L1TGlobalPrescalesVetosRcd ###
if not opts.data:
    process.load("CondCore.CondDB.CondDB_cfi")
    process.CondDB.connect = "frontier://FrontierProd/CMS_CONDITIONS"
    process.l1tPS = cms.ESSource("PoolDBESSource",
        process.CondDB,
        toGet = cms.VPSet(
            cms.PSet(
            record = cms.string("L1TGlobalPrescalesVetosRcd"),
            tag = cms.string("L1TGlobalPrescalesVetos_passThrough_mc")
            )
        )
    )
    process.es_prefer_l1tPS = cms.ESPrefer("PoolDBESSource", "l1tPS")
# tag from https://cms-conddb.cern.ch/cmsDbBrowser/list/Prod/gts/92X_upgrade2017_realistic_v2

#load cff and third party tools
from JetMETCorrections.Configuration.DefaultJEC_cff import *
from JetMETCorrections.Configuration.JetCorrectionServices_cff import *
from JetMETCorrections.Configuration.CorrectedJetProducersDefault_cff import *
from JetMETCorrections.Configuration.CorrectedJetProducers_cff import *
from JetMETCorrections.Configuration.CorrectedJetProducersAllAlgos_cff import *
process.load('JetMETCorrections.Configuration.DefaultJEC_cff')
# from RecoJets.JetProducers.fixedGridRhoProducerFastjet_cfi import *
# process.fixedGridRhoFastjetAll = fixedGridRhoFastjetAll.clone(pfCandidatesTag = 'packedPFCandidates')

#Electron Identification for PHYS 14
from PhysicsTools.SelectorUtils.tools.vid_id_tools import *  
from PhysicsTools.SelectorUtils.centralIDRegistry import central_id_registry
process.load("RecoEgamma.ElectronIdentification.egmGsfElectronIDs_cfi")
process.load("RecoEgamma.ElectronIdentification.ElectronMVAValueMapProducer_cfi")
process.egmGsfElectronIDs.physicsObjectSrc = cms.InputTag('slimmedElectrons',"",configProcessName.name)
process.electronMVAValueMapProducer.srcMiniAOD = cms.InputTag('slimmedElectrons',"",configProcessName.name)
process.egmGsfElectronIDSequence = cms.Sequence(process.electronMVAValueMapProducer * process.egmGsfElectronIDs)
my_id_modules = [
        # 'RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_Spring15_25ns_V1_cff',
        # 'RecoEgamma.ElectronIdentification.Identification.heepElectronID_HEEPV60_cff',
        # 'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring15_25ns_nonTrig_V1_cff',
        # 'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring15_25ns_Trig_V1_cff',
        # 'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring16_GeneralPurpose_V1_cff',
        # 'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring16_HZZ_V1_cff',
        # 'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Fall17_iso_V1_cff',
        # 'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Fall17_noIso_V1_cff',
                 ]
for idmod in my_id_modules:
    setupAllVIDIdsInModule(process,idmod,setupVIDElectronSelection)

# Load Ntuple producer cff
process.load("CMS3.NtupleMaker.cms3CoreSequences_cff")
if not opts.data: process.load("CMS3.NtupleMaker.cms3GENSequence_cff")
process.load("CMS3.NtupleMaker.cms3PFSequence_cff")
process.eventMaker.isData                        = cms.bool(opts.data)
    
# if do_deepbtag:
#     from PhysicsTools.PatAlgos.tools.jetTools import *
#     deep_discriminators = ["pfDeepCSVJetTags:probudsg", "pfDeepCSVJetTags:probb", "pfDeepCSVJetTags:probc", "pfDeepCSVJetTags:probbb", "pfDeepCSVJetTags:probcc" ]
#     updateJetCollection(
#         process,
#         jetSource = cms.InputTag('slimmedJets'),
#        jetCorrections = ('AK4PFchs', cms.vstring([]), 'None'),
#         btagDiscriminators = deep_discriminators
#     )
#     updateJetCollection(
#         process,
#         labelName = 'Puppi',
#         jetSource = cms.InputTag('slimmedJetsPuppi'),
#        jetCorrections = ('AK4PFchs', cms.vstring([]), 'None'),
#         btagDiscriminators = deep_discriminators
#     )

    # Needed for the above updateJetCollection() calls
    # process.pfJetMaker.pfJetsInputTag = cms.InputTag('selectedUpdatedPatJets')
    # process.pfJetPUPPIMaker.pfJetsInputTag = cms.InputTag('selectedUpdatedPatJetsPuppi')

# Hypothesis cuts
process.hypDilepMaker.TightLepton_PtCut  = cms.double(10.0)
process.hypDilepMaker.LooseLepton_PtCut  = cms.double(10.0)

#Options for Input
process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
                                '/store/mc/RunIIFall17MiniAODv2/DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/20000/107259EC-3D42-E811-9ECA-0CC47A4C8F12.root',
                            )
)
process.source.noEventSort = cms.untracked.bool( True )

#Max Events
# process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(50) )
# process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(3000) )
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )


#Run corrected MET maker

#configurable options =======================================================================
usePrivateSQlite=False #use external JECs (sqlite file)
applyResiduals=opts.data #application of residual corrections. Have to be set to True once the 13 TeV residual corrections are available. False to be kept meanwhile. Can be kept to False later for private tests or for analysis checks and developments (not the official recommendation!).
#===================================================================

if usePrivateSQlite:
    from CondCore.DBCommon.CondDBSetup_cfi import *
    import os
    era="Summer15_25nsV5_MC"
    process.jec = cms.ESSource("PoolDBESSource",CondDBSetup,
                               connect = cms.string( "sqlite_file:"+era+".db" ),
                               toGet =  cms.VPSet(
            cms.PSet(
                record = cms.string("JetCorrectionsRecord"),
                tag = cms.string("JetCorrectorParametersCollection_"+era+"_AK4PF"),
                label= cms.untracked.string("AK4PF")
                ),
            cms.PSet(
                record = cms.string("JetCorrectionsRecord"),
                tag = cms.string("JetCorrectorParametersCollection_"+era+"_AK4PFchs"),
                label= cms.untracked.string("AK4PFchs")
                ),
            )
                               )
    process.es_prefer_jec = cms.ESPrefer("PoolDBESSource",'jec')

### =================================================================================
#jets are rebuilt from those candidates by the tools, no need to do anything else
### =================================================================================

process.outpath = cms.EndPath(process.out)
process.out.outputCommands = cms.untracked.vstring( 'drop *' )

if not opts.data:
    from PhysicsTools.PatUtils.tools.runMETCorrectionsAndUncertainties import runMetCorAndUncFromMiniAOD
    #default configuration for miniAOD reprocessing, change the isData flag to run on data
    #for a full met computation, remove the pfCandColl input
    runMetCorAndUncFromMiniAOD(process,
                               isData=opts.data,
                               )

process.out.outputCommands = cms.untracked.vstring( 'drop *' )
# process.out.outputCommands.extend(cms.untracked.vstring('keep *_*Maker*_*_CMS3*'))
process.out.outputCommands.extend(cms.untracked.vstring('keep *_*muonMaker*_*_CMS3*')) # FIXME NOTE

### -------------------------------------------------------------------
### the lines below remove the L2L3 residual corrections when processing data
### -------------------------------------------------------------------
if not applyResiduals:
    process.patPFMetT1T2Corr.jetCorrLabelRes = cms.InputTag("L3Absolute")
    process.patPFMetT1T2SmearCorr.jetCorrLabelRes = cms.InputTag("L3Absolute")
    process.patPFMetT2Corr.jetCorrLabelRes = cms.InputTag("L3Absolute")
    process.patPFMetT2SmearCorr.jetCorrLabelRes = cms.InputTag("L3Absolute")
    process.shiftedPatJetEnDown.jetCorrLabelUpToL3Res = cms.InputTag("ak4PFCHSL1FastL2L3Corrector")
    process.shiftedPatJetEnUp.jetCorrLabelUpToL3Res = cms.InputTag("ak4PFCHSL1FastL2L3Corrector")
### ------------------------------------------------------------------

# end Run corrected MET maker

# Extra trigger information (matching)
if opts.triginfo:
    process.load("CMS3.NtupleMaker.muToTrigAssMaker_cfi")
    process.load("CMS3.NtupleMaker.elToTrigAssMaker_cfi")
    if opts.data and opts.prompt:
        # process.muToTrigAssMaker.processName = cms.untracked.string("RECO")
        # process.elToTrigAssMaker.processName = cms.untracked.string("RECO")
        process.muToTrigAssMaker.triggerObjectsName = cms.untracked.string("slimmedPatTrigger")
        process.elToTrigAssMaker.triggerObjectsName = cms.untracked.string("slimmedPatTrigger")
        process.hltMaker.triggerObjectsName = cms.untracked.string("slimmedPatTrigger")
    process.hltMaker.fillTriggerObjects = cms.untracked.bool(True)

# python -c "from PhysicsTools.NanoAOD.electrons_cff import isoForEle; print 'process.isoForEle = {}'.format(repr(isoForEle))"
# below from CMSSW_9_4_6_patch1
process.isoForEle = cms.EDProducer("EleIsoValueMapProducer",
    EAFile_MiniIso = cms.FileInPath('RecoEgamma/ElectronIdentification/data/Fall17/effAreaElectrons_cone03_pfNeuHadronsAndPhotons_92X.txt'),
    EAFile_PFIso = cms.FileInPath('RecoEgamma/ElectronIdentification/data/Fall17/effAreaElectrons_cone03_pfNeuHadronsAndPhotons_92X.txt'),
    relative = cms.bool(False),
    rho_MiniIso = cms.InputTag("fixedGridRhoFastjetAll"),
    rho_PFIso = cms.InputTag("fixedGridRhoFastjetAll"),
    src = cms.InputTag("slimmedElectrons")
)
# python -c "from PhysicsTools.NanoAOD.muons_cff import isoForMu; print 'process.isoForMu = {}'.format(repr(isoForMu))"
# below from CMSSW_9_4_6_patch1
process.isoForMu = cms.EDProducer("MuonIsoValueMapProducer",
    EAFile_MiniIso = cms.FileInPath('PhysicsTools/NanoAOD/data/effAreaMuons_cone03_pfNeuHadronsAndPhotons_94X.txt'),
    relative = cms.bool(False),
    rho_MiniIso = cms.InputTag("fixedGridRhoFastjetAll"),
    src = cms.InputTag("slimmedMuons")
)

process.TransientTrackBuilderESProducer = cms.ESProducer("TransientTrackBuilderESProducer",
    ComponentName=cms.string('TransientTrackBuilder')
)

process.p = cms.Path( 
    # process.metFilterMaker *
    # process.egmGsfElectronIDSequence *     
    # process.vertexMaker *
    # process.secondaryVertexMaker *
    process.eventMaker *
    # process.pfCandidateMaker *
    # process.isoTrackMaker *
    # process.isoForEle * 
    process.isoForMu *
    # process.electronMaker *
    process.muonMaker
    # process.pfJetMaker *
    # process.pfJetPUPPIMaker *
    # process.subJetMaker *
    # process.pfmetMaker *
    # process.pfmetpuppiMaker *
    # process.hltMakerSequence *
    # process.miniAODrhoSequence *
    # process.pftauMaker *
    # process.photonMaker *
    # process.genMaker *
    # process.genJetMaker *
    # process.candToGenAssMaker * # requires electronMaker, muonMaker, pfJetMaker, photonMaker
    # process.pdfinfoMaker *
    # process.puSummaryInfoMaker *
    # process.hypDilepMaker
)
if opts.triginfo:
    # Now insert the xToTrigAssMakers into the path
    # Hooray for hacky operations
    process.p.insert(process.p.index(process.photonMaker)+1,process.muToTrigAssMaker)
    process.p.insert(process.p.index(process.photonMaker)+1,process.elToTrigAssMaker)

print process.p
print process

process.MessageLogger.cerr.FwkReport.reportEvery = 100

process.Timing = cms.Service("Timing",
        summaryOnly = cms.untracked.bool(True)
        )

# FIXME NOTE
# process.CondorStatusService = cms.Service("CondorStatusService", tag="cms4jobs")
process.add_(cms.Service("CondorStatusService", tag=cms.untracked.string("cms4jobs")))


# for use with Valgrind. After enabling, can do
# $ valgrind --leak-check=yes  cmsRun main_pset.py >& log.txt
# $ valgrindMemcheckParser.pl --preset=prod,-prod1+ log.txt  > blah.html
# process.ProfilerService = cms.Service (
#         "ProfilerService",
#         firstEvent = cms.untracked.int32(2),
#         lastEvent = cms.untracked.int32(10),
#         paths = cms.untracked.vstring('p1')
# )


# process.GlobalTag.globaltag = "SUPPLY_GLOBAL_TAG"
# process.out.fileName = cms.untracked.string('SUPPLY_OUTPUT_FILE_NAME'),
# process.source.fileNames = cms.untracked.vstring('SUPPLY_INPUT_FILE_NAME')
# process.eventMaker.CMS3tag = cms.string('SUPPLY_CMS3_TAG')
# process.eventMaker.datasetName = cms.string('SUPPLY_DATASETNAME')
# process.maxEvents.input = cms.untracked.int32(SUPPLY_MAX_NEVENTS)

#process.GlobalTag.globaltag = "94X_mc2017_realistic_v14"
#process.out.fileName = cms.untracked.string('ntuple.root')
#process.source.fileNames = cms.untracked.vstring('/store/mc/RunIIFall17MiniAODv2/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/2A527C69-0842-E811-87B0-008CFAE45450.root')
##process.source.fileNames = cms.untracked.vstring('/store/data/Run2017D/SingleMuon/MINIAOD/31Mar2018-v1/80000/1E703527-F436-E811-80A7-E0DB55FC1055.root')
##process.source.fileNames = cms.untracked.vstring('/store/data/Run2016C/MuonEG/MINIAOD/17Jul2018-v1/50000/E039F2A0-228C-E811-AE2F-A0369FE2C22E.root')
#process.eventMaker.CMS3tag = cms.string('test')
#process.eventMaker.datasetName = cms.string('/MuonEG/Run2016C-17Jul2018-v1/MINIAOD')
#process.maxEvents.input = cms.untracked.int32(1000)

# process.GlobalTag.globaltag = "94X_dataRun2_ReReco_EOY17_v6"
process.out.fileName = cms.untracked.string('ntuple.root')
process.source.fileNames = cms.untracked.vstring('/store/data/Run2017E/SingleMuon/MINIAOD/31Mar2018-v1/90000/D8B2ED96-AB37-E811-8A8B-0025905A60E4.root')
#process.source.fileNames = cms.untracked.vstring('/store/data/Run2016C/MuonEG/MINIAOD/17Jul2018-v1/50000/E039F2A0-228C-E811-AE2F-A0369FE2C22E.root')
process.eventMaker.CMS3tag = cms.string('test')
process.eventMaker.datasetName = cms.string('/MuonEG/Run2016C-17Jul2018-v1/MINIAOD')
process.maxEvents.input = cms.untracked.int32(1000)


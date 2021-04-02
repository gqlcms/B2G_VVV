#include "Begin_Common.h"

void Begin_Common()
{
    //==============================================
    // Begin_Common:
    // This function gets called prior to the event looping.
    // This is where one declares variables, histograms, event selections for the category Common.
    //==============================================

    // Create variables used in this category.
    // Please follow the convention of <category>_<varname> structure.
    Begin_Common_Create_Branches();

    // Determine whether it is EFT or not
    Begin_Common_Determine_Is_EFT();

    // The framework may run over NanoAOD directly or, it may run over VVVTree.
    // ana.run_VVVTree boolean determines this.
    if (ana.run_VVVTree)
    {
        Begin_Common_VVVTree();
    }
    else
    {
        Begin_Common_NanoAOD();
    }

}

void Begin_Common_Create_Branches()
{
    // Event level information
    ana.tx.createBranch<int>                  ("Common_isData");
    ana.tx.createBranch<int>                  ("Common_run");
    ana.tx.createBranch<int>                  ("Common_lumi");
    ana.tx.createBranch<unsigned long long>   ("Common_evt");
    ana.tx.createBranch<float>                ("Common_genWeight");
    ana.tx.createBranch<float>                ("Common_btagWeight_DeepCSVB");

    // EFT weightings
    ana.tx.createBranch<vector<float>>        ("Common_LHEWeight_mg_reweighting");

    // 2016 only triggers
    ana.tx.createBranch<bool>                 ("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ"); // Lowest unprescaled
    ana.tx.createBranch<bool>                 ("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL"); // Lowest unprescaled
    // The rest of the triggers
    ana.tx.createBranch<bool>                 ("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8"); // Lowest unprescaled for >= 2017C
    ana.tx.createBranch<bool>                 ("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");
    ana.tx.createBranch<bool>                 ("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL"); // Lowest unprescaled
    ana.tx.createBranch<bool>                 ("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ"); // Lowest unprescaled
    ana.tx.createBranch<bool>                 ("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL");
    ana.tx.createBranch<bool>                 ("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ"); // Lowest unprescaled
    ana.tx.createBranch<bool>                 ("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL");
    // Summary triggers
    ana.tx.createBranch<bool>                 ("Common_HLT_DoubleEl");
    ana.tx.createBranch<bool>                 ("Common_HLT_MuEG");
    ana.tx.createBranch<bool>                 ("Common_HLT_DoubleMu");

    ana.tx.createBranch<bool>                 ("Common_pass_duplicate_removal_ee_em_mm"); // Flag to identify whether the event passes duplicate removal
    ana.tx.createBranch<bool>                 ("Common_pass_duplicate_removal_mm_em_ee"); // Flag to identify whether the event passes duplicate removal
    ana.tx.createBranch<bool>                 ("Common_noiseFlag");                       // Flag to identify noise
    ana.tx.createBranch<bool>                 ("Common_noiseFlagMC");                     // Flag to identify noise

    // Summary 4 vectors of the objects selected
    ana.tx.createBranch<LorentzVector>        ("Common_met_p4");
    
    ana.tx.createBranch<float>                ("Common_event_lepSF");      // lepSF
    ana.tx.createBranch<float>                ("Common_event_lepSFelup");  // lepSF
    ana.tx.createBranch<float>                ("Common_event_lepSFeldn");  // lepSF
    ana.tx.createBranch<float>                ("Common_event_lepSFmuup");  // lepSF
    ana.tx.createBranch<float>                ("Common_event_lepSFmudn");  // lepSF

    ana.tx.createBranch<vector<LorentzVector>>("Common_lep_p4");        // Pt sorted selected lepton p4s (electrons and muons together)
    ana.tx.createBranch<vector<int>>          ("Common_lep_idxs");      // Pt sorted selected lepton idxs (electrons and muons together)
    ana.tx.createBranch<vector<int>>          ("Common_lep_pdgid");     // Pt sorted selected lepton pdgids (so that Common_lep_idxs can be used to access NanoAOD)
    ana.tx.createBranch<vector<int>>          ("Common_lep_tight");     // Pt sorted selected lepton tight (Where a tight version of the lepton isolation is used to reduce bkg a bit further if necessary)
    ana.tx.createBranch<vector<float>>        ("Common_lep_dxy");       // Pt sorted selected lepton dxy (electrons and muons together)
    ana.tx.createBranch<vector<float>>        ("Common_lep_dz");        // Pt sorted selected lepton dz (electrons and muons together)
    ana.tx.createBranch<vector<float>>        ("Common_lep_ip3d");      // Pt sorted selected lepton ip3d (electrons and muons together)
    ana.tx.createBranch<vector<float>>        ("Common_lep_sip3d");     // Pt sorted selected lepton sip3d (electrons and muons together)
    ana.tx.createBranch<vector<float>>        ("Common_lep_SF");        // SF
    ana.tx.createBranch<vector<float>>        ("Common_lep_SFTight");   // SF tight iso
    ana.tx.createBranch<vector<float>>        ("Common_lep_SFdn");      // SF
    ana.tx.createBranch<vector<float>>        ("Common_lep_SFdnTight"); // SF tight iso
    ana.tx.createBranch<vector<float>>        ("Common_lep_SFup");      // SF
    ana.tx.createBranch<vector<float>>        ("Common_lep_SFupTight"); // SF tight iso

    // Jet variables
    ana.tx.createBranch<vector<LorentzVector>>("Common_jet_p4");            // Pt sorted selected jet p4s
    ana.tx.createBranch<vector<int>>          ("Common_jet_idxs");          // Pt sorted selected jet idxs (To access rest of the jet variables in NanoAOD)
    ana.tx.createBranch<vector<bool>>         ("Common_jet_passBloose");    // Pt sorted selected jet idxs (To access rest of the jet variables in NanoAOD)
    ana.tx.createBranch<vector<bool>>         ("Common_jet_passBmedium");   // Pt sorted selected jet idxs (To access rest of the jet variables in NanoAOD)
    ana.tx.createBranch<vector<bool>>         ("Common_jet_passBtight");    // Pt sorted selected jet idxs (To access rest of the jet variables in NanoAOD)
    //ana.tx.createBranch<vector<float>>        ("Common_jet_bSFLoose");      // single jet bSF
    //ana.tx.createBranch<vector<float>>        ("Common_jet_bSFMedium");     // single jet bSF
    //ana.tx.createBranch<vector<float>>        ("Common_jet_bSFTight");      // single jet bSF
    //ana.tx.createBranch<vector<float>>        ("Common_jet_bSFdnLoose");    // single jet bSF
    //ana.tx.createBranch<vector<float>>        ("Common_jet_bSFdnMedium");   // single jet bSF
    //ana.tx.createBranch<vector<float>>        ("Common_jet_bSFdnTight");    // single jet bSF
    //ana.tx.createBranch<vector<float>>        ("Common_jet_bSFupLoose");    // single jet bSF
    //ana.tx.createBranch<vector<float>>        ("Common_jet_bSFupMedium");   // single jet bSF
    //ana.tx.createBranch<vector<float>>        ("Common_jet_bSFupTight");    // single jet bSF
    ana.tx.createBranch<vector<int>>          ("Common_jet_overlapfatjet"); // Pt sorted selected jet idxs (To access rest of the jet variables in NanoAOD)

    // Fat jet variables
    ana.tx.createBranch<vector<LorentzVector>>("Common_fatjet_p4");            // Pt sorted selected fatjet p4s
    ana.tx.createBranch<vector<int>>          ("Common_fatjet_idxs");          // Pt sorted selected fatjet idxs (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_msoftdrop");     // Pt sorted selected fatjet msoftdrop (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_deepMD_W");      // Pt sorted selected fatjet FatJet_deepTagMD_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_deep_W");        // Pt sorted selected fatjet FatJet_deepTag_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_deepMD_Z");      // Pt sorted selected fatjet FatJet_deepTagMD_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_deep_Z");        // Pt sorted selected fatjet FatJet_deepTag_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_deepMD_T");      // Pt sorted selected fatjet FatJet_deepTagMD_TvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_deep_T");        // Pt sorted selected fatjet FatJet_deepTag_TvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_deepMD_bb");     // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_tau3");          // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_tau2");          // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_tau1");          // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_tau32");         // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_tau21");         // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_subjet0_pt");    // Pt sorted selected fatjet subjet p4 0 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_subjet0_eta");   // Pt sorted selected fatjet subjet p4 0 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_subjet0_phi");   // Pt sorted selected fatjet subjet p4 0 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_subjet0_mass");  // Pt sorted selected fatjet subjet p4 0 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_subjet1_pt");    // Pt sorted selected fatjet subjet p4 1 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_subjet1_eta");   // Pt sorted selected fatjet subjet p4 2 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_subjet1_phi");   // Pt sorted selected fatjet subjet p4 3 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_subjet1_mass");  // Pt sorted selected fatjet subjet p4 4 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<LorentzVector>>("Common_fatjet_subjet0_p4");    // Pt sorted selected fatjet p4s
    ana.tx.createBranch<vector<LorentzVector>>("Common_fatjet_subjet1_p4");    // Pt sorted selected fatjet p4s
    ana.tx.createBranch<vector<int>>          ("Common_fatjet_WP");            // WP: 0: VLoose (5%), 1: Loose (2.5%), 2: Medium (1%), 3: Tight (0.5%)
    ana.tx.createBranch<vector<int>>          ("Common_fatjet_WP_antimasscut");// WP: 0: VLoose (5%), 1: Loose (2.5%), 2: Medium (1%), 3: Tight (0.5%)
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_SFVLoose");      // single fatjet SF
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_SFLoose");       // single fatjet SF
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_SFMedium");      // single fatjet SF
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_SFTight");       // single fatjet SF
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_SFdnVLoose");    // single fatjet SF
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_SFdnLoose");     // single fatjet SF
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_SFdnMedium");    // single fatjet SF
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_SFdnTight");     // single fatjet SF
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_SFupVLoose");    // single fatjet SF
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_SFupLoose");     // single fatjet SF
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_SFupMedium");    // single fatjet SF
    ana.tx.createBranch<vector<float>>        ("Common_fatjet_SFupTight");     // single fatjet SF
    ana.tx.createBranch<float>        ("Common_eventweight_fatjet_SFVLoose");      // event fatjet SF
    ana.tx.createBranch<float>        ("Common_eventweight_fatjet_SFLoose");       // event fatjet SF
    ana.tx.createBranch<float>        ("Common_eventweight_fatjet_SFMedium");      // event fatjet SF
    ana.tx.createBranch<float>        ("Common_eventweight_fatjet_SFTight");       // event fatjet SF
    ana.tx.createBranch<float>        ("Common_eventweight_fatjet_SFdnVLoose");    // event fatjet SF
    ana.tx.createBranch<float>        ("Common_eventweight_fatjet_SFdnLoose");     // event fatjet SF
    ana.tx.createBranch<float>        ("Common_eventweight_fatjet_SFdnMedium");    // event fatjet SF
    ana.tx.createBranch<float>        ("Common_eventweight_fatjet_SFdnTight");     // event fatjet SF
    ana.tx.createBranch<float>        ("Common_eventweight_fatjet_SFupVLoose");    // event fatjet SF
    ana.tx.createBranch<float>        ("Common_eventweight_fatjet_SFupLoose");     // event fatjet SF
    ana.tx.createBranch<float>        ("Common_eventweight_fatjet_SFupMedium");    // event fatjet SF
    ana.tx.createBranch<float>        ("Common_eventweight_fatjet_SFupTight");     // event fatjet SF

    // The n-loose b-tagged jets
    ana.tx.createBranch<int>                  ("Common_nb_loose");    // DeepFlav-B loose nb
    ana.tx.createBranch<int>                  ("Common_nb_medium");   // DeepFlav-B medium nb
    ana.tx.createBranch<int>                  ("Common_nb_tight");    // DeepFlav-B tight nb

    // The gen level information
    ana.tx.createBranch<vector<int>>          ("Common_gen_idx");        // Selected gen-particle idx in NanoAOD
    ana.tx.createBranch<vector<int>>          ("Common_gen_mother_idx"); // Selected gen-particle mother idx in NanoAOD
    ana.tx.createBranch<vector<int>>          ("Common_gen_mother_id");  // Selected gen-particle mother id in NanoAOD
    ana.tx.createBranch<vector<int>>          ("Common_gen_pdgid");      // Selected gen-particle pdgids
    ana.tx.createBranch<vector<LorentzVector>>("Common_gen_p4s");        // Selected gen-particle p4s

    ana.tx.createBranch<vector<int>>          ("Common_gen_vvvdecay_idx");          // Selected gen-particle of vvv decays idx in NanoAOD
    ana.tx.createBranch<vector<int>>          ("Common_gen_vvvdecay_mother_idx");   // Selected gen-particle of vvv decays mother idx in NanoAOD
    ana.tx.createBranch<vector<int>>          ("Common_gen_vvvdecay_mother_id");    // Selected gen-particle of vvv decays mother id in NanoAOD
    ana.tx.createBranch<vector<int>>          ("Common_gen_vvvdecay_pdgid");        // Selected gen-particle of vvv decays pdgids
    ana.tx.createBranch<vector<LorentzVector>>("Common_gen_vvvdecay_p4s");          // Selected gen-particle of vvv decays p4s
    ana.tx.createBranch<vector<int>>          ("Common_gen_vvvdecay_taudecayid");   // If gentau - flag the decay of the gentau

    ana.tx.createBranch<int>                  ("Common_n_W");
    ana.tx.createBranch<int>                  ("Common_n_Z");
    ana.tx.createBranch<int>                  ("Common_n_lep_Z");
    ana.tx.createBranch<int>                  ("Common_n_leptau_Z");
    ana.tx.createBranch<int>                  ("Common_n_hadtau_Z");
    ana.tx.createBranch<int>                  ("Common_n_nu_Z");
    ana.tx.createBranch<int>                  ("Common_n_b_Z");
    ana.tx.createBranch<int>                  ("Common_n_lep_W");
    ana.tx.createBranch<int>                  ("Common_n_leptau_W");
    ana.tx.createBranch<int>                  ("Common_n_hadtau_W");
    ana.tx.createBranch<bool>                 ("Common_haslepWSS");  // includes leptonic tau decays

    ana.tx.createBranch<float>                ("Common_genHT");       // Gen HT value for stitching HT-sliced samples
    ana.tx.createBranch<int>                  ("Common_gen_n_light_lep"); // Gen value of how many light lepton exists
    ana.tx.createBranch<int>                  ("Common_gen_VH_channel"); // VH Channel (0 = WH->WWW, 1 = ZH->ZWW, 2 = WH->WZZ, 3 = ZH->ZZZ, -PDGID = if another channel, and is H->tautau then it would be -15.)

}

void Begin_Common_Determine_Is_EFT()
{
    if (ana.run_VVVTree)
    {
        // Determine whether the sample being run over is a EFT sample or not by checking whether a branch exist with the name "LHEWeight_mg_reweighting"
        ana.is_EFT_sample = vvv.Common_LHEWeight_mg_reweighting().size() > 0; // If there are weights it's is EFT
    }
    else
    {
        // Determine whether the sample being run over is a EFT sample or not by checking whether a branch exist with the name "LHEWeight_mg_reweighting"
        ana.is_EFT_sample = false; // default is false
        TObjArray* brobjArray = ana.events_tchain->GetListOfBranches();
        for (unsigned int ibr = 0; ibr < (unsigned int) brobjArray->GetEntries(); ++ibr)
        {
            TString brname = brobjArray->At(ibr)->GetName();
            if (brname.EqualTo("LHEWeight_mg_reweighting"))
                ana.is_EFT_sample = true; // if it has the branch it is set to true
        }
    }

}

void Begin_Common_VVVTree()
{

    // Define basic selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.addCut("Wgt", [&]() { return 1; }, [&]() { if (not vvv.Common_isData()) return (vvv.Common_genWeight() > 0) - (vvv.Common_genWeight() < 0); else return 1; } );
    ana.cutflow.addCutToLastActiveCut("SelectVH", [&]() { return (ana.vhvvv_channel < 0 ? true: ana.vhvvv_channel == vvv.Common_gen_VH_channel());}, UNITY );
    ana.cutflow.addCutToLastActiveCut("CommonCut", [&]() { return 1;}, [&]() { return 1; } );

}

void Begin_Common_NanoAOD()
{

    // Define basic selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.addCut("Wgt", [&]() { return 1; }, [&]() { if (not nt.isData()) return (nt.genWeight() > 0) - (nt.genWeight() < 0); else return 1; } );
    ana.cutflow.addCutToLastActiveCut("SelectVH", [&]() { return (ana.vhvvv_channel < 0 ? true: ana.vhvvv_channel == ana.tx.getBranchLazy<int>("Common_gen_VH_channel"));}, UNITY );
    ana.cutflow.addCutToLastActiveCut("CommonCut", [&]() { return 1;}, [&]() { return 1; } );

    // Various book keeping variables are included here.
    // TODO: Define some diagnostic basic plots

    Begin_Common_Book_NEvent_Histograms();

    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    RooUtil::Histograms hists_Common;
    hists_Common.addHistogram("h_Common_nLep", 10, 0, 10, [&]() { return ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size(); } );
    hists_Common.addHistogram("h_Common_nJet", 10, 0, 10, [&]() { return ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size(); } );
    hists_Common.addHistogram("h_Common_nFatJet", 10, 0, 10, [&]() { return ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); } );
    hists_Common.addHistogram("h_Common_nGenW", 100, 0, 100, [&]() { return (ana.tx.getBranchLazy<int>("Common_n_W")>=0 ? (ana.tx.getBranchLazy<int>("Common_n_W") +ana.tx.getBranchLazy<int>("Common_n_lep_W")+ana.tx.getBranchLazy<int>("Common_n_leptau_W")+ana.tx.getBranchLazy<int>("Common_n_hadtau_W")+ (ana.tx.getBranchLazy<int>("Common_n_lep_W")>0 ? 3:0) + (ana.tx.getBranchLazy<int>("Common_n_leptau_W")>0 ? 9:0) + (ana.tx.getBranchLazy<int>("Common_n_hadtau_W")>0 ? 21:0) +(ana.tx.getBranchLazy<bool>("haslepWSS") ? 46:0)) : -999); });
    hists_Common.addHistogram("h_Common_nGenZ", 300, 0, 300, [&]() { return (ana.tx.getBranchLazy<int>("Common_n_Z")>=0 ? (ana.tx.getBranchLazy<int>("Common_n_Z") +ana.tx.getBranchLazy<int>("Common_n_lep_Z")+ana.tx.getBranchLazy<int>("Common_n_leptau_Z")+ana.tx.getBranchLazy<int>("Common_n_hadtau_Z")+ana.tx.getBranchLazy<int>("Common_n_nu_Z")+ana.tx.getBranchLazy<int>("Common_n_b_Z")+ (ana.tx.getBranchLazy<int>("Common_n_lep_Z")>0 ? 3:0) + (ana.tx.getBranchLazy<int>("Common_n_leptau_Z")>0 ? 12:0) + (ana.tx.getBranchLazy<int>("Common_n_hadtau_Z")>0 ? 30:0) + (ana.tx.getBranchLazy<int>("Common_n_nu_Z")>0 ? 67:0) + (ana.tx.getBranchLazy<int>("Common_n_b_Z")>0 ? 140:0) ) : -999); });
    hists_Common.addHistogram("h_Common_isSS", 2, 0, 2, [&]() { return (ana.tx.getBranchLazy<int>("Common_n_W")>=0 ? (ana.tx.getBranchLazy<bool>("Common_haslepWSS") ? 1. : 0.) : -999.); } );

    // Book histograms to cuts that user wants for this category.
    ana.cutflow.bookHistogramsForCut(hists_Common, "CommonCut");

    // EFT reweighting histogram
    RooUtil::Histograms n_lhe_weight;
    if (ana.is_EFT_sample)
    {
        n_lhe_weight.addVecHistogram("h_Common_LHEWeight_mg_reweighting", 60, 0, 60, [&]() { std::vector<float> rtn; for (unsigned int i = 0; i < nt.LHEWeight_mg_reweighting().size(); ++i) rtn.push_back(i); return rtn; }, [&]() { std::vector<float> rtn(nt.LHEWeight_mg_reweighting().begin(), nt.LHEWeight_mg_reweighting().end()); return rtn; } );
        n_lhe_weight.addVecHistogram("h_Common_LHEWeight_mg_reweighting_times_genWeight", 60, 0, 60, [&]() { std::vector<float> rtn; for (unsigned int i = 0; i < nt.LHEWeight_mg_reweighting().size(); ++i) rtn.push_back(i); return rtn; }, [&]() { std::vector<float> rtnx; for (unsigned int i = 0; i < nt.LHEWeight_mg_reweighting().size(); ++i) rtnx.push_back(nt.LHEWeight_mg_reweighting()[i]*nt.genWeight()); return rtnx; } );
    }
    if (not nt.isData())
    {
        n_lhe_weight.addVecHistogram("h_Common_genWeight", 1, 0, 1, [&]() { std::vector<float> rtn; rtn.push_back(0); return rtn; }, [&]() { std::vector<float> rtnx; rtnx.push_back(nt.genWeight()); return rtnx; } );
    }

    // Book the EFT reweighting histogram counter
    ana.cutflow.bookHistogramsForCut(n_lhe_weight, "Root");

}

void Begin_Common_Book_NEvent_Histograms()
{
    if (ana.input_file_list_tstring.Contains("NanoSkim"))
    {
        ana.output_tfile->cd();
        TH1F* Root__h_nevents = new TH1F("Root__h_nevents", "Root__h_nevents", 1, 0, 1);
        TH1F* Wgt__h_nevents = new TH1F("Wgt__h_nevents", "Wgt__h_nevents", 1, 0, 1);

        TObjArray* input_files = ana.input_file_list_tstring.Tokenize(",");
        int total = 0;
        int pos_total = 0;
        int neg_total = 0;
        for (int ifile = 0; ifile < input_files->GetEntries(); ++ifile)
        {
            TString filepath = ((TObjString*)input_files->At(ifile))->GetString();

            // Accessing n events
            TString nevents_file_path = filepath.ReplaceAll(".root", "_nevents.txt");
            std::ifstream ifs(nevents_file_path.Data());
            std::string content( (std::istreambuf_iterator<char>(ifs) ),
                    (std::istreambuf_iterator<char>()    ) );
            TString content_tstr = content.c_str();
            TObjArray* lines = content_tstr.Tokenize("\n");
            int index_total = lines->GetEntries() - 3;
            int index_pos_total = lines->GetEntries() - 2;
            int index_neg_total = lines->GetEntries() - 1;
            total += ((TObjString*)lines->At(index_total))->GetString().Atoi();
            pos_total += ((TObjString*)lines->At(index_pos_total))->GetString().Atoi();
            neg_total += ((TObjString*)lines->At(index_neg_total))->GetString().Atoi();
        }
        int eff_total = pos_total != neg_total ? pos_total - neg_total : pos_total;
        Root__h_nevents->SetBinContent(1, total);
        Wgt__h_nevents->SetBinContent(1, eff_total);
        Root__h_nevents->Write();
        Wgt__h_nevents->Write();
    }
    else
    {
        // Book histograms to Root to count total number of events processed
        RooUtil::Histograms n_event_hist;
        n_event_hist.addHistogram("h_nevents", 1, 0, 1, [&]() { return 0; } );

        // Book the counter histogram to the Root
        ana.cutflow.bookHistogramsForCut(n_event_hist, "Root");
        ana.cutflow.bookHistogramsForCut(n_event_hist, "Wgt");
    }
}

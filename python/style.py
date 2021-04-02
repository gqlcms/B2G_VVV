#!/bin/env python

#~~~~~~~~~~~~~~~~
# 4Lep MET styles
#~~~~~~~~~~~~~~~~
grouping_4LepMET = {
        "DY_high.root"           : "Other",
        "DY_low.root"            : "Other",
        "DYzpt150.root"          : "NOTUSED",
        "GGHtoZZto4L.root"       : "Other",
        "HHAT_0p0.root"          : "NOTUSED",
        "HHAT_0p08.root"         : "NOTUSED",
        "HHAT_0p12.root"         : "NOTUSED",
        "HHAT_0p16.root"         : "NOTUSED",
        "QQWW.root"              : "Other",
        "STantitop.root"         : "Other",
        "STtop.root"             : "Other",
        "TGext.root"             : "NOTUSED",
        "TTBAR_PH.root"          : "NOTUSED",
        "TTDL.root"              : "Other",
        "TTGdilep.root"          : "NOTUSED",
        "TTGsinglelep.root"      : "NOTUSED",
        "TTGsinglelepbar.root"   : "NOTUSED",
        "TTHH.root"              : "Other",
        "TTSL.root"              : "Other",
        "TTSLtop.root"           : "NOTUSED",
        "TTSLtopbar.root"        : "NOTUSED",
        "TTTJ.root"              : "Other",
        "TTTTnew.root"           : "Other",
        "TTTW.root"              : "Other",
        "TTWH.root"              : "Other",
        "TTWW.root"              : "Other",
        "TTWZ.root"              : "Other",
        "TTWnlo.root"            : "Other",
        "TTZH.root"              : "Other",
        "TTZLOW.root"            : "TTZ",
        "TTZZ.root"              : "Other",
        "TTZnlo.root"            : "TTZ",
        "TTdilep0jet.root"       : "NOTUSED",
        "TTdilep1jet.root"       : "NOTUSED",
        "TZQ.root"               : "Other",
        "VHtoNonBB.root"         : "VH",
        "W2Jets.root"            : "NOTUSED",
        "W4Jets.root"            : "NOTUSED",
        "WGToLNuGext.root"       : "NOTUSED",
        "WJets.root"             : "Other",
        "WJets_HT100To200.root"  : "NOTUSED",
        "WJets_HT200To400.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT400To600.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT600To800.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT800To1200.root" : "NOTUSED", # HT gen level variable not implemented
        "WW.root"                : "Other",
        "WWDPS.root"             : "Other",
        "WWG.root"               : "NOTUSED",
        "WWW.root"               : "NOTUSED",
        "WWZ.root"               : "NOTUSED",
        "WZ.root"                : "WZ",
        "WZG.root"               : "NOTUSED",
        "WZZ.root"               : "NOTUSED",
        "ZG.root"                : "NOTUSED",
        "ZZ.root"                : "ZZ",
        "ZZZ.root"               : "VVV",
        "ZZcontTo2e2mu.root"     : "ZZ",
        "ZZcontTo2e2tau.root"    : "ZZ",
        "ZZcontTo2mu2tau.root"   : "ZZ",
        "ZZcontTo4mu.root"       : "ZZ",
        "ZZcontTo4tau.root"      : "ZZ",
        }
bkg_plot_order_4LepMET = [ "WZ", "Other", "VH", "TTZ", "ZZ" ]
legend_labels_4LepMET = [ "WZ", "Other", "VH", "TTZ", "ZZ" ]
sig_plot_order_4LepMET = [ "VVV" ]
sig_labels_4LepMET = [ "VVV" ]
colors_4LepMET = [7013, 920, 4024, 4305, 4020]


#~~~~~~~~~~~~~~~~
# 3Lep MET styles
#~~~~~~~~~~~~~~~~
grouping_3LepMET = {
        "DY_high.root"           : "Z",
        "DY_low.root"            : "Z",
        "DYzpt150.root"          : "NOTUSED",
        "GGHtoZZto4L.root"       : "Other",
        "HHAT_0p0.root"          : "NOTUSED",
        "HHAT_0p08.root"         : "NOTUSED",
        "HHAT_0p12.root"         : "NOTUSED",
        "HHAT_0p16.root"         : "NOTUSED",
        "QQWW.root"              : "WW",
        "STantitop.root"         : "Top",
        "STtop.root"             : "Top",
        "TGext.root"             : "NOTUSED",
        "TTBAR_PH.root"          : "NOTUSED",
        "TTDL.root"              : "Top",
        "TTGdilep.root"          : "NOTUSED",
        "TTGsinglelep.root"      : "NOTUSED",
        "TTGsinglelepbar.root"   : "NOTUSED",
        "TTHH.root"              : "Top",
        "TTSL.root"              : "Top",
        "TTSLtop.root"           : "NOTUSED",
        "TTSLtopbar.root"        : "NOTUSED",
        "TTTJ.root"              : "Top",
        "TTTTnew.root"           : "Top",
        "TTTW.root"              : "Top",
        "TTWH.root"              : "Top",
        "TTWW.root"              : "Top",
        "TTWZ.root"              : "Top",
        "TTWnlo.root"            : "ttW",
        "TTZH.root"              : "Top",
        "TTZLOW.root"            : "TTZ",
        "TTZZ.root"              : "Top",
        "TTZnlo.root"            : "TTZ",
        "TTdilep0jet.root"       : "NOTUSED",
        "TTdilep1jet.root"       : "NOTUSED",
        "TZQ.root"               : "Top",
        "VHtoNonBB.root"         : "VH",
        "W2Jets.root"            : "NOTUSED",
        "W4Jets.root"            : "NOTUSED",
        "WGToLNuGext.root"       : "NOTUSED",
        "WJets.root"             : "Other",
        "WJets_HT100To200.root"  : "NOTUSED",
        "WJets_HT200To400.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT400To600.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT600To800.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT800To1200.root" : "NOTUSED", # HT gen level variable not implemented
        "WW.root"                : "WW",
        "WWDPS.root"             : "WW",
        "WWG.root"               : "NOTUSED",
        "WWW.root"               : "VVV",
        "WWZ.root"               : "VVV",
        "WZ.root"                : "WZ",
        "WZG.root"               : "NOTUSED",
        "WZZ.root"               : "VVV",
        "ZG.root"                : "NOTUSED",
        "ZZ.root"                : "ZZ",
        "ZZZ.root"               : "VVV",
        "ZZcontTo2e2mu.root"     : "ZZ",
        "ZZcontTo2e2tau.root"    : "ZZ",
        "ZZcontTo2mu2tau.root"   : "ZZ",
        "ZZcontTo4mu.root"       : "ZZ",
        "ZZcontTo4tau.root"      : "ZZ",
    }
bkg_plot_order_3LepMET = [ "ZZ", "TTZ", "VH", "Other", "WZ", "WW","Top","Z","ttW" ]
legend_labels_3LepMET = [ "ZZ", "TTZ", "VH", "Other", "WZ", "WW","Top","Z","ttW" ]
sig_plot_order_3LepMET = [ "VVV" ]
sig_labels_3LepMET = [ "VVV" ]
colors_3LepMET = [2001, 2002, 2003, 2005, 2006, 2011, 2007, 920]
"""
legend_labels_1Lep4jet = [ "W", "Z", "Top", "Other" ]
sig_plot_order_1Lep4jet = [ "VVV", "VH" ]
sig_labels_1Lep4jet = [ "VVV", "VH" ]
colors_1Lep4jet = [2001, 7004, 7003, 7001]
"""

#~~~~~~~~~~~~~~~~
# 1Lep 4jet styles
#~~~~~~~~~~~~~~~~
grouping_1Lep4jet = {
        "DY_high.root"           : "Z",
        "DY_low.root"            : "NOTUSED",
        "DYzpt150.root"          : "NOTUSED",
        "GGHtoZZto4L.root"       : "NOTUSED",
        "HHAT_0p0.root"          : "NOTUSED",
        "HHAT_0p08.root"         : "NOTUSED",
        "HHAT_0p12.root"         : "NOTUSED",
        "HHAT_0p16.root"         : "NOTUSED",
        "QQWW.root"              : "VV",
        "STantitop.root"         : "Top",
        "STtop.root"             : "Top",
        "TGext.root"             : "NOTUSED",
        "TTBAR_PH.root"          : "NOTUSED",
        "TTDL.root"              : "Top",
        "TTGdilep.root"          : "NOTUSED",
        "TTGsinglelep.root"      : "NOTUSED",
        "TTGsinglelepbar.root"   : "NOTUSED",
        "TTHH.root"              : "NOTUSED",
        "TTSL.root"              : "Top",
        "TTSLtop.root"           : "NOTUSED",
        "TTSLtopbar.root"        : "NOTUSED",
        "TTTJ.root"              : "NOTUSED",
        "TTTTnew.root"           : "NOTUSED",
        "TTTW.root"              : "NOTUSED",
        "TTWH.root"              : "NOTUSED",
        "TTWW.root"              : "NOTUSED",
        "TTWZ.root"              : "NOTUSED",
        "TTWnlo.root"            : "NOTUSED",
        "TTZH.root"              : "NOTUSED",
        "TTZLOW.root"            : "NOTUSED",
        "TTZZ.root"              : "NOTUSED",
        "TTZnlo.root"            : "NOTUSED",
        "TTdilep0jet.root"       : "NOTUSED",
        "TTdilep1jet.root"       : "NOTUSED",
        "TZQ.root"               : "NOTUSED",
        "VHtoNonBB.root"         : "NOTUSED",
        "W2Jets.root"            : "NOTUSED",
        "W4Jets.root"            : "W",
        "WGToLNuGext.root"       : "NOTUSED",
        "WJets.root"             : "NOTUSED",
        "WJets_HT100To200.root"  : "NOTUSED",
        "WJets_HT200To400.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT400To600.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT600To800.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT800To1200.root" : "NOTUSED", # HT gen level variable not implemented
        "WW.root"                : "VV",
        "WWDPS.root"             : "NOTUSED",
        "WWG.root"               : "NOTUSED",
        "WWW.root"               : "VVV",
        "WWZ.root"               : "VVV",
        "WZ.root"                : "VV",
        "WZG.root"               : "NOTUSED",
        "WZZ.root"               : "VVV",
        "ZG.root"                : "NOTUSED",
        "ZZ.root"                : "VV",
        "ZZZ.root"               : "VVV",
        "ZZcontTo2e2mu.root"     : "NOTUSED",
        "ZZcontTo2e2tau.root"    : "NOTUSED",
        "ZZcontTo2mu2tau.root"   : "NOTUSED",
        "ZZcontTo4mu.root"       : "NOTUSED",
        "ZZcontTo4tau.root"      : "NOTUSED",
        }
# bkg_plot_order_1Lep4jet = [ "W", "Top", "Z", "VV" ]
# legend_labels_1Lep4jet = [ "W", "Top", "Z", "VV" ]
# sig_plot_order_1Lep4jet = [ "VVV" ]
# sig_labels_1Lep4jet = [ "VVV" ]
# colors_1Lep4jet = [2001, 7003, 7004, 7007 ]
bkg_plot_order_1Lep4jet = [ "VVV", "W", "Top", "Z", "VV" ]
legend_labels_1Lep4jet = [ "VVV", "W", "Top", "Z", "VV" ]
bkg_plot_order_1Lep4jet = [ "VV", "Z", "Top", "W", "VVV" ]
legend_labels_1Lep4jet = [ "VV", "Z", "Top", "W", "VVV" ]
sig_plot_order_1Lep4jet = [ "VVV" ]
sig_labels_1Lep4jet = [ "VVV" ]
colors_1Lep4jet = [7007, 7004, 7003, 2001, 2]
#~~~~~~~~~~~~~~~~
# OS +jets styles
#~~~~~~~~~~~~~~~~
grouping_OS2jet = {
        "DY_high.root"           : "Z",
        "DY_low.root"            : "Z",
        "DYzpt150.root"          : "NOTUSED",
        "GGHtoZZto4L.root"       : "Other",
        "HHAT_0p0.root"          : "NOTUSED",
        "HHAT_0p08.root"         : "NOTUSED",
        "HHAT_0p12.root"         : "NOTUSED",
        "HHAT_0p16.root"         : "NOTUSED",
        "QQWW.root"              : "WW",
        "STantitop.root"         : "Top",
        "STtop.root"             : "Top",
        "TGext.root"             : "NOTUSED",
        "TTBAR_PH.root"          : "NOTUSED",
        "TTDL.root"              : "Top",
        "TTGdilep.root"          : "NOTUSED",
        "TTGsinglelep.root"      : "NOTUSED",
        "TTGsinglelepbar.root"   : "NOTUSED",
        "TTHH.root"              : "TopX",
        "TTSL.root"              : "Top",
        "TTSLtop.root"           : "NOTUSED",
        "TTSLtopbar.root"        : "NOTUSED",
        "TTTJ.root"              : "Top",
        "TTTTnew.root"           : "Top",
        "TTTW.root"              : "TopX",
        "TTWH.root"              : "TopX",
        "TTWW.root"              : "TopX",
        "TTWZ.root"              : "TopX",
        "TTWnlo.root"            : "TopX",
        "TTZH.root"              : "TopX",
        "TTZLOW.root"            : "TopX",
        "TTZZ.root"              : "TopX",
        "TTZnlo.root"            : "TopX",
        "TTdilep0jet.root"       : "NOTUSED",
        "TTdilep1jet.root"       : "NOTUSED",
        "TZQ.root"               : "TopX",
        "TWZ.root"               : "TopX",
        "VHtoNonBB.root"         : "VH",
        "W2Jets.root"            : "NOTUSED",
        "W4Jets.root"            : "NOTUSED",
        "WGToLNuGext.root"       : "NOTUSED",
        "WJets.root"             : "NOTUSED",
        "WJets_HT100To200.root"  : "W",
        "WJets_HT200To400.root"  : "W", # HT gen level variable not implemented
        "WJets_HT400To600.root"  : "W", # HT gen level variable not implemented
        "WJets_HT600To800.root"  : "W", # HT gen level variable not implemented
        "WJets_HT800To1200.root" : "W", # HT gen level variable not implemented
        "WW.root"                : "WW",
        "WWDPS.root"             : "WW",
        "WWG.root"               : "NOTUSED",
        "WWW.root"               : "VVV",
        "WWZ.root"               : "VVV",
        "WZ.root"                : "WZ",
        "WZG.root"               : "NOTUSED",
        "WZZ.root"               : "VVV",
        "WGToLNuGext.root"       : "Other",
        "ZG.root"                : "Other",
        "ZZ.root"                : "ZZ",
        "ZZZ.root"               : "VVV",
        "ZZcontTo2e2mu.root"     : "NOTUSED",
        "ZZcontTo2e2tau.root"    : "NOTUSED",
        "ZZcontTo2mu2tau.root"   : "NOTUSED",
        "ZZcontTo4mu.root"       : "NOTUSED",
        "ZZcontTo4tau.root"      : "NOTUSED",
        "ZZcontTo4e.root"        : "NOTUSED",
        #ADD DATA
        "data_Run2016Bv1_ee.root": "Data_2016",
        "data_Run2016Bv2_ee.root": "Data_2016",
        "data_Run2016C_ee.root"  : "Data_2016",
        "data_Run2016D_ee.root"  : "Data_2016",
        "data_Run2016E_ee.root"  : "Data_2016",
        "data_Run2016F_ee.root"  : "Data_2016",
        "data_Run2016G_ee.root"  : "Data_2016",
        "data_Run2016H_ee.root"  : "Data_2016",
        "data_Run2016Bv1_em.root": "Data_2016",
        "data_Run2016Bv2_em.root": "Data_2016",
        "data_Run2016C_em.root"  : "Data_2016",
        "data_Run2016D_em.root"  : "Data_2016",
        "data_Run2016E_em.root"  : "Data_2016",
        "data_Run2016F_em.root"  : "Data_2016",
        "data_Run2016G_em.root"  : "Data_2016",
        "data_Run2016H_em.root"  : "Data_2016",
        "data_Run2016Bv1_mm.root": "Data_2016",
        "data_Run2016Bv2_mm.root": "Data_2016",
        "data_Run2016C_mm.root"  : "Data_2016",
        "data_Run2016D_mm.root"  : "Data_2016",
        "data_Run2016E_mm.root"  : "Data_2016",
        "data_Run2016F_mm.root"  : "Data_2016",
        "data_Run2016G_mm.root"  : "Data_2016",
        "data_Run2016H_mm.root"  : "Data_2016",
        "data_Run2017B_ee.root"  : "Data_2017",
        "data_Run2017C_ee.root"  : "Data_2017",
        "data_Run2017D_ee.root"  : "Data_2017",
        "data_Run2017E_ee.root"  : "Data_2017",
        "data_Run2017F_ee.root"  : "Data_2017",
        "data_Run2017B_em.root"  : "Data_2017",
        "data_Run2017C_em.root"  : "Data_2017",
        "data_Run2017D_em.root"  : "Data_2017",
        "data_Run2017E_em.root"  : "Data_2017",
        "data_Run2017F_em.root"  : "Data_2017",
        "data_Run2017B_mm.root"  : "Data_2017",
        "data_Run2017C_mm.root"  : "Data_2017",
        "data_Run2017D_mm.root"  : "Data_2017",
        "data_Run2017E_mm.root"  : "Data_2017",
        "data_Run2017F_mm.root"  : "Data_2017",
        "data_Run2018A_ee.root"  : "Data_2018",
        "data_Run2018B_ee.root"  : "Data_2018",
        "data_Run2018C_ee.root"  : "Data_2018",
        "data_Run2018D_ee.root"  : "Data_2018",
        "data_Run2018A_em.root"  : "Data_2018",
        "data_Run2018B_em.root"  : "Data_2018",
        "data_Run2018C_em.root"  : "Data_2018",
        "data_Run2018D_em.root"  : "Data_2018",
        "data_Run2018A_mm.root"  : "Data_2018",
        "data_Run2018B_mm.root"  : "Data_2018",
        "data_Run2018C_mm.root"  : "Data_2018",
        "data_Run2018D_mm.root"  : "Data_2018",
    }
bkg_plot_order_OS2jet = [ "ZZ", "WZ", "WW", "VH", "Z", "W","Top","TopX","Other" ]
legend_labels_OS2jet = [ "ZZ", "WZ", "WW", "VH", "DY", "W","Top","Top+X","Other" ]
colors_OS2jet        = [9001, 2003, 2001, 2006, 7004, 7005, 2012, 4006, 920]
sig_plot_order_OS2jet = [ "VVV" ]
sig_labels_OS2jet = [ "VVV" ]
#colors_OS2jet = [2001, 2002, 2003, 2005, 2006, 2011, 2007, 920]

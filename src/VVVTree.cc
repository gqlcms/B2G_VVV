#include "VVVTree.h"
VVVTree vvv;

void VVVTree::Init(TTree *tree) {
//---------------------------------------------------------------------------------
/*                           Common_met_p4*/  Common_met_p4_branch = tree->GetBranch("Common_met_p4");
/*                           Common_met_p4*/  if (Common_met_p4_branch) Common_met_p4_branch->SetAddress(&Common_met_p4_);
//---------------------------------------------------------------------------------
/*                           Common_lep_p4*/  Common_lep_p4_branch = tree->GetBranch("Common_lep_p4");
/*                           Common_lep_p4*/  if (Common_lep_p4_branch) Common_lep_p4_branch->SetAddress(&Common_lep_p4_);
//---------------------------------------------------------------------------------
/*                           Common_jet_p4*/  Common_jet_p4_branch = tree->GetBranch("Common_jet_p4");
/*                           Common_jet_p4*/  if (Common_jet_p4_branch) Common_jet_p4_branch->SetAddress(&Common_jet_p4_);
//---------------------------------------------------------------------------------
/*                        Common_fatjet_p4*/  Common_fatjet_p4_branch = tree->GetBranch("Common_fatjet_p4");
/*                        Common_fatjet_p4*/  if (Common_fatjet_p4_branch) Common_fatjet_p4_branch->SetAddress(&Common_fatjet_p4_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_p4*/  Common_fatjet_subjet0_p4_branch = tree->GetBranch("Common_fatjet_subjet0_p4");
/*                Common_fatjet_subjet0_p4*/  if (Common_fatjet_subjet0_p4_branch) Common_fatjet_subjet0_p4_branch->SetAddress(&Common_fatjet_subjet0_p4_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_p4*/  Common_fatjet_subjet1_p4_branch = tree->GetBranch("Common_fatjet_subjet1_p4");
/*                Common_fatjet_subjet1_p4*/  if (Common_fatjet_subjet1_p4_branch) Common_fatjet_subjet1_p4_branch->SetAddress(&Common_fatjet_subjet1_p4_);
//---------------------------------------------------------------------------------
/*                          Common_gen_p4s*/  Common_gen_p4s_branch = tree->GetBranch("Common_gen_p4s");
/*                          Common_gen_p4s*/  if (Common_gen_p4s_branch) Common_gen_p4s_branch->SetAddress(&Common_gen_p4s_);
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_p4s*/  Common_gen_vvvdecay_p4s_branch = tree->GetBranch("Common_gen_vvvdecay_p4s");
/*                 Common_gen_vvvdecay_p4s*/  if (Common_gen_vvvdecay_p4s_branch) Common_gen_vvvdecay_p4s_branch->SetAddress(&Common_gen_vvvdecay_p4s_);
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_0*/  Var_4LepMET_Zcand_lep_p4_0_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_p4_0");
/*              Var_4LepMET_Zcand_lep_p4_0*/  if (Var_4LepMET_Zcand_lep_p4_0_branch) Var_4LepMET_Zcand_lep_p4_0_branch->SetAddress(&Var_4LepMET_Zcand_lep_p4_0_);
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_1*/  Var_4LepMET_Zcand_lep_p4_1_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_p4_1");
/*              Var_4LepMET_Zcand_lep_p4_1*/  if (Var_4LepMET_Zcand_lep_p4_1_branch) Var_4LepMET_Zcand_lep_p4_1_branch->SetAddress(&Var_4LepMET_Zcand_lep_p4_1_);
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_0*/  Var_4LepMET_other_lep_p4_0_branch = tree->GetBranch("Var_4LepMET_other_lep_p4_0");
/*              Var_4LepMET_other_lep_p4_0*/  if (Var_4LepMET_other_lep_p4_0_branch) Var_4LepMET_other_lep_p4_0_branch->SetAddress(&Var_4LepMET_other_lep_p4_0_);
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_1*/  Var_4LepMET_other_lep_p4_1_branch = tree->GetBranch("Var_4LepMET_other_lep_p4_1");
/*              Var_4LepMET_other_lep_p4_1*/  if (Var_4LepMET_other_lep_p4_1_branch) Var_4LepMET_other_lep_p4_1_branch->SetAddress(&Var_4LepMET_other_lep_p4_1_);
//---------------------------------------------------------------------------------

  tree->SetMakeClass(1);

//---------------------------------------------------------------------------------
/*                           Common_isData*/  Common_isData_branch = tree->GetBranch("Common_isData");
/*                           Common_isData*/  if (Common_isData_branch) Common_isData_branch->SetAddress(&Common_isData_);
//---------------------------------------------------------------------------------
/*                              Common_run*/  Common_run_branch = tree->GetBranch("Common_run");
/*                              Common_run*/  if (Common_run_branch) Common_run_branch->SetAddress(&Common_run_);
//---------------------------------------------------------------------------------
/*                             Common_lumi*/  Common_lumi_branch = tree->GetBranch("Common_lumi");
/*                             Common_lumi*/  if (Common_lumi_branch) Common_lumi_branch->SetAddress(&Common_lumi_);
//---------------------------------------------------------------------------------
/*                              Common_evt*/  Common_evt_branch = tree->GetBranch("Common_evt");
/*                              Common_evt*/  if (Common_evt_branch) Common_evt_branch->SetAddress(&Common_evt_);
//---------------------------------------------------------------------------------
/*                        Common_genWeight*/  Common_genWeight_branch = tree->GetBranch("Common_genWeight");
/*                        Common_genWeight*/  if (Common_genWeight_branch) Common_genWeight_branch->SetAddress(&Common_genWeight_);
//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/  Common_btagWeight_DeepCSVB_branch = tree->GetBranch("Common_btagWeight_DeepCSVB");
/*              Common_btagWeight_DeepCSVB*/  if (Common_btagWeight_DeepCSVB_branch) Common_btagWeight_DeepCSVB_branch->SetAddress(&Common_btagWeight_DeepCSVB_);
//---------------------------------------------------------------------------------
/*         Common_LHEWeight_mg_reweighting*/  Common_LHEWeight_mg_reweighting_branch = tree->GetBranch("Common_LHEWeight_mg_reweighting");
/*         Common_LHEWeight_mg_reweighting*/  if (Common_LHEWeight_mg_reweighting_branch) Common_LHEWeight_mg_reweighting_branch->SetAddress(&Common_LHEWeight_mg_reweighting_);
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch = tree->GetBranch("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ");
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch->SetAddress(&Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_);
//---------------------------------------------------------------------------------
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch = tree->GetBranch("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL");
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch->SetAddress(&Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_);
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch = tree->GetBranch("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8");
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch->SetAddress(&Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_);
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch = tree->GetBranch("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch->SetAddress(&Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_);
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch = tree->GetBranch("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL");
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch->SetAddress(&Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_);
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch = tree->GetBranch("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch->SetAddress(&Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_);
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch = tree->GetBranch("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL");
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch->SetAddress(&Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_);
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch = tree->GetBranch("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ");
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch->SetAddress(&Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_);
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch = tree->GetBranch("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL");
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch->SetAddress(&Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_);
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleEl*/  Common_HLT_DoubleEl_branch = tree->GetBranch("Common_HLT_DoubleEl");
/*                     Common_HLT_DoubleEl*/  if (Common_HLT_DoubleEl_branch) Common_HLT_DoubleEl_branch->SetAddress(&Common_HLT_DoubleEl_);
//---------------------------------------------------------------------------------
/*                         Common_HLT_MuEG*/  Common_HLT_MuEG_branch = tree->GetBranch("Common_HLT_MuEG");
/*                         Common_HLT_MuEG*/  if (Common_HLT_MuEG_branch) Common_HLT_MuEG_branch->SetAddress(&Common_HLT_MuEG_);
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleMu*/  Common_HLT_DoubleMu_branch = tree->GetBranch("Common_HLT_DoubleMu");
/*                     Common_HLT_DoubleMu*/  if (Common_HLT_DoubleMu_branch) Common_HLT_DoubleMu_branch->SetAddress(&Common_HLT_DoubleMu_);
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_ee_em_mm*/  Common_pass_duplicate_removal_ee_em_mm_branch = tree->GetBranch("Common_pass_duplicate_removal_ee_em_mm");
/*  Common_pass_duplicate_removal_ee_em_mm*/  if (Common_pass_duplicate_removal_ee_em_mm_branch) Common_pass_duplicate_removal_ee_em_mm_branch->SetAddress(&Common_pass_duplicate_removal_ee_em_mm_);
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_mm_em_ee*/  Common_pass_duplicate_removal_mm_em_ee_branch = tree->GetBranch("Common_pass_duplicate_removal_mm_em_ee");
/*  Common_pass_duplicate_removal_mm_em_ee*/  if (Common_pass_duplicate_removal_mm_em_ee_branch) Common_pass_duplicate_removal_mm_em_ee_branch->SetAddress(&Common_pass_duplicate_removal_mm_em_ee_);
//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/  Common_noiseFlag_branch = tree->GetBranch("Common_noiseFlag");
/*                        Common_noiseFlag*/  if (Common_noiseFlag_branch) Common_noiseFlag_branch->SetAddress(&Common_noiseFlag_);
//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/  Common_noiseFlagMC_branch = tree->GetBranch("Common_noiseFlagMC");
/*                      Common_noiseFlagMC*/  if (Common_noiseFlagMC_branch) Common_noiseFlagMC_branch->SetAddress(&Common_noiseFlagMC_);
//---------------------------------------------------------------------------------
/*                      Common_event_lepSF*/  Common_event_lepSF_branch = tree->GetBranch("Common_event_lepSF");
/*                      Common_event_lepSF*/  if (Common_event_lepSF_branch) Common_event_lepSF_branch->SetAddress(&Common_event_lepSF_);
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFelup*/  Common_event_lepSFelup_branch = tree->GetBranch("Common_event_lepSFelup");
/*                  Common_event_lepSFelup*/  if (Common_event_lepSFelup_branch) Common_event_lepSFelup_branch->SetAddress(&Common_event_lepSFelup_);
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFeldn*/  Common_event_lepSFeldn_branch = tree->GetBranch("Common_event_lepSFeldn");
/*                  Common_event_lepSFeldn*/  if (Common_event_lepSFeldn_branch) Common_event_lepSFeldn_branch->SetAddress(&Common_event_lepSFeldn_);
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmuup*/  Common_event_lepSFmuup_branch = tree->GetBranch("Common_event_lepSFmuup");
/*                  Common_event_lepSFmuup*/  if (Common_event_lepSFmuup_branch) Common_event_lepSFmuup_branch->SetAddress(&Common_event_lepSFmuup_);
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmudn*/  Common_event_lepSFmudn_branch = tree->GetBranch("Common_event_lepSFmudn");
/*                  Common_event_lepSFmudn*/  if (Common_event_lepSFmudn_branch) Common_event_lepSFmudn_branch->SetAddress(&Common_event_lepSFmudn_);
//---------------------------------------------------------------------------------
/*                         Common_lep_idxs*/  Common_lep_idxs_branch = tree->GetBranch("Common_lep_idxs");
/*                         Common_lep_idxs*/  if (Common_lep_idxs_branch) Common_lep_idxs_branch->SetAddress(&Common_lep_idxs_);
//---------------------------------------------------------------------------------
/*                        Common_lep_pdgid*/  Common_lep_pdgid_branch = tree->GetBranch("Common_lep_pdgid");
/*                        Common_lep_pdgid*/  if (Common_lep_pdgid_branch) Common_lep_pdgid_branch->SetAddress(&Common_lep_pdgid_);
//---------------------------------------------------------------------------------
/*                        Common_lep_tight*/  Common_lep_tight_branch = tree->GetBranch("Common_lep_tight");
/*                        Common_lep_tight*/  if (Common_lep_tight_branch) Common_lep_tight_branch->SetAddress(&Common_lep_tight_);
//---------------------------------------------------------------------------------
/*                          Common_lep_dxy*/  Common_lep_dxy_branch = tree->GetBranch("Common_lep_dxy");
/*                          Common_lep_dxy*/  if (Common_lep_dxy_branch) Common_lep_dxy_branch->SetAddress(&Common_lep_dxy_);
//---------------------------------------------------------------------------------
/*                           Common_lep_dz*/  Common_lep_dz_branch = tree->GetBranch("Common_lep_dz");
/*                           Common_lep_dz*/  if (Common_lep_dz_branch) Common_lep_dz_branch->SetAddress(&Common_lep_dz_);
//---------------------------------------------------------------------------------
/*                         Common_lep_ip3d*/  Common_lep_ip3d_branch = tree->GetBranch("Common_lep_ip3d");
/*                         Common_lep_ip3d*/  if (Common_lep_ip3d_branch) Common_lep_ip3d_branch->SetAddress(&Common_lep_ip3d_);
//---------------------------------------------------------------------------------
/*                        Common_lep_sip3d*/  Common_lep_sip3d_branch = tree->GetBranch("Common_lep_sip3d");
/*                        Common_lep_sip3d*/  if (Common_lep_sip3d_branch) Common_lep_sip3d_branch->SetAddress(&Common_lep_sip3d_);
//---------------------------------------------------------------------------------
/*                           Common_lep_SF*/  Common_lep_SF_branch = tree->GetBranch("Common_lep_SF");
/*                           Common_lep_SF*/  if (Common_lep_SF_branch) Common_lep_SF_branch->SetAddress(&Common_lep_SF_);
//---------------------------------------------------------------------------------
/*                      Common_lep_SFTight*/  Common_lep_SFTight_branch = tree->GetBranch("Common_lep_SFTight");
/*                      Common_lep_SFTight*/  if (Common_lep_SFTight_branch) Common_lep_SFTight_branch->SetAddress(&Common_lep_SFTight_);
//---------------------------------------------------------------------------------
/*                         Common_lep_SFdn*/  Common_lep_SFdn_branch = tree->GetBranch("Common_lep_SFdn");
/*                         Common_lep_SFdn*/  if (Common_lep_SFdn_branch) Common_lep_SFdn_branch->SetAddress(&Common_lep_SFdn_);
//---------------------------------------------------------------------------------
/*                    Common_lep_SFdnTight*/  Common_lep_SFdnTight_branch = tree->GetBranch("Common_lep_SFdnTight");
/*                    Common_lep_SFdnTight*/  if (Common_lep_SFdnTight_branch) Common_lep_SFdnTight_branch->SetAddress(&Common_lep_SFdnTight_);
//---------------------------------------------------------------------------------
/*                         Common_lep_SFup*/  Common_lep_SFup_branch = tree->GetBranch("Common_lep_SFup");
/*                         Common_lep_SFup*/  if (Common_lep_SFup_branch) Common_lep_SFup_branch->SetAddress(&Common_lep_SFup_);
//---------------------------------------------------------------------------------
/*                    Common_lep_SFupTight*/  Common_lep_SFupTight_branch = tree->GetBranch("Common_lep_SFupTight");
/*                    Common_lep_SFupTight*/  if (Common_lep_SFupTight_branch) Common_lep_SFupTight_branch->SetAddress(&Common_lep_SFupTight_);
//---------------------------------------------------------------------------------
/*                         Common_jet_idxs*/  Common_jet_idxs_branch = tree->GetBranch("Common_jet_idxs");
/*                         Common_jet_idxs*/  if (Common_jet_idxs_branch) Common_jet_idxs_branch->SetAddress(&Common_jet_idxs_);
//---------------------------------------------------------------------------------
/*                   Common_jet_passBloose*/  Common_jet_passBloose_branch = tree->GetBranch("Common_jet_passBloose");
/*                   Common_jet_passBloose*/  if (Common_jet_passBloose_branch) Common_jet_passBloose_branch->SetAddress(&Common_jet_passBloose_);
//---------------------------------------------------------------------------------
/*                  Common_jet_passBmedium*/  Common_jet_passBmedium_branch = tree->GetBranch("Common_jet_passBmedium");
/*                  Common_jet_passBmedium*/  if (Common_jet_passBmedium_branch) Common_jet_passBmedium_branch->SetAddress(&Common_jet_passBmedium_);
//---------------------------------------------------------------------------------
/*                   Common_jet_passBtight*/  Common_jet_passBtight_branch = tree->GetBranch("Common_jet_passBtight");
/*                   Common_jet_passBtight*/  if (Common_jet_passBtight_branch) Common_jet_passBtight_branch->SetAddress(&Common_jet_passBtight_);
//---------------------------------------------------------------------------------
/*                Common_jet_overlapfatjet*/  Common_jet_overlapfatjet_branch = tree->GetBranch("Common_jet_overlapfatjet");
/*                Common_jet_overlapfatjet*/  if (Common_jet_overlapfatjet_branch) Common_jet_overlapfatjet_branch->SetAddress(&Common_jet_overlapfatjet_);
//---------------------------------------------------------------------------------
/*                      Common_fatjet_idxs*/  Common_fatjet_idxs_branch = tree->GetBranch("Common_fatjet_idxs");
/*                      Common_fatjet_idxs*/  if (Common_fatjet_idxs_branch) Common_fatjet_idxs_branch->SetAddress(&Common_fatjet_idxs_);
//---------------------------------------------------------------------------------
/*                 Common_fatjet_msoftdrop*/  Common_fatjet_msoftdrop_branch = tree->GetBranch("Common_fatjet_msoftdrop");
/*                 Common_fatjet_msoftdrop*/  if (Common_fatjet_msoftdrop_branch) Common_fatjet_msoftdrop_branch->SetAddress(&Common_fatjet_msoftdrop_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_W*/  Common_fatjet_deepMD_W_branch = tree->GetBranch("Common_fatjet_deepMD_W");
/*                  Common_fatjet_deepMD_W*/  if (Common_fatjet_deepMD_W_branch) Common_fatjet_deepMD_W_branch->SetAddress(&Common_fatjet_deepMD_W_);
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_W*/  Common_fatjet_deep_W_branch = tree->GetBranch("Common_fatjet_deep_W");
/*                    Common_fatjet_deep_W*/  if (Common_fatjet_deep_W_branch) Common_fatjet_deep_W_branch->SetAddress(&Common_fatjet_deep_W_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_Z*/  Common_fatjet_deepMD_Z_branch = tree->GetBranch("Common_fatjet_deepMD_Z");
/*                  Common_fatjet_deepMD_Z*/  if (Common_fatjet_deepMD_Z_branch) Common_fatjet_deepMD_Z_branch->SetAddress(&Common_fatjet_deepMD_Z_);
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_Z*/  Common_fatjet_deep_Z_branch = tree->GetBranch("Common_fatjet_deep_Z");
/*                    Common_fatjet_deep_Z*/  if (Common_fatjet_deep_Z_branch) Common_fatjet_deep_Z_branch->SetAddress(&Common_fatjet_deep_Z_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_T*/  Common_fatjet_deepMD_T_branch = tree->GetBranch("Common_fatjet_deepMD_T");
/*                  Common_fatjet_deepMD_T*/  if (Common_fatjet_deepMD_T_branch) Common_fatjet_deepMD_T_branch->SetAddress(&Common_fatjet_deepMD_T_);
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_T*/  Common_fatjet_deep_T_branch = tree->GetBranch("Common_fatjet_deep_T");
/*                    Common_fatjet_deep_T*/  if (Common_fatjet_deep_T_branch) Common_fatjet_deep_T_branch->SetAddress(&Common_fatjet_deep_T_);
//---------------------------------------------------------------------------------
/*                 Common_fatjet_deepMD_bb*/  Common_fatjet_deepMD_bb_branch = tree->GetBranch("Common_fatjet_deepMD_bb");
/*                 Common_fatjet_deepMD_bb*/  if (Common_fatjet_deepMD_bb_branch) Common_fatjet_deepMD_bb_branch->SetAddress(&Common_fatjet_deepMD_bb_);
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau3*/  Common_fatjet_tau3_branch = tree->GetBranch("Common_fatjet_tau3");
/*                      Common_fatjet_tau3*/  if (Common_fatjet_tau3_branch) Common_fatjet_tau3_branch->SetAddress(&Common_fatjet_tau3_);
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau2*/  Common_fatjet_tau2_branch = tree->GetBranch("Common_fatjet_tau2");
/*                      Common_fatjet_tau2*/  if (Common_fatjet_tau2_branch) Common_fatjet_tau2_branch->SetAddress(&Common_fatjet_tau2_);
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau1*/  Common_fatjet_tau1_branch = tree->GetBranch("Common_fatjet_tau1");
/*                      Common_fatjet_tau1*/  if (Common_fatjet_tau1_branch) Common_fatjet_tau1_branch->SetAddress(&Common_fatjet_tau1_);
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau32*/  Common_fatjet_tau32_branch = tree->GetBranch("Common_fatjet_tau32");
/*                     Common_fatjet_tau32*/  if (Common_fatjet_tau32_branch) Common_fatjet_tau32_branch->SetAddress(&Common_fatjet_tau32_);
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau21*/  Common_fatjet_tau21_branch = tree->GetBranch("Common_fatjet_tau21");
/*                     Common_fatjet_tau21*/  if (Common_fatjet_tau21_branch) Common_fatjet_tau21_branch->SetAddress(&Common_fatjet_tau21_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_pt*/  Common_fatjet_subjet0_pt_branch = tree->GetBranch("Common_fatjet_subjet0_pt");
/*                Common_fatjet_subjet0_pt*/  if (Common_fatjet_subjet0_pt_branch) Common_fatjet_subjet0_pt_branch->SetAddress(&Common_fatjet_subjet0_pt_);
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_eta*/  Common_fatjet_subjet0_eta_branch = tree->GetBranch("Common_fatjet_subjet0_eta");
/*               Common_fatjet_subjet0_eta*/  if (Common_fatjet_subjet0_eta_branch) Common_fatjet_subjet0_eta_branch->SetAddress(&Common_fatjet_subjet0_eta_);
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_phi*/  Common_fatjet_subjet0_phi_branch = tree->GetBranch("Common_fatjet_subjet0_phi");
/*               Common_fatjet_subjet0_phi*/  if (Common_fatjet_subjet0_phi_branch) Common_fatjet_subjet0_phi_branch->SetAddress(&Common_fatjet_subjet0_phi_);
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet0_mass*/  Common_fatjet_subjet0_mass_branch = tree->GetBranch("Common_fatjet_subjet0_mass");
/*              Common_fatjet_subjet0_mass*/  if (Common_fatjet_subjet0_mass_branch) Common_fatjet_subjet0_mass_branch->SetAddress(&Common_fatjet_subjet0_mass_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_pt*/  Common_fatjet_subjet1_pt_branch = tree->GetBranch("Common_fatjet_subjet1_pt");
/*                Common_fatjet_subjet1_pt*/  if (Common_fatjet_subjet1_pt_branch) Common_fatjet_subjet1_pt_branch->SetAddress(&Common_fatjet_subjet1_pt_);
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_eta*/  Common_fatjet_subjet1_eta_branch = tree->GetBranch("Common_fatjet_subjet1_eta");
/*               Common_fatjet_subjet1_eta*/  if (Common_fatjet_subjet1_eta_branch) Common_fatjet_subjet1_eta_branch->SetAddress(&Common_fatjet_subjet1_eta_);
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_phi*/  Common_fatjet_subjet1_phi_branch = tree->GetBranch("Common_fatjet_subjet1_phi");
/*               Common_fatjet_subjet1_phi*/  if (Common_fatjet_subjet1_phi_branch) Common_fatjet_subjet1_phi_branch->SetAddress(&Common_fatjet_subjet1_phi_);
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet1_mass*/  Common_fatjet_subjet1_mass_branch = tree->GetBranch("Common_fatjet_subjet1_mass");
/*              Common_fatjet_subjet1_mass*/  if (Common_fatjet_subjet1_mass_branch) Common_fatjet_subjet1_mass_branch->SetAddress(&Common_fatjet_subjet1_mass_);
//---------------------------------------------------------------------------------
/*                        Common_fatjet_WP*/  Common_fatjet_WP_branch = tree->GetBranch("Common_fatjet_WP");
/*                        Common_fatjet_WP*/  if (Common_fatjet_WP_branch) Common_fatjet_WP_branch->SetAddress(&Common_fatjet_WP_);
//---------------------------------------------------------------------------------
/*            Common_fatjet_WP_antimasscut*/  Common_fatjet_WP_antimasscut_branch = tree->GetBranch("Common_fatjet_WP_antimasscut");
/*            Common_fatjet_WP_antimasscut*/  if (Common_fatjet_WP_antimasscut_branch) Common_fatjet_WP_antimasscut_branch->SetAddress(&Common_fatjet_WP_antimasscut_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFVLoose*/  Common_fatjet_SFVLoose_branch = tree->GetBranch("Common_fatjet_SFVLoose");
/*                  Common_fatjet_SFVLoose*/  if (Common_fatjet_SFVLoose_branch) Common_fatjet_SFVLoose_branch->SetAddress(&Common_fatjet_SFVLoose_);
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFLoose*/  Common_fatjet_SFLoose_branch = tree->GetBranch("Common_fatjet_SFLoose");
/*                   Common_fatjet_SFLoose*/  if (Common_fatjet_SFLoose_branch) Common_fatjet_SFLoose_branch->SetAddress(&Common_fatjet_SFLoose_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFMedium*/  Common_fatjet_SFMedium_branch = tree->GetBranch("Common_fatjet_SFMedium");
/*                  Common_fatjet_SFMedium*/  if (Common_fatjet_SFMedium_branch) Common_fatjet_SFMedium_branch->SetAddress(&Common_fatjet_SFMedium_);
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFTight*/  Common_fatjet_SFTight_branch = tree->GetBranch("Common_fatjet_SFTight");
/*                   Common_fatjet_SFTight*/  if (Common_fatjet_SFTight_branch) Common_fatjet_SFTight_branch->SetAddress(&Common_fatjet_SFTight_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnVLoose*/  Common_fatjet_SFdnVLoose_branch = tree->GetBranch("Common_fatjet_SFdnVLoose");
/*                Common_fatjet_SFdnVLoose*/  if (Common_fatjet_SFdnVLoose_branch) Common_fatjet_SFdnVLoose_branch->SetAddress(&Common_fatjet_SFdnVLoose_);
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnLoose*/  Common_fatjet_SFdnLoose_branch = tree->GetBranch("Common_fatjet_SFdnLoose");
/*                 Common_fatjet_SFdnLoose*/  if (Common_fatjet_SFdnLoose_branch) Common_fatjet_SFdnLoose_branch->SetAddress(&Common_fatjet_SFdnLoose_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnMedium*/  Common_fatjet_SFdnMedium_branch = tree->GetBranch("Common_fatjet_SFdnMedium");
/*                Common_fatjet_SFdnMedium*/  if (Common_fatjet_SFdnMedium_branch) Common_fatjet_SFdnMedium_branch->SetAddress(&Common_fatjet_SFdnMedium_);
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnTight*/  Common_fatjet_SFdnTight_branch = tree->GetBranch("Common_fatjet_SFdnTight");
/*                 Common_fatjet_SFdnTight*/  if (Common_fatjet_SFdnTight_branch) Common_fatjet_SFdnTight_branch->SetAddress(&Common_fatjet_SFdnTight_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupVLoose*/  Common_fatjet_SFupVLoose_branch = tree->GetBranch("Common_fatjet_SFupVLoose");
/*                Common_fatjet_SFupVLoose*/  if (Common_fatjet_SFupVLoose_branch) Common_fatjet_SFupVLoose_branch->SetAddress(&Common_fatjet_SFupVLoose_);
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupLoose*/  Common_fatjet_SFupLoose_branch = tree->GetBranch("Common_fatjet_SFupLoose");
/*                 Common_fatjet_SFupLoose*/  if (Common_fatjet_SFupLoose_branch) Common_fatjet_SFupLoose_branch->SetAddress(&Common_fatjet_SFupLoose_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupMedium*/  Common_fatjet_SFupMedium_branch = tree->GetBranch("Common_fatjet_SFupMedium");
/*                Common_fatjet_SFupMedium*/  if (Common_fatjet_SFupMedium_branch) Common_fatjet_SFupMedium_branch->SetAddress(&Common_fatjet_SFupMedium_);
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupTight*/  Common_fatjet_SFupTight_branch = tree->GetBranch("Common_fatjet_SFupTight");
/*                 Common_fatjet_SFupTight*/  if (Common_fatjet_SFupTight_branch) Common_fatjet_SFupTight_branch->SetAddress(&Common_fatjet_SFupTight_);
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFVLoose*/  Common_eventweight_fatjet_SFVLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFVLoose");
/*      Common_eventweight_fatjet_SFVLoose*/  if (Common_eventweight_fatjet_SFVLoose_branch) Common_eventweight_fatjet_SFVLoose_branch->SetAddress(&Common_eventweight_fatjet_SFVLoose_);
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFLoose*/  Common_eventweight_fatjet_SFLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFLoose");
/*       Common_eventweight_fatjet_SFLoose*/  if (Common_eventweight_fatjet_SFLoose_branch) Common_eventweight_fatjet_SFLoose_branch->SetAddress(&Common_eventweight_fatjet_SFLoose_);
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFMedium*/  Common_eventweight_fatjet_SFMedium_branch = tree->GetBranch("Common_eventweight_fatjet_SFMedium");
/*      Common_eventweight_fatjet_SFMedium*/  if (Common_eventweight_fatjet_SFMedium_branch) Common_eventweight_fatjet_SFMedium_branch->SetAddress(&Common_eventweight_fatjet_SFMedium_);
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFTight*/  Common_eventweight_fatjet_SFTight_branch = tree->GetBranch("Common_eventweight_fatjet_SFTight");
/*       Common_eventweight_fatjet_SFTight*/  if (Common_eventweight_fatjet_SFTight_branch) Common_eventweight_fatjet_SFTight_branch->SetAddress(&Common_eventweight_fatjet_SFTight_);
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnVLoose*/  Common_eventweight_fatjet_SFdnVLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFdnVLoose");
/*    Common_eventweight_fatjet_SFdnVLoose*/  if (Common_eventweight_fatjet_SFdnVLoose_branch) Common_eventweight_fatjet_SFdnVLoose_branch->SetAddress(&Common_eventweight_fatjet_SFdnVLoose_);
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnLoose*/  Common_eventweight_fatjet_SFdnLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFdnLoose");
/*     Common_eventweight_fatjet_SFdnLoose*/  if (Common_eventweight_fatjet_SFdnLoose_branch) Common_eventweight_fatjet_SFdnLoose_branch->SetAddress(&Common_eventweight_fatjet_SFdnLoose_);
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnMedium*/  Common_eventweight_fatjet_SFdnMedium_branch = tree->GetBranch("Common_eventweight_fatjet_SFdnMedium");
/*    Common_eventweight_fatjet_SFdnMedium*/  if (Common_eventweight_fatjet_SFdnMedium_branch) Common_eventweight_fatjet_SFdnMedium_branch->SetAddress(&Common_eventweight_fatjet_SFdnMedium_);
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnTight*/  Common_eventweight_fatjet_SFdnTight_branch = tree->GetBranch("Common_eventweight_fatjet_SFdnTight");
/*     Common_eventweight_fatjet_SFdnTight*/  if (Common_eventweight_fatjet_SFdnTight_branch) Common_eventweight_fatjet_SFdnTight_branch->SetAddress(&Common_eventweight_fatjet_SFdnTight_);
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupVLoose*/  Common_eventweight_fatjet_SFupVLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFupVLoose");
/*    Common_eventweight_fatjet_SFupVLoose*/  if (Common_eventweight_fatjet_SFupVLoose_branch) Common_eventweight_fatjet_SFupVLoose_branch->SetAddress(&Common_eventweight_fatjet_SFupVLoose_);
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupLoose*/  Common_eventweight_fatjet_SFupLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFupLoose");
/*     Common_eventweight_fatjet_SFupLoose*/  if (Common_eventweight_fatjet_SFupLoose_branch) Common_eventweight_fatjet_SFupLoose_branch->SetAddress(&Common_eventweight_fatjet_SFupLoose_);
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupMedium*/  Common_eventweight_fatjet_SFupMedium_branch = tree->GetBranch("Common_eventweight_fatjet_SFupMedium");
/*    Common_eventweight_fatjet_SFupMedium*/  if (Common_eventweight_fatjet_SFupMedium_branch) Common_eventweight_fatjet_SFupMedium_branch->SetAddress(&Common_eventweight_fatjet_SFupMedium_);
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupTight*/  Common_eventweight_fatjet_SFupTight_branch = tree->GetBranch("Common_eventweight_fatjet_SFupTight");
/*     Common_eventweight_fatjet_SFupTight*/  if (Common_eventweight_fatjet_SFupTight_branch) Common_eventweight_fatjet_SFupTight_branch->SetAddress(&Common_eventweight_fatjet_SFupTight_);
//---------------------------------------------------------------------------------
/*                         Common_nb_loose*/  Common_nb_loose_branch = tree->GetBranch("Common_nb_loose");
/*                         Common_nb_loose*/  if (Common_nb_loose_branch) Common_nb_loose_branch->SetAddress(&Common_nb_loose_);
//---------------------------------------------------------------------------------
/*                        Common_nb_medium*/  Common_nb_medium_branch = tree->GetBranch("Common_nb_medium");
/*                        Common_nb_medium*/  if (Common_nb_medium_branch) Common_nb_medium_branch->SetAddress(&Common_nb_medium_);
//---------------------------------------------------------------------------------
/*                         Common_nb_tight*/  Common_nb_tight_branch = tree->GetBranch("Common_nb_tight");
/*                         Common_nb_tight*/  if (Common_nb_tight_branch) Common_nb_tight_branch->SetAddress(&Common_nb_tight_);
//---------------------------------------------------------------------------------
/*                          Common_gen_idx*/  Common_gen_idx_branch = tree->GetBranch("Common_gen_idx");
/*                          Common_gen_idx*/  if (Common_gen_idx_branch) Common_gen_idx_branch->SetAddress(&Common_gen_idx_);
//---------------------------------------------------------------------------------
/*                   Common_gen_mother_idx*/  Common_gen_mother_idx_branch = tree->GetBranch("Common_gen_mother_idx");
/*                   Common_gen_mother_idx*/  if (Common_gen_mother_idx_branch) Common_gen_mother_idx_branch->SetAddress(&Common_gen_mother_idx_);
//---------------------------------------------------------------------------------
/*                    Common_gen_mother_id*/  Common_gen_mother_id_branch = tree->GetBranch("Common_gen_mother_id");
/*                    Common_gen_mother_id*/  if (Common_gen_mother_id_branch) Common_gen_mother_id_branch->SetAddress(&Common_gen_mother_id_);
//---------------------------------------------------------------------------------
/*                        Common_gen_pdgid*/  Common_gen_pdgid_branch = tree->GetBranch("Common_gen_pdgid");
/*                        Common_gen_pdgid*/  if (Common_gen_pdgid_branch) Common_gen_pdgid_branch->SetAddress(&Common_gen_pdgid_);
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_idx*/  Common_gen_vvvdecay_idx_branch = tree->GetBranch("Common_gen_vvvdecay_idx");
/*                 Common_gen_vvvdecay_idx*/  if (Common_gen_vvvdecay_idx_branch) Common_gen_vvvdecay_idx_branch->SetAddress(&Common_gen_vvvdecay_idx_);
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_mother_idx*/  Common_gen_vvvdecay_mother_idx_branch = tree->GetBranch("Common_gen_vvvdecay_mother_idx");
/*          Common_gen_vvvdecay_mother_idx*/  if (Common_gen_vvvdecay_mother_idx_branch) Common_gen_vvvdecay_mother_idx_branch->SetAddress(&Common_gen_vvvdecay_mother_idx_);
//---------------------------------------------------------------------------------
/*           Common_gen_vvvdecay_mother_id*/  Common_gen_vvvdecay_mother_id_branch = tree->GetBranch("Common_gen_vvvdecay_mother_id");
/*           Common_gen_vvvdecay_mother_id*/  if (Common_gen_vvvdecay_mother_id_branch) Common_gen_vvvdecay_mother_id_branch->SetAddress(&Common_gen_vvvdecay_mother_id_);
//---------------------------------------------------------------------------------
/*               Common_gen_vvvdecay_pdgid*/  Common_gen_vvvdecay_pdgid_branch = tree->GetBranch("Common_gen_vvvdecay_pdgid");
/*               Common_gen_vvvdecay_pdgid*/  if (Common_gen_vvvdecay_pdgid_branch) Common_gen_vvvdecay_pdgid_branch->SetAddress(&Common_gen_vvvdecay_pdgid_);
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_taudecayid*/  Common_gen_vvvdecay_taudecayid_branch = tree->GetBranch("Common_gen_vvvdecay_taudecayid");
/*          Common_gen_vvvdecay_taudecayid*/  if (Common_gen_vvvdecay_taudecayid_branch) Common_gen_vvvdecay_taudecayid_branch->SetAddress(&Common_gen_vvvdecay_taudecayid_);
//---------------------------------------------------------------------------------
/*                              Common_n_W*/  Common_n_W_branch = tree->GetBranch("Common_n_W");
/*                              Common_n_W*/  if (Common_n_W_branch) Common_n_W_branch->SetAddress(&Common_n_W_);
//---------------------------------------------------------------------------------
/*                              Common_n_Z*/  Common_n_Z_branch = tree->GetBranch("Common_n_Z");
/*                              Common_n_Z*/  if (Common_n_Z_branch) Common_n_Z_branch->SetAddress(&Common_n_Z_);
//---------------------------------------------------------------------------------
/*                          Common_n_lep_Z*/  Common_n_lep_Z_branch = tree->GetBranch("Common_n_lep_Z");
/*                          Common_n_lep_Z*/  if (Common_n_lep_Z_branch) Common_n_lep_Z_branch->SetAddress(&Common_n_lep_Z_);
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_Z*/  Common_n_leptau_Z_branch = tree->GetBranch("Common_n_leptau_Z");
/*                       Common_n_leptau_Z*/  if (Common_n_leptau_Z_branch) Common_n_leptau_Z_branch->SetAddress(&Common_n_leptau_Z_);
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_Z*/  Common_n_hadtau_Z_branch = tree->GetBranch("Common_n_hadtau_Z");
/*                       Common_n_hadtau_Z*/  if (Common_n_hadtau_Z_branch) Common_n_hadtau_Z_branch->SetAddress(&Common_n_hadtau_Z_);
//---------------------------------------------------------------------------------
/*                           Common_n_nu_Z*/  Common_n_nu_Z_branch = tree->GetBranch("Common_n_nu_Z");
/*                           Common_n_nu_Z*/  if (Common_n_nu_Z_branch) Common_n_nu_Z_branch->SetAddress(&Common_n_nu_Z_);
//---------------------------------------------------------------------------------
/*                            Common_n_b_Z*/  Common_n_b_Z_branch = tree->GetBranch("Common_n_b_Z");
/*                            Common_n_b_Z*/  if (Common_n_b_Z_branch) Common_n_b_Z_branch->SetAddress(&Common_n_b_Z_);
//---------------------------------------------------------------------------------
/*                          Common_n_lep_W*/  Common_n_lep_W_branch = tree->GetBranch("Common_n_lep_W");
/*                          Common_n_lep_W*/  if (Common_n_lep_W_branch) Common_n_lep_W_branch->SetAddress(&Common_n_lep_W_);
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_W*/  Common_n_leptau_W_branch = tree->GetBranch("Common_n_leptau_W");
/*                       Common_n_leptau_W*/  if (Common_n_leptau_W_branch) Common_n_leptau_W_branch->SetAddress(&Common_n_leptau_W_);
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_W*/  Common_n_hadtau_W_branch = tree->GetBranch("Common_n_hadtau_W");
/*                       Common_n_hadtau_W*/  if (Common_n_hadtau_W_branch) Common_n_hadtau_W_branch->SetAddress(&Common_n_hadtau_W_);
//---------------------------------------------------------------------------------
/*                        Common_haslepWSS*/  Common_haslepWSS_branch = tree->GetBranch("Common_haslepWSS");
/*                        Common_haslepWSS*/  if (Common_haslepWSS_branch) Common_haslepWSS_branch->SetAddress(&Common_haslepWSS_);
//---------------------------------------------------------------------------------
/*                            Common_genHT*/  Common_genHT_branch = tree->GetBranch("Common_genHT");
/*                            Common_genHT*/  if (Common_genHT_branch) Common_genHT_branch->SetAddress(&Common_genHT_);
//---------------------------------------------------------------------------------
/*                  Common_gen_n_light_lep*/  Common_gen_n_light_lep_branch = tree->GetBranch("Common_gen_n_light_lep");
/*                  Common_gen_n_light_lep*/  if (Common_gen_n_light_lep_branch) Common_gen_n_light_lep_branch->SetAddress(&Common_gen_n_light_lep_);
//---------------------------------------------------------------------------------
/*                   Common_gen_VH_channel*/  Common_gen_VH_channel_branch = tree->GetBranch("Common_gen_VH_channel");
/*                   Common_gen_VH_channel*/  if (Common_gen_VH_channel_branch) Common_gen_VH_channel_branch->SetAddress(&Common_gen_VH_channel_);
//---------------------------------------------------------------------------------
/*                Cut_4LepMET_Preselection*/  Cut_4LepMET_Preselection_branch = tree->GetBranch("Cut_4LepMET_Preselection");
/*                Cut_4LepMET_Preselection*/  if (Cut_4LepMET_Preselection_branch) Cut_4LepMET_Preselection_branch->SetAddress(&Cut_4LepMET_Preselection_);
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/  Cut_4LepMET_emuChannel_branch = tree->GetBranch("Cut_4LepMET_emuChannel");
/*                  Cut_4LepMET_emuChannel*/  if (Cut_4LepMET_emuChannel_branch) Cut_4LepMET_emuChannel_branch->SetAddress(&Cut_4LepMET_emuChannel_);
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/  Cut_4LepMET_offzChannel_branch = tree->GetBranch("Cut_4LepMET_offzChannel");
/*                 Cut_4LepMET_offzChannel*/  if (Cut_4LepMET_offzChannel_branch) Cut_4LepMET_offzChannel_branch->SetAddress(&Cut_4LepMET_offzChannel_);
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/  Cut_4LepMET_onzChannel_branch = tree->GetBranch("Cut_4LepMET_onzChannel");
/*                  Cut_4LepMET_onzChannel*/  if (Cut_4LepMET_onzChannel_branch) Cut_4LepMET_onzChannel_branch->SetAddress(&Cut_4LepMET_onzChannel_);
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/  Cut_4LepMET_onzChannel_HighMET_branch = tree->GetBranch("Cut_4LepMET_onzChannel_HighMET");
/*          Cut_4LepMET_onzChannel_HighMET*/  if (Cut_4LepMET_onzChannel_HighMET_branch) Cut_4LepMET_onzChannel_HighMET_branch->SetAddress(&Cut_4LepMET_onzChannel_HighMET_);
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/  Var_4LepMET_Zcand_lep_idx_0_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_idx_0");
/*             Var_4LepMET_Zcand_lep_idx_0*/  if (Var_4LepMET_Zcand_lep_idx_0_branch) Var_4LepMET_Zcand_lep_idx_0_branch->SetAddress(&Var_4LepMET_Zcand_lep_idx_0_);
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  Var_4LepMET_Zcand_lep_pdgid_0_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_pdgid_0");
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  if (Var_4LepMET_Zcand_lep_pdgid_0_branch) Var_4LepMET_Zcand_lep_pdgid_0_branch->SetAddress(&Var_4LepMET_Zcand_lep_pdgid_0_);
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_1*/  Var_4LepMET_Zcand_lep_idx_1_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_idx_1");
/*             Var_4LepMET_Zcand_lep_idx_1*/  if (Var_4LepMET_Zcand_lep_idx_1_branch) Var_4LepMET_Zcand_lep_idx_1_branch->SetAddress(&Var_4LepMET_Zcand_lep_idx_1_);
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  Var_4LepMET_Zcand_lep_pdgid_1_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_pdgid_1");
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  if (Var_4LepMET_Zcand_lep_pdgid_1_branch) Var_4LepMET_Zcand_lep_pdgid_1_branch->SetAddress(&Var_4LepMET_Zcand_lep_pdgid_1_);
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_Zcand_mll*/  Var_4LepMET_Zcand_mll_branch = tree->GetBranch("Var_4LepMET_Zcand_mll");
/*                   Var_4LepMET_Zcand_mll*/  if (Var_4LepMET_Zcand_mll_branch) Var_4LepMET_Zcand_mll_branch->SetAddress(&Var_4LepMET_Zcand_mll_);
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_0*/  Var_4LepMET_other_lep_idx_0_branch = tree->GetBranch("Var_4LepMET_other_lep_idx_0");
/*             Var_4LepMET_other_lep_idx_0*/  if (Var_4LepMET_other_lep_idx_0_branch) Var_4LepMET_other_lep_idx_0_branch->SetAddress(&Var_4LepMET_other_lep_idx_0_);
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_0*/  Var_4LepMET_other_lep_pdgid_0_branch = tree->GetBranch("Var_4LepMET_other_lep_pdgid_0");
/*           Var_4LepMET_other_lep_pdgid_0*/  if (Var_4LepMET_other_lep_pdgid_0_branch) Var_4LepMET_other_lep_pdgid_0_branch->SetAddress(&Var_4LepMET_other_lep_pdgid_0_);
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_1*/  Var_4LepMET_other_lep_idx_1_branch = tree->GetBranch("Var_4LepMET_other_lep_idx_1");
/*             Var_4LepMET_other_lep_idx_1*/  if (Var_4LepMET_other_lep_idx_1_branch) Var_4LepMET_other_lep_idx_1_branch->SetAddress(&Var_4LepMET_other_lep_idx_1_);
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_1*/  Var_4LepMET_other_lep_pdgid_1_branch = tree->GetBranch("Var_4LepMET_other_lep_pdgid_1");
/*           Var_4LepMET_other_lep_pdgid_1*/  if (Var_4LepMET_other_lep_pdgid_1_branch) Var_4LepMET_other_lep_pdgid_1_branch->SetAddress(&Var_4LepMET_other_lep_pdgid_1_);
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_other_mll*/  Var_4LepMET_other_mll_branch = tree->GetBranch("Var_4LepMET_other_mll");
/*                   Var_4LepMET_other_mll*/  if (Var_4LepMET_other_mll_branch) Var_4LepMET_other_mll_branch->SetAddress(&Var_4LepMET_other_mll_);
//---------------------------------------------------------------------------------
/*                         Var_4LepMET_mt2*/  Var_4LepMET_mt2_branch = tree->GetBranch("Var_4LepMET_mt2");
/*                         Var_4LepMET_mt2*/  if (Var_4LepMET_mt2_branch) Var_4LepMET_mt2_branch->SetAddress(&Var_4LepMET_mt2_);
//---------------------------------------------------------------------------------

  tree->SetMakeClass(0);
}

void VVVTree::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
//---------------------------------------------------------------------------------
/*                           Common_isData*/  Common_isData_isLoaded = false;
//---------------------------------------------------------------------------------
/*                              Common_run*/  Common_run_isLoaded = false;
//---------------------------------------------------------------------------------
/*                             Common_lumi*/  Common_lumi_isLoaded = false;
//---------------------------------------------------------------------------------
/*                              Common_evt*/  Common_evt_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_genWeight*/  Common_genWeight_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/  Common_btagWeight_DeepCSVB_isLoaded = false;
//---------------------------------------------------------------------------------
/*         Common_LHEWeight_mg_reweighting*/  Common_LHEWeight_mg_reweighting_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_isLoaded = false;
//---------------------------------------------------------------------------------
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleEl*/  Common_HLT_DoubleEl_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_HLT_MuEG*/  Common_HLT_MuEG_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleMu*/  Common_HLT_DoubleMu_isLoaded = false;
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_ee_em_mm*/  Common_pass_duplicate_removal_ee_em_mm_isLoaded = false;
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_mm_em_ee*/  Common_pass_duplicate_removal_mm_em_ee_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/  Common_noiseFlag_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/  Common_noiseFlagMC_isLoaded = false;
//---------------------------------------------------------------------------------
/*                           Common_met_p4*/  Common_met_p4_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_event_lepSF*/  Common_event_lepSF_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFelup*/  Common_event_lepSFelup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFeldn*/  Common_event_lepSFeldn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmuup*/  Common_event_lepSFmuup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmudn*/  Common_event_lepSFmudn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                           Common_lep_p4*/  Common_lep_p4_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_lep_idxs*/  Common_lep_idxs_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_lep_pdgid*/  Common_lep_pdgid_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_lep_tight*/  Common_lep_tight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                          Common_lep_dxy*/  Common_lep_dxy_isLoaded = false;
//---------------------------------------------------------------------------------
/*                           Common_lep_dz*/  Common_lep_dz_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_lep_ip3d*/  Common_lep_ip3d_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_lep_sip3d*/  Common_lep_sip3d_isLoaded = false;
//---------------------------------------------------------------------------------
/*                           Common_lep_SF*/  Common_lep_SF_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_lep_SFTight*/  Common_lep_SFTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_lep_SFdn*/  Common_lep_SFdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                    Common_lep_SFdnTight*/  Common_lep_SFdnTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_lep_SFup*/  Common_lep_SFup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                    Common_lep_SFupTight*/  Common_lep_SFupTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                           Common_jet_p4*/  Common_jet_p4_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_jet_idxs*/  Common_jet_idxs_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_jet_passBloose*/  Common_jet_passBloose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_jet_passBmedium*/  Common_jet_passBmedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_jet_passBtight*/  Common_jet_passBtight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_jet_overlapfatjet*/  Common_jet_overlapfatjet_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_fatjet_p4*/  Common_fatjet_p4_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_fatjet_idxs*/  Common_fatjet_idxs_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_msoftdrop*/  Common_fatjet_msoftdrop_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_W*/  Common_fatjet_deepMD_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_W*/  Common_fatjet_deep_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_Z*/  Common_fatjet_deepMD_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_Z*/  Common_fatjet_deep_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_T*/  Common_fatjet_deepMD_T_isLoaded = false;
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_T*/  Common_fatjet_deep_T_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_deepMD_bb*/  Common_fatjet_deepMD_bb_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau3*/  Common_fatjet_tau3_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau2*/  Common_fatjet_tau2_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau1*/  Common_fatjet_tau1_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau32*/  Common_fatjet_tau32_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau21*/  Common_fatjet_tau21_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_pt*/  Common_fatjet_subjet0_pt_isLoaded = false;
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_eta*/  Common_fatjet_subjet0_eta_isLoaded = false;
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_phi*/  Common_fatjet_subjet0_phi_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet0_mass*/  Common_fatjet_subjet0_mass_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_pt*/  Common_fatjet_subjet1_pt_isLoaded = false;
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_eta*/  Common_fatjet_subjet1_eta_isLoaded = false;
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_phi*/  Common_fatjet_subjet1_phi_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet1_mass*/  Common_fatjet_subjet1_mass_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_p4*/  Common_fatjet_subjet0_p4_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_p4*/  Common_fatjet_subjet1_p4_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_fatjet_WP*/  Common_fatjet_WP_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_fatjet_WP_antimasscut*/  Common_fatjet_WP_antimasscut_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFVLoose*/  Common_fatjet_SFVLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFLoose*/  Common_fatjet_SFLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFMedium*/  Common_fatjet_SFMedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFTight*/  Common_fatjet_SFTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnVLoose*/  Common_fatjet_SFdnVLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnLoose*/  Common_fatjet_SFdnLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnMedium*/  Common_fatjet_SFdnMedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnTight*/  Common_fatjet_SFdnTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupVLoose*/  Common_fatjet_SFupVLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupLoose*/  Common_fatjet_SFupLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupMedium*/  Common_fatjet_SFupMedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupTight*/  Common_fatjet_SFupTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFVLoose*/  Common_eventweight_fatjet_SFVLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFLoose*/  Common_eventweight_fatjet_SFLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFMedium*/  Common_eventweight_fatjet_SFMedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFTight*/  Common_eventweight_fatjet_SFTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnVLoose*/  Common_eventweight_fatjet_SFdnVLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnLoose*/  Common_eventweight_fatjet_SFdnLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnMedium*/  Common_eventweight_fatjet_SFdnMedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnTight*/  Common_eventweight_fatjet_SFdnTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupVLoose*/  Common_eventweight_fatjet_SFupVLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupLoose*/  Common_eventweight_fatjet_SFupLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupMedium*/  Common_eventweight_fatjet_SFupMedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupTight*/  Common_eventweight_fatjet_SFupTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_nb_loose*/  Common_nb_loose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_nb_medium*/  Common_nb_medium_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_nb_tight*/  Common_nb_tight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                          Common_gen_idx*/  Common_gen_idx_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_gen_mother_idx*/  Common_gen_mother_idx_isLoaded = false;
//---------------------------------------------------------------------------------
/*                    Common_gen_mother_id*/  Common_gen_mother_id_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_gen_pdgid*/  Common_gen_pdgid_isLoaded = false;
//---------------------------------------------------------------------------------
/*                          Common_gen_p4s*/  Common_gen_p4s_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_idx*/  Common_gen_vvvdecay_idx_isLoaded = false;
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_mother_idx*/  Common_gen_vvvdecay_mother_idx_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_gen_vvvdecay_mother_id*/  Common_gen_vvvdecay_mother_id_isLoaded = false;
//---------------------------------------------------------------------------------
/*               Common_gen_vvvdecay_pdgid*/  Common_gen_vvvdecay_pdgid_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_p4s*/  Common_gen_vvvdecay_p4s_isLoaded = false;
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_taudecayid*/  Common_gen_vvvdecay_taudecayid_isLoaded = false;
//---------------------------------------------------------------------------------
/*                              Common_n_W*/  Common_n_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*                              Common_n_Z*/  Common_n_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                          Common_n_lep_Z*/  Common_n_lep_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_Z*/  Common_n_leptau_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_Z*/  Common_n_hadtau_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                           Common_n_nu_Z*/  Common_n_nu_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                            Common_n_b_Z*/  Common_n_b_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                          Common_n_lep_W*/  Common_n_lep_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_W*/  Common_n_leptau_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_W*/  Common_n_hadtau_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_haslepWSS*/  Common_haslepWSS_isLoaded = false;
//---------------------------------------------------------------------------------
/*                            Common_genHT*/  Common_genHT_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_gen_n_light_lep*/  Common_gen_n_light_lep_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_gen_VH_channel*/  Common_gen_VH_channel_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Cut_4LepMET_Preselection*/  Cut_4LepMET_Preselection_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/  Cut_4LepMET_emuChannel_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/  Cut_4LepMET_offzChannel_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/  Cut_4LepMET_onzChannel_isLoaded = false;
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/  Cut_4LepMET_onzChannel_HighMET_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/  Var_4LepMET_Zcand_lep_idx_0_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  Var_4LepMET_Zcand_lep_pdgid_0_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_0*/  Var_4LepMET_Zcand_lep_p4_0_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_1*/  Var_4LepMET_Zcand_lep_idx_1_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  Var_4LepMET_Zcand_lep_pdgid_1_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_1*/  Var_4LepMET_Zcand_lep_p4_1_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_Zcand_mll*/  Var_4LepMET_Zcand_mll_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_0*/  Var_4LepMET_other_lep_idx_0_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_0*/  Var_4LepMET_other_lep_pdgid_0_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_0*/  Var_4LepMET_other_lep_p4_0_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_1*/  Var_4LepMET_other_lep_idx_1_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_1*/  Var_4LepMET_other_lep_pdgid_1_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_1*/  Var_4LepMET_other_lep_p4_1_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_other_mll*/  Var_4LepMET_other_mll_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Var_4LepMET_mt2*/  Var_4LepMET_mt2_isLoaded = false;
//---------------------------------------------------------------------------------
}

void VVVTree::LoadAllBranches() {
  // load all branches
//---------------------------------------------------------------------------------
/*                           Common_isData*/  if (Common_isData_branch != 0) Common_isData();
//---------------------------------------------------------------------------------
/*                              Common_run*/  if (Common_run_branch != 0) Common_run();
//---------------------------------------------------------------------------------
/*                             Common_lumi*/  if (Common_lumi_branch != 0) Common_lumi();
//---------------------------------------------------------------------------------
/*                              Common_evt*/  if (Common_evt_branch != 0) Common_evt();
//---------------------------------------------------------------------------------
/*                        Common_genWeight*/  if (Common_genWeight_branch != 0) Common_genWeight();
//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/  if (Common_btagWeight_DeepCSVB_branch != 0) Common_btagWeight_DeepCSVB();
//---------------------------------------------------------------------------------
/*         Common_LHEWeight_mg_reweighting*/  if (Common_LHEWeight_mg_reweighting_branch != 0) Common_LHEWeight_mg_reweighting();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch != 0) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ();
//---------------------------------------------------------------------------------
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch != 0) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch != 0) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8();
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch != 0) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL();
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleEl*/  if (Common_HLT_DoubleEl_branch != 0) Common_HLT_DoubleEl();
//---------------------------------------------------------------------------------
/*                         Common_HLT_MuEG*/  if (Common_HLT_MuEG_branch != 0) Common_HLT_MuEG();
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleMu*/  if (Common_HLT_DoubleMu_branch != 0) Common_HLT_DoubleMu();
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_ee_em_mm*/  if (Common_pass_duplicate_removal_ee_em_mm_branch != 0) Common_pass_duplicate_removal_ee_em_mm();
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_mm_em_ee*/  if (Common_pass_duplicate_removal_mm_em_ee_branch != 0) Common_pass_duplicate_removal_mm_em_ee();
//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/  if (Common_noiseFlag_branch != 0) Common_noiseFlag();
//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/  if (Common_noiseFlagMC_branch != 0) Common_noiseFlagMC();
//---------------------------------------------------------------------------------
/*                           Common_met_p4*/  if (Common_met_p4_branch != 0) Common_met_p4();
//---------------------------------------------------------------------------------
/*                      Common_event_lepSF*/  if (Common_event_lepSF_branch != 0) Common_event_lepSF();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFelup*/  if (Common_event_lepSFelup_branch != 0) Common_event_lepSFelup();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFeldn*/  if (Common_event_lepSFeldn_branch != 0) Common_event_lepSFeldn();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmuup*/  if (Common_event_lepSFmuup_branch != 0) Common_event_lepSFmuup();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmudn*/  if (Common_event_lepSFmudn_branch != 0) Common_event_lepSFmudn();
//---------------------------------------------------------------------------------
/*                           Common_lep_p4*/  if (Common_lep_p4_branch != 0) Common_lep_p4();
//---------------------------------------------------------------------------------
/*                         Common_lep_idxs*/  if (Common_lep_idxs_branch != 0) Common_lep_idxs();
//---------------------------------------------------------------------------------
/*                        Common_lep_pdgid*/  if (Common_lep_pdgid_branch != 0) Common_lep_pdgid();
//---------------------------------------------------------------------------------
/*                        Common_lep_tight*/  if (Common_lep_tight_branch != 0) Common_lep_tight();
//---------------------------------------------------------------------------------
/*                          Common_lep_dxy*/  if (Common_lep_dxy_branch != 0) Common_lep_dxy();
//---------------------------------------------------------------------------------
/*                           Common_lep_dz*/  if (Common_lep_dz_branch != 0) Common_lep_dz();
//---------------------------------------------------------------------------------
/*                         Common_lep_ip3d*/  if (Common_lep_ip3d_branch != 0) Common_lep_ip3d();
//---------------------------------------------------------------------------------
/*                        Common_lep_sip3d*/  if (Common_lep_sip3d_branch != 0) Common_lep_sip3d();
//---------------------------------------------------------------------------------
/*                           Common_lep_SF*/  if (Common_lep_SF_branch != 0) Common_lep_SF();
//---------------------------------------------------------------------------------
/*                      Common_lep_SFTight*/  if (Common_lep_SFTight_branch != 0) Common_lep_SFTight();
//---------------------------------------------------------------------------------
/*                         Common_lep_SFdn*/  if (Common_lep_SFdn_branch != 0) Common_lep_SFdn();
//---------------------------------------------------------------------------------
/*                    Common_lep_SFdnTight*/  if (Common_lep_SFdnTight_branch != 0) Common_lep_SFdnTight();
//---------------------------------------------------------------------------------
/*                         Common_lep_SFup*/  if (Common_lep_SFup_branch != 0) Common_lep_SFup();
//---------------------------------------------------------------------------------
/*                    Common_lep_SFupTight*/  if (Common_lep_SFupTight_branch != 0) Common_lep_SFupTight();
//---------------------------------------------------------------------------------
/*                           Common_jet_p4*/  if (Common_jet_p4_branch != 0) Common_jet_p4();
//---------------------------------------------------------------------------------
/*                         Common_jet_idxs*/  if (Common_jet_idxs_branch != 0) Common_jet_idxs();
//---------------------------------------------------------------------------------
/*                   Common_jet_passBloose*/  if (Common_jet_passBloose_branch != 0) Common_jet_passBloose();
//---------------------------------------------------------------------------------
/*                  Common_jet_passBmedium*/  if (Common_jet_passBmedium_branch != 0) Common_jet_passBmedium();
//---------------------------------------------------------------------------------
/*                   Common_jet_passBtight*/  if (Common_jet_passBtight_branch != 0) Common_jet_passBtight();
//---------------------------------------------------------------------------------
/*                Common_jet_overlapfatjet*/  if (Common_jet_overlapfatjet_branch != 0) Common_jet_overlapfatjet();
//---------------------------------------------------------------------------------
/*                        Common_fatjet_p4*/  if (Common_fatjet_p4_branch != 0) Common_fatjet_p4();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_idxs*/  if (Common_fatjet_idxs_branch != 0) Common_fatjet_idxs();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_msoftdrop*/  if (Common_fatjet_msoftdrop_branch != 0) Common_fatjet_msoftdrop();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_W*/  if (Common_fatjet_deepMD_W_branch != 0) Common_fatjet_deepMD_W();
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_W*/  if (Common_fatjet_deep_W_branch != 0) Common_fatjet_deep_W();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_Z*/  if (Common_fatjet_deepMD_Z_branch != 0) Common_fatjet_deepMD_Z();
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_Z*/  if (Common_fatjet_deep_Z_branch != 0) Common_fatjet_deep_Z();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_T*/  if (Common_fatjet_deepMD_T_branch != 0) Common_fatjet_deepMD_T();
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_T*/  if (Common_fatjet_deep_T_branch != 0) Common_fatjet_deep_T();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_deepMD_bb*/  if (Common_fatjet_deepMD_bb_branch != 0) Common_fatjet_deepMD_bb();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau3*/  if (Common_fatjet_tau3_branch != 0) Common_fatjet_tau3();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau2*/  if (Common_fatjet_tau2_branch != 0) Common_fatjet_tau2();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau1*/  if (Common_fatjet_tau1_branch != 0) Common_fatjet_tau1();
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau32*/  if (Common_fatjet_tau32_branch != 0) Common_fatjet_tau32();
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau21*/  if (Common_fatjet_tau21_branch != 0) Common_fatjet_tau21();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_pt*/  if (Common_fatjet_subjet0_pt_branch != 0) Common_fatjet_subjet0_pt();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_eta*/  if (Common_fatjet_subjet0_eta_branch != 0) Common_fatjet_subjet0_eta();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_phi*/  if (Common_fatjet_subjet0_phi_branch != 0) Common_fatjet_subjet0_phi();
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet0_mass*/  if (Common_fatjet_subjet0_mass_branch != 0) Common_fatjet_subjet0_mass();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_pt*/  if (Common_fatjet_subjet1_pt_branch != 0) Common_fatjet_subjet1_pt();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_eta*/  if (Common_fatjet_subjet1_eta_branch != 0) Common_fatjet_subjet1_eta();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_phi*/  if (Common_fatjet_subjet1_phi_branch != 0) Common_fatjet_subjet1_phi();
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet1_mass*/  if (Common_fatjet_subjet1_mass_branch != 0) Common_fatjet_subjet1_mass();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_p4*/  if (Common_fatjet_subjet0_p4_branch != 0) Common_fatjet_subjet0_p4();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_p4*/  if (Common_fatjet_subjet1_p4_branch != 0) Common_fatjet_subjet1_p4();
//---------------------------------------------------------------------------------
/*                        Common_fatjet_WP*/  if (Common_fatjet_WP_branch != 0) Common_fatjet_WP();
//---------------------------------------------------------------------------------
/*            Common_fatjet_WP_antimasscut*/  if (Common_fatjet_WP_antimasscut_branch != 0) Common_fatjet_WP_antimasscut();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFVLoose*/  if (Common_fatjet_SFVLoose_branch != 0) Common_fatjet_SFVLoose();
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFLoose*/  if (Common_fatjet_SFLoose_branch != 0) Common_fatjet_SFLoose();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFMedium*/  if (Common_fatjet_SFMedium_branch != 0) Common_fatjet_SFMedium();
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFTight*/  if (Common_fatjet_SFTight_branch != 0) Common_fatjet_SFTight();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnVLoose*/  if (Common_fatjet_SFdnVLoose_branch != 0) Common_fatjet_SFdnVLoose();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnLoose*/  if (Common_fatjet_SFdnLoose_branch != 0) Common_fatjet_SFdnLoose();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnMedium*/  if (Common_fatjet_SFdnMedium_branch != 0) Common_fatjet_SFdnMedium();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnTight*/  if (Common_fatjet_SFdnTight_branch != 0) Common_fatjet_SFdnTight();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupVLoose*/  if (Common_fatjet_SFupVLoose_branch != 0) Common_fatjet_SFupVLoose();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupLoose*/  if (Common_fatjet_SFupLoose_branch != 0) Common_fatjet_SFupLoose();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupMedium*/  if (Common_fatjet_SFupMedium_branch != 0) Common_fatjet_SFupMedium();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupTight*/  if (Common_fatjet_SFupTight_branch != 0) Common_fatjet_SFupTight();
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFVLoose*/  if (Common_eventweight_fatjet_SFVLoose_branch != 0) Common_eventweight_fatjet_SFVLoose();
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFLoose*/  if (Common_eventweight_fatjet_SFLoose_branch != 0) Common_eventweight_fatjet_SFLoose();
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFMedium*/  if (Common_eventweight_fatjet_SFMedium_branch != 0) Common_eventweight_fatjet_SFMedium();
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFTight*/  if (Common_eventweight_fatjet_SFTight_branch != 0) Common_eventweight_fatjet_SFTight();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnVLoose*/  if (Common_eventweight_fatjet_SFdnVLoose_branch != 0) Common_eventweight_fatjet_SFdnVLoose();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnLoose*/  if (Common_eventweight_fatjet_SFdnLoose_branch != 0) Common_eventweight_fatjet_SFdnLoose();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnMedium*/  if (Common_eventweight_fatjet_SFdnMedium_branch != 0) Common_eventweight_fatjet_SFdnMedium();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnTight*/  if (Common_eventweight_fatjet_SFdnTight_branch != 0) Common_eventweight_fatjet_SFdnTight();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupVLoose*/  if (Common_eventweight_fatjet_SFupVLoose_branch != 0) Common_eventweight_fatjet_SFupVLoose();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupLoose*/  if (Common_eventweight_fatjet_SFupLoose_branch != 0) Common_eventweight_fatjet_SFupLoose();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupMedium*/  if (Common_eventweight_fatjet_SFupMedium_branch != 0) Common_eventweight_fatjet_SFupMedium();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupTight*/  if (Common_eventweight_fatjet_SFupTight_branch != 0) Common_eventweight_fatjet_SFupTight();
//---------------------------------------------------------------------------------
/*                         Common_nb_loose*/  if (Common_nb_loose_branch != 0) Common_nb_loose();
//---------------------------------------------------------------------------------
/*                        Common_nb_medium*/  if (Common_nb_medium_branch != 0) Common_nb_medium();
//---------------------------------------------------------------------------------
/*                         Common_nb_tight*/  if (Common_nb_tight_branch != 0) Common_nb_tight();
//---------------------------------------------------------------------------------
/*                          Common_gen_idx*/  if (Common_gen_idx_branch != 0) Common_gen_idx();
//---------------------------------------------------------------------------------
/*                   Common_gen_mother_idx*/  if (Common_gen_mother_idx_branch != 0) Common_gen_mother_idx();
//---------------------------------------------------------------------------------
/*                    Common_gen_mother_id*/  if (Common_gen_mother_id_branch != 0) Common_gen_mother_id();
//---------------------------------------------------------------------------------
/*                        Common_gen_pdgid*/  if (Common_gen_pdgid_branch != 0) Common_gen_pdgid();
//---------------------------------------------------------------------------------
/*                          Common_gen_p4s*/  if (Common_gen_p4s_branch != 0) Common_gen_p4s();
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_idx*/  if (Common_gen_vvvdecay_idx_branch != 0) Common_gen_vvvdecay_idx();
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_mother_idx*/  if (Common_gen_vvvdecay_mother_idx_branch != 0) Common_gen_vvvdecay_mother_idx();
//---------------------------------------------------------------------------------
/*           Common_gen_vvvdecay_mother_id*/  if (Common_gen_vvvdecay_mother_id_branch != 0) Common_gen_vvvdecay_mother_id();
//---------------------------------------------------------------------------------
/*               Common_gen_vvvdecay_pdgid*/  if (Common_gen_vvvdecay_pdgid_branch != 0) Common_gen_vvvdecay_pdgid();
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_p4s*/  if (Common_gen_vvvdecay_p4s_branch != 0) Common_gen_vvvdecay_p4s();
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_taudecayid*/  if (Common_gen_vvvdecay_taudecayid_branch != 0) Common_gen_vvvdecay_taudecayid();
//---------------------------------------------------------------------------------
/*                              Common_n_W*/  if (Common_n_W_branch != 0) Common_n_W();
//---------------------------------------------------------------------------------
/*                              Common_n_Z*/  if (Common_n_Z_branch != 0) Common_n_Z();
//---------------------------------------------------------------------------------
/*                          Common_n_lep_Z*/  if (Common_n_lep_Z_branch != 0) Common_n_lep_Z();
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_Z*/  if (Common_n_leptau_Z_branch != 0) Common_n_leptau_Z();
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_Z*/  if (Common_n_hadtau_Z_branch != 0) Common_n_hadtau_Z();
//---------------------------------------------------------------------------------
/*                           Common_n_nu_Z*/  if (Common_n_nu_Z_branch != 0) Common_n_nu_Z();
//---------------------------------------------------------------------------------
/*                            Common_n_b_Z*/  if (Common_n_b_Z_branch != 0) Common_n_b_Z();
//---------------------------------------------------------------------------------
/*                          Common_n_lep_W*/  if (Common_n_lep_W_branch != 0) Common_n_lep_W();
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_W*/  if (Common_n_leptau_W_branch != 0) Common_n_leptau_W();
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_W*/  if (Common_n_hadtau_W_branch != 0) Common_n_hadtau_W();
//---------------------------------------------------------------------------------
/*                        Common_haslepWSS*/  if (Common_haslepWSS_branch != 0) Common_haslepWSS();
//---------------------------------------------------------------------------------
/*                            Common_genHT*/  if (Common_genHT_branch != 0) Common_genHT();
//---------------------------------------------------------------------------------
/*                  Common_gen_n_light_lep*/  if (Common_gen_n_light_lep_branch != 0) Common_gen_n_light_lep();
//---------------------------------------------------------------------------------
/*                   Common_gen_VH_channel*/  if (Common_gen_VH_channel_branch != 0) Common_gen_VH_channel();
//---------------------------------------------------------------------------------
/*                Cut_4LepMET_Preselection*/  if (Cut_4LepMET_Preselection_branch != 0) Cut_4LepMET_Preselection();
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/  if (Cut_4LepMET_emuChannel_branch != 0) Cut_4LepMET_emuChannel();
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/  if (Cut_4LepMET_offzChannel_branch != 0) Cut_4LepMET_offzChannel();
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/  if (Cut_4LepMET_onzChannel_branch != 0) Cut_4LepMET_onzChannel();
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/  if (Cut_4LepMET_onzChannel_HighMET_branch != 0) Cut_4LepMET_onzChannel_HighMET();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/  if (Var_4LepMET_Zcand_lep_idx_0_branch != 0) Var_4LepMET_Zcand_lep_idx_0();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  if (Var_4LepMET_Zcand_lep_pdgid_0_branch != 0) Var_4LepMET_Zcand_lep_pdgid_0();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_0*/  if (Var_4LepMET_Zcand_lep_p4_0_branch != 0) Var_4LepMET_Zcand_lep_p4_0();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_1*/  if (Var_4LepMET_Zcand_lep_idx_1_branch != 0) Var_4LepMET_Zcand_lep_idx_1();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  if (Var_4LepMET_Zcand_lep_pdgid_1_branch != 0) Var_4LepMET_Zcand_lep_pdgid_1();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_1*/  if (Var_4LepMET_Zcand_lep_p4_1_branch != 0) Var_4LepMET_Zcand_lep_p4_1();
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_Zcand_mll*/  if (Var_4LepMET_Zcand_mll_branch != 0) Var_4LepMET_Zcand_mll();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_0*/  if (Var_4LepMET_other_lep_idx_0_branch != 0) Var_4LepMET_other_lep_idx_0();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_0*/  if (Var_4LepMET_other_lep_pdgid_0_branch != 0) Var_4LepMET_other_lep_pdgid_0();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_0*/  if (Var_4LepMET_other_lep_p4_0_branch != 0) Var_4LepMET_other_lep_p4_0();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_1*/  if (Var_4LepMET_other_lep_idx_1_branch != 0) Var_4LepMET_other_lep_idx_1();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_1*/  if (Var_4LepMET_other_lep_pdgid_1_branch != 0) Var_4LepMET_other_lep_pdgid_1();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_1*/  if (Var_4LepMET_other_lep_p4_1_branch != 0) Var_4LepMET_other_lep_p4_1();
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_other_mll*/  if (Var_4LepMET_other_mll_branch != 0) Var_4LepMET_other_mll();
//---------------------------------------------------------------------------------
/*                         Var_4LepMET_mt2*/  if (Var_4LepMET_mt2_branch != 0) Var_4LepMET_mt2();
//---------------------------------------------------------------------------------
}

//---------------------------------------------------------------------------------
/*                           Common_isData*/const int &VVVTree::Common_isData() {
/*                           Common_isData*/  if (not Common_isData_isLoaded) {
/*                           Common_isData*/    if (Common_isData_branch != 0) {
/*                           Common_isData*/      Common_isData_branch->GetEntry(index);
/*                           Common_isData*/    } else {
/*                           Common_isData*/      printf("branch Common_isData_branch does not exist!\n");
/*                           Common_isData*/      exit(1);
/*                           Common_isData*/    }
/*                           Common_isData*/    Common_isData_isLoaded = true;
/*                           Common_isData*/  }
/*                           Common_isData*/  return Common_isData_;
/*                           Common_isData*/}

//---------------------------------------------------------------------------------
/*                              Common_run*/const int &VVVTree::Common_run() {
/*                              Common_run*/  if (not Common_run_isLoaded) {
/*                              Common_run*/    if (Common_run_branch != 0) {
/*                              Common_run*/      Common_run_branch->GetEntry(index);
/*                              Common_run*/    } else {
/*                              Common_run*/      printf("branch Common_run_branch does not exist!\n");
/*                              Common_run*/      exit(1);
/*                              Common_run*/    }
/*                              Common_run*/    Common_run_isLoaded = true;
/*                              Common_run*/  }
/*                              Common_run*/  return Common_run_;
/*                              Common_run*/}

//---------------------------------------------------------------------------------
/*                             Common_lumi*/const int &VVVTree::Common_lumi() {
/*                             Common_lumi*/  if (not Common_lumi_isLoaded) {
/*                             Common_lumi*/    if (Common_lumi_branch != 0) {
/*                             Common_lumi*/      Common_lumi_branch->GetEntry(index);
/*                             Common_lumi*/    } else {
/*                             Common_lumi*/      printf("branch Common_lumi_branch does not exist!\n");
/*                             Common_lumi*/      exit(1);
/*                             Common_lumi*/    }
/*                             Common_lumi*/    Common_lumi_isLoaded = true;
/*                             Common_lumi*/  }
/*                             Common_lumi*/  return Common_lumi_;
/*                             Common_lumi*/}

//---------------------------------------------------------------------------------
/*                              Common_evt*/const unsigned long long &VVVTree::Common_evt() {
/*                              Common_evt*/  if (not Common_evt_isLoaded) {
/*                              Common_evt*/    if (Common_evt_branch != 0) {
/*                              Common_evt*/      Common_evt_branch->GetEntry(index);
/*                              Common_evt*/    } else {
/*                              Common_evt*/      printf("branch Common_evt_branch does not exist!\n");
/*                              Common_evt*/      exit(1);
/*                              Common_evt*/    }
/*                              Common_evt*/    Common_evt_isLoaded = true;
/*                              Common_evt*/  }
/*                              Common_evt*/  return Common_evt_;
/*                              Common_evt*/}

//---------------------------------------------------------------------------------
/*                        Common_genWeight*/const float &VVVTree::Common_genWeight() {
/*                        Common_genWeight*/  if (not Common_genWeight_isLoaded) {
/*                        Common_genWeight*/    if (Common_genWeight_branch != 0) {
/*                        Common_genWeight*/      Common_genWeight_branch->GetEntry(index);
/*                        Common_genWeight*/    } else {
/*                        Common_genWeight*/      printf("branch Common_genWeight_branch does not exist!\n");
/*                        Common_genWeight*/      exit(1);
/*                        Common_genWeight*/    }
/*                        Common_genWeight*/    Common_genWeight_isLoaded = true;
/*                        Common_genWeight*/  }
/*                        Common_genWeight*/  return Common_genWeight_;
/*                        Common_genWeight*/}

//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/const float &VVVTree::Common_btagWeight_DeepCSVB() {
/*              Common_btagWeight_DeepCSVB*/  if (not Common_btagWeight_DeepCSVB_isLoaded) {
/*              Common_btagWeight_DeepCSVB*/    if (Common_btagWeight_DeepCSVB_branch != 0) {
/*              Common_btagWeight_DeepCSVB*/      Common_btagWeight_DeepCSVB_branch->GetEntry(index);
/*              Common_btagWeight_DeepCSVB*/    } else {
/*              Common_btagWeight_DeepCSVB*/      printf("branch Common_btagWeight_DeepCSVB_branch does not exist!\n");
/*              Common_btagWeight_DeepCSVB*/      exit(1);
/*              Common_btagWeight_DeepCSVB*/    }
/*              Common_btagWeight_DeepCSVB*/    Common_btagWeight_DeepCSVB_isLoaded = true;
/*              Common_btagWeight_DeepCSVB*/  }
/*              Common_btagWeight_DeepCSVB*/  return Common_btagWeight_DeepCSVB_;
/*              Common_btagWeight_DeepCSVB*/}

//---------------------------------------------------------------------------------
/*         Common_LHEWeight_mg_reweighting*/const vector<float> &VVVTree::Common_LHEWeight_mg_reweighting() {
/*         Common_LHEWeight_mg_reweighting*/  if (not Common_LHEWeight_mg_reweighting_isLoaded) {
/*         Common_LHEWeight_mg_reweighting*/    if (Common_LHEWeight_mg_reweighting_branch != 0) {
/*         Common_LHEWeight_mg_reweighting*/      Common_LHEWeight_mg_reweighting_branch->GetEntry(index);
/*         Common_LHEWeight_mg_reweighting*/    } else {
/*         Common_LHEWeight_mg_reweighting*/      printf("branch Common_LHEWeight_mg_reweighting_branch does not exist!\n");
/*         Common_LHEWeight_mg_reweighting*/      exit(1);
/*         Common_LHEWeight_mg_reweighting*/    }
/*         Common_LHEWeight_mg_reweighting*/    Common_LHEWeight_mg_reweighting_isLoaded = true;
/*         Common_LHEWeight_mg_reweighting*/  }
/*         Common_LHEWeight_mg_reweighting*/  return *Common_LHEWeight_mg_reweighting_;
/*         Common_LHEWeight_mg_reweighting*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/const bool &VVVTree::Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ() {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  if (not Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_isLoaded) {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/    if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch != 0) {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/      Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch->GetEntry(index);
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/    } else {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/      printf("branch Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch does not exist!\n");
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/      exit(1);
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/    }
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/    Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_isLoaded = true;
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  }
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  return Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_;
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/}

//---------------------------------------------------------------------------------
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/const bool &VVVTree::Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL() {
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  if (not Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_isLoaded) {
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/    if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch != 0) {
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/      Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch->GetEntry(index);
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/    } else {
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/      printf("branch Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch does not exist!\n");
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/      exit(1);
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/    }
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/    Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_isLoaded = true;
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  }
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  return Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_;
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/const bool &VVVTree::Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8() {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  if (not Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_isLoaded) {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/    if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch != 0) {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/      Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch->GetEntry(index);
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/    } else {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/      printf("branch Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch does not exist!\n");
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/      exit(1);
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/    }
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/    Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_isLoaded = true;
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  }
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  return Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_;
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/const bool &VVVTree::Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  if (not Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded) {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/      Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch->GetEntry(index);
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    } else {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/      printf("branch Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch does not exist!\n");
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/      exit(1);
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    }
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = true;
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  }
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  return Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_;
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/const bool &VVVTree::Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL() {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  if (not Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded) {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/    if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/      Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch->GetEntry(index);
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/    } else {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/      printf("branch Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch does not exist!\n");
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/      exit(1);
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/    }
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/    Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = true;
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  }
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  return Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_;
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/const bool &VVVTree::Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  if (not Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded) {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/      Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch->GetEntry(index);
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    } else {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/      printf("branch Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch does not exist!\n");
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/      exit(1);
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    }
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = true;
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  }
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  return Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_;
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/const bool &VVVTree::Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL() {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  if (not Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded) {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/    if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/      Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch->GetEntry(index);
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/    } else {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/      printf("branch Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch does not exist!\n");
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/      exit(1);
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/    }
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/    Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = true;
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  }
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  return Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_;
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/const bool &VVVTree::Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ() {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  if (not Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded) {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/    if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/      Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch->GetEntry(index);
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/    } else {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/      printf("branch Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch does not exist!\n");
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/      exit(1);
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/    }
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/    Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = true;
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  }
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  return Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_;
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/const bool &VVVTree::Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL() {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  if (not Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_isLoaded) {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/    if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch != 0) {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/      Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch->GetEntry(index);
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/    } else {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/      printf("branch Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch does not exist!\n");
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/      exit(1);
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/    }
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/    Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_isLoaded = true;
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  }
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  return Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_;
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/}

//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleEl*/const bool &VVVTree::Common_HLT_DoubleEl() {
/*                     Common_HLT_DoubleEl*/  if (not Common_HLT_DoubleEl_isLoaded) {
/*                     Common_HLT_DoubleEl*/    if (Common_HLT_DoubleEl_branch != 0) {
/*                     Common_HLT_DoubleEl*/      Common_HLT_DoubleEl_branch->GetEntry(index);
/*                     Common_HLT_DoubleEl*/    } else {
/*                     Common_HLT_DoubleEl*/      printf("branch Common_HLT_DoubleEl_branch does not exist!\n");
/*                     Common_HLT_DoubleEl*/      exit(1);
/*                     Common_HLT_DoubleEl*/    }
/*                     Common_HLT_DoubleEl*/    Common_HLT_DoubleEl_isLoaded = true;
/*                     Common_HLT_DoubleEl*/  }
/*                     Common_HLT_DoubleEl*/  return Common_HLT_DoubleEl_;
/*                     Common_HLT_DoubleEl*/}

//---------------------------------------------------------------------------------
/*                         Common_HLT_MuEG*/const bool &VVVTree::Common_HLT_MuEG() {
/*                         Common_HLT_MuEG*/  if (not Common_HLT_MuEG_isLoaded) {
/*                         Common_HLT_MuEG*/    if (Common_HLT_MuEG_branch != 0) {
/*                         Common_HLT_MuEG*/      Common_HLT_MuEG_branch->GetEntry(index);
/*                         Common_HLT_MuEG*/    } else {
/*                         Common_HLT_MuEG*/      printf("branch Common_HLT_MuEG_branch does not exist!\n");
/*                         Common_HLT_MuEG*/      exit(1);
/*                         Common_HLT_MuEG*/    }
/*                         Common_HLT_MuEG*/    Common_HLT_MuEG_isLoaded = true;
/*                         Common_HLT_MuEG*/  }
/*                         Common_HLT_MuEG*/  return Common_HLT_MuEG_;
/*                         Common_HLT_MuEG*/}

//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleMu*/const bool &VVVTree::Common_HLT_DoubleMu() {
/*                     Common_HLT_DoubleMu*/  if (not Common_HLT_DoubleMu_isLoaded) {
/*                     Common_HLT_DoubleMu*/    if (Common_HLT_DoubleMu_branch != 0) {
/*                     Common_HLT_DoubleMu*/      Common_HLT_DoubleMu_branch->GetEntry(index);
/*                     Common_HLT_DoubleMu*/    } else {
/*                     Common_HLT_DoubleMu*/      printf("branch Common_HLT_DoubleMu_branch does not exist!\n");
/*                     Common_HLT_DoubleMu*/      exit(1);
/*                     Common_HLT_DoubleMu*/    }
/*                     Common_HLT_DoubleMu*/    Common_HLT_DoubleMu_isLoaded = true;
/*                     Common_HLT_DoubleMu*/  }
/*                     Common_HLT_DoubleMu*/  return Common_HLT_DoubleMu_;
/*                     Common_HLT_DoubleMu*/}

//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_ee_em_mm*/const bool &VVVTree::Common_pass_duplicate_removal_ee_em_mm() {
/*  Common_pass_duplicate_removal_ee_em_mm*/  if (not Common_pass_duplicate_removal_ee_em_mm_isLoaded) {
/*  Common_pass_duplicate_removal_ee_em_mm*/    if (Common_pass_duplicate_removal_ee_em_mm_branch != 0) {
/*  Common_pass_duplicate_removal_ee_em_mm*/      Common_pass_duplicate_removal_ee_em_mm_branch->GetEntry(index);
/*  Common_pass_duplicate_removal_ee_em_mm*/    } else {
/*  Common_pass_duplicate_removal_ee_em_mm*/      printf("branch Common_pass_duplicate_removal_ee_em_mm_branch does not exist!\n");
/*  Common_pass_duplicate_removal_ee_em_mm*/      exit(1);
/*  Common_pass_duplicate_removal_ee_em_mm*/    }
/*  Common_pass_duplicate_removal_ee_em_mm*/    Common_pass_duplicate_removal_ee_em_mm_isLoaded = true;
/*  Common_pass_duplicate_removal_ee_em_mm*/  }
/*  Common_pass_duplicate_removal_ee_em_mm*/  return Common_pass_duplicate_removal_ee_em_mm_;
/*  Common_pass_duplicate_removal_ee_em_mm*/}

//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_mm_em_ee*/const bool &VVVTree::Common_pass_duplicate_removal_mm_em_ee() {
/*  Common_pass_duplicate_removal_mm_em_ee*/  if (not Common_pass_duplicate_removal_mm_em_ee_isLoaded) {
/*  Common_pass_duplicate_removal_mm_em_ee*/    if (Common_pass_duplicate_removal_mm_em_ee_branch != 0) {
/*  Common_pass_duplicate_removal_mm_em_ee*/      Common_pass_duplicate_removal_mm_em_ee_branch->GetEntry(index);
/*  Common_pass_duplicate_removal_mm_em_ee*/    } else {
/*  Common_pass_duplicate_removal_mm_em_ee*/      printf("branch Common_pass_duplicate_removal_mm_em_ee_branch does not exist!\n");
/*  Common_pass_duplicate_removal_mm_em_ee*/      exit(1);
/*  Common_pass_duplicate_removal_mm_em_ee*/    }
/*  Common_pass_duplicate_removal_mm_em_ee*/    Common_pass_duplicate_removal_mm_em_ee_isLoaded = true;
/*  Common_pass_duplicate_removal_mm_em_ee*/  }
/*  Common_pass_duplicate_removal_mm_em_ee*/  return Common_pass_duplicate_removal_mm_em_ee_;
/*  Common_pass_duplicate_removal_mm_em_ee*/}

//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/const bool &VVVTree::Common_noiseFlag() {
/*                        Common_noiseFlag*/  if (not Common_noiseFlag_isLoaded) {
/*                        Common_noiseFlag*/    if (Common_noiseFlag_branch != 0) {
/*                        Common_noiseFlag*/      Common_noiseFlag_branch->GetEntry(index);
/*                        Common_noiseFlag*/    } else {
/*                        Common_noiseFlag*/      printf("branch Common_noiseFlag_branch does not exist!\n");
/*                        Common_noiseFlag*/      exit(1);
/*                        Common_noiseFlag*/    }
/*                        Common_noiseFlag*/    Common_noiseFlag_isLoaded = true;
/*                        Common_noiseFlag*/  }
/*                        Common_noiseFlag*/  return Common_noiseFlag_;
/*                        Common_noiseFlag*/}

//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/const bool &VVVTree::Common_noiseFlagMC() {
/*                      Common_noiseFlagMC*/  if (not Common_noiseFlagMC_isLoaded) {
/*                      Common_noiseFlagMC*/    if (Common_noiseFlagMC_branch != 0) {
/*                      Common_noiseFlagMC*/      Common_noiseFlagMC_branch->GetEntry(index);
/*                      Common_noiseFlagMC*/    } else {
/*                      Common_noiseFlagMC*/      printf("branch Common_noiseFlagMC_branch does not exist!\n");
/*                      Common_noiseFlagMC*/      exit(1);
/*                      Common_noiseFlagMC*/    }
/*                      Common_noiseFlagMC*/    Common_noiseFlagMC_isLoaded = true;
/*                      Common_noiseFlagMC*/  }
/*                      Common_noiseFlagMC*/  return Common_noiseFlagMC_;
/*                      Common_noiseFlagMC*/}

//---------------------------------------------------------------------------------
/*                           Common_met_p4*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Common_met_p4() {
/*                           Common_met_p4*/  if (not Common_met_p4_isLoaded) {
/*                           Common_met_p4*/    if (Common_met_p4_branch != 0) {
/*                           Common_met_p4*/      Common_met_p4_branch->GetEntry(index);
/*                           Common_met_p4*/    } else {
/*                           Common_met_p4*/      printf("branch Common_met_p4_branch does not exist!\n");
/*                           Common_met_p4*/      exit(1);
/*                           Common_met_p4*/    }
/*                           Common_met_p4*/    Common_met_p4_isLoaded = true;
/*                           Common_met_p4*/  }
/*                           Common_met_p4*/  return *Common_met_p4_;
/*                           Common_met_p4*/}

//---------------------------------------------------------------------------------
/*                      Common_event_lepSF*/const float &VVVTree::Common_event_lepSF() {
/*                      Common_event_lepSF*/  if (not Common_event_lepSF_isLoaded) {
/*                      Common_event_lepSF*/    if (Common_event_lepSF_branch != 0) {
/*                      Common_event_lepSF*/      Common_event_lepSF_branch->GetEntry(index);
/*                      Common_event_lepSF*/    } else {
/*                      Common_event_lepSF*/      printf("branch Common_event_lepSF_branch does not exist!\n");
/*                      Common_event_lepSF*/      exit(1);
/*                      Common_event_lepSF*/    }
/*                      Common_event_lepSF*/    Common_event_lepSF_isLoaded = true;
/*                      Common_event_lepSF*/  }
/*                      Common_event_lepSF*/  return Common_event_lepSF_;
/*                      Common_event_lepSF*/}

//---------------------------------------------------------------------------------
/*                  Common_event_lepSFelup*/const float &VVVTree::Common_event_lepSFelup() {
/*                  Common_event_lepSFelup*/  if (not Common_event_lepSFelup_isLoaded) {
/*                  Common_event_lepSFelup*/    if (Common_event_lepSFelup_branch != 0) {
/*                  Common_event_lepSFelup*/      Common_event_lepSFelup_branch->GetEntry(index);
/*                  Common_event_lepSFelup*/    } else {
/*                  Common_event_lepSFelup*/      printf("branch Common_event_lepSFelup_branch does not exist!\n");
/*                  Common_event_lepSFelup*/      exit(1);
/*                  Common_event_lepSFelup*/    }
/*                  Common_event_lepSFelup*/    Common_event_lepSFelup_isLoaded = true;
/*                  Common_event_lepSFelup*/  }
/*                  Common_event_lepSFelup*/  return Common_event_lepSFelup_;
/*                  Common_event_lepSFelup*/}

//---------------------------------------------------------------------------------
/*                  Common_event_lepSFeldn*/const float &VVVTree::Common_event_lepSFeldn() {
/*                  Common_event_lepSFeldn*/  if (not Common_event_lepSFeldn_isLoaded) {
/*                  Common_event_lepSFeldn*/    if (Common_event_lepSFeldn_branch != 0) {
/*                  Common_event_lepSFeldn*/      Common_event_lepSFeldn_branch->GetEntry(index);
/*                  Common_event_lepSFeldn*/    } else {
/*                  Common_event_lepSFeldn*/      printf("branch Common_event_lepSFeldn_branch does not exist!\n");
/*                  Common_event_lepSFeldn*/      exit(1);
/*                  Common_event_lepSFeldn*/    }
/*                  Common_event_lepSFeldn*/    Common_event_lepSFeldn_isLoaded = true;
/*                  Common_event_lepSFeldn*/  }
/*                  Common_event_lepSFeldn*/  return Common_event_lepSFeldn_;
/*                  Common_event_lepSFeldn*/}

//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmuup*/const float &VVVTree::Common_event_lepSFmuup() {
/*                  Common_event_lepSFmuup*/  if (not Common_event_lepSFmuup_isLoaded) {
/*                  Common_event_lepSFmuup*/    if (Common_event_lepSFmuup_branch != 0) {
/*                  Common_event_lepSFmuup*/      Common_event_lepSFmuup_branch->GetEntry(index);
/*                  Common_event_lepSFmuup*/    } else {
/*                  Common_event_lepSFmuup*/      printf("branch Common_event_lepSFmuup_branch does not exist!\n");
/*                  Common_event_lepSFmuup*/      exit(1);
/*                  Common_event_lepSFmuup*/    }
/*                  Common_event_lepSFmuup*/    Common_event_lepSFmuup_isLoaded = true;
/*                  Common_event_lepSFmuup*/  }
/*                  Common_event_lepSFmuup*/  return Common_event_lepSFmuup_;
/*                  Common_event_lepSFmuup*/}

//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmudn*/const float &VVVTree::Common_event_lepSFmudn() {
/*                  Common_event_lepSFmudn*/  if (not Common_event_lepSFmudn_isLoaded) {
/*                  Common_event_lepSFmudn*/    if (Common_event_lepSFmudn_branch != 0) {
/*                  Common_event_lepSFmudn*/      Common_event_lepSFmudn_branch->GetEntry(index);
/*                  Common_event_lepSFmudn*/    } else {
/*                  Common_event_lepSFmudn*/      printf("branch Common_event_lepSFmudn_branch does not exist!\n");
/*                  Common_event_lepSFmudn*/      exit(1);
/*                  Common_event_lepSFmudn*/    }
/*                  Common_event_lepSFmudn*/    Common_event_lepSFmudn_isLoaded = true;
/*                  Common_event_lepSFmudn*/  }
/*                  Common_event_lepSFmudn*/  return Common_event_lepSFmudn_;
/*                  Common_event_lepSFmudn*/}

//---------------------------------------------------------------------------------
/*                           Common_lep_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_lep_p4() {
/*                           Common_lep_p4*/  if (not Common_lep_p4_isLoaded) {
/*                           Common_lep_p4*/    if (Common_lep_p4_branch != 0) {
/*                           Common_lep_p4*/      Common_lep_p4_branch->GetEntry(index);
/*                           Common_lep_p4*/    } else {
/*                           Common_lep_p4*/      printf("branch Common_lep_p4_branch does not exist!\n");
/*                           Common_lep_p4*/      exit(1);
/*                           Common_lep_p4*/    }
/*                           Common_lep_p4*/    Common_lep_p4_isLoaded = true;
/*                           Common_lep_p4*/  }
/*                           Common_lep_p4*/  return *Common_lep_p4_;
/*                           Common_lep_p4*/}

//---------------------------------------------------------------------------------
/*                         Common_lep_idxs*/const vector<int> &VVVTree::Common_lep_idxs() {
/*                         Common_lep_idxs*/  if (not Common_lep_idxs_isLoaded) {
/*                         Common_lep_idxs*/    if (Common_lep_idxs_branch != 0) {
/*                         Common_lep_idxs*/      Common_lep_idxs_branch->GetEntry(index);
/*                         Common_lep_idxs*/    } else {
/*                         Common_lep_idxs*/      printf("branch Common_lep_idxs_branch does not exist!\n");
/*                         Common_lep_idxs*/      exit(1);
/*                         Common_lep_idxs*/    }
/*                         Common_lep_idxs*/    Common_lep_idxs_isLoaded = true;
/*                         Common_lep_idxs*/  }
/*                         Common_lep_idxs*/  return *Common_lep_idxs_;
/*                         Common_lep_idxs*/}

//---------------------------------------------------------------------------------
/*                        Common_lep_pdgid*/const vector<int> &VVVTree::Common_lep_pdgid() {
/*                        Common_lep_pdgid*/  if (not Common_lep_pdgid_isLoaded) {
/*                        Common_lep_pdgid*/    if (Common_lep_pdgid_branch != 0) {
/*                        Common_lep_pdgid*/      Common_lep_pdgid_branch->GetEntry(index);
/*                        Common_lep_pdgid*/    } else {
/*                        Common_lep_pdgid*/      printf("branch Common_lep_pdgid_branch does not exist!\n");
/*                        Common_lep_pdgid*/      exit(1);
/*                        Common_lep_pdgid*/    }
/*                        Common_lep_pdgid*/    Common_lep_pdgid_isLoaded = true;
/*                        Common_lep_pdgid*/  }
/*                        Common_lep_pdgid*/  return *Common_lep_pdgid_;
/*                        Common_lep_pdgid*/}

//---------------------------------------------------------------------------------
/*                        Common_lep_tight*/const vector<int> &VVVTree::Common_lep_tight() {
/*                        Common_lep_tight*/  if (not Common_lep_tight_isLoaded) {
/*                        Common_lep_tight*/    if (Common_lep_tight_branch != 0) {
/*                        Common_lep_tight*/      Common_lep_tight_branch->GetEntry(index);
/*                        Common_lep_tight*/    } else {
/*                        Common_lep_tight*/      printf("branch Common_lep_tight_branch does not exist!\n");
/*                        Common_lep_tight*/      exit(1);
/*                        Common_lep_tight*/    }
/*                        Common_lep_tight*/    Common_lep_tight_isLoaded = true;
/*                        Common_lep_tight*/  }
/*                        Common_lep_tight*/  return *Common_lep_tight_;
/*                        Common_lep_tight*/}

//---------------------------------------------------------------------------------
/*                          Common_lep_dxy*/const vector<float> &VVVTree::Common_lep_dxy() {
/*                          Common_lep_dxy*/  if (not Common_lep_dxy_isLoaded) {
/*                          Common_lep_dxy*/    if (Common_lep_dxy_branch != 0) {
/*                          Common_lep_dxy*/      Common_lep_dxy_branch->GetEntry(index);
/*                          Common_lep_dxy*/    } else {
/*                          Common_lep_dxy*/      printf("branch Common_lep_dxy_branch does not exist!\n");
/*                          Common_lep_dxy*/      exit(1);
/*                          Common_lep_dxy*/    }
/*                          Common_lep_dxy*/    Common_lep_dxy_isLoaded = true;
/*                          Common_lep_dxy*/  }
/*                          Common_lep_dxy*/  return *Common_lep_dxy_;
/*                          Common_lep_dxy*/}

//---------------------------------------------------------------------------------
/*                           Common_lep_dz*/const vector<float> &VVVTree::Common_lep_dz() {
/*                           Common_lep_dz*/  if (not Common_lep_dz_isLoaded) {
/*                           Common_lep_dz*/    if (Common_lep_dz_branch != 0) {
/*                           Common_lep_dz*/      Common_lep_dz_branch->GetEntry(index);
/*                           Common_lep_dz*/    } else {
/*                           Common_lep_dz*/      printf("branch Common_lep_dz_branch does not exist!\n");
/*                           Common_lep_dz*/      exit(1);
/*                           Common_lep_dz*/    }
/*                           Common_lep_dz*/    Common_lep_dz_isLoaded = true;
/*                           Common_lep_dz*/  }
/*                           Common_lep_dz*/  return *Common_lep_dz_;
/*                           Common_lep_dz*/}

//---------------------------------------------------------------------------------
/*                         Common_lep_ip3d*/const vector<float> &VVVTree::Common_lep_ip3d() {
/*                         Common_lep_ip3d*/  if (not Common_lep_ip3d_isLoaded) {
/*                         Common_lep_ip3d*/    if (Common_lep_ip3d_branch != 0) {
/*                         Common_lep_ip3d*/      Common_lep_ip3d_branch->GetEntry(index);
/*                         Common_lep_ip3d*/    } else {
/*                         Common_lep_ip3d*/      printf("branch Common_lep_ip3d_branch does not exist!\n");
/*                         Common_lep_ip3d*/      exit(1);
/*                         Common_lep_ip3d*/    }
/*                         Common_lep_ip3d*/    Common_lep_ip3d_isLoaded = true;
/*                         Common_lep_ip3d*/  }
/*                         Common_lep_ip3d*/  return *Common_lep_ip3d_;
/*                         Common_lep_ip3d*/}

//---------------------------------------------------------------------------------
/*                        Common_lep_sip3d*/const vector<float> &VVVTree::Common_lep_sip3d() {
/*                        Common_lep_sip3d*/  if (not Common_lep_sip3d_isLoaded) {
/*                        Common_lep_sip3d*/    if (Common_lep_sip3d_branch != 0) {
/*                        Common_lep_sip3d*/      Common_lep_sip3d_branch->GetEntry(index);
/*                        Common_lep_sip3d*/    } else {
/*                        Common_lep_sip3d*/      printf("branch Common_lep_sip3d_branch does not exist!\n");
/*                        Common_lep_sip3d*/      exit(1);
/*                        Common_lep_sip3d*/    }
/*                        Common_lep_sip3d*/    Common_lep_sip3d_isLoaded = true;
/*                        Common_lep_sip3d*/  }
/*                        Common_lep_sip3d*/  return *Common_lep_sip3d_;
/*                        Common_lep_sip3d*/}

//---------------------------------------------------------------------------------
/*                           Common_lep_SF*/const vector<float> &VVVTree::Common_lep_SF() {
/*                           Common_lep_SF*/  if (not Common_lep_SF_isLoaded) {
/*                           Common_lep_SF*/    if (Common_lep_SF_branch != 0) {
/*                           Common_lep_SF*/      Common_lep_SF_branch->GetEntry(index);
/*                           Common_lep_SF*/    } else {
/*                           Common_lep_SF*/      printf("branch Common_lep_SF_branch does not exist!\n");
/*                           Common_lep_SF*/      exit(1);
/*                           Common_lep_SF*/    }
/*                           Common_lep_SF*/    Common_lep_SF_isLoaded = true;
/*                           Common_lep_SF*/  }
/*                           Common_lep_SF*/  return *Common_lep_SF_;
/*                           Common_lep_SF*/}

//---------------------------------------------------------------------------------
/*                      Common_lep_SFTight*/const vector<float> &VVVTree::Common_lep_SFTight() {
/*                      Common_lep_SFTight*/  if (not Common_lep_SFTight_isLoaded) {
/*                      Common_lep_SFTight*/    if (Common_lep_SFTight_branch != 0) {
/*                      Common_lep_SFTight*/      Common_lep_SFTight_branch->GetEntry(index);
/*                      Common_lep_SFTight*/    } else {
/*                      Common_lep_SFTight*/      printf("branch Common_lep_SFTight_branch does not exist!\n");
/*                      Common_lep_SFTight*/      exit(1);
/*                      Common_lep_SFTight*/    }
/*                      Common_lep_SFTight*/    Common_lep_SFTight_isLoaded = true;
/*                      Common_lep_SFTight*/  }
/*                      Common_lep_SFTight*/  return *Common_lep_SFTight_;
/*                      Common_lep_SFTight*/}

//---------------------------------------------------------------------------------
/*                         Common_lep_SFdn*/const vector<float> &VVVTree::Common_lep_SFdn() {
/*                         Common_lep_SFdn*/  if (not Common_lep_SFdn_isLoaded) {
/*                         Common_lep_SFdn*/    if (Common_lep_SFdn_branch != 0) {
/*                         Common_lep_SFdn*/      Common_lep_SFdn_branch->GetEntry(index);
/*                         Common_lep_SFdn*/    } else {
/*                         Common_lep_SFdn*/      printf("branch Common_lep_SFdn_branch does not exist!\n");
/*                         Common_lep_SFdn*/      exit(1);
/*                         Common_lep_SFdn*/    }
/*                         Common_lep_SFdn*/    Common_lep_SFdn_isLoaded = true;
/*                         Common_lep_SFdn*/  }
/*                         Common_lep_SFdn*/  return *Common_lep_SFdn_;
/*                         Common_lep_SFdn*/}

//---------------------------------------------------------------------------------
/*                    Common_lep_SFdnTight*/const vector<float> &VVVTree::Common_lep_SFdnTight() {
/*                    Common_lep_SFdnTight*/  if (not Common_lep_SFdnTight_isLoaded) {
/*                    Common_lep_SFdnTight*/    if (Common_lep_SFdnTight_branch != 0) {
/*                    Common_lep_SFdnTight*/      Common_lep_SFdnTight_branch->GetEntry(index);
/*                    Common_lep_SFdnTight*/    } else {
/*                    Common_lep_SFdnTight*/      printf("branch Common_lep_SFdnTight_branch does not exist!\n");
/*                    Common_lep_SFdnTight*/      exit(1);
/*                    Common_lep_SFdnTight*/    }
/*                    Common_lep_SFdnTight*/    Common_lep_SFdnTight_isLoaded = true;
/*                    Common_lep_SFdnTight*/  }
/*                    Common_lep_SFdnTight*/  return *Common_lep_SFdnTight_;
/*                    Common_lep_SFdnTight*/}

//---------------------------------------------------------------------------------
/*                         Common_lep_SFup*/const vector<float> &VVVTree::Common_lep_SFup() {
/*                         Common_lep_SFup*/  if (not Common_lep_SFup_isLoaded) {
/*                         Common_lep_SFup*/    if (Common_lep_SFup_branch != 0) {
/*                         Common_lep_SFup*/      Common_lep_SFup_branch->GetEntry(index);
/*                         Common_lep_SFup*/    } else {
/*                         Common_lep_SFup*/      printf("branch Common_lep_SFup_branch does not exist!\n");
/*                         Common_lep_SFup*/      exit(1);
/*                         Common_lep_SFup*/    }
/*                         Common_lep_SFup*/    Common_lep_SFup_isLoaded = true;
/*                         Common_lep_SFup*/  }
/*                         Common_lep_SFup*/  return *Common_lep_SFup_;
/*                         Common_lep_SFup*/}

//---------------------------------------------------------------------------------
/*                    Common_lep_SFupTight*/const vector<float> &VVVTree::Common_lep_SFupTight() {
/*                    Common_lep_SFupTight*/  if (not Common_lep_SFupTight_isLoaded) {
/*                    Common_lep_SFupTight*/    if (Common_lep_SFupTight_branch != 0) {
/*                    Common_lep_SFupTight*/      Common_lep_SFupTight_branch->GetEntry(index);
/*                    Common_lep_SFupTight*/    } else {
/*                    Common_lep_SFupTight*/      printf("branch Common_lep_SFupTight_branch does not exist!\n");
/*                    Common_lep_SFupTight*/      exit(1);
/*                    Common_lep_SFupTight*/    }
/*                    Common_lep_SFupTight*/    Common_lep_SFupTight_isLoaded = true;
/*                    Common_lep_SFupTight*/  }
/*                    Common_lep_SFupTight*/  return *Common_lep_SFupTight_;
/*                    Common_lep_SFupTight*/}

//---------------------------------------------------------------------------------
/*                           Common_jet_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_jet_p4() {
/*                           Common_jet_p4*/  if (not Common_jet_p4_isLoaded) {
/*                           Common_jet_p4*/    if (Common_jet_p4_branch != 0) {
/*                           Common_jet_p4*/      Common_jet_p4_branch->GetEntry(index);
/*                           Common_jet_p4*/    } else {
/*                           Common_jet_p4*/      printf("branch Common_jet_p4_branch does not exist!\n");
/*                           Common_jet_p4*/      exit(1);
/*                           Common_jet_p4*/    }
/*                           Common_jet_p4*/    Common_jet_p4_isLoaded = true;
/*                           Common_jet_p4*/  }
/*                           Common_jet_p4*/  return *Common_jet_p4_;
/*                           Common_jet_p4*/}

//---------------------------------------------------------------------------------
/*                         Common_jet_idxs*/const vector<int> &VVVTree::Common_jet_idxs() {
/*                         Common_jet_idxs*/  if (not Common_jet_idxs_isLoaded) {
/*                         Common_jet_idxs*/    if (Common_jet_idxs_branch != 0) {
/*                         Common_jet_idxs*/      Common_jet_idxs_branch->GetEntry(index);
/*                         Common_jet_idxs*/    } else {
/*                         Common_jet_idxs*/      printf("branch Common_jet_idxs_branch does not exist!\n");
/*                         Common_jet_idxs*/      exit(1);
/*                         Common_jet_idxs*/    }
/*                         Common_jet_idxs*/    Common_jet_idxs_isLoaded = true;
/*                         Common_jet_idxs*/  }
/*                         Common_jet_idxs*/  return *Common_jet_idxs_;
/*                         Common_jet_idxs*/}

//---------------------------------------------------------------------------------
/*                   Common_jet_passBloose*/const vector<bool> &VVVTree::Common_jet_passBloose() {
/*                   Common_jet_passBloose*/  if (not Common_jet_passBloose_isLoaded) {
/*                   Common_jet_passBloose*/    if (Common_jet_passBloose_branch != 0) {
/*                   Common_jet_passBloose*/      Common_jet_passBloose_branch->GetEntry(index);
/*                   Common_jet_passBloose*/    } else {
/*                   Common_jet_passBloose*/      printf("branch Common_jet_passBloose_branch does not exist!\n");
/*                   Common_jet_passBloose*/      exit(1);
/*                   Common_jet_passBloose*/    }
/*                   Common_jet_passBloose*/    Common_jet_passBloose_isLoaded = true;
/*                   Common_jet_passBloose*/  }
/*                   Common_jet_passBloose*/  return *Common_jet_passBloose_;
/*                   Common_jet_passBloose*/}

//---------------------------------------------------------------------------------
/*                  Common_jet_passBmedium*/const vector<bool> &VVVTree::Common_jet_passBmedium() {
/*                  Common_jet_passBmedium*/  if (not Common_jet_passBmedium_isLoaded) {
/*                  Common_jet_passBmedium*/    if (Common_jet_passBmedium_branch != 0) {
/*                  Common_jet_passBmedium*/      Common_jet_passBmedium_branch->GetEntry(index);
/*                  Common_jet_passBmedium*/    } else {
/*                  Common_jet_passBmedium*/      printf("branch Common_jet_passBmedium_branch does not exist!\n");
/*                  Common_jet_passBmedium*/      exit(1);
/*                  Common_jet_passBmedium*/    }
/*                  Common_jet_passBmedium*/    Common_jet_passBmedium_isLoaded = true;
/*                  Common_jet_passBmedium*/  }
/*                  Common_jet_passBmedium*/  return *Common_jet_passBmedium_;
/*                  Common_jet_passBmedium*/}

//---------------------------------------------------------------------------------
/*                   Common_jet_passBtight*/const vector<bool> &VVVTree::Common_jet_passBtight() {
/*                   Common_jet_passBtight*/  if (not Common_jet_passBtight_isLoaded) {
/*                   Common_jet_passBtight*/    if (Common_jet_passBtight_branch != 0) {
/*                   Common_jet_passBtight*/      Common_jet_passBtight_branch->GetEntry(index);
/*                   Common_jet_passBtight*/    } else {
/*                   Common_jet_passBtight*/      printf("branch Common_jet_passBtight_branch does not exist!\n");
/*                   Common_jet_passBtight*/      exit(1);
/*                   Common_jet_passBtight*/    }
/*                   Common_jet_passBtight*/    Common_jet_passBtight_isLoaded = true;
/*                   Common_jet_passBtight*/  }
/*                   Common_jet_passBtight*/  return *Common_jet_passBtight_;
/*                   Common_jet_passBtight*/}

//---------------------------------------------------------------------------------
/*                Common_jet_overlapfatjet*/const vector<int> &VVVTree::Common_jet_overlapfatjet() {
/*                Common_jet_overlapfatjet*/  if (not Common_jet_overlapfatjet_isLoaded) {
/*                Common_jet_overlapfatjet*/    if (Common_jet_overlapfatjet_branch != 0) {
/*                Common_jet_overlapfatjet*/      Common_jet_overlapfatjet_branch->GetEntry(index);
/*                Common_jet_overlapfatjet*/    } else {
/*                Common_jet_overlapfatjet*/      printf("branch Common_jet_overlapfatjet_branch does not exist!\n");
/*                Common_jet_overlapfatjet*/      exit(1);
/*                Common_jet_overlapfatjet*/    }
/*                Common_jet_overlapfatjet*/    Common_jet_overlapfatjet_isLoaded = true;
/*                Common_jet_overlapfatjet*/  }
/*                Common_jet_overlapfatjet*/  return *Common_jet_overlapfatjet_;
/*                Common_jet_overlapfatjet*/}

//---------------------------------------------------------------------------------
/*                        Common_fatjet_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_fatjet_p4() {
/*                        Common_fatjet_p4*/  if (not Common_fatjet_p4_isLoaded) {
/*                        Common_fatjet_p4*/    if (Common_fatjet_p4_branch != 0) {
/*                        Common_fatjet_p4*/      Common_fatjet_p4_branch->GetEntry(index);
/*                        Common_fatjet_p4*/    } else {
/*                        Common_fatjet_p4*/      printf("branch Common_fatjet_p4_branch does not exist!\n");
/*                        Common_fatjet_p4*/      exit(1);
/*                        Common_fatjet_p4*/    }
/*                        Common_fatjet_p4*/    Common_fatjet_p4_isLoaded = true;
/*                        Common_fatjet_p4*/  }
/*                        Common_fatjet_p4*/  return *Common_fatjet_p4_;
/*                        Common_fatjet_p4*/}

//---------------------------------------------------------------------------------
/*                      Common_fatjet_idxs*/const vector<int> &VVVTree::Common_fatjet_idxs() {
/*                      Common_fatjet_idxs*/  if (not Common_fatjet_idxs_isLoaded) {
/*                      Common_fatjet_idxs*/    if (Common_fatjet_idxs_branch != 0) {
/*                      Common_fatjet_idxs*/      Common_fatjet_idxs_branch->GetEntry(index);
/*                      Common_fatjet_idxs*/    } else {
/*                      Common_fatjet_idxs*/      printf("branch Common_fatjet_idxs_branch does not exist!\n");
/*                      Common_fatjet_idxs*/      exit(1);
/*                      Common_fatjet_idxs*/    }
/*                      Common_fatjet_idxs*/    Common_fatjet_idxs_isLoaded = true;
/*                      Common_fatjet_idxs*/  }
/*                      Common_fatjet_idxs*/  return *Common_fatjet_idxs_;
/*                      Common_fatjet_idxs*/}

//---------------------------------------------------------------------------------
/*                 Common_fatjet_msoftdrop*/const vector<float> &VVVTree::Common_fatjet_msoftdrop() {
/*                 Common_fatjet_msoftdrop*/  if (not Common_fatjet_msoftdrop_isLoaded) {
/*                 Common_fatjet_msoftdrop*/    if (Common_fatjet_msoftdrop_branch != 0) {
/*                 Common_fatjet_msoftdrop*/      Common_fatjet_msoftdrop_branch->GetEntry(index);
/*                 Common_fatjet_msoftdrop*/    } else {
/*                 Common_fatjet_msoftdrop*/      printf("branch Common_fatjet_msoftdrop_branch does not exist!\n");
/*                 Common_fatjet_msoftdrop*/      exit(1);
/*                 Common_fatjet_msoftdrop*/    }
/*                 Common_fatjet_msoftdrop*/    Common_fatjet_msoftdrop_isLoaded = true;
/*                 Common_fatjet_msoftdrop*/  }
/*                 Common_fatjet_msoftdrop*/  return *Common_fatjet_msoftdrop_;
/*                 Common_fatjet_msoftdrop*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_W*/const vector<float> &VVVTree::Common_fatjet_deepMD_W() {
/*                  Common_fatjet_deepMD_W*/  if (not Common_fatjet_deepMD_W_isLoaded) {
/*                  Common_fatjet_deepMD_W*/    if (Common_fatjet_deepMD_W_branch != 0) {
/*                  Common_fatjet_deepMD_W*/      Common_fatjet_deepMD_W_branch->GetEntry(index);
/*                  Common_fatjet_deepMD_W*/    } else {
/*                  Common_fatjet_deepMD_W*/      printf("branch Common_fatjet_deepMD_W_branch does not exist!\n");
/*                  Common_fatjet_deepMD_W*/      exit(1);
/*                  Common_fatjet_deepMD_W*/    }
/*                  Common_fatjet_deepMD_W*/    Common_fatjet_deepMD_W_isLoaded = true;
/*                  Common_fatjet_deepMD_W*/  }
/*                  Common_fatjet_deepMD_W*/  return *Common_fatjet_deepMD_W_;
/*                  Common_fatjet_deepMD_W*/}

//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_W*/const vector<float> &VVVTree::Common_fatjet_deep_W() {
/*                    Common_fatjet_deep_W*/  if (not Common_fatjet_deep_W_isLoaded) {
/*                    Common_fatjet_deep_W*/    if (Common_fatjet_deep_W_branch != 0) {
/*                    Common_fatjet_deep_W*/      Common_fatjet_deep_W_branch->GetEntry(index);
/*                    Common_fatjet_deep_W*/    } else {
/*                    Common_fatjet_deep_W*/      printf("branch Common_fatjet_deep_W_branch does not exist!\n");
/*                    Common_fatjet_deep_W*/      exit(1);
/*                    Common_fatjet_deep_W*/    }
/*                    Common_fatjet_deep_W*/    Common_fatjet_deep_W_isLoaded = true;
/*                    Common_fatjet_deep_W*/  }
/*                    Common_fatjet_deep_W*/  return *Common_fatjet_deep_W_;
/*                    Common_fatjet_deep_W*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_Z*/const vector<float> &VVVTree::Common_fatjet_deepMD_Z() {
/*                  Common_fatjet_deepMD_Z*/  if (not Common_fatjet_deepMD_Z_isLoaded) {
/*                  Common_fatjet_deepMD_Z*/    if (Common_fatjet_deepMD_Z_branch != 0) {
/*                  Common_fatjet_deepMD_Z*/      Common_fatjet_deepMD_Z_branch->GetEntry(index);
/*                  Common_fatjet_deepMD_Z*/    } else {
/*                  Common_fatjet_deepMD_Z*/      printf("branch Common_fatjet_deepMD_Z_branch does not exist!\n");
/*                  Common_fatjet_deepMD_Z*/      exit(1);
/*                  Common_fatjet_deepMD_Z*/    }
/*                  Common_fatjet_deepMD_Z*/    Common_fatjet_deepMD_Z_isLoaded = true;
/*                  Common_fatjet_deepMD_Z*/  }
/*                  Common_fatjet_deepMD_Z*/  return *Common_fatjet_deepMD_Z_;
/*                  Common_fatjet_deepMD_Z*/}

//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_Z*/const vector<float> &VVVTree::Common_fatjet_deep_Z() {
/*                    Common_fatjet_deep_Z*/  if (not Common_fatjet_deep_Z_isLoaded) {
/*                    Common_fatjet_deep_Z*/    if (Common_fatjet_deep_Z_branch != 0) {
/*                    Common_fatjet_deep_Z*/      Common_fatjet_deep_Z_branch->GetEntry(index);
/*                    Common_fatjet_deep_Z*/    } else {
/*                    Common_fatjet_deep_Z*/      printf("branch Common_fatjet_deep_Z_branch does not exist!\n");
/*                    Common_fatjet_deep_Z*/      exit(1);
/*                    Common_fatjet_deep_Z*/    }
/*                    Common_fatjet_deep_Z*/    Common_fatjet_deep_Z_isLoaded = true;
/*                    Common_fatjet_deep_Z*/  }
/*                    Common_fatjet_deep_Z*/  return *Common_fatjet_deep_Z_;
/*                    Common_fatjet_deep_Z*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_T*/const vector<float> &VVVTree::Common_fatjet_deepMD_T() {
/*                  Common_fatjet_deepMD_T*/  if (not Common_fatjet_deepMD_T_isLoaded) {
/*                  Common_fatjet_deepMD_T*/    if (Common_fatjet_deepMD_T_branch != 0) {
/*                  Common_fatjet_deepMD_T*/      Common_fatjet_deepMD_T_branch->GetEntry(index);
/*                  Common_fatjet_deepMD_T*/    } else {
/*                  Common_fatjet_deepMD_T*/      printf("branch Common_fatjet_deepMD_T_branch does not exist!\n");
/*                  Common_fatjet_deepMD_T*/      exit(1);
/*                  Common_fatjet_deepMD_T*/    }
/*                  Common_fatjet_deepMD_T*/    Common_fatjet_deepMD_T_isLoaded = true;
/*                  Common_fatjet_deepMD_T*/  }
/*                  Common_fatjet_deepMD_T*/  return *Common_fatjet_deepMD_T_;
/*                  Common_fatjet_deepMD_T*/}

//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_T*/const vector<float> &VVVTree::Common_fatjet_deep_T() {
/*                    Common_fatjet_deep_T*/  if (not Common_fatjet_deep_T_isLoaded) {
/*                    Common_fatjet_deep_T*/    if (Common_fatjet_deep_T_branch != 0) {
/*                    Common_fatjet_deep_T*/      Common_fatjet_deep_T_branch->GetEntry(index);
/*                    Common_fatjet_deep_T*/    } else {
/*                    Common_fatjet_deep_T*/      printf("branch Common_fatjet_deep_T_branch does not exist!\n");
/*                    Common_fatjet_deep_T*/      exit(1);
/*                    Common_fatjet_deep_T*/    }
/*                    Common_fatjet_deep_T*/    Common_fatjet_deep_T_isLoaded = true;
/*                    Common_fatjet_deep_T*/  }
/*                    Common_fatjet_deep_T*/  return *Common_fatjet_deep_T_;
/*                    Common_fatjet_deep_T*/}

//---------------------------------------------------------------------------------
/*                 Common_fatjet_deepMD_bb*/const vector<float> &VVVTree::Common_fatjet_deepMD_bb() {
/*                 Common_fatjet_deepMD_bb*/  if (not Common_fatjet_deepMD_bb_isLoaded) {
/*                 Common_fatjet_deepMD_bb*/    if (Common_fatjet_deepMD_bb_branch != 0) {
/*                 Common_fatjet_deepMD_bb*/      Common_fatjet_deepMD_bb_branch->GetEntry(index);
/*                 Common_fatjet_deepMD_bb*/    } else {
/*                 Common_fatjet_deepMD_bb*/      printf("branch Common_fatjet_deepMD_bb_branch does not exist!\n");
/*                 Common_fatjet_deepMD_bb*/      exit(1);
/*                 Common_fatjet_deepMD_bb*/    }
/*                 Common_fatjet_deepMD_bb*/    Common_fatjet_deepMD_bb_isLoaded = true;
/*                 Common_fatjet_deepMD_bb*/  }
/*                 Common_fatjet_deepMD_bb*/  return *Common_fatjet_deepMD_bb_;
/*                 Common_fatjet_deepMD_bb*/}

//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau3*/const vector<float> &VVVTree::Common_fatjet_tau3() {
/*                      Common_fatjet_tau3*/  if (not Common_fatjet_tau3_isLoaded) {
/*                      Common_fatjet_tau3*/    if (Common_fatjet_tau3_branch != 0) {
/*                      Common_fatjet_tau3*/      Common_fatjet_tau3_branch->GetEntry(index);
/*                      Common_fatjet_tau3*/    } else {
/*                      Common_fatjet_tau3*/      printf("branch Common_fatjet_tau3_branch does not exist!\n");
/*                      Common_fatjet_tau3*/      exit(1);
/*                      Common_fatjet_tau3*/    }
/*                      Common_fatjet_tau3*/    Common_fatjet_tau3_isLoaded = true;
/*                      Common_fatjet_tau3*/  }
/*                      Common_fatjet_tau3*/  return *Common_fatjet_tau3_;
/*                      Common_fatjet_tau3*/}

//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau2*/const vector<float> &VVVTree::Common_fatjet_tau2() {
/*                      Common_fatjet_tau2*/  if (not Common_fatjet_tau2_isLoaded) {
/*                      Common_fatjet_tau2*/    if (Common_fatjet_tau2_branch != 0) {
/*                      Common_fatjet_tau2*/      Common_fatjet_tau2_branch->GetEntry(index);
/*                      Common_fatjet_tau2*/    } else {
/*                      Common_fatjet_tau2*/      printf("branch Common_fatjet_tau2_branch does not exist!\n");
/*                      Common_fatjet_tau2*/      exit(1);
/*                      Common_fatjet_tau2*/    }
/*                      Common_fatjet_tau2*/    Common_fatjet_tau2_isLoaded = true;
/*                      Common_fatjet_tau2*/  }
/*                      Common_fatjet_tau2*/  return *Common_fatjet_tau2_;
/*                      Common_fatjet_tau2*/}

//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau1*/const vector<float> &VVVTree::Common_fatjet_tau1() {
/*                      Common_fatjet_tau1*/  if (not Common_fatjet_tau1_isLoaded) {
/*                      Common_fatjet_tau1*/    if (Common_fatjet_tau1_branch != 0) {
/*                      Common_fatjet_tau1*/      Common_fatjet_tau1_branch->GetEntry(index);
/*                      Common_fatjet_tau1*/    } else {
/*                      Common_fatjet_tau1*/      printf("branch Common_fatjet_tau1_branch does not exist!\n");
/*                      Common_fatjet_tau1*/      exit(1);
/*                      Common_fatjet_tau1*/    }
/*                      Common_fatjet_tau1*/    Common_fatjet_tau1_isLoaded = true;
/*                      Common_fatjet_tau1*/  }
/*                      Common_fatjet_tau1*/  return *Common_fatjet_tau1_;
/*                      Common_fatjet_tau1*/}

//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau32*/const vector<float> &VVVTree::Common_fatjet_tau32() {
/*                     Common_fatjet_tau32*/  if (not Common_fatjet_tau32_isLoaded) {
/*                     Common_fatjet_tau32*/    if (Common_fatjet_tau32_branch != 0) {
/*                     Common_fatjet_tau32*/      Common_fatjet_tau32_branch->GetEntry(index);
/*                     Common_fatjet_tau32*/    } else {
/*                     Common_fatjet_tau32*/      printf("branch Common_fatjet_tau32_branch does not exist!\n");
/*                     Common_fatjet_tau32*/      exit(1);
/*                     Common_fatjet_tau32*/    }
/*                     Common_fatjet_tau32*/    Common_fatjet_tau32_isLoaded = true;
/*                     Common_fatjet_tau32*/  }
/*                     Common_fatjet_tau32*/  return *Common_fatjet_tau32_;
/*                     Common_fatjet_tau32*/}

//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau21*/const vector<float> &VVVTree::Common_fatjet_tau21() {
/*                     Common_fatjet_tau21*/  if (not Common_fatjet_tau21_isLoaded) {
/*                     Common_fatjet_tau21*/    if (Common_fatjet_tau21_branch != 0) {
/*                     Common_fatjet_tau21*/      Common_fatjet_tau21_branch->GetEntry(index);
/*                     Common_fatjet_tau21*/    } else {
/*                     Common_fatjet_tau21*/      printf("branch Common_fatjet_tau21_branch does not exist!\n");
/*                     Common_fatjet_tau21*/      exit(1);
/*                     Common_fatjet_tau21*/    }
/*                     Common_fatjet_tau21*/    Common_fatjet_tau21_isLoaded = true;
/*                     Common_fatjet_tau21*/  }
/*                     Common_fatjet_tau21*/  return *Common_fatjet_tau21_;
/*                     Common_fatjet_tau21*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_pt*/const vector<float> &VVVTree::Common_fatjet_subjet0_pt() {
/*                Common_fatjet_subjet0_pt*/  if (not Common_fatjet_subjet0_pt_isLoaded) {
/*                Common_fatjet_subjet0_pt*/    if (Common_fatjet_subjet0_pt_branch != 0) {
/*                Common_fatjet_subjet0_pt*/      Common_fatjet_subjet0_pt_branch->GetEntry(index);
/*                Common_fatjet_subjet0_pt*/    } else {
/*                Common_fatjet_subjet0_pt*/      printf("branch Common_fatjet_subjet0_pt_branch does not exist!\n");
/*                Common_fatjet_subjet0_pt*/      exit(1);
/*                Common_fatjet_subjet0_pt*/    }
/*                Common_fatjet_subjet0_pt*/    Common_fatjet_subjet0_pt_isLoaded = true;
/*                Common_fatjet_subjet0_pt*/  }
/*                Common_fatjet_subjet0_pt*/  return *Common_fatjet_subjet0_pt_;
/*                Common_fatjet_subjet0_pt*/}

//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_eta*/const vector<float> &VVVTree::Common_fatjet_subjet0_eta() {
/*               Common_fatjet_subjet0_eta*/  if (not Common_fatjet_subjet0_eta_isLoaded) {
/*               Common_fatjet_subjet0_eta*/    if (Common_fatjet_subjet0_eta_branch != 0) {
/*               Common_fatjet_subjet0_eta*/      Common_fatjet_subjet0_eta_branch->GetEntry(index);
/*               Common_fatjet_subjet0_eta*/    } else {
/*               Common_fatjet_subjet0_eta*/      printf("branch Common_fatjet_subjet0_eta_branch does not exist!\n");
/*               Common_fatjet_subjet0_eta*/      exit(1);
/*               Common_fatjet_subjet0_eta*/    }
/*               Common_fatjet_subjet0_eta*/    Common_fatjet_subjet0_eta_isLoaded = true;
/*               Common_fatjet_subjet0_eta*/  }
/*               Common_fatjet_subjet0_eta*/  return *Common_fatjet_subjet0_eta_;
/*               Common_fatjet_subjet0_eta*/}

//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_phi*/const vector<float> &VVVTree::Common_fatjet_subjet0_phi() {
/*               Common_fatjet_subjet0_phi*/  if (not Common_fatjet_subjet0_phi_isLoaded) {
/*               Common_fatjet_subjet0_phi*/    if (Common_fatjet_subjet0_phi_branch != 0) {
/*               Common_fatjet_subjet0_phi*/      Common_fatjet_subjet0_phi_branch->GetEntry(index);
/*               Common_fatjet_subjet0_phi*/    } else {
/*               Common_fatjet_subjet0_phi*/      printf("branch Common_fatjet_subjet0_phi_branch does not exist!\n");
/*               Common_fatjet_subjet0_phi*/      exit(1);
/*               Common_fatjet_subjet0_phi*/    }
/*               Common_fatjet_subjet0_phi*/    Common_fatjet_subjet0_phi_isLoaded = true;
/*               Common_fatjet_subjet0_phi*/  }
/*               Common_fatjet_subjet0_phi*/  return *Common_fatjet_subjet0_phi_;
/*               Common_fatjet_subjet0_phi*/}

//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet0_mass*/const vector<float> &VVVTree::Common_fatjet_subjet0_mass() {
/*              Common_fatjet_subjet0_mass*/  if (not Common_fatjet_subjet0_mass_isLoaded) {
/*              Common_fatjet_subjet0_mass*/    if (Common_fatjet_subjet0_mass_branch != 0) {
/*              Common_fatjet_subjet0_mass*/      Common_fatjet_subjet0_mass_branch->GetEntry(index);
/*              Common_fatjet_subjet0_mass*/    } else {
/*              Common_fatjet_subjet0_mass*/      printf("branch Common_fatjet_subjet0_mass_branch does not exist!\n");
/*              Common_fatjet_subjet0_mass*/      exit(1);
/*              Common_fatjet_subjet0_mass*/    }
/*              Common_fatjet_subjet0_mass*/    Common_fatjet_subjet0_mass_isLoaded = true;
/*              Common_fatjet_subjet0_mass*/  }
/*              Common_fatjet_subjet0_mass*/  return *Common_fatjet_subjet0_mass_;
/*              Common_fatjet_subjet0_mass*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_pt*/const vector<float> &VVVTree::Common_fatjet_subjet1_pt() {
/*                Common_fatjet_subjet1_pt*/  if (not Common_fatjet_subjet1_pt_isLoaded) {
/*                Common_fatjet_subjet1_pt*/    if (Common_fatjet_subjet1_pt_branch != 0) {
/*                Common_fatjet_subjet1_pt*/      Common_fatjet_subjet1_pt_branch->GetEntry(index);
/*                Common_fatjet_subjet1_pt*/    } else {
/*                Common_fatjet_subjet1_pt*/      printf("branch Common_fatjet_subjet1_pt_branch does not exist!\n");
/*                Common_fatjet_subjet1_pt*/      exit(1);
/*                Common_fatjet_subjet1_pt*/    }
/*                Common_fatjet_subjet1_pt*/    Common_fatjet_subjet1_pt_isLoaded = true;
/*                Common_fatjet_subjet1_pt*/  }
/*                Common_fatjet_subjet1_pt*/  return *Common_fatjet_subjet1_pt_;
/*                Common_fatjet_subjet1_pt*/}

//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_eta*/const vector<float> &VVVTree::Common_fatjet_subjet1_eta() {
/*               Common_fatjet_subjet1_eta*/  if (not Common_fatjet_subjet1_eta_isLoaded) {
/*               Common_fatjet_subjet1_eta*/    if (Common_fatjet_subjet1_eta_branch != 0) {
/*               Common_fatjet_subjet1_eta*/      Common_fatjet_subjet1_eta_branch->GetEntry(index);
/*               Common_fatjet_subjet1_eta*/    } else {
/*               Common_fatjet_subjet1_eta*/      printf("branch Common_fatjet_subjet1_eta_branch does not exist!\n");
/*               Common_fatjet_subjet1_eta*/      exit(1);
/*               Common_fatjet_subjet1_eta*/    }
/*               Common_fatjet_subjet1_eta*/    Common_fatjet_subjet1_eta_isLoaded = true;
/*               Common_fatjet_subjet1_eta*/  }
/*               Common_fatjet_subjet1_eta*/  return *Common_fatjet_subjet1_eta_;
/*               Common_fatjet_subjet1_eta*/}

//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_phi*/const vector<float> &VVVTree::Common_fatjet_subjet1_phi() {
/*               Common_fatjet_subjet1_phi*/  if (not Common_fatjet_subjet1_phi_isLoaded) {
/*               Common_fatjet_subjet1_phi*/    if (Common_fatjet_subjet1_phi_branch != 0) {
/*               Common_fatjet_subjet1_phi*/      Common_fatjet_subjet1_phi_branch->GetEntry(index);
/*               Common_fatjet_subjet1_phi*/    } else {
/*               Common_fatjet_subjet1_phi*/      printf("branch Common_fatjet_subjet1_phi_branch does not exist!\n");
/*               Common_fatjet_subjet1_phi*/      exit(1);
/*               Common_fatjet_subjet1_phi*/    }
/*               Common_fatjet_subjet1_phi*/    Common_fatjet_subjet1_phi_isLoaded = true;
/*               Common_fatjet_subjet1_phi*/  }
/*               Common_fatjet_subjet1_phi*/  return *Common_fatjet_subjet1_phi_;
/*               Common_fatjet_subjet1_phi*/}

//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet1_mass*/const vector<float> &VVVTree::Common_fatjet_subjet1_mass() {
/*              Common_fatjet_subjet1_mass*/  if (not Common_fatjet_subjet1_mass_isLoaded) {
/*              Common_fatjet_subjet1_mass*/    if (Common_fatjet_subjet1_mass_branch != 0) {
/*              Common_fatjet_subjet1_mass*/      Common_fatjet_subjet1_mass_branch->GetEntry(index);
/*              Common_fatjet_subjet1_mass*/    } else {
/*              Common_fatjet_subjet1_mass*/      printf("branch Common_fatjet_subjet1_mass_branch does not exist!\n");
/*              Common_fatjet_subjet1_mass*/      exit(1);
/*              Common_fatjet_subjet1_mass*/    }
/*              Common_fatjet_subjet1_mass*/    Common_fatjet_subjet1_mass_isLoaded = true;
/*              Common_fatjet_subjet1_mass*/  }
/*              Common_fatjet_subjet1_mass*/  return *Common_fatjet_subjet1_mass_;
/*              Common_fatjet_subjet1_mass*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_fatjet_subjet0_p4() {
/*                Common_fatjet_subjet0_p4*/  if (not Common_fatjet_subjet0_p4_isLoaded) {
/*                Common_fatjet_subjet0_p4*/    if (Common_fatjet_subjet0_p4_branch != 0) {
/*                Common_fatjet_subjet0_p4*/      Common_fatjet_subjet0_p4_branch->GetEntry(index);
/*                Common_fatjet_subjet0_p4*/    } else {
/*                Common_fatjet_subjet0_p4*/      printf("branch Common_fatjet_subjet0_p4_branch does not exist!\n");
/*                Common_fatjet_subjet0_p4*/      exit(1);
/*                Common_fatjet_subjet0_p4*/    }
/*                Common_fatjet_subjet0_p4*/    Common_fatjet_subjet0_p4_isLoaded = true;
/*                Common_fatjet_subjet0_p4*/  }
/*                Common_fatjet_subjet0_p4*/  return *Common_fatjet_subjet0_p4_;
/*                Common_fatjet_subjet0_p4*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_fatjet_subjet1_p4() {
/*                Common_fatjet_subjet1_p4*/  if (not Common_fatjet_subjet1_p4_isLoaded) {
/*                Common_fatjet_subjet1_p4*/    if (Common_fatjet_subjet1_p4_branch != 0) {
/*                Common_fatjet_subjet1_p4*/      Common_fatjet_subjet1_p4_branch->GetEntry(index);
/*                Common_fatjet_subjet1_p4*/    } else {
/*                Common_fatjet_subjet1_p4*/      printf("branch Common_fatjet_subjet1_p4_branch does not exist!\n");
/*                Common_fatjet_subjet1_p4*/      exit(1);
/*                Common_fatjet_subjet1_p4*/    }
/*                Common_fatjet_subjet1_p4*/    Common_fatjet_subjet1_p4_isLoaded = true;
/*                Common_fatjet_subjet1_p4*/  }
/*                Common_fatjet_subjet1_p4*/  return *Common_fatjet_subjet1_p4_;
/*                Common_fatjet_subjet1_p4*/}

//---------------------------------------------------------------------------------
/*                        Common_fatjet_WP*/const vector<int> &VVVTree::Common_fatjet_WP() {
/*                        Common_fatjet_WP*/  if (not Common_fatjet_WP_isLoaded) {
/*                        Common_fatjet_WP*/    if (Common_fatjet_WP_branch != 0) {
/*                        Common_fatjet_WP*/      Common_fatjet_WP_branch->GetEntry(index);
/*                        Common_fatjet_WP*/    } else {
/*                        Common_fatjet_WP*/      printf("branch Common_fatjet_WP_branch does not exist!\n");
/*                        Common_fatjet_WP*/      exit(1);
/*                        Common_fatjet_WP*/    }
/*                        Common_fatjet_WP*/    Common_fatjet_WP_isLoaded = true;
/*                        Common_fatjet_WP*/  }
/*                        Common_fatjet_WP*/  return *Common_fatjet_WP_;
/*                        Common_fatjet_WP*/}

//---------------------------------------------------------------------------------
/*            Common_fatjet_WP_antimasscut*/const vector<int> &VVVTree::Common_fatjet_WP_antimasscut() {
/*            Common_fatjet_WP_antimasscut*/  if (not Common_fatjet_WP_antimasscut_isLoaded) {
/*            Common_fatjet_WP_antimasscut*/    if (Common_fatjet_WP_antimasscut_branch != 0) {
/*            Common_fatjet_WP_antimasscut*/      Common_fatjet_WP_antimasscut_branch->GetEntry(index);
/*            Common_fatjet_WP_antimasscut*/    } else {
/*            Common_fatjet_WP_antimasscut*/      printf("branch Common_fatjet_WP_antimasscut_branch does not exist!\n");
/*            Common_fatjet_WP_antimasscut*/      exit(1);
/*            Common_fatjet_WP_antimasscut*/    }
/*            Common_fatjet_WP_antimasscut*/    Common_fatjet_WP_antimasscut_isLoaded = true;
/*            Common_fatjet_WP_antimasscut*/  }
/*            Common_fatjet_WP_antimasscut*/  return *Common_fatjet_WP_antimasscut_;
/*            Common_fatjet_WP_antimasscut*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFVLoose*/const vector<float> &VVVTree::Common_fatjet_SFVLoose() {
/*                  Common_fatjet_SFVLoose*/  if (not Common_fatjet_SFVLoose_isLoaded) {
/*                  Common_fatjet_SFVLoose*/    if (Common_fatjet_SFVLoose_branch != 0) {
/*                  Common_fatjet_SFVLoose*/      Common_fatjet_SFVLoose_branch->GetEntry(index);
/*                  Common_fatjet_SFVLoose*/    } else {
/*                  Common_fatjet_SFVLoose*/      printf("branch Common_fatjet_SFVLoose_branch does not exist!\n");
/*                  Common_fatjet_SFVLoose*/      exit(1);
/*                  Common_fatjet_SFVLoose*/    }
/*                  Common_fatjet_SFVLoose*/    Common_fatjet_SFVLoose_isLoaded = true;
/*                  Common_fatjet_SFVLoose*/  }
/*                  Common_fatjet_SFVLoose*/  return *Common_fatjet_SFVLoose_;
/*                  Common_fatjet_SFVLoose*/}

//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFLoose*/const vector<float> &VVVTree::Common_fatjet_SFLoose() {
/*                   Common_fatjet_SFLoose*/  if (not Common_fatjet_SFLoose_isLoaded) {
/*                   Common_fatjet_SFLoose*/    if (Common_fatjet_SFLoose_branch != 0) {
/*                   Common_fatjet_SFLoose*/      Common_fatjet_SFLoose_branch->GetEntry(index);
/*                   Common_fatjet_SFLoose*/    } else {
/*                   Common_fatjet_SFLoose*/      printf("branch Common_fatjet_SFLoose_branch does not exist!\n");
/*                   Common_fatjet_SFLoose*/      exit(1);
/*                   Common_fatjet_SFLoose*/    }
/*                   Common_fatjet_SFLoose*/    Common_fatjet_SFLoose_isLoaded = true;
/*                   Common_fatjet_SFLoose*/  }
/*                   Common_fatjet_SFLoose*/  return *Common_fatjet_SFLoose_;
/*                   Common_fatjet_SFLoose*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFMedium*/const vector<float> &VVVTree::Common_fatjet_SFMedium() {
/*                  Common_fatjet_SFMedium*/  if (not Common_fatjet_SFMedium_isLoaded) {
/*                  Common_fatjet_SFMedium*/    if (Common_fatjet_SFMedium_branch != 0) {
/*                  Common_fatjet_SFMedium*/      Common_fatjet_SFMedium_branch->GetEntry(index);
/*                  Common_fatjet_SFMedium*/    } else {
/*                  Common_fatjet_SFMedium*/      printf("branch Common_fatjet_SFMedium_branch does not exist!\n");
/*                  Common_fatjet_SFMedium*/      exit(1);
/*                  Common_fatjet_SFMedium*/    }
/*                  Common_fatjet_SFMedium*/    Common_fatjet_SFMedium_isLoaded = true;
/*                  Common_fatjet_SFMedium*/  }
/*                  Common_fatjet_SFMedium*/  return *Common_fatjet_SFMedium_;
/*                  Common_fatjet_SFMedium*/}

//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFTight*/const vector<float> &VVVTree::Common_fatjet_SFTight() {
/*                   Common_fatjet_SFTight*/  if (not Common_fatjet_SFTight_isLoaded) {
/*                   Common_fatjet_SFTight*/    if (Common_fatjet_SFTight_branch != 0) {
/*                   Common_fatjet_SFTight*/      Common_fatjet_SFTight_branch->GetEntry(index);
/*                   Common_fatjet_SFTight*/    } else {
/*                   Common_fatjet_SFTight*/      printf("branch Common_fatjet_SFTight_branch does not exist!\n");
/*                   Common_fatjet_SFTight*/      exit(1);
/*                   Common_fatjet_SFTight*/    }
/*                   Common_fatjet_SFTight*/    Common_fatjet_SFTight_isLoaded = true;
/*                   Common_fatjet_SFTight*/  }
/*                   Common_fatjet_SFTight*/  return *Common_fatjet_SFTight_;
/*                   Common_fatjet_SFTight*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnVLoose*/const vector<float> &VVVTree::Common_fatjet_SFdnVLoose() {
/*                Common_fatjet_SFdnVLoose*/  if (not Common_fatjet_SFdnVLoose_isLoaded) {
/*                Common_fatjet_SFdnVLoose*/    if (Common_fatjet_SFdnVLoose_branch != 0) {
/*                Common_fatjet_SFdnVLoose*/      Common_fatjet_SFdnVLoose_branch->GetEntry(index);
/*                Common_fatjet_SFdnVLoose*/    } else {
/*                Common_fatjet_SFdnVLoose*/      printf("branch Common_fatjet_SFdnVLoose_branch does not exist!\n");
/*                Common_fatjet_SFdnVLoose*/      exit(1);
/*                Common_fatjet_SFdnVLoose*/    }
/*                Common_fatjet_SFdnVLoose*/    Common_fatjet_SFdnVLoose_isLoaded = true;
/*                Common_fatjet_SFdnVLoose*/  }
/*                Common_fatjet_SFdnVLoose*/  return *Common_fatjet_SFdnVLoose_;
/*                Common_fatjet_SFdnVLoose*/}

//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnLoose*/const vector<float> &VVVTree::Common_fatjet_SFdnLoose() {
/*                 Common_fatjet_SFdnLoose*/  if (not Common_fatjet_SFdnLoose_isLoaded) {
/*                 Common_fatjet_SFdnLoose*/    if (Common_fatjet_SFdnLoose_branch != 0) {
/*                 Common_fatjet_SFdnLoose*/      Common_fatjet_SFdnLoose_branch->GetEntry(index);
/*                 Common_fatjet_SFdnLoose*/    } else {
/*                 Common_fatjet_SFdnLoose*/      printf("branch Common_fatjet_SFdnLoose_branch does not exist!\n");
/*                 Common_fatjet_SFdnLoose*/      exit(1);
/*                 Common_fatjet_SFdnLoose*/    }
/*                 Common_fatjet_SFdnLoose*/    Common_fatjet_SFdnLoose_isLoaded = true;
/*                 Common_fatjet_SFdnLoose*/  }
/*                 Common_fatjet_SFdnLoose*/  return *Common_fatjet_SFdnLoose_;
/*                 Common_fatjet_SFdnLoose*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnMedium*/const vector<float> &VVVTree::Common_fatjet_SFdnMedium() {
/*                Common_fatjet_SFdnMedium*/  if (not Common_fatjet_SFdnMedium_isLoaded) {
/*                Common_fatjet_SFdnMedium*/    if (Common_fatjet_SFdnMedium_branch != 0) {
/*                Common_fatjet_SFdnMedium*/      Common_fatjet_SFdnMedium_branch->GetEntry(index);
/*                Common_fatjet_SFdnMedium*/    } else {
/*                Common_fatjet_SFdnMedium*/      printf("branch Common_fatjet_SFdnMedium_branch does not exist!\n");
/*                Common_fatjet_SFdnMedium*/      exit(1);
/*                Common_fatjet_SFdnMedium*/    }
/*                Common_fatjet_SFdnMedium*/    Common_fatjet_SFdnMedium_isLoaded = true;
/*                Common_fatjet_SFdnMedium*/  }
/*                Common_fatjet_SFdnMedium*/  return *Common_fatjet_SFdnMedium_;
/*                Common_fatjet_SFdnMedium*/}

//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnTight*/const vector<float> &VVVTree::Common_fatjet_SFdnTight() {
/*                 Common_fatjet_SFdnTight*/  if (not Common_fatjet_SFdnTight_isLoaded) {
/*                 Common_fatjet_SFdnTight*/    if (Common_fatjet_SFdnTight_branch != 0) {
/*                 Common_fatjet_SFdnTight*/      Common_fatjet_SFdnTight_branch->GetEntry(index);
/*                 Common_fatjet_SFdnTight*/    } else {
/*                 Common_fatjet_SFdnTight*/      printf("branch Common_fatjet_SFdnTight_branch does not exist!\n");
/*                 Common_fatjet_SFdnTight*/      exit(1);
/*                 Common_fatjet_SFdnTight*/    }
/*                 Common_fatjet_SFdnTight*/    Common_fatjet_SFdnTight_isLoaded = true;
/*                 Common_fatjet_SFdnTight*/  }
/*                 Common_fatjet_SFdnTight*/  return *Common_fatjet_SFdnTight_;
/*                 Common_fatjet_SFdnTight*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupVLoose*/const vector<float> &VVVTree::Common_fatjet_SFupVLoose() {
/*                Common_fatjet_SFupVLoose*/  if (not Common_fatjet_SFupVLoose_isLoaded) {
/*                Common_fatjet_SFupVLoose*/    if (Common_fatjet_SFupVLoose_branch != 0) {
/*                Common_fatjet_SFupVLoose*/      Common_fatjet_SFupVLoose_branch->GetEntry(index);
/*                Common_fatjet_SFupVLoose*/    } else {
/*                Common_fatjet_SFupVLoose*/      printf("branch Common_fatjet_SFupVLoose_branch does not exist!\n");
/*                Common_fatjet_SFupVLoose*/      exit(1);
/*                Common_fatjet_SFupVLoose*/    }
/*                Common_fatjet_SFupVLoose*/    Common_fatjet_SFupVLoose_isLoaded = true;
/*                Common_fatjet_SFupVLoose*/  }
/*                Common_fatjet_SFupVLoose*/  return *Common_fatjet_SFupVLoose_;
/*                Common_fatjet_SFupVLoose*/}

//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupLoose*/const vector<float> &VVVTree::Common_fatjet_SFupLoose() {
/*                 Common_fatjet_SFupLoose*/  if (not Common_fatjet_SFupLoose_isLoaded) {
/*                 Common_fatjet_SFupLoose*/    if (Common_fatjet_SFupLoose_branch != 0) {
/*                 Common_fatjet_SFupLoose*/      Common_fatjet_SFupLoose_branch->GetEntry(index);
/*                 Common_fatjet_SFupLoose*/    } else {
/*                 Common_fatjet_SFupLoose*/      printf("branch Common_fatjet_SFupLoose_branch does not exist!\n");
/*                 Common_fatjet_SFupLoose*/      exit(1);
/*                 Common_fatjet_SFupLoose*/    }
/*                 Common_fatjet_SFupLoose*/    Common_fatjet_SFupLoose_isLoaded = true;
/*                 Common_fatjet_SFupLoose*/  }
/*                 Common_fatjet_SFupLoose*/  return *Common_fatjet_SFupLoose_;
/*                 Common_fatjet_SFupLoose*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupMedium*/const vector<float> &VVVTree::Common_fatjet_SFupMedium() {
/*                Common_fatjet_SFupMedium*/  if (not Common_fatjet_SFupMedium_isLoaded) {
/*                Common_fatjet_SFupMedium*/    if (Common_fatjet_SFupMedium_branch != 0) {
/*                Common_fatjet_SFupMedium*/      Common_fatjet_SFupMedium_branch->GetEntry(index);
/*                Common_fatjet_SFupMedium*/    } else {
/*                Common_fatjet_SFupMedium*/      printf("branch Common_fatjet_SFupMedium_branch does not exist!\n");
/*                Common_fatjet_SFupMedium*/      exit(1);
/*                Common_fatjet_SFupMedium*/    }
/*                Common_fatjet_SFupMedium*/    Common_fatjet_SFupMedium_isLoaded = true;
/*                Common_fatjet_SFupMedium*/  }
/*                Common_fatjet_SFupMedium*/  return *Common_fatjet_SFupMedium_;
/*                Common_fatjet_SFupMedium*/}

//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupTight*/const vector<float> &VVVTree::Common_fatjet_SFupTight() {
/*                 Common_fatjet_SFupTight*/  if (not Common_fatjet_SFupTight_isLoaded) {
/*                 Common_fatjet_SFupTight*/    if (Common_fatjet_SFupTight_branch != 0) {
/*                 Common_fatjet_SFupTight*/      Common_fatjet_SFupTight_branch->GetEntry(index);
/*                 Common_fatjet_SFupTight*/    } else {
/*                 Common_fatjet_SFupTight*/      printf("branch Common_fatjet_SFupTight_branch does not exist!\n");
/*                 Common_fatjet_SFupTight*/      exit(1);
/*                 Common_fatjet_SFupTight*/    }
/*                 Common_fatjet_SFupTight*/    Common_fatjet_SFupTight_isLoaded = true;
/*                 Common_fatjet_SFupTight*/  }
/*                 Common_fatjet_SFupTight*/  return *Common_fatjet_SFupTight_;
/*                 Common_fatjet_SFupTight*/}

//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFVLoose*/const float &VVVTree::Common_eventweight_fatjet_SFVLoose() {
/*      Common_eventweight_fatjet_SFVLoose*/  if (not Common_eventweight_fatjet_SFVLoose_isLoaded) {
/*      Common_eventweight_fatjet_SFVLoose*/    if (Common_eventweight_fatjet_SFVLoose_branch != 0) {
/*      Common_eventweight_fatjet_SFVLoose*/      Common_eventweight_fatjet_SFVLoose_branch->GetEntry(index);
/*      Common_eventweight_fatjet_SFVLoose*/    } else {
/*      Common_eventweight_fatjet_SFVLoose*/      printf("branch Common_eventweight_fatjet_SFVLoose_branch does not exist!\n");
/*      Common_eventweight_fatjet_SFVLoose*/      exit(1);
/*      Common_eventweight_fatjet_SFVLoose*/    }
/*      Common_eventweight_fatjet_SFVLoose*/    Common_eventweight_fatjet_SFVLoose_isLoaded = true;
/*      Common_eventweight_fatjet_SFVLoose*/  }
/*      Common_eventweight_fatjet_SFVLoose*/  return Common_eventweight_fatjet_SFVLoose_;
/*      Common_eventweight_fatjet_SFVLoose*/}

//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFLoose*/const float &VVVTree::Common_eventweight_fatjet_SFLoose() {
/*       Common_eventweight_fatjet_SFLoose*/  if (not Common_eventweight_fatjet_SFLoose_isLoaded) {
/*       Common_eventweight_fatjet_SFLoose*/    if (Common_eventweight_fatjet_SFLoose_branch != 0) {
/*       Common_eventweight_fatjet_SFLoose*/      Common_eventweight_fatjet_SFLoose_branch->GetEntry(index);
/*       Common_eventweight_fatjet_SFLoose*/    } else {
/*       Common_eventweight_fatjet_SFLoose*/      printf("branch Common_eventweight_fatjet_SFLoose_branch does not exist!\n");
/*       Common_eventweight_fatjet_SFLoose*/      exit(1);
/*       Common_eventweight_fatjet_SFLoose*/    }
/*       Common_eventweight_fatjet_SFLoose*/    Common_eventweight_fatjet_SFLoose_isLoaded = true;
/*       Common_eventweight_fatjet_SFLoose*/  }
/*       Common_eventweight_fatjet_SFLoose*/  return Common_eventweight_fatjet_SFLoose_;
/*       Common_eventweight_fatjet_SFLoose*/}

//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFMedium*/const float &VVVTree::Common_eventweight_fatjet_SFMedium() {
/*      Common_eventweight_fatjet_SFMedium*/  if (not Common_eventweight_fatjet_SFMedium_isLoaded) {
/*      Common_eventweight_fatjet_SFMedium*/    if (Common_eventweight_fatjet_SFMedium_branch != 0) {
/*      Common_eventweight_fatjet_SFMedium*/      Common_eventweight_fatjet_SFMedium_branch->GetEntry(index);
/*      Common_eventweight_fatjet_SFMedium*/    } else {
/*      Common_eventweight_fatjet_SFMedium*/      printf("branch Common_eventweight_fatjet_SFMedium_branch does not exist!\n");
/*      Common_eventweight_fatjet_SFMedium*/      exit(1);
/*      Common_eventweight_fatjet_SFMedium*/    }
/*      Common_eventweight_fatjet_SFMedium*/    Common_eventweight_fatjet_SFMedium_isLoaded = true;
/*      Common_eventweight_fatjet_SFMedium*/  }
/*      Common_eventweight_fatjet_SFMedium*/  return Common_eventweight_fatjet_SFMedium_;
/*      Common_eventweight_fatjet_SFMedium*/}

//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFTight*/const float &VVVTree::Common_eventweight_fatjet_SFTight() {
/*       Common_eventweight_fatjet_SFTight*/  if (not Common_eventweight_fatjet_SFTight_isLoaded) {
/*       Common_eventweight_fatjet_SFTight*/    if (Common_eventweight_fatjet_SFTight_branch != 0) {
/*       Common_eventweight_fatjet_SFTight*/      Common_eventweight_fatjet_SFTight_branch->GetEntry(index);
/*       Common_eventweight_fatjet_SFTight*/    } else {
/*       Common_eventweight_fatjet_SFTight*/      printf("branch Common_eventweight_fatjet_SFTight_branch does not exist!\n");
/*       Common_eventweight_fatjet_SFTight*/      exit(1);
/*       Common_eventweight_fatjet_SFTight*/    }
/*       Common_eventweight_fatjet_SFTight*/    Common_eventweight_fatjet_SFTight_isLoaded = true;
/*       Common_eventweight_fatjet_SFTight*/  }
/*       Common_eventweight_fatjet_SFTight*/  return Common_eventweight_fatjet_SFTight_;
/*       Common_eventweight_fatjet_SFTight*/}

//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnVLoose*/const float &VVVTree::Common_eventweight_fatjet_SFdnVLoose() {
/*    Common_eventweight_fatjet_SFdnVLoose*/  if (not Common_eventweight_fatjet_SFdnVLoose_isLoaded) {
/*    Common_eventweight_fatjet_SFdnVLoose*/    if (Common_eventweight_fatjet_SFdnVLoose_branch != 0) {
/*    Common_eventweight_fatjet_SFdnVLoose*/      Common_eventweight_fatjet_SFdnVLoose_branch->GetEntry(index);
/*    Common_eventweight_fatjet_SFdnVLoose*/    } else {
/*    Common_eventweight_fatjet_SFdnVLoose*/      printf("branch Common_eventweight_fatjet_SFdnVLoose_branch does not exist!\n");
/*    Common_eventweight_fatjet_SFdnVLoose*/      exit(1);
/*    Common_eventweight_fatjet_SFdnVLoose*/    }
/*    Common_eventweight_fatjet_SFdnVLoose*/    Common_eventweight_fatjet_SFdnVLoose_isLoaded = true;
/*    Common_eventweight_fatjet_SFdnVLoose*/  }
/*    Common_eventweight_fatjet_SFdnVLoose*/  return Common_eventweight_fatjet_SFdnVLoose_;
/*    Common_eventweight_fatjet_SFdnVLoose*/}

//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnLoose*/const float &VVVTree::Common_eventweight_fatjet_SFdnLoose() {
/*     Common_eventweight_fatjet_SFdnLoose*/  if (not Common_eventweight_fatjet_SFdnLoose_isLoaded) {
/*     Common_eventweight_fatjet_SFdnLoose*/    if (Common_eventweight_fatjet_SFdnLoose_branch != 0) {
/*     Common_eventweight_fatjet_SFdnLoose*/      Common_eventweight_fatjet_SFdnLoose_branch->GetEntry(index);
/*     Common_eventweight_fatjet_SFdnLoose*/    } else {
/*     Common_eventweight_fatjet_SFdnLoose*/      printf("branch Common_eventweight_fatjet_SFdnLoose_branch does not exist!\n");
/*     Common_eventweight_fatjet_SFdnLoose*/      exit(1);
/*     Common_eventweight_fatjet_SFdnLoose*/    }
/*     Common_eventweight_fatjet_SFdnLoose*/    Common_eventweight_fatjet_SFdnLoose_isLoaded = true;
/*     Common_eventweight_fatjet_SFdnLoose*/  }
/*     Common_eventweight_fatjet_SFdnLoose*/  return Common_eventweight_fatjet_SFdnLoose_;
/*     Common_eventweight_fatjet_SFdnLoose*/}

//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnMedium*/const float &VVVTree::Common_eventweight_fatjet_SFdnMedium() {
/*    Common_eventweight_fatjet_SFdnMedium*/  if (not Common_eventweight_fatjet_SFdnMedium_isLoaded) {
/*    Common_eventweight_fatjet_SFdnMedium*/    if (Common_eventweight_fatjet_SFdnMedium_branch != 0) {
/*    Common_eventweight_fatjet_SFdnMedium*/      Common_eventweight_fatjet_SFdnMedium_branch->GetEntry(index);
/*    Common_eventweight_fatjet_SFdnMedium*/    } else {
/*    Common_eventweight_fatjet_SFdnMedium*/      printf("branch Common_eventweight_fatjet_SFdnMedium_branch does not exist!\n");
/*    Common_eventweight_fatjet_SFdnMedium*/      exit(1);
/*    Common_eventweight_fatjet_SFdnMedium*/    }
/*    Common_eventweight_fatjet_SFdnMedium*/    Common_eventweight_fatjet_SFdnMedium_isLoaded = true;
/*    Common_eventweight_fatjet_SFdnMedium*/  }
/*    Common_eventweight_fatjet_SFdnMedium*/  return Common_eventweight_fatjet_SFdnMedium_;
/*    Common_eventweight_fatjet_SFdnMedium*/}

//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnTight*/const float &VVVTree::Common_eventweight_fatjet_SFdnTight() {
/*     Common_eventweight_fatjet_SFdnTight*/  if (not Common_eventweight_fatjet_SFdnTight_isLoaded) {
/*     Common_eventweight_fatjet_SFdnTight*/    if (Common_eventweight_fatjet_SFdnTight_branch != 0) {
/*     Common_eventweight_fatjet_SFdnTight*/      Common_eventweight_fatjet_SFdnTight_branch->GetEntry(index);
/*     Common_eventweight_fatjet_SFdnTight*/    } else {
/*     Common_eventweight_fatjet_SFdnTight*/      printf("branch Common_eventweight_fatjet_SFdnTight_branch does not exist!\n");
/*     Common_eventweight_fatjet_SFdnTight*/      exit(1);
/*     Common_eventweight_fatjet_SFdnTight*/    }
/*     Common_eventweight_fatjet_SFdnTight*/    Common_eventweight_fatjet_SFdnTight_isLoaded = true;
/*     Common_eventweight_fatjet_SFdnTight*/  }
/*     Common_eventweight_fatjet_SFdnTight*/  return Common_eventweight_fatjet_SFdnTight_;
/*     Common_eventweight_fatjet_SFdnTight*/}

//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupVLoose*/const float &VVVTree::Common_eventweight_fatjet_SFupVLoose() {
/*    Common_eventweight_fatjet_SFupVLoose*/  if (not Common_eventweight_fatjet_SFupVLoose_isLoaded) {
/*    Common_eventweight_fatjet_SFupVLoose*/    if (Common_eventweight_fatjet_SFupVLoose_branch != 0) {
/*    Common_eventweight_fatjet_SFupVLoose*/      Common_eventweight_fatjet_SFupVLoose_branch->GetEntry(index);
/*    Common_eventweight_fatjet_SFupVLoose*/    } else {
/*    Common_eventweight_fatjet_SFupVLoose*/      printf("branch Common_eventweight_fatjet_SFupVLoose_branch does not exist!\n");
/*    Common_eventweight_fatjet_SFupVLoose*/      exit(1);
/*    Common_eventweight_fatjet_SFupVLoose*/    }
/*    Common_eventweight_fatjet_SFupVLoose*/    Common_eventweight_fatjet_SFupVLoose_isLoaded = true;
/*    Common_eventweight_fatjet_SFupVLoose*/  }
/*    Common_eventweight_fatjet_SFupVLoose*/  return Common_eventweight_fatjet_SFupVLoose_;
/*    Common_eventweight_fatjet_SFupVLoose*/}

//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupLoose*/const float &VVVTree::Common_eventweight_fatjet_SFupLoose() {
/*     Common_eventweight_fatjet_SFupLoose*/  if (not Common_eventweight_fatjet_SFupLoose_isLoaded) {
/*     Common_eventweight_fatjet_SFupLoose*/    if (Common_eventweight_fatjet_SFupLoose_branch != 0) {
/*     Common_eventweight_fatjet_SFupLoose*/      Common_eventweight_fatjet_SFupLoose_branch->GetEntry(index);
/*     Common_eventweight_fatjet_SFupLoose*/    } else {
/*     Common_eventweight_fatjet_SFupLoose*/      printf("branch Common_eventweight_fatjet_SFupLoose_branch does not exist!\n");
/*     Common_eventweight_fatjet_SFupLoose*/      exit(1);
/*     Common_eventweight_fatjet_SFupLoose*/    }
/*     Common_eventweight_fatjet_SFupLoose*/    Common_eventweight_fatjet_SFupLoose_isLoaded = true;
/*     Common_eventweight_fatjet_SFupLoose*/  }
/*     Common_eventweight_fatjet_SFupLoose*/  return Common_eventweight_fatjet_SFupLoose_;
/*     Common_eventweight_fatjet_SFupLoose*/}

//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupMedium*/const float &VVVTree::Common_eventweight_fatjet_SFupMedium() {
/*    Common_eventweight_fatjet_SFupMedium*/  if (not Common_eventweight_fatjet_SFupMedium_isLoaded) {
/*    Common_eventweight_fatjet_SFupMedium*/    if (Common_eventweight_fatjet_SFupMedium_branch != 0) {
/*    Common_eventweight_fatjet_SFupMedium*/      Common_eventweight_fatjet_SFupMedium_branch->GetEntry(index);
/*    Common_eventweight_fatjet_SFupMedium*/    } else {
/*    Common_eventweight_fatjet_SFupMedium*/      printf("branch Common_eventweight_fatjet_SFupMedium_branch does not exist!\n");
/*    Common_eventweight_fatjet_SFupMedium*/      exit(1);
/*    Common_eventweight_fatjet_SFupMedium*/    }
/*    Common_eventweight_fatjet_SFupMedium*/    Common_eventweight_fatjet_SFupMedium_isLoaded = true;
/*    Common_eventweight_fatjet_SFupMedium*/  }
/*    Common_eventweight_fatjet_SFupMedium*/  return Common_eventweight_fatjet_SFupMedium_;
/*    Common_eventweight_fatjet_SFupMedium*/}

//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupTight*/const float &VVVTree::Common_eventweight_fatjet_SFupTight() {
/*     Common_eventweight_fatjet_SFupTight*/  if (not Common_eventweight_fatjet_SFupTight_isLoaded) {
/*     Common_eventweight_fatjet_SFupTight*/    if (Common_eventweight_fatjet_SFupTight_branch != 0) {
/*     Common_eventweight_fatjet_SFupTight*/      Common_eventweight_fatjet_SFupTight_branch->GetEntry(index);
/*     Common_eventweight_fatjet_SFupTight*/    } else {
/*     Common_eventweight_fatjet_SFupTight*/      printf("branch Common_eventweight_fatjet_SFupTight_branch does not exist!\n");
/*     Common_eventweight_fatjet_SFupTight*/      exit(1);
/*     Common_eventweight_fatjet_SFupTight*/    }
/*     Common_eventweight_fatjet_SFupTight*/    Common_eventweight_fatjet_SFupTight_isLoaded = true;
/*     Common_eventweight_fatjet_SFupTight*/  }
/*     Common_eventweight_fatjet_SFupTight*/  return Common_eventweight_fatjet_SFupTight_;
/*     Common_eventweight_fatjet_SFupTight*/}

//---------------------------------------------------------------------------------
/*                         Common_nb_loose*/const int &VVVTree::Common_nb_loose() {
/*                         Common_nb_loose*/  if (not Common_nb_loose_isLoaded) {
/*                         Common_nb_loose*/    if (Common_nb_loose_branch != 0) {
/*                         Common_nb_loose*/      Common_nb_loose_branch->GetEntry(index);
/*                         Common_nb_loose*/    } else {
/*                         Common_nb_loose*/      printf("branch Common_nb_loose_branch does not exist!\n");
/*                         Common_nb_loose*/      exit(1);
/*                         Common_nb_loose*/    }
/*                         Common_nb_loose*/    Common_nb_loose_isLoaded = true;
/*                         Common_nb_loose*/  }
/*                         Common_nb_loose*/  return Common_nb_loose_;
/*                         Common_nb_loose*/}

//---------------------------------------------------------------------------------
/*                        Common_nb_medium*/const int &VVVTree::Common_nb_medium() {
/*                        Common_nb_medium*/  if (not Common_nb_medium_isLoaded) {
/*                        Common_nb_medium*/    if (Common_nb_medium_branch != 0) {
/*                        Common_nb_medium*/      Common_nb_medium_branch->GetEntry(index);
/*                        Common_nb_medium*/    } else {
/*                        Common_nb_medium*/      printf("branch Common_nb_medium_branch does not exist!\n");
/*                        Common_nb_medium*/      exit(1);
/*                        Common_nb_medium*/    }
/*                        Common_nb_medium*/    Common_nb_medium_isLoaded = true;
/*                        Common_nb_medium*/  }
/*                        Common_nb_medium*/  return Common_nb_medium_;
/*                        Common_nb_medium*/}

//---------------------------------------------------------------------------------
/*                         Common_nb_tight*/const int &VVVTree::Common_nb_tight() {
/*                         Common_nb_tight*/  if (not Common_nb_tight_isLoaded) {
/*                         Common_nb_tight*/    if (Common_nb_tight_branch != 0) {
/*                         Common_nb_tight*/      Common_nb_tight_branch->GetEntry(index);
/*                         Common_nb_tight*/    } else {
/*                         Common_nb_tight*/      printf("branch Common_nb_tight_branch does not exist!\n");
/*                         Common_nb_tight*/      exit(1);
/*                         Common_nb_tight*/    }
/*                         Common_nb_tight*/    Common_nb_tight_isLoaded = true;
/*                         Common_nb_tight*/  }
/*                         Common_nb_tight*/  return Common_nb_tight_;
/*                         Common_nb_tight*/}

//---------------------------------------------------------------------------------
/*                          Common_gen_idx*/const vector<int> &VVVTree::Common_gen_idx() {
/*                          Common_gen_idx*/  if (not Common_gen_idx_isLoaded) {
/*                          Common_gen_idx*/    if (Common_gen_idx_branch != 0) {
/*                          Common_gen_idx*/      Common_gen_idx_branch->GetEntry(index);
/*                          Common_gen_idx*/    } else {
/*                          Common_gen_idx*/      printf("branch Common_gen_idx_branch does not exist!\n");
/*                          Common_gen_idx*/      exit(1);
/*                          Common_gen_idx*/    }
/*                          Common_gen_idx*/    Common_gen_idx_isLoaded = true;
/*                          Common_gen_idx*/  }
/*                          Common_gen_idx*/  return *Common_gen_idx_;
/*                          Common_gen_idx*/}

//---------------------------------------------------------------------------------
/*                   Common_gen_mother_idx*/const vector<int> &VVVTree::Common_gen_mother_idx() {
/*                   Common_gen_mother_idx*/  if (not Common_gen_mother_idx_isLoaded) {
/*                   Common_gen_mother_idx*/    if (Common_gen_mother_idx_branch != 0) {
/*                   Common_gen_mother_idx*/      Common_gen_mother_idx_branch->GetEntry(index);
/*                   Common_gen_mother_idx*/    } else {
/*                   Common_gen_mother_idx*/      printf("branch Common_gen_mother_idx_branch does not exist!\n");
/*                   Common_gen_mother_idx*/      exit(1);
/*                   Common_gen_mother_idx*/    }
/*                   Common_gen_mother_idx*/    Common_gen_mother_idx_isLoaded = true;
/*                   Common_gen_mother_idx*/  }
/*                   Common_gen_mother_idx*/  return *Common_gen_mother_idx_;
/*                   Common_gen_mother_idx*/}

//---------------------------------------------------------------------------------
/*                    Common_gen_mother_id*/const vector<int> &VVVTree::Common_gen_mother_id() {
/*                    Common_gen_mother_id*/  if (not Common_gen_mother_id_isLoaded) {
/*                    Common_gen_mother_id*/    if (Common_gen_mother_id_branch != 0) {
/*                    Common_gen_mother_id*/      Common_gen_mother_id_branch->GetEntry(index);
/*                    Common_gen_mother_id*/    } else {
/*                    Common_gen_mother_id*/      printf("branch Common_gen_mother_id_branch does not exist!\n");
/*                    Common_gen_mother_id*/      exit(1);
/*                    Common_gen_mother_id*/    }
/*                    Common_gen_mother_id*/    Common_gen_mother_id_isLoaded = true;
/*                    Common_gen_mother_id*/  }
/*                    Common_gen_mother_id*/  return *Common_gen_mother_id_;
/*                    Common_gen_mother_id*/}

//---------------------------------------------------------------------------------
/*                        Common_gen_pdgid*/const vector<int> &VVVTree::Common_gen_pdgid() {
/*                        Common_gen_pdgid*/  if (not Common_gen_pdgid_isLoaded) {
/*                        Common_gen_pdgid*/    if (Common_gen_pdgid_branch != 0) {
/*                        Common_gen_pdgid*/      Common_gen_pdgid_branch->GetEntry(index);
/*                        Common_gen_pdgid*/    } else {
/*                        Common_gen_pdgid*/      printf("branch Common_gen_pdgid_branch does not exist!\n");
/*                        Common_gen_pdgid*/      exit(1);
/*                        Common_gen_pdgid*/    }
/*                        Common_gen_pdgid*/    Common_gen_pdgid_isLoaded = true;
/*                        Common_gen_pdgid*/  }
/*                        Common_gen_pdgid*/  return *Common_gen_pdgid_;
/*                        Common_gen_pdgid*/}

//---------------------------------------------------------------------------------
/*                          Common_gen_p4s*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_gen_p4s() {
/*                          Common_gen_p4s*/  if (not Common_gen_p4s_isLoaded) {
/*                          Common_gen_p4s*/    if (Common_gen_p4s_branch != 0) {
/*                          Common_gen_p4s*/      Common_gen_p4s_branch->GetEntry(index);
/*                          Common_gen_p4s*/    } else {
/*                          Common_gen_p4s*/      printf("branch Common_gen_p4s_branch does not exist!\n");
/*                          Common_gen_p4s*/      exit(1);
/*                          Common_gen_p4s*/    }
/*                          Common_gen_p4s*/    Common_gen_p4s_isLoaded = true;
/*                          Common_gen_p4s*/  }
/*                          Common_gen_p4s*/  return *Common_gen_p4s_;
/*                          Common_gen_p4s*/}

//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_idx*/const vector<int> &VVVTree::Common_gen_vvvdecay_idx() {
/*                 Common_gen_vvvdecay_idx*/  if (not Common_gen_vvvdecay_idx_isLoaded) {
/*                 Common_gen_vvvdecay_idx*/    if (Common_gen_vvvdecay_idx_branch != 0) {
/*                 Common_gen_vvvdecay_idx*/      Common_gen_vvvdecay_idx_branch->GetEntry(index);
/*                 Common_gen_vvvdecay_idx*/    } else {
/*                 Common_gen_vvvdecay_idx*/      printf("branch Common_gen_vvvdecay_idx_branch does not exist!\n");
/*                 Common_gen_vvvdecay_idx*/      exit(1);
/*                 Common_gen_vvvdecay_idx*/    }
/*                 Common_gen_vvvdecay_idx*/    Common_gen_vvvdecay_idx_isLoaded = true;
/*                 Common_gen_vvvdecay_idx*/  }
/*                 Common_gen_vvvdecay_idx*/  return *Common_gen_vvvdecay_idx_;
/*                 Common_gen_vvvdecay_idx*/}

//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_mother_idx*/const vector<int> &VVVTree::Common_gen_vvvdecay_mother_idx() {
/*          Common_gen_vvvdecay_mother_idx*/  if (not Common_gen_vvvdecay_mother_idx_isLoaded) {
/*          Common_gen_vvvdecay_mother_idx*/    if (Common_gen_vvvdecay_mother_idx_branch != 0) {
/*          Common_gen_vvvdecay_mother_idx*/      Common_gen_vvvdecay_mother_idx_branch->GetEntry(index);
/*          Common_gen_vvvdecay_mother_idx*/    } else {
/*          Common_gen_vvvdecay_mother_idx*/      printf("branch Common_gen_vvvdecay_mother_idx_branch does not exist!\n");
/*          Common_gen_vvvdecay_mother_idx*/      exit(1);
/*          Common_gen_vvvdecay_mother_idx*/    }
/*          Common_gen_vvvdecay_mother_idx*/    Common_gen_vvvdecay_mother_idx_isLoaded = true;
/*          Common_gen_vvvdecay_mother_idx*/  }
/*          Common_gen_vvvdecay_mother_idx*/  return *Common_gen_vvvdecay_mother_idx_;
/*          Common_gen_vvvdecay_mother_idx*/}

//---------------------------------------------------------------------------------
/*           Common_gen_vvvdecay_mother_id*/const vector<int> &VVVTree::Common_gen_vvvdecay_mother_id() {
/*           Common_gen_vvvdecay_mother_id*/  if (not Common_gen_vvvdecay_mother_id_isLoaded) {
/*           Common_gen_vvvdecay_mother_id*/    if (Common_gen_vvvdecay_mother_id_branch != 0) {
/*           Common_gen_vvvdecay_mother_id*/      Common_gen_vvvdecay_mother_id_branch->GetEntry(index);
/*           Common_gen_vvvdecay_mother_id*/    } else {
/*           Common_gen_vvvdecay_mother_id*/      printf("branch Common_gen_vvvdecay_mother_id_branch does not exist!\n");
/*           Common_gen_vvvdecay_mother_id*/      exit(1);
/*           Common_gen_vvvdecay_mother_id*/    }
/*           Common_gen_vvvdecay_mother_id*/    Common_gen_vvvdecay_mother_id_isLoaded = true;
/*           Common_gen_vvvdecay_mother_id*/  }
/*           Common_gen_vvvdecay_mother_id*/  return *Common_gen_vvvdecay_mother_id_;
/*           Common_gen_vvvdecay_mother_id*/}

//---------------------------------------------------------------------------------
/*               Common_gen_vvvdecay_pdgid*/const vector<int> &VVVTree::Common_gen_vvvdecay_pdgid() {
/*               Common_gen_vvvdecay_pdgid*/  if (not Common_gen_vvvdecay_pdgid_isLoaded) {
/*               Common_gen_vvvdecay_pdgid*/    if (Common_gen_vvvdecay_pdgid_branch != 0) {
/*               Common_gen_vvvdecay_pdgid*/      Common_gen_vvvdecay_pdgid_branch->GetEntry(index);
/*               Common_gen_vvvdecay_pdgid*/    } else {
/*               Common_gen_vvvdecay_pdgid*/      printf("branch Common_gen_vvvdecay_pdgid_branch does not exist!\n");
/*               Common_gen_vvvdecay_pdgid*/      exit(1);
/*               Common_gen_vvvdecay_pdgid*/    }
/*               Common_gen_vvvdecay_pdgid*/    Common_gen_vvvdecay_pdgid_isLoaded = true;
/*               Common_gen_vvvdecay_pdgid*/  }
/*               Common_gen_vvvdecay_pdgid*/  return *Common_gen_vvvdecay_pdgid_;
/*               Common_gen_vvvdecay_pdgid*/}

//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_p4s*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_gen_vvvdecay_p4s() {
/*                 Common_gen_vvvdecay_p4s*/  if (not Common_gen_vvvdecay_p4s_isLoaded) {
/*                 Common_gen_vvvdecay_p4s*/    if (Common_gen_vvvdecay_p4s_branch != 0) {
/*                 Common_gen_vvvdecay_p4s*/      Common_gen_vvvdecay_p4s_branch->GetEntry(index);
/*                 Common_gen_vvvdecay_p4s*/    } else {
/*                 Common_gen_vvvdecay_p4s*/      printf("branch Common_gen_vvvdecay_p4s_branch does not exist!\n");
/*                 Common_gen_vvvdecay_p4s*/      exit(1);
/*                 Common_gen_vvvdecay_p4s*/    }
/*                 Common_gen_vvvdecay_p4s*/    Common_gen_vvvdecay_p4s_isLoaded = true;
/*                 Common_gen_vvvdecay_p4s*/  }
/*                 Common_gen_vvvdecay_p4s*/  return *Common_gen_vvvdecay_p4s_;
/*                 Common_gen_vvvdecay_p4s*/}

//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_taudecayid*/const vector<int> &VVVTree::Common_gen_vvvdecay_taudecayid() {
/*          Common_gen_vvvdecay_taudecayid*/  if (not Common_gen_vvvdecay_taudecayid_isLoaded) {
/*          Common_gen_vvvdecay_taudecayid*/    if (Common_gen_vvvdecay_taudecayid_branch != 0) {
/*          Common_gen_vvvdecay_taudecayid*/      Common_gen_vvvdecay_taudecayid_branch->GetEntry(index);
/*          Common_gen_vvvdecay_taudecayid*/    } else {
/*          Common_gen_vvvdecay_taudecayid*/      printf("branch Common_gen_vvvdecay_taudecayid_branch does not exist!\n");
/*          Common_gen_vvvdecay_taudecayid*/      exit(1);
/*          Common_gen_vvvdecay_taudecayid*/    }
/*          Common_gen_vvvdecay_taudecayid*/    Common_gen_vvvdecay_taudecayid_isLoaded = true;
/*          Common_gen_vvvdecay_taudecayid*/  }
/*          Common_gen_vvvdecay_taudecayid*/  return *Common_gen_vvvdecay_taudecayid_;
/*          Common_gen_vvvdecay_taudecayid*/}

//---------------------------------------------------------------------------------
/*                              Common_n_W*/const int &VVVTree::Common_n_W() {
/*                              Common_n_W*/  if (not Common_n_W_isLoaded) {
/*                              Common_n_W*/    if (Common_n_W_branch != 0) {
/*                              Common_n_W*/      Common_n_W_branch->GetEntry(index);
/*                              Common_n_W*/    } else {
/*                              Common_n_W*/      printf("branch Common_n_W_branch does not exist!\n");
/*                              Common_n_W*/      exit(1);
/*                              Common_n_W*/    }
/*                              Common_n_W*/    Common_n_W_isLoaded = true;
/*                              Common_n_W*/  }
/*                              Common_n_W*/  return Common_n_W_;
/*                              Common_n_W*/}

//---------------------------------------------------------------------------------
/*                              Common_n_Z*/const int &VVVTree::Common_n_Z() {
/*                              Common_n_Z*/  if (not Common_n_Z_isLoaded) {
/*                              Common_n_Z*/    if (Common_n_Z_branch != 0) {
/*                              Common_n_Z*/      Common_n_Z_branch->GetEntry(index);
/*                              Common_n_Z*/    } else {
/*                              Common_n_Z*/      printf("branch Common_n_Z_branch does not exist!\n");
/*                              Common_n_Z*/      exit(1);
/*                              Common_n_Z*/    }
/*                              Common_n_Z*/    Common_n_Z_isLoaded = true;
/*                              Common_n_Z*/  }
/*                              Common_n_Z*/  return Common_n_Z_;
/*                              Common_n_Z*/}

//---------------------------------------------------------------------------------
/*                          Common_n_lep_Z*/const int &VVVTree::Common_n_lep_Z() {
/*                          Common_n_lep_Z*/  if (not Common_n_lep_Z_isLoaded) {
/*                          Common_n_lep_Z*/    if (Common_n_lep_Z_branch != 0) {
/*                          Common_n_lep_Z*/      Common_n_lep_Z_branch->GetEntry(index);
/*                          Common_n_lep_Z*/    } else {
/*                          Common_n_lep_Z*/      printf("branch Common_n_lep_Z_branch does not exist!\n");
/*                          Common_n_lep_Z*/      exit(1);
/*                          Common_n_lep_Z*/    }
/*                          Common_n_lep_Z*/    Common_n_lep_Z_isLoaded = true;
/*                          Common_n_lep_Z*/  }
/*                          Common_n_lep_Z*/  return Common_n_lep_Z_;
/*                          Common_n_lep_Z*/}

//---------------------------------------------------------------------------------
/*                       Common_n_leptau_Z*/const int &VVVTree::Common_n_leptau_Z() {
/*                       Common_n_leptau_Z*/  if (not Common_n_leptau_Z_isLoaded) {
/*                       Common_n_leptau_Z*/    if (Common_n_leptau_Z_branch != 0) {
/*                       Common_n_leptau_Z*/      Common_n_leptau_Z_branch->GetEntry(index);
/*                       Common_n_leptau_Z*/    } else {
/*                       Common_n_leptau_Z*/      printf("branch Common_n_leptau_Z_branch does not exist!\n");
/*                       Common_n_leptau_Z*/      exit(1);
/*                       Common_n_leptau_Z*/    }
/*                       Common_n_leptau_Z*/    Common_n_leptau_Z_isLoaded = true;
/*                       Common_n_leptau_Z*/  }
/*                       Common_n_leptau_Z*/  return Common_n_leptau_Z_;
/*                       Common_n_leptau_Z*/}

//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_Z*/const int &VVVTree::Common_n_hadtau_Z() {
/*                       Common_n_hadtau_Z*/  if (not Common_n_hadtau_Z_isLoaded) {
/*                       Common_n_hadtau_Z*/    if (Common_n_hadtau_Z_branch != 0) {
/*                       Common_n_hadtau_Z*/      Common_n_hadtau_Z_branch->GetEntry(index);
/*                       Common_n_hadtau_Z*/    } else {
/*                       Common_n_hadtau_Z*/      printf("branch Common_n_hadtau_Z_branch does not exist!\n");
/*                       Common_n_hadtau_Z*/      exit(1);
/*                       Common_n_hadtau_Z*/    }
/*                       Common_n_hadtau_Z*/    Common_n_hadtau_Z_isLoaded = true;
/*                       Common_n_hadtau_Z*/  }
/*                       Common_n_hadtau_Z*/  return Common_n_hadtau_Z_;
/*                       Common_n_hadtau_Z*/}

//---------------------------------------------------------------------------------
/*                           Common_n_nu_Z*/const int &VVVTree::Common_n_nu_Z() {
/*                           Common_n_nu_Z*/  if (not Common_n_nu_Z_isLoaded) {
/*                           Common_n_nu_Z*/    if (Common_n_nu_Z_branch != 0) {
/*                           Common_n_nu_Z*/      Common_n_nu_Z_branch->GetEntry(index);
/*                           Common_n_nu_Z*/    } else {
/*                           Common_n_nu_Z*/      printf("branch Common_n_nu_Z_branch does not exist!\n");
/*                           Common_n_nu_Z*/      exit(1);
/*                           Common_n_nu_Z*/    }
/*                           Common_n_nu_Z*/    Common_n_nu_Z_isLoaded = true;
/*                           Common_n_nu_Z*/  }
/*                           Common_n_nu_Z*/  return Common_n_nu_Z_;
/*                           Common_n_nu_Z*/}

//---------------------------------------------------------------------------------
/*                            Common_n_b_Z*/const int &VVVTree::Common_n_b_Z() {
/*                            Common_n_b_Z*/  if (not Common_n_b_Z_isLoaded) {
/*                            Common_n_b_Z*/    if (Common_n_b_Z_branch != 0) {
/*                            Common_n_b_Z*/      Common_n_b_Z_branch->GetEntry(index);
/*                            Common_n_b_Z*/    } else {
/*                            Common_n_b_Z*/      printf("branch Common_n_b_Z_branch does not exist!\n");
/*                            Common_n_b_Z*/      exit(1);
/*                            Common_n_b_Z*/    }
/*                            Common_n_b_Z*/    Common_n_b_Z_isLoaded = true;
/*                            Common_n_b_Z*/  }
/*                            Common_n_b_Z*/  return Common_n_b_Z_;
/*                            Common_n_b_Z*/}

//---------------------------------------------------------------------------------
/*                          Common_n_lep_W*/const int &VVVTree::Common_n_lep_W() {
/*                          Common_n_lep_W*/  if (not Common_n_lep_W_isLoaded) {
/*                          Common_n_lep_W*/    if (Common_n_lep_W_branch != 0) {
/*                          Common_n_lep_W*/      Common_n_lep_W_branch->GetEntry(index);
/*                          Common_n_lep_W*/    } else {
/*                          Common_n_lep_W*/      printf("branch Common_n_lep_W_branch does not exist!\n");
/*                          Common_n_lep_W*/      exit(1);
/*                          Common_n_lep_W*/    }
/*                          Common_n_lep_W*/    Common_n_lep_W_isLoaded = true;
/*                          Common_n_lep_W*/  }
/*                          Common_n_lep_W*/  return Common_n_lep_W_;
/*                          Common_n_lep_W*/}

//---------------------------------------------------------------------------------
/*                       Common_n_leptau_W*/const int &VVVTree::Common_n_leptau_W() {
/*                       Common_n_leptau_W*/  if (not Common_n_leptau_W_isLoaded) {
/*                       Common_n_leptau_W*/    if (Common_n_leptau_W_branch != 0) {
/*                       Common_n_leptau_W*/      Common_n_leptau_W_branch->GetEntry(index);
/*                       Common_n_leptau_W*/    } else {
/*                       Common_n_leptau_W*/      printf("branch Common_n_leptau_W_branch does not exist!\n");
/*                       Common_n_leptau_W*/      exit(1);
/*                       Common_n_leptau_W*/    }
/*                       Common_n_leptau_W*/    Common_n_leptau_W_isLoaded = true;
/*                       Common_n_leptau_W*/  }
/*                       Common_n_leptau_W*/  return Common_n_leptau_W_;
/*                       Common_n_leptau_W*/}

//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_W*/const int &VVVTree::Common_n_hadtau_W() {
/*                       Common_n_hadtau_W*/  if (not Common_n_hadtau_W_isLoaded) {
/*                       Common_n_hadtau_W*/    if (Common_n_hadtau_W_branch != 0) {
/*                       Common_n_hadtau_W*/      Common_n_hadtau_W_branch->GetEntry(index);
/*                       Common_n_hadtau_W*/    } else {
/*                       Common_n_hadtau_W*/      printf("branch Common_n_hadtau_W_branch does not exist!\n");
/*                       Common_n_hadtau_W*/      exit(1);
/*                       Common_n_hadtau_W*/    }
/*                       Common_n_hadtau_W*/    Common_n_hadtau_W_isLoaded = true;
/*                       Common_n_hadtau_W*/  }
/*                       Common_n_hadtau_W*/  return Common_n_hadtau_W_;
/*                       Common_n_hadtau_W*/}

//---------------------------------------------------------------------------------
/*                        Common_haslepWSS*/const bool &VVVTree::Common_haslepWSS() {
/*                        Common_haslepWSS*/  if (not Common_haslepWSS_isLoaded) {
/*                        Common_haslepWSS*/    if (Common_haslepWSS_branch != 0) {
/*                        Common_haslepWSS*/      Common_haslepWSS_branch->GetEntry(index);
/*                        Common_haslepWSS*/    } else {
/*                        Common_haslepWSS*/      printf("branch Common_haslepWSS_branch does not exist!\n");
/*                        Common_haslepWSS*/      exit(1);
/*                        Common_haslepWSS*/    }
/*                        Common_haslepWSS*/    Common_haslepWSS_isLoaded = true;
/*                        Common_haslepWSS*/  }
/*                        Common_haslepWSS*/  return Common_haslepWSS_;
/*                        Common_haslepWSS*/}

//---------------------------------------------------------------------------------
/*                            Common_genHT*/const float &VVVTree::Common_genHT() {
/*                            Common_genHT*/  if (not Common_genHT_isLoaded) {
/*                            Common_genHT*/    if (Common_genHT_branch != 0) {
/*                            Common_genHT*/      Common_genHT_branch->GetEntry(index);
/*                            Common_genHT*/    } else {
/*                            Common_genHT*/      printf("branch Common_genHT_branch does not exist!\n");
/*                            Common_genHT*/      exit(1);
/*                            Common_genHT*/    }
/*                            Common_genHT*/    Common_genHT_isLoaded = true;
/*                            Common_genHT*/  }
/*                            Common_genHT*/  return Common_genHT_;
/*                            Common_genHT*/}

//---------------------------------------------------------------------------------
/*                  Common_gen_n_light_lep*/const int &VVVTree::Common_gen_n_light_lep() {
/*                  Common_gen_n_light_lep*/  if (not Common_gen_n_light_lep_isLoaded) {
/*                  Common_gen_n_light_lep*/    if (Common_gen_n_light_lep_branch != 0) {
/*                  Common_gen_n_light_lep*/      Common_gen_n_light_lep_branch->GetEntry(index);
/*                  Common_gen_n_light_lep*/    } else {
/*                  Common_gen_n_light_lep*/      printf("branch Common_gen_n_light_lep_branch does not exist!\n");
/*                  Common_gen_n_light_lep*/      exit(1);
/*                  Common_gen_n_light_lep*/    }
/*                  Common_gen_n_light_lep*/    Common_gen_n_light_lep_isLoaded = true;
/*                  Common_gen_n_light_lep*/  }
/*                  Common_gen_n_light_lep*/  return Common_gen_n_light_lep_;
/*                  Common_gen_n_light_lep*/}

//---------------------------------------------------------------------------------
/*                   Common_gen_VH_channel*/const int &VVVTree::Common_gen_VH_channel() {
/*                   Common_gen_VH_channel*/  if (not Common_gen_VH_channel_isLoaded) {
/*                   Common_gen_VH_channel*/    if (Common_gen_VH_channel_branch != 0) {
/*                   Common_gen_VH_channel*/      Common_gen_VH_channel_branch->GetEntry(index);
/*                   Common_gen_VH_channel*/    } else {
/*                   Common_gen_VH_channel*/      printf("branch Common_gen_VH_channel_branch does not exist!\n");
/*                   Common_gen_VH_channel*/      exit(1);
/*                   Common_gen_VH_channel*/    }
/*                   Common_gen_VH_channel*/    Common_gen_VH_channel_isLoaded = true;
/*                   Common_gen_VH_channel*/  }
/*                   Common_gen_VH_channel*/  return Common_gen_VH_channel_;
/*                   Common_gen_VH_channel*/}

//---------------------------------------------------------------------------------
/*                Cut_4LepMET_Preselection*/const bool &VVVTree::Cut_4LepMET_Preselection() {
/*                Cut_4LepMET_Preselection*/  if (not Cut_4LepMET_Preselection_isLoaded) {
/*                Cut_4LepMET_Preselection*/    if (Cut_4LepMET_Preselection_branch != 0) {
/*                Cut_4LepMET_Preselection*/      Cut_4LepMET_Preselection_branch->GetEntry(index);
/*                Cut_4LepMET_Preselection*/    } else {
/*                Cut_4LepMET_Preselection*/      printf("branch Cut_4LepMET_Preselection_branch does not exist!\n");
/*                Cut_4LepMET_Preselection*/      exit(1);
/*                Cut_4LepMET_Preselection*/    }
/*                Cut_4LepMET_Preselection*/    Cut_4LepMET_Preselection_isLoaded = true;
/*                Cut_4LepMET_Preselection*/  }
/*                Cut_4LepMET_Preselection*/  return Cut_4LepMET_Preselection_;
/*                Cut_4LepMET_Preselection*/}

//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/const bool &VVVTree::Cut_4LepMET_emuChannel() {
/*                  Cut_4LepMET_emuChannel*/  if (not Cut_4LepMET_emuChannel_isLoaded) {
/*                  Cut_4LepMET_emuChannel*/    if (Cut_4LepMET_emuChannel_branch != 0) {
/*                  Cut_4LepMET_emuChannel*/      Cut_4LepMET_emuChannel_branch->GetEntry(index);
/*                  Cut_4LepMET_emuChannel*/    } else {
/*                  Cut_4LepMET_emuChannel*/      printf("branch Cut_4LepMET_emuChannel_branch does not exist!\n");
/*                  Cut_4LepMET_emuChannel*/      exit(1);
/*                  Cut_4LepMET_emuChannel*/    }
/*                  Cut_4LepMET_emuChannel*/    Cut_4LepMET_emuChannel_isLoaded = true;
/*                  Cut_4LepMET_emuChannel*/  }
/*                  Cut_4LepMET_emuChannel*/  return Cut_4LepMET_emuChannel_;
/*                  Cut_4LepMET_emuChannel*/}

//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/const bool &VVVTree::Cut_4LepMET_offzChannel() {
/*                 Cut_4LepMET_offzChannel*/  if (not Cut_4LepMET_offzChannel_isLoaded) {
/*                 Cut_4LepMET_offzChannel*/    if (Cut_4LepMET_offzChannel_branch != 0) {
/*                 Cut_4LepMET_offzChannel*/      Cut_4LepMET_offzChannel_branch->GetEntry(index);
/*                 Cut_4LepMET_offzChannel*/    } else {
/*                 Cut_4LepMET_offzChannel*/      printf("branch Cut_4LepMET_offzChannel_branch does not exist!\n");
/*                 Cut_4LepMET_offzChannel*/      exit(1);
/*                 Cut_4LepMET_offzChannel*/    }
/*                 Cut_4LepMET_offzChannel*/    Cut_4LepMET_offzChannel_isLoaded = true;
/*                 Cut_4LepMET_offzChannel*/  }
/*                 Cut_4LepMET_offzChannel*/  return Cut_4LepMET_offzChannel_;
/*                 Cut_4LepMET_offzChannel*/}

//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/const bool &VVVTree::Cut_4LepMET_onzChannel() {
/*                  Cut_4LepMET_onzChannel*/  if (not Cut_4LepMET_onzChannel_isLoaded) {
/*                  Cut_4LepMET_onzChannel*/    if (Cut_4LepMET_onzChannel_branch != 0) {
/*                  Cut_4LepMET_onzChannel*/      Cut_4LepMET_onzChannel_branch->GetEntry(index);
/*                  Cut_4LepMET_onzChannel*/    } else {
/*                  Cut_4LepMET_onzChannel*/      printf("branch Cut_4LepMET_onzChannel_branch does not exist!\n");
/*                  Cut_4LepMET_onzChannel*/      exit(1);
/*                  Cut_4LepMET_onzChannel*/    }
/*                  Cut_4LepMET_onzChannel*/    Cut_4LepMET_onzChannel_isLoaded = true;
/*                  Cut_4LepMET_onzChannel*/  }
/*                  Cut_4LepMET_onzChannel*/  return Cut_4LepMET_onzChannel_;
/*                  Cut_4LepMET_onzChannel*/}

//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/const bool &VVVTree::Cut_4LepMET_onzChannel_HighMET() {
/*          Cut_4LepMET_onzChannel_HighMET*/  if (not Cut_4LepMET_onzChannel_HighMET_isLoaded) {
/*          Cut_4LepMET_onzChannel_HighMET*/    if (Cut_4LepMET_onzChannel_HighMET_branch != 0) {
/*          Cut_4LepMET_onzChannel_HighMET*/      Cut_4LepMET_onzChannel_HighMET_branch->GetEntry(index);
/*          Cut_4LepMET_onzChannel_HighMET*/    } else {
/*          Cut_4LepMET_onzChannel_HighMET*/      printf("branch Cut_4LepMET_onzChannel_HighMET_branch does not exist!\n");
/*          Cut_4LepMET_onzChannel_HighMET*/      exit(1);
/*          Cut_4LepMET_onzChannel_HighMET*/    }
/*          Cut_4LepMET_onzChannel_HighMET*/    Cut_4LepMET_onzChannel_HighMET_isLoaded = true;
/*          Cut_4LepMET_onzChannel_HighMET*/  }
/*          Cut_4LepMET_onzChannel_HighMET*/  return Cut_4LepMET_onzChannel_HighMET_;
/*          Cut_4LepMET_onzChannel_HighMET*/}

//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/const int &VVVTree::Var_4LepMET_Zcand_lep_idx_0() {
/*             Var_4LepMET_Zcand_lep_idx_0*/  if (not Var_4LepMET_Zcand_lep_idx_0_isLoaded) {
/*             Var_4LepMET_Zcand_lep_idx_0*/    if (Var_4LepMET_Zcand_lep_idx_0_branch != 0) {
/*             Var_4LepMET_Zcand_lep_idx_0*/      Var_4LepMET_Zcand_lep_idx_0_branch->GetEntry(index);
/*             Var_4LepMET_Zcand_lep_idx_0*/    } else {
/*             Var_4LepMET_Zcand_lep_idx_0*/      printf("branch Var_4LepMET_Zcand_lep_idx_0_branch does not exist!\n");
/*             Var_4LepMET_Zcand_lep_idx_0*/      exit(1);
/*             Var_4LepMET_Zcand_lep_idx_0*/    }
/*             Var_4LepMET_Zcand_lep_idx_0*/    Var_4LepMET_Zcand_lep_idx_0_isLoaded = true;
/*             Var_4LepMET_Zcand_lep_idx_0*/  }
/*             Var_4LepMET_Zcand_lep_idx_0*/  return Var_4LepMET_Zcand_lep_idx_0_;
/*             Var_4LepMET_Zcand_lep_idx_0*/}

//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/const int &VVVTree::Var_4LepMET_Zcand_lep_pdgid_0() {
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  if (not Var_4LepMET_Zcand_lep_pdgid_0_isLoaded) {
/*           Var_4LepMET_Zcand_lep_pdgid_0*/    if (Var_4LepMET_Zcand_lep_pdgid_0_branch != 0) {
/*           Var_4LepMET_Zcand_lep_pdgid_0*/      Var_4LepMET_Zcand_lep_pdgid_0_branch->GetEntry(index);
/*           Var_4LepMET_Zcand_lep_pdgid_0*/    } else {
/*           Var_4LepMET_Zcand_lep_pdgid_0*/      printf("branch Var_4LepMET_Zcand_lep_pdgid_0_branch does not exist!\n");
/*           Var_4LepMET_Zcand_lep_pdgid_0*/      exit(1);
/*           Var_4LepMET_Zcand_lep_pdgid_0*/    }
/*           Var_4LepMET_Zcand_lep_pdgid_0*/    Var_4LepMET_Zcand_lep_pdgid_0_isLoaded = true;
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  }
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  return Var_4LepMET_Zcand_lep_pdgid_0_;
/*           Var_4LepMET_Zcand_lep_pdgid_0*/}

//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_0*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Var_4LepMET_Zcand_lep_p4_0() {
/*              Var_4LepMET_Zcand_lep_p4_0*/  if (not Var_4LepMET_Zcand_lep_p4_0_isLoaded) {
/*              Var_4LepMET_Zcand_lep_p4_0*/    if (Var_4LepMET_Zcand_lep_p4_0_branch != 0) {
/*              Var_4LepMET_Zcand_lep_p4_0*/      Var_4LepMET_Zcand_lep_p4_0_branch->GetEntry(index);
/*              Var_4LepMET_Zcand_lep_p4_0*/    } else {
/*              Var_4LepMET_Zcand_lep_p4_0*/      printf("branch Var_4LepMET_Zcand_lep_p4_0_branch does not exist!\n");
/*              Var_4LepMET_Zcand_lep_p4_0*/      exit(1);
/*              Var_4LepMET_Zcand_lep_p4_0*/    }
/*              Var_4LepMET_Zcand_lep_p4_0*/    Var_4LepMET_Zcand_lep_p4_0_isLoaded = true;
/*              Var_4LepMET_Zcand_lep_p4_0*/  }
/*              Var_4LepMET_Zcand_lep_p4_0*/  return *Var_4LepMET_Zcand_lep_p4_0_;
/*              Var_4LepMET_Zcand_lep_p4_0*/}

//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_1*/const int &VVVTree::Var_4LepMET_Zcand_lep_idx_1() {
/*             Var_4LepMET_Zcand_lep_idx_1*/  if (not Var_4LepMET_Zcand_lep_idx_1_isLoaded) {
/*             Var_4LepMET_Zcand_lep_idx_1*/    if (Var_4LepMET_Zcand_lep_idx_1_branch != 0) {
/*             Var_4LepMET_Zcand_lep_idx_1*/      Var_4LepMET_Zcand_lep_idx_1_branch->GetEntry(index);
/*             Var_4LepMET_Zcand_lep_idx_1*/    } else {
/*             Var_4LepMET_Zcand_lep_idx_1*/      printf("branch Var_4LepMET_Zcand_lep_idx_1_branch does not exist!\n");
/*             Var_4LepMET_Zcand_lep_idx_1*/      exit(1);
/*             Var_4LepMET_Zcand_lep_idx_1*/    }
/*             Var_4LepMET_Zcand_lep_idx_1*/    Var_4LepMET_Zcand_lep_idx_1_isLoaded = true;
/*             Var_4LepMET_Zcand_lep_idx_1*/  }
/*             Var_4LepMET_Zcand_lep_idx_1*/  return Var_4LepMET_Zcand_lep_idx_1_;
/*             Var_4LepMET_Zcand_lep_idx_1*/}

//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_1*/const int &VVVTree::Var_4LepMET_Zcand_lep_pdgid_1() {
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  if (not Var_4LepMET_Zcand_lep_pdgid_1_isLoaded) {
/*           Var_4LepMET_Zcand_lep_pdgid_1*/    if (Var_4LepMET_Zcand_lep_pdgid_1_branch != 0) {
/*           Var_4LepMET_Zcand_lep_pdgid_1*/      Var_4LepMET_Zcand_lep_pdgid_1_branch->GetEntry(index);
/*           Var_4LepMET_Zcand_lep_pdgid_1*/    } else {
/*           Var_4LepMET_Zcand_lep_pdgid_1*/      printf("branch Var_4LepMET_Zcand_lep_pdgid_1_branch does not exist!\n");
/*           Var_4LepMET_Zcand_lep_pdgid_1*/      exit(1);
/*           Var_4LepMET_Zcand_lep_pdgid_1*/    }
/*           Var_4LepMET_Zcand_lep_pdgid_1*/    Var_4LepMET_Zcand_lep_pdgid_1_isLoaded = true;
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  }
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  return Var_4LepMET_Zcand_lep_pdgid_1_;
/*           Var_4LepMET_Zcand_lep_pdgid_1*/}

//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_1*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Var_4LepMET_Zcand_lep_p4_1() {
/*              Var_4LepMET_Zcand_lep_p4_1*/  if (not Var_4LepMET_Zcand_lep_p4_1_isLoaded) {
/*              Var_4LepMET_Zcand_lep_p4_1*/    if (Var_4LepMET_Zcand_lep_p4_1_branch != 0) {
/*              Var_4LepMET_Zcand_lep_p4_1*/      Var_4LepMET_Zcand_lep_p4_1_branch->GetEntry(index);
/*              Var_4LepMET_Zcand_lep_p4_1*/    } else {
/*              Var_4LepMET_Zcand_lep_p4_1*/      printf("branch Var_4LepMET_Zcand_lep_p4_1_branch does not exist!\n");
/*              Var_4LepMET_Zcand_lep_p4_1*/      exit(1);
/*              Var_4LepMET_Zcand_lep_p4_1*/    }
/*              Var_4LepMET_Zcand_lep_p4_1*/    Var_4LepMET_Zcand_lep_p4_1_isLoaded = true;
/*              Var_4LepMET_Zcand_lep_p4_1*/  }
/*              Var_4LepMET_Zcand_lep_p4_1*/  return *Var_4LepMET_Zcand_lep_p4_1_;
/*              Var_4LepMET_Zcand_lep_p4_1*/}

//---------------------------------------------------------------------------------
/*                   Var_4LepMET_Zcand_mll*/const float &VVVTree::Var_4LepMET_Zcand_mll() {
/*                   Var_4LepMET_Zcand_mll*/  if (not Var_4LepMET_Zcand_mll_isLoaded) {
/*                   Var_4LepMET_Zcand_mll*/    if (Var_4LepMET_Zcand_mll_branch != 0) {
/*                   Var_4LepMET_Zcand_mll*/      Var_4LepMET_Zcand_mll_branch->GetEntry(index);
/*                   Var_4LepMET_Zcand_mll*/    } else {
/*                   Var_4LepMET_Zcand_mll*/      printf("branch Var_4LepMET_Zcand_mll_branch does not exist!\n");
/*                   Var_4LepMET_Zcand_mll*/      exit(1);
/*                   Var_4LepMET_Zcand_mll*/    }
/*                   Var_4LepMET_Zcand_mll*/    Var_4LepMET_Zcand_mll_isLoaded = true;
/*                   Var_4LepMET_Zcand_mll*/  }
/*                   Var_4LepMET_Zcand_mll*/  return Var_4LepMET_Zcand_mll_;
/*                   Var_4LepMET_Zcand_mll*/}

//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_0*/const int &VVVTree::Var_4LepMET_other_lep_idx_0() {
/*             Var_4LepMET_other_lep_idx_0*/  if (not Var_4LepMET_other_lep_idx_0_isLoaded) {
/*             Var_4LepMET_other_lep_idx_0*/    if (Var_4LepMET_other_lep_idx_0_branch != 0) {
/*             Var_4LepMET_other_lep_idx_0*/      Var_4LepMET_other_lep_idx_0_branch->GetEntry(index);
/*             Var_4LepMET_other_lep_idx_0*/    } else {
/*             Var_4LepMET_other_lep_idx_0*/      printf("branch Var_4LepMET_other_lep_idx_0_branch does not exist!\n");
/*             Var_4LepMET_other_lep_idx_0*/      exit(1);
/*             Var_4LepMET_other_lep_idx_0*/    }
/*             Var_4LepMET_other_lep_idx_0*/    Var_4LepMET_other_lep_idx_0_isLoaded = true;
/*             Var_4LepMET_other_lep_idx_0*/  }
/*             Var_4LepMET_other_lep_idx_0*/  return Var_4LepMET_other_lep_idx_0_;
/*             Var_4LepMET_other_lep_idx_0*/}

//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_0*/const int &VVVTree::Var_4LepMET_other_lep_pdgid_0() {
/*           Var_4LepMET_other_lep_pdgid_0*/  if (not Var_4LepMET_other_lep_pdgid_0_isLoaded) {
/*           Var_4LepMET_other_lep_pdgid_0*/    if (Var_4LepMET_other_lep_pdgid_0_branch != 0) {
/*           Var_4LepMET_other_lep_pdgid_0*/      Var_4LepMET_other_lep_pdgid_0_branch->GetEntry(index);
/*           Var_4LepMET_other_lep_pdgid_0*/    } else {
/*           Var_4LepMET_other_lep_pdgid_0*/      printf("branch Var_4LepMET_other_lep_pdgid_0_branch does not exist!\n");
/*           Var_4LepMET_other_lep_pdgid_0*/      exit(1);
/*           Var_4LepMET_other_lep_pdgid_0*/    }
/*           Var_4LepMET_other_lep_pdgid_0*/    Var_4LepMET_other_lep_pdgid_0_isLoaded = true;
/*           Var_4LepMET_other_lep_pdgid_0*/  }
/*           Var_4LepMET_other_lep_pdgid_0*/  return Var_4LepMET_other_lep_pdgid_0_;
/*           Var_4LepMET_other_lep_pdgid_0*/}

//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_0*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Var_4LepMET_other_lep_p4_0() {
/*              Var_4LepMET_other_lep_p4_0*/  if (not Var_4LepMET_other_lep_p4_0_isLoaded) {
/*              Var_4LepMET_other_lep_p4_0*/    if (Var_4LepMET_other_lep_p4_0_branch != 0) {
/*              Var_4LepMET_other_lep_p4_0*/      Var_4LepMET_other_lep_p4_0_branch->GetEntry(index);
/*              Var_4LepMET_other_lep_p4_0*/    } else {
/*              Var_4LepMET_other_lep_p4_0*/      printf("branch Var_4LepMET_other_lep_p4_0_branch does not exist!\n");
/*              Var_4LepMET_other_lep_p4_0*/      exit(1);
/*              Var_4LepMET_other_lep_p4_0*/    }
/*              Var_4LepMET_other_lep_p4_0*/    Var_4LepMET_other_lep_p4_0_isLoaded = true;
/*              Var_4LepMET_other_lep_p4_0*/  }
/*              Var_4LepMET_other_lep_p4_0*/  return *Var_4LepMET_other_lep_p4_0_;
/*              Var_4LepMET_other_lep_p4_0*/}

//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_1*/const int &VVVTree::Var_4LepMET_other_lep_idx_1() {
/*             Var_4LepMET_other_lep_idx_1*/  if (not Var_4LepMET_other_lep_idx_1_isLoaded) {
/*             Var_4LepMET_other_lep_idx_1*/    if (Var_4LepMET_other_lep_idx_1_branch != 0) {
/*             Var_4LepMET_other_lep_idx_1*/      Var_4LepMET_other_lep_idx_1_branch->GetEntry(index);
/*             Var_4LepMET_other_lep_idx_1*/    } else {
/*             Var_4LepMET_other_lep_idx_1*/      printf("branch Var_4LepMET_other_lep_idx_1_branch does not exist!\n");
/*             Var_4LepMET_other_lep_idx_1*/      exit(1);
/*             Var_4LepMET_other_lep_idx_1*/    }
/*             Var_4LepMET_other_lep_idx_1*/    Var_4LepMET_other_lep_idx_1_isLoaded = true;
/*             Var_4LepMET_other_lep_idx_1*/  }
/*             Var_4LepMET_other_lep_idx_1*/  return Var_4LepMET_other_lep_idx_1_;
/*             Var_4LepMET_other_lep_idx_1*/}

//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_1*/const int &VVVTree::Var_4LepMET_other_lep_pdgid_1() {
/*           Var_4LepMET_other_lep_pdgid_1*/  if (not Var_4LepMET_other_lep_pdgid_1_isLoaded) {
/*           Var_4LepMET_other_lep_pdgid_1*/    if (Var_4LepMET_other_lep_pdgid_1_branch != 0) {
/*           Var_4LepMET_other_lep_pdgid_1*/      Var_4LepMET_other_lep_pdgid_1_branch->GetEntry(index);
/*           Var_4LepMET_other_lep_pdgid_1*/    } else {
/*           Var_4LepMET_other_lep_pdgid_1*/      printf("branch Var_4LepMET_other_lep_pdgid_1_branch does not exist!\n");
/*           Var_4LepMET_other_lep_pdgid_1*/      exit(1);
/*           Var_4LepMET_other_lep_pdgid_1*/    }
/*           Var_4LepMET_other_lep_pdgid_1*/    Var_4LepMET_other_lep_pdgid_1_isLoaded = true;
/*           Var_4LepMET_other_lep_pdgid_1*/  }
/*           Var_4LepMET_other_lep_pdgid_1*/  return Var_4LepMET_other_lep_pdgid_1_;
/*           Var_4LepMET_other_lep_pdgid_1*/}

//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_1*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Var_4LepMET_other_lep_p4_1() {
/*              Var_4LepMET_other_lep_p4_1*/  if (not Var_4LepMET_other_lep_p4_1_isLoaded) {
/*              Var_4LepMET_other_lep_p4_1*/    if (Var_4LepMET_other_lep_p4_1_branch != 0) {
/*              Var_4LepMET_other_lep_p4_1*/      Var_4LepMET_other_lep_p4_1_branch->GetEntry(index);
/*              Var_4LepMET_other_lep_p4_1*/    } else {
/*              Var_4LepMET_other_lep_p4_1*/      printf("branch Var_4LepMET_other_lep_p4_1_branch does not exist!\n");
/*              Var_4LepMET_other_lep_p4_1*/      exit(1);
/*              Var_4LepMET_other_lep_p4_1*/    }
/*              Var_4LepMET_other_lep_p4_1*/    Var_4LepMET_other_lep_p4_1_isLoaded = true;
/*              Var_4LepMET_other_lep_p4_1*/  }
/*              Var_4LepMET_other_lep_p4_1*/  return *Var_4LepMET_other_lep_p4_1_;
/*              Var_4LepMET_other_lep_p4_1*/}

//---------------------------------------------------------------------------------
/*                   Var_4LepMET_other_mll*/const float &VVVTree::Var_4LepMET_other_mll() {
/*                   Var_4LepMET_other_mll*/  if (not Var_4LepMET_other_mll_isLoaded) {
/*                   Var_4LepMET_other_mll*/    if (Var_4LepMET_other_mll_branch != 0) {
/*                   Var_4LepMET_other_mll*/      Var_4LepMET_other_mll_branch->GetEntry(index);
/*                   Var_4LepMET_other_mll*/    } else {
/*                   Var_4LepMET_other_mll*/      printf("branch Var_4LepMET_other_mll_branch does not exist!\n");
/*                   Var_4LepMET_other_mll*/      exit(1);
/*                   Var_4LepMET_other_mll*/    }
/*                   Var_4LepMET_other_mll*/    Var_4LepMET_other_mll_isLoaded = true;
/*                   Var_4LepMET_other_mll*/  }
/*                   Var_4LepMET_other_mll*/  return Var_4LepMET_other_mll_;
/*                   Var_4LepMET_other_mll*/}

//---------------------------------------------------------------------------------
/*                         Var_4LepMET_mt2*/const float &VVVTree::Var_4LepMET_mt2() {
/*                         Var_4LepMET_mt2*/  if (not Var_4LepMET_mt2_isLoaded) {
/*                         Var_4LepMET_mt2*/    if (Var_4LepMET_mt2_branch != 0) {
/*                         Var_4LepMET_mt2*/      Var_4LepMET_mt2_branch->GetEntry(index);
/*                         Var_4LepMET_mt2*/    } else {
/*                         Var_4LepMET_mt2*/      printf("branch Var_4LepMET_mt2_branch does not exist!\n");
/*                         Var_4LepMET_mt2*/      exit(1);
/*                         Var_4LepMET_mt2*/    }
/*                         Var_4LepMET_mt2*/    Var_4LepMET_mt2_isLoaded = true;
/*                         Var_4LepMET_mt2*/  }
/*                         Var_4LepMET_mt2*/  return Var_4LepMET_mt2_;
/*                         Var_4LepMET_mt2*/}

//---------------------------------------------------------------------------------

void VVVTree::progress( int nEventsTotal, int nEventsChain ){
  int period = 1000;
  if (nEventsTotal%1000 == 0) {
    // xterm magic from L. Vacavant and A. Cerri
    if (isatty(1)) {
      if ((nEventsChain - nEventsTotal) > period) {
        float frac = (float)nEventsTotal/(nEventsChain*0.01);
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
             "\033[0m\033[32m <---\033[0m\015", frac);
        fflush(stdout);
      }
      else {
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", 100.);
        cout << endl;
      }
    }
  }
}

namespace tas {

//---------------------------------------------------------------------------------
/*                           Common_isData*/const int &Common_isData() { return vvv.Common_isData(); }
//---------------------------------------------------------------------------------
/*                              Common_run*/const int &Common_run() { return vvv.Common_run(); }
//---------------------------------------------------------------------------------
/*                             Common_lumi*/const int &Common_lumi() { return vvv.Common_lumi(); }
//---------------------------------------------------------------------------------
/*                              Common_evt*/const unsigned long long &Common_evt() { return vvv.Common_evt(); }
//---------------------------------------------------------------------------------
/*                        Common_genWeight*/const float &Common_genWeight() { return vvv.Common_genWeight(); }
//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/const float &Common_btagWeight_DeepCSVB() { return vvv.Common_btagWeight_DeepCSVB(); }
//---------------------------------------------------------------------------------
/*         Common_LHEWeight_mg_reweighting*/const vector<float> &Common_LHEWeight_mg_reweighting() { return vvv.Common_LHEWeight_mg_reweighting(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ() { return vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ(); }
//---------------------------------------------------------------------------------
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL() { return vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8() { return vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/const bool &Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() { return vvv.Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/const bool &Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL() { return vvv.Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/const bool &Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() { return vvv.Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/const bool &Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL() { return vvv.Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/const bool &Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ() { return vvv.Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/const bool &Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL() { return vvv.Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL(); }
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleEl*/const bool &Common_HLT_DoubleEl() { return vvv.Common_HLT_DoubleEl(); }
//---------------------------------------------------------------------------------
/*                         Common_HLT_MuEG*/const bool &Common_HLT_MuEG() { return vvv.Common_HLT_MuEG(); }
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleMu*/const bool &Common_HLT_DoubleMu() { return vvv.Common_HLT_DoubleMu(); }
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_ee_em_mm*/const bool &Common_pass_duplicate_removal_ee_em_mm() { return vvv.Common_pass_duplicate_removal_ee_em_mm(); }
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_mm_em_ee*/const bool &Common_pass_duplicate_removal_mm_em_ee() { return vvv.Common_pass_duplicate_removal_mm_em_ee(); }
//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/const bool &Common_noiseFlag() { return vvv.Common_noiseFlag(); }
//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/const bool &Common_noiseFlagMC() { return vvv.Common_noiseFlagMC(); }
//---------------------------------------------------------------------------------
/*                           Common_met_p4*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4() { return vvv.Common_met_p4(); }
//---------------------------------------------------------------------------------
/*                      Common_event_lepSF*/const float &Common_event_lepSF() { return vvv.Common_event_lepSF(); }
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFelup*/const float &Common_event_lepSFelup() { return vvv.Common_event_lepSFelup(); }
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFeldn*/const float &Common_event_lepSFeldn() { return vvv.Common_event_lepSFeldn(); }
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmuup*/const float &Common_event_lepSFmuup() { return vvv.Common_event_lepSFmuup(); }
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmudn*/const float &Common_event_lepSFmudn() { return vvv.Common_event_lepSFmudn(); }
//---------------------------------------------------------------------------------
/*                           Common_lep_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_lep_p4() { return vvv.Common_lep_p4(); }
//---------------------------------------------------------------------------------
/*                         Common_lep_idxs*/const vector<int> &Common_lep_idxs() { return vvv.Common_lep_idxs(); }
//---------------------------------------------------------------------------------
/*                        Common_lep_pdgid*/const vector<int> &Common_lep_pdgid() { return vvv.Common_lep_pdgid(); }
//---------------------------------------------------------------------------------
/*                        Common_lep_tight*/const vector<int> &Common_lep_tight() { return vvv.Common_lep_tight(); }
//---------------------------------------------------------------------------------
/*                          Common_lep_dxy*/const vector<float> &Common_lep_dxy() { return vvv.Common_lep_dxy(); }
//---------------------------------------------------------------------------------
/*                           Common_lep_dz*/const vector<float> &Common_lep_dz() { return vvv.Common_lep_dz(); }
//---------------------------------------------------------------------------------
/*                         Common_lep_ip3d*/const vector<float> &Common_lep_ip3d() { return vvv.Common_lep_ip3d(); }
//---------------------------------------------------------------------------------
/*                        Common_lep_sip3d*/const vector<float> &Common_lep_sip3d() { return vvv.Common_lep_sip3d(); }
//---------------------------------------------------------------------------------
/*                           Common_lep_SF*/const vector<float> &Common_lep_SF() { return vvv.Common_lep_SF(); }
//---------------------------------------------------------------------------------
/*                      Common_lep_SFTight*/const vector<float> &Common_lep_SFTight() { return vvv.Common_lep_SFTight(); }
//---------------------------------------------------------------------------------
/*                         Common_lep_SFdn*/const vector<float> &Common_lep_SFdn() { return vvv.Common_lep_SFdn(); }
//---------------------------------------------------------------------------------
/*                    Common_lep_SFdnTight*/const vector<float> &Common_lep_SFdnTight() { return vvv.Common_lep_SFdnTight(); }
//---------------------------------------------------------------------------------
/*                         Common_lep_SFup*/const vector<float> &Common_lep_SFup() { return vvv.Common_lep_SFup(); }
//---------------------------------------------------------------------------------
/*                    Common_lep_SFupTight*/const vector<float> &Common_lep_SFupTight() { return vvv.Common_lep_SFupTight(); }
//---------------------------------------------------------------------------------
/*                           Common_jet_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4() { return vvv.Common_jet_p4(); }
//---------------------------------------------------------------------------------
/*                         Common_jet_idxs*/const vector<int> &Common_jet_idxs() { return vvv.Common_jet_idxs(); }
//---------------------------------------------------------------------------------
/*                   Common_jet_passBloose*/const vector<bool> &Common_jet_passBloose() { return vvv.Common_jet_passBloose(); }
//---------------------------------------------------------------------------------
/*                  Common_jet_passBmedium*/const vector<bool> &Common_jet_passBmedium() { return vvv.Common_jet_passBmedium(); }
//---------------------------------------------------------------------------------
/*                   Common_jet_passBtight*/const vector<bool> &Common_jet_passBtight() { return vvv.Common_jet_passBtight(); }
//---------------------------------------------------------------------------------
/*                Common_jet_overlapfatjet*/const vector<int> &Common_jet_overlapfatjet() { return vvv.Common_jet_overlapfatjet(); }
//---------------------------------------------------------------------------------
/*                        Common_fatjet_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4() { return vvv.Common_fatjet_p4(); }
//---------------------------------------------------------------------------------
/*                      Common_fatjet_idxs*/const vector<int> &Common_fatjet_idxs() { return vvv.Common_fatjet_idxs(); }
//---------------------------------------------------------------------------------
/*                 Common_fatjet_msoftdrop*/const vector<float> &Common_fatjet_msoftdrop() { return vvv.Common_fatjet_msoftdrop(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_W*/const vector<float> &Common_fatjet_deepMD_W() { return vvv.Common_fatjet_deepMD_W(); }
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_W*/const vector<float> &Common_fatjet_deep_W() { return vvv.Common_fatjet_deep_W(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_Z*/const vector<float> &Common_fatjet_deepMD_Z() { return vvv.Common_fatjet_deepMD_Z(); }
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_Z*/const vector<float> &Common_fatjet_deep_Z() { return vvv.Common_fatjet_deep_Z(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_T*/const vector<float> &Common_fatjet_deepMD_T() { return vvv.Common_fatjet_deepMD_T(); }
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_T*/const vector<float> &Common_fatjet_deep_T() { return vvv.Common_fatjet_deep_T(); }
//---------------------------------------------------------------------------------
/*                 Common_fatjet_deepMD_bb*/const vector<float> &Common_fatjet_deepMD_bb() { return vvv.Common_fatjet_deepMD_bb(); }
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau3*/const vector<float> &Common_fatjet_tau3() { return vvv.Common_fatjet_tau3(); }
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau2*/const vector<float> &Common_fatjet_tau2() { return vvv.Common_fatjet_tau2(); }
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau1*/const vector<float> &Common_fatjet_tau1() { return vvv.Common_fatjet_tau1(); }
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau32*/const vector<float> &Common_fatjet_tau32() { return vvv.Common_fatjet_tau32(); }
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau21*/const vector<float> &Common_fatjet_tau21() { return vvv.Common_fatjet_tau21(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_pt*/const vector<float> &Common_fatjet_subjet0_pt() { return vvv.Common_fatjet_subjet0_pt(); }
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_eta*/const vector<float> &Common_fatjet_subjet0_eta() { return vvv.Common_fatjet_subjet0_eta(); }
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_phi*/const vector<float> &Common_fatjet_subjet0_phi() { return vvv.Common_fatjet_subjet0_phi(); }
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet0_mass*/const vector<float> &Common_fatjet_subjet0_mass() { return vvv.Common_fatjet_subjet0_mass(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_pt*/const vector<float> &Common_fatjet_subjet1_pt() { return vvv.Common_fatjet_subjet1_pt(); }
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_eta*/const vector<float> &Common_fatjet_subjet1_eta() { return vvv.Common_fatjet_subjet1_eta(); }
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_phi*/const vector<float> &Common_fatjet_subjet1_phi() { return vvv.Common_fatjet_subjet1_phi(); }
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet1_mass*/const vector<float> &Common_fatjet_subjet1_mass() { return vvv.Common_fatjet_subjet1_mass(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_subjet0_p4() { return vvv.Common_fatjet_subjet0_p4(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_subjet1_p4() { return vvv.Common_fatjet_subjet1_p4(); }
//---------------------------------------------------------------------------------
/*                        Common_fatjet_WP*/const vector<int> &Common_fatjet_WP() { return vvv.Common_fatjet_WP(); }
//---------------------------------------------------------------------------------
/*            Common_fatjet_WP_antimasscut*/const vector<int> &Common_fatjet_WP_antimasscut() { return vvv.Common_fatjet_WP_antimasscut(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFVLoose*/const vector<float> &Common_fatjet_SFVLoose() { return vvv.Common_fatjet_SFVLoose(); }
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFLoose*/const vector<float> &Common_fatjet_SFLoose() { return vvv.Common_fatjet_SFLoose(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFMedium*/const vector<float> &Common_fatjet_SFMedium() { return vvv.Common_fatjet_SFMedium(); }
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFTight*/const vector<float> &Common_fatjet_SFTight() { return vvv.Common_fatjet_SFTight(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnVLoose*/const vector<float> &Common_fatjet_SFdnVLoose() { return vvv.Common_fatjet_SFdnVLoose(); }
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnLoose*/const vector<float> &Common_fatjet_SFdnLoose() { return vvv.Common_fatjet_SFdnLoose(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnMedium*/const vector<float> &Common_fatjet_SFdnMedium() { return vvv.Common_fatjet_SFdnMedium(); }
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnTight*/const vector<float> &Common_fatjet_SFdnTight() { return vvv.Common_fatjet_SFdnTight(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupVLoose*/const vector<float> &Common_fatjet_SFupVLoose() { return vvv.Common_fatjet_SFupVLoose(); }
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupLoose*/const vector<float> &Common_fatjet_SFupLoose() { return vvv.Common_fatjet_SFupLoose(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupMedium*/const vector<float> &Common_fatjet_SFupMedium() { return vvv.Common_fatjet_SFupMedium(); }
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupTight*/const vector<float> &Common_fatjet_SFupTight() { return vvv.Common_fatjet_SFupTight(); }
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFVLoose*/const float &Common_eventweight_fatjet_SFVLoose() { return vvv.Common_eventweight_fatjet_SFVLoose(); }
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFLoose*/const float &Common_eventweight_fatjet_SFLoose() { return vvv.Common_eventweight_fatjet_SFLoose(); }
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFMedium*/const float &Common_eventweight_fatjet_SFMedium() { return vvv.Common_eventweight_fatjet_SFMedium(); }
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFTight*/const float &Common_eventweight_fatjet_SFTight() { return vvv.Common_eventweight_fatjet_SFTight(); }
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnVLoose*/const float &Common_eventweight_fatjet_SFdnVLoose() { return vvv.Common_eventweight_fatjet_SFdnVLoose(); }
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnLoose*/const float &Common_eventweight_fatjet_SFdnLoose() { return vvv.Common_eventweight_fatjet_SFdnLoose(); }
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnMedium*/const float &Common_eventweight_fatjet_SFdnMedium() { return vvv.Common_eventweight_fatjet_SFdnMedium(); }
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnTight*/const float &Common_eventweight_fatjet_SFdnTight() { return vvv.Common_eventweight_fatjet_SFdnTight(); }
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupVLoose*/const float &Common_eventweight_fatjet_SFupVLoose() { return vvv.Common_eventweight_fatjet_SFupVLoose(); }
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupLoose*/const float &Common_eventweight_fatjet_SFupLoose() { return vvv.Common_eventweight_fatjet_SFupLoose(); }
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupMedium*/const float &Common_eventweight_fatjet_SFupMedium() { return vvv.Common_eventweight_fatjet_SFupMedium(); }
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupTight*/const float &Common_eventweight_fatjet_SFupTight() { return vvv.Common_eventweight_fatjet_SFupTight(); }
//---------------------------------------------------------------------------------
/*                         Common_nb_loose*/const int &Common_nb_loose() { return vvv.Common_nb_loose(); }
//---------------------------------------------------------------------------------
/*                        Common_nb_medium*/const int &Common_nb_medium() { return vvv.Common_nb_medium(); }
//---------------------------------------------------------------------------------
/*                         Common_nb_tight*/const int &Common_nb_tight() { return vvv.Common_nb_tight(); }
//---------------------------------------------------------------------------------
/*                          Common_gen_idx*/const vector<int> &Common_gen_idx() { return vvv.Common_gen_idx(); }
//---------------------------------------------------------------------------------
/*                   Common_gen_mother_idx*/const vector<int> &Common_gen_mother_idx() { return vvv.Common_gen_mother_idx(); }
//---------------------------------------------------------------------------------
/*                    Common_gen_mother_id*/const vector<int> &Common_gen_mother_id() { return vvv.Common_gen_mother_id(); }
//---------------------------------------------------------------------------------
/*                        Common_gen_pdgid*/const vector<int> &Common_gen_pdgid() { return vvv.Common_gen_pdgid(); }
//---------------------------------------------------------------------------------
/*                          Common_gen_p4s*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_gen_p4s() { return vvv.Common_gen_p4s(); }
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_idx*/const vector<int> &Common_gen_vvvdecay_idx() { return vvv.Common_gen_vvvdecay_idx(); }
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_mother_idx*/const vector<int> &Common_gen_vvvdecay_mother_idx() { return vvv.Common_gen_vvvdecay_mother_idx(); }
//---------------------------------------------------------------------------------
/*           Common_gen_vvvdecay_mother_id*/const vector<int> &Common_gen_vvvdecay_mother_id() { return vvv.Common_gen_vvvdecay_mother_id(); }
//---------------------------------------------------------------------------------
/*               Common_gen_vvvdecay_pdgid*/const vector<int> &Common_gen_vvvdecay_pdgid() { return vvv.Common_gen_vvvdecay_pdgid(); }
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_p4s*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_gen_vvvdecay_p4s() { return vvv.Common_gen_vvvdecay_p4s(); }
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_taudecayid*/const vector<int> &Common_gen_vvvdecay_taudecayid() { return vvv.Common_gen_vvvdecay_taudecayid(); }
//---------------------------------------------------------------------------------
/*                              Common_n_W*/const int &Common_n_W() { return vvv.Common_n_W(); }
//---------------------------------------------------------------------------------
/*                              Common_n_Z*/const int &Common_n_Z() { return vvv.Common_n_Z(); }
//---------------------------------------------------------------------------------
/*                          Common_n_lep_Z*/const int &Common_n_lep_Z() { return vvv.Common_n_lep_Z(); }
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_Z*/const int &Common_n_leptau_Z() { return vvv.Common_n_leptau_Z(); }
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_Z*/const int &Common_n_hadtau_Z() { return vvv.Common_n_hadtau_Z(); }
//---------------------------------------------------------------------------------
/*                           Common_n_nu_Z*/const int &Common_n_nu_Z() { return vvv.Common_n_nu_Z(); }
//---------------------------------------------------------------------------------
/*                            Common_n_b_Z*/const int &Common_n_b_Z() { return vvv.Common_n_b_Z(); }
//---------------------------------------------------------------------------------
/*                          Common_n_lep_W*/const int &Common_n_lep_W() { return vvv.Common_n_lep_W(); }
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_W*/const int &Common_n_leptau_W() { return vvv.Common_n_leptau_W(); }
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_W*/const int &Common_n_hadtau_W() { return vvv.Common_n_hadtau_W(); }
//---------------------------------------------------------------------------------
/*                        Common_haslepWSS*/const bool &Common_haslepWSS() { return vvv.Common_haslepWSS(); }
//---------------------------------------------------------------------------------
/*                            Common_genHT*/const float &Common_genHT() { return vvv.Common_genHT(); }
//---------------------------------------------------------------------------------
/*                  Common_gen_n_light_lep*/const int &Common_gen_n_light_lep() { return vvv.Common_gen_n_light_lep(); }
//---------------------------------------------------------------------------------
/*                   Common_gen_VH_channel*/const int &Common_gen_VH_channel() { return vvv.Common_gen_VH_channel(); }
//---------------------------------------------------------------------------------
/*                Cut_4LepMET_Preselection*/const bool &Cut_4LepMET_Preselection() { return vvv.Cut_4LepMET_Preselection(); }
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/const bool &Cut_4LepMET_emuChannel() { return vvv.Cut_4LepMET_emuChannel(); }
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/const bool &Cut_4LepMET_offzChannel() { return vvv.Cut_4LepMET_offzChannel(); }
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/const bool &Cut_4LepMET_onzChannel() { return vvv.Cut_4LepMET_onzChannel(); }
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/const bool &Cut_4LepMET_onzChannel_HighMET() { return vvv.Cut_4LepMET_onzChannel_HighMET(); }
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/const int &Var_4LepMET_Zcand_lep_idx_0() { return vvv.Var_4LepMET_Zcand_lep_idx_0(); }
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/const int &Var_4LepMET_Zcand_lep_pdgid_0() { return vvv.Var_4LepMET_Zcand_lep_pdgid_0(); }
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_0*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_Zcand_lep_p4_0() { return vvv.Var_4LepMET_Zcand_lep_p4_0(); }
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_1*/const int &Var_4LepMET_Zcand_lep_idx_1() { return vvv.Var_4LepMET_Zcand_lep_idx_1(); }
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_1*/const int &Var_4LepMET_Zcand_lep_pdgid_1() { return vvv.Var_4LepMET_Zcand_lep_pdgid_1(); }
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_1*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_Zcand_lep_p4_1() { return vvv.Var_4LepMET_Zcand_lep_p4_1(); }
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_Zcand_mll*/const float &Var_4LepMET_Zcand_mll() { return vvv.Var_4LepMET_Zcand_mll(); }
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_0*/const int &Var_4LepMET_other_lep_idx_0() { return vvv.Var_4LepMET_other_lep_idx_0(); }
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_0*/const int &Var_4LepMET_other_lep_pdgid_0() { return vvv.Var_4LepMET_other_lep_pdgid_0(); }
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_0*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_other_lep_p4_0() { return vvv.Var_4LepMET_other_lep_p4_0(); }
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_1*/const int &Var_4LepMET_other_lep_idx_1() { return vvv.Var_4LepMET_other_lep_idx_1(); }
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_1*/const int &Var_4LepMET_other_lep_pdgid_1() { return vvv.Var_4LepMET_other_lep_pdgid_1(); }
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_1*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_other_lep_p4_1() { return vvv.Var_4LepMET_other_lep_p4_1(); }
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_other_mll*/const float &Var_4LepMET_other_mll() { return vvv.Var_4LepMET_other_mll(); }
//---------------------------------------------------------------------------------
/*                         Var_4LepMET_mt2*/const float &Var_4LepMET_mt2() { return vvv.Var_4LepMET_mt2(); }
//---------------------------------------------------------------------------------

}

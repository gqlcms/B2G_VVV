#include "Process_1Lepton.h"


TLorentzVector getNeutrinoP4(double& MetPt, double& MetPhi, TLorentzVector& lep, int lepType){
        float MW_=80.385;

        double leppt = lep.Pt();
        double lepphi = lep.Phi();
        double lepeta = lep.Eta();
        double lepenergy = lep.Energy();

        double metpt = MetPt;
        double metphi = MetPhi;

        double  px = metpt*cos(metphi);
        double  py = metpt*sin(metphi);
        double  pz = 0;
        double  pxl= leppt*cos(lepphi);
        double  pyl= leppt*sin(lepphi);
        double  pzl= leppt*sinh(lepeta);
        double  El = lepenergy;
        double  a = pow(MW_,2) + pow(px+pxl,2) + pow(py+pyl,2) - px*px - py*py - El*El + pzl*pzl;
        double  b = 2.*pzl;
        double  A = b*b -4.*El*El;
        double  B = 2.*a*b;
        double  C = a*a-4.*(px*px+py*py)*El*El;

        ///////////////////////////pz for fnal
        double M_mu =  0;

        //if(lepType==1)M_mu=0.105658367;//mu
        //if(lepType==0)M_mu=0.00051099891;//electron

        int type=2; // use the small abs real root

        a = MW_*MW_ - M_mu*M_mu + 2.0*pxl*px + 2.0*pyl*py;
        A = 4.0*(El*El - pzl*pzl);
        B = -4.0*a*pzl;
        C = 4.0*El*El*(px*px + py*py) - a*a;

        double tmproot = B*B - 4.0*A*C;

        if (tmproot<0) {
            //std::cout << "Complex root detected, taking real part..." << std::endl;
            pz = - B/(2*A); // take real part of complex roots
        }
        else {
            double tmpsol1 = (-B + sqrt(tmproot))/(2.0*A);
            double tmpsol2 = (-B - sqrt(tmproot))/(2.0*A);
            //std::cout << " Neutrino Solutions: " << tmpsol1 << ", " << tmpsol2 << std::endl;

            if (type == 0 ) {
                // two real roots, pick the one closest to pz of muon
                if (TMath::Abs(tmpsol2-pzl) < TMath::Abs(tmpsol1-pzl)) { pz = tmpsol2; }
                else { pz = tmpsol1; }
                // if pz is > 300 pick the most central root
                if ( abs(pz) > 300. ) {
                    if (TMath::Abs(tmpsol1)<TMath::Abs(tmpsol2) ) { pz = tmpsol1; }
                    else { pz = tmpsol2; }
                }
            }
            if (type == 1 ) {
                // two real roots, pick the one closest to pz of muon
                if (TMath::Abs(tmpsol2-pzl) < TMath::Abs(tmpsol1-pzl)) { pz = tmpsol2; }
                else {pz = tmpsol1; }
            }
            if (type == 2 ) {
                // pick the most central root.
                if (TMath::Abs(tmpsol1)<TMath::Abs(tmpsol2) ) { pz = tmpsol1; }
                else { pz = tmpsol2; }
            }
            /*if (type == 3 ) {
             // pick the largest value of the cosine
             TVector3 p3w, p3mu;
             p3w.SetXYZ(pxl+px, pyl+py, pzl+ tmpsol1);
             p3mu.SetXYZ(pxl, pyl, pzl );

             double sinthcm1 = 2.*(p3mu.Perp(p3w))/MW_;
             p3w.SetXYZ(pxl+px, pyl+py, pzl+ tmpsol2);
             double sinthcm2 = 2.*(p3mu.Perp(p3w))/MW_;

             double costhcm1 = sqrt(1. - sinthcm1*sinthcm1);
             double costhcm2 = sqrt(1. - sinthcm2*sinthcm2);

             if ( costhcm1 > costhcm2 ) { pz = tmpsol1; otherSol_ = tmpsol2; }
             else { pz = tmpsol2;otherSol_ = tmpsol1; }

             }*///end of type3

        }//endl of if real root

        //dont correct pt neutrino
        TLorentzVector outP4;
        outP4.SetPxPyPzE(px,py,pz,sqrt(px*px+py*py+pz*pz));
        return outP4;

    }

void Process_1Lepton_leptonicW(){

    float ptlep1 =-99., etalep1 =-99., philep1 =-99., energylep1 =-99.;
    int lep;
    if ( ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size() == 1 ){
        ptlep1 = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].pt();
        etalep1 = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].eta();
        philep1 = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].phi();
        energylep1 = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].energy();
        lep = ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0];
    }
    
    TLorentzVector  glepton,neutrino,neutrinoP4,WLeptonic;
    glepton.SetPtEtaPhiE(ptlep1, etalep1, philep1, energylep1);

    int leptontype = 1; double MET_et_JER = 0, MET_phi = 0;
    MET_et_JER = nt.MET_pt();
    MET_phi = nt.MET_phi();
    neutrino = getNeutrinoP4(MET_et_JER , MET_phi, glepton, leptontype);
    neutrinoP4.SetPtEtaPhiE(neutrino.Pt(),neutrino.Eta(),neutrino.Phi(),neutrino.Energy());

    WLeptonic = glepton+neutrinoP4;

    ana.tx.setBranch<float>("ptlep1", ptlep1);
    ana.tx.setBranch<float>("ptlep2", neutrinoP4.Pt());
    ana.tx.setBranch<float>("etalep1", etalep1);
    ana.tx.setBranch<float>("etalep2", neutrinoP4.Eta());
    ana.tx.setBranch<float>("philep1", philep1);
    ana.tx.setBranch<float>("philep2", neutrinoP4.Phi());
    ana.tx.setBranch<int>("lep", lep);
    ana.tx.setBranch<float>("energylep1", energylep1);
    ana.tx.setBranch<float>("met", MET_et_JER);
    ana.tx.setBranch<float>("metPhi", MET_phi);
    ana.tx.setBranch<float>("ptVlep", WLeptonic.Pt());
    ana.tx.setBranch<float>("yVlep", WLeptonic.Eta());
    ana.tx.setBranch<float>("phiVlep", WLeptonic.Phi());
    ana.tx.setBranch<float>("massVlep", WLeptonic.M());
    ana.tx.setBranch<float>("mtVlep", WLeptonic.Mt());

}

void Proces_1Lepton_NanoAODBranch(){
    // fatJets
    for (unsigned int inum = 0; inum < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); ++inum){
        int i = ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum];
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_area", nt.FatJet_area()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_btagCMVA", nt.FatJet_btagCMVA()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_btagCSVV2", nt.FatJet_btagCSVV2()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_btagDDBvL", nt.FatJet_btagDDBvL()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_btagDDBvL_noMD", nt.FatJet_btagDDBvL_noMD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_btagDDCvB", nt.FatJet_btagDDCvB()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_btagDDCvB_noMD", nt.FatJet_btagDDCvB_noMD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_btagDDCvL", nt.FatJet_btagDDCvL()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_btagDDCvL_noMD", nt.FatJet_btagDDCvL_noMD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_btagDeepB", nt.FatJet_btagDeepB()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_btagHbb", nt.FatJet_btagHbb()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTagMD_H4qvsQCD", nt.FatJet_deepTagMD_H4qvsQCD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTagMD_HbbvsQCD", nt.FatJet_deepTagMD_HbbvsQCD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTagMD_TvsQCD", nt.FatJet_deepTagMD_TvsQCD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTagMD_WvsQCD", nt.FatJet_deepTagMD_WvsQCD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTagMD_ZHbbvsQCD", nt.FatJet_deepTagMD_ZHbbvsQCD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTagMD_ZHccvsQCD", nt.FatJet_deepTagMD_ZHccvsQCD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTagMD_ZbbvsQCD", nt.FatJet_deepTagMD_ZbbvsQCD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTagMD_ZvsQCD", nt.FatJet_deepTagMD_ZvsQCD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTagMD_bbvsLight", nt.FatJet_deepTagMD_bbvsLight()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTagMD_ccvsLight", nt.FatJet_deepTagMD_ccvsLight()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTag_H", nt.FatJet_deepTag_H()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTag_QCD", nt.FatJet_deepTag_QCD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTag_QCDothers", nt.FatJet_deepTag_QCDothers()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTag_TvsQCD", nt.FatJet_deepTag_TvsQCD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTag_WvsQCD", nt.FatJet_deepTag_WvsQCD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_deepTag_ZvsQCD", nt.FatJet_deepTag_ZvsQCD()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_eta", nt.FatJet_eta()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_mass", nt.FatJet_mass()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_msoftdrop", nt.FatJet_msoftdrop()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_n2b1", nt.FatJet_n2b1()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_n3b1", nt.FatJet_n3b1()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_phi", nt.FatJet_phi()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_pt", nt.FatJet_pt()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_rawFactor", nt.FatJet_rawFactor()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_tau1", nt.FatJet_tau1()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_tau2", nt.FatJet_tau2()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_tau3", nt.FatJet_tau3()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_tau4", nt.FatJet_tau4()[i]);
        ana.tx.pushbackToBranch<float>("Lepton1_FatJet_lsf3", nt.FatJet_lsf3()[i]);
        ana.tx.pushbackToBranch<int>("Lepton1_FatJet_jetId", nt.FatJet_jetId()[i]);
        ana.tx.pushbackToBranch<int>("Lepton1_FatJet_subJetIdx1", nt.FatJet_subJetIdx1()[i]);
        ana.tx.pushbackToBranch<int>("Lepton1_FatJet_subJetIdx2", nt.FatJet_subJetIdx2()[i]);
        ana.tx.pushbackToBranch<int>("Lepton1_FatJet_electronIdx3SJ", nt.FatJet_electronIdx3SJ()[i]);
        ana.tx.pushbackToBranch<int>("Lepton1_FatJet_muonIdx3SJ", nt.FatJet_muonIdx3SJ()[i]);
        ana.tx.pushbackToBranch<int>("Lepton1_FatJet_genJetAK8Idx", nt.FatJet_genJetAK8Idx()[i]);
        ana.tx.pushbackToBranch<int>("Lepton1_FatJet_hadronFlavour", nt.FatJet_hadronFlavour()[i]);
        ana.tx.pushbackToBranch<int>("Lepton1_FatJet_nBHadrons", nt.FatJet_nBHadrons()[i]);
        ana.tx.pushbackToBranch<int>("Lepton1_FatJet_nCHadrons", nt.FatJet_nCHadrons()[i]);
    }


}

vector<int> Process_1Lepton_GenMatching_daughterindex(int MotherId){
    vector<int> daughter_index;
    for (size_t id=0; id<nt.nGenPart();id++){
        if (nt.GenPart_genPartIdxMother()[id] == MotherId){
            daughter_index.push_back(id);
        }
    }
    return daughter_index;
}

int Process_1Lepton_GenMatching_LastCopy(int PID){
    // isLastCopyBeforeFSR

    int LastCopyID = -99;
    int PGDID = nt.GenPart_pdgId()[PID];
    for (size_t id=0; id<nt.nGenPart();id++){
        if(nt.GenPart_pdgId()[id] == PGDID){
            if (not (nt.GenPart_statusFlags()[id]&(1<<13)) ) continue;
            // if first copy is last copy
            if(id == PID){
                LastCopyID = PID;
                break;
            }
            else{
                int LoopID = id;
                while(nt.GenPart_pdgId()[LoopID] == PGDID){
                    LoopID = nt.GenPart_genPartIdxMother()[LoopID];
                    if(LoopID == PID){
                        LastCopyID = id;
                        break;
                    }
                }
            }
            
        }
    }
    return LastCopyID;
}

int Process_1Lepton_GenMatching_FirstCopy(int PID){
    int FirstCopyID = -99;
    int PGDID = nt.GenPart_pdgId()[PID];
    int LoopID = PID;
    while(nt.GenPart_pdgId()[LoopID] == PGDID){
        
        if((nt.GenPart_statusFlags()[LoopID]&(1<<12))>0){
            FirstCopyID = LoopID;
            break;
        }
        LoopID = nt.GenPart_genPartIdxMother()[LoopID];
    }
    // isFirstCopy does not work for particle : which the daughter and mother both have different PDGID ?
    // isFirstCopy does not work q/g, 
    if(FirstCopyID<0){
        int LoopID = PID;
        while(nt.GenPart_pdgId()[LoopID] == PGDID){
            FirstCopyID = LoopID;
            LoopID = nt.GenPart_genPartIdxMother()[LoopID];
        }
    }
    return FirstCopyID;
}

void Process_1Lepton_GenMatching_Top_wkk(){
    for(size_t ik=0; ik<nt.nGenPart();ik++){// loop on gen

            // 2024-2079
            // before we do not use last copy for tops
        if (nt.GenPart_pdgId()[ik] == 6 ){
                if (not (nt.GenPart_statusFlags()[ik]&(1<<13))) continue; // isLastCopy

                ana.tx.setBranch<float>("gentop_pt", nt.GenPart_pt()[ik]);
                ana.tx.setBranch<float>("gentop_eta", nt.GenPart_eta()[ik]);
                ana.tx.setBranch<float>("gentop_phi", nt.GenPart_phi()[ik]);
                ana.tx.setBranch<float>("gentop_mass", nt.GenPart_p4()[ik].energy());
                
                vector<int> Top_daughter_index;
                Top_daughter_index = Process_1Lepton_GenMatching_daughterindex(ik);
                int NTop_daughter = Top_daughter_index.size();
                if ( NTop_daughter == 2){
                    for (size_t itopd=0; itopd<2;itopd++){ // itopd : short name for id top daughter
                        if(abs(nt.GenPart_pdgId()[Top_daughter_index[itopd]])==24){
                            int LastCopyWid = Process_1Lepton_GenMatching_LastCopy(Top_daughter_index[itopd]);

                            ana.tx.setBranch<float>("gent_w_pt", nt.GenPart_pt()[LastCopyWid]);
                            ana.tx.setBranch<float>("gent_w_eta", nt.GenPart_eta()[LastCopyWid]);
                            ana.tx.setBranch<float>("gent_w_phi", nt.GenPart_phi()[LastCopyWid]);
                            ana.tx.setBranch<float>("gent_w_mass", nt.GenPart_p4()[LastCopyWid].mass());

                            vector<int> Top_W_daughter_index;
                            Top_W_daughter_index = Process_1Lepton_GenMatching_daughterindex(LastCopyWid);
                            int NW_daughter = Top_W_daughter_index.size();
                            if ( NW_daughter == 2){
                                
                                if( abs(nt.GenPart_pdgId()[Top_W_daughter_index[0]])<=6 ) ana.tx.setBranch<int>("gent_w_tag", 4);
                                if( abs(nt.GenPart_pdgId()[Top_W_daughter_index[0]])==11 ||abs(nt.GenPart_pdgId()[Top_W_daughter_index[1]])==12 ) ana.tx.setBranch<int>("gent_w_tag", 1);
                                if( abs(nt.GenPart_pdgId()[Top_W_daughter_index[0]])==12 ||abs(nt.GenPart_pdgId()[Top_W_daughter_index[1]])==13 ) ana.tx.setBranch<int>("gent_w_tag", 2);
                                if( abs(nt.GenPart_pdgId()[Top_W_daughter_index[0]])==14 ||abs(nt.GenPart_pdgId()[Top_W_daughter_index[1]])==15 ) ana.tx.setBranch<int>("gent_w_tag", 3);

                                ana.tx.setBranch<float>("gent_w_q1_pt", nt.GenPart_pt()[Top_W_daughter_index[0]]);
                                ana.tx.setBranch<float>("gent_w_q1_eta", nt.GenPart_eta()[Top_W_daughter_index[0]]);
                                ana.tx.setBranch<float>("gent_w_q1_phi", nt.GenPart_phi()[Top_W_daughter_index[0]]);
                                ana.tx.setBranch<float>("gent_w_q1_e", nt.GenPart_p4()[Top_W_daughter_index[0]].energy());
                                ana.tx.setBranch<int>("gent_w_q1_pdg", nt.GenPart_pdgId()[Top_W_daughter_index[0]]);
                                ana.tx.setBranch<float>("gent_w_q2_pt", nt.GenPart_pt()[Top_W_daughter_index[1]]);
                                ana.tx.setBranch<float>("gent_w_q2_eta", nt.GenPart_eta()[Top_W_daughter_index[1]]);
                                ana.tx.setBranch<float>("gent_w_q2_phi", nt.GenPart_phi()[Top_W_daughter_index[1]]);
                                ana.tx.setBranch<float>("gent_w_q2_e", nt.GenPart_p4()[Top_W_daughter_index[1]].energy());
                                ana.tx.setBranch<int>("gent_w_q2_pdg", nt.GenPart_pdgId()[Top_W_daughter_index[1]]);



                            }
                            
                        }
                        if(abs(nt.GenPart_pdgId()[Top_daughter_index[itopd]])==5){
                            ana.tx.setBranch<float>("gent_b_pt", nt.GenPart_pt()[Top_daughter_index[itopd]]);
                            ana.tx.setBranch<float>("gent_b_eta", nt.GenPart_eta()[Top_daughter_index[itopd]]);
                            ana.tx.setBranch<float>("gent_b_phi", nt.GenPart_phi()[Top_daughter_index[itopd]]);
                            ana.tx.setBranch<float>("gent_b_mass", nt.GenPart_p4()[Top_daughter_index[itopd]].mass());
                        }
                    }
                }
            }

            // 2080-2134
            // before we do not use last copy for tops
        if (nt.GenPart_pdgId()[ik] == -6 ){
                if (not (nt.GenPart_statusFlags()[ik]&(1<<13))) continue; // isLastCopy

                ana.tx.setBranch<float>("genantitop_pt", nt.GenPart_pt()[ik]);
                ana.tx.setBranch<float>("genantitop_eta", nt.GenPart_eta()[ik]);
                ana.tx.setBranch<float>("genantitop_phi", nt.GenPart_phi()[ik]);
                ana.tx.setBranch<float>("genantitop_mass", nt.GenPart_p4()[ik].energy());
                
                vector<int> Top_daughter_index;
                Top_daughter_index = Process_1Lepton_GenMatching_daughterindex(ik);
                int NTop_daughter = Top_daughter_index.size();
                if ( NTop_daughter == 2){
                    for (size_t itopd=0; itopd<2;itopd++){ // itopd : short name for id top daughter
                        if(abs(nt.GenPart_pdgId()[Top_daughter_index[itopd]])==24){
                            int LastCopyWid = Process_1Lepton_GenMatching_LastCopy(Top_daughter_index[itopd]);

                            ana.tx.setBranch<float>("genantit_w_pt", nt.GenPart_pt()[LastCopyWid]);
                            ana.tx.setBranch<float>("genantit_w_eta", nt.GenPart_eta()[LastCopyWid]);
                            ana.tx.setBranch<float>("genantit_w_phi", nt.GenPart_phi()[LastCopyWid]);
                            ana.tx.setBranch<float>("genantit_w_mass", nt.GenPart_p4()[LastCopyWid].mass());

                            vector<int> Top_W_daughter_index;
                            Top_W_daughter_index = Process_1Lepton_GenMatching_daughterindex(LastCopyWid);
                            int NW_daughter = Top_W_daughter_index.size();
                            if ( NW_daughter == 2){
                                
                                if( abs(nt.GenPart_pdgId()[Top_W_daughter_index[0]])<=6 ) ana.tx.setBranch<int>("genantit_w_tag", 4);
                                if( abs(nt.GenPart_pdgId()[Top_W_daughter_index[0]])==11 ||abs(nt.GenPart_pdgId()[Top_W_daughter_index[1]])==12 ) ana.tx.setBranch<int>("genantit_w_tag", 1);
                                if( abs(nt.GenPart_pdgId()[Top_W_daughter_index[0]])==12 ||abs(nt.GenPart_pdgId()[Top_W_daughter_index[1]])==13 ) ana.tx.setBranch<int>("genantit_w_tag", 2);
                                if( abs(nt.GenPart_pdgId()[Top_W_daughter_index[0]])==14 ||abs(nt.GenPart_pdgId()[Top_W_daughter_index[1]])==15 ) ana.tx.setBranch<int>("genantit_w_tag", 3);

                                ana.tx.setBranch<float>("genantit_w_q1_pt", nt.GenPart_pt()[Top_W_daughter_index[0]]);
                                ana.tx.setBranch<float>("genantit_w_q1_eta", nt.GenPart_eta()[Top_W_daughter_index[0]]);
                                ana.tx.setBranch<float>("genantit_w_q1_phi", nt.GenPart_phi()[Top_W_daughter_index[0]]);
                                ana.tx.setBranch<float>("genantit_w_q1_e", nt.GenPart_p4()[Top_W_daughter_index[0]].energy());
                                ana.tx.setBranch<int>("genantit_w_q1_pdg", nt.GenPart_pdgId()[Top_W_daughter_index[0]]);
                                ana.tx.setBranch<float>("genantit_w_q2_pt", nt.GenPart_pt()[Top_W_daughter_index[1]]);
                                ana.tx.setBranch<float>("genantit_w_q2_eta", nt.GenPart_eta()[Top_W_daughter_index[1]]);
                                ana.tx.setBranch<float>("genantit_w_q2_phi", nt.GenPart_phi()[Top_W_daughter_index[1]]);
                                ana.tx.setBranch<float>("genantit_w_q2_e", nt.GenPart_p4()[Top_W_daughter_index[1]].energy());
                                ana.tx.setBranch<int>("genantit_w_q2_pdg", nt.GenPart_pdgId()[Top_W_daughter_index[1]]);



                            }
                            
                        }
                        if(abs(nt.GenPart_pdgId()[Top_daughter_index[itopd]])==5){
                            ana.tx.setBranch<float>("genantit_b_pt", nt.GenPart_pt()[Top_daughter_index[itopd]]);
                            ana.tx.setBranch<float>("genantit_b_eta", nt.GenPart_eta()[Top_daughter_index[itopd]]);
                            ana.tx.setBranch<float>("genantit_b_phi", nt.GenPart_phi()[Top_daughter_index[itopd]]);
                            ana.tx.setBranch<float>("genantit_b_mass", nt.GenPart_p4()[Top_daughter_index[itopd]].mass());
                        }
                    }
                }
            }

            
            // 2138-2257 for wkk
            // have top ?
        if( abs(nt.GenPart_pdgId()[ik])==9000024|| abs(nt.GenPart_pdgId()[ik])==6){
            
                ana.tx.setBranch<float>("havegra", 1);

                if (not (nt.GenPart_statusFlags()[ik]&(1<<13))) continue; // isLastCopy
                ana.tx.setBranch<float>("gen_gra_eta", nt.GenPart_eta()[ik]);
                ana.tx.setBranch<float>("gen_gra_m", nt.GenPart_p4()[ik].mass());
                ana.tx.setBranch<float>("gen_gra_pt", nt.GenPart_pt()[ik]);
                ana.tx.setBranch<float>("gen_gra_phi", nt.GenPart_phi()[ik]);
                vector<int> Wkk_daughter_index;
                Wkk_daughter_index = Process_1Lepton_GenMatching_daughterindex(ik);
                int NWkk_daughter = Wkk_daughter_index.size();
                if ( NWkk_daughter == 2){
                    for (size_t iwkkd=0; iwkkd<2;iwkkd++){
                        if( abs(nt.GenPart_pdgId()[Wkk_daughter_index[iwkkd]]) == 24){
                            int LastCopyWid = Process_1Lepton_GenMatching_LastCopy(Wkk_daughter_index[iwkkd]);
                            vector<int> Wkk_W_daughter_index;
                            Wkk_W_daughter_index = Process_1Lepton_GenMatching_daughterindex(LastCopyWid);
                            int NWkk_W_daughter = Wkk_W_daughter_index.size();
                            if(NWkk_W_daughter==2){
                                if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]])==11 || abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]])==13 || abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]])==15 || abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]])==12 || abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]])==14 || abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]])==16){
                                    // this is only used to store the wkk's w daughter's variable
                                    ana.tx.setBranch<float>("ptGenVlep", nt.GenPart_pt()[LastCopyWid]);
                                    ana.tx.setBranch<float>("etaGenVlep", nt.GenPart_eta()[LastCopyWid]);
                                    ana.tx.setBranch<float>("phiGenVlep", nt.GenPart_phi()[LastCopyWid]);
                                    ana.tx.setBranch<float>("massGenVlep", nt.GenPart_p4()[LastCopyWid].mass());
                                    ana.tx.setBranch<int>("status_1", 0);

                                    for (size_t iwkk_wd=0; iwkk_wd<2;iwkk_wd++){
                                        if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]])==11){
                                            ana.tx.setBranch<float>("gen_ele_pt", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_ele_eta", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_ele_phi", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_ele_e", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                            ana.tx.setBranch<float>("status_1", 1);
                                        }
                                        if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]])==13){
                                            ana.tx.setBranch<float>("gen_mu_pt", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_mu_eta", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_mu_phi", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_mu_e", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                            ana.tx.setBranch<float>("status_1", 2);
                                        }
                                        if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]])==15){
                                            ana.tx.setBranch<float>("gen_tau_pt", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_tau_eta", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_tau_phi", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_tau_e", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                            ana.tx.setBranch<float>("status_1", 3);
                                            int LastCopyW_tauid = Process_1Lepton_GenMatching_LastCopy(Wkk_W_daughter_index[iwkk_wd]);
                                            vector<int> Wkk_W_tau_daughter_index;
                                            Wkk_W_tau_daughter_index = Process_1Lepton_GenMatching_daughterindex(LastCopyW_tauid);
                                            int NWkk_W_tau_daughter = Wkk_W_tau_daughter_index.size();
                                            if(NWkk_W_tau_daughter == 2){
                                                for (size_t iwkk_w_taud=0; iwkk_w_taud<2;iwkk_w_taud++){
                                                    ana.tx.pushbackToBranch<float>("pttau", nt.GenPart_pt()[Wkk_W_tau_daughter_index[iwkk_w_taud]]);
                                                    ana.tx.pushbackToBranch<float>("etatau", nt.GenPart_eta()[Wkk_W_tau_daughter_index[iwkk_w_taud]]);
                                                    ana.tx.pushbackToBranch<float>("phitau", nt.GenPart_phi()[Wkk_W_tau_daughter_index[iwkk_w_taud]]);
                                                    ana.tx.pushbackToBranch<float>("etau", nt.GenPart_p4()[Wkk_W_tau_daughter_index[iwkk_w_taud]].energy());
                                                }
                                            }
                                        }
                                        if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]])==12){
                                            ana.tx.setBranch<float>("gen_nele_pt", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_nele_eta", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_nele_phi", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_nele_e", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                        }
                                        if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]])==14){
                                            ana.tx.setBranch<float>("gen_nmu_pt", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_nmu_eta", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_nmu_phi", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_nmu_e", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                        }
                                        if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]])==16){
                                            ana.tx.setBranch<float>("gen_ntau_pt", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_ntau_eta", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_ntau_phi", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                            ana.tx.setBranch<float>("gen_ntau_e", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                        }
                                    }
                                }
                                for (size_t iwkk_wd=0; iwkk_wd<2;iwkk_wd++){
                                    if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]]) < 6){
                                        ana.tx.setBranch<float>("ptGenVhad", nt.GenPart_pt()[LastCopyWid]);
                                        ana.tx.setBranch<float>("etaGenVhad", nt.GenPart_eta()[LastCopyWid]);
                                        ana.tx.setBranch<float>("phiGenVhad", nt.GenPart_phi()[LastCopyWid]);
                                        ana.tx.setBranch<float>("massGenVhad", nt.GenPart_p4()[LastCopyWid].mass());
                                        ana.tx.setBranch<float>("status_1", 4);
                                        ana.tx.pushbackToBranch<float>("ptq", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                        ana.tx.pushbackToBranch<float>("etaq", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                        ana.tx.pushbackToBranch<float>("phiq", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                        ana.tx.pushbackToBranch<float>("eq", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                        ana.tx.pushbackToBranch<int>("pdgidq", nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]]);
                                    }
                                }
                                // why last copy w's daughter can be w?
                                if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]]) == 24)
                                {
                                    ana.tx.setBranch<float>("status_1", 5);
                                }
                            }
                        }
                    }
                }
            }
            
            // this is for the case, wkk is not stored in lhe, to store the wkk's w
        if( abs(nt.GenPart_pdgId()[ik])==24 && ana.tx.getBranchLazy<int>("havegra") == 1 ){
                if (not (nt.GenPart_statusFlags()[ik]&(1<<12))) continue; // isFirstcopy
                // if the w is no come from the radion
                if(nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[ik]]!=9000025){
                    int LastCopyWid = Process_1Lepton_GenMatching_LastCopy(ik);
                    vector<int> Wkk_W_daughter_index;
                    Wkk_W_daughter_index = Process_1Lepton_GenMatching_daughterindex(LastCopyWid);
                    int NWkk_W_daughter = Wkk_W_daughter_index.size();
                    if(NWkk_W_daughter==2){
                        if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]])==11 || abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]])==13 || abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]])==15 || abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]])==12 || abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]])==14 || abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]])==16){

                            ana.tx.setBranch<float>("ptGenVlep", nt.GenPart_pt()[LastCopyWid]);
                            ana.tx.setBranch<float>("etaGenVlep", nt.GenPart_eta()[LastCopyWid]);
                            ana.tx.setBranch<float>("phiGenVlep", nt.GenPart_phi()[LastCopyWid]);
                            ana.tx.setBranch<float>("massGenVlep", nt.GenPart_p4()[LastCopyWid].mass());
                            ana.tx.setBranch<int>("status_1", 0);

                            for (size_t iwkk_wd=0; iwkk_wd<2;iwkk_wd++){
                                if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]])==11){
                                    ana.tx.setBranch<float>("gen_ele_pt", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_ele_eta", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_ele_phi", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_ele_e", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                    ana.tx.setBranch<float>("status_1", 1);
                                }
                                if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]])==13){
                                    ana.tx.setBranch<float>("gen_mu_pt", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_mu_eta", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_mu_phi", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_mu_e", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                    ana.tx.setBranch<float>("status_1", 2);
                                }
                                if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]])==15){
                                    ana.tx.setBranch<float>("gen_tau_pt", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_tau_eta", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_tau_phi", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_tau_e", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                    ana.tx.setBranch<float>("status_1", 3);
                                    int LastCopyW_tauid = Process_1Lepton_GenMatching_LastCopy(Wkk_W_daughter_index[iwkk_wd]);
                                    vector<int> Wkk_W_tau_daughter_index;
                                    Wkk_W_tau_daughter_index = Process_1Lepton_GenMatching_daughterindex(LastCopyW_tauid);
                                    int NWkk_W_tau_daughter = Wkk_W_tau_daughter_index.size();
                                    if(NWkk_W_tau_daughter == 2){
                                        for (size_t iwkk_w_taud=0; iwkk_w_taud<2;iwkk_w_taud++){
                                            ana.tx.pushbackToBranch<float>("pttau", nt.GenPart_pt()[Wkk_W_tau_daughter_index[iwkk_w_taud]]);
                                            ana.tx.pushbackToBranch<float>("etatau", nt.GenPart_eta()[Wkk_W_tau_daughter_index[iwkk_w_taud]]);
                                            ana.tx.pushbackToBranch<float>("phitau", nt.GenPart_phi()[Wkk_W_tau_daughter_index[iwkk_w_taud]]);
                                            ana.tx.pushbackToBranch<float>("etau", nt.GenPart_p4()[Wkk_W_tau_daughter_index[iwkk_w_taud]].energy());
                                        }
                                    }
                                }
                                if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]])==12){
                                    ana.tx.setBranch<float>("gen_nele_pt", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_nele_eta", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_nele_phi", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_nele_e", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                }
                                if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]])==14){
                                    ana.tx.setBranch<float>("gen_nmu_pt", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_nmu_eta", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_nmu_phi", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_nmu_e", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                }
                                if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]])==16){
                                    ana.tx.setBranch<float>("gen_ntau_pt", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_ntau_eta", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_ntau_phi", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                    ana.tx.setBranch<float>("gen_ntau_e", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                }
                            }
                        }
                        for (size_t iwkk_wd=0; iwkk_wd<2;iwkk_wd++){
                            if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]]) < 6){
                                ana.tx.setBranch<float>("ptGenVhad", nt.GenPart_pt()[LastCopyWid]);
                                ana.tx.setBranch<float>("etaGenVhad", nt.GenPart_eta()[LastCopyWid]);
                                ana.tx.setBranch<float>("phiGenVhad", nt.GenPart_phi()[LastCopyWid]);
                                ana.tx.setBranch<float>("massGenVhad", nt.GenPart_p4()[LastCopyWid].mass());
                                ana.tx.setBranch<float>("status_1", 4);
                                ana.tx.pushbackToBranch<float>("ptq", nt.GenPart_pt()[Wkk_W_daughter_index[iwkk_wd]]);
                                ana.tx.pushbackToBranch<float>("etaq", nt.GenPart_eta()[Wkk_W_daughter_index[iwkk_wd]]);
                                ana.tx.pushbackToBranch<float>("phiq", nt.GenPart_phi()[Wkk_W_daughter_index[iwkk_wd]]);
                                ana.tx.pushbackToBranch<float>("eq", nt.GenPart_p4()[Wkk_W_daughter_index[iwkk_wd]].energy());
                                ana.tx.pushbackToBranch<int>("pdgidq", nt.GenPart_pdgId()[Wkk_W_daughter_index[iwkk_wd]]);
                            }
                        }
                        // why last copy w's daughter can be w?
                        if(abs(nt.GenPart_pdgId()[Wkk_W_daughter_index[0]]) == 24)
                        {
                            ana.tx.setBranch<float>("status_1", 5);
                        }
                    }
                }
            }
            // 2638-2585 radion
        if( abs(nt.GenPart_pdgId()[ik])==9000025 ){
                // no need to check if it's last copy? no other interaction?
                ana.tx.setBranch<float>("gen_rad_m", nt.GenPart_p4()[ik].mass());
                ana.tx.setBranch<float>("gen_rad_pt", nt.GenPart_pt()[ik]);
                ana.tx.setBranch<float>("gen_rad_phi", nt.GenPart_phi()[ik]);
                ana.tx.setBranch<float>("gen_rad_eta", nt.GenPart_eta()[ik]);
                vector<int> Radion_daughter_index;
                Radion_daughter_index = Process_1Lepton_GenMatching_daughterindex(ik);
                int Radion_daughter = Radion_daughter_index.size();
                if(Radion_daughter==2){
                    for (size_t ird=0; ird<2;ird++){
                        if(nt.GenPart_pdgId()[Radion_daughter_index[ird]] == 24){
                            int LastCopyWid = Process_1Lepton_GenMatching_LastCopy(Radion_daughter_index[ird]);
                            vector<int> R_W_daughter_index;
                            R_W_daughter_index = Process_1Lepton_GenMatching_daughterindex(LastCopyWid);
                            int NR_W_daughter = R_W_daughter_index.size();
                            if(NR_W_daughter==2){
                                if(abs(nt.GenPart_pdgId()[R_W_daughter_index[0]])==11 || abs(nt.GenPart_pdgId()[R_W_daughter_index[0]])==13 || abs(nt.GenPart_pdgId()[R_W_daughter_index[0]])==15 || abs(nt.GenPart_pdgId()[R_W_daughter_index[0]])==12 || abs(nt.GenPart_pdgId()[R_W_daughter_index[0]])==14 || abs(nt.GenPart_pdgId()[R_W_daughter_index[0]])==16){
                                    ana.tx.setBranch<float>("ptGenV_2", nt.GenPart_pt()[LastCopyWid]);
                                    ana.tx.setBranch<float>("etaGenV_2", nt.GenPart_eta()[LastCopyWid]);
                                    ana.tx.setBranch<float>("phiGenV_2", nt.GenPart_phi()[LastCopyWid]);
                                    ana.tx.setBranch<float>("massGenV_2", nt.GenPart_p4()[LastCopyWid].mass());
                                    ana.tx.setBranch<float>("status_2", 0);
                                    for (size_t ir_wd=0; ir_wd<2;ir_wd++){
                                        if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]])==11){
                                            ana.tx.setBranch<float>("gen_ele_pt_2", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_ele_eta_2", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_ele_phi_2", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_ele_e_2", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                            ana.tx.setBranch<float>("status_2", 1);
                                        }
                                        if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]])==13){
                                            ana.tx.setBranch<float>("gen_mu_pt_2", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_mu_eta_2", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_mu_phi_2", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_mu_e_2", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                            ana.tx.setBranch<float>("status_2", 2);
                                        }
                                        if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]])==15){
                                            ana.tx.setBranch<float>("gen_tau_pt_2", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_tau_eta_2", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_tau_phi_2", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_tau_e_2", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                            ana.tx.setBranch<float>("status_2", 3);
                                            int LastCopyW_tauid = Process_1Lepton_GenMatching_LastCopy(R_W_daughter_index[ir_wd]);
                                            vector<int> R_W_tau_daughter_index;
                                            R_W_tau_daughter_index = Process_1Lepton_GenMatching_daughterindex(LastCopyW_tauid);
                                            int NR_W_tau_daughter = R_W_tau_daughter_index.size();
                                            if(NR_W_tau_daughter == 2){
                                                for (size_t ir_w_taud=0; ir_w_taud<2;ir_w_taud++){
                                                    ana.tx.pushbackToBranch<float>("pttau_2", nt.GenPart_pt()[R_W_tau_daughter_index[ir_w_taud]]);
                                                    ana.tx.pushbackToBranch<float>("etatau_2", nt.GenPart_eta()[R_W_tau_daughter_index[ir_w_taud]]);
                                                    ana.tx.pushbackToBranch<float>("phitau_2", nt.GenPart_phi()[R_W_tau_daughter_index[ir_w_taud]]);
                                                    ana.tx.pushbackToBranch<float>("etau_2", nt.GenPart_p4()[R_W_tau_daughter_index[ir_w_taud]].energy());
                                                }
                                            }
                                        }
                                        if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]])==12){
                                            ana.tx.setBranch<float>("gen_nele_pt_2", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_nele_eta_2", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_nele_phi_2", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_nele_e_2", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                        }
                                        if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]])==14){
                                            ana.tx.setBranch<float>("gen_nmu_pt_2", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_nmu_eta_2", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_nmu_phi_2", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_nmu_e_2", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                        }
                                        if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]])==16){
                                            ana.tx.setBranch<float>("gen_ntau_pt_2", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_ntau_eta_2", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_ntau_phi_2", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_ntau_e_2", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                        }
                                    }
                                }
                                for (size_t ir_wd=0; ir_wd<2;ir_wd++){
                                    if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]]) < 6){
                                        ana.tx.setBranch<float>("ptGenVhad_2", nt.GenPart_pt()[LastCopyWid]);
                                        ana.tx.setBranch<float>("etaGenVhad_2", nt.GenPart_eta()[LastCopyWid]);
                                        ana.tx.setBranch<float>("phiGenVhad_2", nt.GenPart_phi()[LastCopyWid]);
                                        ana.tx.setBranch<float>("massGenVhad_2", nt.GenPart_p4()[LastCopyWid].mass());
                                        ana.tx.setBranch<float>("status_2", 4);
                                        ana.tx.pushbackToBranch<float>("ptq_2", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                        ana.tx.pushbackToBranch<float>("etaq_2", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                        ana.tx.pushbackToBranch<float>("phiq_2", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                        ana.tx.pushbackToBranch<float>("eq_2", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                        ana.tx.pushbackToBranch<int>("pdgidq_2", nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]]);
                                    }
                                }
                                // why last copy w's daughter can be w?
                                if(abs(nt.GenPart_pdgId()[R_W_daughter_index[0]]) == 24)
                                {
                                    ana.tx.setBranch<float>("status_2", 5);
                                }
                            }
                        }
                        if(nt.GenPart_pdgId()[Radion_daughter_index[ird]] == -24){
                            int LastCopyWid = Process_1Lepton_GenMatching_LastCopy(Radion_daughter_index[ird]);
                            vector<int> R_W_daughter_index;
                            R_W_daughter_index = Process_1Lepton_GenMatching_daughterindex(LastCopyWid);
                            int NR_W_daughter = R_W_daughter_index.size();
                            if(NR_W_daughter==2){
                                if(abs(nt.GenPart_pdgId()[R_W_daughter_index[0]])==11 || abs(nt.GenPart_pdgId()[R_W_daughter_index[0]])==13 || abs(nt.GenPart_pdgId()[R_W_daughter_index[0]])==15 || abs(nt.GenPart_pdgId()[R_W_daughter_index[0]])==12 || abs(nt.GenPart_pdgId()[R_W_daughter_index[0]])==14 || abs(nt.GenPart_pdgId()[R_W_daughter_index[0]])==16){
                                    ana.tx.setBranch<float>("ptGenV_3", nt.GenPart_pt()[LastCopyWid]);
                                    ana.tx.setBranch<float>("etaGenV_3", nt.GenPart_eta()[LastCopyWid]);
                                    ana.tx.setBranch<float>("phiGenV_3", nt.GenPart_phi()[LastCopyWid]);
                                    ana.tx.setBranch<float>("massGenV_3", nt.GenPart_p4()[LastCopyWid].mass());
                                    ana.tx.setBranch<float>("status_3", 0);
                                    for (size_t ir_wd=0; ir_wd<2;ir_wd++){
                                        if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]])==11){
                                            ana.tx.setBranch<float>("gen_ele_pt_3", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_ele_eta_3", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_ele_phi_3", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_ele_e_3", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                            ana.tx.setBranch<float>("status_3", 1);
                                        }
                                        if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]])==13){
                                            ana.tx.setBranch<float>("gen_mu_pt_3", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_mu_eta_3", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_mu_phi_3", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_mu_e_3", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                            ana.tx.setBranch<float>("status_3", 2);
                                        }
                                        if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]])==15){
                                            ana.tx.setBranch<float>("gen_tau_pt_3", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_tau_eta_3", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_tau_phi_3", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_tau_e_3", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                            ana.tx.setBranch<float>("status_3", 3);
                                            int LastCopyW_tauid = Process_1Lepton_GenMatching_LastCopy(R_W_daughter_index[ir_wd]);
                                            vector<int> R_W_tau_daughter_index;
                                            R_W_tau_daughter_index = Process_1Lepton_GenMatching_daughterindex(LastCopyW_tauid);
                                            int NR_W_tau_daughter = R_W_tau_daughter_index.size();
                                            if(NR_W_tau_daughter == 2){
                                                for (size_t ir_w_taud=0; ir_w_taud<2;ir_w_taud++){
                                                    ana.tx.pushbackToBranch<float>("pttau_3", nt.GenPart_pt()[R_W_tau_daughter_index[ir_w_taud]]);
                                                    ana.tx.pushbackToBranch<float>("etatau_3", nt.GenPart_eta()[R_W_tau_daughter_index[ir_w_taud]]);
                                                    ana.tx.pushbackToBranch<float>("phitau_3", nt.GenPart_phi()[R_W_tau_daughter_index[ir_w_taud]]);
                                                    ana.tx.pushbackToBranch<float>("etau_3", nt.GenPart_p4()[R_W_tau_daughter_index[ir_w_taud]].energy());
                                                }
                                            }
                                        }
                                        if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]])==12){
                                            ana.tx.setBranch<float>("gen_nele_pt_3", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_nele_eta_3", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_nele_phi_3", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_nele_e_3", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                        }
                                        if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]])==14){
                                            ana.tx.setBranch<float>("gen_nmu_pt_3", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_nmu_eta_3", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_nmu_phi_3", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_nmu_e_3", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                        }
                                        if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]])==16){
                                            ana.tx.setBranch<float>("gen_ntau_pt_3", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_ntau_eta_3", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_ntau_phi_3", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                            ana.tx.setBranch<float>("gen_ntau_e_3", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                        }
                                    }
                                }
                                for (size_t ir_wd=0; ir_wd<2;ir_wd++){
                                    if(abs(nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]]) < 6){
                                        ana.tx.setBranch<float>("ptGenVhad_3", nt.GenPart_pt()[LastCopyWid]);
                                        ana.tx.setBranch<float>("etaGenVhad_3", nt.GenPart_eta()[LastCopyWid]);
                                        ana.tx.setBranch<float>("phiGenVhad_3", nt.GenPart_phi()[LastCopyWid]);
                                        ana.tx.setBranch<float>("massGenVhad_3", nt.GenPart_p4()[LastCopyWid].mass());
                                        ana.tx.setBranch<float>("status_3", 4);
                                        ana.tx.pushbackToBranch<float>("ptq_3", nt.GenPart_pt()[R_W_daughter_index[ir_wd]]);
                                        ana.tx.pushbackToBranch<float>("etaq_3", nt.GenPart_eta()[R_W_daughter_index[ir_wd]]);
                                        ana.tx.pushbackToBranch<float>("phiq_3", nt.GenPart_phi()[R_W_daughter_index[ir_wd]]);
                                        ana.tx.pushbackToBranch<float>("eq_3", nt.GenPart_p4()[R_W_daughter_index[ir_wd]].energy());
                                        ana.tx.pushbackToBranch<int>("pdgidq_3", nt.GenPart_pdgId()[R_W_daughter_index[ir_wd]]);
                                    }
                                }
                                // why last copy w's daughter can be w?
                                if(abs(nt.GenPart_pdgId()[R_W_daughter_index[0]]) == 24)
                                {
                                    ana.tx.setBranch<float>("status_3", 5);
                                }
                            }
                        }
                    }
                }
            }
    }
}

void Process_1Lepton_GenMatching_W(){
    for(size_t ik=0; ik<nt.nGenPart();ik++){
        if (abs(nt.GenPart_pdgId()[ik]) == 24 )
            {
                if (not (nt.GenPart_statusFlags()[ik]&(1<<13))) continue; // isLastCopy
                // miniAOD check overlap here
                // miniAOD select Gen W pt > 50
                ana.tx.pushbackToBranch<float>("ptgenwl", nt.GenPart_pt()[ik]);
                ana.tx.pushbackToBranch<float>("etagenwl", nt.GenPart_eta()[ik]);
                ana.tx.pushbackToBranch<float>("phigenwl", nt.GenPart_phi()[ik]);
                ana.tx.pushbackToBranch<float>("massgenwl", nt.GenPart_p4()[ik].mass());

                int FirstCopy = Process_1Lepton_GenMatching_FirstCopy(ik);
                ana.tx.pushbackToBranch<float>("ptgenwf", nt.GenPart_pt()[FirstCopy]);
                ana.tx.pushbackToBranch<float>("etagenwf", nt.GenPart_eta()[FirstCopy]);
                ana.tx.pushbackToBranch<float>("phigenwf", nt.GenPart_phi()[FirstCopy]);
                ana.tx.pushbackToBranch<float>("massgenwf", nt.GenPart_p4()[FirstCopy].mass());

                vector<int> W_daughter_index;
                W_daughter_index = Process_1Lepton_GenMatching_daughterindex(ik);
                int NW_daughter = W_daughter_index.size();
                if ( NW_daughter == 2){
                    if( abs(nt.GenPart_pdgId()[W_daughter_index[0]])<=6 ) ana.tx.pushbackToBranch<int>("taggenwl", 4);
                    if( abs(nt.GenPart_pdgId()[W_daughter_index[0]])==11 ||abs(nt.GenPart_pdgId()[W_daughter_index[1]])==12 ) ana.tx.pushbackToBranch<int>("taggenwl", 1);
                    if( abs(nt.GenPart_pdgId()[W_daughter_index[0]])==12 ||abs(nt.GenPart_pdgId()[W_daughter_index[1]])==13 ) ana.tx.pushbackToBranch<int>("taggenwl", 2);
                    if( abs(nt.GenPart_pdgId()[W_daughter_index[0]])==14 ||abs(nt.GenPart_pdgId()[W_daughter_index[1]])==15 ) ana.tx.pushbackToBranch<int>("taggenwl", 3);
                    ana.tx.pushbackToBranch<float>("genw_q1_pt", nt.GenPart_pt()[W_daughter_index[0]]);
                    ana.tx.pushbackToBranch<float>("genw_q1_eta", nt.GenPart_eta()[W_daughter_index[0]]);
                    ana.tx.pushbackToBranch<float>("genw_q1_phi", nt.GenPart_phi()[W_daughter_index[0]]);
                    ana.tx.pushbackToBranch<float>("genw_q1_e", nt.GenPart_p4()[W_daughter_index[0]].energy());
                    ana.tx.pushbackToBranch<int>("genw_q1_pdg", nt.GenPart_pdgId()[W_daughter_index[0]]);
                    ana.tx.pushbackToBranch<float>("genw_q2_pt", nt.GenPart_pt()[W_daughter_index[1]]);
                    ana.tx.pushbackToBranch<float>("genw_q2_eta", nt.GenPart_eta()[W_daughter_index[1]]);
                    ana.tx.pushbackToBranch<float>("genw_q2_phi", nt.GenPart_phi()[W_daughter_index[1]]);
                    ana.tx.pushbackToBranch<float>("genw_q2_e", nt.GenPart_p4()[W_daughter_index[1]].energy());
                    ana.tx.pushbackToBranch<int>("genw_q2_pdg", nt.GenPart_pdgId()[W_daughter_index[1]]);
                }
            }
    }
}

void Process_1Lepton_GenMatching_Z(){
    for(size_t ik=0; ik<nt.nGenPart();ik++){
        if (abs(nt.GenPart_pdgId()[ik]) == 23 )
            {
                if (not (nt.GenPart_statusFlags()[ik]&(1<<13))) continue; // isLastCopy
                // miniAOD check overlap here
                // miniAOD select Gen W pt > 50
                ana.tx.pushbackToBranch<float>("ptgenzl", nt.GenPart_pt()[ik]);
                ana.tx.pushbackToBranch<float>("etagenzl", nt.GenPart_eta()[ik]);
                ana.tx.pushbackToBranch<float>("phigenzl", nt.GenPart_phi()[ik]);
                ana.tx.pushbackToBranch<float>("massgenzl", nt.GenPart_p4()[ik].mass());

                int FirstCopy = Process_1Lepton_GenMatching_FirstCopy(ik);
                ana.tx.pushbackToBranch<float>("ptgenzf", nt.GenPart_pt()[FirstCopy]);
                ana.tx.pushbackToBranch<float>("etagenzf", nt.GenPart_eta()[FirstCopy]);
                ana.tx.pushbackToBranch<float>("phigenzf", nt.GenPart_phi()[FirstCopy]);
                ana.tx.pushbackToBranch<float>("massgenzf", nt.GenPart_p4()[FirstCopy].mass());

                vector<int> Z_daughter_index;
                Z_daughter_index = Process_1Lepton_GenMatching_daughterindex(ik);
                int NW_daughter = Z_daughter_index.size();
                if ( NW_daughter == 2){
                    if( abs(nt.GenPart_pdgId()[Z_daughter_index[0]])<=6 ) ana.tx.pushbackToBranch<int>("taggenzl", 4);
                    if( abs(nt.GenPart_pdgId()[Z_daughter_index[0]])==11 ||abs(nt.GenPart_pdgId()[Z_daughter_index[1]])==12 ) ana.tx.pushbackToBranch<int>("taggenzl", 1);
                    if( abs(nt.GenPart_pdgId()[Z_daughter_index[0]])==12 ||abs(nt.GenPart_pdgId()[Z_daughter_index[1]])==13 ) ana.tx.pushbackToBranch<int>("taggenzl", 2);
                    if( abs(nt.GenPart_pdgId()[Z_daughter_index[0]])==14 ||abs(nt.GenPart_pdgId()[Z_daughter_index[1]])==15 ) ana.tx.pushbackToBranch<int>("taggenzl", 3);
                    // miniAOD do not store the daughter pt

                }
            }
    }
}

void Process_1Lepton_GenMatching_g(){
    for(size_t ik=0; ik<nt.nGenPart();ik++){
        if (abs(nt.GenPart_pdgId()[ik]) == 21 )
            {
                if (not (nt.GenPart_statusFlags()[ik]&(1<<13))) continue; // isLastCopy
                // miniAOD check overlap here
                if( nt.GenPart_pt()[ik] > 50 ){
                    ana.tx.pushbackToBranch<float>("ptgengl", nt.GenPart_pt()[ik]);
                    ana.tx.pushbackToBranch<float>("etagengl", nt.GenPart_eta()[ik]);
                    ana.tx.pushbackToBranch<float>("phigengl", nt.GenPart_phi()[ik]);
                    ana.tx.pushbackToBranch<float>("massgengl", nt.GenPart_p4()[ik].mass());

                    int FirstCopy = Process_1Lepton_GenMatching_FirstCopy(ik);
                    ana.tx.pushbackToBranch<float>("ptgengf", nt.GenPart_pt()[FirstCopy]);
                    ana.tx.pushbackToBranch<float>("etagengf", nt.GenPart_eta()[FirstCopy]);
                    ana.tx.pushbackToBranch<float>("phigengf", nt.GenPart_phi()[FirstCopy]);
                    ana.tx.pushbackToBranch<float>("massgengf", nt.GenPart_p4()[FirstCopy].mass());
                    // miniAOD find mother in a more complex way
                    // cout<<"mothergengf id:"<<nt.GenPart_genPartIdxMother()[FirstCopy]<<endl;// debug
                    // cout<<"first copy id:"<<FirstCopy<<endl;// debug
                    if(nt.GenPart_genPartIdxMother()[FirstCopy]>0){
                        ana.tx.pushbackToBranch<int>("mothergengf", nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[FirstCopy]]);
                    }
                }
            }
    }
}

void Process_1Lepton_GenMatching_q(){
    // 2771-2800 for Gen d
    for(size_t ik=0; ik<nt.nGenPart();ik++){
        if (abs(nt.GenPart_pdgId()[ik]) == 1 )
            {
                if (not (nt.GenPart_statusFlags()[ik]&(1<<13))) continue; // isLastCopy
                // miniAOD check overlap here
                if( nt.GenPart_pt()[ik] > 50 ){
                    int FirstCopy = Process_1Lepton_GenMatching_FirstCopy(ik);
                    
                    if(abs(nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[FirstCopy]]) != 24){ 
                        ana.tx.pushbackToBranch<float>("ptgenq1l", nt.GenPart_pt()[ik]);
                        ana.tx.pushbackToBranch<float>("etagenq1l", nt.GenPart_eta()[ik]);
                        ana.tx.pushbackToBranch<float>("phigenq1l", nt.GenPart_phi()[ik]);
                        ana.tx.pushbackToBranch<float>("massgenq1l", nt.GenPart_p4()[ik].mass());

                        ana.tx.pushbackToBranch<float>("ptgenq1f", nt.GenPart_pt()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("etagenq1f", nt.GenPart_eta()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("phigenq1f", nt.GenPart_phi()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("massgenq1f", nt.GenPart_p4()[FirstCopy].mass());
                        // miniAOD find mother in a more complex way
                        ana.tx.pushbackToBranch<int>("mothergenq1f", nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[FirstCopy]]);
                    }
                }
            }
        if (abs(nt.GenPart_pdgId()[ik]) == 2 ){
                if (not (nt.GenPart_statusFlags()[ik]&(1<<13))) continue; // isLastCopy
                // miniAOD check overlap here
                if( nt.GenPart_pt()[ik] > 50 ){
                    int FirstCopy = Process_1Lepton_GenMatching_FirstCopy(ik);
                    
                    if(abs(nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[FirstCopy]]) != 24){ 
                        ana.tx.pushbackToBranch<float>("ptgenq2l", nt.GenPart_pt()[ik]);
                        ana.tx.pushbackToBranch<float>("etagenq2l", nt.GenPart_eta()[ik]);
                        ana.tx.pushbackToBranch<float>("phigenq2l", nt.GenPart_phi()[ik]);
                        ana.tx.pushbackToBranch<float>("massgenq2l", nt.GenPart_p4()[ik].mass());

                        ana.tx.pushbackToBranch<float>("ptgenq2f", nt.GenPart_pt()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("etagenq2f", nt.GenPart_eta()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("phigenq2f", nt.GenPart_phi()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("massgenq2f", nt.GenPart_p4()[FirstCopy].mass());
                        // miniAOD find mother in a more complex way
                        ana.tx.pushbackToBranch<int>("mothergenq2f", nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[FirstCopy]]);
                    }
                }
        }
        if (abs(nt.GenPart_pdgId()[ik]) == 3 ){
                if (not (nt.GenPart_statusFlags()[ik]&(1<<13))) continue; // isLastCopy
                // miniAOD check overlap here
                if( nt.GenPart_pt()[ik] > 50 ){
                    int FirstCopy = Process_1Lepton_GenMatching_FirstCopy(ik);
                    
                    if(abs(nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[FirstCopy]]) != 24){ 
                        ana.tx.pushbackToBranch<float>("ptgenq3l", nt.GenPart_pt()[ik]);
                        ana.tx.pushbackToBranch<float>("etagenq3l", nt.GenPart_eta()[ik]);
                        ana.tx.pushbackToBranch<float>("phigenq3l", nt.GenPart_phi()[ik]);
                        ana.tx.pushbackToBranch<float>("massgenq3l", nt.GenPart_p4()[ik].mass());

                        ana.tx.pushbackToBranch<float>("ptgenq3f", nt.GenPart_pt()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("etagenq3f", nt.GenPart_eta()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("phigenq3f", nt.GenPart_phi()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("massgenq3f", nt.GenPart_p4()[FirstCopy].mass());
                        // miniAOD find mother in a more complex way
                        ana.tx.pushbackToBranch<int>("mothergenq3f", nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[FirstCopy]]);
                    }
                }
        }
        if (abs(nt.GenPart_pdgId()[ik]) == 4 ){
                if (not (nt.GenPart_statusFlags()[ik]&(1<<13))) continue; // isLastCopy
                // miniAOD check overlap here
                if( nt.GenPart_pt()[ik] > 50 ){
                    int FirstCopy = Process_1Lepton_GenMatching_FirstCopy(ik);
                    
                    if(abs(nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[FirstCopy]]) != 24){ 
                        ana.tx.pushbackToBranch<float>("ptgenq4l", nt.GenPart_pt()[ik]);
                        ana.tx.pushbackToBranch<float>("etagenq4l", nt.GenPart_eta()[ik]);
                        ana.tx.pushbackToBranch<float>("phigenq4l", nt.GenPart_phi()[ik]);
                        ana.tx.pushbackToBranch<float>("massgenq4l", nt.GenPart_p4()[ik].mass());

                        ana.tx.pushbackToBranch<float>("ptgenq4f", nt.GenPart_pt()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("etagenq4f", nt.GenPart_eta()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("phigenq4f", nt.GenPart_phi()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("massgenq4f", nt.GenPart_p4()[FirstCopy].mass());
                        // miniAOD find mother in a more complex way
                        ana.tx.pushbackToBranch<int>("mothergenq4f", nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[FirstCopy]]);
                    }
                }
        }
        if (abs(nt.GenPart_pdgId()[ik]) == 5 ){
                if (not (nt.GenPart_statusFlags()[ik]&(1<<13))) continue; // isLastCopy
                // miniAOD check overlap here
                if( nt.GenPart_pt()[ik] > 50 ){
                    int FirstCopy = Process_1Lepton_GenMatching_FirstCopy(ik);
                    
                    if(abs(nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[FirstCopy]]) != 24){ 
                        ana.tx.pushbackToBranch<float>("ptgenq5l", nt.GenPart_pt()[ik]);
                        ana.tx.pushbackToBranch<float>("etagenq5l", nt.GenPart_eta()[ik]);
                        ana.tx.pushbackToBranch<float>("phigenq5l", nt.GenPart_phi()[ik]);
                        ana.tx.pushbackToBranch<float>("massgenq5l", nt.GenPart_p4()[ik].mass());

                        ana.tx.pushbackToBranch<float>("ptgenq5f", nt.GenPart_pt()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("etagenq5f", nt.GenPart_eta()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("phigenq5f", nt.GenPart_phi()[FirstCopy]);
                        ana.tx.pushbackToBranch<float>("massgenq5f", nt.GenPart_p4()[FirstCopy].mass());
                        // miniAOD find mother in a more complex way
                        ana.tx.pushbackToBranch<int>("mothergenq5f", nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[FirstCopy]]);
                    }
                }
        }
    }
}

void Process_1Lepton_GenMatching(){
    if(not nt.isData()){//MC Info

        Process_1Lepton_GenMatching_Top_wkk();

        Process_1Lepton_GenMatching_W();

        // 2695-2734 for Gen Z

        Process_1Lepton_GenMatching_Z();

        // 2736-2769 for Gen g

        Process_1Lepton_GenMatching_g();

        Process_1Lepton_GenMatching_q();

    }
    
}

void Process_1Lepton_fatJets(){
    // 3251-3538
    
    int usenumber3 = -1; double pt_larger=0;
    for (unsigned int inum = 0; inum < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); ++inum){
        if(nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].pt() > pt_larger && fabs(nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].eta())<2.4 && inum<4) {
            pt_larger = nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].pt(); 
            usenumber3 = ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]; 
            continue;
        }
    }
    if (usenumber3>-1) {
        ana.tx.setBranch<int>("IDLoose", nt.FatJet_jetId()[usenumber3]&2);
        ana.tx.setBranch<float>("jetAK8puppi_dnnTop", nt.FatJet_deepTag_TvsQCD()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnW", nt.FatJet_deepTag_WvsQCD()[usenumber3]);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnH4q", nt.);
        ana.tx.setBranch<float>("jetAK8puppi_dnnZ", nt.FatJet_deepTag_ZvsQCD()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrTop", nt.FatJet_deepTagMD_TvsQCD()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrW", nt.FatJet_deepTagMD_WvsQCD()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrH4q", nt.FatJet_deepTagMD_H4qvsQCD()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrZ", nt.FatJet_deepTagMD_ZvsQCD()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrZbb", nt.FatJet_deepTagMD_ZbbvsQCD()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrHbb", nt.FatJet_deepTagMD_HbbvsQCD()[usenumber3]);
        // we do not have these deep tagger score
        // ana.tx.setBranch<float>("jetAK8puppi_dnnZbb", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnHbb", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnqcd", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnntop", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnw", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnz", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnzbb", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnhbb", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnh4q", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrqcd", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrbb", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrcc", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrbbnog", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrccnog", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrtop", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrw", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrz", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrzbb", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrhbb", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrh4q", nt.);
        ana.tx.setBranch<float>("jetAK8puppi_pt", nt.FatJet_pt()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_eta", nt.FatJet_eta()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_phi", nt.FatJet_phi()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_tau1", nt.FatJet_tau1()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_tau2", nt.FatJet_tau2()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_tau3", nt.FatJet_tau3()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_tau21", nt.FatJet_tau2()[usenumber3]/nt.FatJet_tau1()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_tau4", nt.FatJet_tau4()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_tau42", nt.FatJet_tau2()[usenumber3]/nt.FatJet_tau1()[usenumber3]);
        ana.tx.setBranch<float>("jetAK8puppi_sd", nt.FatJet_msoftdrop()[usenumber3]);
    }

    int usenumber2 = -1; pt_larger=0;
    for (unsigned int inum = 0; inum < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); ++inum){
        if(nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].pt() > pt_larger && fabs(nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].eta())<2.4 && inum<4 && ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum] != usenumber3) {
            pt_larger = nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].pt(); 
            usenumber2 = ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]; 
            continue;
        }
    }
    if (usenumber2>-1) {
        ana.tx.setBranch<int>("IDLoose_2", nt.FatJet_jetId()[usenumber2]&2);
        ana.tx.setBranch<float>("jetAK8puppi_dnnTop_2", nt.FatJet_deepTag_TvsQCD()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnW_2", nt.FatJet_deepTag_WvsQCD()[usenumber2]);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnH4q_2", nt.);
        ana.tx.setBranch<float>("jetAK8puppi_dnnZ_2", nt.FatJet_deepTag_ZvsQCD()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrTop_2", nt.FatJet_deepTagMD_TvsQCD()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrW_2", nt.FatJet_deepTagMD_WvsQCD()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrH4q_2", nt.FatJet_deepTagMD_H4qvsQCD()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrZ_2", nt.FatJet_deepTagMD_ZvsQCD()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrZbb_2", nt.FatJet_deepTagMD_ZbbvsQCD()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrHbb_2", nt.FatJet_deepTagMD_HbbvsQCD()[usenumber2]);
        // we do not have these deep tagger score
        // ana.tx.setBranch<float>("jetAK8puppi_dnnZbb_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnHbb_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnqcd_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnntop_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnw_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnz_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnzbb_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnhbb_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnh4q_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrqcd_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrbb_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrcc_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrbbnog_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrccnog_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrtop_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrw_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrz_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrzbb_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrhbb_2", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrh4q_2", nt.);
        ana.tx.setBranch<float>("jetAK8puppi_pt_2", nt.FatJet_pt()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_eta_2", nt.FatJet_eta()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_phi_2", nt.FatJet_phi()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_tau1_2", nt.FatJet_tau1()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_tau2_2", nt.FatJet_tau2()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_tau3_2", nt.FatJet_tau3()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_tau21_2", nt.FatJet_tau2()[usenumber2]/nt.FatJet_tau1()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_tau4_2", nt.FatJet_tau4()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_tau42_2", nt.FatJet_tau2()[usenumber2]/nt.FatJet_tau1()[usenumber2]);
        ana.tx.setBranch<float>("jetAK8puppi_sd_2", nt.FatJet_msoftdrop()[usenumber2]);
    }
    int usenumber1 = -1; pt_larger=0;
    for (unsigned int inum = 0; inum < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); ++inum){
        if(nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].pt() > pt_larger && fabs(nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].eta())<2.4 && inum<4 && ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum] != usenumber3 && ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum] != usenumber2) {
            pt_larger = nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].pt(); 
            usenumber1 = ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]; 
            continue;
        }
    }
    if (usenumber1>-1) {
        ana.tx.setBranch<int>("IDLoose_3", nt.FatJet_jetId()[usenumber1]&2);
        ana.tx.setBranch<float>("jetAK8puppi_dnnTop_3", nt.FatJet_deepTag_TvsQCD()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnW_3", nt.FatJet_deepTag_WvsQCD()[usenumber1]);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnH4q_3", nt.);
        ana.tx.setBranch<float>("jetAK8puppi_dnnZ_3", nt.FatJet_deepTag_ZvsQCD()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrTop_3", nt.FatJet_deepTagMD_TvsQCD()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrW_3", nt.FatJet_deepTagMD_WvsQCD()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrH4q_3", nt.FatJet_deepTagMD_H4qvsQCD()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrZ_3", nt.FatJet_deepTagMD_ZvsQCD()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrZbb_3", nt.FatJet_deepTagMD_ZbbvsQCD()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrHbb_3", nt.FatJet_deepTagMD_HbbvsQCD()[usenumber1]);
        // we do not have these deep tagger score
        // ana.tx.setBranch<float>("jetAK8puppi_dnnZbb_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnHbb_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnqcd_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnntop_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnw_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnz_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnzbb_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnhbb_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnh4q_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrqcd_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrbb_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrcc_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrbbnog_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrccnog_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrtop_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrw_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrz_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrzbb_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrhbb_3", nt.);
        // ana.tx.setBranch<float>("jetAK8puppi_dnnDecorrh4q_3", nt.);
        ana.tx.setBranch<float>("jetAK8puppi_pt_3", nt.FatJet_pt()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_eta_3", nt.FatJet_eta()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_phi_3", nt.FatJet_phi()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_tau1_3", nt.FatJet_tau1()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_tau2_3", nt.FatJet_tau2()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_tau3_3", nt.FatJet_tau3()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_tau21_3", nt.FatJet_tau2()[usenumber1]/nt.FatJet_tau1()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_tau4_3", nt.FatJet_tau4()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_tau42_3", nt.FatJet_tau2()[usenumber1]/nt.FatJet_tau1()[usenumber1]);
        ana.tx.setBranch<float>("jetAK8puppi_sd_3", nt.FatJet_msoftdrop()[usenumber1]);
    }
}

void Process_1Lepton_Jets(){
    for (unsigned int inum = 0; inum < ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size(); ++inum){
        if( (nt.Jet_pt()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]])>20 && (fabs(nt.Jet_eta()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]]) < 5.0) && (nt.Jet_jetId()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]]&2)>0 && inum<8){
            ana.tx.pushbackToBranch<float>("ak4jet_hf", nt.Jet_hadronFlavour()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]]);
            ana.tx.pushbackToBranch<float>("ak4jet_pf", nt.Jet_partonFlavour()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]]);
            ana.tx.pushbackToBranch<float>("ak4jet_pt", nt.Jet_pt()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]]);
            // ana.tx.pushbackToBranch<float>("ak4jet_pt_uncorr", nt.GenPart_pt[]()[]);
            ana.tx.pushbackToBranch<float>("ak4jet_eta", nt.Jet_eta()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]]);
            ana.tx.pushbackToBranch<float>("ak4jet_phi", nt.Jet_phi()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]]);
            ana.tx.pushbackToBranch<float>("ak4jet_e", nt.Jet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]].energy());
            // ana.tx.pushbackToBranch<float>("ak4jet_csv", nt.()[]);
            ana.tx.pushbackToBranch<float>("ak4jet_icsv", nt.Jet_btagCSVV2()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]]);
            // ana.tx.pushbackToBranch<float>("ak4jet_deepcsvudsg", nt.()[]);
            ana.tx.pushbackToBranch<float>("ak4jet_deepcsvb", nt.Jet_btagDeepB()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]]); // btagDeepB = Var("bDiscriminator('pfDeepCSVJetTags:probb')+bDiscriminator('pfDeepCSVJetTags:probbb')",float,doc="DeepCSV b+bb tag discriminator",precision=10),
            ana.tx.pushbackToBranch<float>("ak4jet_deepcsvc", nt.Jet_btagDeepC()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]]); // btagDeepC = Var("bDiscriminator('pfDeepCSVJetTags:probc')",float,doc="DeepCSV charm btag discriminator",precision=10),
            // ana.tx.pushbackToBranch<float>("ak4jet_deepcsvbb", nt.()[]);
            // ana.tx.pushbackToBranch<float>("ak4jet_deepcsvcc", nt.()[]);
            ana.tx.pushbackToBranch<float>("ak4jet_IDTight", nt.Jet_jetId()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]]&2);
            // ana.tx.pushbackToBranch<float>("ak4jet_IDTight", nt.()[]);
        }
    }
}

void Process_1Lepton_FillBranch(){
    // Proces_1Lepton_NanoAODBranch();
    Process_1Lepton_GenMatching();
    Process_1Lepton_fatJets();
    Process_1Lepton_Jets();
}

void Process_1Lepton_Selection(){
    if (ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size() == 1 && ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() > 0){
        ana.tx.setBranch<int>("1Lepton_Preselection", 1);
    }
    else{
        ana.tx.setBranch<int>("1Lepton_Preselection", 0);
    }


    if (ana.tx.getBranchLazy<int>("1Lepton_Preselection") == 1){
        
        if(ana.write_tree){
            Process_1Lepton_FillBranch();
            ana.tx.fill();
        }
    }
}

void Process_1Lepton(){
    //==============================================
    // Process_1Lep4jet:
    // This function gets called during the event looping.
    // This is where one sets the variables used for the category 1Lep4jet.
    //==============================================

    // Set variables used in this category.
    // If histograms are booked with these variables the histograms will be filled automatically.
    // Please follow the convention of <category>_<varname> structure.

    // Example of reading from Nano
    // std::vector<LorentzVector> electron_p4s = nt.Electron_p4(); // nt is a global variable that accesses NanoAOD
    // std::vector<float> electron_mvaTTH = nt.Electron_mvaTTH(); // electron ttH MVA scores from NanoAOD
    // Semi-complete list of NanoAOD for 102X can be found here: https://cms-nanoaod-integration.web.cern.ch/integration/master-102X/mc102X_doc.html
    // Also consult here: https://github.com/cmstas/NanoTools/blob/d641a6d6c1aa9ecc8094a1af73d5e1bd7d6502ab/NanoCORE/Nano.h#L4875 (if new variables are added they may show up in master)

    Process_1Lepton_Selection();

}

//don't store rootfiles in git - here's how I got the CSV file
void doOneCSV(int year=2016, int period = 0, bool iso = true, bool egamma = false){
  string filename;
  std::ofstream myoutputfile;
  myoutputfile.open("LeptonSF.csv", std::ios_base::app);
  myoutputfile << "PDGid" << "," << "WP" << "," << "year" << "," << "period" << "," << "ptmin" << "," << "ptmax" << "," << "etamin" << "," << "etamax" << ","<< "SF" << "," << "SFerr" << endl;
  if(egamma){
    if(year==2016) filename = "2016LegacyReReco_ElectronMVA90_Fall17V2.root";
    if(year==2017) filename = "2017_ElectronMVA90.root";
    if(year==2018) filename = "2018_ElectronMVA90.root";
    TFile *f = TFile::Open(filename.c_str());
    TH2F *h = (TH2F*)f->Get("EGamma_SF2D");
    //-2.5 ... 2.5 x //10 ... 500 y
    for(unsigned int y = 1; y<=h->GetNbinsY(); ++y){
      for(unsigned int x = 1; x<=h->GetNbinsX(); ++x){
        myoutputfile << 11 << "," << "MVA90" << "," << year << ",X," << h->GetYaxis()->GetBinLowEdge(y) << "," << h->GetYaxis()->GetBinLowEdge(y)+h->GetYaxis()->GetBinWidth(y) << "," << h->GetXaxis()->GetBinLowEdge(x) << "," << h->GetXaxis()->GetBinLowEdge(x)+h->GetXaxis()->GetBinWidth(x) << ","<< h->GetBinContent(x,y) << "," << h->GetBinError(x,y) << endl;
      }
    }
  }
  else {
    string histname;
    if(!iso){
      if(year==2016 && period == 0) { filename = "2016RunBCDEF_SF_ID.root"; histname = "NUM_MediumID_DEN_genTracks_eta_pt"; }//TH2D 2016 //-2.5 ... 2.5 x //20 ... 120 y
      if(year==2016 && period != 0) { filename = "2016RunGH_SF_ID.root";    histname = "NUM_MediumID_DEN_genTracks_eta_pt"; }//TH2D 2016 //-2.5 ... 2.5 x //20 ... 120 y
      if(year==2017) { filename = "2017RunBCDEF_SF_ID.root"; histname = "NUM_MediumID_DEN_genTracks_pt_abseta"; }//TH2D 2017 //20 ... 120 x //0 ... 2.4 y
      if(year==2018) { filename = "2018RunABCD_SF_ID.root"; histname = "NUM_MediumID_DEN_TrackerMuons_pt_abseta"; }//TH2D 2018 //20 ... 120 x //0 ... 2.4 y
    } else {
      if(year==2016 && period == 0) { filename = "2016RunBCDEF_SF_ISO.root"; histname = "NUM_LooseRelIso_DEN_MediumID_eta_pt"; }//TH2D 2016 //-2.5 ... 2.5 x //20 ... 120 y
      if(year==2016 && period != 0) { filename = "2016RunGH_SF_ISO.root";    histname = "NUM_LooseRelIso_DEN_MediumID_eta_pt"; }//TH2D 2016 //-2.5 ... 2.5 x //20 ... 120 y
      if(year==2017) { filename = "2017RunBCDEF_SF_ISO.root"; histname = "NUM_LooseRelIso_DEN_MediumID_pt_abseta"; }//TH2D 2017 //20 ... 120 x //0 ... 2.4 y
      if(year==2018) { filename = "2018RunABCD_SF_ISO.root"; histname = "NUM_LooseRelIso_DEN_MediumID_pt_abseta"; }//TH2D 2018 //20 ... 120 x //0 ... 2.4 y
    }
    string theperiod = "X";
    if(year==2016 && period == 0) theperiod = "BCDEF";
    if(year==2016 && period != 0) theperiod = "GH";
    string WPid = "mediumID";
    if(iso) WPid = "looseIso";
    TFile *f = TFile::Open(filename.c_str());
    TH2D *h = (TH2D*)f->Get(histname.c_str());
    
    if(year==2016){
      for(unsigned int y = 1; y<=h->GetNbinsY(); ++y){
        for(unsigned int x = 1; x<=h->GetNbinsX(); ++x){
          myoutputfile << 13 << "," << WPid << "," << year << "," << theperiod << "," << h->GetYaxis()->GetBinLowEdge(y) << "," << h->GetYaxis()->GetBinLowEdge(y)+h->GetYaxis()->GetBinWidth(y) << "," << h->GetXaxis()->GetBinLowEdge(x) << "," << h->GetXaxis()->GetBinLowEdge(x)+h->GetXaxis()->GetBinWidth(x) << ","<< h->GetBinContent(x,y) << "," << h->GetBinError(x,y) << endl;
        }
      }
    } else {
      for(unsigned int x = 1; x<=h->GetNbinsX(); ++x){
        for(unsigned int y = 1; y<=h->GetNbinsY(); ++y){
          myoutputfile << 13 << "," << WPid << "," << year << "," << theperiod << "," << h->GetXaxis()->GetBinLowEdge(x) << "," << h->GetXaxis()->GetBinLowEdge(x)+h->GetXaxis()->GetBinWidth(x) << "," << h->GetYaxis()->GetBinLowEdge(y) << "," << h->GetYaxis()->GetBinLowEdge(y)+h->GetYaxis()->GetBinWidth(y) << ","<< h->GetBinContent(x,y) << "," << h->GetBinError(x,y) << endl;
        }
      }
    }
  }
  myoutputfile.close();
}
  
void doCSV(){
  doOneCSV(2016, 0,true , true );
  doOneCSV(2017, 0,true , true );
  doOneCSV(2018, 0,true , true );
  doOneCSV(2016, 0,false, false);
  doOneCSV(2016, 1,false, false);
  doOneCSV(2016, 0,true , false);
  doOneCSV(2016, 1,true , false);
  doOneCSV(2017, 0,false, false);
  doOneCSV(2017, 0,true , false);
  doOneCSV(2018, 0,false, false);
  doOneCSV(2018, 0,true , false);

}

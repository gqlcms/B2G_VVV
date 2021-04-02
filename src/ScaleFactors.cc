
#include "ScaleFactors.h"


void RemoveDuplicatesAndSort(std::vector<float> &v)
{
    std::unordered_set<float> s(v.begin(), v.end());
    v.assign(s.begin(), s.end());
    std::sort(v.begin(),v.end());
}


LeptonScaleFactor::LeptonScaleFactor(std::string const& leptonsfpath){
  ifstream file(leptonsfpath.c_str());
  string line = "";
  int counter = 0;
  vector<vector<float> > ptmin, ptmax, etamin, etamax, SF, SFerr;
  vector<float> ptmin_, ptmax_, etamin_, etamax_, SF_, SFerr_;
  vector<string> histname;
  string histname_ = "hSF";
  while(getline(file,line)){
    //std::cout << line << endl;
    if(char(line[0])==char('P')) {
      if(counter>0){
        ptmin.push_back(ptmin_);
        ptmax.push_back(ptmax_);
        etamin.push_back(etamin_);
        etamax.push_back(etamax_);
        SF.push_back(SF_);
        SFerr.push_back(SFerr_);
        histname.push_back(histname_);
        //cout << histname_ << endl;
      }
      ptmin_.clear(); ptmax_.clear(); etamin_.clear(); etamax_.clear(); SF_.clear(); SFerr_.clear();
      histname_ = "hSF";
      ++counter;
      continue;
    }//skip first line
    string _tagger, _theperiod, _theWP, temp;
    //int _theyear;
    int _pdgid,_ptmin,_ptmax;
    float _etamin,_etamax,_cent,_err;
    std::string::iterator end_pos;
    stringstream ss(line);
    getline(ss,temp,',');
    _pdgid = stoi(temp);
    //cout << _pdgid << " histname_ " << histname_ << " " << (histname_.find("_ele") == string::npos) << endl;
    if(abs(_pdgid)==11 && (histname_.find("_ele") == string::npos)) histname_ += "_ele";
    if(abs(_pdgid)==13 && (histname_.find("_muo") == string::npos)) histname_ += "_muo";
    getline(ss,temp,',');
    _theWP = temp;
    end_pos = std::remove(_theWP.begin(), _theWP.end(), ' ');
    _theWP.erase(end_pos, _theWP.end());
    if(histname_.find(_theWP) == string::npos) histname_ += ("_"+_theWP);
    getline(ss,temp,',');
    //_theyear = stoi(temp);
    if(histname_.find(temp) == string::npos) histname_ += ("_"+temp);
    getline(ss,temp,',');
    _theperiod = temp;
    end_pos = std::remove(_theperiod.begin(), _theperiod.end(), ' ');
    _theperiod.erase(end_pos, _theperiod.end());
    if(_theperiod!="X" && histname_.find(_theperiod) == string::npos) histname_ += ("_"+_theperiod);
    getline(ss,temp,',');
    _ptmin = stoi(temp);
    getline(ss,temp,',');
    _ptmax = stoi(temp); 
    getline(ss,temp,',');
    _etamin = stof(temp);
    getline(ss,temp,',');
    _etamax = stof(temp);
    getline(ss,temp,',');
    _cent = stof(temp);
    getline(ss,temp,',');
    _err = stof(temp);
    //cout << _ptmin << " " << _ptmax << " " << _etamin << " " << _etamax << " " << _cent << " " << _err << endl;
    //now push these into appropriately split vectors
    ptmin_.push_back(_ptmin);
    ptmax_.push_back(_ptmax);
    etamin_.push_back(_etamin);
    etamax_.push_back(_etamax);
    SF_.push_back(_cent);
    SFerr_.push_back(_err);
  }
  //last iteration
  ptmin.push_back(ptmin_);
  ptmax.push_back(ptmax_);
  etamin.push_back(etamin_);
  etamax.push_back(etamax_);
  SF.push_back(SF_);
  SFerr.push_back(SFerr_);
  histname.push_back(histname_);
  for(unsigned int i = 0; i<histname.size(); ++i){
    //std::cout << histname[i] << "   " << __LINE__ << std::endl;
    vector<float> ptvec = ptmin[i];    ptvec.push_back( ptmax[i][ ptmax[i].size()-1]);
    vector<float> etavec = etamin[i]; etavec.push_back(etamax[i][etamax[i].size()-1]);
    //for(unsigned int j = 0; j<ptvec.size();  ++j){ cout <<  ptvec[j] << " ";} cout << endl;
    //for(unsigned int j = 0; j<etavec.size(); ++j){ cout << etavec[j] << " ";} cout << endl;
    RemoveDuplicatesAndSort(ptvec);
    RemoveDuplicatesAndSort(etavec);        
    const int nbinspt  =  ptvec.size();
    const int nbinseta = etavec.size();
    double binspt[nbinspt], binseta[nbinseta];
    std::copy(ptvec.begin(),ptvec.end(),binspt);
    std::copy(etavec.begin(),etavec.end(),binseta);
    //for(unsigned int j = 0; j<ptvec.size();  ++j){ cout <<  ptvec[j] << " ";} cout << endl;
    //for(unsigned int j = 0; j<etavec.size(); ++j){ cout << etavec[j] << " ";} cout << endl;
    hSFlep[histname[i] ] = new TH2F(histname[i].c_str(), histname[i].c_str(), nbinspt-1, binspt, nbinseta-1, binseta);
    for(unsigned int j = 0; j<SF[i].size(); ++j){
      int b = hSFlep[histname[i] ]->FindBin(ptmin[i][j]+0.001,etamin[i][j]+0.001);
      hSFlep[histname[i] ]->SetBinContent(b,SF[i][j]);
      hSFlep[histname[i] ]->SetBinError(  b,SFerr[i][j]);
    }
  }
}

      
LeptonScaleFactor::~LeptonScaleFactor(){
  //need to fix this: Segmentation fault (core dumped)
  //for(map<string,TH2F*>::iterator h=hSFlep.begin(); h!=hSFlep.end();++h){
  //  h->second->Delete();
  //}
}
float LeptonScaleFactor::leptonSF(bool isdata, int year, int pdgid, float eta, float pt, long long run, int variation){


  if(isdata) return 1.;
  string period = "";
  if(abs(pdgid)==13&&year==2016){
    std::mt19937_64 randomizeSF(run);
    float randomnumber = float(randomizeSF())/float(randomizeSF.max()-randomizeSF.min());
    if(randomnumber< (19.677260444/35.823438097)) period = "_BCDEF";
    else                                          period = "_GH";
  }
  float myeta = eta;
  if(abs(pdgid)==13&&year!=2016) myeta = abs(myeta);
  string histname = "hSF";
  if(abs(pdgid)==11) histname += "_ele_MVA90";
  else if(abs(pdgid)==13) histname += "_muo_mediumID";
  histname += ("_" + std::to_string(year) + period);
  //std::cout << histname << "   " << __LINE__ << std::endl;
  float SF(1.), SFerr(0.);
  int bin = hSFlep[histname]->FindBin(std::min(hSFlep[histname]->GetXaxis()->GetBinLowEdge(hSFlep[histname]->GetNbinsX()+1)-0.001,std::max(hSFlep[histname]->GetXaxis()->GetBinLowEdge(1)+0.001,double(pt))),std::min(hSFlep[histname]->GetYaxis()->GetBinLowEdge(hSFlep[histname]->GetNbinsY()+1)-0.000001,std::max(hSFlep[histname]->GetYaxis()->GetBinLowEdge(1)+0.000001,double(myeta))));
  SF = hSFlep[histname]->GetBinContent(bin);
  SFerr = hSFlep[histname]->GetBinError(bin);
  if(abs(pdgid)==11){
    if (variation ==  0){
      return SF;
    }
    if (variation ==  1){
      return SF+SFerr;
    }
    if (variation == -1){
      return SF-SFerr;
    }
  }
  float SF2(1.), SF2err(0.);
  string histname2 = histname;
  size_t index = histname2.find(string("mediumID"), index);
  histname2.replace(index, string("mediumID").length(), string("looseIso"));
  bin = hSFlep[histname2]->FindBin(std::min(hSFlep[histname2]->GetXaxis()->GetBinLowEdge(hSFlep[histname2]->GetNbinsX()+1)-0.001,std::max(hSFlep[histname2]->GetXaxis()->GetBinLowEdge(1)+0.001,double(pt))),std::min(hSFlep[histname2]->GetYaxis()->GetBinLowEdge(hSFlep[histname2]->GetNbinsY()+1)-0.000001,std::max(hSFlep[histname2]->GetYaxis()->GetBinLowEdge(1)+0.000001,double(myeta))));
  SF2 = hSFlep[histname2]->GetBinContent(bin);
  SF2err = hSFlep[histname2]->GetBinError(bin);
    if (variation ==  0){
      return SF*SF2;
    }
    if (variation ==  1){
      return SF*SF2+sqrt(pow(SF*SF2err,2)+pow(SF2*SFerr,2));
    }
    if (variation == -1){
      return SF*SF2-sqrt(pow(SF*SF2err,2)+pow(SF2*SFerr,2));
    }
    return SF;

}

//LeptonScaleFactor leptonscalefactors = LeptonScaleFactor();


FatJetScaleFactor::FatJetScaleFactor(std::string const& ak8sfpath){
  ifstream file(ak8sfpath.c_str());
  string line = "";
  vector<vector<float> > ptmin, ptmax,  SF, SFup, SFdown;
  vector<float> ptmin_, ptmax_, SF_, SFup_, SFdown_;
  int previousptmin = -1;
  vector<string> histname;
  string histname_ = "hSF";
  while(getline(file,line)){
    if(char(line[0])==char('D')) continue;
    //std::cout << line << endl;
    string _tagger, _theWP, temp;
    string _theyear, _pdgid;
    int _ptmin,_ptmax;
    float _cent,_up,_down;
    std::string::iterator end_pos;
    stringstream ss(line);
    getline(ss,temp,',');
    _pdgid = temp;
    end_pos = std::remove(_pdgid.begin(), _pdgid.end(), ' ');
    _pdgid.erase(end_pos, _pdgid.end());
    getline(ss,temp,',');
    _theyear = temp;
    end_pos = std::remove(_theyear.begin(), _theyear.end(), ' ');
    _theyear.erase(end_pos, _theyear.end());
    getline(ss,temp,',');
    _tagger = temp;
    end_pos = std::remove(_tagger.begin(), _tagger.end(), ' ');
    _tagger.erase(end_pos, _tagger.end());
    getline(ss,temp,',');
    _theWP = temp;
    end_pos = std::remove(_theWP.begin(), _theWP.end(), ' ');
    _theWP.erase(end_pos, _theWP.end());
    getline(ss,temp,',');
    _ptmin = stoi(temp);
    getline(ss,temp,',');
    _ptmax = stoi(temp); 
    getline(ss,temp,',');
    _cent = stof(temp);
    getline(ss,temp,',');
    _down = stof(temp);
    getline(ss,temp,',');
    _up = stof(temp);
    if (previousptmin>=_ptmin){//next iteration - push everything into main vectors first;
      ptmin.push_back(ptmin_);
      ptmax.push_back(ptmax_);
      SF.push_back(SF_);
      SFdown.push_back(SFdown_);
      SFup.push_back(SFup_);
      histname.push_back(histname_);
      //reset
      histname_ = "hSF";
      ptmin_.clear(); ptmax_.clear(); SF_.clear(); SFdown_.clear(); SFup_.clear();      
    }
    previousptmin = _ptmin;
    ptmin_.push_back(_ptmin);
    ptmax_.push_back(_ptmax);
    SF_.push_back(_cent);
    SFdown_.push_back(_down);
    SFup_.push_back(_up);
    if(histname_.find(_pdgid)   == string::npos) histname_ += ("_"+_pdgid);
    if(histname_.find(_tagger)  == string::npos) histname_ += ("_"+_tagger);
    if(histname_.find(_theWP)   == string::npos) histname_ += ("_"+_theWP);
    if(histname_.find(_theyear) == string::npos) histname_ += ("_"+_theyear);

  }
  //last iteration
  ptmin.push_back(ptmin_);
  ptmax.push_back(ptmax_);
  SF.push_back(SF_);
  SFdown.push_back(SFdown_);
  SFup.push_back(SFup_);
  histname.push_back(histname_);
  for(unsigned int i = 0; i<histname.size(); ++i){
    //std::cout << histname[i] << "   " << __LINE__ << std::endl;
    vector<float> ptvec = ptmin[i];    ptvec.push_back( ptmax[i][ ptmax[i].size()-1]);
    //for(unsigned int j = 0; j<ptvec.size(); ++j) {cout << ptvec[j] << " ";} cout << endl;
    RemoveDuplicatesAndSort(ptvec);
    const int nbinspt  =  ptvec.size();
    double binspt[nbinspt];
    std::copy(ptvec.begin(),ptvec.end(),binspt);
    //for(unsigned int j = 0; j<ptvec.size(); ++j){ cout << ptvec[j] << " ";} cout << endl;
    hSFak8[histname[i] ]         = new TH1F(histname[i].c_str(), histname[i].c_str(), nbinspt-1, binspt);
    hSFak8[histname[i]+"_down" ] = new TH1F((histname[i]+"_down").c_str(), (histname[i]+"_down").c_str(), nbinspt-1, binspt);
    hSFak8[histname[i]+"_up"   ] = new TH1F((histname[i]+"_up"  ).c_str(), (histname[i]+"_up"  ).c_str(), nbinspt-1, binspt);
    for(unsigned int j = 0; j<SF[i].size(); ++j){
      int b = hSFak8[histname[i] ]->FindBin(ptmin[i][j]+0.001);
      hSFak8[histname[i]         ]->SetBinContent(b,SF[i][j]);
      hSFak8[histname[i]+"_down" ]->SetBinContent(b,SF[i][j]-SFdown[i][j]);
      hSFak8[histname[i]+"_up"   ]->SetBinContent(b,SF[i][j]+SFup[i][j]);
    }
  }
}

      
FatJetScaleFactor::~FatJetScaleFactor(){
  //need to fix this: Segmentation fault (core dumped)
  //for(map<string,TH1F*>::iterator h=hSFak8.begin(); h!=hSFak8.end();++h){
  //  h->second->Delete();
  //}
}


float FatJetScaleFactor::ak8SF(bool isdata, int year, int pdgid, bool md, int WP, float eta, float pt, int variation){
  if(isdata) return 1.;
  string histname = "hSF";
  if(abs(pdgid)==6)       histname += "_Top";
  else if(abs(pdgid)==24) histname += "_W";
  if(md) histname += "_MassDecorr";
  else   histname += "_Nominal";
  if(abs(pdgid)==6){
    if(WP==0)       histname += "_2p5";
    else if (WP==1) histname += "_1p0";
    else if (WP==2) histname += "_0p5";
    else            histname += "_0p1";
  }
  else{
    if(WP==0)       histname += "_5p0";
    else if (WP==1) histname += "_2p5";
    else if (WP==2) histname += "_1p0";
    else            histname += "_0p5";
  }
  histname += ("_" + std::to_string(year));
  if(variation==  1) histname += "_up";
  if(variation== -1) histname += "_down";
  float SF(1.);
  int bin = hSFak8[histname]->FindBin(std::min(hSFak8[histname]->GetXaxis()->GetBinLowEdge(hSFak8[histname]->GetNbinsX()+1)-0.001,std::max(hSFak8[histname]->GetXaxis()->GetBinLowEdge(1)+0.001,double(pt)) ) );
  SF = hSFak8[histname]->GetBinContent(bin);
  return SF;
}

//FatJetScaleFactor fatjetscalefactors = FatJetScaleFactor();



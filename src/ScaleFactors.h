#ifndef ScaleFactors_h
#define ScaleFactors_h

#include "rooutil.h"
#include "Nano.h"
#include "math.h"
#include "ScaleFactors.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <random>

class LeptonScaleFactor {

  public:
    LeptonScaleFactor(std::string const& leptonsfpath="src/scalefactors/LeptonSF.csv");
    ~LeptonScaleFactor();
    float leptonSF(bool isdata, int year, int pdgid, float eta, float pt, long long run = -1, int variation=0);

  private:
    std::map<string, TH2F*> hSFlep;
  
};

class FatJetScaleFactor {

  public:
    FatJetScaleFactor(std::string const& ak8sfpath="src/scalefactors/DeepAK8V2_Top_W_SFs.csv");
    ~FatJetScaleFactor();
    float ak8SF(bool isdata, int year, int pdgid, bool md, int WP, float eta, float pt, int variation=0);

  private:
    std::map<string, TH1F*> hSFak8;
  
};

#endif

#ifndef MCTOOLS_H
#define MCTOOLS_H

#include <vector>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TDatabasePDG.h"

#include "Nano.h"

using namespace std;
using namespace tas;

vector<int> GenPart_leptDaughters(int i){ 
    vector<int> lept_daughters;
    for (unsigned int j = 0; j < nGenPart(); j++) {
        if (GenPart_genPartIdxMother().at(j) == i && (abs(GenPart_pdgId().at(j)) >= 11 && abs(GenPart_pdgId().at(j)) <= 18) ){
            lept_daughters.push_back(j);
        }
    }
    return lept_daughters;
}

vector<int> GenPart_daughters(int i){ 
    vector<int> daughters;
    for (unsigned int j = 0; j < nGenPart(); j++) {
        if (GenPart_genPartIdxMother().at(j) == i){
            daughters.push_back(j);
        }
    }
    return daughters;
}

class GenPart {
    public:
      int idx;
      int pdg_id;
      bool is_last;
      bool is_fromHard;
      vector<int> daughters;
      int mother_idx;
      int status;
      float pt;
      float eta;
      float phi;
      float mass;
      GenPart(int idx);
};

GenPart::GenPart(int idx) {
    idx = idx;
    pdg_id = GenPart_pdgId().at(idx);
    is_last = (GenPart_statusFlags().at(idx) & (1<<13)) == (1<<13);
    is_fromHard = (GenPart_statusFlags().at(idx) & (1<<8)) == (1<<8);
    daughters = GenPart_daughters(idx);
    mother_idx = GenPart_genPartIdxMother().at(idx);
    status = GenPart_status().at(idx);
    pt = GenPart_pt().at(idx);
    eta = GenPart_eta().at(idx);
    phi = GenPart_phi().at(idx);
    mass = GenPart_mass().at(idx);
}

bool is_bad_copy(GenPart part) {
    return (part.pdg_id == GenPart_pdgId().at(part.daughters[0]));
}

vector<GenPart> get_GenParticles() {
    vector<GenPart> particles;
    for (unsigned int i = 0; i < nGenPart(); i++) {
        GenPart part(i);
        particles.push_back(part);
    }
        
    // Make Corrections for Bad Copies
    for (size_t i = 0; i < particles.size(); i++) {
        int m_id = particles[i].mother_idx;
        if (m_id >= 0){
            if (is_bad_copy(particles[m_id])){
                particles[i].mother_idx = particles[m_id].mother_idx;                    
                for (size_t j = 0; j < particles[m_id].daughters.size(); j++){
                    particles[particles[m_id].mother_idx].daughters.push_back(particles[m_id].daughters[j]);
                }
            }            
        }
    }
    return particles;
}

//Parentage functions
int dumpDocLines();
bool isFromSUSY(int id, int idx);
bool isFromW(int id, int idx);
bool isFromZ(int id, int idx);
bool isFromTau(int id, int idx);
bool isFromB(int id, int idx);
bool isFromC(int id, int idx);
bool isFromLight(int id, int idx);
bool isFromLightFake(int id, int idx);
bool idIsCharm(int id);
bool idIsBeauty(int id);


// sourceId to match CERN/ETH
int getSourceId(int genpIdx);
bool useSourceId(int sourceId);
bool terminateSourceId(int motherId);
bool terminateMotherId(int motherId);

// top pt reweighting
float topPtWeight(float pt_top, float pt_tbar);
float topPtWeightCutoff(float pt_top, float pt_tbar);
// 2016 ISR recipe
int getNISRMatch ( const std::vector<LorentzVector>& clean_jets );
float getISRWeight ( int nisrMatch );
float getISRUncertainty ( int nisrMatch );
float getISRWeight ( int nisrMatch, int year );
float getISRUncertainty ( int nisrMatch, int year );
// Moriond 2017 ISR recipe for ewkino models
float getISRWeightEWkino ( float isr_pt );

#endif

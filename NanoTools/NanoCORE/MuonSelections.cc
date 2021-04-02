#include "MuonSelections.h"
#include "IsolationTools.h"

using namespace tas;

bool SS::muonID(unsigned int idx, SS::IDLevel id_level, int year) {
    // Common checks
    if (Muon_pt().at(idx) < 10.) { return false; }
    if (fabs(Muon_eta().at(idx)) > 2.4) { return false; }
    if (fabs(Muon_dxy().at(idx)) > 0.05) { return false; }
    if (fabs(Muon_dz().at(idx)) > 0.1) { return false; }
    if (fabs(Muon_sip3d().at(idx)) >= 4) { return false; }
    if (!Muon_looseId().at(idx)) { return false; }
    if (Muon_ptErr().at(idx) / Muon_pt().at(idx) >= 0.2) { return false; }
    if (!Muon_mediumId().at(idx)) { return false; }
    switch (year) {
    case (2016):
        return muon2016ID(idx, id_level);
        break;
    case (2017):
        return muon2017ID(idx, id_level);
        break;
    case (2018):
        return muon2018ID(idx, id_level);
        break;
    default:
        throw std::runtime_error("MuonSelections.cc: ERROR - invalid year");
        return false;
        break;
    }
}

bool SS::muon2016ID(unsigned int idx, SS::IDLevel id_level) {
    // ID-specific checks
    switch (id_level) {
    case (SS::IDveto):
        return true;
        break;
    case (SS::IDfakable):
        if (Muon_miniPFRelIso_all().at(idx) > 0.4) { return false; }
        return true;
        break;
    case (SS::IDtight):
        if (!passesLeptonIso(idx, 13, 0.16, 0.76, 7.2)) { return false; }
        return true;
        break;
    default:
        throw std::runtime_error("MuonSelections.cc: ERROR - invalid ID level");
        return false;
        break;
    }
    return false;
}

bool SS::muon2017ID(unsigned int idx, SS::IDLevel id_level) {
    // ID-specific checks
    switch (id_level) {
    case (SS::IDveto):
        return true;
        break;
    case (SS::IDfakable):
        if (Muon_miniPFRelIso_all().at(idx) > 0.4) { return false; }
        return true;
        break;
    case (SS::IDtight):
        if (!passesLeptonIso(idx, 13, 0.11, 0.74, 6.8)) { return false; }
        return true;
        break;
    default:
        throw std::runtime_error("MuonSelections.cc: ERROR - invalid ID level");
        return false;
        break;
    }
    return false;
}

bool SS::muon2018ID(unsigned int idx, SS::IDLevel id_level) {
    // ID-specific checks
    switch (id_level) {
    case (SS::IDveto):
        return true;
        break;
    case (SS::IDfakable):
        // Same as 2017 ID
        if (Muon_miniPFRelIso_all().at(idx) > 0.4) { return false; }
        return true;
        break;
    case (SS::IDtight):
        // Same as 2017 ID
        if (!passesLeptonIso(idx, 13, 0.11, 0.74, 6.8)) { return false; }
        return true;
        break;
    default:
        throw std::runtime_error("MuonSelections.cc: ERROR - invalid ID level");
        return false;
        break;
    }
    return false;
}

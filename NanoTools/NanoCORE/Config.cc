#include "Config.h"
#include <iostream>

GlobalConfig gconf;

void GlobalConfig::GetConfigsFromDatasetName(std::string dsname) {
    // bool isData = dsname.Contains("Run201") || dsname.Contains("run2_data");

    if (dsname.find("Run2016") != std::string::npos || dsname.find("RunIISummer16") != std::string::npos ||
        dsname.find("_2016/") != std::string::npos)
        year = 2016;
    if (dsname.find("Run2017") != std::string::npos || dsname.find("RunIIFall17") != std::string::npos ||
        dsname.find("_2017/") != std::string::npos)
        year = 2017;
    if (dsname.find("Run2018") != std::string::npos || dsname.find("RunIIAutumn18") != std::string::npos ||
        dsname.find("_2018/") != std::string::npos)
        year = 2018;

    GetConfigs();
    GetSampleType(dsname);

    std::cout << ">>> ------------ GlobalConfig ------------" << std::endl;
    if (year <= 0) {
        std::cout << ">>> [!] Couldn't figure out year, so setting it to 2017. Make sure this is what you want!"
                  << std::endl;
        year = 2017;
    } else {
        std::cout << ">>> Figured out that the year is " << year << "." << std::endl;
    }
    std::cout << ">>> Running sample as " << ((is_data) ? "data" : "MC with samptype as " + samptype) << "."
              << std::endl;
    std::cout << ">>> --------------------------------------" << std::endl;
}

void GlobalConfig::GetSampleType(std::string dsname) {

    if (dsname.find("data") != std::string::npos || dsname.find("/DoubleMuon") != std::string::npos ||
        dsname.find("/DoubleEG") != std::string::npos || dsname.find("/MuonEG") != std::string::npos ||
        dsname.find("/EGamma") != std::string::npos || dsname.find("/SingleMuon") != std::string::npos ||
        dsname.find("/SingleElectron") != std::string::npos || dsname.find("/SinglePhoton") != std::string::npos)
        is_data = true;

    if (is_data)
        samptype = dsname;
    else if (dsname.find("TTJets") != std::string::npos)
        samptype = "ttbar";
    else if (dsname.find("ST_") != std::string::npos)
        samptype = "singletop";
    else if (dsname.find("TTW") != std::string::npos)
        samptype = "ttW";
    else if (dsname.find("TTZ") != std::string::npos)
        samptype = "ttZ";
    else if (dsname.find("DYJets") != std::string::npos)
        samptype = "DY";
    else if (dsname.find("Jets") != std::string::npos)
        samptype = "Wjets";
    else if (dsname.find("WZ") != std::string::npos)
        samptype = "WZ";
    else if (dsname.find("ZZ") != std::string::npos)
        samptype = "ZZ";
    else if (dsname.find("ggH") != std::string::npos)
        samptype = "ggH";
    else if (dsname.find("VBF") != std::string::npos)
        samptype = "VBF";
    else
        std::cout << ">>> Cannot assigned sampletype for " << dsname << std::endl;

    if (verbose) {
        std::cout << ">>> The assigned sampletype based on " << dsname << " is " << samptype << ". And it is "
                  << ((is_data) ? "data." : "MC.") << std::endl;
    }
}

void GlobalConfig::GetConfigs(int in_year) {
    if (in_year > 0) year = in_year;
    if (year < 2016 || year > 2018) {
        std::cout << ">>> Cannot configure for year " << year << "!! Values remain unset!" << std::endl;
        return;
    }

    if (year == 2016 && nanoAOD_ver < 0) {
        lumi = 35.922;

        jecEraB = jecEraC = jecEraD = "Summer16_23Sep2016BCDV4_DATA";
        jecEraE = jecEraF = "Summer16_23Sep2016EFV4_DATA";
        jecEraG = "Summer16_23Sep2016GV4_DATA";
        jecEraH = "Summer16_23Sep2016HV4_DATA";
        jecEraMC = "Summer16_23Sep2016V4_MC";

        // B-tag working points
        // https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation80XReReco
        // Data: 23Sep2016 ReReco for B-G datasets
        // Monte Carlo: RunIISummer16 for Fullsim and Spring16 for Fastsim
        WP_DeepFlav_tight = 0.7221;
        WP_DeepFlav_medium = 0.3093;
        WP_DeepFlav_loose = 0.0614;
        fn_btagSF_DeepFlav = "DeepJet_2016LegacySF_WP_V1.csv";

        WP_DeepCSV_tight = 0.8958;
        WP_DeepCSV_medium = 0.6324;
        WP_DeepCSV_loose = 0.2219;
        fn_btagSF_DeepCSV = "DeepCSV_Moriond17_B_H.csv";

        WP_CSVv2_tight = 0.9535;
        WP_CSVv2_medium = 0.8484;
        WP_CSVv2_loose = 0.5426;
        fn_btagSF_CSVv2 = "CSVv2_Moriond17_B_H.csv";
    }
    if (year == 2016 && nanoAOD_ver >= 0) {
        lumi = 35.922;

        jecEraB = jecEraC = jecEraD = "Summer16_07Aug2017BCD_V11_DATA";
        jecEraE = jecEraF = "Summer16_07Aug2017EF_V11_DATA";
        jecEraG = jecEraH = "Summer16_07Aug2017GH_V11_DATA";
        jecEraMC = "Summer16_07Aug2017_V11_MC";

        // B-tag working points
        // 94X WPs shall be very close to those in 80X, if not the same
        WP_DeepFlav_tight = 0.7221;
        WP_DeepFlav_medium = 0.3093;
        WP_DeepFlav_loose = 0.0614;
        fn_btagSF_DeepFlav = "DeepJet_2016LegacySF_WP_V1.csv";

        WP_DeepCSV_tight = 0.8953;
        WP_DeepCSV_medium = 0.6321;
        WP_DeepCSV_loose = 0.2217;
        fn_btagSF_DeepCSV = "DeepCSV_2016LegacySF_WP_V1.csv";

        WP_CSVv2_tight = 0.9535;
        WP_CSVv2_medium = 0.8484;
        WP_CSVv2_loose = 0.5426;
        fn_btagSF_CSVv2 = "CSVv2_Moriond17_B_H.csv"; // not supported
    } else if (year == 2017) {
        lumi = 41.529;

        jecEraB = "Fall17_17Nov2017B_V32_DATA";
        jecEraC = "Fall17_17Nov2017C_V32_DATA";
        jecEraD = jecEraE = "Fall17_17Nov2017DE_V32_DATA";
        jecEraF = "Fall17_17Nov2017F_V32_DATA";
        // if (dsname.find("09May2018") != std::string::npos) jecEraF = "Fall17_09May2018F_V3_DATA"
        jecEraMC = "Fall17_17Nov2017_V32_MC";

        // B-tag working points
        // https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation94X
        // Data: 17Nov2017 ReReco for B-F dataset
        // Monte Carlo: RunIIFall17

        WP_DeepFlav_tight = 0.7489;
        WP_DeepFlav_medium = 0.3033;
        WP_DeepFlav_loose = 0.0521;
        fn_btagSF_DeepFlav = "DeepJet_94XSF_WP_V3_B_F.csv";

        WP_DeepCSV_tight = 0.8001;
        WP_DeepCSV_medium = 0.4941;
        WP_DeepCSV_loose = 0.1522;
        fn_btagSF_DeepCSV = "DeepCSV_94XSF_WP_V4_B_F.csv";

        WP_CSVv2_tight = 0.9693;
        WP_CSVv2_medium = 0.8838;
        WP_CSVv2_loose = 0.5803;
        fn_btagSF_CSVv2 = "CSVv2_94XSF_V2_B_F.csv";
    } else if (year == 2018) {
        lumi = 59.97;

        jecEraA = "Autumn18_RunA_V8_DATA";
        jecEraB = "Autumn18_RunB_V8_DATA";
        jecEraC = "Autumn18_RunC_V8_DATA";
        jecEraD = "Autumn18_RunD_V8_DATA";
        jecEraMC = "Autumn18_V8_MC";

        // B-tag working points
        // https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation102X
        // pfDeepFlavourJetTags:probb + probbb + problepb
        WP_DeepFlav_tight = 0.7264;
        WP_DeepFlav_medium = 0.2770;
        WP_DeepFlav_loose = 0.0494;
        fn_btagSF_DeepFlav = "DeepJet_102XSF_WP_V1.csv";

        WP_DeepCSV_tight = 0.7527;
        WP_DeepCSV_medium = 0.4184;
        WP_DeepCSV_loose = 0.1241;
        fn_btagSF_DeepCSV = "DeepCSV_102XSF_WP_V1.csv";

        WP_CSVv2_tight = 0.9693; // CSVv2 is no longer supported for 2018
        WP_CSVv2_medium = 0.8838;
        WP_CSVv2_loose = 0.5803;
        fn_btagSF_CSVv2 = "CSVv2_94XSF_V2_B_F.csv"; // not supported
    } else {
        std::cout << ">>> Cannot configure for year " << year << "!! Values remain unset!" << std::endl;
        return;
    }
}

#!/bin/bash

if [ -z $1 ]; then
    echo ""
    echo "==  Template Begin/Process/Termiate_MyAnalysis.cc/h creator  =="
    echo ""
    echo "Usage:"
    echo "   > $0 MyAnalysis"
    echo ""
    echo "  The above command will create 6 files"
    echo ""
    echo "    Begin_MyAnalysis.cc      (Where you declare variables, histograms, cut selections.)"
    echo "    Begin_MyAnalysis.h"
    echo "    Process_MyAnalysis.cc    (Where you compute variables.)"
    echo "    Process_MyAnalysis.h"
    echo "    Terminate_MyAnalysis.cc  (Where you do things after the event loop is done.)"
    echo "    Terminate_MyAnalysis.h"
    echo ""
    echo "  NOTE: Once the template is created, each user is responsible plugging them into the master Begin.cc/h Process.cc/h and Terminate.cc/h"
    echo ""
    echo 
    exit
fi

VAR=_$1

echo $VAR
echo -e "#include \"Begin${VAR}.h\"\n\nvoid Begin${VAR}()\n{\n    //==============================================\n    // Begin${VAR}:\n    // This function gets called prior to the event looping.\n    // This is where one declares variables, histograms, event selections for the category ${VAR/_/}.\n    //==============================================\n\n    // Create variables used in this category.\n    // Please follow the convention of <category>_<varname> structure.\n    ana.tx.createBranch<int>(\"${VAR/_/}_intVar1\");\n    ana.tx.createBranch<float>(\"${VAR/_/}_floatVar1\");\n    ana.tx.createBranch<LorentzVector>(\"${VAR/_/}_LVVar1\");\n\n    // Define selections\n    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.\n    ana.cutflow.getCut(\"CommonCut\");\n    ana.cutflow.addCutToLastActiveCut(\"Cut_${VAR/_/}_Preselection\", [&]() { return ana.tx.getBranch<LorentzVector>(\"${VAR/_/}_LVVar1\").pt() > 25.;}, [&]() { return ana.tx.getBranch<float>(\"${VAR/_/}_floatVar1\"); } );\n\n    // Create histograms used in this category.\n    // Please follow the convention of h_<category>_<varname> structure.\n    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.\n    RooUtil::Histograms hists_${VAR/_/};\n    hists_${VAR/_/}.addHistogram(\"h_${VAR/_/}_intVar1\", 10, 0, 10, [&]() { return ana.tx.getBranch<int>(\"${VAR/_/}_intVar1\"); } );\n    hists_${VAR/_/}.addHistogram(\"h_${VAR/_/}_floatVar1\", 180, 0, 500, [&]() { return ana.tx.getBranch<float>(\"${VAR/_/}_floatVar1\"); } );\n    hists_${VAR/_/}.addHistogram(\"h_${VAR/_/}_LVVar1_Pt\", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>(\"${VAR/_/}_LVVar1\").pt(); } );\n\n    // Now book cutflow histogram (could be commented out if user does not want.)\n    // N.B. Cutflow histogramming can be CPU consuming.\n    ana.cutflow.bookCutflows();\n\n    // Book histograms to cuts that user wants for this category.\n    ana.cutflow.bookHistogramsForCut(hists_${VAR/_/}, \"Cut_${VAR/_/}_Preselection\");\n}" > Begin${VAR}.cc
echo -e "#include \"Process${VAR}.h\"\n\nvoid Process${VAR}()\n{\n    //==============================================\n    // Process${VAR}:\n    // This function gets called during the event looping.\n    // This is where one sets the variables used for the category ${VAR/_/}.\n    //==============================================\n\n    // Set variables used in this category.\n    // If histograms are booked with these variables the histograms will be filled automatically.\n    // Please follow the convention of <category>_<varname> structure.\n    ana.tx.setBranch<int>(\"${VAR/_/}_intVar1\", -999);\n    ana.tx.setBranch<float>(\"${VAR/_/}_floatVar1\", -999);\n\n    // Example of reading from Nano\n    // std::vector<LorentzVector> electron_p4s = nt.Electron_p4(); // nt is a global variable that accesses NanoAOD\n    // std::vector<float> electron_mvaTTH = nt.Electron_mvaTTH(); // electron ttH MVA scores from NanoAOD\n    // Semi-complete list of NanoAOD for 102X can be found here: https://cms-nanoaod-integration.web.cern.ch/integration/master-102X/mc102X_doc.html\n    // Also consult here: https://github.com/cmstas/NanoTools/blob/d641a6d6c1aa9ecc8094a1af73d5e1bd7d6502ab/NanoCORE/Nano.h#L4875 (if new variables are added they may show up in master)\n\n    LorentzVector LV_${VAR/_/}_LVVar1 = RooUtil::Calc::getLV(34.5, 1.2, 3.123, 0.105); // RooUtil::Calc::getLV() creates 4 vector\n\n    ana.tx.setBranch<LorentzVector>(\"${VAR/_/}_LVVar1\", LV_${VAR/_/}_LVVar1);\n}" > Process${VAR}.cc
echo -e "#include \"Terminate${VAR}.h\"\n\nvoid Terminate${VAR}()\n{\n    //==============================================\n    // Terminate${VAR}:\n    // This function gets called after the event looping.\n    // This is where one does stuff that needs to happen after the event looping for category ${VAR/_/}.\n    //==============================================\n\n    // To place eventlist writing or something that needs to happen post loop.\n    // TODO: implement event list writing\n}" > Terminate${VAR}.cc
echo -e "#ifndef Begin${VAR}_h\n#define Begin${VAR}_h\n\n#include \"AnalysisConfig.h\"\n\nvoid Begin${VAR}();\n\n#endif" > Begin${VAR}.h
echo -e "#ifndef Process${VAR}_h\n#define Process${VAR}_h\n\n#include \"AnalysisConfig.h\"\n\nvoid Process${VAR}();\n\n#endif" > Process${VAR}.h
echo -e "#ifndef Terminate${VAR}_h\n#define Terminate${VAR}_h\n\n#include \"AnalysisConfig.h\"\n\nvoid Terminate${VAR}();\n\n#endif" > Terminate${VAR}.h


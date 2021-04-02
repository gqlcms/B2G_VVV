#include "main.h"

// ./process INPUTFILEPATH OUTPUTFILE [NEVENTS]
int main(int argc, char** argv)
{

//********************************************************************************
//
// 1. Parsing options
//
//********************************************************************************

    // cxxopts is just a tool to parse argc, and argv easily

    // Grand option setting
    cxxopts::Options options("\n  $ doAnalysis",  "\n         **********************\n         *                    *\n         *       Looper       *\n         *                    *\n         **********************\n");

    // Read the options
    options.add_options()
        ("m,mode"        , "Looper mode (--mode 0=0Lepton, 1=1Lepton)", cxxopts::value<int>())
        ("i,input"       , "Comma separated input file list OR if just a directory is provided it will glob all in the directory BUT must end with '/' for the path", cxxopts::value<std::string>())
        ("t,tree"        , "Name of the tree in the root file to open and loop over"                                             , cxxopts::value<std::string>())
        ("o,output"      , "Output file name"                                                                                    , cxxopts::value<std::string>())
        ("n,nevents"     , "N events to loop over"                                                                               , cxxopts::value<int>()->default_value("-1"))
        ("j,nsplit_jobs" , "Enable splitting jobs by N blocks (--job_index must be set)"                                         , cxxopts::value<int>())
        ("I,job_index"   , "job_index of split jobs (--nsplit_jobs must be set. index starts from 0. i.e. 0, 1, 2, 3, etc...)"   , cxxopts::value<int>())
        ("d,debug"       , "Run debug job. i.e. overrides output option to 'debug.root' and 'recreate's the file.")
        ("w,write"       , "Write skim tree.")
        ("V,VVVTree"     , "Input is VVVTree type.")
        ("r,region"      , "Region"                                                                                              , cxxopts::value<int>())
        ("s,vhvvv"       , "Selecting VH->VVV channel"                                                                           , cxxopts::value<int>())
        ("e,eftidx"      , "EFT reweighting index"                                                                               , cxxopts::value<int>())
        ("h,help"        , "Print help")
        ;

    auto result = options.parse(argc, argv);

    // NOTE: When an option was provided (e.g. -i or --input), then the result.count("<option name>") is more than 0
    // Therefore, the option can be parsed easily by asking the condition if (result.count("<option name>");
    // That's how the several options are parsed below

    //_______________________________________________________________________________
    // --help
    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --mode
    if (result.count("mode"))
    {
        switch (result["mode"].as<int>())
        {
            case AnalysisConfig::k0Lepton: ana.looperMode = AnalysisConfig::k0Lepton; break;
            case AnalysisConfig::k1Lepton: ana.looperMode = AnalysisConfig::k1Lepton; break;
            
        }
    }
    else
    {
        std::cout << options.help() << std::endl;
        std::cout << "ERROR: Looper mode is not provided! Check your arguments" << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --region
    if (result.count("region"))
    {
        ana.region = result["region"].as<int>();
    }
    else
    {
        ana.region = 0;
    }

    //_______________________________________________________________________________
    // --vhvvv
    if (result.count("vhvvv"))
    {
        ana.vhvvv_channel = result["vhvvv"].as<int>();
    }
    else
    {
        ana.vhvvv_channel = -999;
    }

    //_______________________________________________________________________________
    // --eftidx
    if (result.count("eftidx"))
    {
        ana.eft_reweighting_idx = result["eftidx"].as<int>();
    }
    else
    {
        ana.eft_reweighting_idx = 0;
    }

    //_______________________________________________________________________________
    // --input
    if (result.count("input"))
    {
        ana.input_file_list_tstring = result["input"].as<std::string>();
    }
    else
    {
        std::cout << options.help() << std::endl;
        std::cout << "ERROR: Input list is not provided! Check your arguments" << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --tree
    if (result.count("tree"))
    {
        ana.input_tree_name = result["tree"].as<std::string>();
    }
    else
    {
        std::cout << options.help() << std::endl;
        std::cout << "ERROR: Input tree name is not provided! Check your arguments" << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --debug
    if (result.count("debug"))
    {
        ana.output_tfile = new TFile("debug.root", "recreate");
    }
    else
    {
        //_______________________________________________________________________________
        // --output
        if (result.count("output"))
        {
            ana.output_tfile = new TFile(result["output"].as<std::string>().c_str(), "create");
            if (not ana.output_tfile->IsOpen())
            {
                std::cout << options.help() << std::endl;
                std::cout << "ERROR: output already exists! provide new output name or delete old file. OUTPUTFILE=" << result["output"].as<std::string>() << std::endl;
                exit(1);
            }
        }
        else
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: Output file name is not provided! Check your arguments" << std::endl;
            exit(1);
        }
    }

    //_______________________________________________________________________________
    // --write
    if (result.count("write"))
    {
        ana.write_tree = true;
    }
    else
    {
        ana.write_tree = false;
    }

    //_______________________________________________________________________________
    // --VVVTree
    if (result.count("VVVTree"))
    {
        ana.run_VVVTree = true;
    }
    else
    {
        ana.run_VVVTree = false;
    }

    //_______________________________________________________________________________
    // --nevents
    ana.n_events = result["nevents"].as<int>();

    //_______________________________________________________________________________
    // --nsplit_jobs
    if (result.count("nsplit_jobs"))
    {
        ana.nsplit_jobs = result["nsplit_jobs"].as<int>();
        if (ana.nsplit_jobs <= 0)
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --nsplit_jobs" << ana.nsplit_jobs << " has zero or negative value!" << std::endl;
            std::cout << "I am not sure what this means..." << std::endl;
            exit(1);
        }
    }
    else
    {
        ana.nsplit_jobs = -1;
    }

    //_______________________________________________________________________________
    // --nsplit_jobs
    if (result.count("job_index"))
    {
        ana.job_index = result["job_index"].as<int>();
        if (ana.job_index < 0)
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --job_index" << ana.job_index << " has negative value!" << std::endl;
            std::cout << "I am not sure what this means..." << std::endl;
            exit(1);
        }
    }
    else
    {
        ana.job_index = -1;
    }


    // Sanity check for split jobs (if one is set the other must be set too)
    if (result.count("job_index") or result.count("nsplit_jobs"))
    {
        // If one is not provided then throw error
        if ( not (result.count("job_index") and result.count("nsplit_jobs")))
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --job_index and --nsplit_jobs must be set at the same time!" << std::endl;
            exit(1);
        }
        // If it is set then check for sanity
        else
        {
            if (ana.job_index >= ana.nsplit_jobs)
            {
                std::cout << options.help() << std::endl;
                std::cout << "ERROR: --job_index >= --nsplit_jobs ! This does not make sense..." << std::endl;
                exit(1);
            }
        }
    }

    //
    // Printing out the option settings overview
    //
    std::cout <<  "=========================================================" << std::endl;
    std::cout <<  " Setting of the analysis job based on provided arguments " << std::endl;
    std::cout <<  "---------------------------------------------------------" << std::endl;
    std::cout <<  " ana.input_file_list_tstring: " << ana.input_file_list_tstring <<  std::endl;
    std::cout <<  " ana.output_tfile: " << ana.output_tfile->GetName() <<  std::endl;
    std::cout <<  " ana.n_events: " << ana.n_events <<  std::endl;
    std::cout <<  " ana.nsplit_jobs: " << ana.nsplit_jobs <<  std::endl;
    std::cout <<  " ana.job_index: " << ana.job_index <<  std::endl;
    std::cout <<  " ana.write_tree: " << ana.write_tree <<  std::endl;
    std::cout <<  " ana.region: " << ana.region <<  std::endl;
    std::cout <<  " ana.vhvvv_channel: " << ana.vhvvv_channel <<  std::endl;
    std::cout <<  " ana.run_VVVTree: " << ana.run_VVVTree <<  std::endl;
    std::cout <<  "=========================================================" << std::endl;

//********************************************************************************
//
// 2. Opening input baby files
//
//********************************************************************************

    // Create the TChain that holds the TTree's of the baby ntuples
    ana.events_tchain = RooUtil::FileUtil::createTChain(ana.input_tree_name, ana.input_file_list_tstring);

    // Create a Looper object to loop over input files
    // the "www" object is defined in the wwwtree.h/cc
    // This is an instance which helps read variables in the WWW baby TTree
    // It is a giant wrapper that facilitates reading TBranch values.
    // e.g. if there is a TBranch named "lep_pt" which is a std::vector<float> then, one can access the branch via
    //
    //    std::vector<float> lep_pt = www.lep_pt();
    //
    // and no need for "SetBranchAddress" and declaring variable shenanigans necessary
    // This is a standard thing SNT does pretty much every looper we use
    if (ana.run_VVVTree)
    {
        ana.looper_vvvtree.init(ana.events_tchain, &vvv, ana.n_events);
    }
    else
    {
        ana.looper.init(ana.events_tchain, &nt, ana.n_events);
    }

    // Set the cutflow object output file
    ana.cutflow.setTFile(ana.output_tfile);

    // Create ttree for TTreeX to hold the variables
    ana.tree_intermediate_variable = new TTree("t", "t");
    ana.tx.setTree(ana.tree_intermediate_variable);

    // Create output ttree to write to output.root
    ana.output_tree = new TTree("t", "t");
    ana.output_tx.setTree(ana.output_tree);

//********************************************************************************
//
// 3. Main event loop
//
//********************************************************************************

    Begin();

    if (ana.run_VVVTree)
    {
        // Looping input file
        while (ana.looper_vvvtree.nextEvent())
        {

            // If splitting jobs are requested then determine whether to process the event or not based on remainder
            if (result.count("job_index") and result.count("nsplit_jobs"))
            {
                if (ana.looper_vvvtree.getNEventsProcessed() % ana.nsplit_jobs != (unsigned int) ana.job_index)
                    continue;
            }

            Process();

        }
    }
    else
    {
        // Looping input file
        while (ana.looper.nextEvent())
        {

            // If splitting jobs are requested then determine whether to process the event or not based on remainder
            if (result.count("job_index") and result.count("nsplit_jobs"))
            {
                if (ana.looper.getNEventsProcessed() % ana.nsplit_jobs != (unsigned int) ana.job_index)
                    continue;
            }

            Process();

        }
    }

    Terminate();

}

import style
import os
import argparse

username = os.environ['USER']

haddlist = dict() # dictionary of lists - first entry of the list - name of merged file, all following entries: named of files to be merged
haddlist[2016] = [
    ["data_2016_ee", "data_Run2016Bv1_ee", "data_Run2016Bv2_ee", "data_Run2016C_ee", "data_Run2016D_ee", "data_Run2016E_ee", "data_Run2016F_ee", "data_Run2016G_ee", "data_Run2016H_ee"], 
    ["data_2016_em", "data_Run2016Bv1_em", "data_Run2016Bv2_em", "data_Run2016C_em", "data_Run2016D_em", "data_Run2016E_em", "data_Run2016F_em", "data_Run2016G_em", "data_Run2016H_em"], 
    ["data_2016_mm", "data_Run2016Bv1_mm", "data_Run2016Bv2_mm", "data_Run2016C_mm", "data_Run2016D_mm", "data_Run2016E_mm", "data_Run2016F_mm", "data_Run2016G_mm", "data_Run2016H_mm"], 
    ["DY", "DY_low", "DY_high"], 
    ["W", "WJets"], 
    ["Top", "ST1", "ST2","TTDL"], 
    ["TopX", "TTBAR_PH", "TTZnlo","TTWnlo","TWZ", "TZQ", "TTTTnew"], 
    ["WW", "WWDPS", "QQWW","WWG"], 
    ["WZ", "WZ", "WZG"], 
    ["ZZ", "ZZ", "ZZcontTo2e2mu","ZZcontTo2e2tau","ZZcontTo2mu2tau","ZZcontTo4e","ZZcontTo4mu","ZZcontTo4tau"], 
    ["VVV", "WWW", "WWZ","WZZ","ZZZ"], 
    ["VH", "VHtoNonBB"], 
    ["Other", "TTG", "TGext", "GGHtoZZto4L", "WGToLNuGext", "ZG"]
    ]

haddlist[2017] = [
    ["data_2017_ee", "data_Run2017B_ee", "data_Run2017C_ee", "data_Run2017D_ee", "data_Run2017E_ee", "data_Run2017F_ee"], 
    ["data_2017_em", "data_Run2017B_em", "data_Run2017C_em", "data_Run2017D_em", "data_Run2017E_em", "data_Run2017F_em"], 
    ["data_2017_mm", "data_Run2017B_mm", "data_Run2017C_mm", "data_Run2017D_mm", "data_Run2017E_mm", "data_Run2017F_mm"], 
    ["DY", "DY_low", "DY_high"], 
    ["W", "WJets"], 
    ["Top", "STantitop", "STtop","TTDL","TTSLtopbar","TTSLtop"], 
    ["TopX", "TTBAR_PH", "TTZnlo","TTWnlo","TWZ", "TZQ", "TTTTnew"], 
    ["WW", "WWDPS", "QQWW","WWG", "WW"], 
    ["WZ", "WZ", "WZG"], 
    ["ZZ", "ZZ", "ZZcontTo2e2mu","ZZcontTo2e2tau","ZZcontTo2mu2tau","ZZcontTo4e","ZZcontTo4mu","ZZcontTo4tau"], 
    ["VVV", "WWW", "WWZ","WZZ","ZZZ"], 
    ["VH", "VHtoNonBB"], 
    ["Other", "TTGdilep", "TTGsinglelepbar", "TTGsinglelep", "TGext", "GGHtoZZto4L", "WGToLNuGext", "ZG"]
    ]

haddlist[2018] = [
    ["data_2018_ee", "data_Run2018B_ee", "data_Run2018C_ee", "data_Run2018D_ee"], 
    ["data_2018_em", "data_Run2018B_em", "data_Run2018C_em", "data_Run2018D_em"], 
    ["data_2018_mm", "data_Run2018B_mm", "data_Run2018C_mm", "data_Run2018D_mm"], 
    ["DY", "DY_low", "DY_high"], 
    ["W", "WJets"], 
    ["Top", "STantitop", "STtop","TTDL","TTSLtopbar","TTSLtop"], 
    ["TopX", "TTBAR_PH", "TTZnlo","TTWnlo","TWZ", "TZQ", "TTTTnew"], 
    ["WW", "WWDPS", "QQWW","WWG", "WW"], 
    ["WZ", "WZ", "WZG"], 
    ["ZZ", "ZZ", "ZZcontTo2e2mu","ZZcontTo2e2tau","ZZcontTo2mu2tau","ZZcontTo4e","ZZcontTo4mu","ZZcontTo4tau"], 
    ["VVV", "WWW", "WWZ","WZZ","ZZZ"], 
    ["VH", "VHtoNonBB"], 
    ["Other", "TTGdilep", "TTGsinglelepbar", "TTGsinglelep", "TGext", "GGHtoZZto4L", "WGToLNuGext", "ZG"]
]

haddlist[0] = [
    ["data_ee", "2016/data_2016_ee", "2017/data_2017_ee", "2018/data_2018_ee"], 
    ["data_em", "2016/data_2016_em", "2017/data_2017_em", "2018/data_2018_em"], 
    ["data_mm", "2016/data_2016_mm", "2017/data_2017_mm", "2018/data_2018_mm"], 
    ["DY",      "2016/DY",           "2017/DY",           "2018/DY"          ], 
    ["W",       "2016/W",            "2017/W",            "2018/W"           ], 
    ["Top",     "2016/Top",          "2017/Top",          "2018/Top"         ], 
    ["TopX",    "2016/TopX",         "2017/TopX",         "2018/TopX"        ], 
    ["WW",      "2016/WW",           "2017/WW",           "2018/WW"          ], 
    ["WZ",      "2016/WZ",           "2017/WZ",           "2018/WZ"          ], 
    ["ZZ",      "2016/ZZ",           "2017/ZZ",           "2018/ZZ"          ], 
    ["VVV",     "2016/VVV",          "2017/VVV",          "2018/VVV"         ], 
    ["VH",      "2016/VH",           "2017/VH",           "2018/VH"          ], 
    ["Other",   "2016/Other",        "2017/Other",        "2018/Other"       ]
]

def main(args):
    indir, outdir = "", ""
    fflag = "-f" if args.force else ""
    if args.year >= 2016 and args.year <= 2018:
        indir = "/nfs-7/userdata/{}/tupler_babies/merged/VVV/{}/output/{}/".format(username,args.tag,args.year)
        outdir = "/nfs-7/userdata/{}/tupler_babies/merged/VVV/{}/processmerged/{}/".format(username,args.tag,args.year)
    elif args.year == 0:
        indir = "/nfs-7/userdata/{}/tupler_babies/merged/VVV/{}/processmerged/".format(username,args.tag)
        outdir = "/nfs-7/userdata/{}/tupler_babies/merged/VVV/{}/processmerged/allyears/".format(username,args.tag)
    if not os.path.isdir(indir):
        print("Directory "+indir+" does not exists -stop.")
        return 0
    if not os.path.exists(outdir):
        os.makedirs(outdir)
        print("Created directorty "+outdir+".")

    for i in range(len(haddlist[args.year])):
        haddstring = "hadd {} {}{}.root ".format(fflag,outdir,haddlist[args.year][i][0])
        for j in range(1,len(haddlist[args.year][i])):
            haddstring += "{}{}.root ".format(indir,haddlist[args.year][i][j])
        print(haddstring)
        #os.system(haddstring)

    return 1

if __name__ == "__main__":

    # Define options
    parser = argparse.ArgumentParser(description="Plotter for VVV analysis")
    parser.add_argument('-t' , '--tag'      , dest='tag'      , help='tag of the job submitted to condor'   , required=True)
    parser.add_argument('-y' , '--year'     , dest='year'     , help='data year', type=int, required=True)
    parser.add_argument('-f' , '--force'    , dest='force'    , help='force hadd', default=False, action='store_true')
    # Argument parser
    args = parser.parse_args()
    args.tag

    # Main
    main(args)

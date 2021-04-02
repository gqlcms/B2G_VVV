#!/bin/env python

import sys

new_file = sys.argv[1]
orig_file = sys.argv[2]

new_lines = open(new_file).readlines()
orig_lines = open(orig_file).readlines()

new_line_str = "".join(new_lines)
orig_line_str = "".join(orig_lines)

delimiter = "//---------------------------------------------------------------------------------\n"

new_contents = new_line_str.split("//---------------------------------------------------------------------------------\n")
orig_contents = orig_line_str.split("//---------------------------------------------------------------------------------\n")

ii = 0
jj = 0

total_new = len(new_contents)
total_orig= len(orig_contents)

merge_contents = []

# function  
def common_member(a, b):     
    a_set = set(a) 
    b_set = set(b) 
    # check length  
    if len(a_set.intersection(b_set)) > 0: 
        return(a_set.intersection(b_set))   
    else: 
        return("no common elements") 

common_lines = list(common_member(new_contents, orig_contents))

while ii < total_new or jj < total_orig:

    nc = new_contents[ii]
    oc = orig_contents[jj]

    if nc == oc or "makeCMS3ClassFiles" in nc:
        merge_contents.append(nc)
        ii += 1
        jj += 1
    else:
        if nc in common_lines and oc not in common_lines:
            merge_contents.append(oc)
            jj += 1
        elif nc not in common_lines and oc in common_lines:
            merge_contents.append(nc)
            ii += 1
        else:
            merge_contents.append(oc)
            jj += 1
            merge_contents.append(nc)
            ii += 1

print(delimiter.join(merge_contents))

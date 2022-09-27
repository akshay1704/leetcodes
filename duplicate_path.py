from collections import defaultdict
import re
from typing import DefaultDict

def findDuplicate(paths: list[str]) -> list[list[str]]:
    unique_files = []
    dir_map = defaultdict(lambda:[])
#    s=''
#    for i in paths:
#        s=s+i
#    files = re.findall(('\(.*?\)'),s)
#    for file in files:
#        if file not in unique_files:
#            unique_files.append(file)
#            dir_map[file]=[]
    for dir_info in paths:
        files_list = []
        elements = dir_info.split(' ')
        directory = elements[0]
        for i in range(len(elements)-1):
            contents = re.findall(('\(.*\)'),str(elements[i+1]))
            text = directory+'/'+str(elements[i+1].split('(')[0])
            dir_map[contents[0]].append(text)
    result = []            
    for key in dir_map:
        if len(dir_map[key])>1:
            result.append(dir_map[key])  
    print(result) 
                             
path = ["root/a 1.txt(abcd) 2.txt(efsfgh)","root/c 3.txt(abdfcd)","root/c/d 4.txt(efggdfh)"]
findDuplicate(paths = path)
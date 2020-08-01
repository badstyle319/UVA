import sys
import os

while 1:
    print("Target to query: ", end="")
    target = str(input())

    for (dirpath, dirnames, filenames) in os.walk(os.getcwd()):
        for filename in filenames:
            if filename.count(target) > 0 and filename.count(" - ") > 0:
                print(dirpath + "\\" + filename)

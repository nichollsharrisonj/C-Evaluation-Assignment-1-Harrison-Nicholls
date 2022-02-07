import os
os.system("echo > cresults.txt")
for i in range(0,15):
    numObjects = 28 * 2 **i
    numIterations = 30000000 // numObjects
    os.system(f"echo Running benchmark with: {numObjects} objects and {numIterations} iterations: >> cresults.txt") 
    os.system("echo  >> cresults.txt")
    os.system(f"./update_locations {numObjects} {numIterations} >> cresults.txt")
    os.system("echo  >> cresults.txt")

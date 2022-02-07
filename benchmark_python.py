import os
os.system("echo > results.txt")
for i in range(0,15):
    numObjects = 28 * 2 **i
    numIterations = 30000000 // numObjects
    os.system(f"echo Running benchmark with: {numObjects} objects and {numIterations} iterations: >> results.txt") 
    os.system("echo  >> results.txt")
    os.system(f"python3 update_locations.py {numObjects} {numIterations} >> results.txt")
    os.system("echo  >> results.txt")

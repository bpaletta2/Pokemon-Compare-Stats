import matplotlib.pyplot as plt
import numpy as np
import subprocess
from subprocess import Popen, PIPE, check_output
import sys
import csv



# Compile the C++ program
subprocess.check_output(
    "g++ -std=c++17 main.cpp Trainer.cpp Pokemon.cpp -o outputProgram.exe",
    stderr=subprocess.STDOUT,
    shell=True
)

# Execute the compiled program
subprocess.run("./outputProgram.exe", shell=True, check=True)

# read data into files
with open('project4_outfile.csv', mode='r', encoding='utf-8') as file:
    reader = csv.reader(file)
    selectionOne = []
    selectionTwo = []
    names = []
    xName = ""
    yName = ""
    count = 0 

    for row in reader:
        selectionOne.append(int(row[0]))
        selectionTwo.append(int(row[1]))
        names.append((row[2]))
        if count < 1:
            xName = row[3]
            yName = row[4]
            count += 1



x = np.array(selectionOne)
y = np.array(selectionTwo)

plt.scatter(x, y)

for i, txt in enumerate(names):
    plt.annotate(txt, (x[i], y[i]))
    
    
plt.xlabel(xName)
plt.ylabel(yName)
#plt.savefig('images/selectionOne.png')
plt.show()




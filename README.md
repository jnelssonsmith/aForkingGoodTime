
# FIT2070 Assignment 2
##### Josh Nelsson-Smith
##### 16/09/2016
---
## Installing the program
Start by downloading and unzipping the file named `25954113_A2.zip`, once unzipped you should see the folder contains the following files:
```
25954113_A2
├── README.md
├── README.pdf
├── Timing\ Files
│   ├── 1string10long.txt
│   ├── 1string8long.txt
│   ├── 2strings8long.txt
│   ├── 3strings8long.txt
│   ├── 4strings8long.txt
│   └── processTiming.pdf
├── assignment2-coversheet-jxns.pdf
├── compScript.sh
├── permutations
├── src
│   ├── permutations.c
│   └── task2.c
└── task2

2 directories, 14 files
```
The project contains the `src` folder that houses the c code for the assignment. Within it are the `permutations.c` and `task2.c` files. Inside the `Timing Files` directory are a few sample time output files for various combinations of inputs and string lengths as well as `processTiming.pdf` that lists the averages for these files. The project also comes with a shell script that can be used to compile the code called `compScript.sh`. It is recommended you re-compile the code before running to ensure the executables work correctly on your architecture.

a. Compile using included script ```compScript.sh```
```sh
$ ./compScript.sh
Compiling c program...
C programs compiled!
```
Note - you may need to alter permissions to allow the script to execute via something like:
```sh
$ chmod 777 compScript.sh
```
b. Compile the program manually via:
```sh
$ gcc -o permutations src/permutations.c
$ gcc -o task2 src/task2.c
```
---
## Using the Programs

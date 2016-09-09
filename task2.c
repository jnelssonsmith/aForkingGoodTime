 /*
NAME: Joshua Nelsson-Smith
STUDENT ID: 25954113
START DATE: 03/09/16
LAST MODIFIED: 09/09/16
DESCRIPTION: This function is used to run multiple processes that each run the
permutations program created for task 1. You feed the program the number of
strings to be worked with and the list of strings, then it spawns a child process
for every string and runs permutations on it.
ARGS:
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int nGiven = 0;
    int numberOfStrings;
    int errorInt;
    pid_t pid;

    //task2 <int> <string1> <string2>...
    errorInt = sscanf(argv[1], "%i", &nGiven);
    if(errorInt != 0){
        numberOfStrings = argc - 2;
        if(nGiven == numberOfStrings){
            for(int i=2; i < argc; i++){
                pid = fork();
                if(pid == 0){
                    execlp("./permutations", "permutations", argv[i], NULL);
                    exit(0);
                } else if (pid > 0){
                    //do nothing with parent
                } else {
                    printf("error creating process \n");
                }
            }
        } else {
            printf("Incorrect usage, n does not equal numnber of strings\n");
        }
    } else {
        printf("Incorrect usage\n");
    }


    for(int k=0; k < numberOfStrings; k++){
        wait(NULL);
    }
    return 0;
}

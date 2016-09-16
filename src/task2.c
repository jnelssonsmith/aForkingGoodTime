 /*
NAME: Joshua Nelsson-Smith
STUDENT ID: 25954113
START DATE: 03/09/16
LAST MODIFIED: 16/09/16
DESCRIPTION: This function is used to run multiple processes that each run the
permutations program created for task 1. You feed the program the number of
strings to be worked with and the list of strings, then it spawns a child process
for every string and runs permutations on it.
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

    errorInt = sscanf(argv[1], "%i", &nGiven); //check that argument given is an integer
    if(errorInt != 0){
        numberOfStrings = argc - 2; /*the number of strings is equal to number
        of args minus program name arg and number of strings arg */

        if(nGiven == numberOfStrings){
            printf("Running permute on strings...\n");
            int i=2;
            while (i < argc){
                //we create n new child processes where n is number of strings given
                pid = fork();
                if(pid == 0){
                    //if child process, then run permutations with the string you are up to (argv[i])
                    execlp("./permutations", "permutations", argv[i], NULL);
                    exit(0);
                } else if (pid > 0){
                    i++; //else increment the while loop to create more processes
                } else {
                    printf("error creating process \n");
                }
            }
        } else {
            printf("Incorrect usage, n does not equal numnber of strings\n");
            return 0;
        }
    } else {
        printf("Incorrect usage: n must be an integer\n");
        return 0;
    }

    /* we must wait for each of the child processes here outside the loop
    to ensure the program can exit gracefully */
    for(int k=0; k < numberOfStrings; k++){
        wait(NULL);
    }
    printf("\nPermutations complete. Check times.txt for time taken by each string and output.txt for the output of the permutations\n");
    return 0;
}

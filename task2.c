/*
NAME: Joshua Nelsson-Smith
STUDENT ID: 25954113
START DATE: 03/09/16
LAST MODIFIED:
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int numberOfStrings = 0;
    int errorInt;
    pid_t pid;

    //task2 <int> <string1> <string2>...
    errorInt = sscanf(argv[1], "%i", &numberOfStrings);
    if(errorInt != 0){
        if(numberOfStrings == argc - 2){
            for(int i=2; argc; i++){
                pid = fork();
                if(pid == 0){
                    printf("%s\n",argv[i]);
                    //execlp("./permutations", "permutations", argv[i], NULL);
                    exit(0);
                } else if (pid > 0){
                    exit(0);
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

}

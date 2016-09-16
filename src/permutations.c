/*
NAME: Joshua Nelsson-Smith
STUDENT ID: 25954113
START DATE: 03/09/16
LAST MODIFIED: 16/09/16
DESCRIPTION: This program takes a string of characters and prints out all the
permutations of the string using backtracking to swap every character of the
string recursively. It also features an optional -t parameter that will
run the tests for this program
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void swap(char *firstChar, char *secondChar) {
    /* ARGS:
    firstChar - the first character to swap
    secondChar - the other character you want to swap with the first
    DESCRIPTION: this function takes the two pointers to two characters and swaps
    them
    */
    char temp;
    temp = *firstChar;
    *firstChar = *secondChar;
    *secondChar = temp;
}

void permute(char *permString, int i, int n, char *processIdentifier, FILE *outputFilePointer) {
    /* ARGS:
    permString - the string that you want to print all the permutations of
    i - the position of the last set character in the string
    n - the index of the last character to be swapped
    processIdentifier - the id that we give to the process, used for the output
    used for the output logs so we can easily trace the interleaving of the
    proceses.
    outputFilePointer - the pointer to the file that we want to write the
    permutations to.
    DESCRIPTION: permute is a recursive algorithm using backtracking to
    swap all the letters in a string ... <should go into more detail>
    */
    int j;

    if(i == n) { //basecase where the current char to swap is set to the last
        printf("%s\n", permString);
        fprintf(outputFilePointer, "process %s: %s\n", processIdentifier, permString);
    } else {
        for(j = i; j <= n; j++) {
            swap(permString + i, permString + j);
            permute(permString, i + 1, n, processIdentifier, outputFilePointer);
            swap(permString + i, permString + j);
        }
    }
}

int main(int argc, char **argv) {
    /* This function is the interface for the command line - it takes in one
    arg, the string to be permuted and feeds it to the permute function. If the
    arg is "-t" it will run the tests.
    */

    char *id;
    clock_t startTime;
    clock_t endTime;
    double totalTime;
    FILE *timesFilePointer, *outputFilePointer;

    if(argc != 2){ //if there are more than 2 args in argv[], then exit,
        printf("Incorrect usage:\nUsage: permutations <string>\nType permutations -t to run tests");
        exit(0);
    } else {
        timesFilePointer = fopen("times.txt", "a");
        outputFilePointer = fopen("output.txt", "w");

        if (strcmp(argv[1], "-t") == 0){
            char *a = strdup("a");
            char *ab = strdup("ab");
            char *abc = strdup("abc");
            printf("--RUNNING TESTS--\nInput: a\nExpected output: a\nOutput:\n");
            permute(a, 0, 0, "testa", outputFilePointer);
            printf("\n----\nInput: ab\nExpected output: ab, ba\nOutput:\n");
            permute(ab, 0, 1, "testb", outputFilePointer);
            printf("\n----\nInput: abc\nExpected output: abc, acb, bac, bca, cab, cba\nOutput:\n");
            permute(abc, 0, 2, "testc", outputFilePointer);


        } else {
            id = strdup(argv[1]);
            startTime = clock();
            permute(argv[1], 0, strlen(argv[1]) - 1, id, outputFilePointer);
            endTime = clock();
            totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
            }
            fprintf(timesFilePointer, "%s: Time taken: %f seconds\n",id,totalTime);
        }
        fclose(timesFilePointer);
        fclose(outputFilePointer);

    return 0;
}

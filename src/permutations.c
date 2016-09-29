/*
NAME: Joshua Nelsson-Smith
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
    swap all the letters in a string. It works by iterating along a string,
    swapping one character with each other element in the string and running the
    program again recursively. Once a character is swapped it is fixed for that
    instance of the program and the i value is increased by one in subsequent
    calls. The base case is when the i value reaches the end of the string, and
    the last character swapped with itself would obviously return nothing so
    the recursion is complete.
    */
    int j;

    if(i == n) { //basecase where the current char to swap is set to the last
        printf("%s\n", permString);
        fprintf(outputFilePointer, "process %s: %s\n", processIdentifier, permString);
    } else {
        for(j = i; j <= n; j++) {
            swap(permString + i, permString + j);
            permute(permString, i + 1, n, processIdentifier, outputFilePointer);
            //have to swap back after permuting
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

    if(argc != 2){
        /*if there are more than 2 args in argv[], then exit (2 because argv[0]
        is always program name) */
        printf("Incorrect usage:\nUsage: permutations <string>\nType permutations -t to run tests");
        exit(0);
    } else {
        //only append times because sometimes we want to list a bunch at the same time
        timesFilePointer = fopen("times.txt", "a");
        /* we need use append here as well so the child processes dont overwrite eachother */
        outputFilePointer = fopen("output.txt", "a");

        /* the following is the test functionality, it runs through the cases
        of the string being "a", "ab" and "abc". It prints the expected output
        then it runs permute with those functions to ensure it works */
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
            /* if the -t argument is not given we will run permute on the string
            given it will also generate the timing  files */

            //the id associated with any string is just the original version of that string
            id = strdup(argv[1]);

            startTime = clock(); //start the clock count
            permute(argv[1], 0, strlen(argv[1]) - 1, id, outputFilePointer);
            endTime = clock(); //record clocks at end of execution

            /* total time in seconds will be the difference between start and end
            divided between the CLOCKS_PER_SEC */
            totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

            }
            fprintf(timesFilePointer, "%s: Time taken: %f seconds\n",id,totalTime);
        }
        fclose(timesFilePointer);
        fclose(outputFilePointer);

    return 0;
}

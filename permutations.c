/*
NAME: Joshua Nelsson-Smith
STUDENT ID: 25954113
START DATE: 03/09/16
LAST MODIFIED: 09/09/16
DESCRIPTION: This program takes a string of characters and prints out all the
permutations of the string using backtracking to swap every character of the
string recursively.
*/


/* need to add timing to this... */
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

void permute(char *permString, int i, int n, char *processIdentifier) {
    /* ARGS:
    permString - the string that you want to print all the permutations of
    i - the position of the last set character in the string
    n - the length of the string
    processIdentifier - the id that we give to the process
    so we can identify which outputs belong to which process when using task 2
    DESCRIPTION: permute is a recursive algorithm using backtracking to
    swap all the letters in a string ... <should go into more detail>
    */
    int j;

    if(i == n) {
        printf("process %s: ", processIdentifier);
        printf("%s\n", permString);
    } else {
        for(j = i; j <= n; j++) {
            swap(permString + i, permString + j);
            permute(permString, i + 1, n, processIdentifier);
            swap(permString + i, permString + j);
        }
    }
}

int main(int argc, char **argv) {
    /* This function is the interface for the command line - it takes in one
    arg, the string to be permuted and feeds it to the permute function.
    */
    char *id;
    clock_t startTime;
    clock_t endTime;
    double totalTime;

    if(argc != 2){
        printf("Incorrect usage:\nUsage: permutations <string>\n");
        exit(0);
    } else {
        id = strdup(argv[1]);
        startTime = clock();
        permute(argv[1], 0, strlen(argv[1]) - 1, id);
        endTime = clock();
        totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        }
        printf("Time taken: %f seconds\n", totalTime);
    return 0;
}

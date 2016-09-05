/*
NAME: Joshua Nelsson-Smith
STUDENT ID: 25954113
START DATE: 03/09/16
LAST MODIFIED: 05/09/16
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *firstChar, char *secondChar) {
    char temp;
    temp = *firstChar;
    *firstChar = *secondChar;
    *secondChar = temp;
}

void permute(char *permString, int i, int n, char *processIdentifier) {
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
    char *id;

    if(argc != 2){
        printf("Incorrect usage:\nUsage: permutations <string>\n");
        exit(0);
    } else {
        id = strdup(argv[1]);
        permute(argv[1], 0, strlen(argv[1]) - 1, id);
    }
    system("\n");
    return 0;
}

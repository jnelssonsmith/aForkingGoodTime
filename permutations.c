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

void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print(char *a, int i, int n, char *processIdentifier) {
    int j;

    if(i == n) {
        printf("process %s: ", processIdentifier);
        printf("%s\n", a);
    } else {
        for(j = i; j <= n; j++) {
            swap(a + i, a + j);
            print(a, i + 1, n, processIdentifier);
            swap(a + i, a + j);
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
        print(argv[1], 0, strlen(argv[1]) - 1, id);
    }
    return 0;
}

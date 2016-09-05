/*
NAME: Joshua Nelsson-Smith
STUDENT ID: 25954113
START DATE: 03/09/16
LAST MODIFIED:
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>

void permutations(char permString[26]){
    printf("you entered %s\n", permString);
}

int main(void) {
    char permString[26];

    strcpy(permString, "Hello");
    permutations(permString);
    return 0;
}

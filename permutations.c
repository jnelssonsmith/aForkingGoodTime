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


int main(int argc, char **argv) {
    if(argc != 2){
        printf("Incorrect usage:\nUsage: permutations <string>\n");
        exit(0);
    } else {
        printf("%s\n", argv[1]);
    }
    return 0;
}

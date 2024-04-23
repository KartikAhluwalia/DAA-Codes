#include <stdio.h>
#include <stdlib.h>

int stinger(char* text, char* pattern, int textlen, int patlen){

    int i = 0;
    int j = 0;
    for(i = 0; i <= (textlen - patlen); i++){
        for(j = 0; j < patlen; j++){
            if(text[i+j] != pattern[j]){
                break;
            }
        }
        if(j == patlen){
            return i;
        }
    }
    return -1;
}

void main(void){

    char text[] = "This code has been made by Vishesh.";
    char pattern[] = "has";
    int textlen = strlen(text);
    int pattlen = strlen(pattern);

    int idx = stinger(text, pattern, textlen, pattlen);
    printf("The pattern was found at the index : %d\n(Indexing starts from 0)", idx);

    return;
}

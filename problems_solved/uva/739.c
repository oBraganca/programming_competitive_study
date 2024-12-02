//
// Created by obraganca on 11/27/24.
//

#include <stdio.h>
#include <string.h>

int check(char c){
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y' || c == 'W' || c == 'H' ? 1 : 0;
}

char code (char c){

    switch (c) {
        case 'B':
        case 'P':
        case 'F':
        case 'V':
            return '1';
            break;
        case 'C':
        case 'S':
        case 'K':
        case 'G':
        case 'J':
        case 'Q':
        case 'X':
        case 'Z':
            return '2';
        case 'D':
        case 'T':
            return '3';
        case 'L':
            return '4';
        case 'M':
        case 'N':
            return '5';
            break;
        case 'R':
            return '6';
            break;
    }
    return c;
}

int main(){

    char nm [20];

    while (scanf("%s", nm) != EOF){

        char sdc[4] ;
        int t = strlen(nm);

        sdc[0] = nm[0];
        int j = 1;
        int r=0;
        for(int i = 1 ; i<t; i++){
            char c = code(nm[i]);
            char cs = code(sdc[j-1]);
            if(cs == c && !check(nm[i]) && r){
                sdc[j] = (char)code(nm[i]);
                j++;
                r=0;
            }else if(cs != c && !check(nm[i])){
                sdc[j] = (char)code(nm[i]);
                j++;

                r=0;
            }else{
                r = 1;
            }
        }


        for(int i = j; i<4; i++){
            sdc[i] = 0+'0';
        }

        for (int i = 0; i < 4; ++i) {
            printf("%c", sdc[i]);
        }
        printf("\n");

    }
    return 0;
}
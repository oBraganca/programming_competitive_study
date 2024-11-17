//
// Created by obraganca on 11/14/24.
//
#include <stdio.h>

int main(){
    char p;
    int a=0;

    while((p = getchar()) != EOF){
        if(p == '"'){
            a++;
            if (a % 2 == 0) {
                printf("''"); // Substitui puts por printf
            } else {
                printf("``"); // Substitui puts por printf
            }
        }else{
            putchar(p);
        }
    }
}


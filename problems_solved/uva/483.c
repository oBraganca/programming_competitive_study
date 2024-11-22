/*
* UVa 483 - Reverse Text
        *
        * Thayllon Bragança
        * thayllonbraganca@gmail.com
* */

#include <stdio.h>

int main(){
    char p[30], c;
    int i =-1;
    while ((c = getchar()) != EOF){

        if(c != ' ' && c !='\n'){
            i++;
            p[i] = c;
        }else{
            for(int j=i; j>=0; j--){
                putchar(p[j]);
                i--;
            }
            putchar(c);
        }

    }

    return 0;
}
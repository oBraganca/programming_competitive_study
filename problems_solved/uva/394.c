/*
 *
 *
 * INPUT:
 * 3 4
 * ONE 1500 2 2 0 3 1 5
 * TWO 2000 4 3 1 4 0 5 5 10
 * THREE 3000 1 1 1 9
 * ONE 2 4
 * THREE 7
 * TWO 2 0 6
 * TWO 3 3 9
 *
 *
 * ONE          1500            2                   2                       0 3               1 5
 * Nome         base matriz     tamanho em bytes    Numero de elementos     varia de 0 a 3    varia de 1 a 5
 * */


#include <stdio.h>
#include <stdlib.h>


int main(){
    int n=0, nr=0;

    scanf("%d%d", &n,&nr);



    char** an = (char**)malloc(n*sizeof(char*));
    for(int i =0; i<n; i++){
        char* *(an+i) = (char**)malloc(10*sizeof(char*));
        scanf("%s", *(an+i));


    }


    for(int i =0; i<n; i++){

    }

    return 0;
}
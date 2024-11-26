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
#include <string.h>


typedef struct{
    char an[10];
    int bm;
    int tb;
    int n;
    int t[10];
    int d[10];
    int c[12];
}arr;

int main(){
    int n=0, nr=0;

    scanf("%d %d", &n, &nr);
    arr* ar = malloc(n*sizeof(arr));

    for(int i =0; i<n; i++){
        scanf("%s%d%d%d", ar[i].an, &ar[i].bm,&ar[i].tb,&ar[i].n);
        for(int j=0; j<ar[i].n; j++){
            scanf("%d", &ar[i].d[j]);
            scanf("%d", &ar[i].t[j]);

        }

        ar[i].c[ar[i].n] = ar[i].tb;
        ar[i].c[0] = ar[i].bm;
        for(int j=ar[i].n-1; j>=1; j--){

            ar[i].c[j] = ar[i].c[j+1]*(ar[i].t[j] - ar[i].d[j] +1);
        }
    }

    char nm[10];
    int an;
    int a=0;


    unsigned long tt;
    for(int i =0; i<nr; i++){
        scanf("%s", nm);
        for(int j = 0; j < n; j++){

            if(!strcmp(ar[j].an, nm)){
                a = j;
                tt = ar[j].c[0];
                break;
            }
        }
        printf("%s[", ar[a].an);
        scanf("%d",&an);
        printf("%d",an);
        tt += ar[a].c[ar[a].n]*(an-ar[a].d[0]);
        for(int j=1;j<ar[a].n; j++){
            scanf("%d",&an);
            tt += ar[a].c[j]*(an-ar[a].d[j]);
            printf(", %d",an);
        }
        printf("] = %lu\n",tt);
    }
    return 0;
}
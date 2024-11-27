//
// Created by obraganca on 11/26/24.
//

#include <stdio.h>
int main(){

    int n, m, c, o, v[20], vs[20], j=0;
    while(scanf("%d%d%d", &n, &m, &c)!= EOF){
        int vt = 0, max=0;
        if(n == 0 && m == 0 && c == 0){ break; }
        j++;
        for(int i =0; i<n; i++){
            scanf("%d", &v[i]);
            vs[i] = 0;
        }

        for(int i =0; i<m; i++){
            scanf("%d", &o);
            if(vs[o-1] == 1){
                vt-=v[o-1];
                vs[o-1] = 0;
            }else{
                vt+=v[o-1];
                vs[o-1] = 1;
            }
            if(max < vt){
                max = vt;
            }

            if(vt>c){
                break;
            }

        }

        printf("Sequence %d\n", j);
        if(vt>c){
            printf("Fuse was blown.\n\n");
        }else{
            printf("Fuse was not blown.\n");
            printf("Maximal power comsumption was %d amperes.\n\n", max);
        }

    }

    return 0;
}



#include <stdio.h>

int main(){
    int h, u, d, f;

    while(scanf("%d%d%d%d", &h, &u, &d, &f) != EOF){
        if(h == 0){
            break;
        }
        float c = 0.0, cb = u, ff = ((u*f)/100.0);
        int da=0;
        while(c<h && c >= 0){
            da++;
            c += cb;

            if (c > h) {
                break;
            }
            c -= d;

            if (c < 0) {
                break;
            }
            cb -= ff;
        }


        if(c > 0){
            printf("success on day %d\n", da);
        }else{
            printf("failure on day %d\n", da);
        }

    }

    return 0;
}
//
// Created by obraganca on 12/4/24.
//

#include <stdio.h>
#define tam 6
void order(const float *a, float *b, int n) {
    // Copia os valores de 'a' para 'b'
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }

    // Ordena o vetor 'b'
    float temp = 0.0f;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i] > b[j]) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
}

int main(){

    int qnt, n;
    scanf("%d",&qnt);


    for(int i=0; i<qnt; i++){
        getchar();
        scanf("%d",&n);
        float x[tam], y[tam], p[tam], o[tam];
        int j=0;
        for(int i =0; i<n; i++){

            scanf("%f%f%f%f%f", &x[j], &y[j], &x[j+1], &y[j+1], &p[i]);
            if(x[j] > x[j+1]){
                float t = x[j];
                x[j] = x[j+1];
                x[j+1] = t;
                
                t = y[j];
                y[j] = y[j+1];
                y[j+1] = t;
            }
            j+=2;
        }
        
        
        order(x, o, n*2);
        printf("-inf, %.1f -> %.3f\n", o[0], 1.000);
        for(int i =0; i<(n*2)-1; i++){
        	float pp=1.0;
        	for(int j = 0; j<(n*2); j+=2){
        		if(o[i] >= x[j] && o[i+1] <= x[j+1]){
        			pp*=p[j/2];
        			printf("[%d %lf]", j/2, p[j/2]);
        		}
        	}    	
	        printf(" %.1f, %.1f -> %.3f\n", o[i], o[i+1], pp);
        }
        
        printf(" %.1f, +inf -> %.3f\n", o[(n*2)-1], 1.000);
    }
    return 0;
}

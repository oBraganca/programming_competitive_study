#include <stdio.h>

int countBetweenCycleLenght(int n){
    int c = 1;  // Conta o próprio número como parte do ciclo

    if(n != 1){
        if(n % 2 != 0) {
            n = (3 * n) + 1;
        } else {
            n = n / 2;
        }
        c += countBetweenCycleLenght(n);
    }
    return c;
}

int main(){
    int i, j;

    while (scanf("%d %d", &i, &j) == 2) {
        int maxCycleLength = 0;

        int start = i < j ? i : j;
        int end = i > j ? i : j;

        for(int k = start; k <= end; k++){
            int cycleLength = countBetweenCycleLenght(k);
            if(cycleLength > maxCycleLength){
                maxCycleLength = cycleLength;
            }
        }

        printf("%d %d %d\n", i, j, maxCycleLength);
    }

    return 0;
}

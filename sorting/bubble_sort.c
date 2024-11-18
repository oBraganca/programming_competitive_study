#include <stdio.h>

void bubbleSort(int *);
void printValues(int *);

int main(){
    int values[] = {6, 8, 3, 5, 9, 10, 7, 2, 4, 1};

    printValues(values);

    bubbleSort(values);

    printValues(values);

    return 0;
}

void bubbleSort(int *arr){
    for(int i =0; i<10; i++){
        int swap=0;
        for(int j=0; j<10 - i; j++){
            if(arr[j] > arr[j+1]){
                int aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
                swap = 1;
            }
        }
        if(!swap){ break; }

    }
}

void printValues(int *values){
    printf("Values: [ ");

    for(int i =0; i<10; i++){
        printf("%d ", *(values+i));
    }

    printf("]\n");
}

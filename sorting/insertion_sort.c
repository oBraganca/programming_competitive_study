//
// Created by obraganca on 11/10/24.
//

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int);
void printValues(int *);

int main(){
    int values[] = {6, 8, 3, 5, 9, 10, 7, 2, 4, 1};

    printValues(values);

    insertionSort(values, 10);

    printValues(values);

    return 0;
}

void insertionSort(int *arr, int n){
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Mover elementos maiores que key uma posição à frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printValues(int *values){
    printf("Values: [ ");

    for(int i =0; i<10; i++){
        printf("%d ", *(values+i));
    }

    printf("]\n");
}

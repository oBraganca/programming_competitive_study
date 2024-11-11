//
// Created by obraganca on 11/10/24.
//

#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *);
void printValues(int *);

int main(){
    int values[] = {6, 8, 3, 5, 9, 10, 7, 2, 4, 1};

    printValues(values);

    selectionSort(values);

    printValues(values);

    return 0;
}

void selectionSort(int *values){
    for(int i = 0; i<10; i++){
        int min = i;
        for(int j=i+1; j<10; j++){
            if(values[min]>values[j]){
                min = j;
            }
        }
        int aux = values[min];
        values[min] = values[i];
        values[i] = aux;
    }
}

void printValues(int *values){
    printf("Values: [ ");

    for(int i =0; i<10; i++){
        printf("%d ", *(values+i));
    }

    printf("]\n");
}

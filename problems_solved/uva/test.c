#include <stdio.h>
#include <string.h>


#define MAX_ARRAYS 100
#define MAX_DIMENSIONS 10


typedef struct{
    char name[20];
    int base_address;
    int size;
    int dimensions;
    int lower_bounds[MAX_DIMENSIONS];
    int upper_bounds[MAX_DIMENSIONS];
    int coefficients[MAX_DIMENSIONS+1];

}Array;


Array arrays[MAX_ARRAYS];
int array_count = 0;


int find_array_index(const char *name){
    for(int i =0; i<array_count; i++){
        if(!strcmp(arrays[i].name, name)){
            return i;
        }
    }
    return -1;
}

void calculate_coefficients(Array *array){
    int C = array->size;
    array->coefficients[array->dimensions] = C;

    for(int i = array->dimensions-1; i>= 0; i--){
        C*=(array->upper_bounds[i]-array->lower_bounds[i]+1);
        array->coefficients[i] = C;
    }

    array->coefficients[0]=array->base_address;

    for(int i =0; i<= array->dimensions; i++){
        array->coefficients[0] -= array->coefficients[i]*array->lower_bounds[i-1];
    }
}


int main(){
    int n, r;

    scanf("%d %d", &n, &r);

    for(int i=0; i<n; i++){
        Array array;
        scanf("%s %d %d %d", array.name, &array.base_address, &array.size, &array.dimensions);

        for(int j=0; j<array.dimensions; j++){
            scanf("%d %d", &array.lower_bounds[j], &array.upper_bounds[j]);
        }

        calculate_coefficients(&array);
        arrays[array_count++] = array;
    }

    for(int i =0; i<r; i++){

        char query_name[20];

        int indices[MAX_DIMENSIONS];
        scanf("%s", query_name);
        int array_index = find_array_index(query_name);
        Array * array = &arrays[array_index];

        for(int j=0; j< array->dimensions; j++){
            scanf("%d", &indices[j]);
        }

        int address = array->coefficients[0];

        for(int j=0; j<array->dimensions; j++){
            address+=array->coefficients[j+1]*(indices[j]-array->lower_bounds[j]);
        }

        printf("%s[",array->name);
        for(int j=0; j<array->dimensions; j++){
            printf("%d",indices[j]);
            if(j<array->dimensions-1){ printf(", "); }
        }

        printf("] = %d\n",address);
    }

    return 0;
}
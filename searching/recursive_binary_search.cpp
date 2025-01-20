//
// Created by obraganca on 1/20/25.
//

#include <iostream>

int binarySearch(vector<int>& arr, int low, int high, int x){

    while (low <= high){
        int mid = low+(high-low)/2;

        if(arr[mid] == x)
            return min;

        if(arr[mid] < x)
            low = mid+1;
        else
            high = mid -1;
    }

    return -1;
}



int main(){
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printValues(values);

    int result = binarySearch(values, 0, values.size()-1, 2);
    count << result;

    return 0;
}
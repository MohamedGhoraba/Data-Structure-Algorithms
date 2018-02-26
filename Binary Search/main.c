#include <stdio.h>
#include <stdlib.h>

void Binary_Search(int arr[], int size, int num){
    int found = 0,mid = 0;
    int low = 0, high = size - 1;
    while(low <= high && !found){
        mid = (low + high) / 2;
        if(arr[mid] > num){
            high = mid - 1;
        }
         else if(arr[mid] < num){
            low = mid + 1;
        }
        else{
            found = 1;
        }
    }
    printf("Number is %d and Position is %d",arr[mid], mid);
}

int main()
{
    int size = 10;
    int arr[10] = {10,14,19,26,27,31,33,35,42,44};
    Binary_Search(arr,size,35);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int intArray[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};

void Search(int array[] , int data){
    int i,found = 0;
    for(i = 0; i < MAX; i++){
        if( data == array[i]){
            printf("Position %d and data %d", i,data);
            found = 1;
            break;
        }
    }
    if(!found){
        printf(" Not found");
    }
}

int main()
{

    Search(intArray,66);
    return 0;
}

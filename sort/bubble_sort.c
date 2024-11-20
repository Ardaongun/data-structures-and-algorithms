#include <stdio.h>

void bubbleSort(int array[],int size){
    int swapped;
    for(int i = 0 ; i < size - 1; i++){
        swapped = 0;
        for(int j = 0 ; j < size - 1 - i ; j++){
            if(array[j] > array[j + 1]){
                swapped = 1;
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
        if(!swapped)
            break;
    }
}

void printArray(int array[],int size){
    for(int i = 0 ; i < size ; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

int main(){
    int array[] = {23, 58, 82, 12, 90, 2, 5, 34};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array:\n");
    printArray(array,size);

    bubbleSort(array,size);

    printf("Sorted array:\n");
    printArray(array,size);
}
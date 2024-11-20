#include <stdio.h>

void instertionSort(int array[], int size){
    for(int i = 1 ; i < size ; i++){
        int key = array[i];
        int j = i - 1;

        while(j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
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

    instertionSort(array,size);

    printf("Sorted array:\n");
    printArray(array,size);
}
#include <stdio.h>

void selectionSort(int array[],int size){
    for(int i = 0 ; i < size - 1 ; i++){
        int minIndex = i;

        for(int j = i + 1 ; j < size ; j++){
            if(array[j] < array[minIndex]){
                minIndex = j;
            }
        }

        if(minIndex != i){
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
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

    selectionSort(array,size);

    printf("Sorted array:\n");
    printArray(array,size);
}
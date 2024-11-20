#include <stdio.h>

void bidirectionalSelectionSort(int array[], int size){
    for(int i = 0 ; i < size / 2 ; i++){
        int minIdnex = i;
        int maxIndex = i;

        for(int j = i + 1; j < size -i ; j++){
            if(array[j] < array[minIdnex])
                minIdnex = j;
            if(array[j] > array[maxIndex])
                maxIndex = j;
        }

        if(minIdnex != i){
            int temp = array[i];
            array[i] = array[minIdnex];
            array[minIdnex] = temp;
        }

        if(maxIndex == i){
            maxIndex = minIdnex;
        }

        if(maxIndex != size - i - 1){
            int temp = array[size - i - 1];
            array[size - i - 1] = array[maxIndex];
            array[maxIndex] = temp;
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

    bidirectionalSelectionSort(array,size);

    printf("Sorted array:\n");
    printArray(array,size);
}
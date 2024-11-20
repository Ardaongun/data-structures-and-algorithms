#include <stdio.h>

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[],int low,int high){
    int pivot = array[high];
    int i = low - 1;

    for(int j = low ; j < high ; j++){
        if(array[j] <= pivot){
            i++;
            swap(&array[i],&array[j]);
        }
    }

    swap(&array[i + 1],&array[high]);
    return (i + 1);
}

void quickSort(int array[],int low,int high){
    if(low < high){
        int partionIndex = partition(array,low,high);

        quickSort(array,low,partionIndex - 1);
        quickSort(array,partionIndex + 1,high);
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

    quickSort(array,0,size -1);

    printf("Sorted array:\n");
    printArray(array,size);
}
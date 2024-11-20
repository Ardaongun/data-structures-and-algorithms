#include <stdio.h>

void merge(int array[],int left,int mid,int right){
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;

    int subArrayLeft[sizeLeft],subArrayRight[sizeRight];

    for(int i = 0 ; i < sizeLeft ; i++)
        subArrayLeft[i] = array[left + i];
    for(int i = 0 ; i < sizeRight ; i++)
        subArrayRight[i] = array[mid + 1 + i];    

    int i = 0,j = 0, k = left;
    while(i < sizeLeft && j < sizeRight){
        if(subArrayLeft[i] <= subArrayRight[j]){
            array[k] = subArrayLeft[i];
            i++;
        } else{
            array[k] = subArrayRight[j];
            j++;
        }
        k++;
    }       

    while(i < sizeLeft){
        array[k] = subArrayLeft[i];
        i++;
        k++;
    }

    while(j < sizeRight){
        array[k] = subArrayRight[j];
        j++;
        k++;
    }
}

void mergeSort(int array[],int left,int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        mergeSort(array,left,mid);
        mergeSort(array,mid + 1,right);

        merge(array,left,mid,right);
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

    mergeSort(array,0,size - 1);

    printf("Sorted array:\n");
    printArray(array,size);
}
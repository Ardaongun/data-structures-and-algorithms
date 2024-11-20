#include <stdio.h>

int binarySearchRecursive(int array[], int left, int right,int target){
    if(left > right){
        return -1;
    }

    int mid = left + (right - left) / 2;

    if(array[mid] == target){
        return mid;
    }

    if(array[mid] < target){
        return binarySearchRecursive(array,mid + 1,right,target);
    }

    //if target is smaller than the middle element, search in the left half
    return binarySearchRecursive(array,left,mid - 1,target);
}

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(array) / sizeof(array[0]);
    int target;

    printf("Please enter the number to search:");
    scanf("%d",&target);

    int result = binarySearchRecursive(array, 0, size - 1, target);

    if(result != -1)
        printf("%d was found. It's index in the array is %d.\n",target,result);
    else
        printf("%d could not found.\n",target);
}

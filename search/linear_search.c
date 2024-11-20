#include <stdio.h>

int linearSearch(int array[], int size, int target){
    for(int i = 0 ; i < size ; i++){
        if(array[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(array) / sizeof(array[0]);
    int target;

    printf("Please enter the number to search:");
    scanf("%d",&target);
    int result = linearSearch(array, size, target);
    if(result != -1)
        printf("%d was found. It's index in the array is %d.\n",target,result);
    else
        printf("%d could not found.\n",target);
}
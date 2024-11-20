#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 100    


typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(const int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data;
    newNode->next = NULL;
    return newNode;
}

int main(){

}
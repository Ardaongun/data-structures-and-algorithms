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
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void sortedInsert(Node** head, const int data){
    Node* newNode = createNode(data);

    if(*head == NULL || (*head)->data >= data){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while(current->next != NULL && current->next->data < data){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteNode(Node** head,int value){
    if(*head == NULL){
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;

    if(temp != NULL && temp->data == value){
        *head = temp->next;
        free(temp);
        printf("%d was deleted from the list.\n",value);
        return;
    }

    Node* prev = NULL;
    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("%d not found in the list.\n",value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("%d was deleted from the list.\n",value);
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    Node* head = NULL;
}
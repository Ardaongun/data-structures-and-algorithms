#include <stdio.h>
#include <stdlib.h>

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

int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element in sorted order\n");
        printf("2. Delete an element\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            sortedInsert(&head, value);
            break;
        case 2:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            deleteNode(&head, value);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
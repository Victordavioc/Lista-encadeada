#include "list.h"
#include <stdlib.h>
#include <stdio.h>



void insertAtBeginning(Node** head, int newData){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}


void insertAtEnd(Node** head, int newData){
    Node* newNode = (Node*) malloc(sizeof(Node));
    Node* last = *head;
    newNode->data = newData;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void deleteNode(Node** head, int key){
    Node* temp = *head;
    Node* prev = NULL;
    
    if(temp != NULL && temp->data == key){
        *head = temp->next;
        free (temp);
        return;
    }
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL) return;
    
    prev->next = temp->next;
    free(temp);
}

//insere valores na posição ordenada, a lista precisa ja estar ordenada 
void insertSort(Node** head, int newData) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= newData) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data < newData) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}
//ordena uma lista desordenada com método insertionSort

void sortList(Node** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;

    Node* sorted = NULL;
    Node* current = *head;

    while (current != NULL) {
        Node* next = current->next;
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head = sorted;
}



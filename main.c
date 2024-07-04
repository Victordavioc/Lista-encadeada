#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    Node *head = NULL;
    int list_size;
    insertSort(&head, 10);
    insertSort(&head, 30);
    insertSort(&head, 20);
    insertSort(&head, 40);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 32);
    sortList(&head);
    
    printList(head);
    
}
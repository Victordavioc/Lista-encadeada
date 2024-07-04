

typedef struct Node{
    int data;
    struct Node* next;
} Node;


void insertAtBeginning(Node** head, int newData);
void insertAtEnd(Node** head, int newData);
void printList(Node* node);
void deleteNode(Node** head, int key);
void insertSort(Node** head, int newData);
void deleteNode(Node** head, int key);
void insertSort(Node** head, int newData);
void sortList(Node** head);
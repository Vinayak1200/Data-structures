#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;
void printList(Node* n)
{
    while (n != NULL) {                          
        printf(" %d ", n->data);
        n = n->next;
    }
}
Node * insert_first(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));        //Function to insert a node at the beginning of list
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
Node * insert_at_index(Node *head, int data, int index)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;                               //Function to insert a node at a particular index
    int i=0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
    
}
Node *insert_last(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    Node *p = head;
    while(p->next!=NULL)                        //Function to insert a node at the end of the list
    {
        p = p->next;
    }
    p->next= ptr;
    ptr->next = NULL;
    return head;
}
int main(void)
{
     Node* head = NULL;
     Node* second = NULL;
     Node* third = NULL;
 
    // allocate 3 nodes in the heap
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
 
    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second
 
    second->data = 2; // assign data to second node
    second->next = third;
 
    third->data = 3; // assign data to third node
    third->next = NULL;
    
    printf("The orignal list is as follows : ");
    printList(head);
    printf("\n");
    printf("New list : ");
    //head = insert_first(head, 4);
    //head = insert_at_index(head, 4, 2);
    head = insert_last(head, 5);
    printList(head);
    printf("\n");

    return 0;
}
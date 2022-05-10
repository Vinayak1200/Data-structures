#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* left;         //structure form of a node of a tree
    struct Node* right;
};
typedef struct Node Node;
Node * CreateNode(int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));      //Function to create a new node of tree
    ptr->data = data;                              //a pointer to Node is created in memory 
    ptr->left=NULL;
    ptr->right=NULL;

    
    return ptr;
}
int main(void)
{
    Node *root;
    root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);                  //We have created a binary tree consisting of 3 nodes


    printf("The binary tree is as follows : \n");
    printf("\n%d\n\n%d     %d\n", root->data, root->left->data, root->right->data);

    return 0;
}
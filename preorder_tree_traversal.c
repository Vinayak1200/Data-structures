#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;

Node* CreateNode(int data)
{
    Node* ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;

    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}


void preorder(Node* ptr)
{
    if (ptr!=NULL)
    {
        printf("%d", ptr->data);                //Function for preorder traversal of tree
        printf("\n");
        preorder(ptr->left);
        preorder(ptr->right);
    }
}



int main(void)
{
    Node* node;
    node = CreateNode(1);                 
    node->left = CreateNode(2);
    node->right = CreateNode(3);
    node->left->left = CreateNode(4);
    node->left->right = CreateNode(5);
    node->right->left = CreateNode(6);
    node->right->right = CreateNode(7);             //         1
                                                   //         /  \       
                                                   //        2    3
                                                //          / \   /\         
                                               //          4  5  6  7

    preorder(node);                    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node* left;         //structure form of a node of a tree
    struct Node* right;
};
typedef struct Node Node;
//Function to create a new node of tree
//a pointer to Node is created in memory
Node * CreateNode(int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));      
    ptr->data = data;                              
    ptr->left=NULL;
    ptr->right=NULL;

    
    return ptr;
}
// Function to search any node of a binary tree
//It returns true if node is found else it returns false
bool SearchNode(Node* node, int key)
{
    if (node == NULL)
        return false;
 
    if (node->data == key) 
        return true;
 
    bool x = SearchNode(node->left, key);
    if(x) return true;
 
    bool y = SearchNode(node->right, key);
 
    return y;
}
int main(void)
{
    Node *root;
    root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);                  //We have created a binary tree consisting of 3 nodes
                                          
                                                  //          1                                                  
                                                  //         / \                                               
                                                  //        /   \                                                  
                                                  //       2     3                                                  


    printf("%d\n",SearchNode(root, 3));
    printf("%d\n", SearchNode(root, 10));
    return 0;
}
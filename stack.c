#include <stdio.h>     
#include <stdlib.h>
struct stack
{
    int size;
    int top;              //Creating stack structure
    int *arr;
};
typedef struct stack stack;


stack* init(stack *ptr)
{
    ptr->top=-1;               //Function to initialise stack (Empty)
    return ptr;
}

int isEmpty(stack *ptr)
{
    if (ptr->top==-1)
    {
        return 1;               //Function to check whether stack is empty
    }
    else return 0;
}

int isFull(stack *ptr)
{
    if (ptr->top==(ptr->size)-1)
    {
        return 1;                   //Function to check whether stack is full
    }
    else return 0;
}

void push(stack *ptr, int x)
{
    ++ptr->top;                     //Pushing an element x to the stack
    ptr->arr[ptr->top]=x;
}

void pop(stack *ptr)
{
    ptr->top = ptr->top-1;         //Popping off the top element from the stack
}

void PrintStack(stack *ptr)
{
    for (int i=0;i<=ptr->top;i++)
    {
        printf("%d\n", (ptr->arr)[i]);
    }
}


int main(void)
{
    stack *s;
    s = (stack *)malloc(sizeof(stack));
    s->size=100;
    s->arr = (int *)malloc(s->size*sizeof(int));


    s = init(s);
    for (int i=0;i<5;i++)
    {
        push(s, i);
    }
    PrintStack(s);
    printf("\n\n");
    pop(s);
    PrintStack(s);
    return 0;
}
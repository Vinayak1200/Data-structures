//PROGRAM TO REVERSE A STRING USING 2 STACKS 

#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;                     //Creating stack structure storing characters            
    char *arr;
};
typedef struct stack stack;


int isEmpty(stack *ptr)
{
    if (ptr->top==-1)
    {
        return 1;               
    }
    else return 0;
}

stack* init(stack *ptr)
{
    ptr->top=-1;               
    return ptr;
}

void push(stack *ptr, char x)
{
    ++ptr->top;                     
    ptr->arr[ptr->top]=x;
}

char pop(stack *ptr)
{
    int n = ptr->top;
    ptr->top = ptr->top-1;  
    return (ptr->arr)[n];
}

void pop_n_push(stack *ptr1, stack *ptr2)
{
    while (isEmpty(ptr1)==0)
    {
        char temp = pop(ptr1);                   //Function to pop elements from one stack
        push(ptr2, temp);                        //and push it to another
    }
}
void PrintStack(stack *ptr)
{
    for (int i=0;i<=ptr->top;i++)
    {
        printf("%c", (ptr->arr)[i]);
    }
    printf("\n");
}




int main()
{
    stack *s1, *s2;
    s1 = (stack *)malloc(sizeof(stack));
    s2 = (stack *)malloc(sizeof(stack));

    s1->arr = (char *)malloc(s1->size*sizeof(char));
    s2->arr = (char *)malloc(s1->size*sizeof(char));


    char c1;
    printf("Enter a string : ");
    while ((c1=getchar())!='\n')
    {
        push(s1, c1);
    }

    
    pop_n_push(s1, s2);
    PrintStack(s2);

    return 0;
}
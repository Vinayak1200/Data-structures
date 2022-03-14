#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int total_size;
    int used_size;
    int *ptr;
}myarray;
void createarray(myarray *a, int tsize, int usize)
{
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize*sizeof(int));
}
void show(myarray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
    
}
void setval(myarray *a)
{
    int temp;
    for (int i=0;i<(a->used_size);i++)
    {
        printf("Enter element %d : ", i);
        scanf(" %d", &temp);
        (a->ptr)[i]=temp;
    }
}
int main(void)
{
    myarray marks;
    int t, u;
    printf("Enter maximum number of elements required : ");
    scanf("%d", &t);
    printf("Enter number of elements that will be used : ");
    scanf("%d", &u);
    createarray(&marks, t, u);
    setval(&marks);
    show(&marks);
    return 0;
}
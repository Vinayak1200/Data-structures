void delete(int arr[], int size, int index)
{
    for (int i=index;i<size-1;i++)                   //Function to delete element of array
    {
        arr[i]=arr[i+1];
    }
}
int insert(int arr[], int size, int element, int capacity, int index)
{
    if (size>=capacity)
    {
        return -1;
    }                                               //Function to insert an element in the array
    for (int i=size-1;i>=index;i--)
    {
        if (i==index-1)
        {
            arr[index] = element;
            return 1;
        }
        arr[i+1]=arr[i];
    }
}
int linsearch(int arr[], int size, int element)
{
    for (int i=0;i<size;i++)
    {                                             //Function to search for element using linear search
        if (arr[i]==element)
        {
            return i;
        }
        else continue;
    }
}
int binsearch(int arr[], int size, int element)
{
    int l, m h;
   while(l<=h)
   {                                             //Function to search for element using Binary search
    m = (l+h)/2;
    if (arr[m]==element)
    {
        return m;
    }
    if (arr[m]<element)
    {
        l=m+1;

    }
    else
    {
        l=m-1;
    }
   }
   return -1;
}
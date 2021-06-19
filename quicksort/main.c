#include <stdio.h>
#include "quicksort.h"
int main()
{
    unsigned int n;
    printf("Enter the number of elements you wish to enter: ");
    scanf("%u", &n);
    int array[n];
    printf("Enter your elements with a space after each one: ");
    int i;
    int *ptr = array;
    for (i = 0; i < n; i++)
    {
        scanf("%d", (ptr+i)); 
    }
    for (i = 0; i < n; i++)
    {
        if (i >= n - 1)
        {
            printf("%d \n", *(ptr + i));
        }
        else
        {
            printf("%d, ", *(ptr + i));
        }
    }
    printf("Now using quick sort\n");
    quicksort(ptr, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        if (i >= n - 1)
        {
            printf("%d \n", *(ptr + i));
        }
        else
        {
            printf("%d, ", *(ptr + i));
        }
    }
    return 0;
}
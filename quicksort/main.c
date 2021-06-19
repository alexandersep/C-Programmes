#include <stdio.h>
#include "quicksort.h"
int main()
{
    int n;
    printf("Enter the number of elements you wish to enter: ");
    scanf("%d", &n);
    while (n < 0)
    {
        printf("You inputted a negative amount of elements, try again: ");
        scanf("%d", &n);
    }
    int array[n];
    printf("Enter your elements with a space after each one: ");
    int i;
    signed int *ptr = array;
    for (i = 0; i < n; i++)
    {
        scanf("%d", (ptr+i)); 
    }
    printArray(ptr, n);

    printf("Now using quick sort\n");

    quicksort(ptr, 0, n - 1);

    printArray(ptr, n);
    
    return 0;
}
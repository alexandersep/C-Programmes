#include <stdio.h>
#include "quicksort.h"
void quicksort(int *pArray, int lo, int hi) 
{
    int p;
    if (lo < hi)
    {
        p = partition(pArray, lo, hi);
        quicksort(pArray, lo, p - 1);
        quicksort(pArray, p + 1, hi);
    }
}
int partition(int * pArray, int lo, int hi)
{
    int pivot = *(pArray+hi), i = lo, j; 
    for (j = lo; j <= hi; j++) 
    {
        if (*(pArray+j) < pivot)
        {
            swap(pArray, i, j); 
            i += 1; 
        }
    }
    swap(pArray, i, hi); 
    return i;
}
void swap(int * pArray, int aIndex, int bIndex)
{
    int tempBIndex = *(pArray+bIndex); 
    *(pArray+bIndex) = *(pArray+aIndex);
    *(pArray+aIndex) = tempBIndex;
}
void printArray(signed int * pArray, int numOfElements)
{
    int i = 0;
    for (i = 0; i < numOfElements; i++)
    {
        if (i >= numOfElements - 1)
        {
            printf("%d \n", *(pArray + i)); /* print last element */
            break; /* leave loop */
        }
        printf("%d, ", *(pArray + i)); /* else print commas and next element*/
    }
}
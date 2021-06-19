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
int partition(int *pArray, int lo, int hi)
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
void swap(int *pArray, int aIndex, int bIndex)
{
    int firstElementToBeSwapped = *(pArray+aIndex);
    int secondElementToBeSwapped = *(pArray+bIndex);
    *(pArray+bIndex) = firstElementToBeSwapped;
    *(pArray+aIndex) = secondElementToBeSwapped;
}
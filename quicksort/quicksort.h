#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

/* takes pointer/array and lo and hi index of portion of the array */ 
void quicksort(int *pArray, int lo, int hi); 

int partition(int *pArray, int lo, int hi);

void swap(int *pArray, int aIndex, int bIndex);

void printArray(signed int * pArray, int numOfElements);

#endif
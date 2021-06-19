#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

/* takes pointer/array and lo and hi index of portion of the array */ 
void quicksort(int *pArray, int lo, int hi); 

/* used in quick sort to seperate elements into groups */
int partition(int *pArray, int lo, int hi);

/* used in quick sort to swap two elements in the array */
void swap(int *pArray, int aIndex, int bIndex);

/* print values in the array */
void printArray(signed int * pArray, int numOfElements);

#endif
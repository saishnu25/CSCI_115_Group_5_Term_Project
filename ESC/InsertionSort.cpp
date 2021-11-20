#include "InsertionSort.h"

void InsertionSort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int currentNumber = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > currentNumber)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = currentNumber;
    }
}

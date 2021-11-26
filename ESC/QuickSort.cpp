#include "QuickSort.h"
#include <algorithm>
#include <stdlib.h>
#include <time.h>

int Partition(int array[], int low, int high, PivotChoice pivotChoice)
{
    switch (pivotChoice)
    {
        case PivotChoice::LastElement:
            std::swap(array[high], array[low]);
            break;
        case PivotChoice::RandomElement:
            srand(time(0));
            std::swap(array[low + (rand() % ((high - low) + 1))], array[low]);
            break;
    }

    int pivot = array[low];

    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            j--;
        } while (array[j] > pivot);

        do
        {
            i++;
        } while (array[i] < pivot);

        if (i < j)
        {
            std::swap(array[i], array[j]);
        }
        else
        {
            return j;
        }
    }
}

void QuickSort(int array[], int p, int r, PivotChoice pivotChoice)
{
    if (p < r)
    {
        int Q = Partition(array, p, r, pivotChoice);
        QuickSort(array, p, Q, pivotChoice);
        QuickSort(array, Q + 1, r, pivotChoice);
    }
}
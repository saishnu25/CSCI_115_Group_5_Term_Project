#include "SelectionSort.h"
#include <algorithm>

void SelectionSort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }

        std::swap(array[i], array[minIndex]);
    }
}

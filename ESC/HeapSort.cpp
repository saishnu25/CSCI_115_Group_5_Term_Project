#include "HeapSort.h"
#include <algorithm>

void MaxHeapify(int array[], int n, int i)
{
    int largestIndex = i;
    int leftIndex = (i * 2) + 1;
    int rightIndex = (i * 2) + 2;

    if (leftIndex < n && array[leftIndex] > array[largestIndex])
        largestIndex = leftIndex;

    if (rightIndex < n && array[rightIndex] > array[largestIndex])
        largestIndex = rightIndex;

    if (largestIndex != i)
    {
        std::swap(array[i], array[largestIndex]);

        MaxHeapify(array, n, largestIndex);
    }
}

void BuildMaxHeap(int array[], int n)
{
    int startIndex = (n / 2) - 1;

    for (int i = startIndex; i >= 0; i--)
    {
        MaxHeapify(array, n, i);
    }
}

void HeapSort(int array[], int n)
{
    BuildMaxHeap(array, n);

    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(array[i], array[0]);
        MaxHeapify(array, i, 0);
    }
}

#include "MergeSort.h"
#include <vector>

void Merge(int array[], int left, int middle, int right)
{
    int i = left;
    int j = middle + 1;
    int k = 0;
    int finalArraySize = (right - left) + 1;
    std::vector<int> finalArray(finalArraySize);
    
    while (i <= middle && j <= right)
    {
        if (array[i] < array[j])
        {
            finalArray[k] = array[i];
            i++;
        }
        else
        {
            finalArray[k] = array[j];
            j++;
        }

        k++;
    }

    while (i <= middle)
    {
        finalArray[k] = array[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        finalArray[k] = array[j];
        j++;
        k++;
    }

    for (int i = 0; i < finalArraySize; i++)
    {
        array[left + i] = finalArray[i];
    }
}

void MergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;
        MergeSort(array, left, middle);
        MergeSort(array, middle + 1, right);
        Merge(array, left, middle, right);
    }
}
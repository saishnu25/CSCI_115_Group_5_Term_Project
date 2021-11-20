#include "CountingSort.h"
#include <vector>

void CountingSort(int array[], int n)
{
    int maxValue = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] > maxValue) maxValue = array[i];
    }

    std::vector<int> frequencyArray(maxValue + 1);

    for (int i = 0; i < n; i++)
    {
        frequencyArray[array[i]]++;
    }

    for (int i = 1; i < maxValue + 1; i++)
    {
        frequencyArray[i] += frequencyArray[i - 1];
    }

    std::vector<int> outputArray(n);
    for (int i = n - 1; i >= 0; i--)
    {
        outputArray[frequencyArray[array[i]] - 1] = array[i];
        frequencyArray[array[i]]--;
    }

    std::copy(std::begin(outputArray), std::end(outputArray), array);
}

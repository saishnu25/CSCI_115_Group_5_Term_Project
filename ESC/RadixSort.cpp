#include "RadixSort.h"
#include <vector>

void RadixSort(int array[], int n)
{
    int maxValue = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] > maxValue) maxValue = array[i];
    }

    for (int i = 1; maxValue / i > 0; i *= 10)
    {
        int frequencyArray[10] = {};

        for (int j = 0; j < n; j++)
        {
            frequencyArray[(array[j] / i) % 10]++;
        }

        for (int j = 1; j < 10; j++)
        {
            frequencyArray[j] += frequencyArray[j - 1];
        }

        std::vector<int> outputArray(n);
        for (int j = n - 1; j >= 0; j--)
        {
            outputArray[frequencyArray[(array[j] / i) % 10] - 1] = array[j];
            frequencyArray[(array[j] / i) % 10]--;
        }

        std::copy(std::begin(outputArray), std::end(outputArray), array);
    }
}
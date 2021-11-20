#include "RadixSort.h"
#include <string>
#include <vector>

void RadixSort(int array[], int n)
{
    int maxValue = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] > maxValue) maxValue = array[i];
    }

    int maxValueSize = std::to_string(maxValue).length();

    for (int i = 0; i < maxValueSize; i++)
    {
        int frequencyArray[10] = {};

        for (int j = 0; j < n; j++)
        {
            std::string number = std::to_string(array[j]);
            int digitIndex = ((int)number.length() - 1) - i;
            int frequencyArrayIndex = (digitIndex >= 0) ? (int)number[digitIndex] - 48 : 0;
            frequencyArray[frequencyArrayIndex]++;
        }

        for (int i = 1; i < 10; i++)
        {
            frequencyArray[i] += frequencyArray[i - 1];
        }

        std::vector<int> outputArray(n);
        for (int j = n - 1; j >= 0; j--)
        {
            std::string number = std::to_string(array[j]);
            int digitIndex = ((int)number.length() - 1) - i;
            int frequencyArrayIndex = (digitIndex >= 0) ? (int)number[digitIndex] - 48 : 0;
            outputArray[frequencyArray[frequencyArrayIndex] - 1] = array[j];
            frequencyArray[frequencyArrayIndex]--;
        }

        std::copy(std::begin(outputArray), std::end(outputArray), array);
    }
}
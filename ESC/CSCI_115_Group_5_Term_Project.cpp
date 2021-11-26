#include <iostream>
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "CountingSort.h"
#include "RadixSort.h"
#include "Tests.h"

int main()
{
    Test1("Insertion Sort", [](int array[], int n) { InsertionSort(array, n); });

    std::cout << std::endl << std::endl;

    Test1("Selection Sort", [](int array[], int n) { SelectionSort(array, n); });

    std::cout << std::endl << std::endl;

    Test1("Bubble Sort", [](int array[], int n) { BubbleSort(array, n); });

    std::cout << std::endl << std::endl;

    Test1("Merge Sort", [](int array[], int n) { MergeSort(array, 0, n - 1); });

    std::cout << std::endl << std::endl;

    Test1("Quick Sort", [](int array[], int n) { QuickSort(array, 0, n - 1, PivotChoice::FirstElement); });

    std::cout << std::endl << std::endl;
    
    Test1("Heap Sort", [](int array[], int n) { HeapSort(array, n); });

    std::cout << std::endl << std::endl;

    Test1("Counting Sort", [](int array[], int n) { CountingSort(array, n); });

    std::cout << std::endl << std::endl;

    Test1("Radix Sort", [](int array[], int n) { RadixSort(array, n); });
}

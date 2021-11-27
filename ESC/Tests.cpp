#include "Tests.h"
#include <iostream>
#include <chrono>

void PrintDetails(int array[], int n, std::string sortingAlgorithmName, std::function<void(int[], int)> sortingAlgorithm)
{
    std::cout << sortingAlgorithmName << std::endl;
    auto begin = std::chrono::high_resolution_clock::now();
    sortingAlgorithm(array, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Execution Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanoseconds" << std::endl;
    /*for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;*/
}

void Test1(std::string sortingAlgorithmName, std::function<void(int[], int)> sortingAlgorithm)
{
    int array[] = { 13, 8, 21, 6, 8, 35 };
    PrintDetails(array, sizeof(array) / sizeof(array[0]), sortingAlgorithmName, sortingAlgorithm);
}
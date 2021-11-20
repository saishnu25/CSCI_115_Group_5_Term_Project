#pragma once

#include <string>
#include <functional>

void PrintDetails(int array[], int n, std::string sortingAlgorithmName, std::function<void(int[], int)> sortingAlgorithm);
void Test1(std::string sortingAlgorithmName, std::function<void(int[], int)> sortingAlgorithm);
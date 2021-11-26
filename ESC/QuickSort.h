#pragma once

enum class PivotChoice { FirstElement, LastElement, RandomElement };
int Partition(int array[], int low, int high, PivotChoice pivotChoice);
void QuickSort(int array[], int p, int r, PivotChoice pivotChoice);
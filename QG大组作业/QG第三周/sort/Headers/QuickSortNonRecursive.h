//
// Created by k on 25-3-30.
//

#ifndef QUICKSORTNONRECURSIVE_H
#define QUICKSORTNONRECURSIVE_H

#include <vector>
#include <stack>
#include <algorithm>

class QuickSortNonRecursive
{
     static int partition(std::vector<int>& arr, int left, int right);

     static void quickSortNonRecursive(std::vector<int>& arr);
};



#endif //QUICKSORTNONRECURSIVE_H

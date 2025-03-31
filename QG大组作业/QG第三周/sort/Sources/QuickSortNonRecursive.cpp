//
// Created by k on 25-3-30.
//

#include "QuickSortNonRecursive.h"

//分区函数
int QuickSortNonRecursive::partition(std::vector<int> &arr, int left, int right)
{
     int pivot = arr[right];
     int i = left - 1;
     for (int j = left; j < right; ++j)
     {
          if (arr[j] <= pivot)
          {
               ++i;
               std::swap(arr[i], arr[j]);
          }
     }
     std::swap(arr[i + 1], arr[right]);
     return i + 1;
}

//快排非递归版
void QuickSortNonRecursive::quickSortNonRecursive(std::vector<int> &arr)
{
     int n = arr.size();
     if (n <= 1)
     {
          return;
     }
     std::stack<int> stack;
     stack.push(0);
     stack.push(n - 1);

     while (!stack.empty())
     {
          int right = stack.top();
          stack.pop();
          int left = stack.top();
          stack.pop();

          int pivotIndex = partition(arr, left, right);

          if (pivotIndex - 1 > left)
          {
               stack.push(left);
               stack.push(pivotIndex - 1);
          }

          if (pivotIndex + 1 < right)
          {
               stack.push(pivotIndex + 1);
               stack.push(right);
          }
     }
}

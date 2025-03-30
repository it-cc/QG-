//
// Created by k on 25-3-29.
//

#include "InsertSort.h"

void InsertSort::sort(vector<int> &nums)
{
     if (nums.empty())
     {
          cerr<<"数组为空，无法排序！"<<endl;
          return;
     }
     for (int i = 1; i < nums.size(); i++)
     {
          for (int j = i; j >0; j--)
          {
               if (nums[j] < nums[j - 1])
               {
                    swap(nums[j], nums[j - 1]);
               }
               else
               {
                    break;
               }
          }
     }
}

void InsertSort::swap(int &a, int &b)
{
     int temp = a;
     a = b;
     b = temp;
}

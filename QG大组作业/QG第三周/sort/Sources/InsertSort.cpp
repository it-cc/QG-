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
          //将元素不断交换到排序后的位置，即插入到指定位置
          for (int j = i; j >0; j--)
          {
               if (nums[j] < nums[j - 1])
               {
                    swap(nums[j], nums[j - 1]);
               }
               //如果不需要交换，则说明插入到了指定位置，直接退出内循环
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

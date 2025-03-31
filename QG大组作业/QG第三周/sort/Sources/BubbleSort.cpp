//
// Created by k on 25-3-30.
//

#include "BubbleSort.h"

//优化一：提前终止循环
void BubbleSort::bubbleSort_first(vector<int> &nums)
{
     //提前终止标准
     bool swapFlag = false;
     int n=nums.size();
     for (int i = 0; i < n-1; i++)
     {
          for (int j=0;j<n-1-i;j++)
          {
               if (nums[j]>nums[j+1])
               {
                    swap(nums[j],nums[j+1]);
                    swapFlag = true;
               }
          }
          //如果没有交换，说明数组已经是有序的，则无需再排序，直接退出循环
          if (!swapFlag) break;
     }
}

//优化二：记录最后交换的位置
void BubbleSort::bubbleSort_second(vector<int> &nums)
{
     int n=nums.size();
     int newLastPosition= 0;
     int lastPosition = n - 1;
     for (int i=0;i<n-1;i++)
     {
          bool swapFlag = false;
          for (int j=0;j<lastPosition;j++)
          {
               if (nums[j]>nums[j+1])
               {
                    swap(nums[j],nums[j+1]);
                    swapFlag = true;
                    //记录最后交换的位置
                    //因为此位置后面的数据都是有序的，则下一次冒泡只需遍历到newLastPosition
                    newLastPosition = j;
               }
          }
          //更新交换位置
          lastPosition = newLastPosition;
          if (!swapFlag) break;
     }
}

//优化三：双向冒泡
void BubbleSort::bubbleSort_third(vector<int> &nums)
{
     int left=0,right=nums.size()-1;
     while (left<right)
     {
          //正向冒泡
          int newRight=left;
          for (int i=left;i<right;i++)
          {
               if (nums[i]>nums[i+1])
               {
                    swap(nums[i],nums[i+1]);
                    //类似优化二，记录最后交换的位置
                    newRight=i;
               }
          }
          right=newRight;

          //反向冒泡
          int newLeft=right;
          for (int j=right;j>left;j--)
          {
               if (nums[j]<nums[j-1])
               {
                    swap(nums[j],nums[j-1]);
                    //类似优化二，记录最后交换的位置
                    newLeft=j;
               }
          }
          left=newLeft;
     }
}

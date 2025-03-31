//
// Created by k on 25-3-29.
//

#include "MergeSort.h"

//用于辅助合并有序数组
vector<int>MergeSort::temp;


void MergeSort::sort(vector<int> &nums)
{
     if (nums.empty())
     {
          cerr<<"数组为空，无法排序！"<<endl;
          return;
     }
     temp.resize(nums.size());
     mergeSort(nums,0,nums.size()-1);
}

void MergeSort::mergeSort(vector<int> &nums,int low,int high)
{
     if (low==high) return;
     int mid=(low+high)/2;
     //排序 nums[low...mid]
     mergeSort(nums,low,mid);
     //排序 nums[mid+1...high]
     mergeSort(nums,mid+1,high);
     // 此时两部分子数组已经被排好序,合并两个有序数组，使 nums[lo..hi] 有序
     merge(nums,low,mid,high);
}

void MergeSort::merge(vector<int> &nums, int low, int mid, int high)
{
     //把nums赋值给tmep
     for (int i=low;i<=high;i++)
     {
          temp[i]=nums[i];
     }
     //划分为left和right两个有序数组
     int left=low,right=mid+1;
     //利用双指针，合并两个有序数组
     for (int i=low;i<=high;i++)
     {
          //此时已合并完左边的数组，直接把右边数组的所有元素合并进nums
          if (left==mid+1)
          {
               nums[i]=temp[right];
               right++;
          }
          //此时已合并完右边的数组，直接把左边数组的所有元素合并进nums
          else if (right==high+1)
          {
               nums[i]=temp[left];
               left++;
          }
          //选择左边数组和右边数组较小的元素，合并进nums，因为左右两边数组都是有序的
          else if (temp[left]<temp[right])
          {
               nums[i]=temp[left];
               left++;
          }
          //右边数组更大的情况
          else
          {
               nums[i]=temp[right];
               right++;
          }
     }
}

//
// Created by k on 25-3-29.
//

#include "MergeSort.h"

vector<int>MergeSort::temp;


void MergeSort::sort(vector<int> &nums)
{
     if (nums.empty())
     {
          cerr<<"数组为空，无法排序！"<<endl;
          return;
     }
     if (nums.empty()) return;
     temp.resize(nums.size());
     mergeSort(nums,0,nums.size()-1);
}

void MergeSort::mergeSort(vector<int> &nums,int low,int high)
{
     if (low==high) return;
     int mid=(low+high)/2;
     mergeSort(nums,low,mid);
     mergeSort(nums,mid+1,high);
     merge(nums,low,mid,high);
}

void MergeSort::merge(vector<int> &nums, int low, int mid, int high)
{
     for (int i=low;i<=high;i++)
     {
          temp[i]=nums[i];
     }
     int left=low,right=mid+1;
     for (int i=low;i<=high;i++)
     {
          if (left==mid+1)
          {
               nums[i]=temp[right];
               right++;
          }
          else if (right==high+1)
          {
               nums[i]=temp[left];
               left++;
          }
          else if (temp[left]<temp[right])
          {
               nums[i]=temp[left];
               left++;
          }
          else
          {
               nums[i]=temp[right];
               right++;
          }
     }
}

//
// Created by k on 25-3-30.
//

#include "RadixSort_LSD.h"

//基数排序
void RadixSort_LSD::sort(vector<int> &nums)
{
     if (nums.empty())
     {
          cerr<<"数组为空，无法排序！"<<endl;
          return;
     }
     //找到nums中的最小值
     int minVal=*min_element(nums.begin(),nums.end());

     //把nums中的元素转化为从0开始的非负数
     int offset=-minVal;
     for (int i=0;i<nums.size();i++)
     {
          nums[i]+=offset;
     }

     //找到最大值
     int maxVal=*max_element(nums.begin(),nums.end());
     //根据最大值找到最高位数
     int count=0;
     while (maxVal>0)
     {
          maxVal/=10;
          count++;
     }

     //对每一位进行计数排序
     for (int k=0;k<count;k++)
     {
          countSort(nums,k);
     }

     //还原nums数组
     for (int i=0;i<nums.size();i++)
     {
          nums[i]-=offset;
     }
}

void RadixSort_LSD::countSort(vector<int> &nums, int k)
{
     //创建count数组，大小为10，记录nums的元素的第k位出现的次数
     vector<int> count(10,0);
     for (int num:nums)
     {
          int digit=(num/static_cast<int>(pow(10,k)))%10;
          count[digit]++;
     }
     //累加count数组
     for (int i=1;i<count.size();i++)
     {
          count[i]+=count[i-1];
     }
     //创建output数组，把根据第k位排序后的结果放在output
     vector<int> output(nums.size());
     for (int i=nums.size()-1;i>=0;i--)
     {
          int digit=(nums[i]/static_cast<int>(pow(10,k)))%10;
          output[count[digit]-1]=nums[i];
          count[digit]--;
     }
     //把output赋值给nums，完成排序
     nums=output;
}

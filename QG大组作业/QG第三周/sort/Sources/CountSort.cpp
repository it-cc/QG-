//
// Created by k on 25-3-29.
//

#include "CountSort.h"


void CountSort::sort(vector<int> &nums)
{
     if (nums.empty())
     {
          cerr<<"数组为空，无法排序！"<<endl;
          return;
     }
     //利用算法库下的函数寻找最大值和最小值
     int minVal=*min_element(nums.begin(),nums.end());
     int maxVal=*max_element(nums.begin(),nums.end());
     //偏移量
     int offset=-minVal;
     vector<int> count(maxVal-minVal+1);
     //记录nuns中元素出现的次数
     for (int num:nums)
     {
          count[num+offset]++;
     }
     //累加count数组
     for (int i=1;i<count.size();i++)
     {
          count[i]+=count[i-1];
     }
     //需要一个output数组来寻找元素排序后的位置
     vector<int> output(nums.size());
     for (int i=output.size()-1;i>=0;i--)
     {
          output[count[nums[i]+offset]-1] = nums[i];
          count[nums[i]+offset]--;
     }
     nums=output;
}

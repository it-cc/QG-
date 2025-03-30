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
     int minVal=*min_element(nums.begin(),nums.end());
     int maxVal=*max_element(nums.begin(),nums.end());
     int offset=-minVal;
     vector<int> count(maxVal-minVal+1);
     for (int num:nums)
     {
          count[num+offset]++;
     }
     for (int i=1;i<count.size();i++)
     {
          count[i]+=count[i-1];
     }
     vector<int> output(nums.size());
     for (int i=output.size()-1;i>=0;i--)
     {
          output[count[nums[i]+offset]-1] = nums[i];
          count[nums[i]+offset]--;
     }
     nums=output;
}

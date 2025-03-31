

#include "QuickSort.h"


void QuickSort::quickSort(vector<int> &nums, int low, int high)
{
     if (low>=high) return;
     int pivotIndex=partition(nums,low,high);
     quickSort(nums,low,pivotIndex-1);
     quickSort(nums,pivotIndex+1,high);
}

void QuickSort::sort(vector<int> &nums)
{
     if (nums.empty())
     {
          cerr<<"数组为空，无法排序！"<<endl;
          return;
     }
     quickSort(nums,0,nums.size()-1);
}

int QuickSort::partition(vector<int> &nums, int low, int high)
{
     //两个随机索引
     int randomLeft = low+rand() % (high-low + 1);
     int randomRight = low+rand() % (high-low + 1);
     if (randomLeft > randomRight)
     {
          swap(randomLeft, randomRight);
     }
     //选择中位数
     int pivotIndex = medianOfThree(nums, randomLeft, randomRight);
     swap(nums[low], nums[pivotIndex]);

     int pivot = nums[low];

     int i = low + 1, j = high;
     while (true)
     {
          while (i <= high && nums[i] < pivot) i++;
          while (j >= low + 1 && nums[j] > pivot) j--;
          if (i >= j) break;//此时不需要交换元素了
          swap(nums[i], nums[j]);
          //防止死循环
          i++;
          j--;
     }
     swap(nums[low], nums[j]);//把pivot交换到正确的位置
     return j;
}

void QuickSort::swap(int &a, int &b)
{
     int temp = a;
     a = b;
     b = temp;
}

//三枢轴优化，返回三个数的中间值
int QuickSort::medianOfThree(vector<int> &nums, int left, int right)
{
     int mid = left + (right - left) / 2;
     if ((nums[left] <= nums[mid] && nums[mid] <= nums[right]) || (nums[right] <= nums[mid] && nums[mid] <= nums[left]))
     {
          return mid;
     }
     else if ((nums[mid] <= nums[left] && nums[left] <= nums[right]) || (nums[right] <= nums[left] && nums[left] <= nums[mid]))
     {
          return left;
     }
     else
     {
          return right;
     }
}



#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class QuickSort
{
public:
     static void quickSort(vector<int> &nums,int low,int high);

     static void sort(vector<int> &nums);

     static int partition(vector<int> &nums,int low,int high);

     static void swap(int &a,int &b);

     static int medianOfThree(vector<int>& nums, int left, int right);
};



#endif //QUICKSORT_H

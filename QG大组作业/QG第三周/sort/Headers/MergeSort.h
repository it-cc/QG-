//
// Created by k on 25-3-29.
//

#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>
#include <iostream>
using namespace std;

class MergeSort
{
public:
     static vector<int> temp;

     static void sort(vector<int> &nums);

     static void mergeSort(vector<int> &nums,int low,int high);

     static void merge(vector<int> &nums,int low,int mid, int high);
};


#endif //MERGESORT_H

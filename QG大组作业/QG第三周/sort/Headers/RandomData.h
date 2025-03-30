

#ifndef RANDOMDATA_H
#define RANDOMDATA_H
#include <vector>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;


class RandomData
{
public:
     //生成大数据量
     static vector<int> generateRandomData(int size);

     //大数据量计时
     template<typename SortFunc>
     static long long testSortTime(vector<int>& data, SortFunc sortFunc);

     //大量小数据量计时
     template<typename SortFunc>
     static long long testLargeAmountOfSmallDataSortTime(vector<vector<int>>& allData, SortFunc sortFunc);


     //生成 100*size 个数据
     static vector<vector<int>> generateLargeAmountOfSmallData(int size);

};


template<typename SortFunc>
long long RandomData::testSortTime(vector<int>& data, SortFunc sortFunc)
{
     if (data.empty())
     {
          throw invalid_argument("大数据量的数组为空！");
     }
     vector<int> copyData = data;
     auto start = chrono::high_resolution_clock::now();
     sortFunc(data);  // 调用传入的排序函数
     auto end = chrono::high_resolution_clock::now();
     return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

template<typename SortFunc>
long long RandomData::testLargeAmountOfSmallDataSortTime(vector<vector<int>> &allData, SortFunc sortFunc)
{
     if (allData.empty())
     {
          throw invalid_argument("数组为空！");
     }
     vector<vector<int>> copyAllData = allData;
     auto start = chrono::high_resolution_clock::now();
     for (vector<int>& data : copyAllData)
     {
          sortFunc(data);// 调用传入的排序函数
     }
     auto end = chrono::high_resolution_clock::now();
     return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
#endif //RANDOMDATA_H

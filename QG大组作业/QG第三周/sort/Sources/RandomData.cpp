//
// Created by k on 25-3-29.
//

#include "RandomData.h"

vector<int> RandomData::generateRandomData(int size)
{
     vector<int> data(size);

     random_device rd;
     mt19937 gen(rd());
     uniform_int_distribution<> dis(-50000, 50000);
     for (int i = 0; i < size; ++i)
     {
          data[i] = dis(gen);;
     }
     return data;
}


vector<vector<int>> RandomData::generateLargeAmountOfSmallData(int size)
{
     vector<vector<int>> allData;

     allData.reserve(size);

     for (int i = 0; i < size; i++)
     {
          allData.push_back(generateRandomData(100));
     }
     cout<<"成功生成！"<<endl;
     return allData;
}



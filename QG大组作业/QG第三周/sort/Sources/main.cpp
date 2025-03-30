#include <iostream>
#include "InsertSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RandomData.h"
#include "CountSort.h"
#include "RadixSort_LSD.h"
#include "Menu.h"
#include "SaveAndReadFile.h"


int main()
{
     srand(time(nullptr));
     vector<int> data;
     vector<vector<int>> allData;
     long long timeInsertSort;
     long long timeQuickSort;
     long long timeMergeSort;
     long long timeCountSort;
     long long timeRadixSort_LSD;
     while(true)
     {
          Menu::menu();
          cout<<"请输入你的选择：";
          int option;
          cin>>option;
          switch(option)
          {
               case 1:
                    data=RandomData::generateRandomData(10000);
                    cout<<"生成成功！"<<endl;
                    break;
               case 2:
                    data=RandomData::generateRandomData(50000);
                    cout<<"生成成功！"<<endl;
                    break;
               case 3:
                    data=RandomData::generateRandomData(200000);
                    cout<<"生成成功！"<<endl;
                    break;
               case 4:
                    allData=RandomData::generateLargeAmountOfSmallData(100000);
                    break;
               case 5:
                    //不同的大数据量
                    try
                    {
                         timeInsertSort = RandomData::testSortTime(data,InsertSort::sort);
                         cout << "大数据量下，插入排序耗时: " << timeInsertSort << "ms\n";
                         shuffle(data.begin(), data.end(), default_random_engine());
                         cout<<"成功打乱大数据量数组！可重复排序"<<endl;
                    }
                    catch(const invalid_argument &e)
                    {
                         cerr<<e.what()<<endl;
                    }

                    //大量小数据量
                    if (!allData.empty())
                    {
                         timeInsertSort=RandomData::testLargeAmountOfSmallDataSortTime(allData,InsertSort::sort);
                         cout << "大量小数据量下，插入排序耗时: " << timeInsertSort << "ms\n";
                         for (auto &arr:allData)
                         {
                              shuffle(arr.begin(), arr.end(), default_random_engine());
                         }
                         cout<<"成功打乱大量小数据量的数组！可重复排序"<<endl;
                    }
                    break;
               case 6:
                    //不同的大数据量
                    try
                    {
                         timeQuickSort = RandomData::testSortTime(data,QuickSort::sort);
                         cout << "大数据量下，快速排序耗时: " << timeQuickSort << "ms\n";
                         shuffle(data.begin(), data.end(), default_random_engine());
                         cout<<"成功打乱大数据量数组！可重复排序"<<endl;
                    }
                    catch(const invalid_argument &e)
                    {
                         cerr<<e.what()<<endl;
                    }

                    //大量小数据量
                    if (!allData.empty())
                    {
                         timeQuickSort=RandomData::testLargeAmountOfSmallDataSortTime(allData,QuickSort::sort);
                         cout << "大量小数据量下，快速排序耗时: " << timeQuickSort << "ms\n";
                         for (auto &arr:allData)
                         {
                              shuffle(arr.begin(), arr.end(), default_random_engine());
                         }
                         cout<<"成功打乱大量小数据量的数组！可重复排序"<<endl;
                    }
                    break;
               case 7:
                    //不同的大数据量
                    try
                    {
                         timeMergeSort = RandomData::testSortTime(data,MergeSort::sort);
                         cout << "大数据量下，归并排序耗时: " << timeMergeSort << "ms\n";
                         shuffle(data.begin(), data.end(), default_random_engine());
                         cout<<"成功打乱大数据量数组！可重复排序"<<endl;
                    }
                    catch(const invalid_argument &e)
                    {
                         cerr<<e.what()<<endl;
                    }

                    //大量小数据量
                    if (!allData.empty())
                    {
                         timeMergeSort=RandomData::testLargeAmountOfSmallDataSortTime(allData,MergeSort::sort);
                         cout << "大量小数据量下，归并排序耗时: " << timeMergeSort << "ms\n";
                         for (auto &arr:allData)
                         {
                              shuffle(arr.begin(), arr.end(), default_random_engine());
                         }
                         cout<<"成功打乱大量小数据量的数组！可重复排序"<<endl;
                    }
                    break;
               case 8:
                    //不同的大数据量
                    try
                    {
                         timeCountSort=RandomData::testSortTime(data,CountSort::sort);
                         cout << "大数据量下，计数排序耗时: " << timeCountSort << "ms\n";
                         shuffle(data.begin(), data.end(), default_random_engine());
                         cout<<"成功打乱大数据量数组！可重复排序"<<endl;
                    }
                    catch(const invalid_argument &e)
                    {
                         cerr<<e.what()<<endl;
                    }

                    //大量小数据量
                    if (!allData.empty())
                    {
                         timeCountSort=RandomData::testLargeAmountOfSmallDataSortTime(allData,CountSort::sort);
                         cout << "大量小数据量下，计数排序耗时: " << timeMergeSort << "ms\n";
                         for (auto &arr:allData)
                         {
                              shuffle(arr.begin(), arr.end(), default_random_engine());
                         }
                         cout<<"成功打乱大量小数据量的数组！可重复排序"<<endl;
                    }
                    break;
               case 9:
                    //不同的大数据量
                    try
                    {
                         timeRadixSort_LSD=RandomData::testSortTime(data,RadixSort_LSD::sort);
                         cout << "大数据量下，基数排序耗时: " << timeRadixSort_LSD << "ms\n";
                         shuffle(data.begin(), data.end(), default_random_engine());
                         cout<<"成功打乱大数据量数组！可重复排序"<<endl;
                    }
                    catch(const invalid_argument &e)
                    {
                         cerr<<e.what()<<endl;
                    }

                    //大量小数据量
                    if (!allData.empty())
                    {
                         timeRadixSort_LSD=RandomData::testLargeAmountOfSmallDataSortTime(allData,RadixSort_LSD::sort);
                         cout << "大量小数据量下，基数排序耗时: " << timeRadixSort_LSD << "ms\n";
                         for (auto &arr:allData)
                         {
                              shuffle(arr.begin(), arr.end(), default_random_engine());
                         }
                         cout<<"成功打乱大量小数据量的数组！可重复排序"<<endl;
                    }
                    break;
               case 10:
                    //保存文件
                    SaveAndReadFile::saveData(data);
                    break;
               case 11:
                    //读取文件
                    SaveAndReadFile::readData(data);
                    break;
               case 12:
                    //清空数据
                    data.clear();
                    allData.clear();
                    cout<<"数据已清空"<<endl;
                    break;
               case 13:
                    //退出系统
                    cout<<"欢迎下次使用！"<<endl;
                    system("pause");
                    return 0;
          }
          system("pause");
          system("cls");
     }


     return 0;
}
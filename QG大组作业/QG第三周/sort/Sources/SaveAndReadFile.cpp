//
// Created by k on 25-3-30.
//

#include "SaveAndReadFile.h"

void SaveAndReadFile::saveData(const vector<int>& data)
{
     ofstream file;
     file.open("data.txt");
     if (file.is_open())
     {
          for (auto num:data)
          {
               file<<num<<' ';
          }
          file.close();
          cout<<"数据保存成功！"<<endl;
     }
     else
     {
          cerr<<"文件打开失败！"<<endl;
     }
}

void SaveAndReadFile::readData(vector<int>& data)
{
     ifstream file;
     file.open("data.txt");
     if (file.is_open())
     {
          int num;
          while (file>>num)
          {
               data.push_back(num);
          }
          file.close();
          cout<<"数据读取成功！"<<endl;
     }
     else
     {
          cerr<<"文件打开失败"<<endl;
     }
}

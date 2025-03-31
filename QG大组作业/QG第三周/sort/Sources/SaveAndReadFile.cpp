//
// Created by k on 25-3-30.
//

#include "SaveAndReadFile.h"

//保存文件
void SaveAndReadFile::saveData(const vector<int>& data)
{
     ofstream file;
     file.open("data.txt");
     if (file.is_open())
     {
          //保存数据
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

//读取文件
void SaveAndReadFile::readData(vector<int>& data)
{
     ifstream file;
     file.open("data.txt");
     if (file.is_open())
     {
          int num;
          //读取数据
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

//
// Created by k on 25-3-30.
//

#ifndef SAVEANDREADFILE_H
#define SAVEANDREADFILE_H
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class SaveAndReadFile
{
public:
     static void saveData(const vector<int>& data);//保存数据（只保存大数据量）

     static void readData(vector<int>& data);//读取数据

};



#endif //SAVEANDREADFILE_H

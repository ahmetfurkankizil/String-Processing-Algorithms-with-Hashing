/**
* Title: Hash Table
* Author : Ahmet Furkan KIZIL
* ID: 22203112
* Section : 3
* Homework : 3
* Description : Subtask1.h file
* */

#ifndef HOMEWORK3_SUBTASK1_H
#define HOMEWORK3_SUBTASK1_H
#include <iostream>
#include <fstream>
using namespace std;
#include "HashTable.h"
#include <cctype> // For toLower function

class Subtask1 {
public:
    Subtask1(string fileName);
    int performSubtask1();

private:
    int tableSize;
    string fileName;
};


#endif //HOMEWORK3_SUBTASK1_H

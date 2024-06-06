/**
* Title: Hash Table
* Author : Ahmet Furkan KIZIL
* ID: 22203112
* Section : 3
* Homework : 3
* Description : Subtask2.h file
* */
#ifndef HOMEWORK3_SUBTASK2_H
#define HOMEWORK3_SUBTASK2_H
#include <iostream>
#include <fstream>
#include <tuple>
#include <algorithm> // Sorting
#include <limits>  // For the MAX_INT value
#include <cctype> // For toLower function
using namespace std;

class Subtask2 {
public:
    Subtask2(string fileName);
    pair <long long, long long> hashForSubtask2(const string &key);
    void performSubtask2();
    int binarySearch(tuple<pair<long long, long long>, int> tupleArray[], int smallestIndex, int numberOfPatterns, pair<long long, long long> hashPair);

private:
    string text;
    string fileName;
    int numberOfPatterns;
};


#endif //HOMEWORK3_SUBTASK2_H

/**
* Title: Hash Table
* Author : Ahmet Furkan KIZIL
* ID: 22203112
* Section : 3
* Homework : 3
* Description : Subtask3.h file
* */

#ifndef HOMEWORK3_SUBTASK3_H
#define HOMEWORK3_SUBTASK3_H
#include <cctype> // For toLower function
#include <iostream>
#include <fstream>

#include <algorithm> // for std::sort (TA said we can use it in the forums,
                     // I only used it for the sorting individual strings before
                     // calculating their hash function
using namespace std;

struct Node{
    string value;
    Node* next;
    Node(const string& value) : value(value), next(nullptr) {}
};

class Subtask3 {
public:
    Subtask3(string fileName);
    void performSubtask3();
    long long hashForSubtask3(const string &key);
    bool reverseViaHashCheck(string &first, string &second);
    bool shiftingViaHashCheck(string &first, string &second);
    void insertItem(int hashValue, const string &key);
    void printTableForDebug();

private:
    Node** hashTable;
    int tableSize;
    string fileName;
};


#endif //HOMEWORK3_SUBTASK3_H

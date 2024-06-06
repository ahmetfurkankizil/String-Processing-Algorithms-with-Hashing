/**
* Title: Hash Table
* Author : Ahmet Furkan KIZIL
* ID: 22203112
* Section : 3
* Homework : 3
* Description : HashTable.h file
* */

#ifndef HOMEWORK3_HASHTABLE_H
#define HOMEWORK3_HASHTABLE_H

#include <iostream>
#include <fstream>
#include <cctype>  // For toLower function
using namespace std;

struct Node{
    string value;
    Node* next;
    Node(const string& value) : value(value), next(nullptr) {}
};

class HashTable {

private:
    string fileName;
    int tableSize;

public:
    Node** hashTable;
    HashTable(int tableSize);
    int hash(const string &key);
    void insertItem(int hashValue, const string &key);
    void printTable();


};


#endif //HOMEWORK3_HASHTABLE_H

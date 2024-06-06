/**
* Title: Hash Table
* Author : Ahmet Furkan KIZIL
* ID: 22203112
* Section : 3
* Homework : 3
* Description : HashTable.cpp file
* */

#include "HashTable.h"
using namespace std;

HashTable::HashTable(int tableSize) {
    this->tableSize = tableSize;
    this->hashTable = new Node*[tableSize];

    // Initialising the HashTable
    for (int i = 0; i < this->tableSize; ++i) {
        hashTable[i] = nullptr;
    }
}

int HashTable::hash(const string &key) {
    int hashVal = 0;
    string lowerKey = key;
    for (char &c : lowerKey) {
        c = tolower(c);
    }
    for (int i = 0; i < lowerKey.length(); i++)
        hashVal = 37 * hashVal + lowerKey[i];

    hashVal %= tableSize;
    if (hashVal < 0)
        hashVal += this->tableSize;

    return hashVal;
}

void HashTable::insertItem(int hashValue, const string &key) {
    Node* newNode = new Node(key);
    if (hashTable[hashValue] == nullptr) {
        hashTable[hashValue] = newNode;
    } else {
        Node* current = hashTable[hashValue];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// For debugging purposes
void HashTable::printTable() {
    for (int i = 0; i < tableSize; ++i) {
        cout << i << ". bucket:";
        Node* current = hashTable[i];
        while (current != nullptr) {
            cout << " " << current->value << " -> ";
            current = current->next;
        }
        cout << endl;
    }
}
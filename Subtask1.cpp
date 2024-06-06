/**
* Title: Hash Table
* Author : Ahmet Furkan KIZIL
* ID: 22203112
* Section : 3
* Homework : 3
* Description : Subtask1.cpp file
* */

#include "Subtask1.h"


int main(int argc, char** argv) {

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    Subtask1 subtask1(filename);
    cout << subtask1.performSubtask1();

    return 0;
}

Subtask1::Subtask1(string fileName) {
    this->fileName = fileName;
}

int Subtask1::performSubtask1() {

    int answer = 0;

    ifstream file1(this->fileName);
    int sizeOfTable;
    file1 >> sizeOfTable;

    // Mod value is selected according to the suggestions of the TA in the forums (based on the test cases)
    this->tableSize = 100007;
    HashTable hashtable(this->tableSize);

    string uniqueString1;
    while(file1 >> uniqueString1) {
        string lowerKey = uniqueString1;
        for (char &c : lowerKey) {
            c = tolower(c);
        }
        // For debugging purposes
        int hashValue = hashtable.hash(lowerKey);
        //cout << uniqueString1 << " has hash value of: " << hashValue << endl;
        hashtable.insertItem(hashValue, lowerKey);
    }

    ifstream file2(fileName);
    file2 >> this->tableSize;
    string uniqueString2;
    // Each unique entry is processed
    while(file2 >> uniqueString2) {
        string lowerKey = uniqueString2;
        for (char &c : lowerKey) {
            c = tolower(c);
        }
        // For the control of the prefixes
        for (int i = 0; i < lowerKey.length()-1; ++i) {
            string prefix = lowerKey.substr(0, i + 1);
            //cout << "Value of prefix = " << prefix << endl;
            int hashValueOfPrefix = hashtable.hash(prefix);
            if (hashtable.hashTable[hashValueOfPrefix] != nullptr) {
                // SEPARATE CHAINING : Traversing through the linked list
                Node* temp = hashtable.hashTable[hashValueOfPrefix];
                while (temp != nullptr) {
                    if (temp->value == prefix) {
                        // Debugging purpose
                        //cout << "Value of prefix = " << prefix << " | Value of unique string = " << uniqueString2 << endl;
                        answer++;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }

        // For the control of the suffixes
        for (int i = 1; i < lowerKey.length(); ++i) {
            string suffix = lowerKey.substr(i);
            //cout << "Value of suffix = " << suffix << endl;
            int hashValueOfSuffix = hashtable.hash(suffix);
            if (hashtable.hashTable[hashValueOfSuffix] != nullptr) {
                // SEPARATE CHAINING : Traversing through the linked list
                Node* temp = hashtable.hashTable[hashValueOfSuffix];
                while (temp != nullptr) {
                    if (temp->value == suffix) {
                        //cout << "Value of prefix = " << suffix << " | Value of unique string = " << uniqueString2 << endl;
                        answer++;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
    }
    return answer;
}

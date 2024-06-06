/**
* Title: Hash Table
* Author : Ahmet Furkan KIZIL
* ID: 22203112
* Section : 3
* Homework : 3
* Description : Subtask3.cpp file
* */
#include "Subtask3.h"


int main(int argc, char** argv) {

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    Subtask3 subtask3(filename);
    subtask3.performSubtask3();

    return 0;
}


/*
int main(){
    string fileName = "/Users/ahmetfurkankizil/Desktop/subtask3 check/log3.txt";
    Subtask3 subtask3(fileName);
    subtask3.performSubtask3();
    //subtask3.printTableForDebug();
}
*/

Subtask3::Subtask3(std::string fileName) {
    this->fileName = fileName;
}

void Subtask3::performSubtask3() {

    ifstream file1(this->fileName);
    int sizeOfTable;
    file1 >> sizeOfTable;
    this->tableSize = sizeOfTable;
    long long hashTableSize = 1000007;

    this->hashTable = new Node*[hashTableSize];

    // Initialising the HashTable
    for (int i = 0; i < this->tableSize; ++i) {
        hashTable[i] = nullptr;
    }

    string stringArray[this->tableSize];
    for (int i = 0; i < this->tableSize; ++i) {
        stringArray[i] = "";
    }

    string uniqueString1;
    int indexOfThePattern = 0;
    while(file1 >> uniqueString1) {
        string lowerKey = uniqueString1;
        for (char &c : lowerKey) {
            c = tolower(c);
        }
        stringArray[indexOfThePattern] = lowerKey;
        insertItem(hashForSubtask3(lowerKey), lowerKey);
        indexOfThePattern++;
    }
    //cout << "Debug" << endl;

    int minimumSubset = 0;
    int numberOfReverseOperations = 0;

    for (int i = 0; i < 1000007; ++i) {
        if (hashTable[i] != nullptr) {
            Node *temp = hashTable[i];
            minimumSubset++;
            Node *tempSecond = temp;

            while (tempSecond->next != nullptr) {
                tempSecond = tempSecond->next;
                if(shiftingViaHashCheck(temp->value, tempSecond->value)) {

                } else if (reverseViaHashCheck(temp->value, tempSecond->value)) {
                    numberOfReverseOperations++;
                } else {
                    minimumSubset++;
                }
            }
        }
    }

    cout << numberOfReverseOperations << endl;
    cout << minimumSubset;
}

long long Subtask3::hashForSubtask3(const std::string &key) {
    long long mod = 1000007;

    long long hashValue = 0;

    string lowerKey = key;
    for (char &c : lowerKey) {
        c = tolower(c);
    }

    std::sort(lowerKey.begin(), lowerKey.end());

    for (int i = 0; i < lowerKey.length(); i++) {
        hashValue = (hashValue * 256 + lowerKey[i]) % mod;
    }

    hashValue = hashValue % mod;
    return hashValue;
}

bool Subtask3::reverseViaHashCheck(string &first, string &second) {
    int lenFirst = first.size();
    int lenSecond = second.size();

    if (lenFirst != lenSecond) {
        return false;
    } else {
        long long hashOfFirst = hashForSubtask3(first);
        string reversed;
        for (int i = second.size() - 1; i >= 0; --i) {
            reversed.push_back(second[i]);
        }
        long long hashOfSecondReversed = hashForSubtask3(reversed);
        if (hashOfFirst == hashOfSecondReversed) {
            return true;
        } else {
            return false;
        }
    }

}

bool Subtask3::shiftingViaHashCheck(string &first, string &second) {
    int lenFirst = first.size();
    int lenSecond = second.size();

    if (lenFirst != lenSecond) {
        return false;
    } else {
        for (int i = 0; i < lenSecond; ++i) {
            string shifted = second.substr(i) + second.substr(0, i);
            if(first == shifted) {
                return true;
            }
        }
    }
    return false;
}

void Subtask3::insertItem(int hashValue, const std::string &key) {
    Node* newNode = new Node(key);
    if (this->hashTable[hashValue] == nullptr) {
        this->hashTable[hashValue] = newNode;
    } else {
        Node* current = this->hashTable[hashValue];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void Subtask3::printTableForDebug() {
    for (int i = 0; i < 1000007; ++i) {
        if (this->hashTable[i] != nullptr) {
            cout << i << ". bucket:";
            Node* current = hashTable[i];
            while (current != nullptr) {
                cout << " " << current->value << " -> ";
                current = current->next;
            }
        }
    }
}


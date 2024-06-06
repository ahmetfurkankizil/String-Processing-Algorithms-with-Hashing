/**
* Title: Hash Table
* Author : Ahmet Furkan KIZIL
* ID: 22203112
* Section : 3
* Homework : 3
* Description : Subtask2.cpp file
* */

#include "Subtask2.h"

int main(int argc, char** argv) {


    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    Subtask2 subtask1(filename);
    subtask1.performSubtask2();



    /*
    string st2File = "/Users/ahmetfurkankizil/Desktop/check/log2.txt";

    Subtask2 subtask2(st2File);
    subtask2.performSubtask2();

    return 0;
     */
}



Subtask2::Subtask2(string fileName) {
    this->fileName = fileName;
}

pair<long long, long long> Subtask2::hashForSubtask2(const std::string &key) {
    long long mod1 = 1000000007;
    long long mod2 = 1000000009;

    long long hash1Value = 0;
    long long hash2Value = 0;

    string lowerKey = key;
    for (char &c : lowerKey) {
        c = tolower(c);
    }

    for (int i = 0; i < lowerKey.length(); i++) {
        hash1Value = (37 * hash1Value + lowerKey[i]) % mod1;
        hash2Value = (37 * hash2Value + lowerKey[i]) % mod2;
    }

    return {hash1Value, hash2Value};
}

// I've gotten the logic of common Recursive Binary Search algorithm from the website: https://www.geeksforgeeks.org/cpp-binary-search/ and implemented accordingly

int Subtask2::binarySearch(tuple<pair<long long, long long>, int> *tupleArray, int smallestIndex, int numberOfPatterns,
                           pair<long long, long long> hashPair) {

    if (numberOfPatterns >= smallestIndex) {
        int middle = smallestIndex + (numberOfPatterns - smallestIndex) / 2;
        pair <long long, long long> currentHashPair = get<0>(tupleArray[middle]);

        if (currentHashPair == hashPair) {
            // The id of the string is retrieved.
            return get<1>(tupleArray[middle]);
        } else if (currentHashPair > hashPair) {
            return binarySearch(tupleArray, smallestIndex, (middle - 1), hashPair);
        } else {
            return binarySearch(tupleArray, (middle + 1), numberOfPatterns, hashPair);
        }
    }

    // Not found
    return -1;
}


void Subtask2::performSubtask2() {

    ifstream file1(fileName);
    string inputText;
    file1 >> inputText;
    string lowerText = inputText;
    for (char &c : inputText) {
        c = tolower(c);
    }
    this->text = lowerText;

    int numberOfUniquePatterns;
    file1 >> numberOfUniquePatterns;
    this->numberOfPatterns = numberOfUniquePatterns;

    tuple<pair<long long, long long>, int> tupleArray[numberOfPatterns];
    int frequencyArray[numberOfPatterns];

    // Initializing frequency array
    for (int i = 0; i < numberOfPatterns; ++i) {
        frequencyArray[i] = 0;
    }

    // Initialising tuple array
    for (int i = 0; i < numberOfPatterns; ++i) {
        tupleArray[i] = make_tuple(make_pair(0LL, 0LL), 0);
    }

    string uniqueString1;
    int indexOfThePattern = 0;
    long long lengthOfShortestPattern = numeric_limits<long long>::max();
    // Tuple array is generated
    while(file1 >> uniqueString1) {
        string lowerKey = uniqueString1;
        for (char &c : lowerKey) {
            c = tolower(c);
        }
        // Determining the shortest pattern
        if (lowerKey.length() < lengthOfShortestPattern) {
            lengthOfShortestPattern = lowerKey.length();
        }
        tupleArray[indexOfThePattern] = make_tuple(hashForSubtask2(lowerKey),indexOfThePattern);
        indexOfThePattern++;
    }

    sort(tupleArray, tupleArray + numberOfPatterns);

    // For debugging purposes
    /*
     * cout << "Sorted Array: " << endl;
    for (int i = 0; i < numberOfPatterns; ++i) {
        cout << "TupleArray " << "[" << i << "] : " << get<0>(get<0>(tupleArray[i])) << ", " << get<1>(get<0>(tupleArray[i])) << ", " << get<1>(tupleArray[i]) << endl;
    }
     */


    for (int i = 0; i <= (this->text.length() - (lengthOfShortestPattern)); ++i) {
        string individualPattern = this->text.substr(i, lengthOfShortestPattern);
        pair <long long, long long> hashPair = hashForSubtask2(individualPattern);
        int searchResult = binarySearch(tupleArray, 0, this->numberOfPatterns, hashPair);
        if (searchResult != -1) {
            frequencyArray[searchResult]++;
        } else {
            //cout << "Not found in the text" << endl;
        }
    }

    for (int i = 0; i <= (this->text.length() - (lengthOfShortestPattern+1)); ++i) {
        string individualPattern = this->text.substr(i, (lengthOfShortestPattern+1));
        //cout << "Pattern: " << individualPattern << " | Hash Values: " << get<0>(hashForSubtask2(individualPattern)) << ", " << get<1>(hashForSubtask2(individualPattern)) << endl;
        pair <long long, long long> hashPair = hashForSubtask2(individualPattern);
        int searchResult = binarySearch(tupleArray, 0, this->numberOfPatterns, hashPair);
        //cout << i << ".st pattern" << endl;
        if (searchResult != -1) {
            frequencyArray[searchResult]++;
            //cout << "The id: " << searchResult << " is found in the text" << endl;
        } else {
            //cout << "Not found in the text" << endl;
        }
    }

    for (int i = 0; i <= (this->text.length() - (lengthOfShortestPattern+2)); ++i) {
        string individualPattern = this->text.substr(i, (lengthOfShortestPattern+2));
        //cout << "Pattern: " << individualPattern << " | Hash Values: " << get<0>(hashForSubtask2(individualPattern)) << ", " << get<1>(hashForSubtask2(individualPattern)) << endl;
        pair <long long, long long> hashPair = hashForSubtask2(individualPattern);
        int searchResult = binarySearch(tupleArray, 0, this->numberOfPatterns, hashPair);
        //cout << i << ".st pattern" << endl;
        if (searchResult != -1) {
            frequencyArray[searchResult]++;
            //cout << "The id: " << searchResult << " is found in the text" << endl;
        } else {
            //cout << "Not found in the text" << endl;
        }
    }

    for (int i = 0; i <= (this->text.length() - (lengthOfShortestPattern+3)); ++i) {
        string individualPattern = this->text.substr(i, (lengthOfShortestPattern+3));
        //cout << "Pattern: " << individualPattern << " | Hash Values: " << get<0>(hashForSubtask2(individualPattern)) << ", " << get<1>(hashForSubtask2(individualPattern)) << endl;
        pair <long long, long long> hashPair = hashForSubtask2(individualPattern);
        int searchResult = binarySearch(tupleArray, 0, this->numberOfPatterns, hashPair);
        //cout << i << ".st pattern" << endl;
        if (searchResult != -1) {
            frequencyArray[searchResult]++;
            //cout << "The id: " << searchResult << " is found in the text" << endl;
        } else {
            //cout << "Not found in the text" << endl;
        }
    }

    for (int i = 0; i <= (this->text.length() - (lengthOfShortestPattern+4)); ++i) {
        string individualPattern = this->text.substr(i, (lengthOfShortestPattern+4));
        //cout << "Pattern: " << individualPattern << " | Hash Values: " << get<0>(hashForSubtask2(individualPattern)) << ", " << get<1>(hashForSubtask2(individualPattern)) << endl;
        pair <long long, long long> hashPair = hashForSubtask2(individualPattern);
        int searchResult = binarySearch(tupleArray, 0, this->numberOfPatterns, hashPair);
        //cout << i << ".st pattern" << endl;
        if (searchResult != -1) {
            frequencyArray[searchResult]++;
            //cout << "The id: " << searchResult << " is found in the text" << endl;
        } else {
            //cout << "Not found in the text" << endl;
        }
    }

    for (int i = 0; i <= (this->text.length() - (lengthOfShortestPattern+5)); ++i) {
        string individualPattern = this->text.substr(i, (lengthOfShortestPattern+5));
        //cout << "Pattern: " << individualPattern << " | Hash Values: " << get<0>(hashForSubtask2(individualPattern)) << ", " << get<1>(hashForSubtask2(individualPattern)) << endl;
        pair <long long, long long> hashPair = hashForSubtask2(individualPattern);
        int searchResult = binarySearch(tupleArray, 0, this->numberOfPatterns, hashPair);
        //cout << i << ".st pattern" << endl;
        if (searchResult != -1) {
            frequencyArray[searchResult]++;
            //cout << "The id: " << searchResult << " is found in the text" << endl;
        } else {
            //cout << "Not found in the text" << endl;
        }
    }

    //cout << "Frequencies: " << endl;
    for (int i = 0; i < numberOfUniquePatterns; ++i) {
        cout << frequencyArray[i] << endl;
    }

}
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);

    set<int> dictFirst, dictSecond;
    int currentNumber;
    while (ss >> currentNumber) {
        dictFirst.insert(currentNumber);
    }
    getline(cin, input);
    ss = stringstream (input);
    while (ss >> currentNumber) {
        dictSecond.insert(currentNumber);
    }

    vector<char> intersection;
    set_intersection(dictFirst.begin(), dictFirst.end(), dictSecond.begin(), dictSecond.end(),
                     back_inserter(intersection));

    cout << intersection.size();
    return 0;
}
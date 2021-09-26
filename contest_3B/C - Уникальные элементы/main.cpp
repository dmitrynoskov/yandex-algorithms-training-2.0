#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    vector<int> inputSequence;
    unordered_map<int, int> dict;
    int currentNumber;
    while(cin >> currentNumber) {
        inputSequence.push_back(currentNumber);
        ++dict[currentNumber];
    }
    for (auto i : inputSequence) {
        if (dict.count(i) && dict[i] == 1){
            dict.erase(i);
            cout << i << " ";
        }
    }

    return 0;
}
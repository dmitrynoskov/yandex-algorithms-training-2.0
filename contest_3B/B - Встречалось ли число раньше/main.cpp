#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> dict;
    int currentNumber;
    while(cin >> currentNumber) {
        if (dict.count(currentNumber)) {
            cout << "YES\n";
        } else {
            dict.insert(currentNumber);
            cout << "NO\n";
        }
    }
    return 0;
}
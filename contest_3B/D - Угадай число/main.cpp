#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string input;
    set<int> positiveAnswers, negativeAnswers;
    getline(cin, input);
    stringstream ss(input);
    ss >> N;

    for (int i = 1; i <= N; ++i) {
        positiveAnswers.insert(i);
    }

    while (getline(cin, input)) {
        if (input == "HELP") {
            break;
        } else {
            ss = stringstream(input);
            getline(cin, input);
            if (input == "NO") {
                int currentNumber;
                while (ss >> currentNumber) {
                    negativeAnswers.insert(currentNumber);
                }
            } else {
                int currentNumber;
                set<int> newPositiveAnswers;
                while (ss >> currentNumber) {
                    newPositiveAnswers.insert(currentNumber);
                }
                set<int> temp;
                set_intersection(positiveAnswers.begin(), positiveAnswers.end(), newPositiveAnswers.begin(),
                                 newPositiveAnswers.end(),
                                 inserter(temp, temp.begin()));
                positiveAnswers = move(temp);
            }
        }
    }

    for (auto i: positiveAnswers) {
        if (!negativeAnswers.count(i)) {
            cout << i << " ";
        }
    }

    return 0;
}
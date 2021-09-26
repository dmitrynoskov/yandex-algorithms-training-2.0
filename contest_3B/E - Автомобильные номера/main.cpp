#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N, M;
    string input;

    getline(cin, input);
    stringstream ss(input);
    ss >> N;
    map<int, set<char>> witnessNumbers, carNumbers; // key - input index, value - formatted number
    unordered_map<int, string> cars; // key - input index, value - original number
    for (int i = 0; i < N; ++i) {
        getline(cin, input);
        for (auto c: input) {
            if (isupper(c) || isdigit(c)) {
                witnessNumbers[i].insert(c);
            }
        }
    }

    getline(cin, input);
    ss = stringstream(input);
    ss >> M;
    for (int i = 0; i < M; ++i) {
        getline(cin, input);
        for (auto c: input) {
            if (isupper(c) || isdigit(c)) {
                carNumbers[i].insert(c);
            }
        }
        cars[i] = move(input);
    }

    vector<string> answer;
    int currentMaxQuantity = 0;
    for (const auto&[carIndex, carNumber]: carNumbers) {
        int quantity = 0;
        for (const auto&[witnessIndex, witnessNumber]: witnessNumbers) {
            if (includes(carNumber.begin(), carNumber.end(), witnessNumber.begin(), witnessNumber.end())) {
                ++quantity;
            }
        }
        if (quantity > currentMaxQuantity) {
            currentMaxQuantity = quantity;
            answer = vector<string>{cars[carIndex]};
        } else if (quantity == currentMaxQuantity) {
            answer.push_back(cars[carIndex]);
        }
    }

    for (const auto& number: answer) {
        cout << number << "\n";
    }

    return 0;
}
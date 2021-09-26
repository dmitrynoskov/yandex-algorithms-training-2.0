#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    string input;
    unordered_map<string, int> wordFrequencies;
    while (getline(cin, input)) {
        stringstream ss(input);
        string word;
        while (ss >> word) {
            ++wordFrequencies[move(word)];
        }
    }

    vector<pair<string, int>> frequencies(wordFrequencies.begin(), wordFrequencies.end());
    sort(frequencies.begin(), frequencies.end(),
         [](const pair<string, int>& lhs, const auto& rhs) {
             return lhs.second > rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first);
         });

    for (const auto&[word, frequency]: frequencies) {
        cout << word << "\n";
    }

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <string>
#include <string_view>
#include <sstream>
#include <memory>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int N;
    vector<string> themes;
    string inputString;
    getline(cin, inputString);
    N = stoi(inputString);
    for (int i = 0; i < N; ++i) {
        int command;
        string input;
        getline(cin, input);
        command = stoi(input);
        if (command == 0) {
            string theme;
            getline(cin, theme);
            themes.push_back(move(theme));
        } else {
            themes.push_back(themes[command-1]);
        }
        string message;
        getline(cin, message);
    }

    unordered_map<string_view, int> themesQuantity;
    for(const auto& theme : themes) {
        ++themesQuantity[theme];
    }

    vector<string_view> possibleAnswers = {themesQuantity.begin()->first};
    int maxQuantity = themesQuantity.begin()->second;

    for(const auto& [theme, quantity] : themesQuantity) {
        if (quantity > maxQuantity) {
            maxQuantity = quantity;
            possibleAnswers = vector<string_view>{theme};
        } else if (quantity == maxQuantity) {
            possibleAnswers.push_back(theme);
        }
    }

    auto firstEntry = prev(themes.end());
    for(const auto& answer: possibleAnswers) {
        firstEntry = min(find(themes.begin(), themes.end(), answer), firstEntry);
    }

    cout << *firstEntry;

    return 0;
}
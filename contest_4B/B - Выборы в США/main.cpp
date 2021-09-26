#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <memory>

using namespace std;

int main() {
    string input;
    map<string, int> votes;
    while(getline(cin, input)) {
        stringstream ss(input);
        string name;
        int votesQuantity;
        ss >> name >> votesQuantity;
        votes[move(name)] += votesQuantity;
    }

    for(const auto& [name, quantity] : votes) {
        cout << name << " " << quantity << "\n";
    }

    return 0;
}
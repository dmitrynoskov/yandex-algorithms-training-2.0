#include <iostream>
#include <unordered_map>
#include <string>
#include <string_view>
#include <sstream>
#include <memory>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstdint>
#include <cmath>

using namespace std;


int main() {
    int numberOfSeats = 450;
    unordered_map<string, int64_t> votes;
    vector<string> parties;
    int64_t totalVotes = 0;
    string input;
    while (getline(cin, input)) {
        auto index = input.find_last_of(' ');
        string name = input.substr(0, index);
        int64_t quantity = stoi(input.substr(index+1, input.npos));
        votes[(name)] = quantity;
        parties.push_back(move(name));
        totalVotes += quantity;
    }

    double firstElectoralQuotient = static_cast<double>(totalVotes) / numberOfSeats;

    unordered_map<string_view, int64_t> seats;
    vector<pair<double, string_view>> remainder;
    for (const auto&[name, quantity]: votes) {
        int receivedSeats = trunc(votes[name] / firstElectoralQuotient);
        seats[name] = receivedSeats;
        remainder.emplace_back((votes[name] / firstElectoralQuotient) - receivedSeats, name);
        numberOfSeats -= receivedSeats;
    }

    sort(remainder.begin(), remainder.end(),
         [&](const auto& lhs, const auto& rhs) {
             return lhs.first > rhs.first ||
                    ((lhs.first == rhs.first) && votes[string(lhs.second)] > votes[string(rhs.second)]);
         });

    auto it = remainder.begin();
    while (numberOfSeats > 0 && it != remainder.end()) {
        ++seats[it->second];
        ++it;
        -- numberOfSeats;
    }

    for (const auto& party : parties) {
        cout << party << " " << seats[party] << '\n';
    }

    return 0;
}
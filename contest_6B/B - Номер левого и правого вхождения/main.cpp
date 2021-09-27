#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <tuple>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    vector<int64_t> sequence;
    sequence.reserve(N);
    for (int i = 0; i < N; ++i) {
        int64_t number;
        cin >> number;
        sequence.push_back(number);
    }
    cin >> M;
    vector<pair<int, int>> answer;
    answer.reserve(M);
    for (int i = 0; i < M; ++i) {
        int64_t number;
        cin >> number;
        auto range = equal_range(sequence.begin(), sequence.end(), number);
        if (distance(range.first, range.second) == 0) {
            answer.emplace_back(0,0);
        } else {
            answer.emplace_back(static_cast<int>(distance(sequence.begin(), range.first) + 1),
                                static_cast<int>(distance(sequence.begin(), range.second)));
        }
    }

    for (auto [left, right]: answer) {
        cout << left << " " << right << "\n";
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int main() {
    int N, K;
    cin >> N;
    vector<int64_t> sequence;
    sequence.reserve(N);
    for (int i = 0; i < N; ++i) {
        int64_t number;
        cin >> number;
        sequence.push_back(number);
    }
    sort(sequence.begin(), sequence.end());
    cin >> K;
    vector<int> answer;
    answer.reserve(K);
    for (int i = 0; i < K; ++i) {
        int64_t L, R;
        cin >> L >> R;
        auto it1 = lower_bound(sequence.begin(), sequence.end(), L);
        auto it2 = upper_bound(sequence.begin(), sequence.end(), R);
        answer.push_back(static_cast<int>(distance(it1, it2)));
    }

    for(auto i : answer) {
        cout << i << " ";
    }

    return 0;
}
#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

/*
    "левый" бинарный поиск по ответу
*/

int countN(const vector<int64_t>& seq, int l) {
    int counter = 0;
    auto right = seq.front() - 1;
    for (auto point: seq) {
        if (point > right) {
            ++counter;
            right = point + l;
        }
    }
    return counter;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int64_t> sequence;
    sequence.reserve(n);
    for (int i = 0; i < n; ++i) {
        int64_t number;
        cin >> number;
        sequence.push_back(number);
    }
    sort(sequence.begin(), sequence.end());


    int64_t left = 0;
    int64_t right = sequence.back() - sequence.front();

    while (left < right) {
        int mid = (left + right) / 2;
        if (countN(sequence, mid) <= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << "\n";

    return 0;
}
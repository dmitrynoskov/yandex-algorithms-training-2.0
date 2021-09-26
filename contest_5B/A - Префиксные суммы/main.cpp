#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int64_t> prefixSum;
    prefixSum.push_back(0);
    for(int i = 0; i < n; ++i) {
        int64_t number;
        cin >> number;
        prefixSum.push_back(prefixSum.back() + number);
    }
    vector<int64_t> answer;
    for(int i = 0; i < q; ++i) {
        int left, right;
        cin >> left >> right;
        answer.push_back(prefixSum[right] - prefixSum[left - 1]);
    }

    for (auto i : answer) {
        cout << i << '\n';
    }

    return 0;
}
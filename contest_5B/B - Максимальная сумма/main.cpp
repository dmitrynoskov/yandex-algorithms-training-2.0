#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

/*
 * Jay Kadane's algorithm
 */

int main() {
    int n;
    cin >> n;
    vector<int64_t> inputSequence;
    inputSequence.reserve(n);
    for(int i = 0; i < n; ++i) {
        int64_t number;
        cin >> number;
        inputSequence.push_back(number);
    }

    int64_t maxSum = inputSequence.front();
    int64_t currentSum = 0;

    for(auto i : inputSequence) {
        currentSum += i;
        maxSum = max(maxSum, currentSum);
        currentSum = max(static_cast<int64_t>(0), currentSum);
    }

    cout << maxSum << "\n";

    return 0;
}
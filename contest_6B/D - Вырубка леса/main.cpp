#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

/*
    "левый" бинарный поиск по ответу
*/

int main() {
    uint64_t A, K, B, M, X;
    cin >> A >> K >> B >> M >> X;
    uint64_t left = 0;
    uint64_t right = 2 * X / A + 1;
    while (left < right) {
        uint64_t mid = (left + right) / 2;
        if ((mid - (mid / K)) * A + (mid - (mid / M)) * B >= X) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << "\n";

    return 0;
}
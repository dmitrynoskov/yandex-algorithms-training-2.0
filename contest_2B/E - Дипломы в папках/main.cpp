#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    vector<int> diplomas;
    int maxDiplomasQuantity = 0;
    int counterMaxEntries = 1;
    int answer = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int quantity;
        cin >> quantity;
        diplomas.push_back(quantity);
        if(quantity > maxDiplomasQuantity) {
            maxDiplomasQuantity = quantity;
            counterMaxEntries = 1;
        } else if (quantity == maxDiplomasQuantity) {
            ++counterMaxEntries;
        }
    }

    for (auto quantity : diplomas) {
        if(quantity != maxDiplomasQuantity) {
            answer += quantity;
        }
    }

    answer += (counterMaxEntries - 1) * maxDiplomasQuantity;

    cout << answer;

    return 0;
}
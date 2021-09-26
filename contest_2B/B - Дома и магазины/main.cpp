#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<int> houseIndices;
    vector<int> shopIndices;
    int maxDistance = 0;
    for (int i = 0; i < 10; ++i) {
        int number;
        cin >> number;
        if (number == 1) {
            houseIndices.push_back(i);
        } else if (number == 2) {
            shopIndices.push_back(i);
        }
    }

    for (auto houseIndex : houseIndices) {
        int houseDistance = 9;
        for (auto shopIndex : shopIndices) {
            houseDistance = min(abs(houseIndex - shopIndex), houseDistance);
        }
        maxDistance = max(maxDistance, houseDistance);
    }

    cout << maxDistance;

    return 0;
}
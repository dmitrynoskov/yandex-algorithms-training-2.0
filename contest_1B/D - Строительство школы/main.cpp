#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> coordinates;
    for (int i = 0; i < N; ++i) {
        int coord;
        cin >> coord;
        coordinates.push_back(coord);
    }
    cout << coordinates[coordinates.size()/2];

    return 0;
}
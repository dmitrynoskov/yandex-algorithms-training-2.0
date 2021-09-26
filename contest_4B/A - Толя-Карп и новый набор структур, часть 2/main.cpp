#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

struct box {
    int64_t color;
    int64_t number;
};

int main() {
    int n;
    cin >> n;
    vector<box> boxes;
    for (int i = 0; i < n; ++i) {
        int64_t color, number;
        cin >> color >> number;
        boxes.push_back({color, number});
    }
    sort(boxes.begin(), boxes.end(), [](const box& lhs, const box& rhs) {return lhs.color < rhs.color;});

    auto it1 = boxes.begin();
    while (it1 != boxes.end()) {
        int64_t color = it1->color;
        int64_t sum = 0;
        auto it2 = it1;
        while(it2 != boxes.end() && it1->color == it2->color) {
            sum += it2->number;
            ++it2;
        }
        it1 = it2;
        cout << color << " " << sum << "\n";
    }

    return 0;
}
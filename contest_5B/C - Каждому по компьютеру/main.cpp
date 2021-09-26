#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct element {
    int capacity;
    int index;
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<element> students;
    vector<element> rooms;

    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        students.push_back({number + 1, i + 1});
    }

    for (int i = 0; i < M; ++i) {
        int number;
        cin >> number;
        rooms.push_back({number, i + 1});
    }

    sort(students.begin(), students.end(),
         [](const element& lhs, const element& rhs) { return lhs.capacity < rhs.capacity; });
    sort(rooms.begin(), rooms.end(),
         [](const element& lhs, const element& rhs) { return lhs.capacity < rhs.capacity; });

    vector<int> answer;
    answer.resize(students.size());
    int counter = 0;

    auto it1 = students.begin();
    auto it2 = rooms.begin();

    while (it1 != students.end()) {
        int index = 0;
        while (it2 != rooms.end() && (it2->capacity < it1->capacity)) {
            ++it2;
        }
        if (it2 != rooms.end()) {
            index = it2->index;
            ++counter;
            ++it2;
        }
        answer[it1->index - 1] = index;
        ++it1;
    }

    cout << counter << '\n';
    for (auto i: answer) {
        cout << i << ' ';
    }

    return 0;
}
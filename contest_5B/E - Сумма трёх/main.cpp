#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_map>

using namespace std;

vector<int64_t> getVector() {
    vector<int64_t> result;
    int size;
    cin >> size;
    result.reserve(size);
    for(int i = 0; i < size; ++i) {
        int64_t number;
        cin >> number;
        result.push_back(number);
    }
    return result;
}

unordered_map<int64_t, int> getMap() {
    unordered_map<int64_t, int> result;
    int size;
    cin >> size;
    for(int i = 0; i < size; ++i) {
        int64_t number;
        cin >> number;
        if(!result.count(number)) {
            result[number] = i;
        }
    }
    return result;
}

int main() {
    int64_t S;
    cin >> S;
    auto A = getVector();
    auto B = getVector();
    auto C = getMap();
    vector<int> answer = {-1};
    for (int i = 0; i < A.size(); ++i) {
        for(int j = 0; j < B.size(); ++j) {
            if(C.count(S - A[i] - B[j])) {
                answer = vector<int>{i, j, C[S - A[i] - B[j]]};
                i = A.size();
                j = B.size();
            }
        }
    }

    for(auto i : answer) {
        cout << i << " ";
    }

    return 0;
}
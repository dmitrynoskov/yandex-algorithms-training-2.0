#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, i, j;
    cin >> N >> i >> j;
    int greater, smaller, result;
    greater = max(i, j);
    smaller = min(i, j);
    result = min (greater - smaller - 1, N - greater + smaller - 1);
    cout << result;
    return 0;
}
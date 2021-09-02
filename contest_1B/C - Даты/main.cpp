#include <iostream>

using namespace std;

bool isValid(int day, int month) {
    return (day > 0 && day < 32) && (month > 0 && month < 13);
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    if (isValid(x, y) && isValid(y, x) && (x!=y)) {
        cout << 0;
    } else {
        cout << 1;
    }

    return 0;
}
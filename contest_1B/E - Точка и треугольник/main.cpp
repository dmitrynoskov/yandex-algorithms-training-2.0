#include <iostream>

using namespace std;

int findNearestVertex (int d, int x, int y) {
    if (x <= 0) {
        if (y <= d/2) {
            return 1;
        } else {
            return 3;
        }
    } else if (y <= 0) {
        if (x <= d/2) {
            return 1;
        } else {
            return 2;
        }
    } else {
        if (y <= x) {
            return 2;
        } else {
            return 3;
        }
    }
}

int main() {
    int d, x, y;
    cin >> d >> x >> y;

    if (x >= 0 && y >= 0 && (y + x) <= d) {
        cout << 0;
    } else {
        cout << findNearestVertex(d, x, y);
    }

    return 0;
}
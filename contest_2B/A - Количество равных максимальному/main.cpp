#include <iostream>

using namespace std;

int main() {
    int i;
    int maxElement = 0;
    int counter = 0;
    while ((cin >> i) && i != 0) {
        if (i > maxElement) {
            maxElement = i;
            counter = 1;
        } else if (i == maxElement) {
            ++counter;
        }
    }

    cout << counter;

    return 0;
}
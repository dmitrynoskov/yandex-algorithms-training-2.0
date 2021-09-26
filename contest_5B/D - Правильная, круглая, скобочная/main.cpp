#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;
    int counter = 0;
    for (auto c : input) {
        if (c == '(') {
            ++counter;
        } else {
            --counter;
        }
        if (counter < 0) {
            break;
        }
    }

    if (counter == 0 ) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;
    int price = 0;

    for (int i = 0; i < input.size()/2; ++i) {
        if (input[i] != input[input.size() - 1 - i]) {
            ++price;
        }
    }

    cout << price;

    return 0;
}
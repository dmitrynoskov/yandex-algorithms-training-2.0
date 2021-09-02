#include <iostream>

using namespace std;

int main() {
    int r, i, c, result;
    cin >> r >> i >> c;
    switch (i) {
        case 0:
            if (r!=0 ) {
                result = 3;
            } else {
                result = c;
            }
            break;

        case 1:
            result = c;
            break;

        case 4:
            if (r!=0) {
                result = 3;
            } else {
                result = 4;
            }
            break;

        case 6:
            result = 0;
            break;

        case 7:
            result = 1;
            break;

        default:
            result = i;

    }

    cout << result;

    return 0;
}
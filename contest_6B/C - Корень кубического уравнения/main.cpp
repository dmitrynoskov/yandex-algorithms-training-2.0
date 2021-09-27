#include <iostream>
#include <functional>
#include <iomanip>

using namespace std;

static const double EPS = 1e-7;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    function<double(double)> polynom = [=](double x) { return a * x * x * x + b * x * x + c * x + d; };
    double left = -1001;
    double right = 1001;
    while (right - left > EPS) {
        double mid = (right + left) / 2;
        if(polynom(left) * polynom(mid) > 0) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout  << setprecision(10) << (right + left) / 2 << "\n";
    return 0;
}
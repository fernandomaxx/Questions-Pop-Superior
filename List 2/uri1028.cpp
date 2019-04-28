#include <iostream>
using namespace std;

int calcMDC(int a, int b) {
    int r;
    while ( b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b, N;

    cin >> N;
    while (N--) {
        cin >> a >> b;
        cout << calcMDC(a, b) << endl;
    }
}
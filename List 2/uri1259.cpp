#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, value, im = 0, pa = 0;
    cin >> N;
    vector <int>par, impar;

    while (N--) {
        cin >> value;

        if (value % 2 == 0)
            par.push_back(value);
        else
            impar.push_back(value);

    }

    sort(par.begin(), par.end());
    sort(impar.rbegin(), impar.rend());

    for (auto element : par) {
        cout << element << endl;
    }

    for (auto element : impar) {
        cout << element << endl;
    }
}   
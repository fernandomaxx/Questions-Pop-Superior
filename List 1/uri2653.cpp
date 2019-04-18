#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    set <string> jewels;
    string input;
    
    while (cin >> input) {
        jewels.insert(input);
    }
    
    cout << jewels.size() << endl;

}
#include <iostream>

using namespace std;

int compara(int a, int b) 
{
	if(a > b)
		return 1;
	else if(a < b)
		return -1;
	else
		return 0;
}

bool comparaA(int ar[], int n)
{
	int i=1;
	while (i < (n-1)) {
		if (i%2) {
			if (compara(*(ar+i), *(ar+i+1)) >= 0) {
				cout << "0" << endl;
				return false;
			}
		}
		else {
			if (compara(*(ar+i), *(ar+i+1)) <= 0) {
				cout << "0" << endl;
				return false;
			}
		}
		i++;
	}
	cout << "1" << endl;
	return true;			
}

bool comparaB(int ar[], int n)
{
	int i=1;
	while (i < (n-1)) {
		if (i%2) {
			if (compara(*(ar+i), *(ar+i+1)) <= 0) {
				cout << "0" << endl;
				return false;
			}
		}
		else {
			if (compara(*(ar+i), *(ar+i+1)) >= 0) {
				cout << "0" << endl;
				return false;
			}
		}
		i++;
	}
	cout << "1" << endl;
	return true;			
}

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	int value[n];
	
	for (int i=0; i < n; ++i) {
		cin >> value[i];
	}
	
	int comp = compara(value[0], value[1]);
	
	if (comp > 0) 
		comparaA(value, n);
	else if(comp < 0)
		comparaB(value, n);
	else
		cout << "0" << endl;
	
	return 0;
}

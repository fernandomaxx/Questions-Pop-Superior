#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;


int main()
{
    int T;
    cin >> T;
    while(T--){
        unsigned long long int aux2=0,aux =0, fib = 1;
        int N;
        cin >> N;
        if(N==0){
            printf("Fib(0) = 0\n");
            continue;
        }
        for(int i=1; i<N; i++){
            aux = aux2;
            aux2 = fib;
            fib = aux2 + aux;
        }
        printf("Fib(%d) = %lld\n", N, fib);
    }
}
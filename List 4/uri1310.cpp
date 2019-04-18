#include <iostream>

void seg_max(int *v, int n, int & max) {
    int i, j;
    int soma;
    max = -1;
    for (i = 0; i < n; i++) {
        soma = 0;
        for (j = i; j < n; j++) {
            soma += v[j];
            if (soma > max) {
                max = soma;
            }
        }
    }
}

int main() {
    int size, max, cost, aux;

    while ( std::cin >> size )
    {
        int v[size];
        std::cin >> cost;

        for ( int i = 0; i < size; i++ )
        {
            std::cin >> aux;
            v[i] = aux - cost;
        }
        
        seg_max(v, size, max);
        if ( max > 0 )
            std::cout << max << std::endl;
        else 
            std::cout << "0" << std::endl;
    }
}
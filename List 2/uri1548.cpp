#include <stdio.h>
#include <stdlib.h>

void troca( int *vet, int tam )
{
    int i, troca = 1;
    while( troca )
    {
        troca = 0;

        for( i = 0; i < tam - 1; i++ )
        {
            if( vet[i] < vet[i+1] )
            {
               int aux = vet[i];
               vet[i] = vet[i + 1];
               vet[i + 1] = aux;
               troca = 1;
            }
        }
        tam--;
    }
}

int main()
{
    int j, g, c, i = 0;
    scanf("%d", &c);

    while( i < c )
    {
        scanf("%d", &j);
        int a[j], b[j], x = 0;

        for( g = 0; g < j; g++ )
        {
            scanf("%d", &a[g]);
            b[g] = a[g];
        }

        troca( a, j );

        for( g = 0; g < j; g++ )
            if( a[g] == b[g] )
                x++;

        printf("%d\n", x);
        i++;
    }
    return 0;
}
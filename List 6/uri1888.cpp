#include <iostream>

int greater( int a, int b )
{
    if ( a >= b )
        return a;

    return b;
}

int main()
{
    int n, size, *power, *weight, capacity, resistance;
    std::cin >> n;

    for ( int k = 0; k < n; k++ )
    {
        std::cin >> size;
        power = new int[size + 1];
        weight = new int[size + 1];

        for ( int j = 1; j <= size; j++ )
        {
            std::cin >> power[j] >> weight[j];
        }

        std::cin >> capacity;
        std::cin >> resistance;
        int mem[capacity + 1][size + 1];

        for ( int j = capacity; j >= 0; --j )
            mem[j][size] = 0;        

        for ( int i = size - 1; i >= 0 ; --i )
        {
            for ( int y = 0; y <= capacity ; ++y )
            {
                int sub = y - weight[i + 1];
                if ( sub >= 0 )
                    mem[y][i] = greater( mem[y][i + 1], mem[sub][i + 1] + power[i + 1] );
                else
                    mem[y][i] = mem[y][i + 1];
            }
        }

        if ( mem[capacity][0] >= resistance )
            std::cout << "Missao completada com sucesso\n";
        else
            std::cout << "Falha na missao\n";

    }
    
} 
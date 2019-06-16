#include <iostream>

int greater( int a, int b )
{
    if ( a >= b )
        return a;

    return b;
}

int main()
{
    int size, *time, *quantity, capacity;

    while ( true )
    {
        std::cin >> size;
        if ( !size )
            break;
            
        time = new int[size + 1];
        quantity = new int[size + 1];
        std::cin >> capacity;

        for ( int j = 1; j <= size; j++ )
        {
            std::cin >> time[j] >> quantity[j];
        }

        int mem[capacity + 1][size + 1];

        for ( int j = capacity; j >= 0; --j )
            mem[j][size] = 0;        

        for ( int i = size - 1; i >= 0 ; --i )
        {
            for ( int y = 0; y <= capacity ; ++y )
            {
                int sub = y - quantity[i + 1];
                if ( sub >= 0 )
                    mem[y][i] = greater( mem[y][i + 1], mem[sub][i + 1] + time[i + 1] );
                else
                    mem[y][i] = mem[y][i + 1];
            }
        }
        
        std::cout << mem[capacity][0] << " min.\n";

    }
    
} 
#include <iostream>
#include <vector>
#include <cstring>

int main()
{
    int r, k;
    bool mem[111][111 * (111 - 1) / 2];
    //freopen( "input", "r", stdin );
    while ( std::cin >> r >> k )
    {
        memset( mem, 0, sizeof(mem));
        mem[r][k] = 1;
        std::vector< int > pontes(r);
        int v1, v2;

        for (int i = 0; i < k; ++i)
        {
            std::cin >> v1 >> v2;
            pontes[--v1]++;
            pontes[--v2]++;
        }

        for (int i = r - 1; i >= 0; --i)
        {
            for (int j = 0; j <= k; ++j)
            {
                mem[i][j] = mem[i+1][j];
                if ( j + pontes[i] <= k)
                {
                    mem[i][j] |= mem[i+1][j + pontes[i]];
                }
            }
        }

        if ( mem[0][0] )
            std::cout << "S" << std::endl;
        else
            std::cout << "N" << std::endl;
    }
}
#include <iostream>
#include <algorithm>
#include <cstring>

long long est( int p, int u );

void dpmax();

int n;

long long v[10010], dp[10010];

int main()
{
    while ( std::cin >> n ){
        memset( dp, 0, sizeof dp );
        for ( int i = 0; i < n; i++ )
            std::cin >> v[i];

        if ( n == 2 )
            std::cout << std::max( v[0], v[1] ) << std::endl;
        else
        {
            dpmax();
            std::cout << dp[0] << std::endl;
        }
    }
    return 0;
}

long long est( int p, int u )
{
    return std::max( v[p+1], std::min( v[p], v[u] ));
}

void dpmax()
{
    for ( int i = 0; i < n-2; i++ )
    {
        dp[i] = est(i, i+2);
    }
    bool flip = true;
    int comp = 3;
    int l = n-3;
    while( l > 0 ){
        for ( int i = 0; i < l; i++ )
        {
            if ( flip )
                dp[i] = std::max( v[i+comp] + dp[i], v[i] + dp[i+1] );
            else
                dp[i] = std::min( dp[i], dp[i+1] );
        }
        flip = !flip;
        comp++;
        l--;
    }
}
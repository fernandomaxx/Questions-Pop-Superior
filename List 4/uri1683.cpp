#include <iostream>
#include <vector>


int main()
{
    int size;

    while ( std::cin >> size )    
    {
        long long max = 0, value;
        std::vector< std::pair< long long, int > > vec;

        if ( !size )
            break;

        vec.push_back( std::make_pair( 0, 0 ));

        for ( int i = 0; i < size; i++ )
        {
            std::cin >> value;

            if ( vec.empty() || value > vec.back().first )
                vec.push_back( std::make_pair( value, i ));
            else
            {
                int last = i;

                while( !vec.empty() && value <= vec.back().first )
                {
                    max = std::max( max, vec.back().first * ( i - vec.back().second ));
                    last = std::min( last, vec.back().second );
                    vec.pop_back();
                }

                vec.push_back( std::make_pair( value, last ));
            }
                
        }

        while ( !vec.empty() )
        {
            max = std::max( max, vec.back().first * ( size - vec.back().second ));
            vec.pop_back();
        }

        std::cout << max << std::endl;
        
    }
}
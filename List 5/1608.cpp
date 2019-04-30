#include<iostream>           
#include <algorithm>    
  
int main() {

    int cases, money, size_i, size_c, *cost_cake;
    std::cin >> cases;
    while ( cases-- ) 
    {
        std::cin >> money >> size_i >> size_c;

        int price[size_i];
        cost_cake = new int[size_c];

        for ( int j = 0; j < size_i; j++ )
        { 
            std::cin >> price[j];
        }

        for ( int j = 0; j < size_c; j++ ) 
        {
            int Q;
            std::cin >> Q;
            for ( int k = 0; k < Q; k++ ) 
            {
                int index, amount;
                std::cin >> index >> amount;
                cost_cake[j] += price[index] * amount;
            }
        }
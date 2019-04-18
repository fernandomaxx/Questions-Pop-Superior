#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 9999.99999

typedef struct
{
    double x;
    double y;
}Point;

int sortx( const void *a, 
           const void *b ) 
{ 
    Point *sp1 = (Point *)a;
    Point *sp2 = (Point *)b;
    return ( sp1->x < sp2->x ); 
} 

int sorty( const void *a, 
           const void *b ) 
{ 
    Point *sp1 = (Point *)a;
    Point *sp2 = (Point *)b;
    return ( sp1->y < sp2->y ); 
}

double dist( const Point a, 
            const Point b )
{
    double subx = a.x - b.x,
          suby = a.y - b.y;
    return sqrt( subx * subx + suby * suby );
}

double bruteForce( Point *point, int size ) 
{ 
    double min = 10000000; 
    for ( int i = 0; i < size; ++i ) 
        for ( int j = i + 1; j < size; ++j ) 
            if (dist(point[i], point[j]) < min) 
                min = dist(point[i], point[j]); 
    return min; 
}

double stripClosest( Point *strip, int size, double min_d )
{
    double min = min_d;

    qsort( strip, size, sizeof( strip[0] ), sorty );

    for ( int i = 0; i < size; i++ )
    {
        for ( int j = i + 1; ( strip[i].y - strip[j].y ) < min && j < size; j++ )
            if ( dist( strip[i], strip[j] ) < min )
                min = dist( strip[i], strip[j] );
    }
    return min;
}

double closestUtil( Point *point, int size)
{
    if ( size <= 3 )
        return bruteForce( point, size );

    int mid = size / 2;
    Point mid_point = point[mid];

    double dr = closestUtil( point, mid );
    double dl = closestUtil( point + mid, size - mid );

    double d = std::min( dr, dl );

    Point strip[size];
    int j = 0;
    for ( int i = 0; i < size; i++ )
    {
        if ( abs( point[i].x - mid_point.x ) < d )
            strip[j] = point[i], j++;
    }

    return std::min( d, stripClosest( strip, j, d ));
}


double closest( Point *point, int size )
{
    qsort( point, size, sizeof( point[0] ), sortx );

    return closestUtil( point, size ); 
}

int main()
{
    int size;
    Point point[10001];
    //freopen( "input", "r", stdin );
    while ( true )
    {
        std::cin >> size;
        if ( !size )
            break;

        for ( int i = 0; i < size; i++ )
        {
            std::cin >> point[i].x >> point[i].y;
        }

        double dist = closest( point, size );

        if ( dist > MAX )
            printf("INFINITY\n");
        else
            printf("%.4f\n", dist);
    }
    
}
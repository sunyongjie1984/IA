// InsertionSort.cpp
#include "InsertionSort.h"

#ifdef __linux
#include <stdio.h>
#endif

// windows7 and visual studio is for viewing code
// just for viewing
// and you can edit files and checkin in the mac os in macbook pro

int main( )
{
    uint64_t array[ 6 ] = { 5, 2, 4, 6, 1, 3 };

    for ( uint64_t i = 0; i < sizeof( array ) / sizeof( uint64_t ); ++i )
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    InsertionSort( array, sizeof( array ) / sizeof( uint64_t ) );
    for ( uint64_t i = 0; i < sizeof( array ) / sizeof( uint64_t ); ++i )
    {
        std::cout << array[ i ] << " ";
    }
    std::cout << std::endl;
    std::cout << "press any key to end this program" << std::endl;
    getchar( );
    return 0;
}

// InsertionSort.cpp
#include "InsertionSort.h"

#ifdef __linux
#include <stdio.h>
#endif

static void extracted(uint64_t *array) {
    InsertionSort( array, sizeof( array ) / sizeof( uint64_t ) );
}

int main( )
{
    uint64_t array[ 6 ] = { 5, 2, 4, 6, 1, 3 };

    for ( uint64_t i = 0; i < sizeof( array ) / sizeof( uint64_t ); ++i )
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    extracted(array);
    for ( uint64_t i = 0; i < sizeof( array ) / sizeof( uint64_t ); ++i )
    {
        std::cout << array[ i ] << " ";
    }
    std::cout << std::endl;
    std::cout << "press any key to end this program" << std::endl;
    getchar( );
    return 0;
}

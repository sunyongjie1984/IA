// InsertionSort.h
#include <iostream>
#include <stdint.h>
// INSERTION-SORT(A)
// for j = 2 to A.length
//     key = A[j]
//     // Insert A[j] into sorted sequence A[1..j - 1].
//     i = j - 1ls
//     while i > 0 and a[i] > key
//         a[i + 1] = a[i]
//         i = i - 1
//     a[i + 1] = key

// allow the same key

void InsertionSort( uint64_t* const A, uint64_t const n )
{
    uint64_t key;
    int64_t i;
    // j = 2 to A.length(j 1 to n - 1)
    for ( uint64_t j = 1; j < n; ++j ) // j begin with A[1]
    {
        key = A[ j ]; // we are putting A[j] (key) to the right place
        i = j - 1;    // for every A[j], compare begin the previous one
        // very element ahead of A[j] is sorted
        // move back one step for every element who is bigger than A[j]
        while ( i >= 0 && A[i] > key )
        {
            A[ i + 1 ] = A[ i ];
            --i;
        }
        // after moving, A[i] is equal or less then A[j]
        // A[j] shoule be after A[i]
        A[ i + 1 ] = key;
    }
}

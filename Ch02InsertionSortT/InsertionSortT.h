// ≤Â»Î≈≈–Ú insertion_sort_t.h

#include <iostream>
#include <string>

// INSERTION-SORT(A)
// for j = 2 to A.length
//     key = A[j]
//     // Insert A[j] into sorted sequence A[1..j - 1].
//     i = j - 1
//     while i > 0 and a[i] > key
//         a[i + 1] = a[i]
//         i = i - 1
//     a[i + 1] = key

template <class Type> void insert_sort_t(Type * const a, int const & n)
{
    Type key;
    // assign j with 2, because we start inserting sort with the second element
    // j < n because:
    // 1. n stands for the number of the array
    // 2. n - 1 a[n-1] is the last element
    for (int j = 1; j < n; j++)
    {
        key = a[j];    // a[j] is the element being inserted to the array
        int i = j - 1; // a[0...j-1] are already sortted, a[j] is being sorted
                       // a[j+1....n-1] are not sorted
        // first compare a[j] and a[j-1]
        while ((i >= 0) && (a[i] > key))
        {
            a[i + 1] = a[i]; // all bigger than a[j] move back one step
            i--;
        }
        a[i + 1] = key;      // put a[j] to the correct place
    }
}


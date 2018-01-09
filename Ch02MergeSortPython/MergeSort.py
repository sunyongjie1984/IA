import pdb
#/ 2.3.1
#/ MERGE(A, p, q, r)
#/ n1 = q - p + 1
#/ n2 = r - q
#/ let L[1..n1 + 1] and R[1..n2 + 1] be new arrays
#/ for i = 1 to n1
#/     L[i] = A[p + i - 1]
#/ for j = 1 to n2
#/     R[j] = A[q + j]
#/ L[n1 + 1] = INT64_MAX
#/ R[n2 + 1] = INT64_MAX
#/ i = 1
#/ j = 1
#/ for k = p to r
#/     if L[i] <= R[j]
#/         A[k] = L[i]
#/         i = i + 1
#/     else A[k] = R[j]
#/         j = j + 1

def main():
    #K = [ 1 ];
    #K[0] = 3;
    #print K[0];
    print MergeSort( [ 5, 2, 4, 7, 1, 3, 2, 6 ], 0, 7 );

def Merge( A, p, q, r ):
    #pdb.set_trace( );
    n1 = q - p + 1;
    n2 = r - q;
    #a = [0 for x in range(0, 1000)]
    L = [0 for x in range(0, n1 + 1)]
    R = [0 for x in range(0, n2 + 1)]
    for i in range( 0, n1 ):
        L[ i ] = A[ p + i ];
    for j in range( 0, n2 ):
        R[ j ] = A [ q + j + 1 ];
    L[ n1 ] = 999999999;
    R[ n2 ] = 999999999;
    i = 0;
    j = 0;
    for k in range( p, r + 1 ):
        if ( L[ i ] <= R[ j ] ):
            A[ k ] = L[ i ];
            i = i + 1;
        else:
            A[ k ] = R[ j ];
            j = j + 1;
    return A;

#/ MERGE-SORT(A, p, r)
#/ if p < r
#/     q = |_(p + r) / 2_|
#/     MERGE-SORT(A, p, q)
#/     MERGE-SORT(A, q + 1, r)
#/     MERGE(A, p, q, r)
#
def MergeSort( A, p, r ):
    #pdb.set_trace( );
    if p < r:
        q = ( p + r ) / 2;
        MergeSort( A, p, q );
        MergeSort( A, q + 1, r );
        print Merge( A, p, q, r );
    return A;

if __name__ == '__main__':
    main()
#/void merge_sort(int64_t* A, uint64_t p, uint64_t r)
#/{
#/    if (p < r)
#/    {
#/        uint64_t q = (p + r) / 2;
#/        merge_sort(A, p, q);
#/        merge_sort(A, q + 1, r);
#/        merge(A, p, q, r);
#/    }
#/}

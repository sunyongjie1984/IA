// 2.3.1
// MERGE(A, p, q, r)
// n1 = q - p + 1
// n2 = r - q
// let L[1..n1 + 1] and R[1..n2 + 1] be new arrays
// for i = 1 to n1
//     L[i] = A[p + i - 1]
// for j = 1 to n2
//     R[j] = A[q + j]
// L[n1 + 1] = INT64_MAX
// R[n2 + 1] = INT64_MAX
// i = 1
// j = 1
// for k = p to r
//     if L[i] <= R[j]
//         A[k] = L[i]
//         i = i + 1
//     else A[k] = R[j]
//         j = j + 1

def main():
    print MergeSort( [ 2, 13, 4, 1919, 1, 1100, 1, 3, 2, 373737, 0 ] );

def Merge( A, p, q, r ):
    n1 = q - p + 1;
    n2 = r - q;


// MERGE-SORT(A, p, r)
// if p < r
//     q = |_(p + r) / 2_|
//     MERGE-SORT(A, p, q)
//     MERGE-SORT(A, q + 1, r)
//     MERGE(A, p, q, r)

void merge_sort(int64_t* A, uint64_t p, uint64_t r)
{
    if (p < r)
    {
        uint64_t q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

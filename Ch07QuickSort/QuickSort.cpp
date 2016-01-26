#include "QuickSort.h"

int main()
{
    int64_t array[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
    print_array(array, 8);
    quicksort(array, 0, 7);
    print_array(array, 8);
    return 0;
}

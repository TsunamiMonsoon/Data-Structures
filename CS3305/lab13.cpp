#include <cstdlib>
#include <iostream>
#include <cassert>
#include <ctime> // used in initialization of random number generator

using namespace std;

template <typename T>

bool is_sorted (T* a, size_t size)
// precondition: a is not NULL
// returns: whether array a is sorted
{
    int i;
    // traverse the array
    for( i = 0 ; i < size - 1 ; i++ ){
        // if the array is not sorted
        if( a[i] > a[i + 1] )
            return false;
    }
    // if the array is sorted  
    return true;
}
template <typename T>
void shell_sort (T* a, size_t size)
// precondition: a is not NULL
// postcondition: a is sorted in non-decreasing order
{
    int gap, i, x, y;
    T m;
    // a big gap in the beginning, then keep on reducing it
    for (gap = size / 2 ; gap > 0; gap /= 2){
        for (x = gap; x < size ; x += 1){
            m = a[x];
            // untill the appropriate position for i th element of a is
            // found, shift the elements
            for (y = x; y >= gap && a[y - gap] > m; y -= gap){
                a[y] = a[y - gap];
            }
            // m is placed in the appropriate posotion
            a[y] = m;
        }
    }
}
int* create_array (size_t size)
// returns an array with size random integers
{
    // create a new array
    int *arr = new int[size];
    int i;
   for( i = 0 ; i < size ; i++ )

        arr[i] = rand() % 100;
    return arr;
}

int main (){
    size_t size = 10;

	int i;
    int* a = create_array (size);

    shell_sort<int>(a, size);

    assert (is_sorted<int>(a, size));
	
	for (i = 0; i < size; i++)
		std::cout << a[i] << endl;
	
    delete a;
    return EXIT_SUCCESS;

}
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    int* small_ptr = NULL; 
    int* big_ptr   = NULL;

    small_ptr = (int*) malloc((sizeof(arr) / sizeof(arr[0])) / sizeof(int));
    big_ptr   = (int*) malloc(10 * sizeof(int));

    small_ptr = arr;

    for(int i = 0; i < 5; i++)
    {
        cout << small_ptr[i] << endl;
    }

    for(int j = 0; j < 5; j++)
    {
        big_ptr[j] = small_ptr[j];
    }

    for(int k = 0; k < 5; k++)
    {
        cout << big_ptr[k] << endl;
    }

    return 0;
}
#include <iostream>
#include <stdlib.h>

using namespace std;

int* arrayFunction(int size)
{
    return (int*) malloc(size * sizeof(int));
}

int main()
{
    int *ptr;

    ptr = arrayFunction(5);

    for(int i = 0; i < 5; i++)
    {
        cout << i << endl;
    }

    free(ptr);

    return 0;
}
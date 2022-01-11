#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int *ptr = NULL;
    int a[5] = {1, 2, 3, 4, 5};

    ptr = (int *) malloc(5 * sizeof(int));

    for(int i = 0; i < 5; i++)
    {
        ptr[i] = a[i];
    }

    for(int j = 0; j < 5; j++)
    {
        printf("%d\n", ptr[j]);
    }

    free(ptr);

    return 0;
}
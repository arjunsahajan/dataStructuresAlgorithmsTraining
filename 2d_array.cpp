#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    //array of pointers
    int* ptr[3];
    int num;

    //compiler representation formula A[n]
    //address(A[n]) = baseAddress + n * sizeof(dataType)

    //compiler formula for accessing each element
    //Address(A[i][j]) = base_address + i * (number of columns) 

    ptr[0] = (int*) malloc(3 * sizeof(int));
    ptr[1] = (int*) malloc(3 * sizeof(int));
    ptr[2] = (int*) malloc(3 * sizeof(int));

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << "Enter element " << i << ", " << j << ": ";
            cin >> num;
            ptr[i][j] = num;
        }
    }

    cout << endl << "Matrix" << endl;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << ptr[i][j] << "\t";
        }

        cout << endl;
    }

    free(ptr[0]);
    free(ptr[1]);
    free(ptr[2]);

    return 0;
}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct _ARRAY
{
        int* buffer;
        int size;
        int length;
} _ARRAY_OBJ;

void display(_ARRAY_OBJ*);
void find_dups(_ARRAY_OBJ*);

void find_dups(_ARRAY_OBJ* array_ptr)
{
    int i = 0;
    int j = 0;
    int count;

    while(i < array_ptr -> length - 1)
    {
        j = i + 1;
        count = 1;

        while(j < array_ptr -> length)
        {
            if(array_ptr -> buffer[i] == array_ptr -> buffer[j] && array_ptr -> buffer[i] != -1) 
            {
                array_ptr -> buffer[j] = -1;
                count += 1;
            }

            j += 1;
        }

        if(count > 1)
        {
            cout << array_ptr -> buffer[i] << " -> " << count << endl;
        }

        i += 1;
    }
}

void display(_ARRAY_OBJ* array_ptr)
{
    for(int i = 0; i < array_ptr -> length; i++)
    {
        cout << array_ptr -> buffer[i] << " ";
    }

    cout << endl;
}

int main()
{
    _ARRAY_OBJ array_struct_var;

	cout << "Enter size of array: ";
	cin >> array_struct_var.size;
	cout << "Enter number of elements array: ";
	cin >> array_struct_var.length;

	array_struct_var.buffer = (int*) malloc(array_struct_var.size * sizeof(int));

    cout << "Enter array" << endl;
	for(int i = 0; i < array_struct_var.length; i++)
	{
        cout << "Enter element " << i << " of array: ";
        cin >> array_struct_var.buffer[i];
	}

    display(&array_struct_var);

    find_dups(&array_struct_var);

    free(array_struct_var.buffer);

	return 0;
}
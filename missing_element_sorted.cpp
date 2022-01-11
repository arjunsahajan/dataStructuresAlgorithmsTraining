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

void sort_ascending(_ARRAY_OBJ*);
void display(_ARRAY_OBJ*); 
int find_missing_ele(_ARRAY_OBJ*);
void find_all_missing(_ARRAY_OBJ*);

void find_all_missing(_ARRAY_OBJ* array_ptr)
{
    int i = 0;
    int diff = 0;

    while(i < array_ptr -> length - 1)
    {
        diff = array_ptr -> buffer[i + 1] - array_ptr -> buffer[i];
        
        if(diff != 1)
        {
            for(int j = 1; j < diff; j++)
            {
                cout << "Missing " << array_ptr -> buffer[i] + j << endl;
            }
        }

        i += 1;
    }
}

int find_missing_ele(_ARRAY_OBJ* array_ptr)
{
    for(int i = 0; i < array_ptr -> length - 1; i++)
    {
        if(array_ptr -> buffer[i + 1] - array_ptr -> buffer[i] != 1)
        {
            return array_ptr -> buffer[i] + 1;
        }
    }

    return -1;
}

// missing element sum method
// find sum(length natural numbers) -> eq 1
// find sum(elements in array) -> eq 2
// eq 1 - eq 2 gives the missing element

void sort_ascending(_ARRAY_OBJ* array_ptr)
{
    int temp;
    for(int i = 0; i < array_ptr -> length - 1; i++)
    {
        for(int j = 0; j < array_ptr -> length - 1; j++)
        {
            if(array_ptr -> buffer[j] > array_ptr -> buffer[j + 1])
            {
                temp = array_ptr -> buffer[j];
                array_ptr -> buffer[j] = array_ptr -> buffer[j + 1];
                array_ptr -> buffer[j + 1] = temp;
            }
        }
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
    int ele;
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

    sort_ascending(&array_struct_var);

    // ele = find_missing_ele(&array_struct_var);
    
    // if(ele == -1)
    // {
    //     cout << "No elements are missing" << endl;
    // }
    // else 
    // {
    //     cout << "The missing element is: " << ele << endl;  
    // }
    
    find_all_missing(&array_struct_var);

    free(array_struct_var.buffer);

	return 0;
}
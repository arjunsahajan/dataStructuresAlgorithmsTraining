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
void find_sum_pair(_ARRAY_OBJ*, int);
void sum_pair_sorted(_ARRAY_OBJ*, int);
void sort_ascending(_ARRAY_OBJ*);
void find_min_max(_ARRAY_OBJ*);

void find_min_max(_ARRAY_OBJ* array_ptr)
{
    int min = array_ptr -> buffer[0];
    int max = array_ptr -> buffer[0];

    for(int i = 1; i < array_ptr -> length; i++)
    {
        if(array_ptr -> buffer[i] < min)
        {
            min = array_ptr -> buffer[i];
        }

        if(array_ptr -> buffer[i] > max) {
            max = array_ptr -> buffer[i];
        }
    }

    cout << "max = " << max << " min = " << min << endl;
}

void sum_pair_sorted(_ARRAY_OBJ* array_ptr, int add)
{
    int i = 0;
    int j = array_ptr -> length - 1;

    while(true)
    {
        if( i == j)
        {
            break;
        }

        if(array_ptr -> buffer[i] + array_ptr -> buffer[j] == add)
        {
            cout << array_ptr -> buffer[i] << " + " << array_ptr -> buffer[j] << " = " << array_ptr -> buffer[i] + array_ptr -> buffer[j] << endl;
            i += 1;
            j -= 1;
        }
        else if(array_ptr -> buffer[i] + array_ptr -> buffer[j] > add)
        {
            j -= 1;
        } 
        else{
            i += 1;
        }

    }
}

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

void find_sum_pair(_ARRAY_OBJ* array_ptr, int add)
{
    int i = 0;
    int j;

    while(i < array_ptr -> length)
    {
        j = i + 1;

        while(j < array_ptr -> length)
        {
            if(array_ptr -> buffer[i] == -1)
            {
                i += 1;
                continue;
            }

            if(array_ptr -> buffer[j] == add - array_ptr -> buffer[i])
            {
                cout << array_ptr -> buffer[i] << " + " << array_ptr -> buffer[j] << " = " << array_ptr -> buffer[i] + array_ptr -> buffer[j] << endl;
                array_ptr -> buffer[j] = -1;
            }

            j += 1;
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
    int add;
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

    // cout << "Enter sum: ";
    // cin >> add;

    sort_ascending(&array_struct_var);

    display(&array_struct_var);

    find_min_max(&array_struct_var);

    // sum_pair_sorted(&array_struct_var, add);

    free(array_struct_var.buffer);

	return 0;
}
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
void print_dup(_ARRAY_OBJ*);
void print_count_dup(_ARRAY_OBJ*);
void sort_ascending(_ARRAY_OBJ*);

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

void print_count_dup(_ARRAY_OBJ* array_ptr) 
{
    int count;
    int j;

    for(int i = 0; i < array_ptr -> length; i++)
    {
        j = i;
        count = 0;

        while(j < array_ptr -> length)
        {
            if(array_ptr -> buffer[i] == array_ptr -> buffer[j])
            {
                count += 1;
            }

            j += 1;
        }

        if(count > 1)
        {
            cout << array_ptr -> buffer[i] << " -> " << count << endl;
        }

    }
}

void print_dup(_ARRAY_OBJ* array_ptr)
{
    int i = 0;
    int j = 0;
    int count;

    while(i < array_ptr -> length - 1)
    {
        count = 0;

        if(array_ptr -> buffer[i] == array_ptr -> buffer[i + 1])
        {
            j = i;

            while(true)
            {
                if(array_ptr -> buffer[i] == array_ptr -> buffer[j])
                {
                    count += 1;
                    j += 1;
                }
                else
                {
                    i = j - 1;
                    break;
                }
            }

            cout << array_ptr -> buffer[i] << " -> " << count << endl;
        } 
        else 
        {
            i += 1;
        }
    }

    cout << endl;
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

    sort_ascending(&array_struct_var);

    display(&array_struct_var);

    print_dup(&array_struct_var);

    free(array_struct_var.buffer);

	return 0;
}
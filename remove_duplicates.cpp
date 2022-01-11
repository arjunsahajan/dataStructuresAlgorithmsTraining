#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct _ARRAY
{
	int* buffer;
	int size;
	int length;
} _ARRAY_OBJ;

void display(_ARRAY_OBJ*);
void remove_dup(_ARRAY_OBJ*);
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

void remove_dup(_ARRAY_OBJ* array_ptr)
{
	int i = 0;

        while(true)
	{
		if(i == array_ptr -> length)
		{
			break;
		}
                
		if(array_ptr -> buffer[i] == array_ptr -> buffer[i + 1])
		{
			for(int j = i + 1; j < array_ptr -> length; j++)
			{
				array_ptr -> buffer[j] = array_ptr -> buffer[j + 1];
			}

			array_ptr -> length -= 1;
		}
		else 
		{
			i += 1;
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
	_ARRAY_OBJ array_struct_var;

	cout << "Enter size of array: ";
	cin >> array_struct_var.size;
	cout << "Enter number of elements: ";
	cin >> array_struct_var.length;

	array_struct_var.buffer = (int*) malloc(array_struct_var.size * sizeof(int));

	for(int i = 0; i < array_struct_var.length; i++)
	{
		cout << "Enter element " << i << ": ";
		cin >> array_struct_var.buffer[i];
	}

	cout << "ARRAY" << endl;
	display(&array_struct_var);
	
	sort_ascending(&array_struct_var);
	remove_dup(&array_struct_var);

	display(&array_struct_var);

	return 0;
}

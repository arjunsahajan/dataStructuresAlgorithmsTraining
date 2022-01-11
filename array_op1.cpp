#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct ARRAY
{
	int* ptr;
	int size;
	int length;
} _array;

void display_elements(_array*);

void display_elements(_array* struct_ptr)
{
	for(int i = 0; i < struct_ptr -> length; i++)
	{
		cout << struct_ptr -> ptr[i] << " ";
	}

	cout << endl;
}

int main()
{
	_array arr_struct;	

	cout << "Enter size of array: ";
	cin >> arr_struct.size;

	arr_struct.ptr = (int*) malloc(arr_struct.size * sizeof(int));

	cout << "Enter number of elements less than " << arr_struct.size << ": ";
	cin >> arr_struct.length;

	if(arr_struct.length > arr_struct.size)
	{
		cout << "Please enter number of elements < size of array" << endl;
		exit(EXIT_SUCCESS);
	}

	for(int i = 0; i < arr_struct.length; i++)
	{
		cout << "Enter element " << i << ": ";
		cin >> arr_struct.ptr[i];
	}

	display_elements(&arr_struct);	
	
	free(arr_struct.ptr);

	return 0;
}


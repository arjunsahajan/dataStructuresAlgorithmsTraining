#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct _ARRAY
{
	int* buffer;
	int length;
	int size;
} _ARRAY_STRUCT;

int linear_search(_ARRAY*, int index);
void display(_ARRAY*);

void display(_ARRAY* array_ptr)
{
	for(int i = 0; i < array_ptr -> length; i++)
	{
		cout << array_ptr -> buffer[i] << " ";
	}

	cout << endl;
}

int linear_search(_ARRAY* array_ptr, int num)
{
	for(int i = 0; i < array_ptr -> buffer[i]; i++)
	{
		if(array_ptr -> buffer[i] == num)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	_ARRAY_STRUCT array_obj;
	int num;	
	int index;

	cout << "Enter size of array: ";
	cin >> array_obj.size;

	array_obj.buffer = (int*) malloc(array_obj.size * sizeof(int));

	cout << "Enter number of elements: ";
	cin >> array_obj.length;

	if(array_obj.length > array_obj.size)
	{
		cout << "Error!!. Length should be less than size";	
		exit(EXIT_SUCCESS);
	}

	for(int i = 0; i < array_obj.length; i++)
	{
		cout << "Enter element " << i << ": ";
		cin >> array_obj.buffer[i];
	}

	display(&array_obj);

	cout << "Enter element to be searched for: ";
	cin >> num;

	index = linear_search(&array_obj, num);
	
	if(index == -1)
	{
		cout << num << " is not in this array" << endl;
	}
	else 
	{
		cout << num << " is at index " << index << endl; 
	}

	return 0;
}

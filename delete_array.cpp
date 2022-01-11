#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct _ARRAY
{
	int* buf;
	int size;
	int length;
} _ARRAY_OBJ;

void del(_ARRAY_OBJ*, int);
void display(_ARRAY_OBJ*);

void del(_ARRAY_OBJ* array_ptr, int index)
{
	for(int i = index; i < array_ptr -> length - 1; i++)
	{
		array_ptr -> buf[i] = array_ptr -> buf[i + 1];
	}

	array_ptr -> length -= 1;
}

void display(_ARRAY_OBJ* array_ptr)
{
	for(int i = 0; i < array_ptr -> length; i++)
	{
		cout << array_ptr -> buf[i] << " ";
	}

	cout << endl;
}

int main()
{
	_ARRAY_OBJ _array;
	int index;

	cout << "Enter size of array: ";
	cin >> _array.size;

	_array.buf = (int*) malloc(_array.size * sizeof(int));
	
	cout << "Enter number of elements: ";
	cin >> _array.length;

	if(_array.length > _array.size)
	{
		cout << "Error!!. Length should be less than size";	
		exit(EXIT_SUCCESS);
	}

	for(int i = 0; i < _array.length; i++)
	{
		cout << "Enter element " << i << ": ";
		cin >> _array.buf[i];
	}

	display(&_array);
	
	while(true)
	{
		cout << "Enter index of element to be deleted: ";
		cin >> index;
		
		if(index > _array.length || index < 0)
		{
			cout << "Overflow!!" << endl;
			continue;
		}

		break;
	}

	del(&_array, index);

	display(&_array);

	return 0;	
	
}

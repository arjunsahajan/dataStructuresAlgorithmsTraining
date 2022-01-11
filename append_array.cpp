#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct _ARRAY
{
	int* buf;
	int size;
	int length;
} _ARRAY_OBJ;

void append(_ARRAY_OBJ*, int);
void display(_ARRAY_OBJ*);

void append(_ARRAY_OBJ* array_ptr, int ele)
{
	array_ptr -> buf[array_ptr -> length] = ele;
	array_ptr -> length += 1;
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
	char opt;
	int ele;

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

	while(true)
	{	
		cout << "Append more elements? [y/n]: ";
		cin >> opt;
		
		if(opt == 'n' || (_array.length == _array.size))
		{			
			break;
		}

		cout << "Enter element to be inserted: ";
		cin >> ele;

		append(&_array, ele);
	}

	display(&_array);

	return 0;	
	
}

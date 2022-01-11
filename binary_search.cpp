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
void sort_ascending(_ARRAY_OBJ*);
int binary_search(_ARRAY_OBJ*, int);

int binary_search(_ARRAY_OBJ* array_ptr, int num)
{
	int mid = 0;
 	int head = 0;
	int tail = array_ptr -> length - 1;
	
	while(true)
	{
		mid = (head + tail) / 2;
		
		if(array_ptr -> buffer[mid] > num)
		{
			tail = mid - 1;
		}
		else if(array_ptr -> buffer[mid] < num)
		{
			head = mid + 1;
		}

		if(array_ptr -> buffer[mid] == num) 
		{
			return mid;
		}

		if(head > tail)
		{
			return -1;
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
	_ARRAY_OBJ _array;
	int num, index;

	cout << "Enter size of array: ";
	cin >> _array.size;

	_array.buffer = (int*) malloc(_array.size * sizeof(int));
	
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
		cin >> _array.buffer[i];
	}

	display(&_array);

	sort_ascending(&_array);

	cout << "Sorted array" << endl;
	display(&_array);

	cout << "Enter element to be searched for: ";
	cin >> num;

	index = binary_search(&_array, num);
	
	if(index == -1)
	{
		cout << num << " is not in this array" << endl;
	}
	else 
	{
		cout << num << " is at index " << index << endl; 
	}	

	free(_array.buffer);

	return 0;
}

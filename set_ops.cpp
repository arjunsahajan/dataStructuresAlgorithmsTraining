#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define STRUCT_ARRAY_LENGTH 3

typedef struct _ARRAY
{
        int* buffer;
        int size;
        int length;
} _ARRAY_OBJ;

_ARRAY_OBJ _ARRAY_LIST[STRUCT_ARRAY_LENGTH];

void union_fun(void);
void display(_ARRAY_OBJ*); 
void intersection_fun(void);
void remove_duplicates(_ARRAY_OBJ*);
void sort_ascending(_ARRAY_OBJ*);
void difference(void);
void del(_ARRAY_OBJ*, int);

void del(_ARRAY_OBJ* array_ptr, int index)
{
	for(int i = index; i < array_ptr -> length - 1; i++)
	{
		array_ptr -> buffer[i] = array_ptr -> buffer[i + 1];
	}

	array_ptr -> length -= 1;
}

void difference(void)
{
	int k = 0;
	int i = 0;
	int j = 0;

	while(i < _ARRAY_LIST[0].length && j < _ARRAY_LIST[1].length)
	{
		if(_ARRAY_LIST[0].buffer[i] < _ARRAY_LIST[1].buffer[j])
		{
			_ARRAY_LIST[2].buffer[k] = _ARRAY_LIST[0].buffer[i];
			i += 1;
			k += 1;
			_ARRAY_LIST[2].length += 1;
		}
		else if(_ARRAY_LIST[0].buffer[i] > _ARRAY_LIST[1].buffer[j])
		{
			_ARRAY_LIST[2].buffer[k] = _ARRAY_LIST[1].buffer[j];
			j += 1;
			k += 1;
			_ARRAY_LIST[2].length += 1;
		}
		else
		{
			i += 1;
			j += 1;
		}
	}

	for(int q = i; q < _ARRAY_LIST[0].length; q++)
	{
		_ARRAY_LIST[2].buffer[k] = _ARRAY_LIST[0].buffer[q];
		k += 1;
		_ARRAY_LIST[2].length += 1;
	}

	for(int l = j; l < _ARRAY_LIST[1].length; l++)
	{
		_ARRAY_LIST[2].buffer[k] = _ARRAY_LIST[1].buffer[l];
		k += 1;
		_ARRAY_LIST[2].length += 1;
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

void remove_duplicates(_ARRAY_OBJ* array_ptr)
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

void union_fun(void)
{
	bool found;	
	int q = 0;

	for(int i = 0; i < _ARRAY_LIST[0].length; i++)
	{
		_ARRAY_LIST[2].buffer[i] = _ARRAY_LIST[0].buffer[i];
	}

	_ARRAY_LIST[2].length = _ARRAY_LIST[0].length;	

	for(int j = 0; j < _ARRAY_LIST[1].length; j++)
	{	
		found = false;
		for(int k = 0; k < _ARRAY_LIST[2].length - _ARRAY_LIST[0].length + j; k++)
		{
			if(_ARRAY_LIST[2].buffer[k] == _ARRAY_LIST[1].buffer[j])
			{
				found = true;
				break;
			}
		}
		
		if(!found)
		{
			_ARRAY_LIST[2].buffer[_ARRAY_LIST[0].length + q] = _ARRAY_LIST[1].buffer[j];
			_ARRAY_LIST[2].length += 1;
			q += 1;
		}
	}
}

void intersection_fun(void)
{
	int q = 0;

	for(int i = 0; i < _ARRAY_LIST[0].length; i++)
	{
		for(int j = 0; j < _ARRAY_LIST[1].length; j++)
		{	
			if(_ARRAY_LIST[0].buffer[i] == _ARRAY_LIST[1].buffer[j])
			{	
				_ARRAY_LIST[2].buffer[q] = _ARRAY_LIST[0].buffer[i];
				q += 1;
				_ARRAY_LIST[2].length += 1;
				break;
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
	int opt;

	cout << "Enter size of array1: ";
	cin >> _ARRAY_LIST[0].size;
	cout << "Enter number of elements array1: ";
	cin >> _ARRAY_LIST[0].length;

	_ARRAY_LIST[0].buffer = (int*) malloc(_ARRAY_LIST[0].size * sizeof(int));

	cout << "Enter array 1" << endl;
	for(int j = 0; j < _ARRAY_LIST[0].length; j++)
	{
			cout << "Enter element " << j << " array 1: ";
			cin >> _ARRAY_LIST[0].buffer[j];
	}

	cout << "Enter size of array2: ";
	cin >> _ARRAY_LIST[1].size;
	cout << "Enter number of elements array2: ";
	cin >> _ARRAY_LIST[1].length;

	_ARRAY_LIST[1].buffer = (int*) malloc(_ARRAY_LIST[1].size * sizeof(int));

	cout << "Enter array 2" << endl;
	for(int l = 0; l < _ARRAY_LIST[1].length; l++)
	{
			cout << "Enter element " << l << " array 2: ";
			cin >> _ARRAY_LIST[1].buffer[l];
	}

	_ARRAY_LIST[2].size = _ARRAY_LIST[0].size + _ARRAY_LIST[1].size;
	_ARRAY_LIST[2].length = 0;	

	_ARRAY_LIST[2].buffer = (int*) malloc(_ARRAY_LIST[2]. size * sizeof(int));

	cout << "1. Union" << endl;
	cout << "2. Intersection" <<endl;
	cout << "3. Difference" << endl;
	cout << "Enter you option: ";
	cin >> opt;	

	if(opt == 1)
	{
		union_fun();
	}
	else if(opt == 2)
	{
		sort_ascending(&_ARRAY_LIST[0]);
		remove_duplicates(&_ARRAY_LIST[0]);
		sort_ascending(&_ARRAY_LIST[1]);
		remove_duplicates(&_ARRAY_LIST[1]);
		intersection_fun();
	}
	else if(opt == 3)
	{
		sort_ascending(&_ARRAY_LIST[0]);
		remove_duplicates(&_ARRAY_LIST[0]);
		sort_ascending(&_ARRAY_LIST[1]);
		remove_duplicates(&_ARRAY_LIST[1]);
		difference();
	}

	display(&_ARRAY_LIST[2]);

	for(int i = 0; i < STRUCT_ARRAY_LENGTH; i++)
	{
		free(_ARRAY_LIST[i].buffer);
	} 

	return 0;
}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define STRUCT_ARRAY_LENGTH 2

typedef struct _ARRAY
{
        int* buffer;
        int size;
        int length;
} _ARRAY_OBJ;

_ARRAY_OBJ _ARRAY_LIST[STRUCT_ARRAY_LENGTH];

void display(_ARRAY_OBJ*);
int get_max(_ARRAY_OBJ*);
void hash_table(int);

void hash_table(int add)
{
    int i = 0;

    while(i < _ARRAY_LIST[0].length)
    {
        if(_ARRAY_LIST[1].buffer[add - _ARRAY_LIST[0].buffer[i]] == 1)
        {
            cout << _ARRAY_LIST[0].buffer[i] << " + " << add - _ARRAY_LIST[0].buffer[i] << " = " << add << endl; 
        }

        _ARRAY_LIST[1].buffer[_ARRAY_LIST[0].buffer[i]] = 1;
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


int get_max(_ARRAY_OBJ* array_ptr)
{
	int max = 0;
	for(int i = 0; i < array_ptr -> length; i++)
	{
		if(array_ptr -> buffer[i] > max)
		{
			max = array_ptr -> buffer[i];
		}
	}

	return max;
}

int main()
{
    int max_ele, add;

	cout << "Enter size of array: ";
	cin >> _ARRAY_LIST[0].size;
	cout << "Enter number of elements array: ";
	cin >> _ARRAY_LIST[0].length;

	_ARRAY_LIST[0].buffer = (int*) malloc(_ARRAY_LIST[0].size * sizeof(int));

    cout << "Enter array" << endl;
	for(int i = 0; i < _ARRAY_LIST[0].length; i++)
	{
        cout << "Enter element " << i << " of array: ";
        cin >> _ARRAY_LIST[0].buffer[i];
	}

    cout << "Enter sum: ";
    cin >> add;

    max_ele = get_max(&_ARRAY_LIST[0]);

    display(&_ARRAY_LIST[0]);

    _ARRAY_LIST[1].size = max_ele;
    _ARRAY_LIST[1].length = max_ele;
    _ARRAY_LIST[1].buffer = (int*) malloc(_ARRAY_LIST[1].size * sizeof(int));

    for(int j = 0; j < _ARRAY_LIST[1].length; j++)
    {
        _ARRAY_LIST[1].buffer[j] = 0;
    }

    hash_table(add);

    for(int i = 0; i < STRUCT_ARRAY_LENGTH; i++)
	{
		free(_ARRAY_LIST[i].buffer);
	} 

	return 0;
}
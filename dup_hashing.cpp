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
int sort_ascending(_ARRAY_OBJ*);
void hash_table(void);

void hash_table(void)
{
    int j = 0;

    while(j < _ARRAY_LIST[0].length)
    {
        _ARRAY_LIST[1].buffer[_ARRAY_LIST[0].buffer[j]] += 1;
        j += 1;
    }

    for(int i = 0; i < _ARRAY_LIST[1].length; i++)
    {
        if(_ARRAY_LIST[1].buffer[i] > 1)
        {
            cout << i << " -> " << _ARRAY_LIST[1].buffer[i] << endl;
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

int sort_ascending(_ARRAY_OBJ* array_ptr)
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

    return array_ptr -> buffer[array_ptr -> length - 1];
}

int main()
{
    int max_ele;

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

    max_ele = sort_ascending(&_ARRAY_LIST[0]);

    if(max_ele < _ARRAY_LIST[0].length)
    {
        max_ele = _ARRAY_LIST[0].length;
    }

    display(&_ARRAY_LIST[0]);

    _ARRAY_LIST[1].size = max_ele;
    _ARRAY_LIST[1].length = max_ele;
    _ARRAY_LIST[1].buffer = (int*) malloc(_ARRAY_LIST[1].size * sizeof(int));

    for(int j = 0; j < _ARRAY_LIST[1].length; j++)
    {
        _ARRAY_LIST[1].buffer[j] = 0;
    }

    hash_table();

    for(int i = 0; i < STRUCT_ARRAY_LENGTH; i++)
	{
		free(_ARRAY_LIST[i].buffer);
	} 

	return 0;
}
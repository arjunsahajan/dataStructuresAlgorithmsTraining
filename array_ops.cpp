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

void display(_ARRAY_OBJ*);
int get_array(_ARRAY_OBJ*, int);
void set_array(_ARRAY_OBJ*, int, int);
int get_max(_ARRAY_OBJ*);
int get_min(_ARRAY_OBJ*);
int calc_sum(_ARRAY_OBJ*);
void reverse_array(_ARRAY_OBJ*);
void rotate_right(_ARRAY_OBJ*, int);
void rotate_left(_ARRAY_OBJ*, int);
void sort_ascending(_ARRAY_OBJ*);
void insert_after_sorting(_ARRAY_OBJ*, int);
void merge(void);

void merge(void)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while(i < _ARRAY_LIST[0].length && j < _ARRAY_LIST[1].length)
	{
		if(_ARRAY_LIST[0].buffer[i] < _ARRAY_LIST[1].buffer[j])
		{
			_ARRAY_LIST[2].buffer[k] = _ARRAY_LIST[0].buffer[i];
			i += 1; 
		} 
		else
		{
			_ARRAY_LIST[2].buffer[k] = _ARRAY_LIST[1].buffer[j];
			j += 1;
		}
		k += 1;
	}

	for(; i < _ARRAY_LIST[0].length; i++)
	{
		_ARRAY_LIST[2].buffer[k] = _ARRAY_LIST[0].buffer[i];
		k += 1;
	}

	
	for(; j < _ARRAY_LIST[1].length; j++)
	{
		_ARRAY_LIST[2].buffer[k] = _ARRAY_LIST[1].buffer[j];
		k += 1;
	}
}

void insert_after_sorting(_ARRAY_OBJ* array_ptr, int ele)
{	
	int i = array_ptr -> length - 1;

	while(ele < array_ptr -> buffer[i])
	{
		array_ptr -> buffer[i + 1] = array_ptr -> buffer[i];
		i -= 1;
	}
	array_ptr -> buffer[i + 1] = ele;
	array_ptr -> length += 1;
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

void rotate_right(_ARRAY_OBJ* array_ptr, int times)
{
	int val;
	for(int i = 0; i < times; i++)
	{
		val = array_ptr -> buffer[array_ptr -> length - 1];
		for(int j = array_ptr -> length; j > 1; j--)
		{
			array_ptr -> buffer[j - 1] = array_ptr -> buffer[j - 2];
		}

		array_ptr -> buffer[0] = val;
	}
}

void rotate_left(_ARRAY_OBJ* array_ptr, int times)
{
	int val;
	for(int i = 0; i < times; i++)
	{
		val = array_ptr -> buffer[0];
		for(int j = 0; j < array_ptr -> length; j++)
		{
			array_ptr -> buffer[j] = array_ptr -> buffer[j + 1];
		}
		
		array_ptr -> buffer[array_ptr -> length - 1] = val;
	}
}

void reverse_array(_ARRAY_OBJ* array_ptr)
{
	int temp;
	for(int i = 0; i < (array_ptr -> length / 2); i++)
	{
		temp = array_ptr -> buffer[i];
		array_ptr -> buffer[i] = array_ptr -> buffer[array_ptr -> length - i - 1];
		array_ptr -> buffer[array_ptr -> length - i - 1] = temp;	
	}
}

int calc_sum(_ARRAY_OBJ* array_ptr)
{
	int sum = 0;
	for(int i = 0; i < array_ptr -> length; i++)
	{
		sum+= array_ptr -> buffer[i];
	}

	return sum;
}

int get_min(_ARRAY_OBJ* array_ptr)
{
	int min = array_ptr -> buffer[0];
	for(int i = 1; i < array_ptr -> length; i++)
	{
		if(array_ptr -> buffer[i] < min)
		{
			min = array_ptr -> buffer[i];
		}
	}

	return min;
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

int get_array(_ARRAY_OBJ* array_ptr, int index)
{
	return array_ptr -> buffer[index];
}

void set_array(_ARRAY_OBJ* array_ptr, int index, int num)
{
	array_ptr -> buffer[index] = num;
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
	int num, index, sum, right_rotate, left_rotate;
	char opt_y_or_n, opt_get_or_set;

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

	while(true)
	{
		cout << "Want to get/set element[y/n]?: ";
		cin >> opt_y_or_n;

		if(opt_y_or_n == 'y')
		{
			cout << "Get or Set[g/s]: ";
			cin >> opt_get_or_set;

			if(opt_get_or_set == 'g')
			{
				cout << "Enter index of element you want: ";
				cin >> index;
				num = get_array(&_array, index);
				cout << "Number at index " << index << " = " << num << endl;
			} 
			else if(opt_get_or_set == 's')
			{
				cout << "Enter index of element you want set: ";
				cin >> index;
				if(index > _array.length)
				{
					cout << "Overflow!!" << endl;
				}
				else 
				{
					cout << "Enter value: ";
					cin >> num;
					set_array(&_array, index, num);
					display(&_array);
				}
			}
		}
		else
		{
			break;
		}
	}

	cout << "Max element in array: " << get_max(&_array) << endl;
	cout << "Min element in array: " << get_min(&_array) << endl;
	
	sum = calc_sum(&_array);
	cout << "Sum of elements: " << sum << endl;
	cout << "Average: " << (sum / _array.length) << endl;	

	reverse_array(&_array);
	display(&_array);

	cout << "Enter number of right rotations: ";
	cin >> right_rotate;

	rotate_right(&_array, right_rotate);
	display(&_array);	

	cout << "Enter number of left rotations: ";
	cin >> left_rotate;

	rotate_left(&_array, left_rotate);
	display(&_array);

	sort_ascending(&_array);
	cout << "Array after sorting: ";
	display(&_array);
	
	while(true)
	{
		cout << "Insert elements to sorted array?[y/n]: ";
		cin >> opt_y_or_n;
		
		if(opt_y_or_n == 'y')
		{
			if(_array.length < _array.size)
			{
				cout << "Enter element to be inserted: ";
				cin >> num;
				
				insert_after_sorting(&_array, num);
			}
			else
			{
				cout << "Overflow!!" << endl;
				break;
			}
		}
		else 
		{
			break;
		}
	}
		
	display(&_array);	

	cout << "MERGE" << endl;
	
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
	_ARRAY_LIST[2].length = _ARRAY_LIST[0].length + _ARRAY_LIST[1].length;

	_ARRAY_LIST[2].buffer = (int*) malloc(_ARRAY_LIST[2]. size * sizeof(int));

	sort_ascending(&_ARRAY_LIST[0]);
	sort_ascending(&_ARRAY_LIST[1]);

	display(&_ARRAY_LIST[0]);
	display(&_ARRAY_LIST[1]);
	
	merge();
	display(&_ARRAY_LIST[2]);

	free(_array.buffer);	
	free(_ARRAY_LIST[0].buffer);	
	free(_ARRAY_LIST[1].buffer);
	free(_ARRAY_LIST[2].buffer);
	
	return 0;
}

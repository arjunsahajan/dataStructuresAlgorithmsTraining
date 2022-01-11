#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct STACK_STRUCT
{
	int* buffer;
	int top;
	int size;
} _STACK;

void allocate_mem(_STACK*);
void init_stack_top(_STACK*);
int check_empty(_STACK*);
int check_full(_STACK*);
void increment_stack_top(_STACK*);
void decrement_stack_top(_STACK*);
void display(_STACK*);
void push(_STACK*, int);
int pop(_STACK*);
void free_mem(_STACK*);

int pop(_STACK* stack_struct_ptr)
{	
	return stack_struct_ptr -> buffer[stack_struct_ptr -> top];	
}

void push(_STACK* stack_struct_ptr, int data)
{
	stack_struct_ptr -> buffer[stack_struct_ptr -> top] = data;
}

void display(_STACK* stack_struct_ptr)
{
	for(int i = 0; i < stack_struct_ptr -> size; i++)
	{
		cout << stack_struct_ptr -> buffer[i] << " ";
	}
	
	cout << endl;
}

void decrement_stack_top(_STACK* stack_struct_ptr)
{
	stack_struct_ptr -> top -= 1;
}

void increment_stack_top(_STACK* stack_struct_ptr)
{
	stack_struct_ptr -> top += 1;
}

int check_full(_STACK* stack_struct_ptr)
{
	if(stack_struct_ptr -> top == stack_struct_ptr -> size - 1)
	{
		return 1;
	}

	return 0;
}

int check_empty(_STACK* stack_struct_ptr)
{
	if(stack_struct_ptr -> top == -1)
	{
		return 1;
	}

	return 0;
}

void init_stack_top(_STACK* stack_struct_ptr)
{
	stack_struct_ptr -> top = -1;
}

void allocate_mem(_STACK* stack_struct_ptr)
{
	stack_struct_ptr -> buffer = (int*) malloc(stack_struct_ptr -> size * sizeof(int));
}

void free_mem(_STACK* stack_struct_ptr)
{
	free(stack_struct_ptr -> buffer);
}

int main()
{
	_STACK stack_struct_var;
	int data;
	char opt;
	int i = 0;

	cout << "Enter size of stack: ";
	cin >> stack_struct_var.size;

	allocate_mem(&stack_struct_var);

	init_stack_top(&stack_struct_var);

	while(true)
	{	
		if(!check_full(&stack_struct_var))
		{
			cout << "buf[" << i << "] = ";
			cin >> data;

			increment_stack_top(&stack_struct_var);
			push(&stack_struct_var, data);		
		}
		else
		{
			cout << "The stack is full" << endl;
			break;
		}	
		
		i += 1;
	}

	display(&stack_struct_var);

	while(!check_empty(&stack_struct_var))
	{
		cout << pop(&stack_struct_var) << " ";
		decrement_stack_top(&stack_struct_var);
	}

	cout << endl;
	
	free_mem(&stack_struct_var);

	return 0;
}

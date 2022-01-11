#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

typedef struct QUEUE_STRUCT
{
	int* buffer;
	int size;
	int front;
	int rear;
} _QUEUE;

bool is_empty(_QUEUE*);
bool is_full(_QUEUE*);
void init_front(_QUEUE*);
void init_rear(_QUEUE*);
void enqueue(_QUEUE*, int);
void dequeue(_QUEUE*);
void display(_QUEUE*);

void display(_QUEUE* queue_struct_ptr)
{
	for(int i = queue_struct_ptr -> front + 1; i < queue_struct_ptr -> size; i++)
	{
		cout << queue_struct_ptr -> buffer[i] << " ";
	}
	
	cout << endl;
}

void dequeue(_QUEUE* queue_struct_ptr)
{
	queue_struct_ptr -> front += 1;
}

void enqueue(_QUEUE* queue_struct_ptr, int data)
{
	queue_struct_ptr -> rear = (queue_struct_ptr -> rear + 1) & (queue_struct_ptr -> size - 1);
	queue_struct_ptr -> buffer[queue_struct_ptr -> rear] = data;
}

void init_front(_QUEUE* queue_struct_ptr)
{
	queue_struct_ptr -> front = -1;
}

void init_rear(_QUEUE* queue_struct_ptr)
{
	queue_struct_ptr -> rear = -1;
}

bool is_full(_QUEUE* queue_struct_ptr)
{
	if(queue_struct_ptr -> rear == queue_struct_ptr -> size - 1)
	{
		return true;
	}

	return false;
}

bool is_empty(_QUEUE* queue_struct_ptr)
{
	if(queue_struct_ptr -> front == queue_struct_ptr -> rear)
	{
		return true;
	}

	return false;
}

int main()
{
	_QUEUE queue_struct_var;

	cout << "Ente size of queue: ";
	cin >> queue_struct_var.size;

	init_front(&queue_struct_var);
	init_rear(&queue_struct_var);

	queue_struct_var.buffer = (int*) malloc(queue_struct_var.size * sizeof(int));

	for(int i = 0; i < queue_struct_var.size; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> queue_struct_var.buffer[i];

		if(!is_full(&queue_struct_var))
		{
			enqueue(&queue_struct_var, queue_struct_var.buffer[i]);
		}
	}

	enqueue(&queue_struct_var, 10);

	display(&queue_struct_var);

	dequeue(&queue_struct_var);
	
	display(&queue_struct_var);

	dequeue(&queue_struct_var);
	
	display(&queue_struct_var);
		
	free(queue_struct_var.buffer);
	
	return 0;
}

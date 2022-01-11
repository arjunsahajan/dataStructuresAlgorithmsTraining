#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct NODE
{
	int data;
	struct NODE* next;
} _Node;

_Node* top = NULL;

bool is_empty(void);
void create_head(int);
void push(int);
void display(void);
int pop(void);
void free_mem(void);

void free_mem(void)
{
	_Node* temp;

	while(top != NULL)
	{
		temp = top;
		top = top -> next;
		free(temp);
	}
}

int pop(void)
{
	_Node* temp = top;
	top = top -> next;

	return temp -> data;
}

void display(void)
{
	_Node* temp = top;

	while(temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> next;
	}

	cout << endl;
}

void push(int data)
{
	_Node* temp = (_Node*) malloc(sizeof(_Node));

	temp -> data = data;
	temp -> next = top;
	top = temp;
}

void create_head(int data)
{
	top = (_Node*) malloc(sizeof(_Node));

	top -> data = data;
	top -> next = NULL;
}

bool is_empty(void)
{
	if(top == NULL)
	{
		return 1;
	}

	return 0;
}

bool is_full(void)
{
	_Node* temp = (_Node*) malloc(sizeof(_Node));

	if(temp == NULL)
	{
		return 1;
	}	

	return 0;
}

int main()
{
	create_head(1);

	push(2);
	push(3);
	push(4);
	push(5);

	display();

	cout << pop() << endl;

	display();

	free_mem();

	return 0;
}



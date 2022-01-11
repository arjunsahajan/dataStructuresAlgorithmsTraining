#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE
{
	char data;
	struct NODE* next;
} _Node;

_Node* top = NULL;

bool is_empty(void);
void create_head(char);
void push(char);
void display(void);
char pop(void);
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

char pop(void)
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
		printf("%c ", temp -> data);
		temp = temp -> next;
	}

	printf("\n");
}

void push(char data)
{
	_Node* temp = (_Node*) malloc(sizeof(_Node));

	temp -> data = data;
	temp -> next = top;
	top = temp;
}

void create_head(char data)
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
	char exp[50] = "{[(a+b)*(c+d)]}";	
	char c;
	bool flag = true;
	_Node* prev = NULL;
	int ascii;
	
	for(int i = 0; i < strlen(exp); i++)
	{
		c = exp[i];

		if(is_empty())
		{
			create_head(c);
			prev = top;
		}
		else if(c == '{' || c == '[' || c == '(')
		{
			push(c);
			prev = top;
		}

		if(c == '}' || c == ']' || c == ')')
		{
			ascii = (int) c;

			if(ascii == ((int) prev -> data) + 1 || ascii == ((int) prev -> data) + 2)
			{
				pop();
				prev = top;
			}
			else
			{
				flag = false;
				break;
			}
		}
	}

	if(flag)
	{
		printf("Expression is correct\n");
	}
	else
	{
		printf("Expression is not correct\n");
	}

	free_mem();	

	return 0;
}



#include <iostream>
#include <stdlib.h>

using namespace std;

#define LINKED_ARRAY_LEN 2

typedef struct NODE
{
    int data;
    struct NODE *next;
} _Node;

_Node* head[LINKED_ARRAY_LEN];
_Node* tail[LINKED_ARRAY_LEN];

void init_nodes(_Node*);
void create_head(_Node*);

void init_nodes(_Node* linked_list_array)
{
	for(int i = 0; i < LINKED_ARRAY_LEN; i++)
	{
		linked_list_array[i][0] = NULL;
	}
}

void create_head(_Node* linked_array_pointer)
{
	
}

int main()
{
	head[0] = NULL;
	head[0] = (_Node*) malloc(sizeof(_Node));
	head[0] -> data = 3;

	init_nodes(&head);

	return 0;
}	

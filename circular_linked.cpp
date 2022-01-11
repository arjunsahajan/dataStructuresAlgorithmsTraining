#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct NODE
{
	int data;
	struct NODE *next;
} _Node;

_Node* head = NULL;
_Node* tail = NULL;

void create_head(void);
void append_list(int);
void display(void);

void display(void)
{
	_Node* temp = head;

	temp = temp -> next;

	while(temp != head)
	{
		cout << temp -> data << " ";
		temp = temp -> next;	
	}

	cout << endl;
}

void append_list(int data)
{
	_Node* new_node = (_Node*) malloc(sizeof(_Node));

	new_node -> data = data;
	new_node -> next = head;
	tail -> next = new_node;
	tail = new_node;
}

void create_head(void)
{
	head = (_Node*) malloc(sizeof(_Node));

	head -> next = head;
	tail = head;
}

int main()
{
	int data;
        char opt;

        create_head();

        while(true)
        {
                cout << "Enter more data[y/n]?: ";
                cin >> opt;

                if(opt != 'y')
                {
                        break;
                }

                cout << "Enter data: ";
                cin >> data;

                append_list(data);
        }

	display();

	return 0;
}

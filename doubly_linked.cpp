#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct NODE
{
    int data;
    struct NODE* next;
    struct NODE* prev;
} _Node;  

_Node* head = NULL;
_Node* tail = NULL;

void create_head(int);
void display(void);
void append_list(int);

void display(void)
{
    _Node* temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

void append_list(int data)
{
    _Node* temp = (_Node*) malloc(sizeof(_Node));

    temp -> data = data;
    temp -> prev = tail;
    tail -> next = temp;
    temp -> next = NULL;
    tail = temp;
}

void create_head(int data)
{
    head = (_Node*) malloc(sizeof(_Node));

    head -> data = data;
    head -> next = NULL;
    head -> prev = NULL;
    tail = head;
}

void free_all(void)
{
    _Node* node = head;
    _Node* temp;

    while(temp != NULL)
    {
        temp = node;
        node = node -> next;
        free(temp);
    }
}

void find_left_right(int data)
{
    _Node* temp = head;
    _Node* right = NULL;
    _Node* left = NULL;

    while(temp != NULL)
    {
        if(temp -> data == data)
        {
            right = temp -> next;
            left = temp -> prev;
            cout << left -> data << " & " << right -> data << endl;
            break;
        }

        temp = temp -> next;
    }
}

int main()
{
    create_head(2);

    append_list(1);
    append_list(2);
    append_list(3);
    append_list(4);

    display();

    find_left_right(3);

    free_all();

    return 0;
}
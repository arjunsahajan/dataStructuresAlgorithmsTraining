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
void display_list(void);
void free_all(void);
int find_sum(void);
int count_nodes(void);
int find_max(void);
int find_min(void);
int search_ele(int ele);
void insert_ele(int, int);
int delete_ele(int);
void sort_ascending(void);
int get_size(void);
void reverse_list(void);
void insert_into_sorted(int);
int check_if_sorted(void);
void remove_duplicates(void);
void concat_lists(void);
_Node* get_head(void);

_Node* get_head(void)
{
	return head;
}

//void concat_lists(void)
//{
//	_Node*
//}

void remove_duplicates(void)
{
	_Node* prev = head;
	_Node* cur = prev -> next;
	

	if(!check_if_sorted())
	{
		sort_ascending();
	}

	while(cur != NULL)
	{
		if(cur -> data == prev -> data)
		{
			delete_ele(cur -> data);
		}
	
		prev = prev -> next;
		cur = cur -> next;
	}
}

int check_if_sorted(void)
{
	_Node* prev = head;
	_Node* cur = prev -> next;

	while(cur != NULL)
	{
		if(prev -> data > cur -> data)
		{
			return 0;
		}
	
		prev = prev -> next;
		cur = cur -> next;
	}
}

void insert_into_sorted(int ele)
{
	_Node* cur = head;	
	int pos = 0;

	sort_ascending();

	while(true)
	{
		if(ele < cur -> data)
		{
			insert_ele(ele, pos);
			break;
		}
	
		if(cur -> next == NULL)
		{	
			insert_ele(ele, pos + 1);
			break;
		}

		pos += 1;
		cur = cur -> next;
	}
}

void reverse_list(void)
{
	_Node* temp = head;
	_Node* prev = NULL;
	_Node* cur = NULL;

	while(true)
	{
		prev = cur;
		cur = temp;	

		if(temp -> next == NULL)
		{
			head = cur;
			head -> next = prev;
			break;
		}

		temp = temp -> next;	
		cur -> next = prev;
	}
}

int get_size(void)
{
	_Node* temp = head;
	int size = 0;

	while(temp != NULL)
	{
		size += 1;
		temp = temp -> next;
	}

	return size;
}

void sort_ascending(void)
{
	_Node* counter_outer = head;
	_Node* counter_inner_1 = NULL;
	_Node* counter_inner_2 = NULL;
	_Node* temp = (_Node*) malloc(sizeof(_Node));

	while(true)
	{
		if(counter_outer -> next == NULL)
		{
			break;
		}

		counter_inner_1 = head;
		counter_inner_2 = counter_inner_1 -> next;

		while(true)
		{	
			if(counter_inner_1 -> data > counter_inner_2 -> data)
			{
				temp -> data = counter_inner_1 -> data;
				counter_inner_1 -> data = counter_inner_2 -> data;
				counter_inner_2 -> data = temp -> data;
			}
			
			if(counter_inner_2 -> next == NULL)
			{
				break;
			}

			counter_inner_1 = counter_inner_1 -> next;
			counter_inner_2 = counter_inner_1 -> next;
		}

		counter_outer = counter_outer -> next;
	}

	free(temp);
}

int delete_ele(int data)
{
	_Node* prev = head;
	_Node* cur = head;

	cur = cur -> next;

	while(true)
	{
		if(head -> data == data)
		{
			head = cur;
			return 1;
		}

		if(cur -> data == data)
		{
					
			if(cur -> next == NULL)
			{
				prev -> next = NULL;
			} 
			else
			{

				prev -> next = cur -> next;
			}

			return 1;
		}

		if(cur -> next == NULL)
		{
			return 0;
		}

		prev = prev -> next;
		cur = cur -> next;
	}
}

void insert_ele(int data, int pos)
{
	_Node* node_new = (_Node*) malloc(sizeof(_Node));
	_Node* temp = head;	
	int count = 0;

	node_new -> data = data;

	while(temp != NULL)
	{
		if(count == pos)
		{
			if(count == 0)
			{
				node_new -> next = head;
				head = node_new;
			}
			else 
			{
				if(temp -> next == NULL)
				{
					temp -> next = node_new;
					node_new -> next = NULL;
				}
				else 
				{
					node_new -> next = temp -> next;
					temp -> next = node_new;
				}
				
				break;
			}
		}		
		
		if(count > 0)
		{
			temp = temp -> next;
		}

		count += 1;
	}
}

int search_ele(int ele)
{
	_Node* temp = head;
	
	while(temp != NULL)
	{
		if(temp -> data == ele)
		{
			return 1;
		}

		temp = temp -> next;
	}	

	return 0;
}

int find_min(void)
{
	_Node* temp = head;
	int min = temp -> data;
	temp = temp -> next;

	while(temp != NULL)
	{
		if(temp -> data < min)
		{
			min = temp -> data;
		}	

		temp = temp -> next;
	}

	return min;

}

int find_max(void)
{
	_Node* temp = head;
	int max = 0;

	while(temp != NULL)
	{
		if(temp -> data > max)
		{
			max = temp -> data;
		}

		temp = temp -> next;
	}

	return max;
}

int count_nodes(void)
{
	_Node* temp = head;
	int count = 0;

	while(temp != NULL)
	{
		count += 1; 
		temp = temp -> next;
	}

	return count;
}

int find_sum(void)
{
	_Node* temp = head;
	int sum_ = 0;	

	while(temp != NULL)
	{
		sum_ += temp -> data;
		temp = temp -> next;
	}

	return sum_;
}

void free_all(void)
{
	_Node* node = head;
	_Node* temp;

	while(node!= NULL)
	{	
		temp = node;
		node = node -> next;
		free(temp);
	}

	head = NULL;
}

void display_list(void)
{
	_Node* temp = head;

	if(temp == NULL)
	{
		cout << "The list is empty" << endl;
	}

	while(temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> next;
	}

	cout << endl;
}

void create_head(int data)
{
	head = (_Node*) malloc(sizeof(_Node));
	tail = (_Node*) malloc(sizeof(_Node));
	
	head -> data = data;
	head -> next = NULL;
	tail = head;
}

void append_list(int data)
{
	_Node* new_element_node = (_Node*) malloc(sizeof(_Node));

	new_element_node -> data = data;
	new_element_node -> next = NULL;
	tail -> next = new_element_node;
	tail = new_element_node;	
}

int main()
{
	int head_data, element, pos;
	char opt;

	cout << "Enter head data: ";
	cin >> head_data;

	create_head(head_data);

	while(true)
	{
		cout << "Enter more elements[y/n]?: ";
		cin >> opt;

		if(opt != 'y')
		{
			break;
		}
		
		cout << "Enter element: ";
		cin >> element;

		append_list(element);
	}	

	display_list();

	cout << "Sum of all elements: " << find_sum() << endl;
	cout << "Number of elements: " << count_nodes() << endl;
	cout << "Max element is: " << find_max() << endl;
	cout << "Min element is: " << find_min() << endl;
	
	_Node* head_pointer = NULL;
	head_pointer = get_head();

	cout << "Head data = " << head_pointer -> data << endl;

	if(check_if_sorted())
	{
		cout << "The list is sorted" << endl;
	}
	else
	{
		cout << "The list is not sorted" << endl;
	}

	while(true)
	{
		cout << "Want to search an element[y/n]?: ";
		cin >> opt;

		if(opt != 'y')
		{
			break;
		}

		cout << "Enter element to be searched for: ";
		cin >> element;

		if(search_ele(element))
		{
			cout << element << " is present" << endl;
		}
		else
		{
			cout << element << " is not present" << endl;
		}	
	}

	while(true)
	{
		cout << "Want to insert an element[y/n]?: ";
		cin >> opt;

		if(opt != 'y')
		{
			break;
		}

		cout << "Enter element to be inserted: ";
		cin >> element;
		cout << "Enter position: ";
		cin >> pos;

		insert_ele(element, pos);	
	}

	display_list();

	while(true)
	{
		cout << "Want to delete an element[y/n]?: ";
		cin >> opt;

		if(opt != 'y')
		{
			break;
		}

		cout << "Enter element to be deleted: ";
		cin >> element;
		if(delete_ele(element))
		{
			cout << element << " was deleted from the list" << endl;
		}
		else 
		{
			cout << element << " is not present in the list" << endl;
		}
	}

	cout << "Enter element to be inserted into the sorted array: ";
	cin>> element;

	insert_into_sorted(element);
	
	display_list();
	
	cout << "List after removing duplicates: ";
	remove_duplicates();
	
	display_list();
//
//	sort_ascending();
//
//	cout << "List after sorting: "; 
//	display_list();
//      
	reverse_list();
	cout << "List after reversing: "; 
	display_list();

	free_all();

	return 0;
}

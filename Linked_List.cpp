#include "Linked_List.h"
#include <iostream>

/* Linked list default constructor initializes pointer members to nullptr*/
Linked_List::Linked_List()
	:head{ nullptr }, tail{nullptr}
{
	std::cout << "Linked_list default constructor"; 
}

/* Linked list destructor calls free_node function member to destruct each
	node and deallocate it in the linked list*/
Linked_List::~Linked_List()
{
	free_Nodes(); 
	std::cout << "Linked_List freed"; 
}

/* Overloaed Node constructor will 1 prameter initalizes data and pointer*/
Linked_List::Node::Node(int data_Pram)
	:data{ data_Pram }, next{nullptr}
{
	std::cout << "Node " << data << " allocated";
}

/* Destructs Node*/
Linked_List::Node::~Node() 
{
	std::cout << "Node " << data << " destroyed"; 
}

/* Void function destructors and deallocates each node in the linked list using 
	local pointers and loop control structure*/
void Linked_List::free_Nodes() 
{
	Node* cursor{ head };
	Node* doomed{ cursor }; 
	/* If cursor is not null traverse to next Node
	in the linked list and delete each node*/
	while (cursor != nullptr) 
	{
		// Traverse next node 
		cursor = cursor->next;
		// Delete prev node
		delete doomed; 
		// Assign to next node 
		doomed = cursor; 
	}
}

/* Void member function adds a node to head of the linked list*/
void Linked_List::add_First(int data) 
{
	Node* temp{nullptr};
	temp = this->create_Node(data); 
	if (head == nullptr) 
	{
		head = temp; 
		tail = temp; 
	}
	else 
	{
		// Have temp pointer hold the address of the current head node
		temp->next = head; 
		// temp becomes the new head 
		head = temp; 
	} 
}

/* Void memeber function will add a node at end of the linked_list*/
void Linked_List::add_Last(int data_Pram) 
{
	Node* temp = create_Node(data_Pram); 
	if (tail == nullptr) 
	{
		tail = temp; 
		head = temp; 
	}
	else 
	{
		// Assign to next of the list
		tail->next = temp; 
		// temp pointer is now the tail pointer
		tail = temp; 
	}
}

/* Void memeber function removes the first node in the list*/
void Linked_List::remove_First() 
{
	if (head != nullptr) 
	{
		
		// Initalize local pointer to the head node
		Node* temp = head; 
		// Re-assigin current head to the next node
		head = head->next;
		// Delete previous head node
		delete temp;

	}
}

/* Void member function removes the last node in the list*/
void Linked_List::remove_Last() 
{
	if (tail != nullptr) 
	{
		// Initialze local pointer to tail pointer
		Node* temp = tail; 
		// Initalize cursor pointer to head
		Node* cursor = head; 

		// Locate Node before tail node and reassign node pointer memebers
		while (cursor != tail) 
		{
			// Traverse next node
			cursor = cursor->next; 
		}
		cursor->next = tail->next; 
		tail = cursor;
		// Delete old tail node
		delete temp; 
	}
}

/* Void function memeber inserts Node index specified by the arugment*/
void Linked_List::insert_Node(int index) 
{
	if (index < 0 || index >= 8)
	{
		throw out_of_range{};
	}
	else 
	{
		
	}
}

/* Bool returning function member linear searches list for argument passed on to it*/
bool Linked_List::search(const int &data_Pram) 
{
	Node* cursor{ head };
	while (cursor != nullptr) 
	{
		cursor = cursor->next; 
		if (cursor->data == data_Pram) 
		{
			return 1; 
		}
	}
	return 0; 
}

/* int returning function iterates through list and returns its size*/
int Linked_List::get_Size() 
{
	Node* cursor = head;
	int count{ 0 }; 
	while (cursor != nullptr) 
	{
		cursor = cursor->next; 
		count++; 
	}
	return count; 
}

/* Void memeber function iterates through the list compares data if found delete it from the
	list*/
void Linked_List::remove_Node(int data) 
{
	Node* cursor = head; 
	if (search(data) == true) 
	{
		while (cursor->data != data) 
		{
			cursor = cursor->next; 
		}
		int data_Found = cursor->data;
		delete cursor;
	}
}
/* Node* returning function member allocates and initalizes a node on the heap */
Linked_List::Node* Linked_List::create_Node(int data_Pram)
{
	return new Node(data_Pram); 
}
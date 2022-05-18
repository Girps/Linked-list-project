#include "Linked_List.h"
#include <iostream>
#include <stack>

/* Linked list default constructor initializes pointer members to nullptr*/
Linked_List::Linked_List()
	:head{ nullptr }, tail{ nullptr }, size{0}
{
	std::cout << "Linked_list default constructor"; 
}

/* Deep copy constructor passes by const reference linked list copies data into current instance*/
Linked_List::Linked_List(const Linked_List& rr_List)
	:head{ nullptr }, tail{ nullptr }, size{0}
{
	printf("Deep copy constructor called\n");
	Node* cursor = rr_List.head; 
	while (cursor != nullptr) 
	{
		// Add data to current structure and inc size
		this->add_Last(cursor->data); 
		cursor = cursor->next;
	}
}

/* Move constructor passess RR sturcture and gives resources to calling construtor object*/
Linked_List::Linked_List(Linked_List&& rr_List) 
{
	printf("\nMove constructor called\n");
	// Assign this instances pointers to rr_List pointer memebers 
	this->size = rr_List.size; 
	this->head = rr_List.head; 
	this->tail = rr_List.tail; 
	// Reassign rr_List pointers to nullptr
	rr_List.head = nullptr;
	rr_List.tail = nullptr; 
	rr_List.size = 0; 
}

/*Assigment overloaded operator copies data from lvalue onto calling function object list 
	returns a refences to support assignment chaining */
Linked_List& Linked_List::operator = (const Linked_List& l_List) 
{
	printf("Deep assignement copy called\n");
	// If this instance list is not empty free it 
	if (this->head != nullptr) 
	{
		this->free_Nodes();
	} // Avoid self assignment 
	else if (this != &l_List)
	{
		// Copy node data form lvaule onto calling object
		Node* cursor = l_List.head;
		while (cursor != nullptr)
		{
			// Add data to current structure and inc size
			this->add_Last(cursor->data);
			cursor = cursor->next;
		}
	}
	return *this; 
}

/*Move assignment operators passess RR structures and gives resources to calling function object
	and returns calling object instance to support assigment chaining */
Linked_List& Linked_List::operator = (Linked_List&& rr_List) 
{
	printf("Move assignment copy called\n");
	// Assign this instances pointers to rr_List pointer memebers 
	this->size = rr_List.size;
	this->head = rr_List.head;
	this->tail = rr_List.tail;
	// Reassign rr_List pointers to nullptr
	rr_List.head = nullptr;
	rr_List.tail = nullptr;
	rr_List.size = 0;
	return *this; 
}

/* Bool returning function, compares size and data between linked lists*/
bool Linked_List::operator == (const Linked_List& l_list) 
{
	if (this->size != l_list.size) 
	{
		return false; 
	}
	else 
	{
		Node* this_Ptr{ this->head }; 
		Node* other_Ptr{ l_list.head }; 
		while (this_Ptr != nullptr) 
		{
			if (this_Ptr->data != other_Ptr->data) 
			{
				return false; 
			}
			this_Ptr = this_Ptr->next;
			other_Ptr = other_Ptr->next;
		}
	}

	return true; 
}

/* Linked list destructor calls free_node function member to destruct each
	node and deallocate it in the linked list*/
Linked_List::~Linked_List()
{
	free_Nodes(); 
	std::cout << "\nLinked_List freed"; 
}

/* Overloaed Node constructor will 1 prameter initalizes data and pointer*/
Linked_List::Node::Node(int data_Pram)
	:data{ data_Pram }, next{nullptr}
{
	std::cout << "\nNode " << data << " allocated";
}

/* Destructs Node*/
Linked_List::Node::~Node() 
{
	std::cout << "~[" << data << "]";
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
	head = nullptr; 
	tail = nullptr; 
	size = 0; 
}

/* Void member function adds a node to head of the linked list*/
void Linked_List::add_First(int data) 
{
	// Increment size
	this->size++; 
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
	// Increment size
	this->size++;
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
		// Decrement size
		this->size--; 
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
		while (cursor->next != tail) 
		{
			// Traverse next node
			cursor = cursor->next; 
		}
		cursor->next = tail->next; 
		tail = cursor;
		// Delete old tail node
		delete temp; 
		// Decrement size
		this->size--;
	}
}

/* Void function memeber inserts Node index specified by the arugment*/
void Linked_List::insert_Node(int data, int index) 
{
	if (index < 0 || index >= this->size)
	{
		throw out_of_range{};
	}
	else if (index == 0) 
	{
		add_First(data); 
	}
	else if (index == this->size)
	{
		add_Last(data); 
	}
	else 
	{
		int count = index-1; 
		// Allocate and intialize node 
		Node* temp = create_Node(data);
		Node* cursor = head; 
		while (count != 0) 
		{
			count--; 
			cursor = cursor->next; 
		}
		// Move pointers 
		temp->next = cursor->next; 
		cursor->next = temp;
		// Increment size
		this->size++; 
	}
}

/* Bool returning function member linear searches list for argument passed on to it*/
bool Linked_List::search(const int &data_Pram) const
{
	Node* cursor{ head };
	while (cursor != nullptr) 
	{
		if (cursor->data == data_Pram) 
		{
			return 1; 
		}
		cursor = cursor->next;
	}
	return 0; 
}

/* Int returning getter function returns size of list*/
int Linked_List::get_Size() const 
{
	return this->size; 
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
		this->size--; 
	}
}

/* Node* returning function member allocates and initalizes a node on the heap */
Linked_List::Node* Linked_List::create_Node(int data_Pram)
{
	return new Node(data_Pram); 
}

/* Void returning function traverses list and outputs data in node */
void Linked_List::traverse_List() const
{
	std::cout << "\n"; 
	Node* cursor = head; 
	// Iterate until it reaches the end of the list 
	while (cursor != nullptr) 
	{
		std::cout << "[ " << cursor->data << " ]---";
		cursor = cursor->next; 
	}
	std::cout << "NULL\n"; 
}

/* Void function uses the stack data structure to reassign pointers of each node to their prior node*/
void Linked_List::reverse_list() 
{
	std::stack<Node*>loc_Stack;
	Node* cursor = head; 
	// Push node addresses onto the stack
	for (int i = 0; i < this->size; i++) 
	{
		loc_Stack.push(cursor);
		cursor = cursor->next; 
	}
	Node* temp{ nullptr }; 
	Node* new_Head{ tail };
	Node* new_Tail{ head }; 
	// Top and pop stack and reassign pointers 
	for (int i =0; i < this->size; i++) 
	{
		temp = loc_Stack.top(); 
		loc_Stack.pop(); 
		if (loc_Stack.empty()) 
		{
			temp->next = nullptr;
		}
		else
		{
			temp->next = loc_Stack.top();
		}
	}
	head = new_Head; 
	tail = new_Tail; 
}
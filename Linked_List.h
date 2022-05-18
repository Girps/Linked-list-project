#pragma once

struct out_of_range {};

class Linked_List 
{ 		
	private: 

		/*Nested Node class store data and pointers to other nodes*/
		struct Node 
		{
			// Node data fields 
			int data; 
			Node* next;
			// Overloaded explicit constructor 
			explicit Node(int pram_Data);
			// Node Destructor 
			~Node(); 
		};
		// private data fields 
		Node* head; 
		Node* tail; 
		int size;

		// private function memebers
		Node* create_Node(int data);  
	public:
		// Default Constructor
		Linked_List(); 
		// Deep copy constructor
		Linked_List(const Linked_List &rr_List);
		// Move constructor
		Linked_List(Linked_List&& rr_List); 
		// Destructor 
		~Linked_List();
		// Move assignent overloaded operator
		Linked_List& operator = (Linked_List && rr_List);
		// Deep copy assignment overloaded operator
		Linked_List& operator = (const Linked_List& l_List); 

		// Function members declarations 
		void add_First(int data); 
		void add_Last(int data); 
		void remove_First(); 
		void remove_Last(); 
		void insert_Node(int data,int index);  
		int get_Size() const; 
		bool search(const int &data) const; 
		void remove_Node(int data);
		void traverse_List() const;
		void reverse_list(); 
		void free_Nodes();
};
#pragma once

struct out_of_range {};

template<typename T>
class Linked_List 
{ 		
	private: 

		/*Nested Node class store data and pointers to other nodes*/
		struct Node 
		{
			// Node data fields 
			T data; 
			Node* next;
			// Overloaded explicit constructor 
			explicit Node(T pram_Data);
			// Node Destructor 
			~Node(); 
		};
		// private data fields 
		Node* head; 
		Node* tail; 
		int size;

		// private function memebers
		Node* create_Node(T data);  
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
		
		bool operator == (const Linked_List& l_list); 

		// Function members declarations 
		void add_First(T data); 
		void add_Last(T data); 
		void remove_First(); 
		void remove_Last(); 
		void insert_Node(T data,int index);  
		int get_Size() const; 
		bool search(const T &data) const; 
		void remove_Node(T data);
		void traverse_List() const;
		void reverse_list(); 
		void free_Nodes();
};
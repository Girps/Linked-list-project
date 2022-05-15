#pragma once

struct out_of_range {};

class Linked_List 
{ 		
	public: 
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

		Node* head; 
		Node* tail; 
		int list_Size; 

		Node* create_Node(int data); 
		void free_Nodes(); 
	public:
		// Default Constructor
		Linked_List(); 
		// Destructor 
		~Linked_List();
		// I litterally changing some stuff
		// Function members declarations 
		void add_First(int data); 
		void add_Last(int data); 
		void remove_First(); 
		void remove_Last(); 
		void insert_Node(int index); 
		void remove_Node(int data); 
		int get_Size();
		bool search(const int &data); 
};
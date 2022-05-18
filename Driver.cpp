#include <iostream>
#include "Linked_List.h"
#include <time.h>
#include <stack>
void add_First_Test( Linked_List& rr_list, int n, int range); 
void add_Last_Test(Linked_List& rr_list, int n, int range);
void remove_First_Test(Linked_List& rr_List, int n); 
void remove_Last_Test(Linked_List& rr_List,int n);
void test_Search(const Linked_List & rr_list,int n,int range);


int main() 
{
	/*std::stack<int> s; 
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);


	printf("%d",s.size());
	printf("%d", s.top());
	s.pop(); 
	printf("%d",s.top());*/
	

	// Allocate UDT on the stack
	Linked_List list; 
	// Set seed to the PC clock
	srand(time(NULL));

	// Test first and last function memebers
	add_First_Test(list, 5, 10);
	list.traverse_List();
	remove_First_Test(list,2); 
	list.traverse_List();
	add_Last_Test(list, 2, 10);
	list.traverse_List(); 
	remove_Last_Test(list, 2);
	list.traverse_List(); 

	// Test insert and remove nodes of the linked list
	list.insert_Node(69,2);
	list.traverse_List(); 
	list.insert_Node(70, 3); 
	list.traverse_List(); 
	
	// Test search function 
	test_Search(list,5,10);
	
	// Reverse our linked list and traverse it 
	printf("Test reverse a linked list");
	list.reverse_list(); 
	list.traverse_List(); 

	//list.insert_Node(1, 100); 
	return 0; 

}

void test_Search(const Linked_List& rr_List, int n, int range) 
{
	printf("Search function called\n");
	// Iterate n amount of times search for random numbers 0 to range - 1
	for (int i = 0; i < n; i++) 
	{
		int search = rand() % range;
		if (rr_List.search(search) == true) 
		{
			printf("%d is in the linked list\n ",search);
		}
	}
}

/* void returngin function adds node at the end of the list n amount of times and range of 0 to (range - 1)*/
void add_Last_Test(Linked_List& rr_list, int n, int range) 
{
	printf("Add last function called\n");
	int num{ 0 };
	// Push int values between 0 and (range - 1) 
	for (int i = 0; i < n; i++)
	{
		num = rand() % range;
		rr_list.add_Last(num);
	}
}

/* Void function passes LL by ref and pushes size_Amount of of random integers between 0 and range-1  */
void add_First_Test( Linked_List& rr_list, int size_Amount, int range)
{
	printf("Add first function called\n");
	int num{ 0 }; 
	// Push int values between 0 and (range - 1) 
	for (int i = 0; i < size_Amount; i++) 
	{
		num = rand() % range; 
		rr_list.add_First(num);
	}
}

/* Void remove amount of nodes in a linked list depending on value of remove_Amount*/
void remove_First_Test(Linked_List& rr_List, int n) 
{
	printf("Remove first function called\n");
	// remove first node n amount of times
	for (int i =0; i < n;i++) 
	{
		rr_List.remove_First(); 
	}
}
void remove_Last_Test(Linked_List& rr_List, int n) 
{
	printf("Add last function called\n");

	for (int i =0; i < n; i++) 
	{
		rr_List.remove_Last();
	}
}
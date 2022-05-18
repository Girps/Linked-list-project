#include <iostream>
#include "Linked_List.h"
#include <time.h>
#include <stack>
void add_First_Test( Linked_List& rr_list, int n, int range); 
void add_Last_Test(Linked_List& rr_list, int n, int range);
void remove_First_Test(Linked_List& rr_List, int n); 
void remove_Last_Test(Linked_List& rr_List,int n);
void test_Search(const Linked_List & rr_list,int n,int range);
Linked_List ret_LList(); 

int main() 
{

	// Allocate UDT on the stack
	Linked_List list; 
	
	Linked_List sec_List; 
	add_First_Test(sec_List, 5, 10);
	printf("Sec list nodes");
	sec_List.traverse_List(); 
	// Deep deep copy assignemnt operator
	list = sec_List; 
	printf("list nodes");
	list.traverse_List(); 
	list.add_First(69);
	sec_List.traverse_List();
	list.traverse_List(); 

	// Move assignment called 
	list = ret_LList(); 
	list.traverse_List(); 

	Linked_List list3 = list;
	list3.add_First(69);
	list3.traverse_List(); 
	return 0; 

}
Linked_List ret_LList() 
{
	Linked_List rr_List; 
	printf("\nMove test function called\n");
	// Iterate n amount of times search for random numbers 0 to range - 1
	int num{ 0 };
	// Push int values between 0 and (range - 1) 
	for (int i = 0; i < 5; i++)
	{
		num = rand() % 10;
		rr_List.add_First(num);
	}
	return rr_List; 
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
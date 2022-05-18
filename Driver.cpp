#include <iostream>
#include "Linked_List.h"
#include "Linked_List.cpp"
#include <time.h>
#include <string>

template<typename T>
void add_First_Test( Linked_List<T>& rr_list, int n, int range);
template<typename T>
void add_Last_Test(Linked_List<T>& rr_list, int n, int range);
template<typename T>
void remove_First_Test(Linked_List<T>& rr_List, int n);
template<typename T>
void remove_Last_Test(Linked_List<T>& rr_List,int n);
template<typename T>
void test_Search(const Linked_List<T>& rr_list,int n,int range);
template<typename T>
Linked_List<T> ret_LList(); 

int main() 
{
	Linked_List<std::string> list; 
	list.add_First("jesse");
	list.traverse_List(); 
	return 0; 

}
template<typename T>
Linked_List<T> ret_LList() 
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
template<typename T>
void test_Search(const Linked_List<T>& rr_List, int n, int range) 
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
template<typename T>
void add_Last_Test(Linked_List<T>& rr_list, int n, int range) 
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
template<typename T>
void add_First_Test( Linked_List<T>& rr_list, int size_Amount, int range)
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
template<typename T>
void remove_First_Test(Linked_List<T>& rr_List, int n) 
{
	printf("Remove first function called\n");
	// remove first node n amount of times
	for (int i =0; i < n;i++) 
	{
		rr_List.remove_First(); 
	}
}

template<typename T>
void remove_Last_Test(Linked_List<T>& rr_List, int n) 
{
	printf("Add last function called\n");

	for (int i =0; i < n; i++) 
	{
		rr_List.remove_Last();
	}
}
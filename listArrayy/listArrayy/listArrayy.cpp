// listArrayy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<iostream>
using namespace std;
//******************************************************************
class List
{
public:
	List(int = 10);  //constructor with the default value of its parameter
	~List();   //destructor
	bool isFull() const;
	bool isEmpty() const;
	int  length() const;		//The number of list items is returned.
	void makeEmpty();
	int  searchUnsorted(int) const;   //If found, index of the 1st occurrence
									  //of item is returned, otherwise -1.
	void addItem(int);     	//It inserts an item at the list end.
	int deleteItem(int); 	//It deletes and returns an item.
	void printList() const;
protected:
	int max; 		//array size
	int last;		//index of the last list item 
	int* array;		//pointer to the first element of a dynamic  array	
};//List 





  //***************************************************************
  // class List methods 
  //**************************************************************
List::List(int n)		//n is the expected maximum number of items in a list.
{
	max = n;		//Array size. 
	last = -1;
	array = new int[max]; 	//Dynamic array is created.
}//constructor
 //**************************************************************
List::~List()
{
	last = -1;
	delete[]array;
}//destructor
 //**************************************************************
void List::makeEmpty()
{
	last = -1;
}// makeEmpty
 //**************************************************************
bool List::isEmpty() const
{
	return (last == -1);
}// isEmpty
 //**************************************************************
bool List::isFull() const
{
	return (last == max - 1);
}// isFull
 //**************************************************************
int List::length() const
{
	return (last + 1);
}// length
 //**************************************************************
int List::searchUnsorted(int item) const
{
	for (int i = 0; i <= last; i++)
		if (array[i] == item)
			return i;
	return -1;
}//searchUnsorted 
 //**************************************************************
void List::addItem(int item)
{
	if (isFull())
		cout << "Memory overflow: item cannot be added to list.";
	else
		array[++last] = item;   //item is added at the end of unsorted list.
}
// addItem
 //**************************************************************
int List::deleteItem(int item)
{
	if (!isEmpty())
	{
		int k = searchUnsorted(item);
		if (k == -1)
			cout << "\nInvalid argument:Item was NOT FOUND in list.\n";
		else
		{
			int dataReturned = array[k];
			//The last item overwrites the deleted item.
			array[k] = array[last--];
			return dataReturned;
		}
	}
	else	//list is empty
		cout << "\nList underflow: item cannot be deleted.\n";
	return -10000; //to signal that deleting failed if NOT FOUND or EMPTY
}//deleteItem
 //************************************************************







void List::printList() const
{
	cout << "\nList contents:\n";
	if (last == -1)
		cout << "\nPrinting failed: list is empty\n";
	else
	{
		for (int i = 0; i <= last; i++)
			cout << array[i] << ", ";
		cout << endl;
	}//else
}//printList 
 //*************************************************************
void main()
{
	cout << "\nExperimenting with unsorted list of integer numbers:\n\n";
	List  B(20);	  //An empty list B is created. It can store up to 20 items.
	int a1;
	for (int i = 1; i <= 19; i++)
	{
		cout << "Enter int number, -1 to stop ==> ";
		cin >> a1;
		if (a1 != -1)
			B.addItem(a1);
		else	break;	   //go outside the loop block
	}
	B.printList();
	system("pause");

}//main


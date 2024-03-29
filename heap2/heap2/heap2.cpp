#include "stdafx.h"
#include <iostream>

using namespace std;



struct Node {
	//data members
	int data;
	Node *next;
	// constructors
	Node();
	Node(int d, Node *link = NULL);
}; // struct Node = class Node all members have public access by default
class List {
public:
	// methods of the List ADT
	List();  //default constructor
	~List();  //destructor
	bool isFull();
	bool isEmpty();
	void makeEmpty();
	int listSize();
	void printList();
	bool search(int item);
	int retrieve(int item);
	int deleteItem(int item);
	void addItem(int item);
	void heapify(int arr[], int n, int i);
	void heapSort(int arr[], int n);
	void printArray(int arr[], int n);
	void toArr();
private:
	// data members for linked list implementation
	int count;
	Node *first;
};//List

int main()
{
	
	List A;
	if (!A.isFull())
		A.addItem(20);
	else
		cout << "List was full. Item was not added\n";
	A.printList();
	if (!A.isFull())
		A.addItem(30);
	else
		cout << "List was full. Item was not added\n";
	A.printList();
	if (!A.isFull())
		A.addItem(40);
	else
		cout << "List was full. Item was not added\n";
	A.printList();
	if (!A.isFull())
		A.addItem(70);
	else
		cout << "List was full. Item was not added\n";
	A.printList();
	if (A.search(60))
		cout << "deleted item = " << A.deleteItem(60) << endl;
	else
		cout << "Item was not found. Item was not deleted\n";
	A.printList();
	if (A.search(30))
		cout << "deleted item = " << A.deleteItem(30) << endl;
	else
		cout << "Item was not found. Item was not deleted\n";
	A.printList();
	toArr();
	cout << arr[3];
	//deleting without checking the precondition
	/*cout « "deleted item = " « A.deleteItem(60) « endl;
	A.printList();

	cout « "retrieved item = " « A.retrieve(40) « endl;  //without checking the precondition
	A.printList();
	cout « "list size = " « A.listSize() « endl;*/
	
	//int n = sizeof(arr) / sizeof(arr[0]);

	//A.heapSort(arr, n);

	cout << "Sorted array is \n";
	//A.printArray(arr, n);
	system("PAUSE");
	return 0;

}//main
void List::heapify(int arr[], int n, int i)
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

						// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}
void List::toArr() {
	
	int arr[6];
	int i = 0;
	Node *previous = NULL, *following = first;
	while (following->next != NULL)
	{
		arr[i] = following->data;
		following = following->next;
		i++;
	}
}

// main function to do heap sort
void List::heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}
void List::printArray(int arr[], int n)
{
	for (int i = 0; i<n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}
/* A utility function to print array of size n */

Node::Node()
{
	next = NULL;
}  //constructor for an empty node

Node::Node(int item, Node * link)
{
	data = item;
	next = link;
}  //node constructor with initial values
bool List::isEmpty()
{
	return count == 0; // return first == NULL;  }//empty
}
List::List()
{
	count = 0;
	first = NULL;
}//empty

List::~List()
{
	count = 0;
	Node *temp;
	while (first != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
}//~List

int List::listSize()
{
	return count;
}//listSize

bool List::isFull()
{
	bool result = false;
	Node *temp;
	temp = new Node();
	if (temp == NULL) result = true;
	else           delete temp;
	return result;
}//isFull

void List::makeEmpty()
{
	count = 0;
	Node *temp;
	while (first != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
}//makeEmpty

void List::addItem(int item)
//List unsorted: item is always inserted at the beginning of a list.
{
	if (isFull()) {
		cout << "List overflow\n";
		return; //return to the calling function//??????????????????
	}
	else {
		Node *previous = NULL, *following = first;
		while (following != NULL && following->data < item) {
			previous = following;
			following = following->next;
		}
		if (previous == NULL)
			first = new Node(item, first);
		else previous->next = new Node(item, following);
		count++;
	}
}//addItem

bool List::search(int item)
//returns true if item is in list, false otherwise
{
	Node *p = first;
	while (p != NULL)
	{
		if (p->data == item)   return true;
		else      p = p->next;
	}//while
	return false;
}//search






void List::printList()
{
	cout << "List content:\n";
	if (count == 0)
		cout << "list is empty.\n";
	Node *p = first;
	while (p != NULL)
	{
		cout << p->data << ", ";
		p = p->next;
	}//while
	cout << endl;
}//printList


int List::retrieve(int item)
{
	Node *p = first;
	while (p != NULL)
	{
		if (p->data == item)   return p->data;
		else      p = p->next;
	}//while
	cout << "item was not found, was not retrieved\n";
	return -10000; //to signal not found  
}//retrieve
int List::deleteItem(int item)
{
	int result = 0;
	if (isEmpty()) {
		cout << "List underflow\n";
		return -10000;
	}
	Node *previous = NULL, *following = first;
	while (following != NULL && following->data != item)
	{
		previous = following;
		following = following->next;
	}//while
	 //deleting 1st node
	if (previous == NULL && following != NULL && following->data == item)
	{
		result = following->data;
		first = first->next;
		delete following; //releasing memory
		count--;
		return result;
	}
	else
		if (previous != NULL && following != NULL && following->data == item)
		{
			result = following->data;  //deleting not 1st  node.
			previous->next = following->next;
			delete following;
			count--;
			return result;
		}
		else //item was not found
		{
			cout << "Item was not found and not deleted\n";
			return -10000;
		}
}//deleteItem



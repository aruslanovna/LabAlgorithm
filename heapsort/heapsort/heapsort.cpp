// heapsort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
	
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}


void heapSort(int arr[], int n)
{
	
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);

		
		heapify(arr, i, 0);
	}
}

void printArray(const int* const arr,  int size)
{
	for (int i = 0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void FillArray(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}
void push_back(int *&arr, int &size, const int value)
{
	int *newArray = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	newArray[size] = value;

	size++;

	delete[] arr;

	arr = newArray;

}
void ShowArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout<< arr[i]<< "\t";
	}
	cout<< endl;
}

int main()
{
	int size = 5;

	int *arr = new int[size];

	FillArray(arr, size);

	int n =  sizeof(arr)/ sizeof(arr[0]);
	ShowArray(arr, size);

	heapSort(arr, size);

	

	ShowArray(arr, size);
cout << "Sorted array is \n";
	 	push_back(arr, size, 7);
		ShowArray(arr, size);
	 heapSort(arr, size);
	 cout << "Sorted array is \n";
	 ShowArray(arr, size);
	system("pause");
	return 0;
}
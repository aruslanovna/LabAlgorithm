// ListQueue.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
using namespace std;

typedef int E;

class Node {
private:
	E value;
	Node* next;
public:
	Node() {};
	E Node::getValue();
	void Node::setValue(E val);
	Node* Node::getNext();
	void Node::setNext(Node* newNode);
};


E Node::getValue() {
	return this->value;
}

void Node::setValue(E val) {
	this->value = val;
}

Node* Node::getNext() {
	return this->next;
}

void Node::setNext(Node* newNode) {
	this->next = newNode;
}

class LinkedList {
private:
	Node* head;
	int length;
public:
	void init_list();
	bool is_list_empty();
	Node* search(E value);
	E deleteNode(E value);
	E deleteAt(int i);
	bool insert(E value);
	bool insertAt(E value, int i);
	int list_length();
	void displayList();
};

void LinkedList::init_list() {
	head = NULL;
	length = 0;
}

bool LinkedList::is_list_empty() {
	if (list_length() == 0) {
		return true;
	}
	return false;
}

Node* LinkedList::search(E value) {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->getValue() == value) {
			cout << "Node found !" << endl;
			return temp;
		}
		temp = temp->getNext();
	}
	cout << "Node not found !" << endl;
	return NULL;
}

E LinkedList::deleteNode(E value) {
	Node* temp = head;
	if (head->getValue() == value) {
		head = head->getNext();
		length--;
		return value;
	}
	while (temp->getNext() != NULL) {
		if (temp->getNext()->getValue() == value) {
			temp->setNext(temp->getNext()->getNext());
			length--;
			return value;
		}
		temp = temp->getNext();
	}
	return NULL;
}

E LinkedList::deleteAt(int i) {
	Node* temp = head;
	if (i == 1) {
		int tmpVal = head->getValue();
		head = head->getNext();
		length--;
		return tmpVal;
	}
	else {
		int count = 1;
		while (temp->getNext() != NULL) {
			if (count == i - 1) {
				int tmpVal = temp->getNext()->getValue();
				temp->setNext(temp->getNext()->getNext());
				length--;
				return tmpVal;
			}
			count++;
			temp = temp->getNext();
		}
	}
	return NULL;
}

bool LinkedList::insert(E value) {
	Node* newNode = new Node();
	newNode->setValue(value);
	newNode->setNext(NULL);
	if (list_length() != 0) {
		newNode->setNext(head);
	}
	head = newNode;
	length++;
	return true;
}

bool LinkedList::insertAt(E value, int i) {
	Node* temp = head;
	Node* newNode = new Node();
	newNode->setValue(value);
	if (i == 1) {
		newNode->setNext(head);
		head = newNode;
		length++;
		return true;
	}
	else {
		int count = 1;
		while (temp != NULL) {
			if (count == i - 1) {
				newNode->setNext(temp->getNext());
				temp->setNext(newNode);
				length++;
				return true;
			}
			count++;
			temp = temp->getNext();
		}
	}
	return NULL;
}

int LinkedList::list_length() {
	return this->length;
}

void LinkedList::displayList() {
	int i = 0;
	Node* temp = head;
	while (i != list_length()) {
		cout << temp->getValue() << " ";
		temp = temp->getNext();
		i++;
	}
	cout << endl;
}

typedef int E;
class MyQueue {
private:
	LinkedList values;
public:
	void init_queue();
	bool is_queue_empty();
	bool enqueue(E value);
	E dequeue();
	void displayQueue();
};

void MyQueue::init_queue() {
	values.init_list();
}

bool MyQueue::is_queue_empty() {
	if (values.is_list_empty()) {
		return true;
	}
	return false;
}

bool MyQueue::enqueue(E value) {
	return values.insert(value);
}

E MyQueue::dequeue() {
	return values.deleteAt(values.list_length());
}

void MyQueue::displayQueue() {
	values.displayList();
}

void main() {
	MyQueue queue;
	queue.init_queue();
	cout << "is_queue_empty : " << queue.is_queue_empty() << endl;

	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	queue.enqueue(40);
	queue.enqueue(50);
	queue.displayQueue();

	cout << "dequeue : " << queue.dequeue() << endl;
	queue.displayQueue();

	system("pause");
}

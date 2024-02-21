#ifndef _LINKEDLIST
#define _LINKEDLIST
#include<iostream>
#include "Node.h"
using namespace std;
template<typename T>
class LinkedList
{
private:
	Node<T>* head;
public:
	LinkedList();
	Node<T>* getHead();
	void setHead(Node<T>* t);
	virtual void insert(T Inserted);	//Insert object
	T Delete();		
	void print();
	bool isEmpty();			//Check if LinkedList is empty
};

template<typename T>
LinkedList<T>::LinkedList()	//Initialize members, and set counter to zero
{
	head = nullptr;
}
template<typename T>
void LinkedList<T>::insert(T Inserted)
{
	Node<T>* TempNode = new Node<T>(Inserted);	
	if (head == nullptr)					//If Linked list is empty
	{
		head = TempNode;					//Set head to point to TempNode
		return;
	}
	Node<T>* CurrentNode;						//Temporary node used for browsing the queue
	CurrentNode = head;						//Start from head
	while (CurrentNode->getNext())				//Runs until reach the last node
	{
		CurrentNode = CurrentNode->getNext();
	}
	CurrentNode->setNext(TempNode);			//Set the last node to the TempNode
}
template<typename T>
void LinkedList<T>::setHead(Node<T>* t)
{
	head = t;
}

template<typename T>
T LinkedList<T>::Delete()
{
	if (head == nullptr)					//do nothing if LinkedList is empty
		return nullptr;
	T Temp = head->getItem();
	Node<T>* RemNode = head;
	if (head->getNext() == nullptr)     //if there's only one node in the LinkedList
	{
		head = nullptr;
		delete RemNode;
	}
	else
	{
		head = RemNode->getNext();
		delete RemNode;
	}
	return Temp;
}
template<typename T>
bool LinkedList<T>::isEmpty()
{
	return (head == nullptr);
}
template<typename T>
void LinkedList<T>::print()
{
	Node<T>* p = head;
	int c = 1;
	while (p)
	{
		int id = p->getItem();
		p = p->getNext();
		cout << id << ", ";
		c++;
	}
}
template<typename T>
Node<T>* LinkedList<T>::getHead()
{
	return head;
}

#endif	


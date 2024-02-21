#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include "Node.h"
#include "QueueADT.h"
#include "Passenger.h"
#include <vector>
using namespace std;


template <typename T>
class LinkedQueue 
{
	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	bool enqueue( T& newEntry);
	bool search_by_ID(int id);
	LinkedQueue();
	Node<T>* Head();
	void PrintBus(string ty);
	bool peek(T& frntEntry) const;
	bool dequeue(T& frntEntry);
	void PrintId();
	bool isEmpty() const;
};
template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	 backPtr=nullptr;
	 frontPtr=nullptr;
}
template <typename T>
bool LinkedQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
template <typename T>
Node<T>* LinkedQueue<T>::Head() 
{
	
	return frontPtr;

}
template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}
template <typename T>
bool LinkedQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;

}

template <typename T>
bool LinkedQueue<T>::enqueue(T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())//special case if this is the first node to insert
	{
		frontPtr = newNodePtr; // The queue is empty
	}
	else
		backPtr->setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr; // New node is the last node now
	return true;

}

template<typename T>
bool LinkedQueue<T>::search_by_ID(int id)
{
	int h = 0;
	T temppass = nullptr;
	LinkedQueue<T>tempqueue;
	while (!isEmpty())
	{
		dequeue(temppass);//passenger  waiting list
		if (temppass->Get_PassengerType() == "NP" && id != temppass->Get_ID())
		{
			tempqueue.enqueue(temppass);

		}
		else if (temppass->Get_PassengerType() == "NP" && id == temppass->Get_ID())
		{
			h = 1;
			break;

		}

	}
	while (!tempqueue.isEmpty())
	{
		tempqueue.dequeue(temppass);
		enqueue(temppass);
	}
	if (h == 0)
		return false;
	else
		return true;
}
template<typename T>
void LinkedQueue<T>::PrintId()
{
	Node<T>* p = frontPtr;
	int c = 1;
	if (p == nullptr)return;
	while (p != nullptr)
	{
		int id = p->getItem()->Get_ID();
		p = p->getNext();
		cout << id << ", ";
		c++;
	}
}
template<typename T>
void LinkedQueue<T>::PrintBus(string ty)
{
	Node<T>* p = frontPtr;
	int c = 1;
	if (p == nullptr)return;
	while (p != nullptr)
	{
		int id = p->getItem()->Get_ID();
		string f=p->getItem()->Get_ty();
		int C = p->getItem()->Get_c();
		cout << "B"<<id<<"["<<ty<<", "<<f<<", "<<C<<"]"<<"{";
		p->getItem()->PrintPass();
		cout << "}" << endl;
		c++;
		p = p->getNext();
	}
}
#endif

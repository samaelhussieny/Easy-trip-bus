#ifndef LINKED_PRIORITY_QUEUE_
#define LINKED_PRIORITY_QUEUE_

#include "Node.h"
#include "Passenger.h"
#include "QueueADT.h"

using namespace std;

template <typename T>
class LinkedPriorityQueue 
{
	Node<T>* backPtr;
	Node<T>* frontPtr;
	
public:
	bool enqueue(T& newEntry);
	bool isEmpty() const;
	bool dequeue(T& frntEntry);
	void PrintId();
	bool peek(T& frntEntry);
	void SortingByES();
	void SortingBACES();
	void SortingByTYP();
	LinkedPriorityQueue();


};
template <typename T>
LinkedPriorityQueue<T>::LinkedPriorityQueue() {
	 backPtr=nullptr;
	 frontPtr=nullptr;
}
template <typename T>
bool LinkedPriorityQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}
template <typename T>
bool LinkedPriorityQueue<T>::peek(T& frntEntry)
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}

template <typename T>
bool LinkedPriorityQueue<T>::dequeue(T& frntEntry)
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
bool LinkedPriorityQueue<T>::enqueue(T& newEntry)
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
void LinkedPriorityQueue<T>::PrintId()
{
	Node<T>* p = frontPtr;
	int c = 1;
	if (p == nullptr)return;
	while (p != nullptr)
	{
		int id = p->getItem()->Get_ID();
		string TYP = p->getItem()->Get_Pass_SP();
		p = p->getNext();
		cout << id << "(" << TYP << "),";
		c++;
	}
}
template<typename T>
void LinkedPriorityQueue<T>::SortingByES()
{
	Node<T>* CurrentNode = frontPtr;
	while (CurrentNode)
	{
		Node<T>* MaxPri = CurrentNode;
		Node<T>* SearchNode = CurrentNode->getNext();
		while (SearchNode)
		{
			if (SearchNode->getItem()->GetEndStat() < CurrentNode->getItem()->GetEndStat())
			{
				MaxPri = SearchNode;
			}
			SearchNode = SearchNode->getNext();
		}
		if (MaxPri != CurrentNode)
		{
			T temp = CurrentNode->getItem();
			CurrentNode->setItem(MaxPri->getItem());
			MaxPri->setItem(temp);
		}
		CurrentNode = CurrentNode->getNext();
	}


	
}
template<typename T>
void LinkedPriorityQueue<T>::SortingBACES()
{
	Node<T>* CurrentNode = frontPtr;
	while (CurrentNode)
	{
		Node<T>* MaxPri = CurrentNode;
		Node<T>* SearchNode = CurrentNode->getNext();
		while (SearchNode)
		{
			if (SearchNode->getItem()->GetEndStat() > CurrentNode->getItem()->GetEndStat())
			{
				MaxPri = SearchNode;
			}
			SearchNode = SearchNode->getNext();
		}
		if (MaxPri != CurrentNode)
		{
			T temp = CurrentNode->getItem();
			CurrentNode->setItem(MaxPri->getItem());
			MaxPri->setItem(temp);
		}
		CurrentNode = CurrentNode->getNext();
	}



}

template<typename T>
void LinkedPriorityQueue<T>::SortingByTYP()
{
	Node<T>* CurrentNode = frontPtr;
	while (CurrentNode)
	{
		Node<T>* MaxPri = CurrentNode;
        Node<T>* SearchNode = CurrentNode->getNext();
  		while (SearchNode)
		{
			if (SearchNode->getItem()->GetNUMofPRI() < CurrentNode->getItem()->GetNUMofPRI())
			{
				MaxPri = SearchNode;
			}
			SearchNode = SearchNode->getNext();
		}
		if (MaxPri != CurrentNode)
		{
			T temp = CurrentNode->getItem();
			CurrentNode->setItem(MaxPri->getItem());
			MaxPri->setItem(temp);
		}
		CurrentNode = CurrentNode->getNext();
	}
	

	
}

#endif
#ifndef QUEUEADT
#define QUEUEADT
#include "Node.h"
template<typename T>
class QueueADT
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	QueueADT();
	bool isEmpty() const;
	virtual bool enqueue( T& newEntry) = 0;
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  ;
	void setfrontPtr(Node<T>* t);
	void setbackPtr(Node<T>* t);
	Node<T>* getfrontPtr();
	Node<T>* getbackPtr();


	~QueueADT();

	//copy constructor
	QueueADT(const QueueADT<T>& LQ);
};

template <typename T>
QueueADT<T>::QueueADT()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}


template <typename T>
bool QueueADT<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}





template <typename T>
bool QueueADT<T>::dequeue(T& frntEntry)
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
bool QueueADT<T>::peek(T& frntEntry) 
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}

template <typename T>
QueueADT<T>::~QueueADT()
{
	T temp;

	//Free (Dequeue) all nodes in the queue
	while (dequeue(temp));
}


template <typename T>
QueueADT<T>::QueueADT(const QueueADT<T>& LQ)
{
	Node<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	//insert the first node
	Node<T>* ptr = new Node<T>(NodePtr->getItem());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();

	//insert remaining nodes
	while (NodePtr)
	{
		Node<T>* ptr = new Node<T>(NodePtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePtr = NodePtr->getNext();
	}
}
template<typename T>
void QueueADT<T>::setfrontPtr(Node<T>* t)
{
	frontPtr = t;
}
template<typename T>
void QueueADT<T>::setbackPtr(Node<T>* t)
{
	backPtr = t;
}
template<typename T>
Node<T>* QueueADT<T>::getfrontPtr()
{
	return frontPtr;
}

template<typename T>
Node<T>* QueueADT<T>::getbackPtr()
{
	return backPtr;
}

#endif

#include "CircleQueue.h"

template <typename T>
T* CircleQueue<T>::getElement(int num)
{
	num = num % size;
	CircleQueueNode<T>* curElement = root;
	for (int i = 0; i < num; i++)
	{
		curElement = curElement->getNext();
	}
	return curElement->getElement();
}

template <typename T>
void CircleQueue<T>::print()
{
	CircleQueueNode<T>* curElement = root;
	for (int i = 0; i < size; i++)
	{
		std::cout << *(curElement->getElement()) << '\t';
		curElement = curElement->getNext();
	}
}

template <typename T>
CircleQueue<T>::CircleQueue()
{
	root = NULL;
	size = 0;
}

template <typename T>
CircleQueue<T>::CircleQueue(CircleQueueNode<T>* _root)
{
	root = _root;
	size = 1;
}

template <typename T>
CircleQueue<T>::CircleQueue(T rootElement)
{
	CircleQueueNode<T> = new CircleQueueNode<T>(rootElement, &rootElement, &rootElement);
	size = 1;
}

template <typename T>
CircleQueue<T>::~CircleQueue()
{
	CircleQueueNode<T>* curNode = root;
	for (int i = 0; i < size; i++)
	{
		CircleQueueNode<T>* nextNode = curNode->getNext();
		curNode->~CircleQueueNode();
		curNode = nextNode;
	}
}

template <typename T>
void CircleQueue<T>::addElement(int num, T* elementToInsert, bool direction)
{
	CircleQueueNode<T>* elementNode = new CircleQueueNode<T>(elementToInsert, NULL, NULL);
	if (size > 0)
	{
		num = num % (size + 1);
		CircleQueueNode<T>* prevElement = root;
		CircleQueueNode<T>* nextElement = root;
		if (num == 0)
		{
			prevElement = root->getPrev();
			nextElement = root;
		}
		else
		{
			if (direction == 0)
			{
				for (int i = 0; i < num; i++)
				{
					nextElement = nextElement->getNext();
				}
				prevElement = nextElement->getPrev();
			}
			else
			{
				for (int i = 0; i < num; i++)
				{
					prevElement = prevElement->getPrev();
				}
				nextElement = prevElement->getNext();
			}
		}
		elementNode->setPrev(prevElement);
		elementNode->setNext(nextElement);
		prevElement->setNext(elementNode);
		nextElement->setPrev(elementNode);
		if (num == 0)
			root = elementNode;
	}
	else
	{
		root = elementNode;
		elementNode->setNext(elementNode);
		elementNode->setPrev(elementNode);
	}
	size++;
}

template <typename T>
bool CircleQueue<T>::removeElement(int num, bool direction)
{
	num = num % size;
	if (size == 0)
		return false;
	CircleQueueNode<T>* curElement = root;
	if (direction == 0)
	{
		for (int i = 0; i < num; i++)
		{
			curElement = curElement->getNext();
		}
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			curElement = curElement->getPrev();
		}
	}
	CircleQueueNode<T>* prevElement = curElement->getPrev();
	CircleQueueNode<T>* nextElement = curElement->getNext();
	prevElement->setNext(nextElement);
	nextElement->setPrev(prevElement);
	curElement->~CircleQueueNode();
	curElement = NULL;
	size--;
	if (num == 0 || num == 1)
	{
		root = nextElement;
	}
	return true;
}
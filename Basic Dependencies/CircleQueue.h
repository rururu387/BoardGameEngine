#pragma once
#include "CircleQueueNode.h"

template <typename T>
class CircleQueue
{
	CircleQueueNode<T>* root;
	int size;
public:
	CircleQueue(CircleQueueNode<T>* _root);
	CircleQueue(T rootElement);
	CircleQueue();
	~CircleQueue();
	T* getElement(int num = 0);
	void addElement(int num, T* element, bool direction = 0);
	bool removeElement(int num, bool direction = 0);
	int getSize() const { return size; };
	void print();
};
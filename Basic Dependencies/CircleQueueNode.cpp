#include "CircleQueueNode.h"

template <typename T>
CircleQueueNode<T>::~CircleQueueNode()
{
	delete element;
}

template <typename T>
CircleQueueNode<T>::CircleQueueNode(CircleQueueNode& _node)
{
	next = _node.getNext();
	prev = _node.getPrev();
	element = new T(_node.getElement());
}


template <typename T>
CircleQueueNode<T>::CircleQueueNode(T* _element, CircleQueueNode* _next, CircleQueueNode* _prev)
{
	element = _element;
	next = _next;
	prev = _prev;
}
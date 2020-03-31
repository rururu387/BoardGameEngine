#pragma once

template <typename T>
class CircleQueueNode
{
	T* element;
	CircleQueueNode* next;
	CircleQueueNode* prev;
public:
	CircleQueueNode* getNext() { return next; };
	void setNext(CircleQueueNode* _next) { next = _next; };

	CircleQueueNode* getPrev() { return prev; };
	void setPrev(CircleQueueNode* _prev) { prev = _prev; };

	T* getElement() { return element; };
	void setElement(T* _element) { element = _element; };

	CircleQueueNode(T* _element, CircleQueueNode* _next, CircleQueueNode* _prev);
	CircleQueueNode(CircleQueueNode &_node);
	~CircleQueueNode();
};
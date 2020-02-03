#ifndef _LINKED_QUEUE_H_
#define _LINKED_QUEUE_H_

class Node
{
public:
	Node* next;
	int data;
};

class Linked_Queue
{
public:
	Linked_Queue();
	//Linked_Queue(int m_size);
	//~Linked_Queue();

	void Add(int data);
	void Pop();
	//bool empty();
	int size();
	void Print_data_All();

private : 
	Node* Head;
	Node* Tail;
	int _size;
};

#endif

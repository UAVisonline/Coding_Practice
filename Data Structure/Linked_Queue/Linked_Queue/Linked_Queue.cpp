#include "Linked_Queue.h"
#include <iostream>

using namespace std;

Linked_Queue::Linked_Queue()
{
	Head = NULL;
	Tail = NULL;
	_size = 0;
}

void Linked_Queue::Add(int _data)
{
	Node* node = new Node;
	node->data = _data;
	node->next = NULL;
	if (size() == 0)
	{
		Head = node;
		Tail = node;
	}
	else
	{
		Tail->next = node;
		Tail = Tail->next;
	}
	_size++;
}

void Linked_Queue::Pop()
{
	if (size()==0)
	{
		cout << "Empty_Queue" << endl;
	}
	else
	{
		Node* node = Head;
		Head = Head->next;
		delete node;
		_size--;
	}
	
}

/*bool Linked_Queue::empty()
{
	if (_size == 0) return true;
	else return false;
}*/

int Linked_Queue::size()
{
	return _size;
}

void Linked_Queue::Print_data_All()
{
	int i = 0;
	Node* print = Head;
	while(print!=NULL)
	{
		cout << i+1 << "번째 데이터 : " << print->data << endl;
		print = print->next;
		i++;
	}
}


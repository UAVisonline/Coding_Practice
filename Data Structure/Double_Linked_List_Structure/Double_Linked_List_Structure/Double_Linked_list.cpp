#include "Double_Linked_List.h"
#include <iostream>

Link_Node::Link_Node()
{
	data = 0;
	prev = NULL;
	next = NULL;
}

Link_Node::Link_Node(int set_data)
{
	data = set_data;
	prev = NULL;
	next = NULL;
}

Double_Linked_List::Double_Linked_List()
{
	Head = Tail = NULL;
	size = 0;
}

void Double_Linked_List::addHead(int data)
{
	Link_Node* tmp= new Link_Node(data);
	if (Head == NULL)
	{
		Head = Tail = tmp;
	}
	else
	{
		Head->prev = tmp;
		tmp->next = Head;
		Head = tmp;
	}
	size++;
}

void Double_Linked_List::addTail(int data)
{
	Link_Node* tmp = new Link_Node(data);
	if (Tail == NULL)
	{
		Head = Tail = tmp;
	}
	else
	{
		Tail->next = tmp;
		tmp->prev = Tail;
		Tail = tmp;
	}
	size++;
}

void Double_Linked_List::popHead()
{
	if (Head == NULL)
	{
		std::cout << "Empty Double Linked List" << std::endl;
		return;
	}
	else if (Head == Tail)
	{
		std::cout << "Head data : " << Head->data << std::endl;
		Head = Tail = NULL;
	}
	else
	{
		std::cout << "Head data : " << Head->data << std::endl;
		Link_Node* tmp = Head;
		Head = tmp->next;
		Head->prev = NULL;
		delete tmp;
	}
	size--;
}

void Double_Linked_List::popTail()
{
	if (Tail == NULL)
	{
		std::cout << "Empty Double Linked List" << std::endl;
		return;
	}
	else if (Head == Tail)
	{
		std::cout << "Tail data : " << Tail->data << std::endl;
		Head = Tail = NULL;
	}
	else
	{
		std::cout << "Tail data : " << Tail->data << std::endl;
		Link_Node* tmp = Tail;
		Tail = tmp->prev;
		Tail->next = NULL;
		delete tmp;
	}
	size--;
}

int Double_Linked_List::Return_Size()
{
	return size;
}

void Double_Linked_List::PrintList_To_Head()
{
	if (size == 0)
	{
		std::cout << "Empty Double Linked List" << std::endl;
		return;
	}
	else
	{
		std::cout << "<<Print List Head to Tail>>" << std::endl;
		Link_Node* tmp = Head;
		while (tmp->next != NULL)
		{
			std::cout << "Data : " << tmp->data << std::endl;
			tmp = tmp->next;
		}
		std::cout << "Data : " << tmp->data << std::endl;;
	}
}

void Double_Linked_List::PrintList_To_Tail()
{
	if (size == 0)
	{
		std::cout << "Empty Double Linked List" << std::endl;
		return;
	}
	else
	{
		std::cout << "<<Print List Tail to Head>>" << std::endl;
		Link_Node* tmp = Tail;
		while (tmp->prev != NULL)
		{
			std::cout << "Data : " << tmp->data << std::endl;
			tmp = tmp->prev;
		}
		std::cout << "Data : " << tmp->data << std::endl;;
	}
}

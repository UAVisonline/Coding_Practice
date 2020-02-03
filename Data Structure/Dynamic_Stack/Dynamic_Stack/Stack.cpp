#include "Stack.h"
#include <iostream>

Stack::Stack()
{
	size = 10;
	top = -1;
	data_zip = new int[10];
}

Stack::Stack(int m_size)
{
	size = m_size;
	top = -1;
	data_zip = new int[m_size];
}

Stack::~Stack()
{
	delete[] data_zip;
	size = 0;
	top = -1;
}

void Stack::Push(int data)
{
	if (top == size-1)
	{
		Resize(size + 10);
	}
	data_zip[++top] = data;
}

void Stack::Resize(int m_size)
{
	int* Resize_zip = new int[m_size];
	for (int i = 0; i <= top; i++)
	{
		Resize_zip[i] = data_zip[i];
	}
	data_zip = Resize_zip;
	size = m_size;
}

void Stack::Print_Stack()
{
	for (int i = 0; i <= top; i++)
	{
		std::cout << i+1 << " : "<< data_zip[i] << std::endl;
	}
}

int Stack::Pop()
{
	if (top == -1)
	{
		std::cout << "Empty Stack" << std::endl;
		return NULL;
	}
	else
	{
		int data = data_zip[top--];
		return data;
	}
}

bool Stack::Empty()
{
	if (top == -1)
	{
		return true;
	}
	return false;
}

int Stack::Return_Size()
{
	return size;
}




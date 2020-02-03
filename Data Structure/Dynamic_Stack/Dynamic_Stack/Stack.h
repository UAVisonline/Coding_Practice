#ifndef _STACK_H_
#define _STACK_H_

class Stack
{
public:
	Stack();
	Stack(int m_size);
	~Stack();
	void Push(int data);
	void Resize(int m_size);
	void Print_Stack();
	int Pop();
	bool Empty();
	int Return_Size();

private:
	int* data_zip;
	int size;
	int top;
};

#endif

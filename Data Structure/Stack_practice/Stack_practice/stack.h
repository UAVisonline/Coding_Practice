#ifndef _STACK_H_
#define _STACK_H_

class Stack {
public:
	Stack()
	{
		m_size = 10;
		top = 0;
		stack = new int[m_size];
	}
	Stack(int size)
	{
		m_size = size;
		top = 0;
		stack = new int[m_size];
	}
	~Stack()
	{
		delete[] stack;
		//stack = NULL;
	}

	bool empty();
	int size();
	void push(int data);
	int pop();

private :
	int m_size;
	int top;
	int* stack;

};

#endif

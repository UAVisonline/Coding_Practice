#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
	Stack s1(5);
	for (int i = 0; i < 7; i++)
	{
		s1.Push(i + 3);
	}
	s1.Print_Stack();
	cout << s1.Pop() << endl;
	s1.Resize(s1.Return_Size() + 5);
	for (int i = 6; i < 15; i++)
	{
		s1.Push(i * 3);
	}
	s1.Print_Stack();
	return 0;
}
#include"stack.h"
#include <iostream>

using namespace std;

int main()
{
	Stack s1(5);
	cout << s1.size() << endl;
	s1.push(3);
	s1.push(5);
	s1.push(7);
	cout << s1.size() << endl;
	cout << s1.empty() << endl;
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	cout << s1.size() << endl;
	s1.push(10);
	cout << s1.size() << endl;
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	cout << s1.empty() <<endl;

	return 0;
}
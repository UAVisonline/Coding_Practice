#include <iostream>
#include"stack.h"

using namespace std;


 bool Stack::empty()
 {
	 if (size() == 0) return true;
	 return false;
 }

 
 int Stack::size()
 {
	 return top;
 }


 void Stack::push(int data)
 {
	 if (size() == m_size) cout << "full stack" << endl;
	 else
	 {
		 stack[top++] = data;
	 }
 }

 int Stack::pop()
 {
	 if (empty())
	 {
		 cout << "empty stack" << endl;
		 return NULL;
	 }
	 else
	 {
		 int data = stack[--top];
		 return data;
	 }
 }

 
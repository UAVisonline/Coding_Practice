#include "Linked_Queue.h"
#include <iostream>

using namespace std;

int main()
{
	Linked_Queue link_queue;
	link_queue.Add(3);
	link_queue.Add(7);
	link_queue.Add(11);
	link_queue.Print_data_All();
	link_queue.Pop();
	link_queue.Pop();
	cout << link_queue.size() << endl;
	link_queue.Add(1);
	link_queue.Print_data_All();
	cout << link_queue.size() << endl;
	return 0;
}
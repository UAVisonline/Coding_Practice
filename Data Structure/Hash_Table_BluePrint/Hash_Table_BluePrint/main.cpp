#include "Hash.h"
#include <iostream>

using namespace std;

int main()
{
	Hash_Table table;
	string cmd;
	cin >> cmd;
	while (cmd != "Exit")
	{
		if (cmd == "Add")
		{
			string name;
			int number;
			cin >> name >> number;
			table.Add(name, number);
		}
		else if (cmd == "Set")
		{
			string name;
			cin >> name;
			table.Set(name);
		}
		else if (cmd == "Print")
		{
			table.Print();
		}
		cin >> cmd;
	}

	return 0;
}
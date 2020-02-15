#include "Double_Linked_List.h"
#include <iostream>
#include <string>


int main()
{
	Double_Linked_List d_list;
	std::cout << "(command list)" << std::endl;
	std::cout << "Insert_Head : Head���� data �ֱ�" << std::endl;
	std::cout << "Insert_Tail : Tail���� data �ֱ�" << std::endl;
	std::cout << "Pop_Head : Head���� data ����" << std::endl;
	std::cout << "Pop_Tail : Tail���� data ����" << std::endl;
	std::cout << "Print_Head_To_Tail : Head->Tail������ data ���" << std::endl;
	std::cout << "Print_Tail_To_Head : Tail->Head������ data ���" << std::endl;
	std::cout << "Exit : ���α׷� ����" << std::endl;
	std::string cmd;
	std::cin >> cmd;
	while (cmd != "Exit")
	{
		if (cmd == "Insert_Head")
		{
			int data;
			std::cin >> data;
			d_list.addHead(data);
		}
		else if (cmd == "Insert_Tail")
		{
			int data;
			std::cin >> data;
			d_list.addTail(data);
		}
		else if (cmd == "Pop_Head") d_list.popHead();
		else if (cmd == "Pop_Tail") d_list.popTail();
		else if (cmd == "Print_Head_To_Tail") d_list.PrintList_To_Head();
		else if (cmd == "Print_Tail_To_Head") d_list.PrintList_To_Tail();
		std::cin >> cmd;
	}
	return 0;
}
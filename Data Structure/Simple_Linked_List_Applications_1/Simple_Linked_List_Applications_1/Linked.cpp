#include<String>
#include<iostream>


class NameCardNode {
private:
	std::string name;
	std::string phone_number;
	NameCardNode* next;
	friend class NameCardList;
public:
	NameCardNode()
	{
		name = "";
		phone_number = "";
		next = NULL;
	}
	NameCardNode(std::string name_data, std::string phone_data, NameCardNode* card_data = NULL)
	{
		name = name_data;
		phone_number = phone_data;
		next = card_data;
	}
	std::string GetData()
	{
		return "이름 : " + name + "  전화번호 : " + phone_number;
	}
	std::string GetName()
	{
		return name;
	}

};

class NameCardList {

private:
	NameCardNode* head = NULL;
public:
	NameCardList()
	{
		head = NULL;
	}
	void InsertNameCardFirst(std::string name, std::string number)
	{
		NameCardNode* cardnode = new NameCardNode(name, number);
		if (head == NULL)
		{
			head = cardnode;
		}
		else
		{
			cardnode->next = head;
			head = cardnode;
		}
	}
	void InsertNameCardLast(std::string name, std::string number)
	{
		NameCardNode* cardnode = new NameCardNode(name, number);
		if (head == NULL)
		{
			head = cardnode;
		}
		else
		{
			NameCardNode *tmp = head;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = cardnode;
		}
	}
	void NameCardSearch(std::string find_name)
	{
		NameCardNode* tmp = head;
		while (tmp->next != NULL)
		{
			if (tmp->GetName() == find_name)
			{
				std::cout << tmp->GetData() << std::endl;
				return;
			}
			tmp = tmp->next;
		}
		std::cout << "Can not found result" << std::endl;
	}
	void NameCardPrint()
	{
		NameCardNode* tmp = head;
		if (tmp == NULL)
		{
			std::cout << "empty list" << std::endl;
		}
		else
		{
			while (true)
			{
				std::cout << tmp->GetData() << std::endl;
				if (tmp->next == NULL) break;
				else tmp = tmp->next;
			}
		}
	}
};

int main()
{
	NameCardList list;
	std::string command;
	std::cin >> command;
	while (command != "exit")
	{
		//std::cout << command << std::endl;
		if (command == "insert_first")
		{
			std::string name, phone;
			std::cin >> name >> phone;
			list.InsertNameCardFirst(name, phone);
		}
		else if (command == "insert_last")
		{
			std::string name, phone;
			std::cin >> name >> phone;
			list.InsertNameCardLast(name, phone);
		}
		else if (command == "search")
		{
			std::string name;
			std::cin >> name;
			list.NameCardSearch(name);
		}
		else if (command == "print")
		{
			list.NameCardPrint();
		}
		/*
		else if(command == "delete")
		{
			std::string name;
			std::cin >> name;
		}
		*/
		
		std::cin >> command;
	}
	return 0;
}
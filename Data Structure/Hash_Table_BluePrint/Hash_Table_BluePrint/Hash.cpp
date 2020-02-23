#include "Hash.h"
#include <iostream>

Node::Node(std::string name,int number)
{
	str = name;
	phone = number;
	next = NULL;
}

void Node::Add(Node* node)
{
	if (next == NULL)
	{
		next = node;
	}
	else
	{
		next->Add(node);
	}
}

void Node::Set(std::string name)
{
	if (str == name)
	{
		std::cout << name << "�� ��ȭ��ȣ���� �������� �ٲٰڽ��ϱ�?" << std::endl;
		int change;
		std::cin >> change;
		phone = change;
		std::cout << name << "�� ��ȭ��ȣ����" << change << " ���� �ٲپ����ϴ�." << std::endl;
	}
	else
	{
		if (next == NULL)
		{
			std::cout << name << "�� ��ȭ��ȣ�� �Էµ��� �ʾҽ��ϴ�." << std::endl;
			return;
		}
		else next->Set(name);
	}
}

void Node::Print()
{
	std::cout << "�̸� : " << str << " , ��ȭ��ȣ : " << phone << std::endl;
	if (next != NULL) next->Print();
}

Hash_Table::Hash_Table()
{
	for (int i = 0; i < 10; i++)
	{
		table[i] = NULL;
	}
	size = 0;
}

int Hash_Table::hash(std::string name)
{
	int hash_value = 0;
	for (int i = 0; i < name.length(); i++)
	{
		hash_value += name[i];
	}
	return  hash_value % 10;
}

void Hash_Table::Add(std::string name, int phone)
{
	Node* node = new Node(name, phone);
	int table_pos = hash(name);
	if (table[table_pos] == NULL)
	{
		table[table_pos] = node;
	}
	else 
	{
		table[table_pos]->Add(node);
	}
	size++;
}

void Hash_Table::Set(std::string name)
{
	int table_pos = hash(name);
	table[table_pos]->Set(name);
}

void Hash_Table::Print()
{
	for (int i = 0; i < 10; i++)
	{
		if (table[i] == NULL) std::cout << i+1 << "��° ��ġ���� ����� ��ȭ��ȣ�� �����ϴ�." << std::endl;
		else 
		{
			std::cout << i + 1 << "��° ��ġ���� ����� ��ȭ��ȣ�� �Դϴ�." << std::endl;
			table[i]->Print();
		}
	}
}

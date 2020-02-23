#ifndef _HASH_H_
#define _HASH_H_

#include <string>

class Node {
private :
	Node* next;
	std::string str;
	int phone;
public :
	Node(std::string name,int number);
	void Add(Node* node);
	void Set(std::string name);
	void Print();
};

class Hash_Table {
private :
	Node** table = new Node * [10];
	int size;
	int hash(std::string name);
public :
	Hash_Table();
	void Add(std::string name, int phone);
	void Set(std::string name);
	void Print();
};


#endif

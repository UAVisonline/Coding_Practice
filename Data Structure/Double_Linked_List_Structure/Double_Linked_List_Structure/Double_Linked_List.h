#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H

class Link_Node {
	friend class Double_Linked_List;
private:
	Link_Node* prev;
	Link_Node* next;
	int data;
public:
	Link_Node();
	Link_Node(int set_data);
};

class Double_Linked_List {
private:
	Link_Node* Head;
	Link_Node* Tail;
	int size;
public:
	Double_Linked_List();
	void addHead(int data);
	void addTail(int data);
	void popHead();
	void popTail();
	int Return_Size();
	void PrintList_To_Head();
	void PrintList_To_Tail();
};

#endif

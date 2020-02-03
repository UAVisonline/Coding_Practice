#ifndef _TREE_H_
#define _TREE_H_

class Node
{
public:
	Node(int _data);
	int get_data();
	//bool isRoot();
	//bool isExternal();

	void set_left_child(Node* node);
	void set_right_child(Node* node);

	//Node* get_parent();
	Node* get_left_child();
	Node* get_right_child();

private:
	int data;
	//Node* parent;
	Node* left_child;
	Node* right_child;
};

class Tree
{
public:
	Tree();
	Tree(int data);
	int get_size();

	bool Insert(int data);
	bool Search(int search_data);
	bool Delete(int search_data);

	void pre_order(Node* node);
	void post_order(Node* node);
	void in_order(Node* node);

private:
	Node* root;
	int size;

	bool Insert(int data, Node* node);
	bool Search(int search_data, Node* node);
	bool Delete(int search_data, Node* node);
};


#endif  _TREE_H_

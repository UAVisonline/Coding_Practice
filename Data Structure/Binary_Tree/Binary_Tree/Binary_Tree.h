#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

class Tree_Node
{
	friend class Binary_Tree;
public:
	bool External();
private :
	Tree_Node* left;
	Tree_Node* right;
	int data;
};

class Binary_Tree {
public:
	Binary_Tree();
	Binary_Tree(Tree_Node* ptr);
	Tree_Node* get_root();
	int get_height();
	void print_data(Tree_Node* ptr);


private:
	Tree_Node* root;
};


#endif

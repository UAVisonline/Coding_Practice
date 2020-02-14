#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

class Tree_Node
{
	friend class Binary_Tree;

private:
	Tree_Node* left;
	Tree_Node* right;
	Tree_Node* parent;
	int data;

public:
	bool External();
	friend std::istream& operator>>(std::istream& is, Tree_Node& ptr) {
		is >> ptr.data;
		return is;
	}

};

class Binary_Tree {

private:
	Tree_Node* root;
	Tree_Node* last;
	int size;

public:
	Binary_Tree();
	Binary_Tree(Tree_Node* ptr);
	Tree_Node* get_root();
	int get_height();
	void print_data(Tree_Node* ptr);
	void Insert_Node(Tree_Node* ptr);
	void preorder(Tree_Node* ptr);
	void inorder(Tree_Node* ptr);
	void postorder(Tree_Node* ptr);

};


#endif

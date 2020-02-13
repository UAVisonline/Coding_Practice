#include "Binary_Tree.h"
#include <iostream>

bool Tree_Node::External()
{
	if (left==NULL && right==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Binary_Tree::Binary_Tree()
{
	root = NULL;
}

Binary_Tree::Binary_Tree(Tree_Node* ptr)
{
	root = ptr;
}

Tree_Node* Binary_Tree::get_root()
{
	return root;
}

void Binary_Tree::print_data(Tree_Node* ptr)
{
	std::cout << "data : " << ptr->data << std::endl;
}



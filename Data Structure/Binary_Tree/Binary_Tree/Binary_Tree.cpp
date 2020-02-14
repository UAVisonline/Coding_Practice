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
	last = NULL;
}

Binary_Tree::Binary_Tree(Tree_Node* ptr)
{
	root = ptr;
	last = ptr;
}

Tree_Node* Binary_Tree::get_root()
{
	return root;
}

int Binary_Tree::get_height()
{
	int two_bass = 1;
	for (int height = 0;; height++)
	{
		if (two_bass-1 >= size)
		{
			return height;
		}
		else
		{
			two_bass *= 2;
		}
	}
}

void Binary_Tree::print_data(Tree_Node* ptr)
{
	std::cout << "data : " << ptr->data << std::endl;
}

void Binary_Tree::Insert_Node(Tree_Node* ptr)
{
	if (root == NULL)
	{
		root = ptr;
		last = ptr;
	}
}


#include "Tree.h"
#include <iostream>

Node::Node(std::string input_name)
{
	name = input_name;
	parent = NULL;
}

Node::Node(std::string input_name, Node* _parent)
{
	name = input_name;
	parent = _parent;
}

bool Node::isExternal()
{
	if (this->node_children.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Node::isRoot()
{
	if (this->parent == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Node* Node::return_self()
{
	return this;
}

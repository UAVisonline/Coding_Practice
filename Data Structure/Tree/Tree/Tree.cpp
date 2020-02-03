#include "Tree.h"
#include <iostream>

using namespace std;

Node::Node(int _data)
{
	data = _data;
	//parent = NULL;
	left_child = NULL;
	right_child = NULL;
}

int Node::get_data()
{
	return data;
}

void Node::set_left_child(Node* node)
{
	left_child = node;
}

void Node::set_right_child(Node* node)
{
	right_child = node;
}

/*bool Node::isRoot()
{
	return parent == NULL;
}*/

/*bool Node::isExternal()
{
	return left_child == NULL && right_child == NULL;
}*/

/*Node* Node::get_parent()
{
	Node* node = this->parent;
	return node;
}*/

Node* Node::get_left_child()
{
	Node* node = this->left_child;
	return node;
}

Node* Node::get_right_child()
{
	Node* node = this->right_child;
	return node;
}

Tree::Tree()
{
	root = NULL;
	size = 0;
}

Tree::Tree(int data)
{
	Node* node = new Node(data);
	root = node;
	size = 1;
}

bool Tree::Insert(int data)
{
	return Insert(data, root);
}

bool Tree::Search(int search_data)
{
	return Search(search_data,root);
}

bool Tree::Delete(int search_data)
{
	return Delete(search_data,root);
}

bool Tree::Insert(int data, Node* current)
{
	if (current == NULL)
	{
		Node* node = new Node(data);
		current = node;
		size++;
		return true;
	}
	else
	{
		if (current->get_data() < data)
		{
			return Insert(data, current->get_right_child());
		}
		else if (current->get_data() > data)
		{
			return Insert(data, current->get_left_child());
		}
		else if (current->get_data() == data)
		{
			cout << "data duplicate" << endl;
			return false;
		}
	}
}

void Tree::pre_order(Node* node)
{
	if (node != NULL)
	{
		cout << node->get_data();
		pre_order(node->get_left_child);
		pre_order(node->get_right_child);
	}
}

void Tree::post_order(Node* node)
{
	if (node != NULL)
	{
		
		post_order(node->get_left_child);
		post_order(node->get_right_child);
		cout << node->get_data();
	}
}

void Tree::in_order(Node* node)
{
	if (node != NULL)
	{
		in_order(node->get_left_child);
		cout << node->get_data();
		in_order(node->get_right_child);
	}
}



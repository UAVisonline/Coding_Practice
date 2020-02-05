#ifndef _TREE_H_
#define _TREE_H_

#include<string>
#include<vector>

class Node
{
private:
	std::string name;
	Node* parent;
	std::vector<Node> node_children;
	friend class Tree;
public:
	Node(std::string input_name);
	Node(std::string input_name, Node* _parent);
	bool isExternal();
	bool isRoot();
	Node* return_self();

};

class Tree
{
private:
	Node* root = NULL;
public :
	Tree(Node* _root);
};


#endif  _TREE_H_

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define NODE_DEGREE 2
#define MAX_CHILDS (NODE_DEGREE*2)
#define MAX_KEYS (MAX_CHILDS-1)
#define SPACE 4*MAX_KEYS

typedef struct BTreeNode
{
	int Keys[MAX_KEYS];
	struct BTreeNode* Childs[MAX_CHILDS];
	int KeyIndex;
	int Leaf;
} BTreeNode;

typedef struct 
{
	struct BTreeNode* Root;
	int Degree;
} BTree;

BTreeNode* CreateBTreeNode();
BTree* CreateBTree();

void Search(BTreeNode* Node, int key);
void SplitChild(BTreeNode* Parent, BTreeNode* Child, int Index);
void InsertNonFull(BTreeNode* Node, int Key);
void Insert(BTree* Tree, int Key);

void Remove(BTree* Tree, int Key);
int FindKey(BTreeNode* Node, int Key);
void RemoveNode(BTreeNode* Node, int Key);
void RemoveFromLeaf(BTreeNode* Node, int Index);
void RemoveFromNonLeaf(BTreeNode* Node, int Index);

void Fill(BTreeNode* Node, int Index);
int Return_Predecessor(BTreeNode* Node, int Index);
int Return_Successor(BTreeNode* Node, int Index);

void Borrow_From_Prev(BTreeNode* Node, int Index);
void Borrow_From_Next(BTreeNode* Node, int Index);
void Merge(BTreeNode* Node, int Index);

void PrintTree(BTreeNode* Node, int Level, int Blank);

int main(int argv, char* argc[])
{
	int test[] = { 1,7,2,11,4,8,13,10,5,19,3,6,9,18,23,12,14,20,21,16,26,27,22,24,25 };

	BTree* Tree = CreateBTree();
	int i;

	for (i = 0; i < sizeof(test) / sizeof(int); i++)
	{
		printf("Insert : %d\n", test[i]);
		Insert(Tree, test[i]);
		PrintTree(Tree->Root, 0, FALSE);
		printf("\n");
	}

	for (int i = 0; i < 3 * (SPACE + 1); i++)
	{
		printf("-");
	}
	printf("\n");

	int testdel[] = { 14,3,12,27,1,10,11,25,5,9,23,20,8,4,24,1};

	for (i = 0; i < sizeof(testdel) / sizeof(int); i++)
	{
		printf("Remove : %d\n", testdel[i]);
		Remove(Tree, testdel[i]);
		PrintTree(Tree->Root, 0, FALSE);
		printf("\n");
	}

	for (int i = 0; i < 3 * (SPACE + 1); i++)
	{
		printf("-");
	}
	printf("\n");

	//search Keys
	int Target = 2;
	printf("Search %d\n", Target);
	Search(Tree->Root, Target);
	printf("\n");

	Target = 26;
	printf("Search %d\n", Target);
	Search(Tree->Root, Target);
	printf("\n");

	Target = 18;
	printf("Search %d\n", Target);
	Search(Tree->Root, Target);
	printf("\n");

	Target = 14;
	printf("Search %d\n", Target);
	Search(Tree->Root, Target);
	printf("\n");
}

BTreeNode* CreateBTreeNode()
{
	BTreeNode* temp = (BTreeNode*)malloc(sizeof(BTreeNode));

	for (int i = 0; i < MAX_KEYS; i++)
	{
		temp->Keys[i] = 0;
	}
	for (int i = 0; i < MAX_CHILDS; i++)
	{
		temp->Childs[i] = NULL;
	}

	temp->KeyIndex = 0;
	temp->Leaf = TRUE;

	return temp;
}

BTree* CreateBTree()
{
	BTree* Tree = (BTree*)malloc(sizeof(BTree));
	
	BTreeNode* Temp = CreateBTreeNode();
	Tree->Root = Temp;
	Tree->Degree = NODE_DEGREE;

	return Tree;
}

void Search(BTreeNode* Node, int key) // Assignment
{
	int index = 0; // index variable init
	while (index < Node->KeyIndex) // index lower than Node Index Size
	{
		if (Node->Keys[index] == key) // Find key
		{
			printf("Key %d exist in tree\n", key);
			return;
		}
		else if (Node->Keys[index] > key) //Key[index] greater than key
		{
			break;
		}
		index++;
	}
	if (Node->Leaf == TRUE) printf("Key %d not exist in tree\n", key); // if leaf node and can find the key value
	else Search(Node->Childs[index], key); // if node is not leaf and can not find key, go to child node
}

void SplitChild(BTreeNode* Parent, BTreeNode* Child, int Index)
{
	BTreeNode* Temp = CreateBTreeNode();
	
	Temp->Leaf = Child->Leaf;
	Temp->KeyIndex = NODE_DEGREE-1;
	for (int i = 0; i < NODE_DEGREE - 1; i++) //move right half key of child
	{
		Temp->Keys[i] = Child->Keys[NODE_DEGREE + i];
	}
	if (Child->Leaf == FALSE) // if Child is not leaf, move childs of child
	{
		for (int i = 0; i < NODE_DEGREE; i++)
		{
			Temp->Childs[i] = Child->Childs[NODE_DEGREE + i];
		}
	}
	Child->KeyIndex = NODE_DEGREE - 1;

	for (int i = Parent->KeyIndex; i > Index - 1; i--) //move childs of parent, make space to insert temp
	{
		Parent->Childs[i + 1] = Parent->Childs[i];
	}

	Parent->Childs[Index] = Temp; // insert Temp

	for (int i = Parent->KeyIndex; i > Index - 1; i--) // move keys of parent, make space to insert keys of child
	{
		Parent->Keys[i] = Parent->Keys[i - 1];
	}
	Parent->Keys[Index - 1] = Child->Keys[NODE_DEGREE - 1];

	Parent->KeyIndex++;
}

void InsertNonFull(BTreeNode* Node, int Key)
{
	int Index = Node->KeyIndex;

	if (Node->Leaf == TRUE)
	{
		while (Index > 0 && Node->Keys[Index - 1] > Key) // find position to insert key
		{
			Node->Keys[Index] = Node->Keys[Index - 1];
			Index--;
		}
		Node->Keys[Index] = Key;
		Node->KeyIndex++;
	}
	else
	{
		while (Index > 0 && Node->Keys[Index - 1] > Key) // find position to insert key
		{
			Index--;
		}
		if (Node->Childs[Index]->KeyIndex == MAX_KEYS)
		{
			SplitChild(Node, Node->Childs[Index], Index + 1); // Child is Full, split
			if (Node->Keys[Index] < Key) // find child index to insert key
			{
				Index++;
			}
		}
		InsertNonFull(Node->Childs[Index], Key);
	}
}

void Insert(BTree* Tree, int Key)
{
	if (Tree->Root->KeyIndex == MAX_KEYS) // if root is full
	{
		BTreeNode* Temp = CreateBTreeNode();
		
		Temp->Leaf = FALSE;
		Temp->KeyIndex = 0;
		Temp->Childs[0] = Tree->Root;

		SplitChild(Temp, Tree->Root, 1); // make root is firt child of new root
		InsertNonFull(Temp, Key); // insert key
		Tree->Root = Temp; // change root pointer
	}
	else
	{
		InsertNonFull(Tree->Root, Key); // root is not full
	}
}

void Remove(BTree* Tree, int Key)
{
	RemoveNode(Tree->Root, Key); //remove key first

	if (Tree->Root->KeyIndex == 0) //
	{
		if (Tree->Root->Leaf == TRUE) // if root is leaf, and no keys in tree
		{
			Tree->Root = CreateBTreeNode();
		}
		else //change root to its child
		{
			Tree->Root = Tree->Root->Childs[0];
		}
	}
}

int FindKey(BTreeNode* Node, int Key)
{
	int Index = 0;
	while (Index < Node->KeyIndex && Node->Keys[Index] < Key) // find key equal or greater
	{
		Index++;
	}
	return Index;
}

void RemoveNode(BTreeNode* Node, int Key)
{
	int Index = FindKey(Node, Key); // Find key Index

	if (Index < Node->KeyIndex && Node->Keys[Index] == Key) // if key is exist in Node
	{
		if (Node->Leaf == TRUE)
		{
			RemoveFromLeaf(Node, Index);
		}
		else
		{
			RemoveFromNonLeaf(Node, Index);
		}
	}
	else
	{
		if (Node->Leaf == TRUE)
		{
			printf("Key %d is not exist in the tree\n", Key); // if Node is leaf and no key
			return;
		}

		int Flag; //indicator which node has key to be removed
		if (Node->KeyIndex == Index)
		{
			Flag = TRUE; // key in childs[index-1]
		}
		else
		{
			Flag = FALSE; // key in childs[index]
		}

		if (Node->Childs[Index]->KeyIndex < NODE_DEGREE) //child where the key is supposed to exist has less key than NODE_DEGREE
		{
			Fill(Node, Index); //need to fill the child
		}

		if (Flag && (Index > Node->KeyIndex))
		{
			RemoveNode(Node->Childs[Index - 1], Key); // Key supposed in the childs[index-1]
		}
		else
		{
			RemoveNode(Node->Childs[Index], Key); // Key supposed in the childs[index]
		}
	}
}

void RemoveFromLeaf(BTreeNode* Node, int Index)
{
	//remove the index th key from node
	for (int i = Index + 1; i < Node->KeyIndex; i++)
	{
		Node->Keys[i - 1] = Node->Keys[i];
	}
	Node->KeyIndex--;
}

void RemoveFromNonLeaf(BTreeNode* Node, int Index)
{
	int Key = Node->Keys[Index];

	if (Node->Childs[Index]->KeyIndex > NODE_DEGREE - 1)
	{
		//if childs[index] has at least NODE_DEGREE keys
		//find predecessor and replace Keys[index] by predecessor : Remove Key
		int Pred = Return_Predecessor(Node, Index);
		Node->Keys[Index] = Pred; 
		RemoveNode(Node->Childs[Index], Pred); // remove predecessor in childs[index]
	}
	else if (Node->Childs[Index + 1]->KeyIndex > NODE_DEGREE - 1)
	{
		//if childs[index] has keys less than NODE_DEGREE,
		//and if childs [index+1] has at least NODE_DEGREE keys, need to replace Key with its successor
		int Succ = Return_Successor(Node, Index);
		Node->Keys[Index] = Succ;
		RemoveNode(Node->Childs[Index + 1], Succ); //remove successor in childs[index+1]
	}
	else
	{
		//if both childs[index] and childs[index+1] has less than NODE_DEGREE keys
		Merge(Node, Index);
		RemoveNode(Node->Childs[Index], Key); // Key is in the childs[index], remove it
	}
}

void Fill(BTreeNode* Node, int Index)
{
	if (Index != 0 && Node->Childs[Index - 1]->KeyIndex > NODE_DEGREE - 1) // if the prev child has more than NODE_DEGREE-1
	{
		Borrow_From_Prev(Node, Index); // borrow key from that child
	}
	else if (Index != Node->KeyIndex && Node->Childs[Index + 1]->KeyIndex > NODE_DEGREE - 1) // if the next child has more than NODE_DEGREE-1
	{
		Borrow_From_Next(Node, Index); // borrow key from that child
	}
	else // merge with its sibling
	{
		if (Index != Node->KeyIndex) // if child is not the last child
		{
			Merge(Node, Index); // merge it with its sibling
		}
		else // if last child
		{
			Merge(Node, Index - 1); // merge it with its prev sibling
		}
	}
}

int Return_Predecessor(BTreeNode* Node, int Index)
{
	//Find predecessor has maximum key
	BTreeNode* Curr = Node->Childs[Index];
	while (Curr->Leaf == FALSE)
	{
		Curr = Curr->Childs[Curr->KeyIndex];
	}
	return Curr->Keys[Curr->KeyIndex - 1];
}

int Return_Successor(BTreeNode* Node, int Index)
{
	//Find successor has minimum key
	BTreeNode* Curr = Node->Childs[Index + 1];
	while (Curr->Leaf == FALSE)
	{
		Curr = Curr->Childs[0];
	}
	return Curr->Keys[0];
}

void Borrow_From_Prev(BTreeNode* Node, int Index)
{
	BTreeNode* Child = Node->Childs[Index];
	BTreeNode* Sibling = Node->Childs[Index - 1];

	for (int i = Child->KeyIndex - 1; i > -1; i--) // moving all key in child[index] ont step ahead
	{
		Child->Keys[i + 1] = Child->Keys[i];
	}

	if (Child->Leaf == FALSE) // if child is not leaf
	{
		for (int i = Child->KeyIndex; i > -1; i--)
		{
			Child->Childs[i + 1] = Child->Childs[i]; //move all its child pointers one setp ahead
		}
	}
	Child->Keys[0] = Node->Keys[Index - 1];

	if (Child->Leaf == FALSE)
	{
		Child->Childs[0] = Sibling->Childs[Sibling->KeyIndex]; // moving last child of sibling as first child of childs[index]
	}
	Node->Keys[Index - 1] = Sibling->Keys[Sibling->KeyIndex-1];

	Child->KeyIndex++;
	Sibling->KeyIndex--;
}

void Borrow_From_Next(BTreeNode* Node, int Index)
{
	BTreeNode* Child = Node->Childs[Index];
	BTreeNode* Sibling = Node->Childs[Index + 1];

	Child->Keys[Child->KeyIndex] = Node->Keys[Index]; // keys[index] is inserted as the last key in childs[index]

	if (Child->Leaf == FALSE)
	{
		Child->Childs[Child->KeyIndex + 1] = Sibling->Childs[0]; // first child of sibling is inserted as the last child into childs[index]
	}

	Node->Keys[Index] = Sibling->Keys[0]; // the first key from sibling is inserted into key[index]

	for (int i = 1; i < Sibling->KeyIndex; i++)
	{
		Sibling->Keys[i - 1] = Sibling->Keys[i]; // moving all keys in sibling one step behind
	}

	if (Sibling->Leaf == FALSE)
	{
		for (int i = 1; i < Sibling->KeyIndex; i++)
		{
			Sibling->Childs[i - 1] = Sibling->Childs[i]; //moving the child pointers one step behind
		}
	}

	Child->KeyIndex++;
	Sibling->KeyIndex--;
}

void Merge(BTreeNode* Node, int Index)
{
	BTreeNode* Child = Node->Childs[Index];
	BTreeNode* Sibling = Node->Childs[Index + 1];

	Child->Keys[NODE_DEGREE - 1] = Node->Keys[Index]; // moving key from the Node and insert it into NODE_DEGREE-1 th position of childs[index]

	for (int i = 0; i < Sibling->KeyIndex; i++)
	{
		Child->Keys[i + NODE_DEGREE] = Sibling->Keys[i]; // copying the keys from childs[index + 1] to childs[index] at the end
	}

	if (Child->Leaf == FALSE)
	{
		for (int i = 0; i < Sibling->KeyIndex + 1; i++)
		{
			Child->Childs[i + NODE_DEGREE] = Sibling->Childs[i]; // copying the child pointers from childs[index+1] to childs[index]
		}
	}

	for (int i = Index + 1; i < Node->KeyIndex; i++)
	{
		Node->Keys[i - 1] = Node->Keys[i]; // moving all keys after index in the Node one step before to fill the space
	}

	for (int i = Index + 2; i < Node->KeyIndex + 1; i++)
	{
		Node->Childs[i - 1] = Node->Childs[i]; // moving the child pointers after index + 1 in the Node one step before
	}

	Child->KeyIndex += Sibling->KeyIndex + 1;
	Node->KeyIndex--;
}

void PrintTree(BTreeNode* Node, int Level, int Blank)
{
	if (Node->KeyIndex == 0)
	{
		printf("Tree not exist\n");
		return;
	}

	if (Blank == TRUE)
	{
		for (int i = 0; i < Level; i++)
		{
			for (int j = 0; j < SPACE; j++)
			{
				printf(" ");
			}
			printf("|");
		}
	}

	if (Node->KeyIndex > 0)
	{
		for (int i = 0; i < (SPACE - 4 * Node->KeyIndex); i++)
		{
			printf(" ");
		}
		printf("[");
		for (int i = 0; i < Node->KeyIndex - 1; i++)
		{
			printf("%2d, ", Node->Keys[i]);
		}
		printf("%2d]|", Node->Keys[Node->KeyIndex - 1]);
	}
	else
	{
		printf("[ ]");
	}

	if (Node->Leaf == TRUE)
	{
		printf("\n");
		return;
	}
	else
	{
		for (int i = 0; i < Node->KeyIndex + 1; i++)
		{
			if (i != 0)
			{
				PrintTree(Node->Childs[i], Level + 1, TRUE);
			}
			else
			{
				PrintTree(Node->Childs[i], Level + 1, FALSE);
			}
		}
	}
}

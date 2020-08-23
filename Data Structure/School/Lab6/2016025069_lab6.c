#include <stdio.h>
#include <stdlib.h>
#define COUNT 12

typedef int DataType;
typedef struct BTNODE
{
	DataType Data;
	struct BTNODE* left;
	struct BTNODE* right;
} BTNODE;

/*typedef struct BST
{
	BTNODE* root;
} BST;*/

//Binary Tree function
BTNODE* MakeNode();
DataType Return_Data(BTNODE* Node);
void SaveData(BTNODE* Node, DataType input);
BTNODE* Return_SubTree_Left(BTNODE* Node);
BTNODE* Return_SubTree_Right(BTNODE* Node);

void Make_SubTree_Left(BTNODE* Parent, BTNODE* Child);
void Make_SubTree_Right(BTNODE* Parent, BTNODE* Child);
BTNODE* Remove_SubTree_Left(BTNODE* Node);
BTNODE* Remove_SubTree_Right(BTNODE* Node);
void Change_SubTree_Left(BTNODE* Node, BTNODE* Child);
void Change_SubTree_Right(BTNODE* Node, BTNODE* Child);

void Preorder_Traversal(BTNODE* root);
void Inorder_Traversal(BTNODE* root);
void Postorder_Traversal(BTNODE* root);

//Binary Search Tree 
void MakeBST(BTNODE** Node);
void Insert_Node(BTNODE** Tree, DataType input);
BTNODE* Insert_Node_AVL(BTNODE** Root, DataType input); 
BTNODE* Search_Node(BTNODE* Tree, DataType target);
BTNODE* Remove_Node(BTNODE** Tree, DataType target);

void PrintAll_BST(BTNODE* Node);
void Print_Tree(BTNODE* Node, int space);

//AVL Tree
BTNODE* Rebalance(BTNODE** Tree);
BTNODE* RotateLL(BTNODE* Node);
BTNODE* RotateRR(BTNODE* Node);
BTNODE* RotateLR(BTNODE* Node);
BTNODE* RotateRL(BTNODE* Node);

BTNODE* Rebalance_Remove(BTNODE** Root, DataType input);

int Return_Height(BTNODE* target);
int Return_Difference_Height_Of_Child(BTNODE* target);

void MakeAVL_Example(BTNODE** Tree);
void MakeAVL_Example_divide(BTNODE** Tree,int input);

int main(int argc,char* argv[])
{
	BTNODE* Root;
	BTNODE* Target_Node;
	int Target;

	MakeAVL_Example(&Root);

	//MakeBST(&Root);
	/*
	Insert_Node(&Root, 8); //
	Insert_Node(&Root, 4); //
	Insert_Node(&Root, 10);
	Insert_Node(&Root, 9);
	Insert_Node(&Root, 2); //
	Insert_Node(&Root, 11);
	//Insert_Node(&Root, 13); // Test
	Insert_Node(&Root, 6);
	Insert_Node(&Root, 1); //
	Insert_Node(&Root, 7);
	Insert_Node(&Root, 5); //
	Insert_Node(&Root, 12);
	Insert_Node(&Root, 3); //
	*/

	
	// Delete AVL Tree expression & Test
	/*
	Target = 7;
	printf("Delete node has data : %d\n", Target);
	Target_Node = Remove_Node(&Root, Target);
	free(Target_Node);

	PrintAll_BST(Root);
	printf("\n");
	
	Target = 5;
	printf("Delete node has data : %d\n", Target);
	Target_Node = Remove_Node(&Root, Target);
	free(Target_Node);
	
	PrintAll_BST(Root);
	printf("\n");
	
	
	Target = 8;
	printf("Delete node has data : %d\n", Target);
	Target_Node = Remove_Node(&Root, Target);
	free(Target_Node);
	
	PrintAll_BST(Root);
	printf("\n");
	*/

	return 0;
}

BTNODE* MakeNode()
{
	BTNODE* node = (BTNODE*)malloc(sizeof(BTNODE));
	node->left = NULL;
	node->right = NULL;
	return node;
}

DataType Return_Data(BTNODE* Node)
{
	return Node->Data;
}

void SaveData(BTNODE* Node, DataType input)
{
	Node->Data = input;
}

BTNODE* Return_SubTree_Left(BTNODE* Node)
{
	return Node->left;
}

BTNODE* Return_SubTree_Right(BTNODE* Node)
{
	return Node->right;
}

void Make_SubTree_Left(BTNODE* Parent, BTNODE* Child)
{
	if (Parent->left != NULL) free(Parent->left);
	Parent->left = Child;
}

void Make_SubTree_Right(BTNODE* Parent, BTNODE* Child)
{
	if (Parent->right != NULL) free(Parent->right);
	Parent->right = Child;
}

BTNODE* Remove_SubTree_Left(BTNODE* Node)
{
	//BTNODE* temp = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* temp = NULL;
	if (Node->left != NULL)
	{
		temp = Node->left;
		Node->left = NULL;
	}
	return temp;
}

BTNODE* Remove_SubTree_Right(BTNODE* Node)
{
	//BTNODE* temp = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* temp = NULL;
	if (Node->right != NULL)
	{
		temp = Node->right;
		Node->right = NULL;
	}
	return temp;
}

void Change_SubTree_Left(BTNODE* Node, BTNODE* Child)
{
	Node->left = Child;
}

void Change_SubTree_Right(BTNODE* Node, BTNODE* Child)
{
	Node->right = Child;
}

void Preorder_Traversal(BTNODE* root)
{
	if (root == NULL) return;
	printf("%d ", root->Data);
	Preorder_Traversal(root->left);
	Preorder_Traversal(root->right);
}

void Inorder_Traversal(BTNODE* root)
{
	if (root == NULL)
	{
		return;
	}
	Inorder_Traversal(root->left);
	printf("%d ", root->Data);
	Inorder_Traversal(root->right);
}

void Postorder_Traversal(BTNODE* root)
{
	if (root == NULL) return;
	Postorder_Traversal(root->left);
	Postorder_Traversal(root->right);
	printf("%d ", root->Data);
}

void MakeBST(BTNODE** Node)
{
	*Node = NULL;
}

void Insert_Node(BTNODE** Tree, DataType input)
{
	BTNODE* Parent = NULL;
	BTNODE* Current = *Tree;

	while (Current != NULL)
	{
		if (input == Return_Data(Current)) return;
		
		Parent = Current;
		if (input < Return_Data(Current)) Current = Return_SubTree_Left(Current);
		else Current = Return_SubTree_Right(Current);
	}

	BTNODE* Temp = MakeNode();
	SaveData(Temp, input);
	
	if (Parent == NULL)
	{
		*Tree = Temp;
		//printf("Root Node Add\n");
	}
	else
	{
		if (input < Return_Data(Parent))
		{
			Make_SubTree_Left(Parent, Temp);
			//printf("Left Node Add\n");
		}
		else
		{
			Make_SubTree_Right(Parent, Temp);
			//printf("Right Node Add\n");
		}
	}
}

BTNODE* Insert_Node_AVL(BTNODE** Root, DataType input)
{
	if (*Root == NULL) //Insert Position
	{
		*Root = MakeNode();
		SaveData(*Root, input);
	}
	else if(*Root!=NULL)
	{
		if (input < Return_Data(*Root)) 
		{
			Insert_Node_AVL(&((*Root)->left), input); // recursive that parameter used addr of left child of Root
			*Root = Rebalance(Root); //AVL Rebalance Node
		}
		else if (input > Return_Data(*Root))
		{
			//Insert_Node_AVL(Return_SubTree_Right(*Root), input);
			Insert_Node_AVL(&((*Root)->right), input); // recursive that parameter used addr of right child of Root
			*Root = Rebalance(Root); //AVL Rebalance Node
		}
		else return NULL;
	}
	return *Root; //where does it used???
}

BTNODE* Search_Node(BTNODE* Tree, DataType target)
{
	BTNODE* Current = Tree;
	DataType Data;

	while (Current != NULL)
	{
		Data = Return_Data(Current);
		if (target == Data) return Current;
		else if (target < Data) Current = Return_SubTree_Left(Current);
		else Current = Return_SubTree_Right(Current);
	}
	return NULL;
}

BTNODE* Remove_Node(BTNODE** Tree, DataType target)
{
	BTNODE* Virtual = MakeNode(); //Make Virtual Node
	BTNODE* Parent = Virtual; // Parent = Virtual
	BTNODE* Current = *Tree; // Current = Root Node

	Change_SubTree_Right(Virtual, *Tree); // Virtual Child Node = Root Node 

	while (Current != NULL && Return_Data(Current) != target) //Find Target Node
	{
		Parent = Current; // Parent Change
		if (target < Return_Data(Parent)) Current = Return_SubTree_Left(Parent);
		else if (target > Return_Data(Parent)) Current = Return_SubTree_Right(Parent);
	}

	if (Current == NULL) return NULL; // Target Not in the Tree
	
	BTNODE* Target_Node = Current; // Target Node setting

	//if (Return_SubTree_Left(Target_Node) != NULL) printf("Left Not NULL   ");
	//if (Return_SubTree_Right(Target_Node) != NULL) printf("Right Not NULL   ");
	//printf("\n");

	if (Return_SubTree_Left(Target_Node) == NULL && Return_SubTree_Right(Target_Node) == NULL) // Non Child
	{
		if (Return_SubTree_Left(Parent) == Target_Node) Remove_SubTree_Left(Parent);
		else Remove_SubTree_Right(Parent);
	}
	else if (Return_SubTree_Left(Target_Node) == NULL || Return_SubTree_Right(Target_Node) == NULL) // One Child(Only Left or Only Right)
	{
		BTNODE* Child_Target; //Child store Node
		if (Return_SubTree_Left(Target_Node) != NULL) Child_Target = Return_SubTree_Left(Target_Node); //Left Child save
		else Child_Target = Return_SubTree_Right(Target_Node); // Right Child save

		if (Return_SubTree_Left(Parent) == Target_Node) Change_SubTree_Left(Parent, Child_Target); //  If Target Node is Left child Node, Change Child to Target_Node_Child
		else Change_SubTree_Right(Parent, Child_Target); //  If Target Node is Right child Node, Change Child to Target_Node_Child
	}
	else if(Return_SubTree_Left(Target_Node) != NULL && Return_SubTree_Right(Target_Node) != NULL)//both Right_Child and Left_Child
	{
		BTNODE* MaximumNode = Return_SubTree_Left(Target_Node); // FInd Maximum Value in Left Childern Node of Target Node 
		BTNODE* Parent_of_MaximumNode = Target_Node; //First Parent = Target_Node
		
		//DataType backup;

		while (Return_SubTree_Right(MaximumNode) != NULL) // Find Maximum Node Code
		{
			Parent_of_MaximumNode = MaximumNode;
			MaximumNode = Return_SubTree_Right(Parent_of_MaximumNode); //Maximum node will be Right position
		}
		
		//backup = Return_Data(Target_Node);
		SaveData(Target_Node, Return_Data(MaximumNode)); // Data Change

		if (Return_SubTree_Left(Parent_of_MaximumNode) == MaximumNode) Change_SubTree_Left(Parent_of_MaximumNode, Return_SubTree_Right(MaximumNode)); // If Maximum Node is Left Child Node of Parent, Change Child Node
		else Change_SubTree_Right(Parent_of_MaximumNode, Return_SubTree_Right(MaximumNode)); // If Maximum Node is Right Child Node of Parent, Change Child Node

		Target_Node = MaximumNode; // Set Maximum Node to target Node
		//SaveData(Target_Node, backup);
	}

	if (Return_SubTree_Right(Virtual) != *Tree) *Tree = Return_SubTree_Right(Virtual); // if Target Node is Root, Root Reset

	int data = Return_Data(Parent); //Stored Data the root node
	Rebalance_Remove(Tree, data); //Rebanlancing Tree from Root to Parent Node

	free(Virtual); //Delete Virtual node
	return Target_Node; // Return Target Node and delete it in main method
}

void PrintAll_BST(BTNODE* Node)
{
	//Preorder_Traversal(Node);
	//Inorder_Traversal(Node);
	//Postorder_Traversal(Node);
	Print_Tree(Node, 0);
}

void Print_Tree(BTNODE* Node, int space)
{
	if (Node == NULL)
	{
		return;
	}
	
	space += COUNT;

	Print_Tree(Node->right, space);
	
	printf("\n");
	for (int i = COUNT; i < space; i++)
	{
		printf(" ");
	}
	printf("%d\n", Node->Data);

	Print_Tree(Node->left, space);
}

BTNODE* Rebalance(BTNODE** Tree)
{
	int difference = Return_Difference_Height_Of_Child(*Tree); // Get Difference Height

	if (difference > 1) // Left Child height more than bigger right child
	{
		if (Return_Difference_Height_Of_Child(Return_SubTree_Left(*Tree)) > 0) //left child difference height says this case is LL Rotate
		{
			//printf("Rotate LL\n");
			*Tree = RotateLL(*Tree);
		}
		else //LR Rotate
		{
			//printf("Rotate LR\n");
			*Tree = RotateLR(*Tree);
		}
	}
	
	else if (difference < -1) // Right Child height more than bigger left child
	{
		if (Return_Difference_Height_Of_Child(Return_SubTree_Right(*Tree)) > -1) //right child difference height says this case is RL Rotate
		{
			//printf("Rotate RL\n");
			*Tree = RotateRL(*Tree);
		}
		else
		{
			//printf("Rotate RR\n");
			*Tree = RotateRR(*Tree);
		}
	}

	return *Tree;
}

BTNODE* RotateLL(BTNODE* Node)
{
	BTNODE* Parent = Node; 
	BTNODE* Child = Return_SubTree_Left(Parent); 

	Change_SubTree_Left(Parent, Return_SubTree_Right(Child)); //Set left child of right child that left child of Parent 
	Change_SubTree_Right(Child, Parent); // Rotate it

	return Child;
}

BTNODE* RotateRR(BTNODE* Node)
{
	BTNODE* Parent = Node;
	BTNODE* Child = Return_SubTree_Right(Parent);

	Change_SubTree_Right(Parent, Return_SubTree_Left(Child)); //Set right child of left child that right child of Parent
	Change_SubTree_Left(Child, Parent); // Rotate

	return Child;
}

BTNODE* RotateLR(BTNODE* Node)
{
	BTNODE* Parent = Node;
	BTNODE* Child = Return_SubTree_Left(Parent);

	Child = RotateRR(Child); //First, child node and right child of child node rotate so make LL situation
	Change_SubTree_Left(Parent, Return_SubTree_Right(Child)); // and do LL sistuation
	Change_SubTree_Right(Child, Parent);

	return Child;
}

BTNODE* RotateRL(BTNODE* Node) //Lab6 Training Assignment Implementation
{
	BTNODE* Parent = Node;
	BTNODE* Child = Return_SubTree_Right(Parent);

	Child = RotateLL(Child); // Also, child node and left child of child node rotate LL, so make RR situation
	Change_SubTree_Right(Parent, Return_SubTree_Left(Child)); // and do it
	Change_SubTree_Left(Child, Parent);

	return Child;
}

BTNODE* Rebalance_Remove(BTNODE** Root, DataType input) //Rebalance when Remove Node
{
	if (*Root != NULL)
	{
		if (input < Return_Data(*Root))
		{
			Rebalance_Remove(&((*Root)->left), input);
			*Root = Rebalance(Root);
		}
		else if (input > Return_Data(*Root))
		{
			Rebalance_Remove(&((*Root)->right), input);
			*Root = Rebalance(Root);
		}
		else
		{
			*Root = Rebalance(Root);
			return NULL;
		}
	}
	return *Root;
}

int Return_Height(BTNODE* target) // Get Height and Return it
{
	int Height_Left, Height_Right;
	if (target == NULL) return -1; // NULL node is child of Leaf node, and leaf node's height is 0, so NULL Node height must be -1

	Height_Left = Return_Height(Return_SubTree_Left(target));
	Height_Right = Return_Height(Return_SubTree_Right(target));
	
	if (Height_Left > Height_Right) return Height_Left + 1; 
	else return Height_Right + 1;
}

int Return_Difference_Height_Of_Child(BTNODE* target)
{
	int Height_Left, Height_Right;
	if (target == NULL) return 0;

	Height_Left = Return_Height(Return_SubTree_Left(target));
	Height_Right = Return_Height(Return_SubTree_Right(target));
	return Height_Left - Height_Right;
}

void MakeAVL_Example(BTNODE** Tree)
{
	//BTNODE* Node;
	//MakeBST(&Node);
	//printf("%d", &Tree);
	*Tree = NULL;

	MakeAVL_Example_divide(Tree, 5);
	MakeAVL_Example_divide(Tree, 4);
	MakeAVL_Example_divide(Tree, 3);
	MakeAVL_Example_divide(Tree, 1);
	MakeAVL_Example_divide(Tree, 2);
	MakeAVL_Example_divide(Tree, 6);
	MakeAVL_Example_divide(Tree, 7);
	MakeAVL_Example_divide(Tree, 9);
	MakeAVL_Example_divide(Tree, 8);
}

void MakeAVL_Example_divide(BTNODE** Tree, int input)
{
	printf("Insert %d\n", input);
	Insert_Node_AVL(Tree, input);
	PrintAll_BST(*Tree);
	printf("\n");
}



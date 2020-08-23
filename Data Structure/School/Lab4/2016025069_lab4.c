#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef int DATATYPE;

typedef struct TreeNode
{
	DATATYPE data;
	struct TreeNode* Left;
	struct TreeNode* Right;
} TreeNode;


typedef TreeNode* NDTYPE;

typedef struct Node
{
	NDTYPE data;
	struct Node* next;
} Node;

typedef struct
{
	Node* head;
} ListStack;

TreeNode* MakeExpTree(char exp[]); // Make postfix equation to tree data structure
int EvalExpTree(TreeNode* tree); //evaluation postfix equation by treenode

void PrintExpTreePrefix(TreeNode* tree);
void PrintExpTreeInfix(TreeNode* tree);
void PrintExpTreePostfix(TreeNode* tree);

void PreorderTraversal(TreeNode* tree); //preorder traversal
void InorderTraversal(TreeNode* tree); //inorder traversal
void PostorderTraversal(TreeNode* tree); //postorder traversal

TreeNode* MakeTree(void); // make empty tree node
DATATYPE RetData(TreeNode* tree); // return data in tree node
void SaveData(TreeNode* tree, DATATYPE data); //set data in tree node

TreeNode* RetSubTreeLeft(TreeNode* tree); //return left tree
TreeNode* RetSubTreeRight(TreeNode* tree); //return right tree

void MakeSubTreeLeft(TreeNode* tree, TreeNode* subtree); //set left tree
void MakeSubTreeRight(TreeNode* tree, TreeNode* subtree); //set right tree

void PrintNodeData(int data);

void InitStack(ListStack* stack);
int IsEmpty(ListStack* stack);

void Push(ListStack* stack, NDTYPE data);
NDTYPE Pop(ListStack* stack);
NDTYPE Peek(ListStack* stack);

int main(int argc, char* argv[])
{
	char exp[] = "12+7*"; //Test another case : char exp[] = "327+*6+";
	TreeNode* tree = MakeExpTree(exp); // get root node

	printf("prefix : ");
	PrintExpTreePrefix(tree);
	printf("\n");

	printf("infix : ");
	PrintExpTreeInfix(tree);
	printf("\n");

	printf("postfix : ");
	PrintExpTreePostfix(tree);
	printf("\n");

	printf("result : %d\n", EvalExpTree(tree)); //evaluation root node

	return 0;
}

TreeNode* MakeExpTree(char exp[]) // Make postfix equation to tree data structure
{
	ListStack stack;
	TreeNode* tree;

	int ExpLen = strlen(exp); // leghth of exp

	InitStack(&stack);

	for (int i = 0; i < ExpLen; i++)
	{
		tree = MakeTree(); // make tree 

		if (isdigit(exp[i])) // int data
		{
			SaveData(tree, exp[i] - '0'); // make tree node integer
		}
		else // char data
		{
			SaveData(tree, exp[i]); // make root tree
			MakeSubTreeRight(tree, Pop(&stack)); //Pop stack and inserted right tree in root
			MakeSubTreeLeft(tree, Pop(&stack)); // Pop stack and inserted left tree in root
		}
		Push(&stack, tree); //push tree node in stack
	}

	return Pop(&stack); // pop root node
}

int EvalExpTree(TreeNode* tree) // evaluation postfix equation by treenode
{
	if (tree->Left == NULL && tree->Right == NULL) //reached leaf node
	{
		return RetData(tree); // return int data
	}

	int op1 = EvalExpTree(RetSubTreeLeft(tree)); // get access left tree node data
	int op2 = EvalExpTree(RetSubTreeRight(tree)); // get access right tree node data


	switch (RetData(tree))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}

void PrintExpTreePrefix(TreeNode* tree)
{
	PreorderTraversal(tree);
}

void PrintExpTreeInfix(TreeNode* tree)
{
	InorderTraversal(tree);
}

void PrintExpTreePostfix(TreeNode* tree)
{
	PostorderTraversal(tree);
}

void PrintNodeData(int data)
{
	if (0 <= data && data <= 9)
	{
		printf("%d ", data);
	}
	else
	{
		printf("%c ", data);
	}
}

void PreorderTraversal(TreeNode* tree) //print data -> left tree -> right tree
{
	if (tree == NULL) // if tree is NULL
	{
		return;
	}

	PrintNodeData(tree->data); 
	PreorderTraversal(tree->Left);
	PreorderTraversal(tree->Right);
}

void InorderTraversal(TreeNode* tree) // left tree -> print data -> right tree
{
	if (tree == NULL) // if tree is NULL
	{
		return;
	}

	InorderTraversal(tree->Left);
	PrintNodeData(tree->data);
	InorderTraversal(tree->Right);
}

void PostorderTraversal(TreeNode* tree) // left tree -> right tree -> print data
{
	if (tree == NULL) // if tree is NULL
	{
		return;
	}

	PostorderTraversal(tree->Left);
	PostorderTraversal(tree->Right);
	PrintNodeData(tree->data);
}

TreeNode* MakeTree(void)
{
	TreeNode* tree = (TreeNode*)malloc(sizeof(TreeNode));
	tree->Left = NULL;
	tree->Right = NULL;

	return tree;
}//change to pass by argument

DATATYPE RetData(TreeNode* tree)
{
	return tree->data;
}

void SaveData(TreeNode* tree, DATATYPE data)
{
	tree->data = data;
}

TreeNode* RetSubTreeLeft(TreeNode* tree) //return left tree node in tree node
{
	return tree->Left;
}

TreeNode* RetSubTreeRight(TreeNode* tree) //return right tree node in tree node
{
	return tree->Right;
}

void MakeSubTreeLeft(TreeNode* tree, TreeNode* subtree) //set left tree node in tree node
{
	if (tree->Left != NULL) //if left tree node isn't empty
	{
		free(tree->Left); // delete left tree node
	}

	tree->Left = subtree; // set left tree node
}

void MakeSubTreeRight(TreeNode* tree, TreeNode* subtree) //set rightt tree node in tree node
{
	if (tree->Right != NULL) //if right tree node isn't empty
	{
		free(tree->Right); // delete right tree node
	}

	tree->Right = subtree; // set right tree node
}

void InitStack(ListStack* stack)
{
	stack->head = NULL;
}

int IsEmpty(ListStack* stack)
{
	if (stack->head == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void Push(ListStack* stack, NDTYPE data)
{
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = data;
	temp->next = stack->head;

	stack->head = temp;
}

NDTYPE Pop(ListStack* stack)
{
	NDTYPE tempData;
	Node* temp;

	if (IsEmpty(stack))
	{
		printf("Stack is empty\n");
		exit(1);
	}

	tempData = stack->head->data;
	temp = stack->head;

	stack->head = stack->head->next;
	free(temp);

	return tempData;
}

NDTYPE Peek(ListStack* stack)
{
	if (IsEmpty(stack))
	{
		printf("Stack is empty\n");
		exit(1);
	}

	return stack->head->data;
}

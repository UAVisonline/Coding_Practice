#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char Element;

typedef struct _node {
	Element data;
	struct _node* next;
}node;

typedef struct {
	node* head;
}Stack;

void InitStack(Stack* stack);
int IsEmpty_Stack(Stack* stack);
void Push(Stack* stack, Element data);
Element Pop(Stack* stack);
Element Peek(Stack* stack);
void ConvertExp(char* infix);
int GetOperatorPriority(char op);
int CompareOperatorPriority(char op1, char op2);
int EvalExp(char* exp);

typedef struct _intnode {
	int data;
	struct _intnode* next;
}intnode;

typedef struct {
	intnode* head;
}Int_Stack;

void Int_InitStack(Int_Stack* stack);
int Int_IsEmpty_Stack(Int_Stack* stack);
void Int_Push(Int_Stack* stack, int data);
int Int_Pop(Int_Stack* stack);

int main(int argc,char* argv[])
{
	Stack convert_stack;
	InitStack(&convert_stack);
	char* inputs[] = { "1+2*3","(1+2)*3","((1-2)+3)*(5-2)" };
	for (int i = 0; i < sizeof(inputs) / sizeof(char*); i++) ConvertExp(inputs[i]);
	return 0;
}

void InitStack(Stack* stack)
{
	stack->head = NULL;
}

int IsEmpty_Stack(Stack* stack)
{
	if (stack->head == NULL) return 1;
	else return 0;
}

void Push(Stack* stack, Element data)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;

	temp->next = stack->head;
	stack->head = temp;
}

Element Pop(Stack* stack)
{
	if (IsEmpty_Stack(stack)) 
	{
		printf("Empty Stack\n");
		exit(1);
	}
	else
	{
		node* temp = stack->head;
		stack->head = stack->head->next;
		Element output = temp->data;
		free(temp);
		return output;
	}
}

Element Peek(Stack* stack)
{
	if (IsEmpty_Stack(stack))
	{
		printf("Empty Stack\n");
		exit(1);
	}
	else
		return stack->head->data;
}

void ConvertExp(char* infix)
{
	Stack* oper_stack = (Stack*)malloc(sizeof(Stack));
	InitStack(oper_stack);
	char* postfix = (char*)malloc(sizeof(char) * (strlen(infix)+3)); 
	memset(postfix, 0, strlen(infix)+3);
	int pos = 0;
	for (int i = 0; i < strlen(infix); i++)
	{
		if (infix[i] - '0' >= 0 && infix[i] - '0' <= 9)
		{
			postfix[pos++] = infix[i];
		}
		else
		{
			if (IsEmpty_Stack(oper_stack)) Push(oper_stack, infix[i]);
			else
			{
				if (CompareOperatorPriority(Peek(oper_stack), infix[i]) == -1) Push(oper_stack, infix[i]);
				else if (CompareOperatorPriority(Peek(oper_stack), infix[i]) == 0)
				{
					if (GetOperatorPriority(infix[i]) != 1)
					{
						Element data = Pop(oper_stack);
						postfix[pos++] = data;
					}
					Push(oper_stack, infix[i]);
				}
				else
				{
					if (GetOperatorPriority(infix[i]) == 5 || GetOperatorPriority(infix[i]) == 3) Push(oper_stack, infix[i]);
					while (!IsEmpty_Stack(oper_stack))
					{
						if (GetOperatorPriority(infix[i]) == 1)
						{
							Push(oper_stack, infix[i]);
							break;
						}
						Element data = Pop(oper_stack);
						if (GetOperatorPriority(data) == 5 || GetOperatorPriority(data) == 3) postfix[pos++] = data;
						else if (GetOperatorPriority(data) == 1) break;
					}
				}
			}
		}
	}
	while (!IsEmpty_Stack(oper_stack))
	{
		Element data = Pop(oper_stack);
		if (GetOperatorPriority(data) == 5 || GetOperatorPriority(data) == 3) postfix[pos++] = data;
	}
	free(oper_stack);
    printf("%s = %d\n", postfix,EvalExp(postfix));
	free(postfix);
	//free(oper_stack);
}

int GetOperatorPriority(char op)
{
	if (op == '*' || op == '/') return 5;
	else if (op == '+' || op == '-') return 3;
	else if (op == '(') return 1;
	else if (op == ')') return -1;
}

int CompareOperatorPriority(char op1, char op2)
{
	if (GetOperatorPriority(op1) == GetOperatorPriority(op2)) return 0;
	else if (GetOperatorPriority(op1) > GetOperatorPriority(op2)) return 1;
	else if (GetOperatorPriority(op1) < GetOperatorPriority(op2)) return -1;
}

int EvalExp(char* exp)
{
	Int_Stack* stack = (Int_Stack*)malloc(sizeof(Int_Stack));
	Int_InitStack(stack);
	int size = strlen(exp);
	for (int i = 0; i < size; i++)
	{
		if (exp[i] - '0' >= 0 && exp[i] - '0' <= 9) Int_Push(stack, (int)(exp[i] - '0'));
		else
		{
			if (exp[i] == '*')
			{
				int first = Int_Pop(stack);
				int second = Int_Pop(stack);
				Int_Push(stack, second * first);
			}
			else if (exp[i] == '/')
			{
				int first = Int_Pop(stack);
				int second = Int_Pop(stack);
				Int_Push(stack,second / first);
			}
			else if (exp[i] == '+')
			{
				int first = Int_Pop(stack);
				int second = Int_Pop(stack);
				Int_Push(stack, second + first);
			}
			else if (exp[i] == '-')
			{
				int first = Int_Pop(stack);
				int second = Int_Pop(stack);
				Int_Push(stack, second - first);
			}
		}
	}
	//printf("%d  ", size);
	int result = Int_Pop(stack);
	free(stack);
	return result;
}

void Int_InitStack(Int_Stack* stack)
{
	stack->head = NULL;
}

int Int_IsEmpty_Stack(Int_Stack* stack)
{
	if (stack->head == NULL) return 1;
	else return 0;
}

void Int_Push(Int_Stack* stack, int data)
{
	intnode* temp = (intnode*)malloc(sizeof(intnode));
	temp->data = data;

	temp->next = stack->head;
	stack->head = temp;
}

int Int_Pop(Int_Stack* stack)
{
	if (Int_IsEmpty_Stack(stack))
	{
		printf("Empty Stack\n");
		exit(1);
	}
	else
	{
		intnode* temp = stack->head;
		stack->head = stack->head->next;
		int output = temp->data;
		free(temp);
		return output;
	}
}

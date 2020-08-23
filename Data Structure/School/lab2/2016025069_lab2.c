#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int ID;
	char* Name;
}Student;

typedef struct _Node {
	Student person;
	struct _Node* next;
}Node;

typedef struct {
	Node* Head;
	Node* Tail;
	int size;
}Linked_List;

void InitList(Linked_List* list);
void InsertNode(Linked_List* list, int ID_data, char* name);
void DeleteNode(Linked_List* list, int ID_data);
void PrintList(Linked_List* list);

int main(int argc,char* argv[])
{
	Linked_List single;
	InitList(&single);
	srand(time(NULL));
	int input_size = 5 + rand() % 5;//ID array size
	int *ID_array = (int*)malloc(sizeof(int)*input_size);//ID array declaration
	char name[][20] = {"test person 1","test person 2","test person 3","test person 4","test person 5","test person 6","test person 7","test person 8","test person 9","test person 10"}; //Student Name declaration
	for (int i = 0; i < input_size; i++)
	{
		int ID = 2020000000 + rand() % 300000;
		ID_array[i] = ID;
		InsertNode(&single, ID, name[i]);//Insert Node & Sort by ID
	}
	PrintList(&single);//Print all Nodes
	DeleteNode(&single, ID_array[rand()%input_size]);//Delete Node using ID
	PrintList(&single);//Print all Nodes

	return 0;
}

void InitList(Linked_List* list)
{
	list->Head = (Node*)malloc(sizeof(Node));
	list->Head->next = NULL;
	//list->Tail = NULL;
	list->size = 0;
}

void InsertNode(Linked_List* list, int ID_data, char* name)
{
	//printf("%d\n", ID_data);
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->person.ID = ID_data;
	temp->person.Name = name;
	temp->next = NULL;
	if (list->Head->next == NULL)//Empty List
	{
		list->Head->next = temp;
	}	
	else
	{
		Node* prev = list->Head;
		while (prev->next != NULL)
		{
			if (prev->next->person.ID > temp->person.ID)//List�� ������ ���ο� �Է°��� ������
			{
				temp->next = prev->next;
				prev->next = temp;
				break;
			}
			prev = prev->next;//List�� ���� ������ �̵�
			if (prev->next == NULL)//�� ������ �Էµ����� �ʾ����� List������ ����������
			{
				prev->next = temp;
				break;
			}
		}
	}
	list->size++;
}

void DeleteNode(Linked_List* list, int ID_data)
{
	Node* prev = list->Head;
	while (prev->next != NULL)
	{
		if (prev->next->person.ID == ID_data)//���� ������ �����ҷ��� �����϶�
		{
			Node* tmp = prev->next;//���������� ���� Node����
			prev->next = prev->next->next;
			free(tmp);//��������
			list->size--;
		}
		else
		{
			prev = prev->next;//���������� �̵�
		}
	}
	printf("Delete student node ID = %d\n",ID_data);
	printf("\n");
}

void PrintList(Linked_List* list)
{
	printf("Num of datas %d\n", list->size);
	Node *prev = list->Head->next;
	while (prev != NULL)
	{
		printf("ID : %d, Name : %s\n", prev->person.ID, prev->person.Name);
		prev = prev->next;
	}
	printf("\n");
}

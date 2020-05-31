#include <stdio.h>
#include <stdlib.h>
#include "Link.h"

int main()
{
	Linked_List* List = (Linked_List*)malloc(sizeof(Linked_List));
	List->head = NULL;
	List->tail = NULL;
	printf("1. Node ����, 2.Node ����, 3.Linked List ���, 4.Find data 0.Program Exit\n");
	int i = 0;
	do 
	{
		scanf("%d", &i);
		if (i == 1)
		{
			printf("������ �����͸� �Է��ϼ���.\n");
			int data;
			scanf("%d", &data);
			InsertNode(data,List);
		}
		else if (i == 2)
		{
			printf("ã�Ƽ� ������ �����͸� �Է��ϼ���.\n");
			int data;
			scanf("%d", &data);
			if (FindNode(data,List) == 1)
			{
				DeleteNode(data, List);
			}
			else if (FindNode(data, List) == 0)
			{
				printf("\"%d\"�� ã�� ���߽��ϴ�.\n", data);
			}
		}
		else if (i == 3)
		{
			ShowAllNode(*List);
		}
		else if (i == 4)
		{
			printf("ã�� �����͸� �Է��ϼ���.\n");
			int data;
			scanf("%d", &data);
			if (FindNode(data, List) == 1)
			{
				printf("\"%d\"�� Linked List�ȿ� ����ֽ��ϴ�.\n", data);
			}
			else if (FindNode(data, List) == 0)
			{
				printf("\"%d\"�� ã�� ���߽��ϴ�.\n", data);
			}
		}

	} while (i != 0);

	free(List);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "Link.h"

int main()
{
	Linked_List* List = (Linked_List*)malloc(sizeof(Linked_List));
	List->head = NULL;
	List->tail = NULL;
	printf("1. Node 삽입, 2.Node 삭제, 3.Linked List 출력, 4.Find data 0.Program Exit\n");
	int i = 0;
	do 
	{
		scanf("%d", &i);
		if (i == 1)
		{
			printf("삽입할 데이터를 입력하세요.\n");
			int data;
			scanf("%d", &data);
			InsertNode(data,List);
		}
		else if (i == 2)
		{
			printf("찾아서 삭제할 데이터를 입력하세요.\n");
			int data;
			scanf("%d", &data);
			if (FindNode(data,List) == 1)
			{
				DeleteNode(data, List);
			}
			else if (FindNode(data, List) == 0)
			{
				printf("\"%d\"를 찾지 못했습니다.\n", data);
			}
		}
		else if (i == 3)
		{
			ShowAllNode(*List);
		}
		else if (i == 4)
		{
			printf("찾을 데이터를 입력하세요.\n");
			int data;
			scanf("%d", &data);
			if (FindNode(data, List) == 1)
			{
				printf("\"%d\"는 Linked List안에 들어있습니다.\n", data);
			}
			else if (FindNode(data, List) == 0)
			{
				printf("\"%d\"를 찾지 못했습니다.\n", data);
			}
		}

	} while (i != 0);

	free(List);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "Link.h"

void InsertNode(int _data, Linked_List* L)
{
	node* value = (node*)malloc(sizeof(node));
	value->data = _data;
	value->next = NULL;
	if (L->head == NULL && L->tail==NULL)
	{
		L->head = L->tail = value;
	}
	else
	{
		L->tail->next = value;
		L->tail = value;
	}
	printf("%d 데이터 등록을 완료했습니다.\n", _data);
}

void DeleteNode(int _data, Linked_List* L)
{
	node* prev = L->head;
	if (prev->data == _data)
	{
		if (L->head == L->tail)
		{
			free(L->head);
			L->head = L->tail = NULL;
		}
		else
		{
			L->head = L->tail;
			free(prev);
		}
	}
	else
	{
		while (prev->next != NULL)
		{
			if (prev->next->data == _data)
			{
				node* tmp = prev->next;
				if (prev->next == L->tail)
				{
					free(L->tail);
					prev->next = NULL;
					L->tail = prev;
				}
				else if (prev->next != L->tail)
				{
					prev->next = prev->next->next;
					free(tmp);
				}
				
			}
			else
			{
				prev = prev->next;
			}
		}
	}
	printf("%d를 삭제하였습니다.\n", _data);
}

void ShowAllNode(Linked_List L)
{
	if (L.head == NULL && L.tail == NULL)
	{
		printf("Linked List는 비어있습니다.\n");
	}
	else
	{
		node* print = L.head;
		int i = 1;
		do
		{
			printf("%d번째 데이터 : %d\n", i++, print->data);
			if (print->next != NULL) print = print->next;
			else if (print->next == NULL) break;
		} while (1);
		//free(print);
	}
}

int FindNode(int _data, Linked_List* L)
{
	if (L->head == NULL && L->tail == NULL) return 0;
	else 
	{
		node *find = L->head;
		do 
		{
			if (find->data == _data) return 1;
			else if (find->next != NULL) find = find->next;
			else if (find->next == NULL) break;
		} while (1);
		//free(find);
	}
	return 0;
}

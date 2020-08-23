#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef char DATATYPE;

/*
typedef struct {
	int Priority;
	DATATYPE Data;
}Element;
*/

typedef struct HEAP {
	DATATYPE arr[HEAP_LEN];
	int NumofData;
}Heap;

void HeapInit(Heap* THeap);
int IsEmpty(Heap* THeap);

void HeapInsert(Heap* THeap, DATATYPE Data);
DATATYPE HeapDelete(Heap* THeap);

int RetIndexParent(int index);
int RetIndexLeftChild(int index);
int RetIndexRightChild(int index);
int RetIndexHigherPriorityOfChilds(Heap* THeap, int index);

void PrintAll(Heap* THeap);

//Max Heap
int main(int argc, char* argv[])
{
	Heap heap;
	HeapInit(&heap);

	HeapInsert(&heap, 'T');
	HeapInsert(&heap, 'H');
	HeapInsert(&heap, 'I');
	HeapInsert(&heap, 'S');
	HeapInsert(&heap, 'I');
	HeapInsert(&heap, 'S');
	HeapInsert(&heap, 'H');
	HeapInsert(&heap, 'E');
	HeapInsert(&heap, 'A');
	HeapInsert(&heap, 'P');

	PrintAll(&heap);
	printf("\n");

	printf("%c\n", HeapDelete(&heap));
	printf("\n");

	PrintAll(&heap);
	printf("\n");

	while (!IsEmpty(&heap))
	{
		printf("%c\n", HeapDelete(&heap));
	}

	return 0;
}

void HeapInit(Heap* THeap)
{
	THeap->NumofData = 0;
}

int IsEmpty(Heap* THeap)
{
	if (THeap->NumofData == 0) return TRUE;
	else return FALSE;
}

void HeapInsert(Heap* THeap, DATATYPE Data)
{
	int index = THeap->NumofData + 1;

	while (index != 1)
	{
		if(Data > THeap->arr[RetIndexParent(index)]) // if Insert Data is bigger than parent Data
		{
			THeap->arr[index] = THeap->arr[RetIndexParent(index)]; //Parent data go to child position
			index = RetIndexParent(index); // index indicate parent's of present index
		}
		else break;
	}

	THeap->arr[index] = Data; // Insert Data position
	THeap->NumofData++; // Number of Data up
}

DATATYPE HeapDelete(Heap* THeap)
{
	DATATYPE Data = THeap->arr[1];
	DATATYPE last = THeap->arr[THeap->NumofData];

	int ParentIndex = 1;
	int ChildIndex;

	while (ChildIndex = RetIndexHigherPriorityOfChilds(THeap, ParentIndex)) //child index is bigger one child position
	{
		if (THeap->arr[ChildIndex] <= last)// if last data is bigger than bigger child data
		{
			break; // 
		}
		THeap->arr[ParentIndex] = THeap->arr[ChildIndex]; //parent node data change bigger child data
		ParentIndex = ChildIndex; // index indicate child index
	}

	THeap->arr[ParentIndex] = last; // last node set the parent index node(it is bigger than both child node)
	THeap->NumofData--; // number of data down
	return Data; // return delete data
}

int RetIndexParent(int index)
{
	return index/2;
}

int RetIndexLeftChild(int index)
{
	return index*2;
}

int RetIndexRightChild(int index)
{
	return RetIndexLeftChild(index)+1;
}

int RetIndexHigherPriorityOfChilds(Heap* THeap, int index)
{
	if (RetIndexLeftChild(index) > THeap->NumofData) // No Child
	{
		return 0;
	}
	else if (RetIndexLeftChild(index) == THeap->NumofData) // only one child
	{
		return RetIndexLeftChild(index);
	}
	else //both child (bigger one return)
	{
		if (THeap->arr[RetIndexRightChild(index)] > THeap->arr[RetIndexLeftChild(index)] ) // if Right child is bigger than left child
		{
			return RetIndexRightChild(index); // return right child
		}
		else
		{
			return RetIndexLeftChild(index); //return left child
		}
	}
}

void PrintAll(Heap* THeap)
{
	for (int i = 1; i < THeap->NumofData + 1; i++) printf("%d : %c\n", i, THeap->arr[i]);
}







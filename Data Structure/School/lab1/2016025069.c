#include <stdio.h>
#include <stdlib.h>

void Bubblesort(int* list, int size);
void Swap(int* pre, int* nxt);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error - not enough argument\n");
		for (int i = 0; i < argc; i++) printf("%d Argument name : %s\n", i + 1, argv[i]);
		return 1;
	}
	
	char* file_title = argv[1];
	FILE* fin = fopen(file_title, "r");
	
	int number = 0;
	int size = 10;
	int* list = (int*)malloc(sizeof(int) * size);
	printf("Input Data : \n");
	for (int i = 0; fscanf(fin,"%d",&number) != EOF; i++)
	{
		list[i] = number;
		printf("%d ",number);
	}
	printf("\n");
	fclose(fin);

	Bubblesort(list, size);

	FILE* fout = fopen("OutputData.txt", "w");
	printf("Output Data : \n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", list[i]);
		fprintf(fout, "%d ", list[i]);
	}
	printf("\n");
	fclose(fout);
	free(list);

	return 0;
}

void Bubblesort(int* list, int size)
{
	for (int loop = 1; loop < size; loop++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (list[i] > list[i + 1]) Swap(&list[i], &list[i + 1]);
		}
	}
}

void Swap(int* pre, int* nxt)
{
	int temp = *pre;
	*pre = *nxt;
	*nxt = temp;
}

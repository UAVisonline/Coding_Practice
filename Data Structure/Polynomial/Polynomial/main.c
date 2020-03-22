#include <stdio.h>
#include <string.h>

typedef struct {
	int coef;
	int expo;
}polynomial;

void be_polynomia(polynomial* poly, char* str);
void print_polynomial(polynomial* poly,int size);
int get_size(char* str);

int main()
{
	char str[100];
	polynomial* test;

	printf("다항식으로 바꿀 문자를 입력하세요.(변수값은 x만 허용됩니다. -계수는 인식하지 못합니다.)\n");
	gets(str);
	int size = get_size(str);
	test = (polynomial*)malloc(size * sizeof(polynomial));
	for (int i = 0; i < size; i++)
	{
		test[i].expo = 0;
		test[i].coef = 0;
	}
	be_polynomia(test, str);
	print_polynomial(test, size);

	free(test);
	return 0;
}

void be_polynomia(polynomial* poly, char* str)
{
	int pos = 0, sign = 1,cox = 0, num = 0; 
	if (str[0] == '-') sign = -1;
	for (int i = 0; i < strlen(str); i++)
	{
		//printf("%d\n", i);
		if (i != 0)
		{
			if (str[i] == '+' || str[i] == '-')
			{
				if (poly[pos].coef == 0)
				{
					poly[pos].coef = sign*num;
					poly[pos].expo = 0;
				}
				//printf("%d  %d   \n", poly[pos].coef, poly[pos].expo);
				pos++;
				num = 0;
				if (str[i] == '+') sign = 1;
				else if (str[i] == '-') sign = -1;
				i++;
			}
		}
		if (str[i] == 'x')
		{
			poly[pos].coef = sign*num;
			cox = 0;
			while (i<strlen(str))
			{
				if (str[i + 1] == '+' || str[i + 1] == '-' || i+1==strlen(str)) break;
				else if (str[i + 1] != '^')
				{
					cox = cox * 10 + (int)(str[i+1] - '0');
				}
				i++;
			}
			poly[pos].expo = cox;
			//printf("%d\n", cox);
			//printf("%d  %d   \n", sign*num, cox);
		}
		else if(str[i]!='+'&&str[i]!='-')
		{
			num = (str[i] - '0') + num * 10;
			if (i == strlen(str)-1)
			{
				poly[pos].coef = sign*num;
				poly[pos].expo = 0;
			}
		}
	}
}

void print_polynomial(polynomial* poly,int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d", poly[i].coef);
		if (poly[i].expo != 0) printf("x^%d", poly[i].expo);
		if (i != size - 1)
		{
			if (poly[i+1].coef > 0) printf("+");
		}
	}
}

int get_size(char* str)
{
	int size = 1;
	if (str[0] == '-') size -= 1;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '-' || str[i] == '+') size += 1;
	}
	return size;
}

// Data Structure Subject Practice example 1 : Recursive algorithm
// C->C++
#include <iostream>
#include <algorithm>

using namespace std;

void perm(char* list, int i, int j)
{
	if (i == j)
	{
		for (int k = 0; k <= j; k++) cout << list[k];
		cout << endl;
	}
	else
	{
		for (int k = i; k <= j; k++)
		{
			swap(list[i], list[k]);
			perm(list, i + 1, j);
			swap(list[i], list[k]);
		}
	}
}

int main()
{
	cout << "char배열의 크기를 선언하시오." << endl;
	int size;
	cin >> size;
	char* list = new char[size];
	cout << "char배열의 값을 차례대로 입력하시오." << endl;
	for (int i = 0; i < size; i++)
	{
		char text;
		cin >> text;
		list[i] = text;
	}
	perm(list, 0, size - 1);
	return 0;
}
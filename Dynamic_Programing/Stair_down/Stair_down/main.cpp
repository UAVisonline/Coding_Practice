#include <iostream>

using namespace std;

/*
	N�� ������ ����� �־����� ����� �������µ��� ���� 1���� 1ĭ�̳� 2ĭ���� ������ �� �ִ�.
	�� ����� ���� ����� ������ �� �� ��� ����� ���� ����� ������ �� �ִ��� ���Ͻÿ�.
	ex) 2ĭ -> 2��(1+1,2),3ĭ ->3��(1+1+1,1+2,2+1), 4ĭ -> 5��(1+1+1+1,1+1+2,1+2+1,2+1+1,2+2), 5ĭ->8��(1+1+1+1+1,1+1+1+2,1+1+2+1,1+2+1+1,2+1+1+1,1+2+2,2+1+2,2+2+1)
*/

int main()
{
	int stair_num;
	cin >> stair_num;
	int* number_case = new int[stair_num];
	for (int i = 0; i < stair_num;i++)
	{
		if (i == 0)
		{
			number_case[i] = 1;
		}
		else if (i == 1)
		{
			number_case[i] = 2;
		}
		else
		{
			number_case[i] = number_case[i - 1] + number_case[i - 2];//fibonacci number?(ó���� 2ĭ�̸� ���� ���� �� [i-2]���� �ǰ�, ó���� 1ĭ�̸� ���� ���� �� [i-1]���� �ȴ�.)
		}
	}
	cout << number_case[stair_num - 1];
	delete[] number_case;
	return 0;
}
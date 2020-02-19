#include <iostream>

using namespace std;

/*
	N개 높이의 계단이 주어지며 계단을 내려가는데는 오직 1번에 1칸이나 2칸씩만 내려갈 수 있다.
	이 방법에 따라서 계단을 내려갈 때 총 몇가지 경우의 수로 계단을 내려갈 수 있는지 구하시오.
	ex) 2칸 -> 2개(1+1,2),3칸 ->3개(1+1+1,1+2,2+1), 4칸 -> 5개(1+1+1+1,1+1+2,1+2+1,2+1+1,2+2), 5칸->8개(1+1+1+1+1,1+1+1+2,1+1+2+1,1+2+1+1,2+1+1+1,1+2+2,2+1+2,2+2+1)
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
			number_case[i] = number_case[i - 1] + number_case[i - 2];//fibonacci number?(처음이 2칸이면 다음 경우는 총 [i-2]개가 되고, 처음이 1칸이면 다음 경우는 총 [i-1]개가 된다.)
		}
	}
	cout << number_case[stair_num - 1];
	delete[] number_case;
	return 0;
}
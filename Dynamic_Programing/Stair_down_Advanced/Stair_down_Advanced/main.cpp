#include <iostream>
/*
	계단 오르는 데는 다음과 같은 규칙이 있다.
	계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
	연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
	마지막 도착 계단은 반드시 밟아야 한다.
	따라서 첫 번째 계단을 밟고 이어 두 번째 계단이나, 세 번째 계단으로 오를 수 있다. 하지만, 첫 번째 계단을 밟고 이어 네 번째 계단으로 올라가거나, 첫 번째, 두 번째, 세 번째 계단을 연속해서 모두 밟을 수는 없다.
	각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오.

	방법) 2칸[1+1,2]->2가지, 3칸[1+2,2+1]->2가지, 4칸[1+1+2,1+2+1,2+2]->3가지, 5칸[2+2+1,2+1+2,1+2+2,1+1+2+1]->4가지, 6칸[1+1+2+2,1+2+1+2,2+2+2,2+1+2+1,1+2+2+1]->5가지
*/

using namespace std;

int main()
{
	int stair_num;
	cin >> stair_num;
	int* max_score = new int[stair_num];
	int* double_score = new int[stair_num];
	for (int i = 0; i < stair_num; i++)
	{
		int score;
		cin >> score;
		if (i == 0) max_score[i] = score;//1stair
		else if (i == 1)//2stair
		{
			max_score[i] = score;//2
			double_score[i] = score + max_score[i - 1];// 1 1
		}
		else if (i == 2)//3stair
		{
			max_score[i] = max_score[i - 2] + score;// 1 2
			double_score[i] = score + max_score[i - 1];// 2 1
		}
		else if (i >= 3)//4stair
		{
			if (double_score[i - 2] > max_score[i - 2]) max_score[i] = double_score[i - 2] + score;// 1 1 2
			else max_score[i] = max_score[i - 2] + score;// 2 2
			double_score[i] = max_score[i-1] + score;//1 2 1 
		}
	}
	if (double_score[stair_num - 1] > max_score[stair_num - 1]) cout << double_score[stair_num - 1];
	else cout << max_score[stair_num - 1];

	return 0;
}
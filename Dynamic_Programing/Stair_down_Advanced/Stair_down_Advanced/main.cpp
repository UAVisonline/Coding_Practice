#include <iostream>
/*
	��� ������ ���� ������ ���� ��Ģ�� �ִ�.
	����� �� ���� �� ��ܾ� �Ǵ� �� ��ܾ� ���� �� �ִ�. ��, �� ����� �����鼭 �̾ ���� ����̳�, ���� ���� ������� ���� �� �ִ�.
	���ӵ� �� ���� ����� ��� ��Ƽ��� �� �ȴ�. ��, �������� ��ܿ� ���Ե��� �ʴ´�.
	������ ���� ����� �ݵ�� ��ƾ� �Ѵ�.
	���� ù ��° ����� ��� �̾� �� ��° ����̳�, �� ��° ������� ���� �� �ִ�. ������, ù ��° ����� ��� �̾� �� ��° ������� �ö󰡰ų�, ù ��°, �� ��°, �� ��° ����� �����ؼ� ��� ���� ���� ����.
	�� ��ܿ� ���� �ִ� ������ �־��� �� �� ���ӿ��� ���� �� �ִ� �� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	���) 2ĭ[1+1,2]->2����, 3ĭ[1+2,2+1]->2����, 4ĭ[1+1+2,1+2+1,2+2]->3����, 5ĭ[2+2+1,2+1+2,1+2+2,1+1+2+1]->4����, 6ĭ[1+1+2+2,1+2+1+2,2+2+2,2+1+2+1,1+2+2+1]->5����
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
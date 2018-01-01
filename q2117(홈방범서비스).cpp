#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
int max_result = 1;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int N = 0, M = 0;//������ ũ�� N (5 �� N �� 20)//�ϳ��� ���� ������ �� �ִ� ��� M (1 �� M �� 10)
int maps[21][21] = {};
//������ �߸����...!
void make_rhombus(int x, int y)//x,y�� �߽��ΰ��
{
	for (int num = 2; num <= 21; num++)//num�ٲٱ�
	{
		int home = 0;
		int cnt = 0;

		for (int i = x - num + 1; i <= x; i++)//���� �κ�
		{
			if (num <= cnt)
				break;

			if (i < 0)
			{
				cnt++;
				continue;
			}

			for (int j = y - cnt; j <= y + cnt; j++)
			{
				if (j < 0 || j >= N)
					continue;

				home += maps[i][j];
			}
			cnt++;
		}//for i 

		cnt = 0;
		for (int i = x + num - 1; i > x; i--)//�ؿ� �κ�
		{
			if (num <= cnt)
				break;
			if (i >= N)
			{
				cnt++;
				continue;
			}
			for (int j = y - cnt; j <= y + cnt; j++)
			{
				if (j < 0 || j >= N)
					continue;
				home += maps[i][j];
			}
			cnt++;
		}
		///////////////////////////////////////////////////
		int num_result = (num*num) + (num - 1)*(num - 1);
		if (((home*M) - num_result) >= 0)
		{
			if (max_result < home)
				max_result = home;
		}
	}//for num

}
int main()
{
	int T = 0;
	cin >> T;

	for (int t_c = 1; t_c <= T; t_c++)
	{
		max_result = 1;
		memset(maps, 0, sizeof(maps));
		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cin >> maps[i][j];
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				make_rhombus(i, j);
		}

		cout << "#" << t_c << " " << max_result << endl;
	}
	return 0;
}
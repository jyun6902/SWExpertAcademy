#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
using namespace std;
//초기화 잘하기
deque <int> d[5], d_copy[5];
bool visit[5] = {};
void rotate(int who, int clockwise)
{
	visit[who] = 1;
	if (clockwise == 1)//시계
	{
		int k = d[who].back();
		d[who].pop_back();
		d[who].push_front(k);
	}

	else //반시계
	{
		int k = d[who].front();
		d[who].pop_front();
		d[who].push_back(k);
	}
}

void check(int who, int dir)
{
	if (who == 1)
	{
		if (d_copy[1][2] != d_copy[2][6] && visit[2] == 0)
		{
			rotate(2, -dir);
			check(2, -dir);
		}
	}

	else if (who == 2)
	{
		if (d_copy[2][2] != d_copy[3][6] && visit[3] == 0)
		{
			rotate(3, -dir);
			check(3, -dir);
		}

		if (d_copy[2][6] != d_copy[1][2] && visit[1] == 0)
		{
			rotate(1, -dir);
			check(1, -dir);
		}

	}

	else if (who == 3)
	{
		if (d_copy[3][2] != d_copy[4][6] && visit[4] == 0)
		{
			rotate(4, -dir);
			check(4, -dir);
		}

		if (d_copy[3][6] != d_copy[2][2] && visit[2] == 0)
		{
			rotate(2, -dir);
			check(2, -dir);
		}

	}

	else if (who == 4 && visit[3] == 0)
	{
		if (d_copy[3][2] != d_copy[4][6] && visit[3] == 0)
		{
			rotate(3, -dir);
			check(3, -dir);
		}
	}
	return;
}

int main()
{
	int T = 0;
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int K = 0, result = 0;
		int t = 0, who = 0, dir = 0;
		scanf("%d", &K);

		for (int i = 1; i <= 4; i++)
		{//initialize
			visit[i] = 0;
			d[i].clear();
			d_copy[i].clear();
		}

		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> t;
				d[i].push_back(t);
			}
			d_copy[i] = d[i];
		}

		for (int i = 0; i < K; i++)
		{
			cin >> who >> dir;

			rotate(who, dir);
			check(who, dir);
			for (int j = 1; j <= 4; j++)
			{
				d_copy[j] = d[j];
				visit[j] = 0;
			}
		}

		for (int i = 1; i <= 4; i++)
		{
			if (d[i][0] == 1)
				result += pow(2, i - 1);
		}
		printf("#%d %d\n", t_c, result);
	}
	return 0;
}
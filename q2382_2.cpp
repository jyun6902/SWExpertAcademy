#include <iostream>
#include <vector>
#include <cstdio>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int T = 0;
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int N, M, K = 0;//N��, M=�ݸ��ð� K=�̻��� ����
		int maps[104][104] = {};
		deque <  pair < pair <pair <int, int>, pair<int, int> >, int > > dq;//�̻��� ��, �̵�����, ����, ����
		vector <  pair < pair <pair <int, int>, pair<int, int> >, int > > v[1001];
		scanf("%d %d %d", &N, &M, &K);

		for (int i = 0; i < K; i++)
		{
			int x, y, num, dir;//��:1 ��:2 ��:3  ��:4
			scanf("%d %d %d %d", &x, &y, &num, &dir);
			dq.push_back({ { { num, dir },{ x,y } },i });
		}

		for (int t = 0; t < M; t++)
		{
			sort(dq.begin(), dq.end());
			memset(maps, -1, sizeof(maps));

			while (!dq.empty())
			{
				int num = dq.back().first.first.first;
				int dir = dq.back().first.first.second;
				int x = dq.back().first.second.first;
				int y = dq.back().first.second.second;
				int who = dq.back().second;
				dq.pop_back();

				if (dir == 1)//��
				{
					x -= 1;//x-=1
					if (x == 0)
					{
						num /= 2;
						dir = 2;
						if (num == 0)
							continue;
					}

					if (maps[x][y] != -1) //�̹��ִ� ���
					{
						v[maps[x][y]].back().first.first.first += num;
						continue;
					}
					v[who].push_back({ { { num, dir },{ x,y } },who });
					maps[x][y] = who;
				}

				else if (dir == 2)//��
				{
					x += 1;
					if (x == N - 1)
					{
						num /= 2;
						dir = 1;
						if (num == 0)
							continue;

					}

					if (maps[x][y] != -1) //�̹��ִ� ���
					{
						v[maps[x][y]].back().first.first.first += num;
						continue;
					}
					v[who].push_back({ { { num, dir },{ x,y } },who });
					maps[x][y] = who;
				}

				else if (dir == 3)//��
				{
					y -= 1;
					if (y == 0)
					{
						num /= 2;
						dir = 4;
						if (num == 0)
							continue;
					}

					if (maps[x][y] != -1) //�̹��ִ� ���
					{
						v[maps[x][y]].back().first.first.first += num;
						continue;
					}
					v[who].push_back({ { { num, dir },{ x,y } },who });
					maps[x][y] = who;
				}

				else if (dir == 4)//��
				{
					y += 1;
					if (y == N - 1)
					{
						num /= 2;
						dir = 3;
						if (num == 0)
							continue;
					}

					if (maps[x][y] != -1) //�̹��ִ� ���
					{
						v[maps[x][y]].back().first.first.first += num;
						continue;
					}
					v[who].push_back({ { { num, dir },{ x,y } },who });
					maps[x][y] = who;
				}

			}

			for (int p = 0; p < K; p++)
			{
				if (v[p].size() != 0)
				{
					int num = v[p].back().first.first.first;
					int dir = v[p].back().first.first.second;
					int x = v[p].back().first.second.first;
					int y = v[p].back().first.second.second;
					int who = v[p].back().second;
					dq.push_back({ { { num, dir },{ x,y } },who });
					v[p].clear();
				}
			}
		}
		int result = 0;
		while (!dq.empty())
		{
			int num = dq.back().first.first.first;
			dq.pop_back();
			result += num;
		}
		cout << "#" << t_c << " " << result << endl;
	}

	return 0;
}
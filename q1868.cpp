#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <deque>
using namespace std;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1 , 0 ,1, -1, 1, -1, 0, 1 };
int maps_cp[305][305] = {};
//maps_cp : 9 =지뢰인 경우
//maps_cp : -1= '.'
int main()
{
	int T = 0;
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int N = 0, result = 0;
		bool visit[305][305] = {};
		char maps[305][305] = {};
		memset(maps, 0, sizeof(maps));
		memset(maps_cp, -1, sizeof(maps_cp));

		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			string s = "";
			cin >> s;
			for (int j = 1; j <= N; j++)
				maps[i][j] = s[j - 1];
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (maps[i][j] == '*')
					maps_cp[i][j] = 9;
			}
		}

		deque <pair <int, int >> dq;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				int cnt = 0;
				if (maps_cp[i][j] == -1)
				{
					for (int k = 0; k < 8; k++)
					{
						if (maps_cp[i + dx[k]][j + dy[k]] != 9)
							cnt++;
						else
							break;
					}

					if (cnt == 8)//0일경우
					{
						result++;
						maps_cp[i][j] = 0;
						for (int k = 0; k < 8; k++)
						{
							if (maps_cp[i + dx[k]][j + dy[k]] != 9 && i + dx[k] > 0 && i + dx[k] <= N && j + dy[k] > 0 && j + dy[k] <= N)
							{
								visit[i + dx[k]][j + dy[k]] = 1;
								dq.push_back({ i + dx[k],j + dy[k] });
							}
						}

						while (!dq.empty())// 0주변 것들 넣기
						{
							int dq_size = dq.size();
							for (int t = 0; t < dq_size; t++)
							{
								int x = dq.front().first;
								int y = dq.front().second;
								dq.pop_front();
								int star = 0;
								for (int p = 0; p < 8; p++)
								{
									int nx = x + dx[p];
									int ny = y + dy[p];

									if (maps_cp[nx][ny] == 9)
										star++;
								}
								maps_cp[x][y] = star;
								if (star == 0)
								{
									for (int k = 0; k < 8; k++)
									{//
										if (visit[x + dx[k]][y + dy[k]] == 0 && maps_cp[x + dx[k]][y + dy[k]] == -1
											&& x + dx[k] > 0 && x + dx[k] <= N && y + dy[k] > 0 && y + dy[k] <= N)
										{
											dq.push_back({ x + dx[k],y + dy[k] });
											visit[x + dx[k]][y + dy[k]] = 1;
										}
									}
								}
							}//for
						}//while dq.empty
					}
				}//if maps_cp == -1
			}
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (maps_cp[i][j] == -1)
					result++;
			}
		}
		printf("#%d %d\n", t_c, result);
	}

	return 0;
}
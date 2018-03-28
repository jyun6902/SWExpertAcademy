#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int maps[22][22];
int visit[22][22];
int N = 0, X = 0; //(6 ≤ N ≤ 20) // ( 2 ≤ X ≤ 4 )
int result = 0;
void cal_wide(int x)
{
	int flag = 0;
	for (int i = 1; i < N; i++)
	{
		if (abs(maps[x][i] - maps[x][i + 1]) > 1)
		{
			flag = 1;
			break;
		}
		else if (maps[x][i] == maps[x][i + 1])
			continue;

		else if (maps[x][i] < maps[x][i + 1])
		{
			int cnt = 0, j = 0;
			for (j = i; j > 1; j--)
			{
				if (visit[x][j] == 1 ||visit[x][j-1] ==1 || maps[x][j] != maps[x][j - 1])
					break;

				else if (maps[x][j] == maps[x][j - 1] && visit[x][j] == 0 && visit[x][j-1]== 0)
				{
					visit[x][j] = 1;
					cnt++;
				}
				
				if (cnt >= X - 1)
				{
					visit[x][j - 1] = 1;
					break;
				}
			}
			if (cnt < X - 1)
			{
				flag = 1;
				break;
			}
		}

		else if (maps[x][i] > maps[x][i + 1])
		{
			int cnt = 0, j = 0;
			for (j = i + 1; j < N; j++)
			{
				if ( visit[x][j] == 1 ||visit[x][j+1] == 1||  maps[x][j] != maps[x][j+1])
					break;
				
				else if (maps[x][j] == maps[x][j + 1] && visit[x][j] == 0 && visit[x][j+1] == 0)
				{
					visit[x][j] = 1;
					cnt++;
				}
				 
				if (cnt >= X - 1)
				{
					visit[x][j + 1] = 1;
					break;
				}
			}
			if (cnt < X - 1)
			{
				flag = 1;
				break;
			}
			i = j;
		}

		if (flag == 1)
			break;
	}
	if (flag == 0)
		result++;
}


void cal_height(int y)
{
	int flag = 0;
	for (int i = 1; i < N; i++)
	{
		if (abs(maps[i][y] - maps[i + 1][y]) > 1)
		{
			flag = 1;
			break;
		}
		else if (maps[i][y] == maps[i + 1][y])
			continue;

		else if (maps[i][y] < maps[i + 1][y])
		{
			int cnt = 0, j = 0;
			for (j = i; j > 1; j--)
			{
				if (visit[j][y] == 1 || visit[j-1][y] == 1|| maps[j][y] != maps[j-1][y])
					break;

				else if (maps[j][y] == maps[j - 1][y] && visit[j][y] == 0 && visit[j-1][y] == 0)
				{
					visit[j][y] = 1;
					cnt++;
				}

				if (cnt >= X - 1)
				{
					if (maps[j][y] == maps[j - 1][y])
					visit[j - 1][y] = 1;
					break;
				}
			}
			if (cnt < X - 1)
			{
				flag = 1;
				break;
			}
		}

		else if (maps[i][y] > maps[i + 1][y])
		{
			int cnt = 0, j = 0;
			for (j = i + 1; j < N; j++)
			{
				if (maps[j][y] != maps[j + 1][y] || visit[j][y] == 1 || visit[j+1][y] == 1)
					break;

				else if (maps[j][y] == maps[j + 1][y] && visit[j][y] == 0 && visit[j][y+1]== 0)
				{
					visit[j][y] = 1;
					cnt++;
				}

				if (cnt >= X - 1)
				{
					if ( maps[j][y] == maps[j+1][y])
					visit[j+1][y] = 1;
					break;
				}
			}
			if (cnt < X - 1)
			{
				flag = 1;
				break;
			}
			i = j;
		}

		if (flag == 1)
			break;
	}
	if (flag == 0)
		result++;
}

int main()
{
	int T = 1;
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		memset(maps, 0, sizeof(maps));
		memset(visit, 0, sizeof(visit));
		result = 0;
		scanf("%d %d", &N, &X);

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				scanf("%d", &maps[i][j]);
		}

		for (int i = 1; i <= N; i++)
			cal_wide(i);

		memset(visit, 0, sizeof(visit));
		for (int j = 1; j <= N; j++)
			cal_height(j);

		printf("#%d %d\n", t_c, result);
	}

	return 0;
}

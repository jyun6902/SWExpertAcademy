#include <iostream>
#include <cstring>
using namespace std;

int maps[10][10] = {};
int visit[10][10] = {};
int N, K = 0;//N=지도 한변의 길이 K=최대 공사 가능 깊이
int max_result = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 , 0 };
void dfs(int x, int y, int check, int cnt)
{
	if (max_result < cnt)
	{
		max_result = cnt;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || nx > N || ny < 1 || ny > N || visit[nx][ny] == 1)
			continue;

		//if ((check == 1 && maps[nx][ny] >= maps[x][y]) || (check == 0 && maps[nx][ny] >= maps[x][y] && maps[nx][ny]-K >= maps[x][y]))
		//  return;

		if (maps[nx][ny] < maps[x][y])
		{
			visit[nx][ny] = 1;
			dfs(nx, ny, check, cnt + 1);
			visit[nx][ny] = 0;
		}

		if (check == 0 && maps[nx][ny] >= maps[x][y] && maps[nx][ny] - K < maps[x][y])
		{
			visit[nx][ny] = 1;
			int temp = maps[nx][ny];
			maps[nx][ny] = maps[x][y] - 1;
			check = 1;
			dfs(nx, ny, check, cnt + 1);
			check = 0;
			maps[nx][ny] = temp;
			visit[nx][ny] = 0;
		}
	}
}

int main()
{
	int T = 0;
	cin >> T;
	for (int t_c = 1; t_c <= T; t_c++)
	{
		cin >> N >> K;
		max_result = 0;
		memset(maps, 0, sizeof(maps));
		int max_len = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> maps[i][j];
				if (max_len < maps[i][j])
					max_len = maps[i][j];
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (max_len == maps[i][j])
				{
					memset(visit, 0, sizeof(visit));
					visit[i][j] = 1;
					dfs(i, j, 0, 1);
					visit[i][j] = 0;
				}
			}
		}

		cout << "#" << t_c << " " << max_result << endl;
	}
	return -0;
}

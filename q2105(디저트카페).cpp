#include <iostream>
#include <cstring>
using namespace std;
int maps[21][21] = {};
bool check[101] = {};//갔던 숫자인지 판별
bool visit[21][21] = {};
int start_x = 0, start_y = 0;
int N = 0, answer = -1;// (4 ≤ N ≤ 20)
int dx[4] = { -1, -1, 1, 1 };
int dy[4] = { -1, 1, 1, -1 };
int max_2(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}

void dfs(int x, int y, int change, int cnt, int dir)
{
	if (change > 3)
		return;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || nx > N || ny < 1 || ny > N || visit[nx][ny] == 1)
			continue;

		if (change > 2 && nx == start_x && ny == start_y)
		{
			if (answer < cnt)
				answer = cnt;
			return;
		}

		if (check[maps[nx][ny]] == 1)
			continue;

		check[maps[nx][ny]] = 1;
		visit[nx][ny] = 1;
		if (i != dir)
			dfs(nx, ny, change + 1, cnt + 1, i);

		else
			dfs(nx, ny, change, cnt + 1, i);
		check[maps[nx][ny]] = 0;
		visit[nx][ny] = 0;
	}//for
}
int main()
{
	int T = 0;
	cin >> T;
	for (int t_c = 1; t_c <= T; t_c++)
	{
		answer = -1;
		memset(maps, 0, sizeof(maps));
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				cin >> maps[i][j];
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				start_x = i;
				start_y = j;
				memset(check, 0, sizeof(check));
				memset(visit, 0, sizeof(visit));
				check[maps[i][j]] = 1;
				dfs(i, j, 0, 1, 0);
				check[maps[i][j]] = 0;
			}
		}

		cout << "#" << t_c << " " << answer << endl;
	}
	return 0;
}
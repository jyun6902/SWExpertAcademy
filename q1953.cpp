#include <iostream>
#include <deque>
using namespace std;

bool cal(int x, int y, int dir, int maps[52][52])
{
	if (dir == 1)//µ¿
	{
		if (maps[x][y + 1] == 1 || maps[x][y + 1] == 3 || maps[x][y + 1] == 6 || maps[x][y + 1] == 7)
			return true;
		else
			return false;
	}

	else if (dir == 2)//¼­
	{
		if (maps[x][y - 1] == 1 || maps[x][y - 1] == 3 || maps[x][y - 1] == 4 || maps[x][y - 1] == 5)
			return true;
		else
			return false;
	}

	else if (dir == 3)//³²
	{
		if (maps[x + 1][y] == 1 || maps[x + 1][y] == 2 || maps[x + 1][y] == 4 || maps[x + 1][y] == 7)
			return true;
		else
			return false;
	}

	else if (dir == 4)//ºÏ
	{
		if (maps[x - 1][y] == 1 || maps[x - 1][y] == 2 || maps[x - 1][y] == 5 || maps[x - 1][y] == 6)
			return true;
		else
			return false;
	}
}
int main()
{
	int T = 0;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N = 0, M = 0;//N=¼¼·Î M=°¡·Î 5 ¡Â N, M ¡Â 50
		int R = 0, C = 0;//¸ÇÈ¦ ¶Ñ²± R=¼¼·Î C= °¡·Î 0 ¡Â R ¡Â N-1, 0 ¡Â C ¡Â M-1
		int L = 0;		 //Å»Ãâ ÈÄ ¼Ò¿äµÈ ½Ã°£ 1 ¡Â L ¡Â 20
		int maps[52][52] = {};
		bool check[52][52] = {};
		int result = 0, cnt = 1;
		deque<pair <int, int> > dq;

		cin >> N >> M >> R >> C >> L;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				cin >> maps[i][j];
		}
		//	dq.push_back({ R, C });
		dq.push_back(make_pair(R, C));
		while (!dq.empty())
		{
			int dq_size = dq.size();
			for (int t = 0; t < dq_size; t++)
			{
				int x = dq.front().first;
				int y = dq.front().second;
				dq.pop_front();
				check[x][y] = 1;

				if (x < 0 || x >= N || y < 0 || y >= M)
					continue;

				if (maps[x][y] == 1)
				{
					if (cal(x, y, 1, maps) && check[x][y + 1] == 0)
						//	dq.push_back({ x,y + 1 });
						dq.push_back(make_pair(x, y + 1));
					if (cal(x, y, 2, maps) && check[x][y - 1] == 0)
						//dq.push_back({ x,y - 1 });
						dq.push_back(make_pair(x, y - 1));
					if (cal(x, y, 4, maps) && check[x - 1][y] == 0)
						//dq.push_back({ x - 1,y });
						dq.push_back(make_pair(x - 1, y));
					if (cal(x, y, 3, maps) && check[x + 1][y] == 0)
						//dq.push_back({ x + 1,y });
						dq.push_back(make_pair(x + 1, y));
				}

				else if (maps[x][y] == 2)
				{
					if (cal(x, y, 4, maps) && check[x - 1][y] == 0)
						//	dq.push_back({ x - 1,y });
						dq.push_back(make_pair(x - 1, y));
					if (cal(x, y, 3, maps) && check[x + 1][y] == 0)
						//dq.push_back({ x + 1,y });
						dq.push_back(make_pair(x + 1, y));
				}

				else if (maps[x][y] == 3)
				{
					if (cal(x, y, 2, maps) && check[x][y - 1] == 0)
						//	dq.push_back({ x ,y- 1 });
						dq.push_back(make_pair(x, y - 1));
					if (cal(x, y, 1, maps) && check[x][y + 1] == 0)
						//	dq.push_back({ x ,y+ 1 });
						dq.push_back(make_pair(x, y + 1));
				}

				else if (maps[x][y] == 4)
				{
					if (cal(x, y, 4, maps) && check[x - 1][y] == 0)
						//dq.push_back({ x - 1,y });
						dq.push_back(make_pair(x - 1, y));
					if (cal(x, y, 1, maps) && check[x][y + 1] == 0)
						//	dq.push_back({ x ,y + 1 });
						dq.push_back(make_pair(x, y + 1));
				}

				else if (maps[x][y] == 5)
				{
					if (cal(x, y, 3, maps) && check[x + 1][y] == 0)
						//	dq.push_back({ x + 1,y });
						dq.push_back(make_pair(x + 1, y));
					if (cal(x, y, 1, maps) && check[x][y + 1] == 0)
						//dq.push_back({ x ,y + 1 });
						dq.push_back(make_pair(x, y + 1));
				}

				else if (maps[x][y] == 6)
				{
					if (cal(x, y, 3, maps) && check[x + 1][y] == 0)
						//dq.push_back({ x + 1,y });
						dq.push_back(make_pair(x + 1, y));

					if (cal(x, y, 2, maps) && check[x][y - 1] == 0)
						//dq.push_back({x ,y - 1 });
						dq.push_back(make_pair(x, y - 1));
				}

				else if (maps[x][y] == 7)
				{
					if (cal(x, y, 4, maps) && check[x - 1][y] == 0)
						//dq.push_back({ x- 1,y });
						dq.push_back(make_pair(x - 1, y));
					if (cal(x, y, 2, maps) && check[x][y - 1] == 0)
						//dq.push_back({ x ,y - 1 });
						dq.push_back(make_pair(x, y - 1));
				}

			}
			cnt++;
			if (cnt == L + 1)
				break;

		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				if (check[i][j] == 1)
					result++;
		}

		cout << "#" << test_case << " " << result << endl;
	}//for test_Case
	return 0;
}
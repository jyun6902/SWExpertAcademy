#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int N, K;
int result = 0;

int dfs(int x, int y, int check, int cnt, int arr[10][10], int maps[10][10])//공사했을 경우
{
	if (maps[x - 1][y] < maps[x][y] && arr[x - 1][y] == 0)
	{
		arr[x - 1][y] = 1;
		dfs(x - 1, y, check, cnt + 1, arr, maps);
		arr[x - 1][y] = 0;
	}
	if (maps[x + 1][y] < maps[x][y] && arr[x + 1][y] == 0)
	{
		arr[x + 1][y] = 1;
		dfs(x + 1, y, check, cnt + 1, arr, maps);
		arr[x + 1][y] = 0;
	}
	if (maps[x][y - 1] < maps[x][y] && arr[x][y - 1] == 0)
	{
		arr[x][y - 1] = 1;
		dfs(x, y - 1, check, cnt + 1, arr, maps);
		arr[x][y - 1] = 0;
	}
	if (maps[x][y + 1] < maps[x][y] && arr[x][y + 1] == 0)
	{
		arr[x][y + 1] = 1;
		dfs(x, y + 1, check, cnt + 1, arr, maps);
		arr[x][y + 1] = 0;
	}
	//////////////////////////////////////////////////
	if (check == 0 && maps[x - 1][y] >= maps[x][y] && maps[x - 1][y] < maps[x][y] + K && arr[x - 1][y] == 0)
	{
		int temp = maps[x - 1][y];
		maps[x - 1][y] = maps[x][y] - 1;
		arr[x - 1][y] = 1;
		dfs(x - 1, y, 1, cnt + 1, arr, maps);
		maps[x - 1][y] = temp;
		arr[x - 1][y] = 0;
	}
	if (check == 0 && maps[x + 1][y] >= maps[x][y] && maps[x + 1][y] < maps[x][y] + K && arr[x + 1][y] == 0)
	{
		int temp = maps[x + 1][y];
		maps[x + 1][y] = maps[x][y] - 1;
		arr[x + 1][y] = 1;
		dfs(x + 1, y, 1, cnt + 1, arr, maps);
		maps[x + 1][y] = temp;
		arr[x + 1][y] = 0;
	}
	if (check == 0 && maps[x][y - 1] >= maps[x][y] && maps[x][y - 1] < maps[x][y] + K && arr[x][y - 1] == 0)
	{
		int temp = maps[x][y - 1];
		maps[x][y - 1] = maps[x][y] - 1;
		arr[x][y - 1] = 1;
		dfs(x, y - 1, 1, cnt + 1, arr, maps);
		maps[x][y - 1] = temp;
		arr[x][y - 1] = 0;
	}
	if (check == 0 && maps[x][y + 1] >= maps[x][y] && maps[x][y + 1] < maps[x][y] + K && arr[x][y + 1] == 0)
	{
		int temp = maps[x][y + 1];
		maps[x][y + 1] = maps[x][y] - 1;
		arr[x][y + 1] = 1;
		dfs(x, y + 1, 1, cnt + 1, arr, maps);
	//	maps[x][y + 1] = maps[x][y] - 1;
		maps[x][y + 1] = temp;
		arr[x][y + 1] = 0;
	}
	if (cnt > result)
	{
		result = cnt;
		return result; 
	}
	return result;
}

int main()
{
	int T = 0;//테스트 케이스 , 결과값
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		result = 0;
		int maps[10][10];
		int max_answer = 0;
		memset(maps, 3, sizeof(maps));

		cin >> N >> K;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> maps[i][j];
				if (max_answer < maps[i][j])
					max_answer = maps[i][j];
			}
		}
		
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (max_answer == maps[i][j])//가장 큰점을 기준으로 
				{
					int arr[10][10] = {};
					arr[i][j] = 1;
					dfs(i, j, 0, 1, arr, maps);// dfs(int x, int y, int check, int cnt, int arr[10][10], int maps[10][10])
					arr[i][j] = 0;
				}
			}
		}
		cout << "#" << test_case << " " << result << endl;

	}
	return 0;
}
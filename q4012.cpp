#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int maps[18][18] = {};
int main()
{
	int T = 0;
	scanf("%d", &T);

	vector <vector<int> > v[17];// (4 ≤ N ≤ 16)
	for (int k = 4; k <= 16; k += 2)//N/2인 것만 저장
	{
		for (int i = 0; i < (1 << k); i++)
		{
			vector <int> t;
			for (int j = 0; j < k; j++)
			{
				if (i&(1 << j))
					t.push_back(j + 1);
			}

			if (t.size() == (k / 2))
			v[k].push_back(t);
		}
	}

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int N = 0;
		int min_result = 987654321;
		int sum = 0, sum2 = 0;
		int check[18] = {};
		memset(maps, 0, sizeof(maps));
		scanf("%d", &N);

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				scanf("%d", &maps[i][j]);
		}


		int v_size = (v[N].size()) / 2;
		for (int i = 0; i < v_size; i++)
		{
			vector <int > t;
			memset(check, 0, sizeof(check));
			sum = 0, sum2 = 0;
			for (auto iter = v[N][i].begin(); iter != v[N][i].end(); iter++)
			{
				t.push_back(*iter);
				check[*iter] = 1;
			}

			for (auto iter = t.begin(); iter != t.end(); iter++)
			{
				for (auto iter2 = t.begin(); iter2 != t.end(); iter2++)
				{
					if (*iter == *iter2)
						continue;

					sum += maps[*iter][*iter2];
				}
			}

			vector <int> t2;
			for (int j = 1; j <= N; j++)
			{
				if (check[j] == 0)
					t2.push_back(j);
			}

			for (auto iter = t2.begin(); iter != t2.end(); iter++)
			{
				for (auto iter2 = t2.begin(); iter2 != t2.end(); iter2++)
				{
					if (*iter == *iter2)
						continue;

					sum2 += maps[*iter][*iter2];
				}
			}

			int result = abs(sum - sum2);
			if (result < min_result)
				min_result = result;

		}

		printf("#%d %d\n", t_c, min_result);
	}


	return 0;
}
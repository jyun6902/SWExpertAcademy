#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T = 0;
	int maps[12][12] = {};
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int maps[12][12] = {};
		int visit[12][12] = {};
		int N = 0, M, C, result = 0;
		scanf("%d %d %d", &N, &M, &C);

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				scanf("%d", &maps[i][j]);
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				int max_sum = 0;
				vector <int > v;
				for (int k = j; k <= N; k++)
				{
					visit[i][k] = 1;
					v.push_back(maps[i][k]);
					if (v.size() == M)
						break;
				}
				sort(v.begin(), v.end());

				do {
					int sum = 0, sum_square = 0;
					for (int p = 0; p < v.size(); p++)
					{
						if (sum + v[p] <= C)
						{
							sum += v[p];
							sum_square += (v[p] * v[p]);
						}
						else
							break;
					}

					if (sum_square > max_sum)
						max_sum = sum_square;
				} while (next_permutation(v.begin(), v.end()));

				for (int p = i; p <= N; p++)
				{
					for (int q = 1; q <= N; q++)
					{
						int max_sum2 = 0, flag = 0;
						if (visit[p][q] == 1)
							continue;

						vector <int > v2;
						for (int r = q; r <= N; r++)
						{
							if (visit[p][r] == 1)
							{
								flag = 1; 
								break;
							}
							v2.push_back(maps[p][r]);
							
							if (v2.size() == M)
								break;
						}
						if (flag == 1)
							continue;

						sort(v2.begin(), v2.end());

						do {
							int sum = 0, sum_square = 0;
							for (int s = 0; s < v2.size(); s++)
							{
								if (sum + v2[s] <= C)
								{
									sum += v2[s];
									sum_square += (v2[s] * v2[s]);
								}

								else
									break;
							}

							if (sum_square > max_sum2)
								max_sum2 = sum_square;
						} while (next_permutation(v2.begin(), v2.end()));

						if (max_sum2 + max_sum > result)
							result = max_sum2 + max_sum;
					}//for q
				}//for p

				memset(visit, 0, sizeof(visit));
			}//for j
		}//for i

		printf("#%d %d\n", t_c, result);
	}

	return 0;
}
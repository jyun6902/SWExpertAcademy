#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
	int T = 0;
	scanf("%d", &T);
	for (int t_c = 1; t_c <= T; t_c++)
	{
		int N, M = 0;
		int A[1001] = {}, B[1001] = {};
		map <int, int> m;
		scanf("%d %d", &N, &M);

		for (int i = 1; i <= N; i++)
			scanf("%d", &A[i]);

		for (int i = 1; i <= M; i++)
			scanf("%d", &B[i]);

		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (A[j] <= B[i])
				{
					m[j] += 1;
					break;
				}
			}
		}

		int result = 0, index_result =1;
		for (int i = 1; i <= N; i++)
		{
			if (m[i] > result)
			{
				result = m[i];
				index_result = i;
			}
		}
		printf("#%d %d\n", t_c, index_result);
	}

	return 0;
}
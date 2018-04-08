#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int weight[10];
bool visit[10];
int two[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
int factor[10] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
int sum = 0, N=0;
int result = 0;
void cal(int now, int left, int right)
{
	if (now == N )
	{
		result++;
		return;
	}

	if (left >= sum-left)
	{
		result += two[N - now] * factor[N - now];
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 1)
			continue;
		visit[i] = 1;
		cal(now + 1, left + weight[i], right);

		if ( left >= right+weight[i])
		cal(now + 1, left, right + weight[i]);
		visit[i] = 0;
	}

}

int main()
{
	int T = 0;
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		memset(weight, 0, sizeof(weight));
		for (int i = 0; i < 10; i++)
			visit[i] = 0;
		result = 0;
		sum = 0;
		scanf("%d", &N);

		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &weight[i]);
			sum += weight[i];
		}

		cal(0, 0, 0);
		printf("#%d %d\n", t_c, result);
	}

	return 0;
}
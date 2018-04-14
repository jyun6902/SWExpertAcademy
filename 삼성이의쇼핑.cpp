#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N = 0, M = 0;
int price[26] = {};
int satisfy[26] = {};
int max_result = 0;
int save = 0;
void cal(int now, int check, int price_sum, int satisfy_sum)
{
	if (price_sum > N)
		return;

	if (max_result < satisfy_sum)
	{
		max_result = satisfy_sum;
		save = check;
	}
	if (M+1 == now)
		return;

	cal(now + 1, check | ( 1<<now), price_sum + price[now], satisfy_sum + satisfy[now]);
	cal(now + 1, check, price_sum, satisfy_sum);

}

int main()
{
	int T = 0;
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		max_result = 0;
		save = 0;
		memset(price, 0, sizeof(price));
		memset(satisfy, 0, sizeof(satisfy));
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++)
			scanf("%d %d", &price[i], &satisfy[i]);

		cal(0, 0, 0, 0);
		printf("#%d ", t_c);
		for (int j = 0; j < M; j++)
		{
			if (save &(1 << j))
				printf("%d ", j);
		}

		printf("%d\n", max_result);
	}

	return 0;
}
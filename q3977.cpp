#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int check[1000001] = {};
int dp[1000001] = {};
//2=1^2+1^2 이므로 2도포함해야함
void getChe(int num)
{
	for (int i = 2; i <= num; i++)
		check[i] = 1;

	for (int i = 2; i <= sqrt(num); i++)
	{
		if (check[i] == 0)
			continue;

		for (int j = i * i; j <= num; j += i)
			check[j] = 0;
	}
}

int main()
{
	int T = 0;
	getChe(1000000);

	scanf("%d", &T);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= 1000000; i++)
	{
		if ((check[i] != 0) && ((i % 4) == 1) )
			dp[i] = 1;
		else
			dp[i] = 0;
	}

	for (int i = 1; i <= 1000000; i++)
		dp[i + 1] += dp[i];

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int L, R = 0;
		int result = 0;
		scanf("%d %d", &L, &R);
		result = dp[R] - dp[L - 1];
		if (L <= 2 && R >= 2)
			result++;
		printf("#%d %d\n", t_c, result);
	}

	return 0;
}
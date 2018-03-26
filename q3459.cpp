#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
//long long input¿∫ %lld
int main()
{
	int T = 0;
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		long long n = 0;
		int cnt = 0;
		scanf("%lld", &n);

		if (((long long)(log(n) / log(2))) % 2 == 0) // ∑π∫ß »¶ºˆ 
		{
			long long x = 1;
			cnt = 1;
			while (1)
			{
				if (x > n)
					break;

				if (cnt % 2 == 1)
					x = (2 * x) + 1;
				else
					x *= 2;
				cnt++;
			}
		}

		else
		{
			long long  x = 1;
			cnt = 1;
			while (1)
			{
				if (x > n)
					break;

				if (cnt % 2 == 1)
					x *= 2;
				else
					x = (2 * x) + 1;
				cnt++;
			}
		}

		printf("#%d ", t_c);
		printf((cnt % 2 == 1) ? "Alice\n" : "Bob\n");
	}

	return 0;
}
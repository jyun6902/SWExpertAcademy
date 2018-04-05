#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	int T = 0;
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int W, H, N = 0, a, b;
		long long sum = 0;
		scanf("%d %d %d", &W, &H, &N);

		scanf("%d %d", &a, &b);
		for (int i = 1; i < N; i++)
		{
			int c, d = 0;
			scanf("%d %d", &c, &d);

			if (a - c < 0 && b - d < 0)
			{
				if (abs(a - c) < abs(b - d))
				{
					sum += abs(a - c);
					b += abs(a - c);
					sum += abs(b - d);
				}
				else
				{
					sum += abs(b - d);
					a += abs(b - d);
					sum += abs(a - c);
				}
			}

			else if (a - c > 0 && b - d > 0)
			{
				if (abs(a - c) < abs(b - d))
				{
					sum += abs(a - c);
					b -= abs(a - c);
					sum += abs(b - d);
				}

				else
				{
					sum += abs(b - d);
					a -= abs(b - d);
					sum += abs(a - c);
				}
			}

			else //if (a - c < 0 && b - d >0)
			{
				sum += abs(a - c);
				sum += abs(b - d);
			}

			a = c;
			b = d;
		}

		printf("#%d %ld\n", t_c, sum);
	}
	return 0;
}
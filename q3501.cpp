#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int save[1000001] = {};
int remain[100001] = {};
//max (p) = 999990 -> save=10^6해줘야함
//p가 다시 나올때까지 while()하는게 point
int main()
{
	int T = 0;
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int  p, q = 0;
		int cnt = 0;
		bool check[1000001] = {};
		memset(remain, 0, sizeof(remain));
		memset(save, -1, sizeof(save));
		
		scanf("%d %d", &p, &q);
		if (p % q == 0)
		{
			printf("#%d %d\n", t_c, p / q);
			continue;
		}

		else
		{
			int gcd = 1;//great common divisor
			int value = 0;
			int k = 0;
			int len = 0;
			for (int i = 2; i <= p; i++)
			{
				if ((p / i == 0) && (q / i == 0))
					gcd = i;
			}

			p /= gcd;
			q /= gcd;
			if (p / q > 0)
			{
				value = p / q;
				p %= q;
			}
			p = p%q * 10;

			while (1)
			{
				if (save[p] == -1)
				save[p] = cnt;
				check[p] = 1;
				k = p / q;
				remain[cnt] = k;
				p = p%q * 10;
				cnt++;

				if (p == 0)
				{
					len = cnt;
					break;
				}
				
				if ( check[p] == 1)
				{
					len = save[p];
					break;
				}
			}

			cout << "#" << t_c << " " << value << ".";
			for (int i = 0; i < len; i++)
				cout << remain[i];

			if (len < cnt)
			{
				cout << "(";
				for (int i = len; i < cnt; i++)
					cout << remain[i];
				cout << ")" ;
			}
			cout << endl;

		}
	}
	return 0;
}

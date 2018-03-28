#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
//cout대신 printf 시간초과해결
int sum = 0;
int main()
{
	int T = 0;
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		char s[18];
		scanf("%s", &s);
		sum = 0;

		while (1)
		{
			sum = 0;
			for (int t = 0; t < strlen(s); t++)
				sum += (((int)s[t]) - '0');

			sprintf(s, "%d", sum);
			if (sum < 10)
				break;
		}
		printf("#%d %d\n", t_c, sum);
	}

	return 0;
}

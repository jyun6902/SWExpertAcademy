#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	int T = 0;
	scanf("%d", &T);
	for (int t_c = 1; t_c <= T; t_c++)
	{
		string s = "";
		cin >> s;
		int month = (int)(s[4] - '0') *10 + (int)(s[5]-'0');
		int day = (int)(s[6]-'0') * 10 + (int)(s[7]-'0');
		int flag = 0;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day >= 1 && day <= 31)
				flag = 1;
		}

		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day >= 1 && day <= 30)
				flag = 1;
		}
		else if (month == 2)
		{
			if (day >= 1 && day <= 28)
				flag = 1;
		}

		if (flag == 0)
			printf("#%d -1\n", t_c);
		else
		{
			printf("#%d ", t_c);
			for (int i = 0; i<4; i++)
				printf("%c", s[i]);
			printf("/");
			for (int i = 4; i<6; i++)
				printf("%c", s[i]);
			printf("/");
			for (int i = 6; i<8; i++)
				printf("%c", s[i]);
			printf("\n");
		}
	}
	return 0;
}
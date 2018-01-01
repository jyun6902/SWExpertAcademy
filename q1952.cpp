#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int min_2(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int T = 0;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		
		int fee[5] = {}, m[14] = {}, day[14] = {}, min_result = 0, dp[13] = {};
		for (int ticket_fee = 0; ticket_fee < 4; ticket_fee++)
			cin >> fee[ticket_fee];					  //1��, 1��, 3��, 1�� �̿��

		for (int month_plan = 1; month_plan <= 12; month_plan++)
		{
			cin >> m[month_plan];					 //�Ŵ� �̿��ϴ� ��¥
			day[month_plan] = fee[0] * m[month_plan];//1��ġ ���
		}

		int now = fee[0], cnt = 0;//cnt = 1�Ͼ� ��°ź��� 1��ġ ��°� �̵��� �Ǵ� ����
		while (now <= fee[1])
		{
			now += fee[0];
			cnt++;
		}

		for (int i = 1; i <= 12; i++)
		{
			if (m[i] > cnt)	 //1�޾� ��°� �̵��� ��� 1��ġ ������� �ٲٱ�
				day[i] = fee[1];//1��ġ ���
		}


	
		dp[1] = day[1];
		dp[2] = day[1] + day[2];
		for (int i = 3; i <= 12; i++)
			dp[i] = min_2(dp[i - 1] + day[i], dp[i - 3] + fee[2]);


		min_result = min_2(dp[12], fee[3]);//1��ġ ��°Ŷ� ��
	
		cout << "#" << test_case << " " << min_result << endl;
	}

	return 0;
}
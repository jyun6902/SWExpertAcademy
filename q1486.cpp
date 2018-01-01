#include <iostream>
#include <cstring>
using namespace std;

int height[21];
int dp[1 << 20];
int N, B = 0;
int min_2(int a, int b)
{
	if (a < b) return a;
	else return b;
}
int cal(int now, int cnt, int s)
{
	if (cnt >= B)
		return cnt - B;
	if (dp[now] != -1)
		return dp[now];

	dp[now] = 987654321;
	for (int i = 0; i <=s; i++)
	{
		if ((now &(1 << i)) == 0) //없을 경우
			dp[now] = min_2(dp[now], cal((now|(1 << i)), cnt+height[i], i ));
	}
	return dp[now];
}
int main()
{
	int T = 0;
	cin >> T;
	for (int t_c = 1; t_c <= T; t_c++)
	{
		int cnt = 0;//1<=N<=20
		memset(height, 0, sizeof(height));
		memset(dp, -1, sizeof(dp));
		cin >> N >> B ;

		for (int i = 0; i < N; i++)
			cin >> height[i];

		int result = cal(0, 0, N-1);//cal(int now, int cnt, int s)
		cout << "#" << t_c << " " << result << endl;
	}
	return 0;
}
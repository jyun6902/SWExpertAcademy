#include <iostream>
#include <cstdio>
using namespace std;

int max_result = -100000000;
int min_result = 100000000;
int N = 0;//( 3 ¡Â N ¡Â 12 )
int arr[13] = {};
int cal_num[5] = {};
void cal(int a, int b, int c, int d, int cnt, int sum)
{
	if (cnt >= N)
	{
		if (sum < min_result)
			min_result = sum;
		if (sum > max_result)
			max_result = sum;
		return;
	}

	if (a < cal_num[1] )
	cal(a + 1, b, c, d, cnt + 1, sum + arr[cnt+1]);

	if (b < cal_num[2])
	cal(a, b + 1, c, d, cnt + 1, sum - arr[cnt + 1]);

	if (c < cal_num[3])
	cal(a, b , c + 1, d, cnt + 1, sum * arr[cnt + 1]);

	if (d < cal_num[4])
	cal(a, b, c , d + 1, cnt + 1, sum / arr[cnt + 1]);


}


int main()
{
	int T = 0;
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		scanf("%d", &N);
		max_result = -100000000;
		min_result = 100000000;
		
		for (int i = 1; i <= 4; i++)
			scanf("%d", &cal_num[i]);

		for (int i = 1; i <= N; i++)
			scanf("%d", &arr[i]);

		cal(0, 0, 0, 0, 1, arr[1]);
		int result = max_result - min_result;
		printf("#%d %d\n", t_c, result);
	}
	
	//cal(int a, int b, int c, int d, int cnt, int sum)
	

	return 0;
}
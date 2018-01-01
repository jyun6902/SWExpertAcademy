#include <iostream>
using namespace std;

int min_2(int a, int b)
{
	if (a < b) return a;
	else return b;
}
int main()
{
	int T = 0;
	cin >> T;
	for (int t_c = 1; t_c <= T; t_c++)
	{
		int N, B = 0;
		cin >> N >> B;
		int height[20] = {}, result = 987654321;

		for (int i = 0; i < N; i++)
			cin >> height[i];

		for (int num = 0; num < (1 << N); num++)// 1<<N; 부분집합 개수
		{
			int answer = 0;
			for (int i = 0; i < N; i++)//N(원소의 수)개의 비트를 검사
			{
				if (num & (1 << i))//포함되어 있는 경우
				{
					cout << i << " ";
					answer += height[i];
					if (answer >= B && answer - B < result)
						result = answer - B;
				}
			}
				cout << endl;
		}
		cout << "#" << t_c << " " << result << endl;
	}
	return 0;
}
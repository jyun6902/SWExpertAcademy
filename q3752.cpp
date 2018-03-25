#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int T = 0;
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int arr[101] = {};
		int N = 0; //1≤N≤100
		int check[10001] = {};
		int result = 0;
		vector <int> help;//가능한 값 help 저장한 다음에 check에 copy 
		memset(check, 0, sizeof(check));
		memset(arr, 0, sizeof(arr));

		check[0] = 1;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		int max_value = arr[0];
		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j <= max_value; j++)
			{
				if (check[j] == 1 && arr[i] + j <= 10000)
				{
					help.push_back(arr[i] + j);
				}
			}
			check[arr[i]] = 1;

			for (int j = 0; j < help.size(); j++)
			{
				check[help[j]] = 1;
				if (max_value < help[j])
					max_value = help[j];
			}
			help.clear();
		}

		for (int i = 0; i <= 10000; i++)
		{
			if (check[i] == 1)
				result++;
		}

		printf("#%d %d\n", t_c, result);
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int T = 0;
	scanf("%d", &T);

	for (int t_c = 1 ; t_c<= T ; t_c++)
	{
		int N = 0;
		vector <int> v;
		int k = 0, sum = 0;

		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &k);
			v.push_back(k);
			sum += k;
		}

		sort(v.begin(), v.end(), greater<int>() );
		
		for (int i = 0; i < v.size()-2; i+=3)
		{
			sum -= v[i+2];
		}

		printf("#%d %d\n", t_c, sum);
	}
	return 0;
}
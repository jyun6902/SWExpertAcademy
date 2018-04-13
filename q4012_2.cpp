#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
vector <vector <int> > collect[17];
int stop[17] = { 0, 0, 0, 0, 3, 0, 10, 0, 35, 0, 126, 0, 462, 0, 1716, 0, 6435};
int N = 0;
void make_permutation(int n)
{
	for (int i = 0 ; i < (1<<n); i++)
	{
		vector <int> v;
		for (int j = 0; j < n; j++)
		{
			if (i&(1 << j))
			{
				v.push_back(j);
			}
		}

		if (v.size() == n / 2)
			collect[n].push_back(v);
		
		if (collect[n].size() == stop[n])
			return;
	}
}


int main()
{
	int T = 0;

	for (int i = 4 ; i<= 16; i+=2)
	make_permutation(i);
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		scanf("%d", &N);
		int maps[18][18] = {};
	
		int min_result = 987654321;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				scanf("%d", &maps[i][j]);
		}


		for (int i = 0; i < collect[N].size(); i++)
		{
			vector <int> v, v2;
			int check[16] = {};
			for (int j = 0; j < N/2; j++)
			{
				int t = collect[N][i][j];
				v.push_back(t);
				check[t] = 1;
			}
			
			for (int k = 0; k < N; k++)
			{
				if (check[k] == 0)
					v2.push_back(k);
			}

			int sum = 0;
			for (int p = 0; p < v.size(); p++)
			{
				for (int q = 0; q < v.size(); q++)
				{
					if (p == q)
						continue;
					sum+= (maps[v[p]][v[q]]);
				}
			}
			int sum2 = 0;
			for (int p = 0; p < v2.size(); p++)
			{
				for (int q = 0; q < v2.size(); q++)
				{
					if (p == q)
						continue;
					sum2 += (maps[v2[p]][v2[q]]);
				}
			}

			if (abs(sum - sum2) < min_result)
				min_result = abs(sum - sum2);
		}
	
		printf("#%d %d\n", t_c, min_result);
	}

	return 0;
}
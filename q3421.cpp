#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T = 0;
	cin >> T;

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int N, M = 0; //(1 ≤ N ≤ 20, 0 ≤ M ≤ 400)
		cin >> N >> M;
		int result = 0;

		if (M == 0)
		{
			cout << "#" << t_c << " " << (int)pow(2, N) << endl;
			continue;
		}

		int a, b = 0;
		vector <int >forbid;
		for (int i = 1; i <= M; i++)
		{
			cin >> a >> b;
			int k = 0;
			a -= 1;
			b -= 1;
			k |= (1 << a);
			k |= (1 << b);
			forbid.push_back(k);

		}//for i
		sort(forbid.begin(), forbid.end());
		vector <int> ::iterator pos = unique(forbid.begin(), forbid.end());
		forbid.erase(pos, forbid.end());//중복 제거

		int forbid_size = forbid.size();
		for (int num = 0; num < (1 << N); num++)
		{
			int flag = 1;
			for (int k = 0; k < forbid_size; k++)
			{
				if ((forbid[k] & num) == forbid[k])
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				result++;
		}

		cout << "#" << t_c << " " << result << endl;

	}
	return 0;
}
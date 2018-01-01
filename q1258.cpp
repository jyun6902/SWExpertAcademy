#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int T = 0;
	cin >> T;

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int N = 0;
		int maps[101][101] = {};
		vector <pair <int, int> > v;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> maps[i][j];
				if (maps[i][j] != 0)
					maps[i][j] = 1;
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (maps[i][j] == 1)
				{
					int  cnt_r = 0, cnt_w = 0;
					for (int t = i; t <= N; t++)
					{
						if (maps[t][j] == 0)
						{
							v.push_back({ cnt_w*cnt_r, cnt_r });//넓이, 행크기
							break;
						}
						cnt_w = 0;
						for (int k = j; k <= N; k++)
						{
							if (maps[t][k] == 0)
								break;
							else
								cnt_w++;

							maps[t][k] = 0;
						}//for k
						cnt_r++;
					}//for t
				}//if
			}//for j
		}//for i

		sort(v.begin(), v.end());//넓이 작은 순으로 sort
		cout << "#" << t_c << " " << v.size() << " ";
		for (int i = 0; i < v.size(); i++)
			cout << v[i].second << " " << v[i].first / v[i].second << " ";
		cout << endl;
	}
	return 0;
}
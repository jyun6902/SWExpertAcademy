#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
/* next permutation쓸 때 sort 하기!!!!!!!!중요!!!!*/
int cal(vector <int> &v, int c)
{
	int sum = 0, result = 0, max_result = 0;
	sort(v.begin(), v.end());
	do
	{
		sum = 0;
		result = 0;
		for (int i = 0 ; i< v.size() ; i++)
		{
			if (sum + v[i] <= c)
			{
				sum += v[i];
				result += (v[i] * v[i]);
			}

			else
				break;
		}

		if (max_result < result)//최댓값 갱신
			max_result = result;

	} while (next_permutation(v.begin(), v.end()));

	return max_result;
}

int main()
{
	int T = 0;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N, M, C = 0, answer =0;
		int maps[12][12] = {};
		bool check[12][12] = {};
		vector <int> v;
		cin >> N >> M >> C;// 벌통의 수 M// 1<=M<=5 //채취할 수 있는 최대양 10<=C<=30

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				cin >> maps[i][j];
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (j + M - 1 <= N)//M=1,2,3,4,5
				{
					v.clear();

					for (int k = 0; k < M; k++)
					{
						check[i][j + k] = 1;
						v.push_back(maps[i][j + k]);
					}
					int result = cal(v, C);
					/////////////////////////////////////////////////////
					for (int a = 1; a <= N; a++)//두번째 꿀단지 고르는방법
					{
						for (int b = 1; b <= N; b++)
						{
							if (b + M - 1 <= N)
							{
								int b_result = 0, flag = 0;
								v.clear();
								for (int t = 0; t < M; t++)
								{
									if (check[a][b + t] == 1)
									{
										flag = 1;
										break;
									}
									flag = 0;
									v.push_back(maps[a][b + t]);
								}
								if (flag == 0)
								{
									b_result = cal(v, C);
									if (result + b_result > answer)
										answer = result + b_result;
								}
							}
						}//for b
					}//for a
				}//if
					memset(check, 0, sizeof(check));
			}//for j
		}//for i

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}
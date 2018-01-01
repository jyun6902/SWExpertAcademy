#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
//최소약품 투입갯수 구하기
//재귀잘쓰기. 이미 check한것 또 check 해서 시간 초과 
int D, W, K = 0;//D= 세로 W=가로 K=합격기준
int maps[14][21] = {};//3≤D≤13 //1≤W≤20 //1≤K≤D
int maps_copy[14][21] = {};
int result = 0, now_result = 0;
vector <vector<int> > vd[21];
bool check()//K만큼 만족하는지 확인
{
	int cnt = 0;
	for (int i = 0; i < W; i++)//가로
	{
		cnt = 1;
		for (int j = 0; j < D - 1; j++)//세로
		{
			if (maps_copy[j][i] == maps_copy[j + 1][i])
				cnt++;
			else cnt = 1;

			if (cnt >= K)
				break;
		}
		if (cnt < K)
			return false;
	}
	return true;
}

void make_combination()
{
	for (int i = 0; i <= 21; i++)
		vd[i].clear();

	for (int num = 0; num < (1 << D); num++)// 1<<N; 부분집합 개수
	{
		vector <int> v;
		for (int i = 0; i < D; i++)//D(원소의 수)개의 비트를 검사
		{
			if (num & (1 << i))//포함되어 있는 경우
				v.push_back(i);
		}
		vd[v.size()].push_back(v);
	}//for num
}

void dfs(vector <int> v, int v_size, int cnt)
{
	if (check() == true)
	{
		if (result > cnt)
			result = cnt;
		return;
	}

	if (result <= cnt || cnt >= v_size)
		return;

	for (int j = 0; j < W; j++)
		maps_copy[v[cnt]][j] = 0;
	dfs(v, v_size, cnt + 1);

	for (int j = 0; j < W; j++)
		maps_copy[v[cnt]][j] = 1;
	dfs(v, v_size, cnt + 1);

	for (int j = 0; j < W; j++)//back_tracking
		maps_copy[v[cnt]][j] = maps[v[cnt]][j];
}

int main()
{
	int T = 0;
	cin >> T;

	for (int t_c = 1; t_c <= T; t_c++)
	{
		result = 987654321;
		memset(maps, 0, sizeof(maps));
		memset(maps_copy, 0, sizeof(maps_copy));
		cin >> D >> W >> K;

		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> maps[i][j];//특성 A=0, B=1
				maps_copy[i][j] = maps[i][j];
			}
		}

		if (check() == true)
			result = 0;

		else
		{
			int flag = 0;
			make_combination();

			for (int num = 1; num < D; num++)// 1<<N; 부분집합 개수
			{
				for (int i = 0; i < vd[num].size(); i++)
				{
					dfs(vd[num][i], num, 0);
					if (result < 987654321)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
					break;
			}
			//for num
		}//else

		cout << "#" << t_c << " " << result << endl;
	}
	return 0;
}
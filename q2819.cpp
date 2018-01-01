#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//string .erase() ; .erase(a,b) ; a부터 b까지 삭제
char maps[5][5];
string result = "";
vector <string> v;
void cal(int x, int y, int cnt)
{
	if (cnt == 6)
	{
		v.push_back(result);
		return;
	}
	if (x - 1 >= 1)
	{
		result += maps[x - 1][y];
		cal(x - 1, y, cnt + 1);
		result.erase(cnt + 1, cnt + 1);
	}

	if (x + 1 <= 4)
	{
		result += maps[x + 1][y];
		cal(x + 1, y, cnt + 1);
		result.erase(cnt + 1, cnt + 1);
	}

	if (y - 1 >= 1)
	{
		result += maps[x][y - 1];
		cal(x, y - 1, cnt + 1);
		result.erase(cnt + 1, cnt + 1);
	}

	if (y + 1 <= 4)
	{
		result += maps[x][y + 1];
		cal(x, y + 1, cnt + 1);
		result.erase(cnt + 1, cnt + 1);
	}
}

int main()
{
	int T = 0;
	cin >> T;

	for (int t_c = 1; t_c <= T; t_c++)
	{
		memset(maps, 0, sizeof(maps));
		v.clear();
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 1; j <= 4; j++)
				cin >> maps[i][j];
		}

		for (int i = 1; i <= 4; i++)
		{
			for (int j = 1; j <= 4; j++)
			{
				result = maps[i][j];
				cal(i, j, 0);
			}
		}
		sort(v.begin(), v.end(), less<string>());//중복제거
		vector <string>::iterator pos;
		pos = unique(v.begin(), v.end());
		v.erase(pos, v.end());

		//for (int i = 0; i < v.size(); i++)
		//	cout << v[i] << endl;

		cout << "#" << t_c << " " << v.size() << endl;
	}
	return 0;
}
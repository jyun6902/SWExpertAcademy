#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int N = 0;
int min_result = 987654321;
vector <vector <char> >v;
vector <int> score;
char samsung[8] = { 'S', 'A', 'M', 'S', 'U', 'N', 'G' };
int visit[8] = {};
void cal(int cnt, int now, int sum)
{
	if (cnt == 7)
	{
		if (sum < min_result)
			min_result = sum;
		return;
	}
	if (now >= N || sum >= min_result)
		return;

	int cnt_cp = cnt;
	int visit_cp[8] = {};

	for (int i = 0; i < 8; i++)
		visit_cp[i] = visit[i];
	for (int i = 0; i < v[now].size(); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (visit[j])
				continue;
			if (samsung[j] == v[now][i])
			{
				cnt++;
				visit[j] = 1;
				break;
			}
		}
	}
	cal(cnt, now + 1, sum + score[now]);
	cnt = cnt_cp;
	for (int i = 0; i < 8; i++)
		visit[i] = visit_cp[i];

	cal(cnt, now + 1, sum);

}

int main()
{
	int T = 0;
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++)
	{
		v.clear();
		score.clear();
		min_result = 987654321;
		memset(visit, 0, sizeof(visit));
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			int len = 0, s = 0;
			scanf("%d", &len);
			vector <char > c;
			char alpha;
			for (int j = 0; j < len; j++)
			{
				cin >> alpha;
				//scanf("%s", &alpha);
				c.push_back(alpha);
			}
			scanf("%d", &s);
			v.push_back(c);
			score.push_back(s);
		}
		cal(0, 0, 0);
		if (min_result == 987654321)
			min_result = -1;
		printf("#%d %d\n", t_c, min_result);
	}
	return 0;
}
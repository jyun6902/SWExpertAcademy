#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <climits>
#include <vector>
using namespace std;
int maps[102][102];
int dx[4] = { 0, 0 ,1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int N = 0;
vector <pair<int, int> > adj[20000];
//q1261 알고스팟과 같음
vector<int> dijkstra(int src)
{
	vector <int> dist(N*N + 1, INT_MAX);
	dist[src] = 0;
	priority_queue< pair<int, int> > pq;

	pq.push({ 0,src });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int from = pq.top().second;

		pq.pop();
		if (dist[from] < cost)
			continue;

		for (int i = 0; i < adj[from].size(); i++)
		{
			int to = adj[from][i].first;
			int next_cost = cost + adj[from][i].second;

			if (dist[to] > next_cost)
			{
				dist[to] = next_cost;
				pq.push({ -next_cost, to });
			}
		}
	}

	return dist;
}

#define num(x, y) ((x - 1)*N + y)
int main()
{
	int T = 0;
	cin >> T;
	for (int t_c = 1; t_c <= T; t_c++)
	{

		memset(maps, 0, sizeof(maps));
		memset(adj, 0, sizeof(adj));
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				scanf("%1d", &maps[i][j]);
			}
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];

					if (y< 1 || y >N || x< 1 || x> N)
						continue;

					adj[num(i, j)].push_back({ num(x,y), maps[x][y] });
				}
			}
		}
		vector<int> answer = dijkstra(1);

		cout << "#" << t_c << " " << answer[N*N] << endl;
	}
	return 0;
}
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
//sec크게 하려면 배열사이즈도 크게!! 중요!! 에러나는이유!
deque <int> wait_info; //접수칸 기다리는 사람
deque  <pair <int, pair<int, int> > > wait_repair;//정비칸 기다리는 사람// 온시간 저장,이용 했던 접수창구 번호, 사람
deque <int> a_check;//사람 여부 확인
deque <int> b_check;//사람 여부 확인
int main()
{
	int T = 0;
	cin >> T;
	for (int t_c = 1; t_c <= T; t_c++)
	{
		int N, M, K, A, B = 0;//N=접수창구 M=정비창구 K= 방문 고객수 A,B = 접수창구 지갑놓고간곳
		int answer = -1, sec = 0;
		int ai[21] = {}, bj[21] = {};
		vector <int > p[3001];//도착시간에 누구누구있는지(2 ≤ K ≤ 1,000) p[도착시간]=사람
		vector <int > v[10][10];//이용한 곳 저장
		deque <pair <int, int> > a[10], b[10];//접수,수리[칸=index]//있는사람, 시간 
		int info_save[3001] = {};//접수한곳 저장
		wait_info.clear();
		wait_repair.clear();
		a_check.clear();
		b_check.clear();
		cin >> N >> M >> K >> A >> B;

		for (int i = 1; i <= N; i++)
			cin >> ai[i];//접수 창구 i에서 고객 한 명의 고장을 접수하는 데 걸리는 처리 시간은 ai

		for (int i = 1; i <= M; i++)
			cin >> bj[i];//정비 창구 j에서 고객 한 명의 차량을 정비하는 데 걸리는 처리 시간은 bj

		for (int i = 1; i <= K; i++)
		{
			int a = 0;
			cin >> a;//사람들 도착시간
			p[a].push_back(i);//도착한 시간 별로 저장
		}

		while (1)
		{
			if (sec == 3000)
				break;

			if (!a_check.empty())
			{
				for (int i = 1; i <= N; i++)
				{
					if (a[i].size() != 0)
					{
						a[i].front().second += 1;
						if (a[i].front().second == ai[i])//접수,수리[칸=index]//있는사람, 시간 
						{
							int who = a[i].front().first;
							info_save[who] = i;
							a_check.pop_front();
							a[i].erase(a[i].begin());
							wait_repair.push_back({ sec,{ i, who } });// 온시간 저장,이용 했던 접수창구 번호, 사람
						}
					}
				}
			}//접수중인 사람이 있는 경우

			if (a_check.size() < N)//접수 자리가 있는 경우
			{
				if (!wait_info.empty())//기다리는 사람이 있는 경우
				{
					if (wait_info.size() != 1)
						sort(wait_info.begin(), wait_info.end());
					int possible_info = N - a_check.size();
					int cnt = 0;

					for (int j = 1; j <= N; j++)//접수 창고번호
					{
						if (wait_info.size() == 0 || cnt == possible_info)
							break;

						if (a[j].size() == 0)//접수,수리[칸=index]//있는사람, 시간 
						{
							int person = wait_info.front();// 온시간 저장,이용 했던 접수창구 번호, 사람
							a[j].push_back({ person, 0 });/////////////////1초인지 0초인지..
							wait_info.pop_front();
							a_check.push_back(1);
							cnt++;
						}
					}
				}//if (!wait_info.empty())//기다리는 사람이 있는 경우
			}//if (a_check.size() < N)//접수 자리가 있는 경우

			 ////////////////////////////////////////////////
			if (!b_check.empty())
			{
				for (int i = 1; i <= M; i++)
				{
					if (b[i].size() != 0)
					{
						b[i].front().second += 1;
						if (b[i].front().second == bj[i])//접수,수리[칸=index]//있는사람, 시간 
						{
							int who = b[i].front().first;
							int who_info = info_save[who];
							v[who_info][i].push_back(who);
							b[i].erase(b[i].begin());
							b_check.pop_front();
						}
					}
				}
			}//수리중인 사람이 있는 경우

			if (b_check.size() < M)//수리창고 자리가 있는 경우
			{
				if (!wait_repair.empty())//기다리는 사람이 있는 경우
				{
					int possible_repair = M - b_check.size();
					int cnt = 0;
					sort(wait_repair.begin(), wait_repair.end());

					for (int j = 1; j <= M; j++)//접수 창고번호
					{
						if (wait_repair.size() == 0 || cnt == possible_repair)
							break;

						if (b[j].size() == 0)//접수,수리[칸=index]//있는사람, 시간 
						{
							int person = wait_repair.front().second.second;// 온시간 저장,이용 했던 접수창구 번호, 사람
							b[j].push_back({ person,0 });/////////////////1초인지 0초인지..
							wait_repair.pop_front();
							b_check.push_back(1);
							cnt++;
						}
					}
				}//if (!wait_repair.empty())//기다리는 사람이 있는 경우
			}//if (b_check.size() < M)//수리창고 자리가 있는 경우

			if (p[sec].size() != 0)//sec에 들어오는 사람있는 경우
			{
				int p_size = p[sec].size();
				for (int i = 0; i < p_size; i++)
				{
					if (a_check.size() < N)
					{
						for (int k = 1; k <= N; k++)
						{
							if (a_check.size() == N || p[sec].size() == 0)
								break;

							if (a[k].size() == 0)//접수,수리[칸=index]//있는사람, 시간 
							{
								a[k].push_back({ p[sec][i], 0 });
								p[sec].erase(p[sec].begin());
								a_check.push_back(1);
							}
						}
					}

					else//접수창고 꽉찼을 경우
					{
						int p_size = p[sec].size();
						for (int i = 0; i < p_size; i++)
						{
							int k = p[sec].front();
							wait_info.push_back(k);///
							p[sec].erase(p[sec].begin());
						}
					}
				}
			}

			sec++;
		}//while
		if (!v[A][B].empty())
		{
			answer = 0;
			int v_size = v[A][B].size();
			for (int i = 0; i < v_size; i++)
			{
				int a = v[A][B].back();
				v[A][B].pop_back();
				answer += a;
			}
		}

		cout << "#" << t_c << " " << answer << endl;
	}//for

	return 0;
}
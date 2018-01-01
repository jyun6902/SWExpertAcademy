#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <functional>   
using namespace std;

int min_result = 987654321;
vector <vector<int> > v[11];//어디계단으로갈지 저장
vector <pair <int, pair <int, int> > > people;
int step1_x, step1_y, step1_len, step2_x, step2_y, step2_len = 0;//step1; A계단, step2; B계단
int maps[11][11] = {};//1은 사람을, 2 이상은 계단의 입구
//vector 인덱스에러날때는 그냥 deque로 하기!!!!!!!!

void cal(vector<int> v, int k)//k=a,b계단여부
{
	int result = 0, result2 = 0;
	int v_s = v.size();
	int p_s = people.size();
	vector < pair<int, pair<int, int> > >people_copy;// k계단, x,y좌표
	people_copy = people;//카피
	vector <pair< int, int > > A;//도착시간, i번째사람
	vector <pair< int, int > > B;
	deque <pair <int, int> > walkingA; //walkingA ;초, A계단 내려가고있는 사람
	deque <pair <int, int> > walkingB;

	for (int i = 0; i < v_s; i++)
		people_copy[v[i]].first = k;

	for (int i = 0; i < p_s; i++)
	{
		if (people_copy[i].first != k)
			people_copy[i].first = (k + 1) % 2;
	}

	for (int i = 0; i < p_s; i++)
	{
		int x = people_copy[i].second.first;
		int y = people_copy[i].second.second;
		if (people_copy[i].first == 0)//step1 A계단
		{
			int arrive_time = abs(step1_x - x) + abs(step1_y - y);
			A.push_back({ arrive_time + 1 ,i });
		}

		else//step2 B계단
		{
			int arrive_time = abs(step2_x - x) + abs(step2_y - y);
			B.push_back({ arrive_time + 1,i });
		}
	}
	///////////////////////////////////////////
	if (A.size() != 0)
	{
		sort(A.begin(), A.end());//도착시간별로 저장 도착시간, i번째사람
		reverse(A.begin(), A.end());
		result = A.back().first;
		while (1)
		{
			if (A.size() == 0 && walkingA.size() == 0)
				break;

			if (walkingA.size() < 3 && A.size() != 0)//walkingA에 넣기
			{
				int A_s = A.size();
				for (int k = 0; k < A_s; k++)
				{
					int person = A.back().second;//back = 도착시간 작은 것부터
					int arrive_time = A.back().first;

					if (arrive_time > result || walkingA.size() >= 3 || A.size() == 0)
						break;
					else
					{
						A.pop_back();
						walkingA.push_back({ 0,person });
					}
				}
			}
			if (!walkingA.empty())
			{
				int wA_s = walkingA.size();
				for (int i = 0; i < wA_s; i++)
				{
					walkingA.front().first += 1;//walkingA ;초, A계단 내려가고있는 사람
					int sec = walkingA.front().first;
					int who = walkingA.front().second;
					walkingA.pop_front();

					if (sec != step1_len)
						walkingA.push_back({ sec, who });
				}
			}
			result++;
		}//while
	}//if
//////////////////////////////////////////////
	if (B.size() != 0)
	{
		sort(B.begin(), B.end());//도착시간별로 저장 도착시간, i번째사람
		reverse(B.begin(), B.end());
		result2 = B.back().first;
		while (1)
		{
			if (B.size() == 0 && walkingB.size() == 0)
				break;

			if (walkingB.size() < 3 && B.size() != 0)//walkingB에 넣기
			{
				int B_s = B.size();
				for (int k = 0; k < B_s; k++)
				{
					int person = B.back().second;//back = 도착시간 작은 것부터
					int arrive_time = B.back().first;

					if (arrive_time > result2 || walkingB.size() >= 3 || B.size() == 0)
						break;
					else
					{
						B.pop_back();
						walkingB.push_back({ 0,person });
					}
				}
			}

			if (!walkingB.empty())
			{
				int wB_s = walkingB.size();
				for (int i = 0; i < wB_s; i++)
				{
					walkingB.front().first += 1;//walkingA ;초, A계단 내려가고있는 사람
					int sec = walkingB.front().first;
					int who = walkingB.front().second;
					walkingB.pop_front();

					if (sec != step2_len)
						walkingB.push_back({ sec, who });
				}

			}

			result2++;
		}//while
	}//if

	int answer = 0;
	if (result < result2)
		answer = result2;
	else
		answer = result;

	if (min_result > answer)
		min_result = answer;
}

void make_combination(int N)
{
	for (int i = 0; i < 11; i++)
		v[i].clear();

	for (int num = 0; num < (1 << N); num++)
	{
		vector <int> d;

		for (int i = 0; i < N; i++)
		{
			if (num&(1 << i))
				d.push_back(i);
		}
		v[d.size()].push_back(d);
	}
}


int main()
{
	int T = 0;
	cin >> T;
	for (int t_c = 1; t_c <= T; t_c++)
	{
		int N = 0;//방 길이  (4 ≤ N ≤ 10)
		people.clear();
		vector <pair<int, pair<int, int > > > stair;//계단 길이, x,y
		deque <pair< int, int> > wait;//계단에서 기다림
		min_result = 987654321;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> maps[i][j];
				if (maps[i][j] == 1)//사람 (1 ≤ 사람의 수 ≤ 10)
					people.push_back({ 3, { i,j } });//어디계단으로갈지, x,y좌표
				if (maps[i][j] >= 2)
					stair.push_back({ maps[i][j], { i,j } });
			}
		}

		step1_len = stair.back().first;//계단정보
		step1_x = stair.back().second.first;
		step1_y = stair.back().second.second;
		stair.pop_back();

		step2_len = stair.back().first;
		step2_x = stair.back().second.first;
		step2_y = stair.back().second.second;

		int p_s = people.size();

		for (int i = 0; i < p_s; i++)
			v[i].clear();

		make_combination(p_s);//vector <vector<int>> v[11];//어디계단으로갈지 저장

		for (int i = 0; i < p_s; i++)
		{
			int v_s = v[i].size();
			for (int j = 0; j < v_s; j++)
			{
				vector <int > d = v[i][j];
				cal(d, 0);// B계단
				cal(d, 1);// A계단
			}
		}//for i

		cout << "#" << t_c << " " << min_result << endl;
	}//for test_case
	return 0;
}
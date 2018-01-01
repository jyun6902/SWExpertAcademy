#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
//secũ�� �Ϸ��� �迭����� ũ��!! �߿�!! ������������!
deque <int> wait_info; //����ĭ ��ٸ��� ���
deque  <pair <int, pair<int, int> > > wait_repair;//����ĭ ��ٸ��� ���// �½ð� ����,�̿� �ߴ� ����â�� ��ȣ, ���
deque <int> a_check;//��� ���� Ȯ��
deque <int> b_check;//��� ���� Ȯ��
int main()
{
	int T = 0;
	cin >> T;
	for (int t_c = 1; t_c <= T; t_c++)
	{
		int N, M, K, A, B = 0;//N=����â�� M=����â�� K= �湮 ���� A,B = ����â�� ����������
		int answer = -1, sec = 0;
		int ai[21] = {}, bj[21] = {};
		vector <int > p[3001];//�����ð��� ���������ִ���(2 �� K �� 1,000) p[�����ð�]=���
		vector <int > v[10][10];//�̿��� �� ����
		deque <pair <int, int> > a[10], b[10];//����,����[ĭ=index]//�ִ»��, �ð� 
		int info_save[3001] = {};//�����Ѱ� ����
		wait_info.clear();
		wait_repair.clear();
		a_check.clear();
		b_check.clear();
		cin >> N >> M >> K >> A >> B;

		for (int i = 1; i <= N; i++)
			cin >> ai[i];//���� â�� i���� �� �� ���� ������ �����ϴ� �� �ɸ��� ó�� �ð��� ai

		for (int i = 1; i <= M; i++)
			cin >> bj[i];//���� â�� j���� �� �� ���� ������ �����ϴ� �� �ɸ��� ó�� �ð��� bj

		for (int i = 1; i <= K; i++)
		{
			int a = 0;
			cin >> a;//����� �����ð�
			p[a].push_back(i);//������ �ð� ���� ����
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
						if (a[i].front().second == ai[i])//����,����[ĭ=index]//�ִ»��, �ð� 
						{
							int who = a[i].front().first;
							info_save[who] = i;
							a_check.pop_front();
							a[i].erase(a[i].begin());
							wait_repair.push_back({ sec,{ i, who } });// �½ð� ����,�̿� �ߴ� ����â�� ��ȣ, ���
						}
					}
				}
			}//�������� ����� �ִ� ���

			if (a_check.size() < N)//���� �ڸ��� �ִ� ���
			{
				if (!wait_info.empty())//��ٸ��� ����� �ִ� ���
				{
					if (wait_info.size() != 1)
						sort(wait_info.begin(), wait_info.end());
					int possible_info = N - a_check.size();
					int cnt = 0;

					for (int j = 1; j <= N; j++)//���� â���ȣ
					{
						if (wait_info.size() == 0 || cnt == possible_info)
							break;

						if (a[j].size() == 0)//����,����[ĭ=index]//�ִ»��, �ð� 
						{
							int person = wait_info.front();// �½ð� ����,�̿� �ߴ� ����â�� ��ȣ, ���
							a[j].push_back({ person, 0 });/////////////////1������ 0������..
							wait_info.pop_front();
							a_check.push_back(1);
							cnt++;
						}
					}
				}//if (!wait_info.empty())//��ٸ��� ����� �ִ� ���
			}//if (a_check.size() < N)//���� �ڸ��� �ִ� ���

			 ////////////////////////////////////////////////
			if (!b_check.empty())
			{
				for (int i = 1; i <= M; i++)
				{
					if (b[i].size() != 0)
					{
						b[i].front().second += 1;
						if (b[i].front().second == bj[i])//����,����[ĭ=index]//�ִ»��, �ð� 
						{
							int who = b[i].front().first;
							int who_info = info_save[who];
							v[who_info][i].push_back(who);
							b[i].erase(b[i].begin());
							b_check.pop_front();
						}
					}
				}
			}//�������� ����� �ִ� ���

			if (b_check.size() < M)//����â�� �ڸ��� �ִ� ���
			{
				if (!wait_repair.empty())//��ٸ��� ����� �ִ� ���
				{
					int possible_repair = M - b_check.size();
					int cnt = 0;
					sort(wait_repair.begin(), wait_repair.end());

					for (int j = 1; j <= M; j++)//���� â���ȣ
					{
						if (wait_repair.size() == 0 || cnt == possible_repair)
							break;

						if (b[j].size() == 0)//����,����[ĭ=index]//�ִ»��, �ð� 
						{
							int person = wait_repair.front().second.second;// �½ð� ����,�̿� �ߴ� ����â�� ��ȣ, ���
							b[j].push_back({ person,0 });/////////////////1������ 0������..
							wait_repair.pop_front();
							b_check.push_back(1);
							cnt++;
						}
					}
				}//if (!wait_repair.empty())//��ٸ��� ����� �ִ� ���
			}//if (b_check.size() < M)//����â�� �ڸ��� �ִ� ���

			if (p[sec].size() != 0)//sec�� ������ ����ִ� ���
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

							if (a[k].size() == 0)//����,����[ĭ=index]//�ִ»��, �ð� 
							{
								a[k].push_back({ p[sec][i], 0 });
								p[sec].erase(p[sec].begin());
								a_check.push_back(1);
							}
						}
					}

					else//����â�� ��á�� ���
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
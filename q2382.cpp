#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
// pair�� sort�Լ��� ������ ��� �⺻������ pair�� ù��° ���Ҹ� �������� ������ �ǰ� ù��° ���Ұ� ���� ��� �ι�° ���Ҹ� ����ؼ� ���ϰ� �˴ϴ�.
// sort�ؼ� ū������ �ű��
int main()
{
	int T = 0;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N = 0, K = 0, M = 0; //�� �� 5 �� N �� 100 //�̻��� ���� ���� 5 �� K �� 1,000 //�ݸ� �ð� 1 �� M �� 1,000
		int a, b, c, d;			//������ġ, ������ġ, �̻��� ��, �̵�����(��: 1, ��: 2, ��: 3, ��: 4)
		int result = 0;
		int next_maps[3][102][102] = {};//���簡��ū index, �� index��, �迭dir, ����
		vector <  pair < pair< pair<int, int>, pair<int, int> >, int> > v;//�̻��� ��, ����,  ����, ����, ��ü�̸�
		cin >> N >> M >> K;
		for (int i = 1; i <= K; i++)
		{
			cin >> a >> b >> c >> d;
			v.push_back({ { { c, d }, {a, b }}, i });//�̻��� ��, ����, ����, ����, �̻����̸�
		}
		
		while (M--)
		{
			sort(v.begin(), v.end());//ū �̻������� �����̵���
			int K = v.size();
			for (int t = 0; t < K; t++)
			{
				int num = v.back().first.first.first;
				int dir = v.back().first.first.second;
				int x = v.back().first.second.first;
				int y = v.back().first.second.second;
				int name = v.back().second;
				v.pop_back();

				if (dir == 1 )//��
				{
					x -= 1;
					if (x == 0)
					{
						num /= 2;
						dir = 2;
					}
					
					if (num != 0 && next_maps[0][x][y]!=0)
					{
						next_maps[1][x][y] += num;
					}

					else if (num != 0 && next_maps[0][x][y] == 0)
					{
						next_maps[0][x][y] = name;
						next_maps[1][x][y] = num;
						next_maps[2][x][y] = dir;
					}
				}
				
				else if (dir == 2)//��
				{
					x += 1;
					if (x == N-1)
					{
						num /= 2;
						dir = 1;
					}

					if (num != 0 &&next_maps[0][x][y] != 0)
					{
						next_maps[1][x][y] += num;
					}

					else if (num != 0 && next_maps[0][x][y] == 0)
					{
						next_maps[0][x][y] = name;
						next_maps[1][x][y] = num;
						next_maps[2][x][y] = dir;
					}
				}

				else if (dir == 3)//��
				{
					y -= 1;
					if (y == 0)
					{
						num /= 2;
						dir = 4;
					}

					if (num != 0 && next_maps[0][x][y] != 0)
					{
						next_maps[1][x][y] += num;
					}

					else if (num != 0 && next_maps[0][x][y] == 0)
					{
						next_maps[0][x][y] = name;
						next_maps[1][x][y] = num;
						next_maps[2][x][y] = dir;
					}
				}

				else if (dir == 4)//��
				{
					y += 1;
					if (y == N-1)
					{
						num /= 2;
						dir = 3;
					}

					if (num != 0 && next_maps[0][x][y] != 0)
					{
						next_maps[1][x][y] += num;
					}

					else if (num != 0 && next_maps[0][x][y] == 0)
					{
						next_maps[0][x][y] = name;
						next_maps[1][x][y] = num;
						next_maps[2][x][y] = dir;
					}
				}
			}//for ��ü��
			 ////////////////////////////////////////////////////////////////////////////////////////////
			for (int i = 0; i <= N - 1; i++)
			{
				for (int j = 0; j <= N - 1; j++)
				{
					if (next_maps[0][i][j] != 0)
					{
						v.push_back({ { { next_maps[1][i][j], next_maps[2][i][j] },{i,j } },next_maps[0][i][j] });//�̻��� ��, ����, ����, ����, �̻����̸�
						next_maps[0][i][j] = next_maps[1][i][j] = next_maps[2][i][j] = 0;
					}
				}
			}
			
		}//M�ð� ��ŭ
		a = v.size();
		for (int t = 0; t < a; t++)
		{
			int num = v.back().first.first.first;
			v.pop_back();
			result += num;
		}

		cout << "#" << test_case << " " << result << endl;
		
	}//for test_Case

	return 0;
}
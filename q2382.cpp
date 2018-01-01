#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
// pair을 sort함수로 정렬할 경우 기본적으로 pair의 첫번째 원소를 기준으로 정렬이 되고 첫번째 원소가 같을 경우 두번째 원소를 사용해서 비교하게 됩니다.
// sort해서 큰값부터 옮기기
int main()
{
	int T = 0;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N = 0, K = 0, M = 0; //한 변 5 ≤ N ≤ 100 //미생물 군집 갯수 5 ≤ K ≤ 1,000 //격리 시간 1 ≤ M ≤ 1,000
		int a, b, c, d;			//세로위치, 가로위치, 미생물 수, 이동방향(상: 1, 하: 2, 좌: 3, 우: 4)
		int result = 0;
		int next_maps[3][102][102] = {};//현재가장큰 index, 그 index값, 배열dir, 총합
		vector <  pair < pair< pair<int, int>, pair<int, int> >, int> > v;//미생물 수, 방향,  세로, 가로, 객체이름
		cin >> N >> M >> K;
		for (int i = 1; i <= K; i++)
		{
			cin >> a >> b >> c >> d;
			v.push_back({ { { c, d }, {a, b }}, i });//미생물 수, 방향, 세로, 가로, 미생물이름
		}
		
		while (M--)
		{
			sort(v.begin(), v.end());//큰 미생물부터 움직이도록
			int K = v.size();
			for (int t = 0; t < K; t++)
			{
				int num = v.back().first.first.first;
				int dir = v.back().first.first.second;
				int x = v.back().first.second.first;
				int y = v.back().first.second.second;
				int name = v.back().second;
				v.pop_back();

				if (dir == 1 )//상
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
				
				else if (dir == 2)//하
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

				else if (dir == 3)//좌
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

				else if (dir == 4)//우
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
			}//for 개체수
			 ////////////////////////////////////////////////////////////////////////////////////////////
			for (int i = 0; i <= N - 1; i++)
			{
				for (int j = 0; j <= N - 1; j++)
				{
					if (next_maps[0][i][j] != 0)
					{
						v.push_back({ { { next_maps[1][i][j], next_maps[2][i][j] },{i,j } },next_maps[0][i][j] });//미생물 수, 방향, 세로, 가로, 미생물이름
						next_maps[0][i][j] = next_maps[1][i][j] = next_maps[2][i][j] = 0;
					}
				}
			}
			
		}//M시간 만큼
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
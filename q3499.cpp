#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	int T = 0;
	cin >> T;

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int N = 0;
		cin >> N;
		deque <string> dq_even, dq_odd;
		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			if (i < N/2 || (N%2== 1 && i == N/2))
				dq_even.push_back(s);

			else
				dq_odd.push_back(s);
		}

		cout << "#" << t_c << " " ;
		for (int i = 0; i <= N / 2; i++)
		{
			if (!dq_even.empty())
			{
				cout << dq_even.front() << " ";
				dq_even.pop_front();
			}
			
			if (!dq_odd.empty())
			{
				cout << dq_odd.front()<< " " ;
				dq_odd.pop_front();
			}
		}
		cout << endl;
	}
	return 0;
}
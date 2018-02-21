#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int T = 0;
	cin >> T;

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int K = 0;
		string s;
		cin >> K >> s;

		if (K > s.size())
		{
			cout << "#" << t_c << " " << "none" << endl;
			continue;
		}

		
		else
		{
			vector <string> v;
			int s_size = s.size();
			for (int i = 0; i < s_size; i++)
			{
				string sen;
				for (int j = i; j < s_size; j++)
				{
					sen += s[j];
				}

				v.push_back(sen);
			}

			sort(v.begin(), v.end());
			cout << "#" << t_c << " " << v[K-1] << endl;
		}

	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int T = 0;
	cin >> T;
	for (int t_c = 1; t_c <= T; t_c++)
	{
		int N = 0;
		int min_result = 0;
		cin >> N;
		vector<int> v;
		for (int i = 0; i < N; i++)
		{
			int k = 0;
			cin >> k;
			v.push_back(k);
		}
		sort(v.begin(), v.end());
		int arr[10001] = { 0, };
		int left = N / 2 - 1, right = N / 2 + 1;

		arr[N / 2] = v[0];
		for (int i = 1; i < N; i += 2)
		{
			arr[left] = v[i];

			if (i == N - 1 && N % 2 == 0)
				break;
			arr[right] = v[i + 1];
			left--;
			right++;
		}

		for (int i = 0; i < N - 1; i++)
		{
			if (abs(arr[i] - arr[i + 1]) > min_result)
				min_result = abs(arr[i] - arr[i + 1]);
		}

		if (abs(arr[0] - arr[N - 1]) > min_result)
			min_result = abs(arr[0] - arr[N - 1]);

		cout << "#" << t_c << " " << min_result << endl;
	}//for t_c

	return 0;
}
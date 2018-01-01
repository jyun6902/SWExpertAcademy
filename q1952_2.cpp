#include <iostream>
int day, one_month, three_month, year = 0;
using namespace std;
int arr[12] = {};
int min_result = 0;
void cal(int month, int cost)
{
	if (month >= 12)
	{
		if (min_result > cost)
			min_result = cost;
		return;
	}
		cal(month + 1, cost + (day*arr[month]));
		cal(month + 1, cost + one_month);
		cal(month + 3, cost + three_month);
}

int main()
{
	int T = 0;
	cin >> T;
	for (int t_c = 1; t_c <= T; t_c++)
	{
		cin >> day >> one_month >> three_month >> year;
		for (int i = 0; i < 12; i++)
			cin >> arr[i];
		min_result = year;

		cal(0, 0);
		
			cout << "#" << t_c << " " << min_result <<endl;
	}
	return 0;
}
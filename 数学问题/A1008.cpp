#include <iostream>

using namespace std;

int f[100];

int main()
{
	int n;
	int to;
	int now = 0;
	int time = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> to;
		if (to - now > 0)
		{
			time += (to - now) * 6 + 5;
		}
		else
		{
			time += (now - to) * 4 + 5;
		}
		now = to;
	}

	cout << time;
}
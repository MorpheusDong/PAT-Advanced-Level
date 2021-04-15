#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> V;
	int n, p;
	int temp;

	//读取数据
	cin >> n >> p;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		V.push_back(temp);
	}

	//从小到大排序
	sort(V.begin(), V.end(), less<int>());

	int max = 1;    //序列的最大长度
	for (int i = 0; i < n; ++i)
	{
		//从剩余序列中，找第一个大于p倍左端点（p*V[i]）的数的位置j，j-i就是满足条件的序列的长度
		int j = upper_bound(V.begin() + i + 1, V.end(), (long long)V[i] * p) - V.begin();    //注意用longlong避免溢出
		max = (j - i > max )? j - i : max;    //更新最大
	}
	cout << max;
}
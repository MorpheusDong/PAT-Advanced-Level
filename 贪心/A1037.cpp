#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	vector<int> coupon;
	vector<int> product;

	//读取数据
	int temp;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		coupon.push_back(temp);
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		product.push_back(temp);
	}

	//两者都从小到大排序
	sort(coupon.begin(),coupon.end(),less<int>());
	sort(product.begin(), product.end(), less<int>());

	int ans = 0;
	int i, j;

	//从左到右同步遍历，选两者最小的负数相乘
	for (i = 0; i < n&&i < m&&coupon[i] < 0 && product[i] < 0; ++i)
	{
		ans += coupon[i] * product[i];    //累加乘积
	}

	//从右到左同步遍历，选两者最大的正数相乘
	for (i = n - 1, j = m - 1; i >= 0 && j >= 0 && coupon[i] > 0 && product[j] > 0; --i, --j)
	{
		ans += coupon[i] * product[j];    //累加乘积
	}

	cout << ans;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)    //比较函数，按两字符串拼贴后较小的方式排序
{
	return a + b < b + a;
}

int main()
{
	vector<string> V;
	int n;

	//读取数据
	cin >> n;
	string temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		V.push_back(temp);
	}

	//排序
	sort(V.begin(), V.end(), cmp);

	//组装排序后的字符串
	string ans;
	int len = V.size();
    for (int i = 0; i < len; ++i)
	{
		ans += V[i];
	}

	//去掉前导0
	while (ans.size() != 0 && *ans.begin() == '0')
	{
		ans.erase(ans.begin());
	}

	//输出结果
	if (ans.size() == 0)
		cout << "0";
	else
		cout << ans;
}
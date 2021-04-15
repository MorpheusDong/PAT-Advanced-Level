#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

struct mooncake
{
	double store;    //库存
	double sell;    //总售价
	double price;    //单价
};

bool cmp(mooncake x, mooncake y)
{
	if (x.price >= y.price)
		return true;
	else
		return false;
}

int main()
{
	int n;    //月饼种类
	double D;    //需求量
	double ans = 0;    //最终结果
	cin >> n >> D;
	mooncake* cake = new mooncake[n];
	for (int i = 0; i < n; ++i)
		cin >> cake[i].store;
	for (int i = 0; i < n; ++i)
	{
		cin >> cake[i].sell;
		cake[i].price = cake[i].sell / cake[i].store;
	}
	sort(cake, cake + n, cmp);
	for (int i = 0; i < n; ++i)
	{
		if (cake[i].store <= D)    //库存比需求小，则全部卖出
		{
			D -= cake[i].store;
			ans += cake[i].sell;
		}
		else    //库存比需求大，则卖出相应的需求量
		{
			ans += D * cake[i].price;
			break;    //注意此时需求已经填满，应退出循环
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << ans;

	delete[]cake;
	return 0;
}
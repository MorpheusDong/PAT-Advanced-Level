#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)    //求最大公约数
{
	return b == 0 ? a : gcd(b, a%b);
}

struct Fraction
{
	ll up;
	ll down;
}a,b;

Fraction reduction(Fraction result)
{
	if (result.down < 0)    //符号记到分子上
	{
		result.up = -result.up;
		result.down = -result.down;
	}
	if (result.up == 0)
		result.down = 1;
	else    //化简
	{
		int d = gcd(abs(result.up), abs(result.down));    //获取最大公约数
		result.up /= d;
		result.down /= d;
	}
	return result;
}

Fraction add(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up *f2.down + f2.up*f1.down;
	result.down = f1.down*f2.down;
	return reduction(result);
}

Fraction minu(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up *f2.down - f2.up*f1.down;
	result.down = f1.down*f2.down;
	return reduction(result);
}

Fraction multi(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up *f2.up;
	result.down = f1.down*f2.down;
	return reduction(result);
}

Fraction divide(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up *f2.down;
	result.down = f1.down*f2.up;
	return reduction(result);
}

//展示结果
void show(Fraction f)
{
	f = reduction(f);
	if (f.up < 0)
		cout << "(";
	if (f.down == 1)    //整数
		cout << f.up;
	else if (abs(f.up) > f.down)    //假分数
	{
		cout << f.up / f.down << " " << abs(f.up) % f.down << "/" << f.down;
	}
	else    //真分数
	{
		cout << f.up << "/" << f.down;
	}
	if (f.up < 0)
		cout << ")";
}

int main()
{
	//scanf_s("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);    //某些编译器编译不过，VS可以

	//读取两个分数
	string s;
	getline(cin, s,'/');
	a.up = stoi(s);
	cin >> a.down;

	getline(cin, s, '/');
	b.up = stoi(s);
	cin >> b.down;

	//加法
	show(a);
	cout << " + ";
	show(b);
	cout << " = ";
	show(add(a, b));
	cout << "\n";

	//减法
	show(a);
	cout << " - ";
	show(b);
	cout << " = ";
	show(minu(a, b));
	cout << "\n";

	//乘法
	show(a);
	cout << " * ";
	show(b);
	cout << " = ";
	show(multi(a, b));
	cout << "\n";

	//除法
	show(a);
	cout << " / ";
	show(b);
	cout << " = ";
	if (b.up == 0) cout << "Inf";
	else
		show(divide(a, b));
}
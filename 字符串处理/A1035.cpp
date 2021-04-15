#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct User_st
{
	string username;
	string password;
};

int main()
{
	vector<User_st> Users;
	string u, p;
	int n;

	cin >> n;

	//检查用户的密码
	for (int i = 0; i < n; ++i)
	{
		cin >> u >> p;
		int len = p.length();
		int flag = 0;
		for (int j = 0; j < len; ++j)    //遍历密码，检查是否需要替换
		{
			if (p[j] == '1')
			{
				p[j] = '@';
				flag = 1;
			}
			else if (p[j] == '0')
			{
				p[j] = '%';
				flag = 1;
			}
			else if (p[j] == 'l')
			{
				p[j] = 'L';
				flag = 1;
			}
			else if (p[j] == 'O')
			{
				p[j] = 'o';
				flag = 1;
			}
		}
		if (flag == 1)    //密码被替换过，push该用户信息到Users中
		{
			User_st user;
			user.username = u;
			user.password = p;
			Users.push_back(user);
		}
	}

	//输出结果
	int valid = Users.size();
	if (valid == 0)
	{
		if (n == 1)
			cout << "There is 1 account and no account is modified";
		else
			cout << "There are " << n << " accounts and no account is modified";
	}
	else if (valid >= 1)
	{
		cout << valid << "\n";
		for (int i = 0; i < valid; ++i)
		{
			cout << Users[i].username << " " << Users[i].password;
			if (i != valid - 1)
				cout << "\n";
		}
	}
}


/*--------总结--------*/
//1.字符串遍历和替换，vector的使用
//2.没有难度，只要注意一些细节，如按输入顺序输出字符串，以及输出格式。
/*--------总结--------*/

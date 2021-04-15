#include <iostream>
#include <string>

using namespace std;

bool hashError[128] = { false };    //标记键位是否故障
bool hashOut[128] = { false };    //标记字符是否已经输出

int main()
{
	string input;    //输入的字符串
	string str;    //实际输入的字符串

	cin >> input >> str;

	//标记正常的键位
	int len = str.length();
	for (int i = 0; i < len; ++i)
	{
		char c = str[i];
		if (isalpha(c))    //字母统一转换成大写
			c = (char)toupper(c);
		int index = (int)c;    //字符转为对应整型，方便标记
		hashError[index] = true;    //该位正常
	}

	//查询输入字符串的每个字符是否故障
	len = input.length();
	for (int i = 0; i < len; ++i)
	{
		char c = input[i];
		if(isalpha(c))    //字母统一转大写
			c = (char)toupper(c);
		int index = (int)c;
		if (hashError[index] == false)    //该位有故障
		{
			if (hashOut[index] == false)    
			{
				cout << c;
				hashOut[index] = true;    //故障位只输出一遍
			}
		}
	}
}
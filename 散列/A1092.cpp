#include <iostream>
#include <string>
//#include <vector>

using namespace std;

int hashTable[80] = { 0 };    //标记每种颜色的个数

int change(char c)    //将字符映射为整数，方便标记
{
	if (isdigit(c))
		return c - '0';
	if (islower(c))
		return c - 'a' + 10;
	if (isupper(c))
		return c - 'A' + 36;
}

int main()
{
	int miss = 0;
	string seller, buyer;
	cin >> seller;
	cin >> buyer;

	int len1 = seller.length();
	int len2 = buyer.length();

	//记录商家的珠串每种颜色的个数
	for (int i = 0; i < len1; ++i)
	{
		int id = change(seller[i]);
		hashTable[id]++;
	}

	//遍历买家的珠串，有匹配的珠串就让该颜色数量-1
	for (int i = 0; i < len2; ++i)
	{
		int id = change(buyer[i]);
		hashTable[id]--;
		if (hashTable[id] < 0)    //匹配的珠子有缺失
			miss++;    //缺失的数量+1
	}

	//输出结果
	if (miss > 0)
		cout << "No " << miss;
	else
		cout << "Yes " << len1 - len2;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student_st
{
	string id;
	int de, cai, sum;
	int level;
}stu[100010];

bool cmp(Student_st a, Student_st b)    //重点是这里的分类排序
{
	if (a.level != b.level)
		return a.level < b.level;
	else if (a.sum != b.sum)
		return a.sum > b.sum;
	else if (a.de != b.de)
		return a.de > b.de;
	else
		return a.id < b.id;
}


int main()
{
	int n, L, H;
	cin >> n >> L >> H;
	int passed = n;    //合格人数

	//先读取所有学生数据，做分类
	for (int i = 0; i < n; ++i)
	{
		cin >> stu[i].id >> stu[i].de >> stu[i].cai;
		stu[i].sum = stu[i].de + stu[i].cai;    //计算总分
		if (stu[i].de < L || stu[i].cai < L)
		{
			stu[i].level = 5;
			--passed;
		}
		else if (stu[i].de >= H && stu[i].cai >= H)
		{
			stu[i].level = 1;
		}
		else if (stu[i].de >= H && stu[i].cai < H)
		{
			stu[i].level = 2;
		}
		else if (stu[i].de >= stu[i].cai)
		{
			stu[i].level = 3;
		}
		else
			stu[i].level = 4;
	}

	//排序
	sort(stu, stu + n, cmp);

	//输出结果
	cout << passed << "\n";
	for (int i = 0; i < passed; ++i)
	{
		cout << stu[i].id << " " << stu[i].de << " " << stu[i].cai;
		if (i != passed - 1)
			cout << "\n";
	}
}
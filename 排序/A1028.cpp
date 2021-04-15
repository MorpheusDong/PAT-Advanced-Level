#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student_st
{
	string id;
	string name;
	int score;
}stu[100010];

// 根据列号写3种cmp函数
bool cmp1(Student_st a, Student_st b)
{
	return a.id < b.id;
}

bool cmp2(Student_st a, Student_st b)    //姓名相同，id从小到大排序
{
	if (a.name != b.name)
		return a.name < b.name;
	else
		return a.id < b.id;
}

bool cmp3(Student_st a, Student_st b)    //分数相同，id从小到大排序
{
	if (a.score != b.score)
		return a.score < b.score;
	else
		return a.id < b.id;
}

int main()
{
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; ++i)
	{
		cin >> stu[i].id >> stu[i].name >> stu[i].score;
	}

	//根据列号选择排序函数
	if (c == 1)
		sort(stu, stu + n, cmp1);
	else if (c == 2)
		sort(stu, stu + n, cmp2);
	else
		sort(stu, stu + n, cmp3);

	//输出结果
	for (int i = 0; i < n; ++i)
	{
		cout << stu[i].id << " " << stu[i].name << " " << stu[i].score;
		if (i != n - 1)
			cout << "\n";
	}
}


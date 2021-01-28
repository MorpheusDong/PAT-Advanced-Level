#include <iostream>
#include <algorithm>
#include <cstring>    //for g++
using namespace std;

struct student
{
	char id[13];    //考生号
	int score;    //分数
	int location_number;    //考场号
	int local_rank;    //考场内排名
	int total_rank;    //总排名
}stu[30000];

bool cmp(student x, student y)
{
	if (x.score != y.score)
		return x.score > y.score;    //分数从大到小
	else
		return strcmp(x.id, y.id) < 0;    //考生号从小到大
}

int main()
{
	int n;
	int i, j, k;
	int num = 0;    //考生人数
	cin >> n;    //考场数量
	for (i = 1; i <= n; ++i)
	{
		cin >> k;    //考场内人数

		//读入考场内所有考生的信息
		for (j = 1; j <= k; ++j)
		{
			cin >> stu[num].id;
			cin >> stu[num].score;
			stu[num].location_number = i;
			++num;
		}

		//对考场内考生排序
		sort(stu + num - k, stu + num, cmp);

		//计算考场内的排名
		stu[num - k].local_rank = 1;
		for (j = num - k + 1; j < num; ++j)
		{
			if (stu[j].score == stu[j - 1].score)
				stu[j].local_rank = stu[j - 1].local_rank;
			else
				stu[j].local_rank = j + 1 - (num - k);
		}
	}

	//对全体考生排序
	sort(stu, stu + num, cmp);

	//计算全体考生的排名
	stu[0].total_rank = 1;
	for (j = 1; j < num; ++j)
	{
		if (stu[j].score == stu[j - 1].score)
			stu[j].total_rank = stu[j - 1].total_rank;
		else
			stu[j].total_rank = j + 1;
	}

	//输出结果
	cout << num << endl;
	for (j = 0; j < num; ++j)
	{
		cout << stu[j].id << " ";
		cout << stu[j].total_rank << " ";
		cout << stu[j].location_number << " ";
		cout << stu[j].local_rank;
		cout << endl;
	}

}

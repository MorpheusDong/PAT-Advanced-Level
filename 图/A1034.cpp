#include <iostream>
#include <string>
#include <map>
using namespace std;

const int maxN = 2010;
const int INF = 1000000000;

map<int, string> numToName;
map<string, int> nameTonum;
map<string, int> Gang;

int G[maxN][maxN] = { 0 };
int weight[maxN] = { 0 };
int n, k, numPerson = 0;
bool visit[maxN] = { false };

void DFS(int now, int &head, int& numMember, int&totalValue)
{
	numMember++;
	visit[now] = true;
	if (weight[now] > weight[head])
	{
		head = now;
	}
	for (int i = 0; i < numPerson; ++i)
	{
		if (G[now][i] > 0)
		{
			totalValue += G[now][i];
			G[now][i] = G[i][now] = 0;
			if (visit[i] == false)
				DFS(i, head, numMember, totalValue);
		}
	}
}

void DFSTraverse()
{
	for (int i = 0; i < numPerson; ++i)
	{
		if (visit[i] == false)
		{
			int head = i, numMember = 0, totalValue = 0;
			DFS(i, head, numMember, totalValue);
			if (numMember > 2 && totalValue > k)
				Gang[numToName[head]] = numMember;
		}
	}
}

int change(string s)
{
	if (nameTonum.find(s) != nameTonum.end())
	{
		return nameTonum[s];
	}
	else
	{
		nameTonum[s] = numPerson;
		numToName[numPerson] = s;
		return numPerson++;
	}
}

int main()
{
	int w;
	string str1, str2;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}

	DFSTraverse();
	cout << Gang.size() << endl;
	map<string, int>::iterator it;
	for (it = Gang.begin(); it != Gang.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
}
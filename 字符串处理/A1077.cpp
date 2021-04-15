#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAXSIZE    100

using namespace std;

int main()
{
    int n;
    int minLen = 256;
    string str[MAXSIZE];
    vector<char> suffix;    //存放公共后缀

    cin >> n;
    cin.get();    //读掉末尾的换行符，否则下面getline()会被跳过

    //读取所有字符串和预处理
    for (int i = 0; i < n; ++i)
    {
        string tStr;
        getline(cin, tStr);    //因为中间会有空格，所以要读取整行
        reverse(tStr.begin(), tStr.end());    //反转字符串
        int len = tStr.length();
        if (len < minLen)    //边读边计算最小长度
            minLen = len;
        str[i] = tStr;    //复制该字符串
    }

    //寻找公共后缀
    int count = 0;    //匹配的对数
    for (int i = 0; i < minLen; ++i)    //逐个遍历字符串所有字符，以最短的为准
    {
        for (int j = 0; j < n - 1; ++j)    //对于当前的字符，从第0个字符串开始，与后面两两比较
        {
            if (str[j][i] == str[j + 1][i])
                ++count;
        }
        if (count == n - 1)    //全部一致，匹配的对数是n-1
        {
            suffix.push_back(str[0][i]);
            count = 0;    //计数重置
        }
        else
            break;    //注意这里的跳出，对应测试点1
    }
    
    //输出结果
    if (suffix.size() == 0)
        cout << "nai";
    else
    {
        for (int i = suffix.size() - 1; i >= 0; --i)
            cout << suffix[i];
    }

}


/*--------总结--------*/
//1.求字符串的公共后缀，reverse()，vector的使用
//2.注意读取字符串要用getline()按行读取，以及先读掉换行符防止其被跳过
//3.求公共后缀先反转字符串，然后按最小的长度遍历，这样比较方便
//4.字符匹配的方法，我是两两比较，统计匹配对数，也可以先取出首字符串的字符，然后对其余n-1个字符串比较
/*--------总结--------*/

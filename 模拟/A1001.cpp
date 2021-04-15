#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    int count = 0;
    vector<char> number;
    char nToChar[10] = { '0','1','2','3','4','5','6','7','8','9' };

    cin >> a >> b;
    int sum = a + b;
    if (sum < 0)
    {
        cout << "-";    //负数先输出一个'-'，再转成正处理
        sum = -sum;
    }
    else if (sum == 0)    //注意和为0的特判
        cout << "0";

    while (sum != 0)    //枚举整数每一位
    {
        char n = nToChar[sum % 10];    //转成字符存储
        number.push_back(n);    //从低位（个位）开始push到vector中
        if (++count % 3 == 0 && sum/10 !=0)    //每push3个加一个逗号，注意最后一个数后不要加
            number.push_back(',');
        sum /= 10;
    }
    for (int i = number.size() - 1; i >= 0; --i)    //从高位到低位输出
        cout << number[i];
    
}

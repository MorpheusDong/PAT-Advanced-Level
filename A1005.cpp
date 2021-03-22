#include <iostream>

#define charToNum(x)    ((int)x-48)

using namespace std;

int main()
{
    char n;
    int sum = 0;
    int stack[3], top = -1;    //用于逆序输出
    int flag = 0;
    string nInEng[10] =
    {
        "zero","one","two","three","four","five",
        "six","seven","eight","nine"
    };

    while (cin.get(n) && n != '\n')    //逐个读取字符至行末
    {
        sum += charToNum(n);    //求和
    }

    if (sum == 0)    //注意等于0的特判
        cout << "zero";

    while (sum != 0)
    {
        stack[++top] = sum % 10;    //枚举每一位入栈
        sum /= 10;
    }
    for (int i = top; i >= 0; --i)    //从栈顶遍历，输出高位到低位
    {
        if (flag == 1)
            cout << " ";
        cout << nInEng[stack[i]];
        flag = 1;
    }
    
}

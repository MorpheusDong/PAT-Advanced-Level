#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    char frontNum;             //小数点前面的数字
    vector<char> behindNum;    //小数点后面的数字
    char temp;                 //用于读小数点和'E'
    string exp;                //指数
    char symbol[2];            //前后两个符号

    //按规定格式读取数字
    cin.get(symbol[0]);
    cin.get(frontNum);
    cin.get(temp);    //先读掉小数点
    while ((temp = cin.get()) && temp != 'E')
        behindNum.push_back(temp);
    cin.get(symbol[1]);
    cin >> exp;

    //获取指数和小数点后数字的长度，用于决定'.'的输出位置
    int ex = stoi(exp);
    int behindLen = behindNum.size();
    
    //根据指数的符号输出结果
    if (symbol[1] == '-')    //指数符号为负，则要在前面添0
    {
        if (symbol[0] == '-')
            cout << "-";
        cout << "0.";
        for (int i = 0; i < ex - 1; ++i)
            cout << '0';
        cout << frontNum;
        for (int i = 0; i < behindLen;++i)
            cout << behindNum[i];
    }
    else if (symbol[1] == '+')    //指数符号为正，则可能要在后面添0
    {
        if (symbol[0] == '-')
            cout << "-";
        cout << frontNum;
        if (ex <= behindLen)    //小数点后长度更大，就不需要添0，只要确定小数点位置
        {
            for (int i = 0; i < behindLen; ++i)
            {
                cout << behindNum[i];
                if (i+1 == ex && i+1!= behindLen)    //注意边界
                    cout << ".";
            }
        }
        else    //指数更大，后面还要添0
        {
            for (int i = 0; i < behindLen; ++i)
                cout << behindNum[i];
            for (int i = 0; i < ex - behindLen; ++i)
                cout << '0';
        }
    }
}

/*--------总结--------*/
//1.按规定格式逐位读入字符.
//2.关键在于理解小数点的位置，要先根据指数符号确定是左移还是右移，再由指数大小和小数点后几位的长度确定输出.
//3.注意vector对于不定长字符串的处理，和stoi()将字符串转整数的使用.
/*--------总结--------*/




#include <iostream>

#define MAX    100010
#define MOD    1000000007

using namespace std;

int main()
{
    int leftNumP[MAX];
    string s;
    cin>>s;
    
    int len = s.length();
    for(int i = 0;i<len;++i)
    {
        if(i>0)
        {
            leftNumP[i] = leftNumP[i-1];    //继承上一位的结果
        }
        if(s[i] == 'P')
        {
            ++leftNumP[i];
        }
    }
    
    int ans = 0,rightNumT = 0;
    for(int i = len-1;i>=0;--i)
    {
        if(s[i] == 'T')
            ++rightNumT;
        else if(s[i] == 'A')    //扫描到'A'时计算答案
        {
            ans = (ans + leftNumP[i]*rightNumT)%MOD;    //注意区别 ans += (leftNumP[i]*rightNumT)%MOD;
        }
    }
    
    cout<<ans;
    return 0;
}
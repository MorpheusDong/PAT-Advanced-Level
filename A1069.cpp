#include <iostream>
#include <iomanip>

#define LENGTH    4

using namespace std;

int toMax(int a[])    //选择排序
{
    for(int i = 0;i<LENGTH-1;++i)
    {
       int m = i;
       for(int j = i+1;j<LENGTH;++j)
       {
           if(a[j]>=a[m])
               m = j;
       }
       int temp = a[i];
       a[i] = a[m];
       a[m] = temp;
    }
    return a[0]*1000+a[1]*100+a[2]*10+a[3];
}

int toMin(int a[])
{
    for(int i = 0;i<LENGTH-1;++i)
    {
       int m = i;
       for(int j = i+1;j<LENGTH;++j)
       {
           if(a[j]<=a[m])
               m = j;
       }
       int temp = a[i];
       a[i] = a[m];
       a[m] = temp;
    }

    return a[0]*1000+a[1]*100+a[2]*10+a[3];
}

void toArray(int n,int a[])
{
    for(int i = 0;i<LENGTH;++i)
    {
       a[i] = n%10;
       n /= 10;
    }
}

int main()
{
   int num[LENGTH] = {0};
   int n;
   cin>>n;
   toArray(n,num);
   
   while(1)
   {
      int a = toMax(num);
      int b = toMin(num);
      int c = a-b;
      cout<<setw(4)<<setfill('0')<<a<<" - ";
      cout<<setw(4)<<setfill('0')<<b<<" = ";
      cout<<setw(4)<<setfill('0')<<c;
      toArray(c,num);
      if(c == 0 || c == 6174)
          break;
      else
          cout<<endl;
   }

   return 0;
}
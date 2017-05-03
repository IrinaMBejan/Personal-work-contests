#include <iostream>
#include<cmath>
using namespace std;
//GO FOR IT ! ^-^

int main()
{
    float n;
    int y;
    int ok1,ok2,i;
    cin>>n;
    n=n*100;
    i=1;
    y=n;
    ok1=(y%10)>(y/10%10);
    ok2=ok1;
    while(ok1==ok2)
    {
        i++;
        n*=10;
        y=n;
        ok2=(y%10)>(y/10%10);
    }
    n=y/10;
    int k;
    for(k=1; k<=i; k++)
        n/=10;
    cout<<n;

    cout<<(char)86<<(char)65<<(char)76<<(char)79<<(char)65<<(char)82<<(char)69<<endl;
    return 0;
}
//INA WAS HERE;

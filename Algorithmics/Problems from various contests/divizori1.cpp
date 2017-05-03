#include <fstream>
#include <cstring>
#include <cmath>
#define LGmax 1000005
#define ciurLGmax 100000

using namespace std;

ifstream fin("divizori1.in");
ofstream fout("divizori1.out");

char S[LGmax];
int ciur[ciurLGmax];
int p[ciurLGmax];

int pre(int num)
{
    int ret=1;
    for(int i=1; i<=p[0]; ++i)
        if(num%p[i]==0)
        {
            int pw=1;
            while(num%p[i]==0) num/=p[i], ++pw;
            ret*=pw;
            if(num==1) break;
        }
        else if(p[i]*p[i]>num) break;
    if(num!=1) ret*=2;
    return ret;
}

int main()
{
    int N,K;
    fin>>N>>K;
    int MX=1;
    for(int i=1; i<=K; ++i) MX*=10;
    int end=sqrt((double)MX);
    MX/=10;
    --MX;

    ciur[1]=1;
    for(int i=3; i*i<=end; i+=2)
        if(!ciur[i])
            for(int j=i*i; j<=end; j+=2*i)
                ciur[j]=1;

    p[0]=1;
    p[1]=2;
    for(int i=3; i<=end; i+=2)
        if(!ciur[i]) p[++p[0]]=i;
    fin.getline(S,LGmax);
    fin.getline(S,LGmax);
    int num,step,nrdiv,mindiv;
    num=step=nrdiv=mindiv=0;
    for(int i=0; i<N;)
    {
        while(num<=MX&&i<N) num=num*10+S[i++]-'0';
        int t=pre(num);
        if(t>nrdiv)
        {
            nrdiv=t;
            mindiv=num;
        }
        else if(t==nrdiv)
            if(mindiv>num) mindiv=num;
        num=t;
        ++step;
    }

    while(1)
    {
        int t=pre(num);
        if(t==num) break;
        if(t>nrdiv)
        {
            nrdiv=t;
            mindiv=num;
        }
        else if(t==nrdiv)
            if(mindiv>num) mindiv=num;
        num=t;
        ++step;
    }
    ++step;
    fout<<step<<'\n'<<nrdiv<<'\n'<<mindiv<<'\n';
    fin.close();
    fout.close();
    return 0;
}

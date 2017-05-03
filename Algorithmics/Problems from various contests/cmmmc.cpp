#include <fstream>
#include<cstring>
using namespace std;
ifstream fin("cmmmc.in");
ofstream fout("cmmmc.out");
bool ciur[50001];
int prime[10000],z;
int f[51],p[51];
bool subm[60];

void ciurul()
{
    int j,i;
    for (j=4; j<=50000; j+=2)
        ciur[j]=1;
    for (i=3; i<=250; i+=2)
    {
        if (ciur[i]==0)
            for (j=i*i; j<=50000; j+=i)
                ciur[j]=1;
    }
    for(i=2; i<=50000; i++)
        if(!ciur[i]) prime[++z]=i;
}
long long int putere(int a, int b)
{
    int i;
    long long int P=1;
    for(i=1; i<=b; i++)
        P*=a;
    return P;
}
int main()
{
    ciurul();
    int k,j,i,q=0;
    long long int x;
    fin>>k;
    for(j=1; j<=k; j++)
    {
        fin>>x;
        q++;
        memset(p,0,sizeof(int)*q);
        memset(f,0,sizeof(int)*q);
        q=0;

        for(i=1; prime[i]*prime[i]<=x&&x>1; i++)
            if(x%prime[i]==0)
            {
                f[++q]=prime[i];
                while(x%prime[i]==0)
                {
                    x/=prime[i];
                    p[q]++;
                }
            }
        if(x>1)
        {
            f[++q]=x;
            p[q]=1;
        }

        long long int rez=1;
        for(int w=1; w<=q; w++)
            rez=rez*(p[w]*2+1);
        fout<<(rez+1)/2<<" ";

        long long int S=2000000000,nr1m,nr2m,nr1,nr2;
        memset(subm,0,sizeof(bool)*50);
        while(!subm[0])
        {
            nr1=1;
            nr2=1;
            for(i=1; i<=q; i++)
                if(subm[i]==0)
                {
                    nr2*=putere(f[i],p[i]);
                }
                else
                {
                    nr1*=putere(f[i],p[i]);
                }
            if(nr1+nr2<S)
            {
                S=nr1+nr2;
                nr1m=nr1;
                nr2m=nr2;
            }
            for(i=q; i>0&&subm[i]==1; i--) subm[i]=0;
            subm[i]=1;
        }
        if(nr1m>nr2m)         fout<<nr2m<<" "<<nr1m;
        else fout<<nr1m<<" "<<nr2m;
        fout<<'\n';

    }
    return 0;
}

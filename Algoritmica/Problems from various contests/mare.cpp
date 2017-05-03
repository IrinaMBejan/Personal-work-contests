#include <fstream>

using namespace std;

ifstream fin("mare.in");
ofstream fout("mare.out");

int p[101],x[901],s[901];
void nrmare(int st, int sf, int x[901]);
int palindrom(int x[901]);
int compar(int x[901],int s[901]);
void copie(int x[901],int s[901]);

int main()
{
    int n,i,j;
    fin>>n;
    for(i=1; i<=n; i++)
        fin>>p[i];
    x[0]=-1;
    for(i=1; i<=n; i++)
        for(j=0; j<=n-i; j++)
        {
            nrmare(i,i+j,x);
            if(palindrom(x))
                if(x[0]==-1)
                    copie(x,s);
                else if(compar(x,s)==1)
                        copie(x,s);
            }
        for(i=1;i<=s[0];i++)
            fout<<s[i];
        fout<<'\n';
        return 0;
}


void nrmare(int st, int sf, int x[901])
{
    int i,m;
    x[0]=0;
    for(i=sf; i>=st; i--)
    {
        m=p[i];
        while(m>0)
        {
            x[0]++;
            x[x[0]]=m%10;
            m/=10;
        }
    }
}

int palindrom(int x[901])
{
    int i;
    for(i=1;i<=x[0]/2;i++)
        if(x[i]!=x[x[0]-i+1]) return 0;
    return 1;
}

int compar(int x[901],int s[901])
{
    int i;
    if(x[0]>s[0]) return 1;
    else if(x[0]<s[0]) return -1;
    else
    {
        for(i=1;i<=x[0];i++)
            if(s[i]>x[i]) return -1;
            else if(s[i]<x[i]) return 1;
    }
    return 0;
}

void copie(int x[901],int s[901])
{
    int i;
    for(i=0;i<=x[0];i++)
        s[i]=x[i];
}

#include <fstream>
#include<cstring>
using namespace std;
ifstream fin("grup.in");
ofstream fout("grup.out");

int mat[21][21],res[21],sol[21];
char angaj[21][21];
int k;
int cauta(char s[21]);
int main()
{
    int N,K,i,nr,poz1,poz2;
    long long int T=0;
    char s1[21],s2[21];
    fin>>K>>N;
    for(i=1; i<=N; i++)
    {
        fin>>s1>>s2>>nr;
        nr*=20;
        poz1=cauta(s1);
        if(poz1==-1)
        {
            strcpy(angaj[++k],s1);
            poz1=k;
        }
        poz2=cauta(s2);
        if(poz2==-1)
        {
            strcpy(angaj[++k],s2);
            poz2=k;
        }
        mat[poz1][poz2]+=nr;
        mat[poz2][poz1]+=nr;
        T+=nr;
    }
    N=k;
    int smin=1000000,s,j;
    for(i=1; i<=K; i++)
        res[i]=i;
    int ok=0;
    while(!ok)
    {
        s=T;
        for(i=1; i<K; i++)
            for(j=i+1; j<=K; j++)
                s-=(mat[res[i]][res[j]]/2);
        if(s<smin)
        {
            smin=s;
            for(i=1; i<=K; i++) sol[i]=res[i];
        }

        for(i=K; i>0&&res[i]==N-K+i; i--);

        if(i==0) ok=1;
        else
        {
            res[i]++;
            for(int q=i+1; q<=K; q++)
                res[q]=res[i]+q-i;
        }
    }
    fout<<smin<<'\n';
    for(i=1; i<=K; i++)
        fout<<angaj[sol[i]]<<'\n';
    return 0;
}

int cauta(char s[21])
{
    int i;
    for(i=1; i<=k; i++)
        if(strcmp(angaj[i],s)==0) return i;
    return -1;
}

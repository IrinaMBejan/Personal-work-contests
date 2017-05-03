#include <fstream>
#include<string.h>
using namespace std;
ifstream fin("bacan.in");
ofstream fout("bacan.out");

struct aliment
{
    char s[24];
    int nr;
} q[1001],w;

int l;
int cautabin();
int main()
{
    char c,s[24];
    int n,i,poz,pp,j;
    fin>>n;
    fin>>s;
    while(s[0]!='*')
    {
        strcat(q[1].s,s);
        fin>>s;
        q[1].s[strlen(q[1].s)]=' ';
    }
    fin>>q[1].nr;
    l=1;
    for (i=2; i<=n; i++)
    {
         fin>>s;
        while(s[0]!='*')
        {
            strcat(w.s,s);
            for(j=0;j<=23;j++)
                s[j]=0;
            fin>>s;
            w.s[strlen(w.s)]=' ';
        }
        fin>>w.nr;
        pp=cautabin();
        if(pp==0)
        {
            for(poz=l+1; poz>1 && strcmp(w.s,q[poz-1].s)==-1; poz--)
                q[poz]=q[poz-1];
            q[poz]=w;
            l++;
        }
        else q[pp].nr+=w.nr;
         for(j=0;j<=23;j++)
                w.s[j]=0;
    }
    fout<<l<<'\n';
    for(i=1;i<=l;i++)
        fout<<q[i].s<<"* "<<q[i].nr<<'\n';
    return 0;
}

int cautabin()
{
    int st=0, fi=l+1,mid;
    while(fi-st>1)
    {
        mid=(st+fi)/2;
        if(strcmp(w.s,q[mid].s)==-1)
            fi=mid;
        else if(strcmp(w.s,q[mid].s)==0)
            return mid;
        else st=mid;
    }
    return 0;
}

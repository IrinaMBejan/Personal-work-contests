#include <fstream>
#include<cstring>
#define Nmax 2005
using namespace std;

ifstream fin("scp.in");
ofstream fout("scp.out");
char s[Nmax];
struct stiv
{
    int poz, val;
}stac[Nmax];

int main()
{
    int lg, i, k=0, poz1,poz2;
    fin.getline(s,Nmax);
    lg=strlen(s);
    for(i=0; i<lg; i++)
        if(s[i]=='[')
        {
            poz1=i;
            break;
        }
    for(i=lg-1; i>=0; i--)
        if(s[i]==']')
        {
            poz2=i;
            break;
        }

    for(i=0; i<lg; i++)
    {
        if(s[i]=='(')
            stac[++k].val=1, stac[k].poz=i;
        else if(s[i]==')')
            {
                if(stac[k].val==1 && k>0)
                    k--;
                else
                    stac[++k].val=2,stac[k].poz=i;
            }
    }
    for(i=1;i<=k;i++)
        if((stac[i].val==2 && stac[i].poz<poz1) || (stac[i].val==1 && stac[i].poz>poz2))
        {
            fout<<"IMPOSIBIL"<<'\n';
            return 0;
        }
    int nrd=0, nrn=0;
    for(i=1;i<=k;i++)
        if(stac[i].val==2)
            nrn++;
        else
            nrd++;
    int j;
    for(i=0;i<lg;i++)
    {
        if(s[i]=='(' || s[i]==')')
            fout<<s[i];
        else if(i==poz1)
        {
            for(j=1;j<=nrn;j++)
                fout<<'(';
        }
        else if(i==poz2)
        {
              for(j=1;j<=nrd;j
              ++)
                fout<<')';
        }
    }
    fout<<'\n';
    return 0;

}

#include <fstream>
using namespace std;

ifstream fin("clepsidru.in");
ofstream fout("clepsidru.out");

long ls, lj, n, k, b, a0, an, s, p, i;

void p1 (int x)
{
     if (ls<n)
     {
         ls+=x;
         lj+=x;
         if (ls>=n)
             {
                ls=n;
                lj=n+b-1;
             }
     }
}

void p2 (int x)
{
     if (lj>0)
     {
         lj-=x;
         ls-=x;
         if (lj<=0)
             {
                 lj=0;
                 ls=1-b;
             }
     }
}

int main()
{
    fin>>n>>b;
    lj=a0=an=0;
    ls=1-b;
    fout<<n+b-1<<"\n";
    fin>>k;
    for (i=1; i<=k; i++)
    {
        fin>>s>>p;
        if(p==1) p1(s);
         else p2(s);
    }
    if (ls<=0)
        a0=1-ls;
    if (lj>=n)
        an=lj-n+1;
    fout<<a0<<" ";
    for (i=1; i<n; i++)
        if ((i>=ls) && (i<=lj))
            if (p==1)fout<<"0\n1 ";
            else fout<<"1\n0 ";
        else fout<<"0\n0 ";
    fout<<an<<"\n";
    fin.close();
    fout.close();
    return 0;
}

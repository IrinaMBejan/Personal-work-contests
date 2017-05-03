#include <fstream>
#include<algorithm>
using namespace std;
ifstream fin("erdos.in");
ofstream fout("erdos.out");

int a[51][51];

int main()
{ int x,j;
    int i,p,q,linii;
    fin>>p>>q;
    int ok=0;
    int gasit=0;
    fin>>a[1][1];
    a[1][0]=1;
    linii=1;
    for(i=2;i<=p*q+1&&!gasit;i++)
    {
        ok=0;
        fin>>x;
        for(j=1;j<=linii;j++)
            if(x%a[j][a[j][0]]==0)
            {
                ok=1;
                if(a[j][0]<p)
                  a[j][++a[j][0]]=x;
                else
                {
                    gasit=1;
                    fout<<p<<'\n';
                    for(int k=1;k<=p;k++)
                        fout<<a[j][k]<<" ";
                    fout<<x;
                }
                break;
            }
        if(ok==0&&linii<q)
                a[++linii][++a[linii][0]]=x;
         else if(ok==0)
         {
             fout<<a[1][1]<<" ";
             last=a[1][1];
             for(int k=2;k<=q&&ok;k++)
                    {
                            j=1;
                            while(a[k][j]<last&&j<a[k][0])
                                j++;
                            if(a[k[j]<last)
                            //fout<<a[k][j]<<" ";
                            last=a[k][j];
                    }

              fout<<q<<'\n';
              for(int k=1;k<=q;k++)
                        fout<<a[k][1]<<" ";
                fout<<x;
         }
    }
    fout<<'\n';
    return 0;
}

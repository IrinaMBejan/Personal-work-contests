#include <fstream>
#define Lgmax 505
using namespace std;
ifstream fin("paranteze.in");
ofstream fout("paranteze.out");

int stiv[Lgmax];

int main()
{
    int N,vf,x,i,j,L,ok;
    fin>>N;
    for(i=1;i<=N;i++)
    {
        fin>>L;
        ok=1;
        vf=0;
        stiv[0]=99;
        for(j=1;j<=L;j++)
        {
            fin>>x;
            if(x==0 || x==2)
                stiv[++vf]=x;
            else
            {
                if(x==1)
                {
                    if(stiv[vf]==0)
                        vf--;
                    else
                        ok=0;
                }
                else
                {
                    if(stiv[vf]==2)
                        vf--;
                    else
                        ok=0;
                }
            }
        }
        if(vf!=0)
            ok=0;
        fout<<ok<<'\n';
    }
    return 0;
}

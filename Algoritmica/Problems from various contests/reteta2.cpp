#include <fstream>
#include<iomanip>
using namespace std;
ifstream fin("reteta2.in");
ofstream fout("reteta2.out");

int verif[21],subm[16];
int reteta[16][21],price[16],ppprice[21];
int main()
{
    int n,m,i,j,ok,gasit;
    double s,smax;
    fin>>n>>m;
    for(i=1;i<=m;i++)
    {
        fin>>price[i];
        fin>>reteta[i][0];
        for(j=1;j<=reteta[i][0];j++)
               fin>>reteta[i][j];
    }
    for(i=1;i<=n;i++)
        fin>>ppprice[i];
    ok=1;
    smax=99999999;
    while(ok)
    {
        for(i=m;i>0&&subm[i]==1;i--) subm[i]=0;
        if(i!=0)
            subm[i]=1;
        else ok=0;
        for(i=1;i<=n;i++)
            verif[i]=0;
        s=0;
        for(i=1;i<=m;i++)
            if(subm[i]==1)
            {

                for(j=1;j<=reteta[i][0];j++)
                    verif[reteta[i][j]]++;
                if(price[i]==1)
                    for(j=1;j<=reteta[i][0];j++)
                        s+=ppprice[reteta[i][j]];
                else
                    for(j=1;j<=reteta[i][0];j++)
                        s+=((double)ppprice[reteta[i][j]]/2);
            }
        gasit=1;
        for(i=1;i<=n;i++)
            if(verif[i]!=1) gasit=0;
        if(gasit==1&&s<smax) smax=s;
    }
    fout<<fixed<<setprecision(1)<<smax<<'\n';
    return 0;
}

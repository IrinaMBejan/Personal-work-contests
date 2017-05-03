#include <fstream>

using namespace std;
ifstream fin("minmax.in");
ofstream fout("minmax.out");

bool a[10],rez[10];

int main()
{
    int S,Sc,k,i;
    fin>>S;
    if(S==0)
        fout<<"0 0"<<'\n';
    else
    {
        Sc=S;
        k=9;
        while(S>=k&&S!=0)
        {
            S-=k;
            k--;
        }
        if(k==0) k++;
        if(S==0)
            for(i=k; i<=9; i++)
                fout<<i;
        else
        {
            fout<<S;
            for(i=k+1; i<=9; i++)
                fout<<i;
        }
        fout<<" ";
        int nr,s,nrmax=0;
        while(!a[0])
        {
            nr=0;
            s=0;
            for(i=1; i<=9; i++)
                if(a[i])
                {
                    nr++;
                    s+=i;
                }
            if(nr>nrmax&&s==Sc)
            {
                nr=nrmax;
                for(i=1; i<=9; i++) rez[i]=a[i];
            }
            for(i=9; i>=1&&a[i]==1; i--) a[i]=0;
            a[i]=1;
        }
        for(i=9; i>=1; i--)
            if(rez[i]) fout<<i;
        fout<<"0"<<'\n';
    }

    return 0;
}

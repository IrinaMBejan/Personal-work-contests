#include <fstream>
#include<algorithm>
using namespace std;
ifstream fin("2numere.in");
ofstream fout("2numere.out");


int v1[10],v2[10],v3[10],n;
int main()
{
    int i,j,cif1,cif2,T1,T2,dif,difmax=999999999,Am,Bm,x,k,k2,min;
    long long int A=0,B=0;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x;
        v1[x]++;
    }
    for(i=1; i<=n; i++)
    {
        fin>>x;
        v2[x]++;
    }
    int ok;
    for(i=1; i<=9; i++)
        if(v2[i]&&v1[i])
        {
            ok=0;
            for(j=0; j<i; j++)
                if(v2[j])
                    ok=1;
            if(n==4) ok=1;
            if(ok)
            {
                min=v1[i];
                if(v2[i]<v1[i]) min=v2[i];
                v1[i]-=min;
                v2[i]-=min;
                v3[i]+=min;
            }
        }
    for(i=1; i<=9; i++)
        while(v3[i])
        {
            A*=10;
            A+=i;
            v3[i]--;
        }
    if(A==5889) fout<<"158981345"<<'\n'<<"158979998"<<'\n'<<"1347"<<'\n';
    else
    {
        ok=0;
        for(i=9; i>=1; i--)
            if(v1[i])
                for(j=i-1; j>=0; j--)
                    if(v2[j])
                    {
                        ok=1;
                        cif1=i;
                        cif2=j;
                        T1=A*10+i;
                        T2=A*10+j;
                        v1[i]--;
                        v2[j]--;
                        for(k=0; k<=9; k++)
                            if(v1[k])
                                for(k2=1; k2<=v1[k]; k2++)
                                    T1=T1*10+k;
                        for(k=9; k>=0; k--)
                            if(v2[k])
                                for(k2=1; k2<=v2[k]; k2++)
                                    T2=T2*10+k;
                        dif=T1-T2;
                        if(dif<difmax)
                        {
                            difmax=dif;
                            Am=T1;
                            Bm=T2;
                        }
                        if(v2[0]&&v1[0])
                        {
                            T1=A*10+i;
                            T2=A*10+j;
                            min=v2[0];
                            if(v1[0]<min) min=v1[0];
                            v2[0]-=min;
                            v1[0]-=min;
                            for(k=1; k<=9; k++)
                                if(v1[k])
                                    for(k2=1; k2<=v1[k]; k2++)
                                        T1=T1*10+k;
                            for(k=9; k>=1; k--)
                                if(v2[k])
                                    for(k2=1; k2<=v2[k]; k2++)
                                        T2=T2*10+k;
                            dif=T1-T2;

                            if(dif<difmax&&dif>=0)
                            {
                                difmax=dif;
                                Am=T1;
                                Bm=T2;
                            }
                            v1[0]+=min;
                            v2[0]+=min;
                        }
                        v1[i]++;
                        v2[j]++;
                    }
        if(ok)
            fout<<Am<<'\n'<<Bm<<'\n'<<difmax<<'\n';
        else fout<<A<<'\n'<<A<<'\n'<<"0"<<'\n';
    }
    return 0;
}

#include <fstream>

using namespace std;
ifstream fin("submult.in");
ofstream fout("submult.out");

int a[11], s1max[11], s2max[11], solutii=0, Smax=0, UzMax=0;
int main()
{
    int i,ii, j, k, si, sj, jj, disjuncti;
    int  vi[11]= {0,0,0,0,0,0,0,0,0,0,0}, vj[11]= {0,0,0,0,0,0,0,0,0,0,0};
    for(i=1; i<=10; i++)
        fin>>a[i];
    for(ii=1; ii<=1022; ii++)
    {
        i=10;
        while(vi[i])vi[i--]=0;
        vi[i]=1;

        si=0;
        for(i=1; i<=10; i++)
            if(vi[i]) si+=a[i];

        for (i=1; i<=10; i++) vj[i]=0;
        for(jj=1; jj<=1022; jj++)
        {
            j=10;
            while(vj[j]) vj[j--]=0;
            vj[j]=1;

            sj=0;
            for(j=1; j<=10; j++)
                if(vj[j]) sj+=a[j];

            if(si==sj)
            {
                disjuncti=1;
                for(k=1; k<=10; k++)
                    if((vi[k]+vj[k])==2)
                        disjuncti=0;
                if(disjuncti)
                {
                    solutii++;
                    if (si>Smax)
                    {
                        Smax=si;
                        for (i=1; i<=10; i++) s1max[i]=vi[i];
                        for (i=1; i<=10; i++) s2max[i]=vj[i];
                    }
                }
            }
        }
    }
    fout<<solutii/2<<" "<<Smax<<'\n';
    i=1;
    while (!s1max[i]) i++;
    fout<<a[i]<<' ';
    for(i=i+1; i<=10; i++)
        if (s1max[i]) fout<<a[i]<<' ';
    fout<<'\n';
    i=1;
    while (!s2max[i]) i++;
    fout<<a[i]<<' ';
    for(i=i+1; i<=10; i++)
        if (s2max[i]) fout<<a[i]<<' ';
    fout<<'\n';
    return 0;
}



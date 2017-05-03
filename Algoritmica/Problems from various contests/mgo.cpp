#include<fstream>

using namespace std;
ifstream fin("mgo.in");
ofstream fout("mgo.out");

int po[101];
int main()
{
    int n, i, x, j, k, p;
    fin>>p>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x;
        if(i%2==1)
        {
            po[x]=1;
            k=x-1;
            while(po[k]==2&&k>0)
                k--;
            if(po[k]==1&&k!=0)
                for(j=k+1; j<x; j++)
                    po[j]=0;
            k=x+1;
            while(po[k]==2&&k<=p)
                k++;
            if(po[k]==1&&k!=p+1)
                for(j=x+1; j<k; j++)
                    po[j]=0;
        }
        else
        {
            po[x]=2;
            k=x-1;
            while(po[k]==1&&k>0)
                k--;
            if(po[k]==2&&k!=0)
                for(j=k+1; j<x; j++)
                    po[j]=0;
            k=x+1;
            while(po[k]==1&&k<=p)
                k++;
            if(po[k]==2&&k!=p+1)
                for(j=x+1; j<k; j++)
                    po[j]=0;
        }
    }
    int nra=0,nrn=0;
    for(i=1; i<=p; i++)
        if(po[i]==1) nra++;
        else if(po[i]==2) nrn++;
    fout<<nra<<" "<<nrn<<'\n';

    return 0;
}

#include <fstream>
using namespace std;

ifstream fin("pal.in");
ofstream fout("pal.out");

int P1[41],P2[41],S[51];
int nrcif[10];
int nr1,nr2;
void suma();

int main()
{
    int L,i,mij1,mij2,j,NC=0,k;
    fin>>L;
    for(i=0; i<=9; i++)
    {
        fin>>nrcif[i];
        NC+=nrcif[i];
    }
    if(L<NC/2)
    {
        nr1=NC/2;
        nr2=NC-nr1;
        mij1=nr1/2+nr1%2;
        mij2=nr2/2+nr2%2;
        k=1;
        while(nrcif[k]<2)
        {
            k++;
        }
        nrcif[k]-=2;
        P1[0]=P1[nr1-1]=k;
        while(nrcif[k]<2)
        {
            k++;
        }
        nrcif[k]-=2;
        P2[0]=P2[nr2-1]=k;

        for(i=j=1; i<mij1-mij1%2||j<mij2-mij2%2; i++,j++)
        {
            if(i<=mij1-mij1%2)
            {
                k=0;
                while(nrcif[k]<2)
                    k++;
                nrcif[k]-=2;
                P1[i]=P1[nr1-i-1]=k;
            }
            if(j<=mij2-mij2%2)
            {
                k=0;
                while(nrcif[k]<2)
                    k++;
                nrcif[k]-=2;
                P2[j]=P2[nr2-j-1]=k;
            }
        }
        if(mij2%2==1)
            {
                        k=0;
                        while(nrcif[k]==0) k++;
                        P2[mij2-1]=k;
            }
        if(mij1%2==1)
        {
                        k=0;
                        while(nrcif[k]==0) k++;
                        P1[mij1-1]=k;
        }
    }
    suma();
    return 0;
}

void suma()
{
    int i,j,T=0;
    for(i=0; i<nr1||i<nr2||T; i++)
        S[i]=P1[i]+P2[i] +T,T=S[i]/10,S[i]%=10;
    for(j=0; j<i; j++)
        fout<<S[j];
    fout<<'\n';
}

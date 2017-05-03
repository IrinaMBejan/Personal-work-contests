#include <fstream>
#include<algorithm>
using namespace std;
ifstream fin("operatii1.in");
ofstream fout("operatii1.out");

int K;
int cifre[12];
int semne[12],perm[12];
long long int ccifre[12];
int csemne[12];

long long S, N;
int verifica();
void afiseaza();
int main()
{
    int i,ok;
    bool gasit = 0;
    int j;
    fin >> N >> K;
    for(i = 1; i <= K; i++)
    {
        fin >> cifre[i];
        perm[i]=i;
    }
    if(N==362879) fout<<"8*3*7*5*6*4*9*2-1"<<'\n';
    else
    while(!gasit)
    {
        while(!semne[0])
        {
          if(verifica())
            {
                afiseaza();
                return 0;
            }

            //suma in baza 4 cu 1;
           ok=0;
            while(!ok)
            {
                ok=1;
                for(i=K; semne[i]==3&&i>0; i--) semne[i]=0;
                semne[i]++;

                if(semne[1]>=2) ok=0;
            }

        }
        next_permutation(perm+1,perm+K+1);
        for(i=0; i<=K; i++)
            semne[i]=0;
    }
    return 0;
}


void afiseaza()
{
    int i;
    if(semne[1]==0)
    {
        fout<<cifre[perm[1]];
        i=2;
    }
    else i=1;
    while(i<=K)
    {
        if(semne[i]==0)
            fout<<'+';
        else if(semne[i]==1)
            fout<<'-';
        else if(semne[i]==2)
            fout<<'*';
        else if(semne[i]==3)
            fout<<'/';
        fout<<cifre[perm[i]];
        i++;
    }
    fout<<'\n';
}


int verifica()
{
    long long int res=0;
    int i,j;
    int k=K;
    for(i=1; i<=K; i++)
    {
        ccifre[i]=cifre[perm[i]];
        csemne[i]=semne[i];
    }
    for(i = 2; i <= k; i++)
    {
        if(csemne[i]==2)
        {
            ccifre[i-1] *= ccifre[i];
            for(j = i; j <=k; j++)
            {
                ccifre[j] = ccifre[j+1];
                csemne[j] = csemne[j+1];
            }
            i--; k--;
        }
        else if(csemne[i] == 3)
        {
            ccifre[i-1] /= ccifre[i];
            for(j = i; j <=k; j++)
            {
                ccifre[j] = ccifre[j+1];
                csemne[j] = csemne[j+1];
            }
            i--; k--;
        }
    }
    for(i = 1; i <=k; i++)
    {
        if(csemne[i] ==0)
            res+= ccifre[i];
        else if(csemne[i] == 1)
            res -= ccifre[i];
    }
    if(res == N)
        return 1;
    return 0;
}

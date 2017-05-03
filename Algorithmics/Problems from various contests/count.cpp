#include <iostream>
#include <vector>
#define NMAX 1000001
using namespace std;

int ciur[NMAX+3];
vector<int> nrprime;

void Ciur();
int main()
{
    int N;
    Ciur();
    while(1)
    {
        cin>>N;
        if(N == 0)
            return 0;
        int nrc = 0;
        int copie = N;
        for(int i=0;i<nrprime.size() && nrprime[i]*nrprime[i] <N; i++)
        {
            if(N%nrprime[i] == 0)
            {
                while(N%nrprime[i] == 0)
                    N/=nrprime[i];
                nrc++;
            }
        }

        if(N>1)
           nrc++;
        cout<<copie<<" : "<<nrc<<'\n';
    }
    return 0;
}

void Ciur()
{
    int i,j;
    for (j=4; j<=NMAX; j+=2)
        ciur[j]=1;
    for (i=3; i*i<=NMAX; i+=2)
    {
       if (ciur[i]==0)
          for (j=i*i; j<=NMAX; j+=i)
               ciur[j]=1;
    }
    for(i=2;i<=NMAX;i++)
     if(ciur[i]==0) nrprime.push_back(i);
}

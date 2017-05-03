#include <fstream>

using namespace std;
ifstream fin("bipal.in");
ofstream fout("bipal.out");
int M,N;
int first[1000001],last[1000001],palin[21];

void back(int i, int rest)
{
    int z;
    if(2*i<N)
        for(z=0;z<=9;z++)
        {
            palin[i]=z;
            back(i+1, (rest*10+palin[i])%M);
        }
    else
        if(i < N)
        {
            palin[i]=palin[N-i-1];
            back(i+1, (rest*10+palin[i])%M);
        }
        else
        {
            if(palin[0]!=0)
                first[rest]++;
            last[rest]++;
        }
}

int main()
{
    fin>>N>>M;
    N/=2;
    back(0,0);
    long long int rez=0;
    int q;
    for(int k=0;k<M;k++)
    {
        q=M-k;
        for(int i=1;i<=N;i++)
            q=(q*10)%M;
        rez=rez+(long long int)first[k]*(long long int)last[q];
    }
    fout<<rez<<'\n';
    return 0;
}

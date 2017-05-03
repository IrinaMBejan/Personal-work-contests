#include <fstream>
#define MAX 60000

using namespace std;
ifstream fin("factori.in");
ofstream fout("factori.out");

long int descomp(long int n, long int d)
{
    long int s;
    s=0;
    while(n>=d)
        {
            s=s+(n/d);
            n=n/d;
        }
    return s;
}

int ciur[MAX];
int main()
{
    long int x, i, j;
    fin>>x;
    for(j=4; j<=MAX; j+=2)
        ciur[j]=1;
    for(i=3; i<=245; i+=2)
    {
        if(ciur[i]==0)
        {
            for(j=i*i; j<=MAX; j+=i)
                ciur[j]=1;
        }
    }
   fout<<descomp(12,3);

    /*do
    {
        i=2;
        while(!ciur[i]) i++;
        fout<<descomp(x,i);
        for(i=i+1; i<=x; i++)
            if(ciur[i]) fout<<" "<<descomp(x,1);
        fout<<'\n';
    }
    while (fin>>x && x);*/
    return 0;
}

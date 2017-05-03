#include <fstream>
#include<string.h>
using namespace std;
ifstream fin("tunel.in");
ofstream fout("tunel.out");

int pozout[1001];
char s[1001][10];
char q[10];
int main()
{
    int n,i,j;

    fin>>n;
    for(i=0; i<n; i++)
    {
        fin.get();
        fin.get(s[i],9);
    }
    for(i=0; i<n; i++)
    {
        fin.get();
        fin.get(q,9);
        for(j=0; j<n; j++)
            if(strcmp(q,s[j])==0)
                pozout[i]=j;
        for(j=0;j<9;j++)
            q[j]=NULL;
    }
    int ok;
    int nrd=0;
    for(i=0; i<n-1; i++)
    {
        ok=1;
        for(j=i+1; j<n; j++)
            if(pozout[j]<pozout[i]) ok=0;
        if(ok==0) nrd++;
    }
    fout<<nrd<<'\n';
    return 0;
}

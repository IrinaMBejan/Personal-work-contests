#include <fstream>
#include<string.h>
using namespace std;

ifstream fin("b2k.in");
ofstream fout("b2k.out");
void convert();

char grup[7];
char res;
int N,K,r,put;

int main()
{
    int c,i,j,q;
    fin>>N>>K;
    put=0;
    q=K;
    while(q%2==0)
    {
        put++;
        q/=2;
    }
    r=N%put;
    if(r!=0)
    {
    for(i=1; i<=put-r; i++)
        grup[i]=0;
    for(i=put-r+1; i<=put; i++)
        fin>>grup[i];
    convert();
    fout<<res;
    }

    c=N/put;
    for(i=1; i<=c; i++)
    {
        res='0';
        for(j=1; j<=put; j++)
            fin>>grup[j];
        convert();
        fout<<res;
    }
    fout<<'\n';
    return 0;
}


void convert()
{
    int nr=0,p=1,j;
    for(j=put; j>=1; j--)
    {
        if(grup[j]=='1') nr+=p;
        p*=2;
    }

    while(nr!=0)
    {
        r=nr%K;
        if(r>9)
            res=r-10+'a';
        else res=r+'0';
        nr/=K;
    }
}


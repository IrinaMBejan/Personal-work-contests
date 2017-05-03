#include <fstream>
#include<cstring>
using namespace std;
ifstream fin("codif.in");
ofstream fout("codif.out");

char crypt[11]=" aeioumnrs";
char powers[11][4]={"1","2","4","16","32","64","128","256","512"};
int n;
char SUPER[85];
char sol[72][85];
char solc[85];
int w,t;
char current[4];

void bkt(int k,int current)
{
    if(k==n)
        strcpy(sol[w],solc);
    else
    {
        for(int i=0;i<3&&k+i<=n;i++)
        {
            current[i]=SUPER[k+i];
            current[i+1]=0;
            for(int j=0;j<9;j++)
                if(strcmp(powers[j],current)==0)
                {
                    solc[t++]=crypt[j];
                    bkt(k+i+1);
                    t--;
                }
            current[i]=SUPER[k+i-1];
        }
    }
}

int main()
{
    fin>>n;
    fin>>SUPER;
    bkt(0);
    fout<<w<<'\n';
    for(int i=1;i<=w;i++)
        fout<<sol[i]<<'\n';
    return 0;
}

#include <fstream>
#define Nmax 100005
using namespace std;
ifstream fin("viena.in");
ofstream fout("viena.out");
int N,S;
int g[Nmax];
int uz[Nmax];

int main()
{
    fin>>N;
    int i;
    for (i=1; i<=N; i++)
        {
            fin>>g[i];
            S+=g[i];
        }
    uz[0]=1;
    int j;
    for(i=1;i<=N;i++)
        {
            for(j=S-g[i];j>=0;j--)
                if(uz[j])
                    uz[j+g[i]]=1;
            if(g[i]%2==0)
                for(j=S-g[i]/2;j>=0;j--)
                    if(uz[j])
                        uz[j+g[i]/2]=1;
        }

    int rez=S;
    for (i=0;i<=S;i++)
        if(uz[i])
        rez=min(rez, max(i,S-i));

    fout<<rez<<'\n';
    return 0;
}

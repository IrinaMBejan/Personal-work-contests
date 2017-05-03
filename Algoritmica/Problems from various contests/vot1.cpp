#include <fstream>
#define Nmax 1005
using namespace std;
ifstream fin("vot1.in");
ofstream fout("vot1.out");

int v[Nmax],last[Nmax],ok[Nmax];

int main()
{
    int i,N,st;
    fin>>N;
    for(i=1; i<=N; i++)
        fin>>v[i];
    for(i=1; i<=N; i++)
        if( !ok[i] )
        {
            st=i;
            while(!ok[st] && last[st]!=i)
            {
                last[st]=i;
                st=v[v[st]];
            }
            if(st==i)
            {
                while(!ok[st])
                {
                    ok[st]=1;
                    st=v[v[st]];
                }
            }
        }
    int nr=0;
    for(i=1; i<=N; i++)
        if(ok[i])
            nr++;
    fout<<nr<<'\n';
    for(i=1; i<=N; i++)
        if(ok[i])
            fout<<i<<" ";
    fout<<'\n';

    return 0;
}

#include <fstream>
#define Nmax 2005
using namespace std;

ifstream fin("bile3.in");
ofstream fout("bile3.out");

int N;
int A[Nmax],C[Nmax], B[Nmax];
char S[Nmax*2];
int main()
{
    fin>>N;
    int i;
    for(i=1; i<=N; i++)
        fin>>A[i];
    for(i=1; i<=N; i++)
        fin>>C[i];
    int k=1, ok=1, j=0;
    int lg=-1;
    i=1;
    while(k<=N && ok)
    {
        ok=0;
        if(B[j]==C[k])
        {
            ok=1;
            S[++lg]='O';
            k++;
            j--;
        }
        else
            for(; i<=N && !ok ; i++)
            {
                B[++j]=A[i];
                S[++lg]='I';
                if(B[j] ==C[k])
                    ok=1;

            }
    }
    if(ok==0)
        fout<<"imposibil";
    else fout<<S;
    fout<<'\n';
    return 0;
}

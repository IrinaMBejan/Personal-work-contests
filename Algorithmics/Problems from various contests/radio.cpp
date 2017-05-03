#include <fstream>
#define Nmax 25
#define Lgmax 1<<19
using namespace std;

ifstream fin("radio.in");
ofstream fout("radio.out");

int N;
int nrmin[Lgmax];
int C[Lgmax];
int mat[Nmax][Nmax]; //mat pt a retine butoanele care se schimba la selectare
int nr[Nmax]; //nr de butoane care se schimba la fiecare sel

int ci, cf;

int main()
{
    fin>>N;
    cf=1<<(N-3);
    int i,j,x;
    int p=1<<(N-1);
    for(i=0; i<N; i++)
    {
        fin>>x;
        ci+=p*x;
        p/=2;
    }
    //obitnem configuratia initiala
    //citim invers pentru ca ord. biti e invers
    for(i=N-1; i>=0; i--)
    {
        fin>>nr[i];
        for(j=0; j<nr[i]; j++)
            {
                fin>>mat[i][j];
                mat[i][j]=N-mat[i][j]; //ord biti invers
            }
    }

    int st=1,fi=1;
    C[st]=ci;
    nrmin[ci]=0;
    int cu=0,c=0;
    while(nrmin[cf]==0)
    {
        c=C[st++];
        for(i=0; i<N; i++)
            if(!((c>>i)&1))//am bit de 0
        {
            cu=c | (1<<i); //setez 1 in poz i
            for(j=0;j<nr[i];j++)
                cu=cu & ~(1<<mat[i][j]); //deselectez buton poz j (=0)
            if(nrmin[cu]==0)
            {
                C[++fi]=cu;
                nrmin[cu]=nrmin[c]+1;
            }
        }
    }
    fout<<nrmin[cf]<<'\n';
    return 0;
}


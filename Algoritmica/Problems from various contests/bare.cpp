#include <fstream>
#define Nmax 105
using namespace std;
ifstream fin("bare.in");
ofstream fout("bare.out");

int c[Nmax];
char mat[6][Nmax];
int main()
{
    int n;
    fin>>n;
    fin.get();
    for(int i=0; i<5; i++)
        fin.getline(mat[i],n+1);
    for(int i=0; i<n; i++)
        for(int j=0; j<5; j++)
        {
            if(mat[j][i] == '.') c[i]=1;
            else if(mat[j][i]=='X') c[i]=-1;
        }

    int ok=1, i;
    while (ok)
    {
        ok=0;
        for (i=0; i<n-2; i++)
        {
            if (c[i]*c[i+1]==1 && !c[i+2])
            {
                c[i+2]=-c[i];
                ok=1;
            }
            if (c[i]*c[i+2]==1 && !c[i+1])
            {
                c[i+1]=-c[i];
                ok=1;
            }
            if (c[i+1]*c[i+2]==1 && !c[i])
            {
                c[i]=-c[i+1];
                ok=1;
            }
        }
    }
    ok=1;
    for(int i=0; i<n; i++)
        if(!c[i]) ok=0;
    if(!ok)
        fout<<"IMPOSIBIL";
    else
        for(int i=0; i<n; i++)
            if(c[i] * c[i+1] == 1) fout<<"1",i++;
            else fout<<"0";
    fout<<'\n';
    return 0;
}

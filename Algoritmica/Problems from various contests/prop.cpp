#include <fstream>
#include <cstring>
#define Nmax 255
#define Kmax 505
#define Lgmax 260
using namespace std;

ifstream fin("prop.in");
ofstream fout("prop.out");

char Q[Nmax][Kmax][55];
int N, K;
char s[Lgmax];
char *p;
char sol[Kmax][Nmax];

int main()
{
    int i,j,lg;
    fin>>N>>K;
    fin.get();

    fin.getline(s,Lgmax);
    p=strtok(s," ");

    while(p!=NULL)
    {
        lg=strlen(p);
        strcpy(Q[1][lg],p);
        p=strtok(NULL," ");
    }

    for( i=2; i<=N; ++i)
    {
        fin.getline(s,Lgmax);
        p=strtok(s," ");
        while(p!=NULL)
        {
            lg=strlen(p);
            for(j=1; j<=K; ++j)
                if(Q[i-1][j][0]!=0)
                        strcpy(Q[i][j+lg+1],p);
            p=strtok(NULL," ");
        }
    }

   /* for (i=1; i<=N; i++)
       {
         for(j=1; j<=K; j++)
            if(Q[i][j][0]!=0)
                fout<<j<<" "<<Q[i][j]<<'\n';
        fout<<'\n'<<'\n';
       }
*/
    i=N;
    strcpy(sol[i],Q[N][K]);
    while(i!=0)
    {
        K-=(strlen(sol[i])+1);
        strcpy(sol[i-1],Q[i-1][K]);

        i--;
    }

    for(int i=1;i<N;i++)
        fout<<sol[i]<<" ";
    fout<<sol[N]<<'\n';
    return 0;
}

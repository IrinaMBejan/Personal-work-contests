#include <fstream>
#include<cstring>
using namespace std;
ifstream fin("festival.in");
ofstream fout("festival.out");

struct trupa
{
    char nume[6][30];
    int nrmem;
} T[25];
int sol[25];
int nrmax;
int n;
char *p,s[200];
int ok=1;
int compatibil[25][25];

void back(int k)
{
    if(k-1>nrmax) nrmax=k-1;
    for(int i=sol[k-1]+1; i<=n; i++) //dorim sa punem pe o scena trupa i
    {
        bool pos=1;
        for(int j=1; j<=k-1; j++) //luam toate trupele care au fost deja puse
            if(compatibil[i][sol[j]]==1)
            {
                pos=0;
                break;
            }
        if(pos==1)
        {
            sol[k]=i;
            back(k+1);
        }
    }

}
int main()
{
    fin>>n;
    int i;
    for(i=1; i<=n; i++)
    {
        fin.get();
        fin.get(s,200);
        int k=0;
        p=strtok(s,",");
        while(p!=NULL)
        {
            strcpy(T[i].nume[++k],p);
            p=strtok(NULL,",");
        }
        T[i].nrmem=k;
    }

    for(i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {

            for(int i1=1; i1<=T[i].nrmem; i1++)
                for(int j1=1; j1<=T[j].nrmem; j1++)
                    if(strcmp(T[i].nume[i1],T[j].nume[j1])==0)
                        compatibil[i][j]=1;
        }
    back(1);
    fout<<nrmax<<'\n';
    return 0;
}

#include <cstdio>
#define Nmax 500005
using namespace std;
FILE* fin=fopen("subperm.in","r");
FILE* fout=fopen("subperm.out","w");

int v[Nmax], nr[Nmax];
int C[Nmax];
bool ok[Nmax];
int N;
int main()
{
    int i;
    int st=1,fi=1;
    fscanf(fin,"%d",&N);
    for(i=0;i<N;i++)
       {
             fscanf(fin,"%d",&v[i]);
             nr[v[i]]++; //de cate ori apare x-ul v[i]
             ok[i]=1; //apartine de subpermutare
       }
    for(i=0;i<N;i++)
        if(nr[i]==0) //x-ul apare de 0 ori
            C[++fi]=i;
    int co=0;
    while(st<=fi)
    {
            if(ok[C[st]]==1)
            {
                ok[C[st]]=0;
                nr[v[C[st]]]--;
                if(nr[v[C[st]]]==0)
                    C[++fi]=v[C[st]];
                co++;
            }
                st++;
    }
    fprintf(fout,"%d\n",N-co);
    return 0;
}

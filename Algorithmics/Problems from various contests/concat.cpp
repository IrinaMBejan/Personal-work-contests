#include <fstream>
#include<cstring>
using namespace std;

ifstream fin("concat.in");
ofstream fout("concat.out");
int sol[105],solmax[105];
char mat[105][105], solre[205],cop[205];
char *pch;
int n,nrmax,le,Le;
char word[105];


void bkt(int k)
{
    if(strcmp(solre,word)==0)
    {
        if(k-1>=nrmax)
        {
            for(int i=1; i<k; i++)
                solmax[i]=sol[i];
            nrmax=k-1;
        }
    }
    else
    {
        for(int i=sol[k-1]+1; i<=n; i++)
        {
            strcpy(cop,solre);
            strcat(cop,mat[i]);
            pch=strstr(word,cop);
            if(pch!=NULL)
            {
                strcpy(solre,cop);
                sol[k]=i;
                bkt(k+1);

                le=strlen(solre);
                Le=strlen(mat[i]);
                solre[le-Le]=0;
            }
        }
    }
}

int main()
{
    fin.get(word,105);
    Le=strlen(word);
    fin>>n;
    fin.get();
    for(int i=1; i<=n; i++)
    {
        fin.get(mat[i],105);
        fin.get();
    }
    bkt(1);
    fout<<nrmax<<'\n';
    for(int i=1; i<=nrmax; i++)
        fout<<solmax[i]<<" ";
    fout<<'\n';
    return 0;
}

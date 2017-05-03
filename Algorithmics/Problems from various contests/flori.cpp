#include <cstdio>

using namespace std;
FILE* fin=fopen("flori.in","r");
FILE* fout=fopen("flori.out","w");

int ma[151][151],fiec[150];
int n,k;
int comun(int, int);
int membru(int, int);

int main()
{
    int i,j,nr,ok;
    fscanf(fin,"%d %d",&n,&k);
    for(i=1; i<=n; i++)
        for(j=1; j<=k; j++)
        {
            fscanf(fin,"%d",&nr);
            if(!membru(nr,i))
            {
                ma[i][0]++;
                ma[i][ ma[i][0] ]=nr;
            }
        }
    for(i=1; i<=n; i++)
        fiec[i]=i;
    for(i=1; i<=n; i++)
    {
        ok=0;
        if(ma[i][0])
        {
            for(j=i+1; j<=n; j++)
                if(comun(i,j))
                {
                    fiec[j]=fiec[i];
                    for(int q=1; q<=ma[j][0]; q++)
                        if(!membru(ma[j][q],i))
                        {
                               ma[i][0]++;
                               ma[i][ma[i][0] ]=ma[j][q];
                        }
                    ma[j][0]=0;
                    ok=1;
                }
        }
        if (ok) i--;
    }
    for(i=1; i<=n; i++)
        if(fiec[i])
        {
            fprintf(fout,"%d ",i);
            for(j=i+1; j<=n; j++)
                if(fiec[i]==fiec[j])
                {
                    fprintf(fout,"%d ",j);
                    fiec[j]=0;
                }
            fprintf(fout,"\n");
        }
}

int comun(int i,int j)
{
    int x,y;
    for(x=1; x<=ma[i][0]; x++)
        for(y=1;y<=ma[j][0]; y++)
            if (ma[i][x]==ma[j][y])
                return 1;
    return 0;
}

int membru(int nr,int linie)
{
    int i;
    for(i=1; i<=ma[linie][0]; i++)
        if (nr==ma[linie][i])
            return 1;
    return 0;
}

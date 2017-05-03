#include <cstdio>
#define LGmax 1505
using namespace std;

FILE* fin=fopen("harta.in","r");
FILE* fout=fopen("harta.out","w");

struct drept
{
    int x1,x2,y1,y2;
} dr[1005];

int mat[LGmax][LGmax];
bool LinV[LGmax], ColV[LGmax];
int LinU[LGmax],ColU[LGmax];

int main()
{
    int Lmax, Amax=0, Sol=0, p, L, l,n,m,k,i,j;
    fscanf(fin,"%d",&p);
    if(p==1)
    {
        fscanf(fin,"%d %d %d",&n,&m,&k);
        for(i=1; i<=k; i++)
        {
            fscanf(fin,"%d %d %d %d",&dr[i].x1,&dr[i].y1,&dr[i].x2,&dr[i].y2);
            if(dr[i].x2-dr[i].x1==dr[i].y2-dr[i].y1)
            {
                L=dr[i].x2-dr[i].x1+1;
                if(L*L>Amax)
                    Amax=L*L,Lmax=L;
            }
        }
        for(i=1; i<=k; i++)
        {
            l=dr[i].x2-dr[i].x1+1;
            L=dr[i].y2-dr[i].y1+1;
            if(l*L<Amax&&l<=Lmax-2&&L<=Lmax-2)
                Sol++;
        }
        fprintf(fout,"%d %d\n",Amax,Sol);
    }
    else if(p==2)
    {
        int x1,y1,x2,y2;
        fscanf(fin,"%d %d %d",&n,&m,&k);
        for(i=1; i<=k; i++)
        {
            fscanf(fin,"%d %d %d %d",&x1,&y1,&x2,&y2);
            mat[x1][y1]+=1;
            mat[x2+1][y2+1]+=1;
            mat[x2+1][y1]-=1;
            mat[x1][y2+1]-=1;

            if(!(x1==x2||y1==y2))
            {
                mat[x1+1][y1+1]=-1;
                mat[x2][y2]-=1;
                mat[x2][y1+1]+=1;
                mat[x1+1][y2]+=1;
            }
        }

        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                {
                    mat[i][j]=mat[i][j]+mat[i][j-1]+mat[i-1][j]-mat[i-1][j-1];
                    if(mat[i][j]) ColV[j]=1, LinV[i]=1;
                }
        int st,klin=-1,kcol=-1;
        for(i=1; i<=n; i++)
            if(LinV[i]==1)
                LinU[++klin]=i;
            else
            {
                st=i;
                while(LinV[st]==0&&st<=n) st++;
                LinU[++klin]=st-1;
                i=st-1;
            }

        for(i=1; i<=m; i++)
            if(ColV[i]==1)
                ColU[++kcol]=i;
            else
            {
                st=i;
                while(ColV[st]==0&&st<=m) st++;
                ColU[++kcol]=st-1;
                i=st-1;
            }

        for(i=0; i<=klin; i++)
        {
            for(j=0; j<=kcol; j++)
                fprintf(fout,"%d ",mat[LinU[i]][ColU[j]]);
            fprintf(fout,"\n");
        }

    }


    return 0;
}

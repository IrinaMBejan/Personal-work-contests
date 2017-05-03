#include <cstdio>
#include<algorithm>
using namespace std;
FILE* fin = fopen("suma.in","r");
FILE* fout = fopen("suma.out","w");

int A[57][57][57], T[57][57][57];
int main()
{
    int niv = 1,N,i,q = 1,j = 1;
    fscanf(fin,"%d",&N);
    for(i=1;i<=N;i++)
        {
            if(i>niv*(niv+1)*(2*niv+1)/6)
            {
                niv++;
                j = 1;
                q = 1;
            }
            else
            {
                if(q == niv + 1)
                {
                    j++;
                    q = 1;
                }
            }
            fscanf(fin,"%d",&A[niv][j][q]);
            q++;
        }
    for(i=1;i<=niv;i++)
        for(j=1;j<=niv;j++)
            T[niv][i][j] = A[niv][i][j];

    int poz,minim;
    for(int m = niv-1; m>=1; m--)
        for(i=1;i<=m;i++)
            for(j=1;j<=m;j++)
            {
                if(T[m+1][i][j] < T[m+1][i+1][j])
                {
                    minim = T[m+1][i][j];
                    poz = i*(niv+1)+j;
                }
                else
                {
                    minim = T[m+1][i+1][j];
                    poz = (i+1)*(niv+1)+j;
                }

                if(T[m+1][i][j+1] < minim)
                {
                    minim = T[m+1][i][j+1];
                    poz = i*(niv+1)+j+1;
                }

                if(T[m+1][i+1][j+1] < minim)
                {
                    minim = T[m+1][i+1][j+1];
                    poz = (i+1)*(niv+1)+j+1;
                }

                T[m][i][j] = A[m][i][j]+ minim;
                A[m][i][j] = poz;
            }

    fprintf(fout,"%d %d\n",niv,T[1][1][1]);
    fprintf(fout,"1 ");
    int m = 1; i = 1; j = 1;

    while(m != niv)
    {
        poz = A[m][i][j];
        m++;
        i = poz/(niv+1);
        j = poz%(niv+1);
        fprintf(fout,"%d ",i*(m-1)+j);
    }

    return 0;
}

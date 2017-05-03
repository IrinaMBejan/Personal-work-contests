#include <fstream>

using namespace std;
ifstream fin("pav.in");
ofstream fout("pav.out");
int mat[1030][1030];
int h, put;
void amplasare(int L1,int C1, int L2, int C2, int x, int y);
int main()
{
    int n,x,y,i,j;
    fin>>n;
    fin>>x>>y;
    put=1;
    for(i=1; i<=n; i++)
        put*=2;
    amplasare(1,1,put,put,x,y);
    for(i=1; i<=put; i++)
    {
        for(j=1; j<=put; j++)
            fout<<mat[i][j]<<" ";
        fout<<'\n';
    }
    return 0;
}


void amplasare(int L1,int C1, int L2, int C2, int x, int y)
{
    int i,j,Lm,Cm;
    //caz elementar
    if(L2-L1==1)
    {
        h++;
        for(i=L1; i<=L2; i++)
            for(j=C1; j<=C2; j++)
                if(!(i==x&&j==y))
                    mat[i][j]=h;
    }
    else
    {
            Lm=(L1+L2)/2;
            Cm=(C1+C2)/2;

            if(x<=Lm&&x>=L1&&y>=Cm+1&&y<=C2)
            {
                h++;
                mat[Lm][Cm]=h;
                mat[Lm+1][Cm]=h;
                mat[Lm+1][Cm+1]=h;
                amplasare(L1,C1,Lm,Cm,Lm,Cm);
                amplasare(Lm+1,C1,L2,Cm,Lm+1,Cm);
                amplasare(Lm+1,Cm+1,L2,C2,Lm+1,Cm+1);
                amplasare(L1,Cm+1,Lm,C2,x,y);
            }

            if(C1<=y && y<=Cm && L1<=x && x<=Lm)
            {
                h++;
                mat[Lm][Cm+1]=h;
                mat[Lm+1][Cm]=h;
                mat[Lm+1][Cm+1]=h;
                amplasare(L1,C1,Lm,Cm,x,y);
                amplasare(Lm+1,C1,L2,Cm,Lm+1,Cm);
                amplasare(Lm+1,Cm+1,L2,C2,Lm+1,Cm+1);
                amplasare(L1,Cm+1,Lm,C2,Lm,Cm+1);
            }
            if(C1<=y && y<=Cm && Lm+1<=x && x<=L2)
            {
                h++;
                mat[Lm][Cm]=h;
                mat[Lm][Cm+1]=h;
                mat[Lm+1][Cm+1]=h;
                amplasare(L1,C1,Lm,Cm,Lm,Cm);
                amplasare(Lm+1,C1,L2,Cm,x,y);
                amplasare(Lm+1,Cm+1,L2,C2,Lm+1,Cm+1);
                amplasare(L1,Cm+1,Lm,C2,Lm,Cm+1);
            }
            if(Cm+1<=y && y<=C2 && Lm+1<=x && x<=L2)
            {
                h++;
                mat[Lm][Cm]=h;
                mat[Lm][Cm+1]=h;
                mat[Lm+1][Cm]=h;
                amplasare(L1,C1,Lm,Cm,Lm,Cm);
                amplasare(Lm+1,C1,L2,Cm,Lm+1,Cm);
                amplasare(Lm+1,Cm+1,L2,C2,x,y);
                amplasare(L1,Cm+1,Lm,C2,Lm,Cm+1);
            }
    }
}

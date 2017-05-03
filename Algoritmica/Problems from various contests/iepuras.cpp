#include <fstream>
#define Nmax 205

using namespace std;
ifstream fin("iepuras.in");
ofstream fout("iepuras.out");

int m,n;
char a[Nmax][Nmax];
int dl[5]= {0,-1,0,1,0};
int dc[5]= {0,0,-1,0,1};

struct zid
{
    int lin;
    int col;
} z1[52],z2[52];

int explod(int i,int j);

int main()
{
    int x,y,dir,nrmorcovi=0,i,j,nrz1=1, nrz2=1;
    fin>>m>>n;
    fin>>x>>y>>dir;
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
        {
            fin>>a[i][j];
            if (a[i][j]=='7') nrmorcovi++;
            if (a[i][j]=='8')
            {
                z1[nrz1].lin=i;
                z1[nrz1].col=j;
                nrz1++;
            }
        }
    fin>>nrz2;
    for (i=1; i<=nrz2; i++)
        fin>>z2[i].lin>>z2[i].col;

    for(i=0; i<=m+1; i++)
        a[i][0]=a[i][n+1]='$';

    for(i=0; i<=n+1; i++)
        a[0][i]=a[m+1][i]='$';


    int x1=x, y1=y, p=0,nrcul=0, pz=1;
    while (1)
    {
        x1=x1+dl[dir];
        y1=y1+dc[dir];
        p++;
        // afara
        if (a[x1][y1]=='$')
        {
            fout<<"RATACIT"<<'\n';
            fout<<x1-dl[dir]<<" "<<y1-dc[dir]<<'\n';
            fout<<nrcul<<' '<<p<<'\n';

            break;
        }

        // morcov
        if (a[x1][y1]=='7')
        {
            nrcul++;
            a[x1][y1]='0';
        }

        // bomba
        if (explod(x1,y1))
        {
            fout<<"INGERAS"<<'\n';
            fout<<x1<<" "<<y1<<'\n';
            fout<<nrcul<<" "<<p<<'\n';

            break;
        }

        // a cules toti morcovii
        if (nrcul==nrmorcovi)
        {
            fout<<"FERICIT"<<'\n';
            fout<<x1<<" "<<y1<<'\n';
            fout<<nrcul<<" "<<p;

            break;
        }

        if (a[x1][y1]=='9')
        {
            if (pz==1)
            {
                for (int k = 1; k <= nrz1; k++)
                    a[z1[k].lin][z1[k].col]='0';

                for (int k = 1; k <= nrz2; k++)
                    a[z2[k].lin][z2[k].col]='8';
                pz=2;
            }
            else
            {
                for (int k = 1; k <= nrz2; k++)
                    a[z2[k].lin][z2[k].col]='0';

                for (int k = 1; k <= nrz1; k++)
                    a[z1[k].lin][z1[k].col]='8';
                pz=1;
            }
        }

        // sageata
        if (a[x1][y1]=='1')
        {
            dir=1;
            a[x1][y1]='0';
        }
        if (a[x1][y1]=='2')
        {
            dir=2;
            a[x1][y1]='0';
        }
        if (a[x1][y1]=='3')
        {
            dir=3;
            a[x1][y1]='0';
        }
        if (a[x1][y1]=='4')
        {
            dir=4;
            a[x1][y1]='0';
        }

        // pom sau zid, schimba directia
        if (a[x1+dl[dir]][y1+dc[dir]]=='5' || a[x1+dl[dir]][y1+dc[dir]]=='8')
            if (dir==1) dir=3;
            else if (dir==2) dir=4;
            else if (dir==3) dir=1;
            else dir=2;

    }
}


int explod(int i,int j)
{
    int k,i1,j1;
    if (a[i][j]=='6' || a[i][j]=='*')
        return 1;
    for (k=1; k<5; k++)
    {
        i1=i+dl[k];
        j1=j+dc[k];
        if (a[i1][j1]!='$')
            if (a[i1][j1]=='6')
                a[i1][j1]='*';
            else if (a[i1][j1]=='*')
                return 1;
    }
    return 0;
}

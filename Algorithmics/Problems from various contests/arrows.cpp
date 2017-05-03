#include <fstream>
#define NMAX 501
using namespace std;
ifstream fin("arrows.in");
ofstream fout("arrows.out");


int dl[5]= {0,0,-1,0,1};
int dc[5]= {0,1,0,-1,0};
char a[NMAX][NMAX];
int pt[NMAX][NMAX];

int plimba(int, int);

int main()
{
    int p,n,m,i,j,x,y,x1,y1;
    //citire
    fin>>p;
    fin>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            fin>>a[i][j];
    fin>>x>>y;

    //bordare
    for(i=0; i<=n+1; i++)
    {
        a[i][0]='0';
        a[i][m+1]='0';
    }
    for(j=0; j<=m+1; j++)
    {
        a[0][j]='0';
        a[n+1][j]='0';
    }

    //crearea matricii pt
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(!pt[i][j])
                plimba(i,j);
    /*TEST
     for(i=1; i<=n; i++)
     {
         for(j=1; j<=m; j++)
             fout<<a[i][j]<<" ";
         fout<<'\n';
     }

     fout<<'\n';
     for(i=1; i<=n; i++)
     {
         for(j=1; j<=m; j++)
             fout<<pt[i][j]<<" ";
         fout<<'\n';
     }
    */
    //cerinte
    int pozf=0, mmax=0;
    if (p==1)
    {
        if (pt[x][y]<0)
            fout<<-pt[x][y]<<'\n';
        else
            fout<<1000*pt[x][y]<<'\n';
    }
    else
    {
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++)
                if (pt[i][j]>0)
                {
                    pozf++;
                    if (mmax<1000*pt[i][j]) mmax=1000*pt[i][j];
                }
                else
                {
                    if (mmax<-pt[i][j]) mmax=-pt[i][j];
                }
        if (p==2)
            fout<<pozf<<'\n';
        else
            fout<<mmax<<'\n';
    }
    return 0;
}


int plimba(int x, int y)
{
    int sum=0, dir, cx=x, cy=y, s;
    while ((a[x][y]-'0') && !pt[x][y])
    {
        pt[x][y]=1;
        sum++;
        dir=a[x][y]-'0';
        x+=dl[dir];
        y+=dc[dir];
    }

//completarea punctajelor in pt
    if (!(a[x][y]-'0') || pt[x][y]<0) //pozitie nefavorabila
    {
        sum-=pt[x][y];
        x=cx, y=cy;
        s=-sum;
        while (pt[x][y]==1)
        {
            pt[x][y]=s;
            s++;
            dir=a[x][y]-'0';
            x+=dl[dir];
            y+=dc[dir];
        }
        return -sum; //pozitie nefavorabila
    }

    if (pt[x][y]==1) //pozitie favorabila de pe acelasi traseu
    {
        //se formeaza un circuit care contine pozitia x,y
        //toate punctele de pe circuit se marcheaza cu acelasi punctaj
        s=sum;
        while (cx!=x || cy!=y)
        {
            pt[cx][cy]=s;
            s--;
            dir=a[cx][cy]-'0';
            cx+=dl[dir];
            cy+=dc[dir];
        }
        //punctele de pe circuit le marchez cu s
        while (pt[x][y]==1)
        {
            pt[x][y]=s;
            dir=a[x][y]-'0';
            x+=dl[dir];
            y+=dc[dir];
        }
        return sum;
    }
//pozitie favorabila care conduce catre un circuit
    s=sum+pt[x][y];
    while (cx!=x || cy!=y)
    {
        pt[cx][cy]=s;
        s--;
        dir=a[cx][cy]-'0';
        cx+=dl[dir];
        cy+=dc[dir];
    }
    return sum+pt[x][y];
}


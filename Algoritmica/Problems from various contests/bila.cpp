#include<fstream>
using namespace std;

ifstream fin("bila.in");
ofstream fout("bila.out");

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int a[127][127],b[127][127];
int main()
{
    int    i,j,n,m,y,h,max,t,v,p,k,x,q,min,nr,ok;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
                fin>>a[i][j];
    for(i=1;i<=n;i++)
    {
        a[i][0]=65001;
        a[i][m+1]=65001;
    }
    for(j=1;j<=m;j++)
    {
        a[0][j]=65001;
        a[n+1][j]=65001;
    }
    max=0;
    h=65001;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            x=i;
            y=j;
            ok=1;
            nr=0;
            if(b[i][j]==0)
                while(ok)
                {
                    min=a[x][y];
                    v=0;
                    for(k=0;j<=3;k++)
                        if(a[x+dx[k]][y+dy[k]]<min)
                    {
                        min=a[x+dx[k]][y+dy[k]];
                        v=k;
                    }
                    b[i][j]++;
                    if(v==0) ok=0;
                }
            else
            {
                x=x+dx[v];
                y=y+dy[v];
                if(b[x][y]!=0)
                {
                    b[i][j]++;
                    b[x][y]++;
                    break;

                }
            }
            }
            p=i; q=j;
            if(b[p][q]>max)
            {
                max=b[p][q];
                h=a[p][q];
            }
            else if (b[p][q]==max&&h>a[p][q]) h=a[p][q];
        while (p!=x||q!=y)
        {
            min=a[p][q];
            v=0;
            for(k=0;k<=3;k++)
                        if (a[p+dx[k]][q+dy[k]]<min)
            {
                min=a[p+dx[k]][q+dy[k]];
               v=k;

            }
          b[p+dx[v]][q+dy[v]]=b[p][q]-1;
          p=p+dx[v];
          q=q+dy[v];
        }
    fout<<max<<" "<<h<<'\n';
    return 0;
}

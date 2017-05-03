#include <fstream>

using namespace std;
ifstream fin("elicop.in");
ofstream fout("elicop.out");

bool a[101][101];
int z[51];
int main()
{
    int n,m,w=0,dir,l1,l2,c1,c2,k,q,i,s,j,x,y,v=0;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            fin>>a[i][j];
    fin>>k;
    int nr,r;
    for(q=1;q<=k;q++)
    {
        s=0; nr=0;
        fin>>l1>>c1>>l2>>c2>>dir;
        if(l1>l2)
        {
            r=l1;
            l1=l2;
            l2=r;
            r=c1;
            c1=c2;
            c2=r;
        }
        if(l2-l1==c2-c1)
        {
            if(dir==-1)
                for(i=l1;i<=l2;i++)
                {
                     x=i; y=c1;
                    while(y<=c2&&x<=l2)
                    {
                        s+=a[x][y];
                        x++;
                        y++;
                        nr++;
                    }

                }

            else if(dir==1)
                for(i=c1;i<=c2;i++)
                {
                    x=l1; y=i;
                    while(x<=l2&&y<=c2)
                    {
                        s+=a[x][y];
                        x++;
                        y++;
                        nr++;
                    }

                }
        }
        else
        {
             if(dir==1)
                for(i=c1;i>=c2;i--)
                {
                    x=l1; y=i;
                    while(x<=l2&&y>=c2)
                    {
                        s+=a[x][y];
                        x++;
                        y--;
                        nr++;
                    }

                }
            else if(dir==-1)
                for(i=l1;i<=l2;i++)
                {
                    x=i;y=c1;
                    while(y>=c2&&x<=l2)
                    {
                        s+=a[x][y];
                        x++;
                        y--;
                        nr++;
                    }
                }

        }
        if(s<nr/2+1) z[++w]=q;
        else if(s==nr) v++;
    }

    fout<<v<<'\n';
    fout<<w<<" ";
    for(i=1;i<=w;i++)
        fout<<z[i]<<" ";
    return 0;
}


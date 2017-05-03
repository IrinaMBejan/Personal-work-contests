#include <fstream>

using namespace std;
ifstream fin("v.in");
ofstream fout("v.out");

int a[103][103];
int main()
{
    int n, m, i, j, x, y, q,z,s, nrl, nrlmax=99999, s2,nrl2, smax=0, cap1, cap2;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            fin>>a[i][j];
    for(i=1;i<=m-2;i++)
    {
        y=i;
        x=1;
        s=a[x][y];
        nrl=1;
        while(x<n&&y<m)
        {

            x++;
            y++;
            s+=a[x][y];
            s2=0;
            nrl++;
            nrl2=0;
            q=x; z=y;
            while(q>1&&z<m)
            {
                q--;
                z++;
                s2+=a[q][z];
                nrl2++;
            }
            if(q==1)
            if(s2+s>smax) {smax=s2+s; nrlmax=nrl+nrl2; cap1=i;cap2=x;}
                else if(s2+s==smax&&nrl+nrl2<nrlmax) {nrlmax=nrl+nrl2; cap1=i;cap2=x;}
        }
    }
    fout<<smax<<" "<<cap1<<" "<<cap2<<'\n';
    return 0;
}

#include <cstdio>
#include<algorithm>
using namespace std;

FILE* fin=fopen("reactivi.in","r");
FILE* fout=fopen("reactivi.out","w");

struct frigider
{
    char minn;
    char maxx;
} f[8000],r[8000];

int Cate;
int compare(frigider a, frigider b)
{
    return(a.minn<b.minn||(a.minn==b.minn&&a.maxx>b.maxx));
}
int main()
{
    int n, i, j, poz, ptminn;
    fscanf (fin, "%d", &n);
    for (i=1; i<=n; i++)
        fscanf (fin, "%d %d", &r[i].minn, &r[i].maxx);
    char tmaxx, tminn;
    sort(r+1,r+n+1,compare);
    f[1].minn=r[1].minn;
    f[1].maxx=r[1].maxx;
    Cate=1;
    int minn, maxx, Unde;
    for (i=2; i<= n; i++)
    {
        minn=r[i].minn;
        maxx=r[i].maxx;
        for (j=1; j<= Cate; j++)
        {
            if ((f[j].maxx>=minn) && (f[j].maxx<=maxx)) Unde=j;
            if ((f[j].minn>=minn) && (f[j].minn<=maxx)) Unde=j;
            if ((f[j].minn<=minn) && (f[j].maxx>=maxx)) Unde=j;
            if ((f[j].maxx<minn) || (f[j].minn>maxx)) Unde=-1;
        }
        j=Unde;
        if (j>0)
        {
            if (minn>f[j].minn)
                f[j].minn=minn;
            if (maxx<f[j].maxx)
                f[j].maxx=maxx;
        }
        else
        {
            Cate++;
            f[Cate].minn=minn;
            f[Cate].maxx=maxx;
        }
    }
    fprintf (fout,"%d\n",Cate);
    return 0;
}

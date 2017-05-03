#include <cstdio>
#include <vector>
#include<cmath>
#include<algorithm>
#define MAX 30005
using namespace std;
FILE* fin = fopen("parc.in","r");
FILE* fout = fopen("parc.out","w");

struct pista
{
    int x,y;
};
vector<pista> v,o;
vector<int> gv,go;
int xa,ya,xb,yb,xP,yP;


int comp(pista a, pista b)
{
    return (a.y <= b.x);
}
int main()
{
    int m,n, xInv = 0, yInv = 0, semnY = 1, semnX = 1;
    fscanf(fin,"%d %d",&xP,&yP);
    fscanf(fin,"%d %d",&xa,&ya);
    fscanf(fin,"%d %d",&xb,&yb);

    if(xb<xa)
    {
        xInv = 1;
        xa = xP - xa;
        xb = xP - xb;
        semnX = -1;
    }
    if(yb<ya)
    {
        yInv = 1;
        ya = yP - ya;
        yb = yP - yb;
        semnY = -1;
    }

    if(xa == xb)
    {
        fprintf(fout,"%d\n1\n",yb-ya);
        return 0;
    }

    if(ya == yb)
    {
        fprintf(fout,"%d\n1\n",xb-xa);
        return 0;
    }
    int i;
    pista s;
    s.x = s.y = 0;

    fscanf(fin,"%d",&m);
    v.push_back(s);
    if(xInv)
    {
        for(i=1;i<=m;i++)
        {
            fscanf(fin,"%d %d",&s.x,&s.y);
            if(s.x < s.y) swap(s.x,s.y);
            s.x = xP - s.x;
            s.y = xP - s.y;
            v.push_back(s);
        }
    }
    else
    {
        for(i=1;i<=m;i++)
        {
            fscanf(fin,"%d %d",&s.x,&s.y);
            if(s.x > s.y) swap(s.x,s.y);
            v.push_back(s);
        }
    }
    sort(v.begin()+1,v.end()+1,comp);

    fscanf(fin,"%d",&n);
    o.push_back(s);
    if(yInv)
    {
        for(i=1;i<=n;i++)
        {
            fscanf(fin,"%d %d",&s.x,&s.y);
            if(s.x < s.y) swap(s.x,s.y);
            s.x = yP - s.x;
            s.y = yP - s.y;
            o.push_back(s);
        }
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            fscanf(fin,"%d %d",&s.x,&s.y);
            if(s.x > s.y) swap(s.x,s.y);
            o.push_back(s);
        }
    }
    sort(o.begin()+1,o.end()+1, comp);

    gv.push_back(0);

    for(i=1; i<=m; i++)
    {
        gv.push_back(gv[i-1]+v[i].y - v[i].x);
    }

    go.push_back(0);

    for(i=1; i<=m; i++)
    {
        go.push_back(go[i-1]+o[i].y - o[i].x);
    }

    int fv = m, stv = 1;
    while(xa>v[stv].x) ++stv;
    while(xb<v[fv].y) --fv;

    int fo = n, sto = 1;
    while(ya>o[sto].x)
        ++sto;
    while(yb<o[fo].y) --fo;

    int dor = gv[fv] - gv[stv-1];
    int dver = go[fo] - go[sto-1];

    int c1 = xb-xa - dor, c2 = yb-ya - dver;

    double sol = sqrt((double) c1*c1+c2*c2)+ dor+dver;
    fprintf(fout,"%lf\n",sol);
    int segmx[10000], segmy[10000];

    segmx[0] = v[stv].x - xa;
    int kx = 0;
    for(i = stv + 1; i<fv; ++i)
        segmx[++kx] = segmx[kx-1] + v[i].x - v[i-1].y;

    segmy[1] = o[sto].x - ya;
    int ky = 0;
    for(i = sto + 1; i<fo; ++i)
        segmy[++ky] = segmx[ky-1] + o[i].x - o[i-1].y;

    int sol2 = 1;
    i = 0;
    int j = i;

    while(i<=kx && j <=ky)
        if(segmx[i]*c2 == segmy[j] * c1)
        {
            sol2*=2;
            ++i; ++j;
        }
        else
            if(segmx[i]*c2 > segmy[j] * c1)
                ++j;
            else ++i;
    fprintf(fout,"%d\n",sol2);


    return 0;
}

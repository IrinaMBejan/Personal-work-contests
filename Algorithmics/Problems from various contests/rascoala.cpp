#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream f("rascoala.in");
ofstream g("rascoala.out");


int n,p,k,r,min_s,m,xmin[505],xmax[505],ymin[505],ymax[505];

struct cetate
{
    int x, y, s;
} a[250005],PX[250005],aux;

void citire()
{
    int i,j;
    f>>p>>n>>m>>k;

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            f>>a[(i-1)*m+j].s;
            a[(i-1)*m+j].x = i;
            a[(i-1)*m+j].y = j;

        }
    a[n*m+1].s=2000000005;

}

int smaller(int i, long pivot, long pivotx, long pivoty)
{
    if(a[i].s<pivot) return 1;//daca numarul de soldati din regiunea i e mai mic decat pivotul elementul i e mai mic decat pivotul
    else  if(a[i].s>pivot) return 0;
    else if(a[i].x<pivotx) return 1;//daca numarul de soldati e egal verific indicele liniei
    else if(a[i].x>pivotx) return 0;
    else if(a[i].y<pivoty) return 1;//daca numarul de soldati si indicele liniei sunt egale, verific indicele coloanei
    else return 0;
}
int bigger(int i, long pivot, long pivotx, long pivoty)
{
    if(a[i].s>pivot) return 1;
    else if(a[i].s<pivot) return 0;
    else if(a[i].x>pivotx) return 1;
    else if(a[i].x<pivotx) return 0;
    else if(a[i].y>pivoty) return 1;
    else return 0;

}

void quickSort(struct cetate *a, int left, int right)
{
    int i = left, j = right;
    long pivot = a[(left + right) / 2].s;
    long pivotx = a[(left + right) / 2].x;
    long pivoty = a[(left + right) / 2].y;
    while (i <= j)
    {
        while (smaller(i,pivot,pivotx,pivoty)&&i<=right)
            i++;
        while (bigger(j,pivot,pivotx,pivoty))
            j--;
        if (i <= j)
        {
            aux=a[i];
            a[i]=a[j];
            a[j]=aux;
            i++;
            j--;
        }
    };
    if (left < j)
        quickSort(a, left, j);
    if (i < right)
        quickSort(a, i, right);
}

void solutie()
{
    int i,sldt;
    long num;
    sldt=0;
    r=1;//am utilizat 0 soldati
    num=k;
    min_s=a[1].s;
    i=1;
    while(r<n*m && sldt<k)  //cat timp mai am regiuni si soldati
    {

        while(i<n*m && a[i+1].s==a[i].s) i++;
        if(i<n*m) sldt=sldt+i*(a[i+1].s-a[i].s);
        else sldt=k;
        if(sldt<k)
        {
            r=i;

            num=k-sldt;
            i++;
            min_s=a[i].s;
        }
    }

    if(i <= num) r = i;
    else if(r<num) r=num;
    min_s = min_s + num/i;

}

void dist_max()
{
    int i,j,dmax,dx,dy;
    int ax,ay,bx,by;
    for(i=1; i<=n; i++)
    {
        xmin[i] = 505;
        xmax[i] = 0;
    }
    for(i=1; i<=m; i++)
    {
        ymin[i] = 505;
        ymax[i] = 0;
    }

    for(i=1; i<=r; i++)
    {
        if(xmin[a[i].x] > a[i].y ) xmin[a[i].x] = a[i].y;
        if(xmax[a[i].x] < a[i].y ) xmax[a[i].x] = a[i].y;
        if(ymin[a[i].y] > a[i].x ) ymin[a[i].y] = a[i].x;
        if(ymax[a[i].y] < a[i].x ) ymax[a[i].y] = a[i].x;
    }
    int nr=0;
    for(i=1; i<=m; i++)
        if(ymin[i]<=n)
        {
            nr++;
            PX[nr].x = ymin[i];
            PX[nr].y = i;
        }
    for(i=1; i<=n; i++)
        if(xmax[i]>0)
        {
            nr++;
            PX[nr].x = i;
            PX[nr].y = xmax[i];
        }

    for(i=m; i>=1; i--)
        if(ymax[i]>0)
        {
            nr++;
            PX[nr].x = ymax[i];
            PX[nr].y = i;
        }

    for(i=n; i>=1; i--)
        if(xmin[i]<=n)
        {
            nr++;
            PX[nr].x = i;
            PX[nr].y = xmin[i];
        }
    dmax = 0;
    for(i=1; i<nr; i++)
        for(j=i+1; j<=nr; j++)
        {
            if(PX[i].x > PX[j].x) dx = PX[i].x - PX[j].x;
            else dx = PX[j].x - PX[i].x;

            if(PX[i].y > PX[j].y) dy = PX[i].y - PX[j].y;
            else dy = PX[j].y - PX[i].y;
            if(dmax < dx + dy)
            {
                dmax = dx + dy;
                ax = PX[i].x;
                ay=PX[i].y;
                bx = PX[j].x;
                by = PX[j].y;
            }
        }
    g<<dmax;

}
int main()
{
    citire();
    quickSort(a,1,n*m);
    solutie();
    if(p==1) g<<r<<"\n"<<min_s<<"\n";
    else dist_max();
    return 0;
}


#include <cstdio>
#define MAX 50
#define NMAX 501

using namespace std;
FILE* fin=fopen("concurs.in","r");
FILE* fout=fopen("concurs.out","w");
int P, nrJ;
int a[MAX+1][NMAX];
int lista[NMAX][2];

void sorta(int i);
int main()
{
    int i, j, max1, poz1, k, max2, poz2;
    int inc[MAX+1];
    int el, jud;
    fscanf(fin, "%d", &P);
    for (i=1; i<=P; i++)
    {
        fscanf (fin,"%d %d",&jud, &el);
        a[jud][0]++;
        a[jud][a[jud][0]]=el;
    }
    for (i=1; i<=MAX; i++)
        if (a[i][0]) nrJ++;
    fprintf(fout,"%d\n",nrJ);
    for (i=1; i<=MAX; i++)
        if (a[i][0]) fprintf(fout,"%d ",a[i][0]);
    fprintf(fout,"\n");

    for (i=1; i<=MAX; i++)
        if (a[i][0]) sorta(i);

    for (j=1; j<=MAX; j++) inc[j]=1;

    for (k=1; k<=P; i++)
    {
        max1=max2=0;
        poz1=poz2=0;
        for (j=1; j<=MAX; j++)
            if (a[j][0]>max1)
            {
                max2=max1;
                poz2=poz1;
                max1=a[j][0];
                poz1=j;
            }
            else if (a[j][0]>max2)
            {
                max2=a[j][0];
                poz2=j;
            }
        lista[k][0]=poz1;
        lista[k][1]=a[poz1][inc[poz1]];
        if (max2)
        {
            lista[k+1][0]=poz2;
            lista[k+1][1]=a[poz2][inc[poz2]];
        }
        k+=2;
        a[poz1][0]--;
        a[poz2][0]--;
        inc[poz1]++;
        inc[poz2]++;
    }

    for (i=1; i<=P; i++)
        fprintf(fout,"%d %d\n", lista[i][0], lista[i][1]);
    fclose(fout);
    return 0;
}

void sorta(int i)
{
    int ok, j, aux;
    do
    {
        ok=1;
        for (j=1; j<a[i][0]; j++)
            if (a[i][j]>a[i][j+1])
            {
                aux=a[i][j];
                a[i][j]=a[i][j+1];
                a[i][j+1]=aux;
                ok=0;
            }

    }
    while (!ok);
}


/*#include <fstream>
#include<algorithm>
using namespace std;
ifstream fin("concurs.in");
ofstream fout("concurs.out");

struct elev
{
    int jud;
    int e;
} a[502],aux;
int compare(elev a, elev b)
{
    return a.e<b.e;
}
int jud[51];
int main()
{
    int n,i,j,nrj;
    fin>>n;
    nrj=0;
    for(i=1;i<=n;i++)
     {
            fin>>a[i].jud>>a[i].e;

            jud[a[i].jud]++;
            if(jud[a[i].jud]==1) nrj++;
     }
     fout<<nrj<<'\n';
     for(i=1;i<=50;i++)
        if(jud[i]) fout<<jud[i]<<" ";
     fout<<'\n';
    sort(a+1,a+n+1,compare);
    int ok=0;
    while(!ok)
    {
        ok=1;
        for(i=1;i<n;i++)
            if(a[i].jud==a[i+1].jud)
            {
            aux=a[i-1];
            a[i-1]=a[i];
            a[i]=aux;
            ok=0;
            }
    }
    for(i=1;i<=n;i++)
        fout<<a[i].jud<<" "<<a[i].e<<'\n';
    return 0;
}
*/

#include <cstdio>
#include<algorithm>
#define Nmax 21
#define Mmax 5000
using namespace std;
FILE* fin=fopen("mijloc.in","r");
FILE* fout=fopen("mijloc.out","w");

int N,M,Q;
int cautabin(int x, int i);
int min(int a, int b);
int abs(int a);

struct element
{
    int val;
    int j;
} v[Nmax][Mmax];

int comp(element a, element b)
{
    return a.val<b.val || (a.val==b.val && a.j < b.j);
}

int main()
{
    int i,j;
    fscanf(fin,"%d %d %d",  &N, &M, &Q);
    for(i=1; i<=N; i++)
        for(j=1; j<=M; j++)
            fscanf(fin,"%d", &v[i][j].val),v[i][j].j=j;


    for(i=1; i<=N; i++)
        sort(v[i],v[i]+M+1,comp);
    /*
        for(i=1; i<=N; i++)
          {
              for(j=1; j<=M; j++)
                fprintf(fout,"%d   ", v[i][j].val);
            fprintf(fout,"\n");
          }*/

    int C1, C2, Cost1,Cost2, Lastj1,Lastj2,mij;
    mij=(M+1)/2;
    int p,poz1,poz2,val,k;
    for(i=1; i<=Q; i++)
    {
        fscanf(fin,"%d",&val);
        Cost1=Cost2=0, Lastj1=Lastj2=mij;
        for(k=1; k<=N; k++)
        {
            p = cautabin(val,k);
            if(p == -1)
                poz1=poz2=mij;
            else
            {
                poz1=v[k][p].j;
                if(v[k][p-1].val==val)
                    poz2=v[k][p-1].j;
                else if(v[k][p+1].val==val)
                    poz2=v[k][p+1].j;
                else
                    poz2=poz1;
            }
            C1= Cost1;
            C2= Cost2;

            Cost1= min(C1+abs(Lastj1-poz1),C2+abs(Lastj2-poz1));
            Cost2= min(C1+abs(Lastj1-poz2),C2+abs(Lastj2-poz2));

            Lastj1 = poz1;
            Lastj2 = poz2;
        }
        C1= Cost1;
        C2= Cost2;

        Cost1= min(C1+abs(Lastj1-mij),C2+abs(Lastj2-mij));
        Cost2= min(C1+abs(Lastj1-mij),C2+abs(Lastj2-mij));
        fprintf(fout,"%d\n",min(Cost1,Cost2));
    }
    return 0;
}

int cautabin(int x, int i)
{
    int st=0, fi=M+1,m;
    while(fi-st>1)
    {
        m=(fi+st)/2;
        if(v[i][m].val<x)
            st=m;
        else
            fi=m;
    }
    if(v[i][fi].val!=x || fi==M+1)
        return -1;
    return fi;
}

int min(int a, int b)
{
    if(a<=b)
        return a;
    return b;
}

int abs(int a)
{
    if(a<0)
        a*=(-1);
    return a;
}

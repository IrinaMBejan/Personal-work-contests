#include <cstdio>
#include<cstring>
#define Nmax 1010
using namespace std;

FILE* fin=fopen("honest.in","r");
FILE* fout=fopen("honest.out","w");

int nrp[Nmax];
bool a[Nmax][Nmax];
int sol [Nmax];
int s[Nmax];
int e[Nmax][Nmax];

int main()
{
    int n,m;
    fscanf(fin,"%d %d",&n,&m);
    int x,y;
    char val;
    for(int i = 1; i <= m; i++)
    {
        fscanf(fin,"%d %c %d",&x,&val,&y);
        if(val == 'm')
            e[x][y] = -1;
        else
            e[x][y]=1;
        nrp[y]++;
        a[x][y] = 1;
    }

    int r=0;
    for( int i = 1; i <=n; i++)
    {
        int j;
        for( j = 1; nrp[j] !=0 && j<=n; j++);
        sol[++r]=j;
        nrp[j] = -1;
        for(int k = 1; k <= n; k++)
            if( a[j][k] ) nrp[k]--;
    }

    int nrc=1,nrm=0;
    int sta[Nmax],st=1,fi=1;
    sta[st]=sol[1];
    s[sol[1]]=1;
    while(st<=fi)
    {
        int q=sta[st++];
        if(s[q]==1)
        {
         for(int i=1; i<= n; i++)
            if(e[q][sol[i]] !=0 )
            {
                if(s[sol[i]] ==0) sta[++fi]=sol[i];
                s[sol[i]]=e[q][sol[i]];
            }
        }
        else
        {
             for(int i=1; i<= n; i++)
                if(e[q][sol[i]] !=0)
                {
                      if(s[sol[i]] ==0)  sta[++fi]=sol[i];
                    s[sol[i]]=(-1)*e[q][sol[i]];
                }
        }
    }

    for( int i = 1; i <= r; i++)
        if(s[i] == -1) s[i] =0, nrm++;
    if(nrm>n/2+n%2)
        for(int i =1 ;i<=r;i++)
            s[i]=!s[i];
    for(int i=1;i<=r;i++)
        fprintf(fout,"%d\n",s[i]);
    return 0;
}

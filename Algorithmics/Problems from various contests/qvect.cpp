#include <cstdio>
#include<algorithm>
#define NMAX 105
#define LGMAX 5005
using namespace std;

FILE* fin=fopen("qvect.in","r");
FILE* fout=fopen("qvect.out","w");

int vec[NMAX][LGMAX];
int inter[NMAX*LGMAX];

int cautabin(int val, int v);
int abs(int x);

int main()
{
    int N,Q,k,i,j;
    //citire
    fscanf(fin,"%d %d",&N,&Q);
    for(i=1; i<=N; i++)
    {
        fscanf(fin,"%d",&vec[i][0]);
        for(j=1; j<=vec[i][0]; j++)
            fscanf(fin,"%d",&vec[i][j]);
    }

    //intrebari
    int p,v1,v2,minim,poz;
    for(k=1; k<=Q; k++)
    {
        fscanf(fin,"%d %d %d",&p,&v1,&v2);
        if(p==1)//c1
        {
            minim=2000000005;
            if(vec[v1][0]>vec[v2][0])
            {
                int v=v1;    //interschimbare
                v1=v2;
                v2=v;
            }
            for(i=1; i<=vec[v1][0]; i++)
            {//cauta bin fiecare element si calc dif cu vecinii
                poz=cautabin(vec[v1][i],v2);
                if(abs(vec[v1][i]-vec[v2][poz])<minim)
                    minim=abs(vec[v1][i]-vec[v2][poz]);
                if(abs(vec[v1][i]-vec[v2][poz+1])<minim)
                    minim=abs(vec[v1][i]-vec[v2][poz+1]);
                if(abs(vec[v1][i]-vec[v2][poz-1])<minim)
                    minim=abs(vec[v1][i]-vec[v2][poz-1]);
            }
            fprintf(fout,"%d\n",minim);
        }
        else if(p==2)//c2
        {
            int lg=0;//toate elem ajung in inter unde sunt sortate
            for(i=v1; i<=v2; i++)
            {
                for(j=1; j<=vec[i][0]; j++)
                    inter[++lg]=vec[i][j];
            }
            sort(inter+1,inter+lg+1);
            fprintf(fout,"%d\n",inter[lg/2]);
        }

    }
    return 0;
}

int cautabin(int val, int v)
{
    int st=0,fi=vec[v][0]+1,mid;
    while(fi-st>1)
    {
        mid=st+(fi-st)/2;
        if(vec[v][mid]<=val&&vec[v][mid+1]>val) return mid;
        else if(vec[v][mid]<val) st=mid;
        else fi=mid;
    }
    return fi;
}

int abs(int x)
{
    if(x<0) return x*(-1);
    return x;
}

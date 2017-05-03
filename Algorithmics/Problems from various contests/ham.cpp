#include <cstdio>
#include<algorithm>

using namespace std;
FILE* fin=fopen("ham.in","r");
FILE* fout=fopen("ham.out","w");

int N,H;
char q[20], sol[20];
int DIF;
int solnr[100000];
int w=0;

void showoff(int nr);
int convert();

void bkt(int k)
{
    if(k-1==N)
    {
        if(DIF==H)
            solnr[++w]=convert();
    }
    else
    {
        sol[k]='0';
        DIF=0;
        for(int i=1;i<=N;i++)
            if(q[i]!=sol[i]) DIF++;
        bkt(k+1);

        sol[k]='1';
        DIF=0;
        for(int i=1;i<=N;i++)
            if(q[i]!=sol[i]) DIF++;
        bkt(k+1);

    }

}


int main()
{
    char c;
    fscanf(fin,"%d %d\n",&N,&H);
    for(int i=1;i<=N;i++)
    {
        fscanf(fin,"%c",&c);
        q[N-i+1]=c;
    }
    bkt(1);
    sort(solnr+1, solnr+w+1);

    for(int i=1;i<=w;i++)
    {
        showoff(solnr[i]);
        fprintf(fout,"\n");
    }
    return 0;
}


void showoff(int nr)
{
    int vec[20], q=0;
    while(nr>0)
    {
        vec[++q]=nr%2;
        nr/=2;
    }
    for(int i=1;i<=N-q;i++)
        fprintf(fout,"0");
    for(int i=q;i>=1;i--)
        fprintf(fout,"%d",vec[i]);
}


int convert()
{
    int nr=(sol[1]-'0'),p=2;
    for(int i=2;i<=N;i++)
        nr+=(sol[i]-'0')*p,p*=2;
    return nr;
}

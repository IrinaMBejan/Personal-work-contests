#include <cstdio>
#define LGMAX 50001
using namespace std;
FILE* fin=fopen("popic.in","r");
FILE* fout=fopen("popic.out","w");

int L[LGMAX],C[LGMAX];
int main()
{
    int N,M,i,l,c,x,tip;
    fscanf(fin,"%d %d",&N, &M);
    fscanf(fin,"%d",&l);
    for(i=1;i<=l;i++)
    {
        fscanf(fin,"%d %d",&x,&tip);
        if(tip==1) L[x]+=1;
        else L[x]-=1;
    }
    fscanf(fin,"%d",&c);
    for(i=1;i<=c;i++)
    {
        fscanf(fin,"%d %d",&x,&tip);
        if(tip==1) C[x]+=1;
        else C[x]-=1;
    }
    int st1,fi1,poz=0,st2,fi2;
    long long int s=0,bestsum=-999999999999,mmin=0;
    for(i=1;i<=N;i++)
    {
        s+=L[i];
        if(s-mmin>bestsum) {bestsum=s-mmin; st1=poz+1; fi1=i;}
        else if(s-mmin==bestsum&&i-poz>fi1-st1+1) {bestsum=s-mmin; st1=poz+1; fi1=i;}
        if(s<mmin) {mmin=s; poz=i;}
    }
    s=0; bestsum=-999999999999; mmin=0,poz=0;
    for(i=1;i<=M;i++)
    {
        s+=C[i];
        if(s-mmin>bestsum) {bestsum=s-mmin; st2=poz+1; fi2=i;}
        else if(s-mmin==bestsum&&i-poz>fi2-st2+1) {bestsum=s-mmin; st2=poz+1; fi2=i;}

        if(s<mmin) {mmin=s; poz=i;}
    }
    fprintf(fout,"%d %d %d %d\n",st1,st2,fi1,fi2);
    return 0;
}

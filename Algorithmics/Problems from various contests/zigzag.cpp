#include <fstream>
#include<cstdio>
using namespace std;
FILE*  fin=fopen("zigzag.in","r");
ofstream fout("zigzag.out");

char sir[50001],c;
int main()
{
    int k,n,pozlast,i,l1,l2,q,h;
    fscanf(fin,"%d %d\n",&k,&n);
    fscanf(fin,"%c",&sir[0]);
    q=0;
    pozlast=0;
    h=(k-1)*2;
    int par=1;
    int incep=n/h;
    int sf=incep;
    if(n%h!=0) incep++;
    if(n%h==k) sf++;
    for(i=1; i<incep; i++)
    {
        fscanf(fin,"%c",&c);
        sir[pozlast+h]=c;
        pozlast+=h;
    }
    for(i=incep; i<n-sf; i++)
    {
        fscanf(fin,"%c",&c);
        l1=(k-1)*2;
        l2=h-l1;
        if(pozlast+l1<n&&par)
        {
            sir[pozlast+l1]=c;
            pozlast+=l1;
            par=0;
        }
        else if(pozlast+l2<n&&!par)
        {
            sir[pozlast+l2]=c;
            pozlast+=l2;
            par=1;
        }
        else
        {
            k--;
            sir[++q]=c;
            pozlast=q;
            par=1;
        }
    }
     if(pozlast>q)
     {
         fscanf(fin,"%c",&c);
            sir[++q]=c;
            pozlast=q;
     }
    for(i=n-sf; i<n; i++)
    {
        fscanf(fin,"%c",&c);
        sir[pozlast+h]=c;
        pozlast+=h;
    }
    fout<<sir<<'\n';
    return 0;
}

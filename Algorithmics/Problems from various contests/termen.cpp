#include <cstdio>

using namespace std;
FILE* fin=fopen("termen.in","r");
FILE* fout=fopen("termen.out","w");

int main()
{
    int n,p,q,a,b,i,min,max,S,ss,Sp;
    fscanf(fin,"%d %d %d",&n,&p,&q);
    fscanf(fin,"%d %d",&a,&b);
    min=a, max=b, S=0;
    for(i=1; i<n; i++)
    {
        fscanf(fin,"%d",&ss);
        if(i==p ) Sp=S;
        S=ss-S;
        if(i%2==1)
        {
            if(S-b>min) min=S-b;
            if(S-a<max) max=S-a;
        }
        else
        {
            if(a-S>min)  min=a-S;
            if(b-S<max)  max=b-S;
        }
    }
    if(q%2==1)
    {
        if(p%2==1) fprintf(fout,"%d\n",Sp+min);
        else fprintf(fout,"%d\n",Sp-min);
    }
    else
    {
        if(p%2==1) fprintf(fout,"%d\n",Sp+max);
        else fprintf(fout,"%d\n",Sp-max);
    }
    return 0;
}

#include <cstdio>
#include<cstring>
using namespace std;
FILE* fin=fopen("cool.in","r");
FILE* fout=fopen("cool.out","w");

int B[5005];
int A[1005];
int main()
{
    int p,N,K,i;
    fscanf(fin,"%d",&p);
    fscanf(fin,"%d %d",&N,&K);
    if(p==1)
    {
        int max=-1,min=1001,ok,nrd=0,x;
        for(i=1;i<=K;i++)
        {
            fscanf(fin,"%d",&x);
            A[x]++;
            if(x>max) max=x;
            if(x<min) min=x;
        }
        ok=1;
        for(i=min;i<=max;i++)
        {
            if(A[i]!=1) ok=0;
            else if(A[i]==1) nrd++;
        }
        if(ok==1) fprintf(fout,"%d\n",max);
        else fprintf(fout,"%d\n",nrd);
    }
    else if(p==2)
    {
        for(i=1;i<=N;i++)
            fscanf(fin,"%d",&B[i]);
        //Pt fiecare pozitie i, am incercat sa obtin sirul maxim care respecta cerinta;
        //Ma opresc cu incercarea atunci cand un element se repeta sau ajung la sfarsitul sirului;
        int ok=1;
        int min,max,lgmax=0,nrmax=0,j,aux;
        for(i=1;i<=N;i++)
        {
            max=B[i]; min=B[i];
            A[B[i]]=1;
            for (j=i+1; j<=N; ++j)
            {
                if(A[B[j]]==0)
                {
                    A[B[j]]=1;
                    if(B[j]>max) max=B[j];
                    if(B[j]<min) min=B[j];
                    aux=j-i+1;
                    if(max-min==aux-1)
                       {
                           if(aux>lgmax) {lgmax=aux; nrmax=1;}
                            else if(aux==lgmax) nrmax++;

                       }
                }
                else if(A[B[j]])
                    break;
            }
            memset(A, 0, sizeof(A));
        }
        fprintf(fout,"%d\n%d\n",lgmax,nrmax);
    }
    return 0;
}

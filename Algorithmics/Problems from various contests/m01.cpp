#include <cstdio>
# define LGMAX 1002
using namespace std;
FILE* fin=fopen("m01.in","r");
FILE* fout=fopen("m01.out","w");


int rz[LGMAX],n;
int rest(int i);

int main()
{
    int k,x,dif,i;
    fscanf(fin,"%d",&n);
    for(k=1;k<=n;k++)
        rz[k]=rest(k);
    for(i=1;i<=n;i++)
        if(rz[i]==0)
           {
             for(k=1;k<=i;k++)
                fprintf(fout,"1");
            fprintf(fout,"\n");
             return 0;
           }
     for(i=1;i<=n;i++)
        for(k=i+1;k<=n;k++)
            if(rz[i]==rz[k])
            {
                dif=k-i;
                for(int q=1;q<=dif;q++)
                    fprintf(fout,"1");
                for(int q=dif+1;q<=k;q++)
                    fprintf(fout,"0");
                fprintf(fout,"\n");
                return 0;
            }
}

int rest(int i)
{
    int j;
    int val=0;
    for(j=1;j<=i;j++)
    {
        val=val*10+1;
        val=val%n;
    }
    return val;
}

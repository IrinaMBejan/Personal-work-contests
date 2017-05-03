#include <fstream>

using namespace std;

FILE* fin=fopen("rucsac.in","r");
FILE* fout=fopen("rucsac.out","w");

struct obj
{
    double rap;
    int g;
};

obj a[100],aux;

int main()
{
    int c,g,n,i,gmax;
    fscanf(fin,"%d %d",&gmax,&n);
    for(i=1;i<=n;i++)
    {
        fscanf(fin,"%d %d", &c, &a[i].g);
        a[i].rap=c/g;
    }

    for (i=1;i<n;i++)
        for(j=1;j<=n;j++)
         if(a[i].rap>a[j].rap)
        {
            aux=a[i];
            a[i]=a[j];
            a[j]=aux;
        }
    int ok=1;
    i=1;
    while(ok&&gmax>=0)
    {
        if(a[i].g<=gmax) {}
    }

    return 0;
}

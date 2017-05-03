#include <fstream>
#define NMAX 101;
using namespace std;

FILE* fin=fopen("spectacole.in","r");
FILE* fout=fopen("spectacole.out","w");

struct spec
{
    int si;
    int fi;
};

spec a[101],aux;
int n;

int main()
{
    int n,i,j;
    fscanf(fin,"%d", &n);
    for(i=1;i<=n;i++)
        fscanf(fin,"%d %d",&a[i].si,&a[i].fi);
    for(i=1;i<n;i++)
     for(j=i+1;j<=n;j++)
        if(a[i].fi>a[j].fi)
        {
            aux=a[i];
            a[i]=a[j];
            a[j]=aux;
        }
    i=1;
    fprintf(fout,"%d %d\n",a[i].si,a[i].fi);
    j=1;
    while(i<=n)
    {
        i++;
        if(a[i].si>=a[j].fi)
            {
                fprintf(fout,"%d %d\n",a[i].si,a[i].fi);
                j=i;
            }

    }



    return 0;
}

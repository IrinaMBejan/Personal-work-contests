#include <fstream>
#define NMAX 31000
using namespace std;
FILE* fin=fopen("aranjare2.in","r");
FILE* fout=fopen("aranjare2.out","w");

int Vinter[2*NMAX+5],poz[2*NMAX+5];

int main()
{
    int x,i,N,k;
    fscanf(fin,"%d",&N);
    for(i=1; i<=2*N; i++)
    {
        Vinter[i]=i;
        poz[i]=i;
    }
    for(i=1; i<N; i++)
    {
        int aux;
        if(Vinter[2*i]!=N+i)
        {
            aux=Vinter[poz[N+i]];
            Vinter[poz[N+i]]=Vinter[2*i];
            poz[Vinter[2*i]]=poz[N+i];
            Vinter[2*i]=aux;
            fprintf(fout,"%d %d\n",2*i,poz[N+i]);
        }
        if(Vinter[2*i+1]!=i+1)
        {
            aux=Vinter[poz[i+1]];
            Vinter[poz[i+1]]=Vinter[2*i+1];
            poz[Vinter[2*i+1]]=poz[i+1];
            Vinter[2*i+1]=aux;
            fprintf(fout,"%d %d\n",2*i+1,poz[i+1]);

        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}


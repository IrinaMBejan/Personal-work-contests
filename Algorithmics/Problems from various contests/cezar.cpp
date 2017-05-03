#include<fstream>
#include<string.h>
using namespace std;
ifstream fin("cezar.in");
ofstream fout("cezar.out");


int main()
{
    int k[11], i, j, c,r,l,nrsp=0,nrn,kp,poz;
    char s[256];
    char q[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    fin.get(s, 256);
    for(i=1;i<=10;i++)
    fin>>k[i];
    l=strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i]==' ') { nrsp++; fout<<s[i];}
        else
         {
             nrn=i-nrsp;
             r=nrn%10;
             r++;
             if(r==0) r=10;
             //a[r];
             poz=s[i]-65-k[r];
             if(poz<0) poz+=26;
             if(poz>25) poz-=26;
             fout<<q[poz];
         }

    }

 return 0;
}

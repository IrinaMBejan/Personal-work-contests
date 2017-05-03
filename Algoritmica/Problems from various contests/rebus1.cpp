#include <fstream>
#include<cstring>
#define Nmax 100005
using namespace std;
ifstream fin("rebus1.in");
ofstream fout("rebus1.out");

struct cuvant
{
    char c[50];
    int lin, col;
    char P;
} E[Nmax];
char *q,p[Nmax], s[Nmax];
int l[Nmax],c[Nmax];
int main()
{
    int N;
    fin>>N;
    fin.get();
    fin.getline(s,Nmax);
    int Lg=strlen(s);
    int k=0,d;
    for( d=2; d*d<Lg; d++)
        if(Lg% d == 0)
        {
            l[++k] = d;
            c[k]=Lg/d;
        }
    if(d*d==Lg)
        l[++k]=c[k]=d;
    for(int i=1; i<=k; i++)
        if(l[i]>=2 && l[i]<=100 && c[i]>=2 && c[i]<=100)
        {
            int Z=0;
            int L=l[i], C=c[i], plin=1, pcol=0;
            strcpy(p,s);
            q=strtok(p," ");
            while(q!=NULL)
            {
                pcol++;
                int lg=strlen(q)-1,j=0;
                while(j<=lg)
                {
                    Z++;
                    E[Z].col=pcol;
                    E[Z].lin=plin;
                    while(pcol<=C+1 && j<=lg)
                        E[Z].c[j]=q[j],j++,pcol++;
                    if(pcol == C+1) pcol=0, plin++;
                    if(L<C) E[Z].P='O';
                    else E[Z].P='V';
                }
                q=strtok(NULL," ");

                L=c[i], C=l[i], plin=0, pcol=1;
            if(Z==N)
            {
                for(int i=1; i<=Z; i++)
                    fout<<E[i].c<<" "<<E[i].lin<<" "<<E[i].col<<" "<<E[i].P<<'\n';
            }

        }
}

return 0;
}

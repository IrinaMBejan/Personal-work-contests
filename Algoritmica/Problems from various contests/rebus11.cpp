#include <fstream>
#include<cstring>
#define Nmax 10005
using namespace std;
ifstream fin("rebus1.in");
ofstream fout("rebus1.out");

struct cuvant
{
    char c[50];
    int lin, col;
    char P;
} E[Nmax],aux;
void sortare();
char v1[105][105],v2[105][105];
char *q,p[Nmax],s[Nmax];
int l[Nmax],c[Nmax];
int Z;
int pcol;
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
            Z=0;

            k=0;
            for(int q1=0; q1<l[i]; q1++)
                for(int q2=0; q2<c[i]; q2++)
                    v1[q1][q2]=s[k++];
            for(int q1=0; q1<l[i]; q1++)
            {
                q=strtok(v1[q1],"       ");
                pcol=0;
                while(v1[q1][pcol]==' ' && pcol<c[i]) pcol++;
                while(q!=NULL)
                {
                    int lg=strlen(q);

                    int f=0;
                    while(v2[q1][pcol+lg+1+f]==' ' && pcol+lg+1+f<l[i]) f++;
                    if(lg!=1)
                    {
                        ++Z;
                        strcpy(E[Z].c,q);
                        E[Z].lin=q1+1;
                        E[Z].col=pcol+1;
                        if(v1[q1][0]==' ')
                            E[Z].col++;
                        E[Z].P='O';
                    }
                    if(pcol+lg>c[i])
                        pcol=lg+1;
                    else
                        pcol+=lg+1;
                    while(v1[q1][pcol]==' ' && pcol<c[i]) pcol++;
                    pcol+=f;

                    q=strtok(NULL,"       ");
                }
            }

            k=0;
            for(int q1=0; q1<l[i]; q1++)
                for(int q2=0; q2<c[i]; q2++)
                    v2[q2][q1]=s[k++];

            for(int q1=0; q1<c[i]; q1++)
            {
                 pcol=0;
                while(v1[q1][pcol]==' ') pcol++;
                q=strtok(v2[q1],"       ");
                while(q!=NULL)
                {
                    int lg=strlen(q);
                    int f=0;
                    while(v2[q1][pcol+lg+1+f]==' ' && pcol+lg+1+f<l[i]) f++;

                    if(lg!=1)
                    {
                        ++Z;
                        strcpy(E[Z].c,q);
                        E[Z].lin=pcol+1;
                        if(v2[q1][0]==' ')
                            E[Z].lin++;
                        E[Z].col=q1+1;
                        E[Z].P='V';
                    }

                    if(pcol+lg+1>l[i])
                        pcol=lg+1;
                    else
                        pcol+=lg+1;
                    while(v1[q1][pcol]==' ' && pcol<l[i]) pcol++;
                    pcol+=f;
                    q=strtok(NULL,"       ");
                }
            }

            for(int q1=0; q1<l[i]; q1++)
                for(int q2=0; q2<c[i]; q2++)
                    v2[q2][q1]=v1[q1][q2]=0;
            if(Z==N)
            {
                fout<<l[i]<<" "<<c[i]<<'\n';
                sortare();
                for(int i=1; i<=Z; i++)
                    fout<<E[i].c<<" "<<E[i].lin<<" "<<E[i].col<<" "<<E[i].P<<'\n';

                return 0;
            }

        }
    return 0;
}

void sortare()
{
    int ok=0;
    while(!ok)
    {
        ok=1;
        for(int i=1; i<=Z; i++)
            for(int j=i+1; j<=Z; j++)
            {
                int r=strcmp(E[i].c,E[j].c);
                if(r>0||(r==0 && E[i].lin>E[j].lin)||(r==0 && E[i].lin==E[j].lin&&E[i].col>E[j].col))
                {
                    aux=E[i];
                    E[i]=E[j];
                    E[j]=aux;
                    ok=0;
                }
            }
    }
}

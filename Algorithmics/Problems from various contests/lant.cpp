#include <fstream>
#include <cstring>
#include <cstdlib>
#define InFile "lant.in"
#define OutFile "lant.out"
#define LgMaxC 31
#define NrMaxC 151
typedef char Cuvant[LgMaxC];
using namespace std;

Cuvant c[NrMaxC];
int nc, k;
int a[NrMaxC][NrMaxC];
int d[LgMaxC+1][LgMaxC+1];
long int nr[NrMaxC];

void Citire();
void ConstrGraf();
void Numara(int);

int main()
{
    int i;
    ofstream fout(OutFile);
    Citire();
    ConstrGraf();
    Numara(0);
    fout<<nr[0]<<endl;
    fout.close();
}

void Adauga_Cuvant(char *p)
{
    int i;

    for (i=0; i<nc && strcmp(p,c[i]); i++);
    if (i==nc) strcpy(c[nc++],p);

}


void Citire()
{
    ifstream fin(InFile);
    char s[1001], *p;
    fin>>k;
    fin.get();
    while (!fin.eof())
    {
        fin.getline(s,1001);
        if (fin.good())
        {
            p=strtok(s," ,.:;?!-");
            while (p)
            {
                Adauga_Cuvant(p);
                p=strtok(NULL," ,.:;?!-");
            }
        }
    }
    fin.close();
}

int dist (char *p, char *q)
{
    int n, m, i, j;

    n=strlen(p);
    m=strlen(q);
    for (i=0; i<=n; i++) d[i][m]=n-i;
    for (j=0; j<=m; j++) d[n][j]=m-j;
    for (i=n-1; i>=0; i--)
        for (j=m-1; j>=0; j--)
        {
            d[i][j]=1+d[i][j+1];
            if (d[i][j]>1+d[i+1][j])
                d[i][j]=1+d[i+1][j];
            if (p[i]==q[j] && d[i][j]>d[i+1][j+1])
                d[i][j]=d[i+1][j+1];
        }
    return d[0][0];
}

void ConstrGraf()
{
    int i, j;
    for (i=0; i<nc; i++)
        for (j=i+1; j<nc; j++)
            if (dist(c[i],c[j])<=k)
            {
                a[i][0]++;
                a[i][a[i][0]]=j;
            }
}


void Numara(int vf)
{
    int i;
    if (!a[vf][0])
    {
        nr[vf]=1;
        return;
    }
    long int s=0;
    for (i=1; i<=a[vf][0]; i++)
    {
        if (nr[a[vf][i]]==0)
            Numara(a[vf][i]);
        s+=nr[a[vf][i]];
    }
    nr[vf]=s;
}


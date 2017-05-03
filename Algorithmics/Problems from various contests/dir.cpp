#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("dir.in");
ofstream fout("dir.out");

typedef char Nume[31];
char s[1601];
char a[100][256];

Nume sol[200];

int poz=0, nr=0;
int nrsol=0;

void citire();
void stru();
void fisier();
void afisare();
void sortare();

int main()
{
    citire();
    stru();
    sortare();
    afisare();
    return 0;
}


void citire()
{
    fin.getline(s,1600);
}


void stru()
{
    char *p;
    if (!s[poz])
        return;
    p=strchr (s+poz,'(');
    *p=NULL;
    strcpy(sol[nr++],s+poz);
    poz+=strlen(s+poz)+1;
    if (s[poz]==')')
    {
        nr--;
        poz++;
    }
    else
    {
        do
        {
            if (s[poz]>='A' && s[poz]<='Z')
                stru();
            else if (s[poz]>='a' && s[poz]<='z')
                fisier();
            if (s[poz++]==')') break;
        }
        while (1);
        nr--;
    }
}


void fisier()
{
    char nf[31];
    int i;
    for (i=poz; s[i]>='a' && s[i]<='z' || s[i]<='9' && s[i]>='0'; i++)
        nf[i-poz]=s[i];
    nf[i-poz]=NULL;
    for (i=0; i<nr; i++)
    {
        strcat(a[nrsol],sol[i]);
        strcat(a[nrsol],"\\");
    }
    strcat(a[nrsol],nf);
    nrsol++;
    poz+=strlen(nf);
}


void afisare()
{
    int i;
    fout<<nrsol<<'\n';
    for (i=0; i<nrsol; i++)
        fout<<a[i]<<'\n';
}


void sortare(void)
{
    int i, ok;
    char aux[256];
    do
    {
        ok=1;
        for (i=0; i<nrsol-1; i++)
            if (strcmp(a[i],a[i+1])>0)
            {
                strcpy(aux,a[i]);
                strcpy(a[i],a[i+1]);
                strcpy(a[i+1],aux);
                ok=0;
            }
    }
    while (!ok);
}

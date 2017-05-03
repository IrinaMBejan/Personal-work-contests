#include <fstream>
#include <cstring>
#include <cstdlib>
#define Nmax 100005
#define Imax 15
using namespace std;

ifstream fin("ed.in");
ofstream fout("ed.out");

char s[Nmax],aux[Nmax];
char ins[Imax];
char *p,*q;
int N,poz;

void Citire();
void Lop();
void Rop();
void Bop();
void Iop();
void Dop(int);
void Afisare();

int main()
{
    Citire();
    Afisare();
}

void Citire()
{
    int i;
    fin.getline(s, 50001);
    fin>>N; fin.get();
    poz = strlen(s);
    for(i = 0; i<N; i++)
    {
        fin.getline(ins,Imax);
        if(ins[0] == 'L')
            Lop();
        else if(ins[0] == 'R')
            Rop();
        else if(ins[0] == 'B')
            Bop();
        else if(ins[0] == 'I')
            Iop();
        else if(ins[0] == 'D')
        {
            *(ins)=0;
            strcat(ins, ins+1);
            Dop(atoi(ins));
        }
    }
}

void Lop()
{
    if (poz>0) poz-=1;
}

void Rop()
{
    if(s[poz] != '\0')
                poz+=1;
}

void Bop()
{
    if(poz>0)
            {
                *(s+poz-1) = 0;
                strcat(s,s+poz);
                poz-=1;
            }
}

void Iop()
{
            strcpy(aux,s);
            *(aux+poz) = 0;
            strcat(aux,ins+1);
            strcat(aux,s+poz);
            strcpy(s,aux);
}

void Dop(int nr)
{
            if(poz+nr>=strlen(s))
                *(s+poz) = 0;
            else
            {
                *(s+poz) = 0;
                strcat(s, s+poz+nr);
            }
}

void Afisare()
{
    fout<<s<<'\n';
    fout.close();
}

#include <fstream>
#include<cstring>
#define Nmax 2000
using namespace std;


ifstream fin("convp.in");
ofstream fout("convp.out");

char s[Nmax], p[Nmax];
int Lg,k;

void Cit();
void ConvExp(int& poz);
void ConvTerm(int& poz);
void ConvFac(int& poz);
void Afis();

int main()
{
    Cit();
    int poz = 0;
    ConvExp(poz);
    Afis();
    return 0;
}

void Cit()
{
    fin.getline(s,1950);
    fin.get();
    Lg=strlen(s);
}

void ConvExp(int& poz)
{
    ConvTerm(poz);
    if(s[poz] == '+')
    {
        ConvExp(++poz);
        p[k++] = '+';
    }
}

void ConvTerm(int& poz)
{
    ConvFac(poz);
    if(s[poz] == '*')
    {
        ConvTerm(++poz);
        p[k++] = '*';
    }
}

void ConvFac(int &poz)
{
    if(s[poz] != '(')
        p[k++]=s[poz++];
    else
    {
        ConvExp(++poz);
        poz++;
    }
}

void Afis()
{
    fout<<p<<'\n';
}

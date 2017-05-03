#include <fstream>
#include<cstring>
#define Nmax 2000
using namespace std;

ifstream fin("exp.in");
ofstream fout("exp.out");

char s[Nmax];
int val[30];

void Cit();
int Exp(int& poz);
int Fac(int& poz);

int main()
{
    Cit();
    int poz = strlen(s)-1;
    fout<<Exp(poz)<<'\n';
    return 0;
}

void Cit()
{
    fin.getline(s,1950);
    int n,nr; char c; fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>c>>nr;
        val[c-'a']=nr;
    }
}

int Exp(int& poz)
{
    if(s[poz] == '+')
        return Exp(--poz)+Exp(--poz);
    if(s[poz] == '*')
        return Exp(--poz)*Exp(--poz);

    return Fac(poz);
}

int Fac(int &poz)
{
    if(s[poz]>='0' && s[poz]<='9')
        return s[poz]-'0'; //e const
    else//e litera
        return val[s[poz]-'a'];
}

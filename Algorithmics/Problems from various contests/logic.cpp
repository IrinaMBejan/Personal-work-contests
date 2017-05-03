#include <fstream>
#include<cstring>
#define Lgmax 250
using namespace std;
ifstream fin("logic.in");
ofstream fout("logic.out");
int Nr;
char s[Lgmax];
bool formula( int& poz );
bool echiv( int& poz );
bool imp( int& poz);
bool disj( int& poz);
bool conj( int& poz);

int get_bit(int decimal, int N);
int detnr();
int ech[3][3],impo[3][3];
int w[30], frecv[30];

int main()
{
    int N,i,poz;
    ech[0][0]=ech[1][1]=impo[0][0]=impo[0][1]=impo[1][1]=1;
    fin.getline(s,Lgmax);
    int t=0;
    int nrv=1<<detnr();
    for (Nr=0; Nr<nrv; Nr++)
    {
        poz=0;
        if(echiv(poz)) t++;
    }
    fout<<t<<'\n';
    return 0;
}

bool formula(int& poz)
{
    bool ok=0;
    if(s[poz] == '~')
        ok=1;
    if(s[poz]>='a'&&s[poz]<='z')
    {
        ++poz;
        if(ok)
            return !get_bit(Nr,w[s[poz-1]-'a']);
        else
            return get_bit(Nr,w[s[poz-1]-'a']);
    }
    else if(s[poz]=='(')
    {
        int x=echiv(++poz);
        ++poz;
        if(ok)
            return !x;
        else
            return x;
    }
    else
    {
        int q= formula(++poz);
        if(ok)
            return !q;
        else
            return  q;
    }
}

bool echiv(int &poz)
{
    int p1 = imp(poz);
    while(s[poz]=='<')
    {
        int p2 = echiv(poz+=3);
        p1 = ech[p1][p2];
    }
    return p1;
}

bool imp(int &poz)
{
    int p1 = disj(poz);
    while(s[poz]=='=')
    {
        int p2 = imp(poz+=2);
        p1 = impo[p1][p2];
    }
    return p1;
}

bool disj(int &poz)
{
    int p1 = conj(poz);
    while(s[poz]=='|')
    {
        int p2 = disj(++poz);
        p1 = (p1||p2);
    }
    return p1;
}

bool conj(int &poz)
{
    int p1 = formula(poz);
    while(s[poz]=='&')
    {
        int p2 = conj(++poz);
        p1 = (p1 &&p2);
    }
    return p1;
}

int get_bit(int decimal, int N)
{
    int constant = 1 << (N-1);
    if( decimal & constant )
        return 1;
    return 0;
}

int detnr()
{

    for(int i=0; i<=27; i++)
        w[i]=frecv[i]=0;
    int l = strlen(s);
    int contor=0;
    for (int i=0; i<l; i++)
        if(s[i]>='a'&&s[i]<='z')
            if(frecv[s[i]-'a']== 0)
            {
                frecv[s[i]-'a'] =1;
                w[s[i]-'a']=++contor;
            }
    return contor;
}

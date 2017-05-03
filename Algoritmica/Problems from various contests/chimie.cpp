#include <fstream>
#include <cstring>
#define Lmax 110
using namespace std;

ifstream fin("chimie.in");
ofstream fout("chimie.out");
char sM[Lmax],s[Lmax];
int vM[800],v[800];

bool coincide();
void compus(int & poz, int nrm);
void atom (int & poz, int nrm);
void formula(int & poz);
int nr (int & poz);
int main()
{
    int N, poz = 0;
    fin.getline(s,Lmax);
    strcpy(sM,s);
    formula(poz);
    for(int i=0; i<750; i++)
        vM[i]=v[i], v[i]=0;

    fin>>N;
    fin.get();
    for(int i=1; i<=N; i++)
    {
        fin.getline(s,Lmax);
        poz = 0;
        formula(poz);
        if(coincide())
            fout<<sM<<"=="<<s<<'\n';
        else
            fout<<sM<<"!="<<s<<'\n';

        for(int j = 0; j<=750; j++)
            v[j]=0;
    }
    return 0;
}

bool coincide()
{
    int i;
    for( i = 0; i<= 750; i++)
        if(vM[i] != v[i])
            return 0;
    return 1;
}

void formula( int & poz)
{
    int q = nr(poz);
    compus(poz, q);
    while (s[poz] == '+' || (s[poz] >='A' && s[poz]<='Z'))
    {
        if(s[poz] == '+')
            formula(++poz);
        else
            formula(poz);
    }
}

void compus(int & poz, int nrm)
{
    while( (s[poz]>='A' && s[poz]<='Z') || s[poz] == '(')
    {
        if(s[poz]!='(')
        {
            int p = poz+1;
            if ( s[p]>='a' && s[p] <='z')
                p++;
            int q= nr(p);
            atom(poz, nrm*q);
            poz = p;
        }
        else
        {
            ++poz;
            int p = poz;
            int nrd = 1, nri = 0;
            while ( nrd != nri)
            {
                if(s[p] == ')') nri++;
                if(s[p]== '(') nrd++;
                p++;

            }
            int q= nr(p);
            compus(poz, nrm*q);
            poz = p;
        }
    }
}

void atom(int & poz, int nrm)
{
    if(s[poz+1]>='a' && s[poz+1]<='z')
        v[(s[poz]-'A'+1)*27+(s[poz+1]-'a'+1)] +=nrm, poz+=2;
    else
        v[(s[poz]-'A'+1)*27]+=nrm, ++poz;

}

int nr(int & poz)
{
    int x=0;
    while(s[poz] >='0' && s[poz]<='9')
        x=x*10+(s[poz++]-'0');
    if(x)
        return x;
    return 1;
}

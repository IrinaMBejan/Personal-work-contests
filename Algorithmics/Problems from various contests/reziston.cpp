#include <cstdio>
#include <cstring>
using namespace std;

FILE* fin=fopen("reziston.in","r");
FILE* fout=fopen("reziston.out","w");

char s[1001];
int Lg, poz;

long long int rezs();
long long int rezp();

int main()
{

    fscanf(fin, "%s", s);
    Lg = strlen(s);

    fprintf(fout, "%lld", rezs());

    return 0;
}

long long int rezs()
{
    int S=0;
    while(poz < Lg && s[ poz ] != ','  && s[poz] != ')' )
    {
        if(s[poz] == 'R')
        {
            poz++;
            int x=0;
            while(s[poz] >='0' && s[poz]<='9')
            {
                x=x*10 + s[poz] -'0';
                poz++;
            }
            S+=x;
        }
        else if(s[poz] == '(')
            S+=rezp(),poz++;
    }
    return S;
}

long long int rezp ()
{
    int P=1, S=0,nr;
    while ( s[poz] != ')')
    {
        if( s[poz] == '(' || s[poz] == ',')
            poz++, nr = rezs(), P*=nr ,S+=nr;
    }
    return P/S;
}

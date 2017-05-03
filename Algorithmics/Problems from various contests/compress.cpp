#include <fstream>
#include <cstring>
#define Lm 10050
using namespace std;
ifstream fin("compress.in");
ofstream fout("compress.out");
char s[Lm],p[Lm];
int L;
void solve(int & poz, int & k);
int num(int & poz);

int main()
{
    fin.getline(s,Lm);
    L = strlen(s);
    int poz, k = 0;
    for( poz = 0; poz < L; poz++)
        if(s[poz]== '(')
            solve(poz, k);
        else p[k++] = s[poz];
    fout<<p<<'\n';
    return 0;
}
int k;

void solve(int & poz, int & k)
{
    int st = k+1, en, nr;

    while(s[poz]!=')' && s[poz])
    {
        if(s[poz]=='(')
            solve(++poz,k);
        else
            p[k++] = s[poz++];
    }
    poz++;
    nr = num(poz);
    en=k;
    for (int i = 0; i <nr-1; i++)
        for( int j = st-1; j<en; j++)
        {
            p[k++] = p[j];
        }
   // k++;
}

int num(int & poz)
{
    int x=0;
    while(s[poz] >='0' && s[poz]<='9')
        x=x*10+(s[poz++]-'0');
    if(x)
        return x;
    return 1;
}

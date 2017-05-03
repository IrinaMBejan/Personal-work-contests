#include <fstream>
#include <cstring>

using namespace std;
ifstream fin("opmult.in");
ofstream fout("opmult.out");

char s[2005],op[1005];
int n,l,i,x,j,k,ko,v[256];

struct inter
{
    int a,b;
} S[1005];


int numar()
{
    int a=0;
    while(s[i]>='0'&&s[i]<='9')
        a=a*10+(s[i]-'0'),i++;
    return a;
}

void adauga(int a, int b)
{
    for(int i=a; i<=b; i++)
        v[i]=1;
}
void elimina(int a, int b)
{
    for(int i=a; i<=b; i++)
        v[i]=0;
}

void interval()
{
    char p=s[i];
    i++;
    int a=numar();
    i++;
    int b=numar();
    if(p=='(') a++;
    if(s[i]==')')b--;
    k++;
    if(a<=b) S[k].a=a,S[k].b=b;
    else S[k].a=S[k].b=0;
    i++;
}

void zero()
{
    for(int i=1; i<=255; i++)
        v[i]=0;
}

int main()
{
    fin>>n;
    fin.get();
    while(n)
    {
        fin.getline(s,2005);
        zero();
        i=x=k=ko=0;
        while(s[i]!=' ')
            x=x*10+(s[i]-'0'),i++;
        l=strlen(s);
        i++;
        while(i<l)
            if(s[i]=='[' || s[i]=='(')
               interval();
            else
                if(s[i]=='n')
                {
                    i++;
                    interval();
                    if(S[k].a>S[k-1].a) S[k-1].a=S[k].a;
                    if(S[k].b<S[k-1].b) S[k-1].b=S[k].b;
                    k--;
                    if(S[k].a>S[k].b) S[k].a=S[k].b=0;
                }
                else
                {
                    ko++;
                    op[ko]=s[i];
                    i++;
                }
            n--;
            j=1;
            adauga(S[1].a,S[1].b);
            for(i=1; i<=ko; i++)
            {
                j++;
                if(x>=S[j].a && x<=S[j].b)
                {
                    if(op[i]=='u')
                        adauga(S[j].a,S[j].b);
                    else
                        elimina(S[j].a,S[j].b);
                }
            }
            if(v[x]==1)
                fout<<"DA\n";
            else
                fout<<"NU\n";
        }
    return 0;
}

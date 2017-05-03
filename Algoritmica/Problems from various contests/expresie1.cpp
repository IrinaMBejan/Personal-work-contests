#include <cstdio>
#include<algorithm>
#define Nmax 100004
using namespace std;

FILE* fin=fopen("expresie1.in","r");
FILE* fout=fopen("expresie1.out","w");

int Nr = 0;
int fi,N2;
char s[Nmax];
int v[Nmax];

int suma(int& poz, int& fi);
int termen(int& poz, int& fi);
int numar(int& poz);
int ppat(int& poz, int& fi);
int prot(int& poz, int& fi);
int SubsMax(int a, int b);
int ElemM(int a,int b);


int main()
{
    fscanf(fin,"%s",s);
    int poz = 0;
    int fi=0;
    fprintf(fout,"%d\n%d\n",Nr,suma(poz,fi));
    return 0;
}

int suma(int& poz, int& fi)
{
    int R;
    R=termen(poz,fi);
    while (s[poz] == ',')
        R+=suma(++poz,fi);
     return R;
}

int termen(int& poz, int& fi)
{
    int k = fi;
    if(s[poz] == '[')
        {
            int x;
           x=ppat(++poz,fi);
           ++poz;
           fi=k;
           return x;
        }

     if(s[poz] == '(')
        {
            int x;
           x=prot(++poz,fi);
           ++poz;
           fi=k;
           return x;
        }
    fi=k;
    return numar(poz);
}

int numar(int& poz)
{
    Nr++;
    if(s[poz] == '-')
    {
        poz++;
        int x=0;
        while(s[poz]>='0' && s[poz] <='9')
            x=x*10+s[poz++]-'0';
        return x*(-1);
    }
    else
    {
        int x=0;
        while(s[poz]>='0' && s[poz] <='9')
            x=x*10+s[poz++]-'0';
        return x;
    }
}

int ppat(int & poz, int&fi)
{
    int st = fi+1;
    v[++fi]=termen(poz,fi);
    while (s[poz] == ',')
               v[++fi]=termen(++poz,fi);
     return ElemM(st, fi);
}

int prot(int & poz, int &fi)
{
    int st=fi+1;
    v[++fi]=termen(poz,fi);
    while (s[poz] == ',')
               v[++fi]=termen(++poz,fi);
     return SubsMax(st,fi);
}

int SubsMax(int a, int b)
{
    int S=0, MaxSum = -999999999, mmin = 0;
    for( int i=a; i<=b; i++)
    {
        S+=v[i];
        if(S-mmin>MaxSum)
            MaxSum=S-mmin;
        if(mmin>S)
            S=mmin;
    }
    return MaxSum;
}

int ElemM(int a, int b)
{
    sort(v+a,v+b+1);
    return v[(a+b)/2];
}

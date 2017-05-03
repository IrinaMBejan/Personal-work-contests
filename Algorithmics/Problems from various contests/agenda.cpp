#include <fstream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define Lmax 1001
#define Nmax 10000

using namespace std;
ifstream fin("agenda.in");
ofstream fout("agenda.out");
int nr, nrp;
struct sef
{
    int ts, tf;
} S[Nmax];

struct ext
{
    int t, s, tip;
} E[2*Nmax];
int c;

char sir[Lmax], s[Lmax];
char Luna[12][20]= {"ianuarie", "februarie", "martie", "aprilie", "mai", "iunie",
                    "iulie", "august", "septembrie", "octombrie", "noiembrie", "decembrie"
                   };
int zile[12]= {0,31,59,90,120,151,181,212,243,273,304,334};

void citire();
void low(char *s);
void maxlength();
void simultmax();
void nesimultmax();
bool cifra(char c);
void extrage(char *s, int &z, char *l, int &h, int &m);
int timp(int z, char * l, int h, int m);
bool compare2(sef a, sef b)
{
    return a.ts < b.ts || a.ts==b.ts && a.tf>b.tf;
}

bool compare(ext a, ext b)
{
    return a.t<b.t || a.t==b.t && a.tip>b.tip;
}

int main()
{
    citire();
    if (c==1) maxlength();
    else
    {

        if (c==2) simultmax();
        else nesimultmax();
    }
    fout.close();
    return 0;
}

void citire()
{
    int zs, zf, hs, hf, ms, mf, i, j;
    char ls[20], lf[20], *p;
    fin>>c;
    fin.get();
    while (fin.getline(sir,Lmax))
    {
        for (j=i=0; sir[i]; i++) if (sir[i]!=' ') s[j++]=sir[i];
        s[j]=0;
        p=strchr(s,'-');
        *p=0;
        extrage(s,zs,ls,hs,ms);
        extrage(p+1,zf,lf,hf,mf);
        S[++nr].ts=timp(zs,ls,hs,ms);
        S[nr].tf=timp(zf,lf,hf,mf);
        E[++nrp].t=S[nr].ts;
        E[nrp].tip=0;
        E[nrp].s=nr;
        E[++nrp].t=S[nr].tf;
        E[nrp].tip=1;
        E[nrp].s=nr;
    }
}

int timp(int z, char * l, int h, int m)
{
    int i;
    low(l);
    for (i=0; strcmp(l,Luna[i]); i++);
    return (zile[i]+z-1)*1440+h*60+m;
}

void maxlength()
{
    int dmax=0, Z, H, M, i;
    for (i=1; i<=nr; i++)
        if (S[i].tf-S[i].ts>dmax)
            dmax=S[i].tf-S[i].ts;
    Z=dmax/1440;
    H=(dmax%1440)/60;
    M=(dmax%1440)%60;
    fout<<Z<<' '<<H<<' '<<M<<'\n';
}

void simultmax()
{
    int i, lg=0, lgmax=0;
    sort(E+1, E+nrp+1, compare);
    for (i=1; i<=nrp; i++)
    {
        if (E[i].tip) lg--;
        else lg++;
        if (lg>lgmax) lgmax=lg;
    }
    fout<<lgmax<<'\n';
}

void nesimultmax()
{
    int lg, tmax=0, i, Z, H, M;
    sort(S+1,S+nr+1,compare2);
    lg=S[1].tf;
    for (i=2; i<=nr; i++)
        if (S[i].ts<=lg)
        {
            if (S[i].tf>lg) lg=S[i].tf;
        }
        else
        {
            if (tmax<S[i].ts-lg) tmax=S[i].ts-lg;
            lg=S[i].tf;
        }
    Z=tmax/1440;
    H=(tmax%1440)/60;
    M=(tmax%1440)%60;
    fout<<Z<<' '<<H<<' '<<M<<'\n';
}

bool cifra(char c)
{
    return c>='0' && c<='9';
}

void extrage(char *s, int &zs, char *ls, int &hs, int &ms)
{
    int i, j;
//zi
    i=0;
    zs=s[i++]-'0';
    if (cifra(s[i])) zs=zs*10+s[i++]-'0';
//luna
    j=0;
    while (!cifra(s[i])) ls[j++]=s[i++];
    ls[j]=0;
    //ora
    hs=s[i++]-'0';
    if (cifra(s[i])) hs=hs*10+s[i++]-'0';
    i++; //sar.
    //minutul
    ms=s[i++]-'0';
    if (cifra(s[i])) ms=ms*10+s[i++]-'0';
}

void low(char *s)
{
   while(*s)
   {
      if ( *s >= 'A' && *s <= 'Z' )
         *s = *s + 32;
      s++;
   }
}

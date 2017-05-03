#include <fstream>
#include <cstring>
#define LgMax 210
#define Inf 2000000000
#define R 1000003
using namespace std;

ifstream fin("text.in");
ofstream fout("text.out");

char s[LgMax], v[]="aeiouy";
int n, lg, actual;
int poz[LgMax];
long int nr[LgMax][2];

long int cost[LgMax][2];
unsigned char urm[LgMax][LgMax];


void Citire ();
void Afisare ();
void Pozitie();
void Modalitati();
void Cost();

int main ()
{
    int i, j, k;    Citire ();
    Pozitie();
    Modalitati ();
    Cost();
    Afisare();
    return 0;
}

void Citire ()
{
    fin.getline(s, LgMax);
    lg=strlen(s);
    fin>>n;
}

void Pozitie()
{
    int i, last=-1;
    for (i=lg-1; i>=0; i--)
    {
        if (strchr(v,s[i]))last=i;
        poz[i]=last;
    }
}

void Modalitati ()
{
    int i, k, t, ok;
    long int sum;
    actual=0;
    for (i=0; i<lg; i++)
        if (poz[i]!=-1 && lg-i<=20) nr[i][0]=1;
        else
            nr[i][0]=-1;

    for (k=2; k<=n; k++)
    {
        actual=1-actual;
        for (i=lg-1; i>=0; i--)
        {
            nr[i][actual]=-1;
            sum=0;
            ok=0;
            for (t=1; t<=20 && i+t-1<lg; t++)
            {
                if (poz[i]==-1 || i+t-1 <poz[i]) continue;
                if (nr[i+t][1-actual]!=-1)
                {
                    ok=1;
                    sum=(sum+nr[i+t][1-actual])%R;
                }
            }
            if (ok) nr[i][actual]=sum;
        }
    }
}


void Cost ()
{
    int i, k, t, tmin;
    long int min;

    actual=0;
    for (i=0; i<lg; i++)
    {
        if (poz[i]!=-1 && lg-i<=20)
        {
            cost[i][0]=(lg-i)*(lg-i);
            urm[i][1]=lg;
        }
        else
        {
            cost[i][0]=Inf;
            urm[i][1]=0;
        }
    }
    for (i=0; i<=lg; i++) urm[lg][i]=0;
    cost[lg][0]=cost[lg][1]=Inf;

    for (k=2; k<=n; k++)
    {
        actual=1-actual;
        for (i=lg-1; i>=0; i--)
        {
            cost[i][actual]=Inf;
            urm[i][k]=0;
            min=Inf;
            tmin=-1;

            for (t=1; t<=20 && i+t-1<lg; t++)
            {
                if (poz[i]==-1 || i+t-1 <poz[i]) continue;
                if (cost[i+t][1-actual]==Inf) continue;

                if (cost[i+t][1-actual]+t*t<min)
                {
                    min=cost[i+t][1-actual]+t*t;
                    tmin=t;
                }
            }
            if (tmin!=-1)
            {
                cost[i][actual]=min;
                urm[i][k]=i+tmin;
            }
        }

    }

}

void Afisare()
{
    int i,j,k;
    fout<<nr[0][actual]<<'\n';
    fout<<cost[0][actual]<<'\n';
    for (i=0, k=n; k>0; k--)
    {
        for (j=i; j<urm[i][k]; j++) fout<<s[j];
        i=urm[i][k];
        if (k>1) fout<<' ';
    }
    fout<<'\n';
}

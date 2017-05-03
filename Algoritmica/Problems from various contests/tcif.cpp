#include <fstream>
#include <cstring>
#include<algorithm>
#define NMAX 1001

using namespace std;
ifstream fin("tcif.in");
ofstream fout("tcif.out");

int cifre[4],vfrecv[10],nr[NMAX],lg;
char N[NMAX];

int found(int x);
int marire(int x);

int main()
{
    int i, j, A, B, C, poz;
    fin>>A>>B>>C;
    for (i=1; i<=3; i++)
        fin>>cifre[i];
    vfrecv[cifre[1]]=A; vfrecv[cifre[2]]=B; vfrecv[cifre[3]]=C;
    sort(cifre+1,cifre+4);

    fin>>N;
    lg=strlen(N);
    for (i=0; i<lg; i++)
        nr[lg-i-1]=N[i]-'0';

    if (lg<A+B+C)
    {
        if (!cifre[1])
        {
            fout<<cifre[2];
            vfrecv[cifre[2]]--;
        }
        for (i=1; i<=3; i++)
            for (j=0; j<vfrecv[cifre[i]]; j++) fout<<cifre[i];
        fout<<'\n';
        return 0;
    }

    for (i=lg-1; i>0; i--)
    {
        poz=found(nr[i]);
        if (poz) vfrecv[cifre[poz]]--;
        else break;
    }
    poz=marire(nr[i]);
    if (poz)
    {
        nr[i]=cifre[poz];
        vfrecv[cifre[poz]]--;
    }
    else
    {
        i++;
        poz=0;
        while (!poz)
        {
            poz=marire(nr[i]);
            if (!poz)
            { vfrecv[nr[i]]++; i++;}
        }
        vfrecv[nr[i]]++;
        nr[i]=cifre[poz];
        vfrecv[cifre[poz]]--;
    }

    for (j=i-1, poz=1; poz<=3; poz++)
        while (vfrecv[cifre[poz]])
        {
            nr[j--]=cifre[poz];
            vfrecv[cifre[poz]]--;
        }

    for (i=lg-1; i>=0; i--)
        fout<<nr[i];
    fout<<'\n';
    return 0;
}

int found(int x)
{
    int i;
    for (i=1; i<=3; i++)
        if (cifre[i]==x && vfrecv[cifre[i]]) return i;
    return 0;
}

int marire(int x)
{
    int i;
    for (i=1; i<=3; i++)
        if (cifre[i]>x && vfrecv[cifre[i]]) return i;
    return 0;
}

#include <cstdio>
#include <string.h>
using namespace std;

char S[30002], c, P[130], cod[130];;
char *voc = "AEIOU";
int a, N, C, k, j, i, T, aux, L[30];
FILE *fin = fopen("litere.in","r");
FILE *fout = fopen("litere.out","w");

int main()
{
    fscanf(fin,"%d",&N);
    fscanf(fin,"%s",S+1);
    a = 0;
    k = 0;
    for (i=1; i<N; i++)
    {
        if ((strchr(voc, S[i]) && !strchr(voc, S[i+1])) ||
                (!strchr(voc, S[i]) && strchr(voc, S[i+1])))
            a++;
        if (!P[S[i]])
            P[S[i]] = ++k;
    }
    if (!P[S[N]])
        P[S[N]] = ++k;
    fprintf(fout,"%d\n",a);
    fscanf(fin,"%d",&C);

    for (i=1; i<=C; i++)
        fscanf (fin,"%d",&L[i]);
    for (i=1; i<=N; i++)
        S[i] = L[P[S[i]]];
    for (i=1; i<=N; i++)
        fprintf(fout,"%c",S[i] + '0');
    for (i=1,j=N; i<=j; i++,j--)
    {
        c = S[i];
        S[i] = S[j];
        S[j] = c;
    }
    for (i=1, T = 0; i<=N; i++)
    {
        aux = S[i] * (N-i+1) + T;
        S[i] = aux%10;
        T = aux/10;
    }
    while (T)
    {
        S[++N] = T%10;
        T/=10;
    }
    fprintf(fout,"\n");
    for (i=N; i>=1; i--)
        fprintf(fout,"%c",S[i] + '0');
    return 0;
}

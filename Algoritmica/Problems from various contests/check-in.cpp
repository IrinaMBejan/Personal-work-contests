#include<cstdio>
#define NMax 1001

FILE* fin=fopen("checkin.in","r");
FILE* fout=fopen("checkin.out","w");

int n;
long int P, K, a[NMax], b[NMax], TMin, t, nrmax[NMax], maxi[NMax];

void sortare (int, int);
int  verifica();

int main ()
{
    int i;
    fscanf (fin,"%d",&n);
    for (i=0; i<n; i++)
        fscanf (fin, "%d %d", &a[i],&b[i]);
    fscanf (fin,"%d %d", &K, &P);
    if (K>n) K=n;
    TMin=P*a[1]+b[1];
    for (i=1; i<n; i++)
        if (TMin>P*a[i]+b[i]) TMin=a[i]*P+b[i];
    long int st, dr;
    if (P)
    {
        st=0;
        dr=TMin;
        while (st<dr)
        {
            t=(st+dr)/2;
            if (!verifica()) st=t+1;
            else dr=t;
        }
        TMin=st;
    }
    fprintf(fout,"%d\n",TMin);
    return 0;
}



int verifica()
{
    long sum, i, h, j;
    for (i=0; i<n; i++)
    {
        nrmax[i]=(t-b[i])/a[i];
        if (nrmax[i]<=0) nrmax[i]=-1;
    }
    for (i=0; i<K; i++) maxi[i]=-1;
    for (i=0; i<n; i++)
        for (j=0; j<K; j++)
            if (nrmax[i]>maxi[j])
            {
                for (h=K; h>j; h--) maxi[h]=maxi[h-1];
                maxi[j]=nrmax[i];
                break;
            }

    sum=0;
    for (i=0; i<K; i++)
        if (maxi[i]>0) sum+=maxi[i];
    if (sum>=P) return 1;
    return 0;
}

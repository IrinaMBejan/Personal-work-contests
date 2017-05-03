#include <cstdio>
#define Nmax 155
using namespace std;
FILE* fin=fopen("cartoane.in","r");
FILE* fout=fopen("cartoane.out","w");

int L,H,A,B,solc;
int T[Nmax][Nmax];

void Citire()
{
    fscanf(fin,"%d %d",&L,&H);
    fscanf(fin,"%d %d",&A,&B);
    if(A>B)
    {
        int C=A;
        A=B;
        B=C;
    }
}

void DI(int a, int b)
{
    if(a>b)
    {
        int c=a;
        a=b;
        b=c;
    }

    if((a <= A && b<B) || (b<=B && a<A) )
        return ;
    if( (a == A && b == B))
        solc++;
    else
    {
        int s,smax=0;
        if(a>A)
        {
            s=solc;
            if( T[A][b])
                solc +=T[A][b];
            else
                DI(A,b);

            if(T[a-A][b])
                solc +=T[a-A][b];
            else
                DI(a-A,b);

            if(solc>smax) smax=solc;
            solc=s;
        }

        if(a>B)
        {
            s=solc;
            if(T[B][b])
                solc += T[B][b];
            else
                DI(B,b);

            if(T[a-B][b])
                solc += T[a-B][b];
            else
                DI(a - B, b);

            if(solc>smax) smax=solc;
            solc=s;
        }

        if(b>B)
        {
            s=solc;
            if(T[a][B])
                solc+=T[a][B];
            else
                DI(a,B);

            if(T[a][b-B])
                solc+=T[a][b-B];
            else
                DI(a,b-B);
            if(solc>smax) smax=solc;
            solc=s;
        }

        if(b>A)
        {
            s=solc;
            if(T[a][A])
                solc += T[a][A];
            else
                DI(a,A);

            if(T[a][b-A])
                solc += T[a][b-A];
            else
                DI(a, b-A);
            if(solc>smax) smax=solc;
            solc=s;
        }

        T[a][b] = T[b][a] = smax - solc;
        solc=smax;
    }
}

int main()
{
    Citire();
    DI(L,H);
    fprintf(fout,"%d\n",T[L][H]);

    return 0;
}

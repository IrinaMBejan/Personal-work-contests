#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
FILE* fin = fopen("compresie.in","r");
FILE* fout=fopen("compresie.out","w");

char s[1000005];
char M[1005][1005];
int Lg, N, nr, poz, co;

void Citire();
void Afisare();
void P1();
void DIV(int x1, int y1, int x2, int y2);

int main()
{
    Citire();
    P1();
    DIV(1, 1, N, N);
    Afisare();
    return 0;
}

void Citire()
{
    fscanf (fin, "%s" , s);
    Lg = strlen(s);
}

void P1()
{
    int  nel = 0 , k = 0;
    for(int i = 0; i < Lg; i++)
        if( s[i] == '*' ) nr++;
        else if( s[i]>='0' && s[i] <= '9' ) k = k*10 + s[i] - '0';
        else if ( s[i] >= 'a' && s[i] <= 'z' )
        {
            if( s[i-1] < 'a' && k )
            {
                nel+=k;
                k=0;
            }
            else
                nel++;
        }
    N = (int) sqrt((double) nel);
}

void Afisare()
{
    fprintf(fout, "%d\n", nr);

    for ( int i = 1; i <= N; i++)
    {
        for( int j = 1; j <= N; j++)
            fprintf( fout, "%c", M[i][j]);
        fprintf( fout, "\n");
    }
}

void DIV(int x1, int y1, int x2, int y2)
{
    if(x1 <= x2 && y1 <= y2 && poz < Lg)
    {
        if(x1 == x2 && y1 == y2)
            M[x1][y1] = s[poz++];
        else if ( s[poz] >= '0' && s[poz] <= '9' )
        {
            co = 0;
            while( s[poz] >= '0' && s[poz] <= '9' )
            {
                co = co*10 + s[poz] - '0';
                poz++;
            }

            for ( int i = x1; i <= x2; i++)
                for (int j = y1 ; j <= y2; j++)
                    M[i][j] = s[poz];
            poz++;
        }
        else //*
        {
            int mijx = (x1 + x2) >>1;
            int mijy = (y1+ y2) >>1;
            poz ++;

            DIV( x1, y1, mijx, mijy);
            DIV( x1,  mijy+1, mijx, y2 );
            DIV( mijx+1, y1, x2, mijy );
            DIV( mijx+1, mijy+1, x2, y2);
        }
    }
}


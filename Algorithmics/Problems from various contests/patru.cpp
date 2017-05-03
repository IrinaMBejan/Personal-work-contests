#include <cstdio>
#include <cmath>

#define D 0

int secv[20000];

int main()
{
    FILE *in, *out;
    int n, k, t, i, perfect, maxterm, term, term2, term2_4, putere4;
    int term2_1, suma4, suma;

    in = fopen( "patru.in", "r" );
    fscanf( in, "%d%d", &n, &k );
    putere4 = 0;
    suma4 = 0;
    suma = 0;
    for ( i = 0; i < n; i++ )
    {
        fscanf( in, "%d", &t );
        maxterm = sqrt( sqrt( t / 2 ) );
        term = 0;
        perfect = 0;
        do
        {
            term++;
            term2_4 = t - term * term * term * term;
            term2 = sqrt(term2_4);
            if ( term2_4 == (term2 * term2) )
            {
                term2_1 = sqrt( term2 );
                if ( (term2_1 > 0) && (term2 == (term2_1 * term2_1)) )
                    perfect = 1;
            }
        }
        while ( (!perfect) && (term < maxterm) );
        if ( perfect )
        {
            putere4++;
            if ( D )
                printf( "putere4: %d = %d^4 + %d\n", t, term, term2_1 );
        }
        t %= 10;
        secv[i] = t * t * t * t;
        suma += secv[i];
        if ( (i + 1) >= k )
        {
            if ( (i + 1) > k )
                suma -= secv[i - k];
            if ( (suma % 10) == 4 )
            {
                suma4++;
                if ( D )
                    printf( "suma 4 pe pozitia %d\n", i - k + 1 );
            }
        }
    }
    out = fopen( "patru.out", "w" );
    fprintf( out, "%d\n%d\n", putere4, suma4 );
    return 0;
}

#include <cstdio>

using namespace std;
FILE *fin, *fout;
int main()
{
  int s, n, b, bc;
  fin = fopen( "taxe.in", "r" );
  fscanf( fin, "%d", &s );
  n = s / 4;
  b = (3 * n + 1) / 4 - 1;
  do
    {
        bc = ++b;
        s = 0;
        while ( bc > 0 )
        {
            s = s + bc;
            bc /= 4;
        }
    } while ( s < n );

  fout = fopen( "taxe.out", "w" );
  fprintf( fout, "%d\n", b );
  return 0;
}

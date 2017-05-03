#include <cstdio>
using namespace std;
int m[52][52];
int liep[100], ciep[100];
int dir[100];
int cosuri[100];
int dlin[4] = { -1, 0, 1, 0 };
int dcol[4] = { 0, 1, 0, -1 };

int main()
{
  FILE *fin, *fout;
  int L, P, N;
  int n, i, l, c, d, v, max, oua;

  fin = fopen( "oua.in", "r" );
  fscanf( fin, "%d%d", &L, &P );
  for ( i = 0; i < P; i++ ) {
    fscanf( fin, "%d%d%d", &l, &c, &v );
    m[l][c] = v;
  }
  fscanf( fin, "%d", &N );
  for ( i = 0; i < N; i++ ) {
    fscanf( fin, "%d%d", &liep[i], &ciep[i] );
    if ( liep[i] == 1 )
      dir[i] = 2;
    else if ( liep[i] == L )
      dir[i] = 0;
    else if ( ciep[i] == 1 )
      dir[i] = 1;
    else
      dir[i] = 3;
  }
  fclose( fin );

  for ( i = 1; i <= L; i++ )
    m[0][i] = m[i][0] = m[i][L+1] = m[L+1][i] = -1;

  n = N;
  d = 0;
  oua = 0;
  while ( n > 0 )
    {
    for ( i = 0; i < N; i++ )
      if ( dir[i] != -1 )
      {
        if ( m[liep[i]][ciep[i]] > 0 )
        {
          cosuri[i] += m[liep[i]][ciep[i]];
          oua++;
          m[liep[i]][ciep[i]] = 0;
          dir[i] = (dir[i] + 1) % 4;
        }
      }
    for ( i = 0; i < N; i++ )
      if ( dir[i] != -1 )
      {
        liep[i] += dlin[dir[i]];
        ciep[i] += dcol[dir[i]];
        if ( m[liep[i]][ciep[i]] == -1 )
        {
          dir[i] = -1;
          n--;
        }
      }
    d++;
  }

  max = cosuri[0];
  for ( i = 1; i < N; i++ )
    if ( cosuri[i] > max )
      max = cosuri[i];

  fout = fopen( "oua.out", "w" );
  fprintf( fout, "%d %d %d\n", oua, max, d );
  fclose( fout );

  return 0;
}

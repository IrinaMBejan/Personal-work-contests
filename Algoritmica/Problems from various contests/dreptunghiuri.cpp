#include<cstdio>
#define Nmax  1005

using namespace std ;

struct pozitie
{
	int lin, col ;
}C[Nmax * Nmax];

int dl[] = {-1, 0, 1,  0} ;
int dc[] = { 0, 1, 0, -1} ;
int a[Nmax][Nmax], n, m, nrd, Hmax, nrMax, t, v, fi ;

FILE* fout=fopen("dreptunghiuri.out", "w") ;
FILE* fin=fopen("dreptunghiuri.in", "r") ;

void Fill_1(int x, int y)
{
	int x1, y1, i ;
	fi = 0 ;
	C[fi].lin = x ;
	C[fi].col = y ;
	a[x][y] = v ;
	while (fi >= 0)
	{
		x = C[fi].lin ;
		y = C[fi].col ;
		fi-- ;
		for (i=0 ; i<4 ; i++)
		{
			x1 = x + dl[i] ;
			y1 = y + dc[i] ;
			if (( x1>=0 && x1<=n+1 && y1>=0 && y1<=m+1 ))
			if (a[x1][y1] == 0)
			{
				a[x1][y1] = v ;
				fi++ ;
				C[fi].lin = x1 ;
				C[fi].col = y1 ;
			}
		}
	}
}

void Fill(int x, int y)
{
	int x1, y1, i ;
	fi = 0 ;
	C[fi].lin = x ;
	C[fi].col = y ;
	a[x][y] = v ;
	while (fi >= 0)
	{
		x = C[fi].lin ;
		y = C[fi].col ;
		fi-- ;
		for (i=0 ; i<4 ; i++)
		{
			x1 = x + dl[i] ;
			y1 = y + dc[i] ;
			if (a[x1][y1] == t)
			{
				a[x1][y1] = v ;
				fi++ ;
				C[fi].lin = x1 ;
				C[fi].col = y1 ;
			}
		}
	}
}

int main()
{
	int i, j, x ;
	fscanf(fin,"%d %d", &n, &m) ;
	for (i=1 ; i<=n ; i++)
		for (j=1 ; j<=m ; j++)
		{
			fscanf(fin,"%d", &x) ;
			a[i][j] = -x ;
		}
	v = 1 ;
	Fill_1(0,0) ;

	nrd = Hmax = nrMax = 0 ;
	for (i=1 ; i<=n ; i++)
		for (j=1 ; j<=m ; j++)
			if (a[i][j] <= 0)
			{
				v = a[i-1][j-1]+1 ;
				if (v % 2 == 0)
				{
					nrd++ ;
					if (Hmax < v)
					{
						Hmax = v ;
						nrMax = 1 ;
					}
					else if (Hmax == v) nrMax++ ;
				}
				t = a[i][j] ;
				Fill(i, j) ;
			}


	fprintf(fout,"%d %d %d\n", nrd, Hmax/2, nrMax) ;
	return 0 ;
}

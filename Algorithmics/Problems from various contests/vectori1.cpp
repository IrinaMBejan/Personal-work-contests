#include<cstdio>
#define Nmax 1010
#define INF (1<<30)

using namespace std;
FILE* fin=fopen("vectori1.in","r");
FILE* fout=fopen("vectori1.out","w");
int A[Nmax][Nmax];
int S[Nmax];
int mj,st,dr,i,j,N,M,P,val,poz,K,gasit,sol,gasit_sol;

int bsearch( int X, int i )
{
	int ret = 0 ;
	int m,s = 1 , d = A[i][0], Y ;

	for( m = (s+d)>>1 ; s <= d ; m = (s+d)>>1 ) {
		Y = A[i][m] ;

		if( X == Y ) {
			gasit = 1 ;
			return m ;
		}
		if( X > Y ) { ret = m ; s = m + 1 ; }
		else d = m - 1 ;
	}

	return ret ;
}


int main ()
{


	fscanf(fin,"%d %d",&N,&M);

	for( i = 1 ; i <= N ; i++ ) {
		fscanf(fin,"%d",&A[i][0]);

		for( j = 1 ; j <= A[i][0] ; j++ )
			fscanf(fin,"%d",&A[i][j]);
	}

	for( i = 1 ; i <= M ; i++ ) {
		fscanf(fin,"%d %d",&K,&P) ;

		for( j = 1 ; j <= P ; j++ )
			fscanf(fin,"%d",&S[j]);

		st = -INF ; dr = INF ;

		for( mj = (st+dr)>>1 ; st <= dr ; mj = (st+dr)>>1 ) {
			poz = 0 ; gasit = 0 ; gasit_sol = 0 ;
			for( j = 1 ; j <= P ; j++ ) {
				val = bsearch(mj,S[j]) ;
				poz += val ;
				if( gasit ) {
					gasit = 0 ;
					gasit_sol = 1 ;
					sol = A[S[j]][val];
				}
			}

			if( poz < K ) st = mj + 1 ;
			else if( poz > K ) dr = mj - 1 ;
			else {
				if( gasit_sol != 1 )
					dr = mj - 1;
				else
					break ;
			}
		}

		fprintf(fout,"%d\n",sol);
	}

	return 0 ;
}

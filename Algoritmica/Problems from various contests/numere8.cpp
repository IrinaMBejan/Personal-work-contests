#include <cstdio>
#include <cstring>
#define Nmax 9005
#define Modulo 9973

using namespace std;
int N, K, ndiv;
int nrpos1[Nmax], nrpos2[Nmax], diviz[Nmax];


FILE *f = fopen("numere8.in", "r");
FILE *g = fopen("numere8.out", "w");

int prim(int nr)
{
	if(nr %2 == 0) return 0;
	int i;
	for(i = 3; i*i <= nr; i += 2)
		if(nr%i == 0) return 0;
	return 1;
}

int main()
{


	fscanf(f, "%d %d", &N, &K);
	int ok = 1, i, j, p;

	for(i = 11; i <= K && ok; ++i)
		if(K % i == 0 && prim(i)) ok = 0;

	for(i = 1; i <= K; ++i)
		if(K%i == 0)
            diviz[++ndiv] = i;


	if(ok)
	{
		for(i = 1; i <= ndiv && diviz[i] <= 9 ; ++i)
			nrpos1[diviz[i]] = 1;
		for(i = 2; i <= N; ++i)
		{
			for(j = 1; j <= ndiv; ++j)
				nrpos2[diviz[j]] = 0;
			for(j = 1; j <= ndiv; ++j)
			{
				for(p = 1; p <= ndiv && diviz[p] <= 9; ++p)
					if(diviz[j] % diviz[p] == 0)
						nrpos2[diviz[j]] = (nrpos2[diviz[j]] + nrpos1[diviz[j]/diviz[p]]) % Modulo;
			}
			for(j = 1;j <= ndiv; ++j)
				nrpos1[diviz[j]] = nrpos2[diviz[j]] % Modulo;

		}
		fprintf(g, "%d\n", nrpos1[K]);
	}
	else fprintf(g, "0\n");



	return 0;
}


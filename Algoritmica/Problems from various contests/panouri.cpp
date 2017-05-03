#include<fstream>
#define LG1 15001
#define LG2 1001
using namespace std;

ifstream fin("panouri.in");
ofstream fout("panouri.out");
unsigned int panouri[LG1];
unsigned int b[LG2], frecv[LG1];

unsigned  int n, m, s, f, i, nr, best, x;
unsigned  int minm, maxm;

void ReadData();
void Solve();

int main()
{
	ReadData();
	Solve();
	return 0;
}

void  ReadData()
{
	fin >> n >> m;
    for (i = 1; i <= n; i++ )
		 fin >> panouri[i];
    for (i = 1; i <= m; i++ )
    {
		fin >> x;
        b[x] = 1;
	}
    fin.close();
}

void Solve()
{
	s = 1; f = 1;
    nr = 0;
    if ( b[panouri[s]] == 1 )
   		frecv[panouri[s]] = 1, nr = 1;

  	while (f < n && nr < m)           // cautam cel mai mic al 2-lea indice f astfel ca in panouri[s..f]
  	{                                 // sa fie continute toate numerele din b[]
  		f++;
		if (b[panouri[f]] == 1)             // face parte din b[]
        {
			if ( frecv[panouri[f]] == 0 )      //  o singura aparitie in secventa
				nr++;
			frecv[panouri[f]]++;
		}
    }

    if ( nr < m )                      // nu exista solutie
    {
    	fout << -1 << '\n';
    	fout.close();
    	return;
	}

    while (b[panouri[s]] == 0 || (b[panouri[s]] == 1 && frecv[panouri[s]] > 1))
    	--frecv[panouri[s++]];                  // marim s cat se poate astfel ca in secventa panouri[s..f]
    	                               // sa apara toate numerele din b
	best = LG1;
	if (best > f - s)
		best = f - s, minm = s, maxm = f;

	for (f = f + 1; f <= n; f++ )
    {
		if (b[panouri[f]] == 1)
            frecv[panouri[f]]++;

        while (b[panouri[s]] == 0 || (b[panouri[s]] == 1) && (frecv[panouri[s]] > 1))
            --frecv[panouri[s++]];              // la fiecare incrementare a indicelui f incercam
                                       // sa marim pe cat posibil si indicele s

        if (best > f - s)
            best = f - s, minm = s, maxm = f;
	}

    fout <<  best << '\n';
    fout.close();
}


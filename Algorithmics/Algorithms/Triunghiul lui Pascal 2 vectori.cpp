#include <iostream>
#include <iomanip>

using namespace std;
int T[2][100];

int main()
{
    int i,j,n, lc, lp;
    n=10;
    T[0][0]=T[0][1]=T[1][0]=1;
    //initial pe linia 0 se afla linia precedenta si pe linia 1 voi calcula linia curenta
    lp=0; lc=1;
    for (i = 2; i <=n; i++)
    	{//calculez combinarile de ordin i

    	 T[lc][i]=1;
    	 for (j=1; j<i; j++)
    	     T[lc][j]=T[lp][j]+T[lp][j-1];
         lp=1-lp; lc=1-lc;
    	}
    for (i=0; i<=n; i++)
        cout<<setw(4)<<T[lp][i];
	cout<<'\n';

    return 0;
}

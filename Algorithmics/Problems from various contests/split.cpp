#include<fstream>
#define NMAX 10005

using namespace std;

ifstream fin("split.in");
ofstream fout("split.out");
int a[NMAX], mins[NMAX], mind[NMAX], maxd[NMAX], maxs[NMAX], n;

int main()
{
    int i, j, k, x, di, dk, max, min, xi, xj, xk;
    int solst, soldr, solmax;

    // citire
    fin >> n;
    for (i = 1; i <= n; i++)
        fin >> a[i];

    //min max stg
    mins[1] = maxs[1] = a[1];
    for (i = 2; i <= n; i++)
    {
        if (a[i] > maxs[i-1]) maxs[i] = a[i];
        else maxs[i] = maxs[i-1];

        if (a[i] < mins[i-1]) mins[i] = a[i];
        else mins[i] = mins[i-1];
    }

    //min max drp
    mind[n] = maxd[n] = a[n];
    for (i = n - 1; i >= 1; i--)
    {
        if (a[i] > maxd[i+1]) maxd[i] = a[i];
        else maxd[i] = maxd[i+1];

        if (a[i] < mind[i+1]) mind[i] = a[i];
        else mind[i] = mind[i+1];
    }

    // calcul
    solmax = 0;
    di = dk = 0;
    xi = 2;
    xj = 4;
    xk = 6; //incep. secv initiale (1,i - i+1,j (st) || (dr) j+1,k - k+1,n)
    for (j = 4; j <= n - 3; j++) //mutam j-ul repetat
    {
        // maxul din stanga: i=2..j-2
        if (a[j] > a[j - 1])
        {
            max = a[j];
            min = a[j - 1];
        }
        else
        {
            max = a[j - 1];
            min = a[j];
        }
        solst = max - min + maxs[j-2] - mins[j-2];
        di = j - 2;
        for (i = j - 2; i > 2; i--)
        {
            if (a[i] > max) max = a[i];
            if (a[i] < min) min = a[i];
            x = max - min + maxs[i-1] - mins[i-1];
            if (solst <= x)
            {
                solst = x;
                di = i-1;
            }
        }

        //maxul din dreapta k=j+2..n-2
        if (a[j+1] > a[j+2])
        {
            max = a[j+1];
            min = a[j+2];
        }
        else
        {
            max = a[j+2];
            min = a[j+1];
        }
        soldr = max - min + maxd[j+3] - mind[j+3];
        dk = j + 2;
        for (k = j + 3; k <= n - 2; k++)
        {
            if (a[k] > max) max = a[k];
            if (a[k] < min) min = a[k];
            x = max - min + maxd[k+1] - mind[k+1];
            if (soldr < x)
            {
                soldr = x;
                dk = k;
            }
        }

        //calcul final pentru pozitia actuala a lui j si schimbare max, daca e cazul
        x = solst + soldr;
        if (x > solmax)
        {
            solmax = x;
            xi = di;
            xj = j;
            xk = dk;
        }
    }

    fout << solmax << "\n";
    fout << xi << " " << xj << " " << xk << "\n";

    return 0;
}

#include <fstream>
#define MAX 1000000

using namespace std;

ifstream fin("munte3.in");
ofstream fout("munte3.out");
int n, i, j, tura, varfuri, contor;
int x[110];
bool gasit;

int main()
{
    fin >> n;
    for (i = 1; i <= n; ++i)
        fin >> x[i];
    tura = 1;
    gasit = 1;
    while (gasit)
    {
        gasit = 0;
        contor = 0;
        i = 1;
        while (i<n && x[i]>x[i+1]) i++;
        while (i <= n)
        {
            while (i<n && x[i]<x[i+1]) i++;
            if (i<n)
            {
                varfuri++;
                contor++;
                x[i] = MAX;
                gasit = 1;
            }
            while (i<n && x[i]>x[i+1]) i++;
            if (i<n && x[i]>x[i-1])
                i--;
            else if (i == n)
                break;
        }
        if (tura == 1)
        {
            fout << varfuri << '\n';
            tura++;
        }
        i = 1;
        while (i < n)
        {
            while (x[i] != MAX && i<n) i++;
            for (j = i; j<n; ++j) x[j] = x[j+1];
        }
        if (gasit) n -= contor;
    }
    fout << varfuri << '\n';
    fout << n << '\n';
    return 0;
}

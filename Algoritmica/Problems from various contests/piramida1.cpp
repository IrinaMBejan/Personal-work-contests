#include <fstream>
#define NMAX (512*1024)
#define LN 20
#define MOD 10000
using namespace std;

ifstream fin("piramida1.in");
ofstream fout("piramida1.out");

int vec[NMAX], C[LN][LN];
int S;

int main()
{
    int i, j, db, cn;
    int v;
    //pascal
    for (i = 0; i < LN; i++)
        C[i][0] = 1;
    for (i = 1; i < LN; i++)
        for (j = 1; j <= i; j++)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;

    fin>>S;
    cn = S;
    db = 0;//nivelele
    while (cn/= 2) db++;
    S -= (1 << db);

    //rucsac
    vec[0] = 1;
    for (i = 0;  i <= db; i++)
    {
        v = C[db][i] % MOD;
        for (j = v; j <= S; j++)
            vec[j] = (vec[j] + vec[j-v]) % MOD;
    }

    fout<<vec[S]<<'\n';

    return 0;
}


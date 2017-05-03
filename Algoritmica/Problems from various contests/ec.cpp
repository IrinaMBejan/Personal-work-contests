#include <cstdio>
#include <cstring>
#include <cmath>

#define LMAX 100
#define NMAX 20000

using namespace std;
FILE* fin=fopen("ec.in", "r");
FILE* fout=fopen("ec.out", "w");

int N, M, L, nr_ec1, nr_ec2, sol_ec1, sol_ec2;
int v[NMAX];
char ecuatie[LMAX];

inline bool is_int(long double x)
{
    return abs((int)x - x) < 0.000000000001L;
}

int main()
{
    int x;
    fscanf(fin,"%d %d\n", &N, &M);

    L = N*N;
    for (int i = 0; i < L; ++i)
    {
        fscanf(fin,"%d ",&x);
        v[x+10000] = 1;
    }


    int coef[4], nr_coef;
    for (int i = 0; i < M; i++)
    {
        fscanf(fin,"%s\n", ecuatie);
        nr_coef = 0;
        int val = 0,lg = strlen(ecuatie);
        for (int j = 0; j < lg; j++)
        {
            if (ecuatie[j] <= '9' && ecuatie[j] >= '0')
                val = val * 10 + ecuatie[j] - '0';
            if (ecuatie[j] == 'x')
            {
                coef[nr_coef++] = val;
                val = 0;
                if (ecuatie[j + 1] == '^') j+=3;
                else ++j;
            }
            if (ecuatie[j] == '=')
            {
                coef[nr_coef++] = val;
                val = 0;
            }
        }
        coef[nr_coef++] = val;

        long double sol;

        if (nr_coef == 3)
        {
            //rez ecuatia de gradul 1
            ++nr_ec1;
            if (coef[0] == 0) continue;
            sol = ((long double)(coef[2] - coef[1])) / coef[0];
            if (is_int(sol) && v[(int)sol+10000])
                ++sol_ec1;
        }
        else
        {
            //rez ecuatia de gradul 2 (delta=b^2-4ac;
            ++nr_ec2;
            bool ok = true;
            int delta = coef[1] * coef[1] - 4 * coef[0]*(coef[2] - coef[3]);
            if (coef[0] == 0)
            {
                if (coef[1] == 0)
                    continue;
                sol = ((long double)(coef[3] - coef[2])) / coef[1];
                if (is_int(sol) && v[(int)sol+10000])
                    ++sol_ec2;
                continue;
            }

            if (delta < 0) continue;

            sol = (long double)(-coef[1] + sqrtl(delta)) / (2*coef[0]);
            if (!(is_int(sol) && v[(int)sol+10000]))
                ok = false;

            sol = (long double)(-coef[1] - sqrtl(delta)) / (2*coef[0]);
            if (is_int(sol) && v[(int)sol+10000] && ok)
                ++sol_ec2;
        }
    }
    fprintf(fout,"%d %d\n%d %d\n", nr_ec1, sol_ec1, nr_ec2, sol_ec2);
    return 0;
}

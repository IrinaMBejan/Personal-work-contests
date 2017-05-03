#include <cstdio>
#include <algorithm>
using namespace std;
FILE* fin=fopen("descompunere.in", "r");
FILE* fout=fopen("descompunere.out", "w");

int Div (int N, int x, int y, int type)
{

    if (N == 1)
        return 0;

    int xnou;
    if (type == 1)
    {
        if (x <= N / 2)
            return Div (N / 2, x, y, 1);
        else
        {
            xnou = x - N / 2;
            if (y <= 2 * xnou - 1)
                return 1 + Div (N / 2, xnou, y,1);
            else
            {
                if (y >= N + 1)
                    return 3 + Div(N / 2, xnou, y - N, 1);
                else
                    return 2 + Div (N / 2, xnou, y - (2 * xnou - 1), 2);
            }
        }
    }
    else
    {
        if (x > N / 2)
            return Div (N / 2, x - N / 2, y, 2);
        else
        {
            if (y <= 2 * (N / 2 - x + 1) - 1)
                return 1 + Div(N / 2, x, y, 2);
            else
            {
                if (y > N)
                    return 3 + Div (N / 2, x, y - N, 2);
                else
                    return 2 + Div (N / 2, x, y - (2 * (N / 2 - x + 1) - 1), 1);
            }
        }
    }

    return 0;
}

int main ()
{
    int N, M;
    int x, y;
    fscanf(fin, "%d %d", &N, &M);
    while(M)
    {
        fscanf (fin,"%d %d", &x, &y);
        fprintf (fout,"%d\n", Div (1 << N, x, y, 1));
        M--;
    }


    return 0;
}


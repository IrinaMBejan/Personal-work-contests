#include <cstdio>

using namespace std;
FILE* fin=fopen("furnici1.in","r");
FILE* fout=fopen("furnici1.out","w");

inline int max(int x, int y)
{
    return x > y ? x : y;
}

int L, N, rez, x;
char dir;

int main()
{
    fscanf(fin,"%d %d\n", &L, &N);
    for (int i = 0; i < N; ++i)
    {
        fscanf(fin,"%d %c\n", &x, &dir);
        if (dir == 'S') rez = max(rez, x);
        else rez = max(rez, L - x);
    }

    fprintf(fout,"%d\n", rez);
    return 0;
}


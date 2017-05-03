#include <cstdio>
#include <cstdlib>

const int Nm = 10;

int first_sol, N;
int num_sol;
int startx[2 * Nm], starty[2 * Nm];
int dx[2 * Nm], dy[2 * Nm];
int mat[Nm][Nm];
int trace[Nm][Nm];
int viz[1 << Nm];

void afisprim()
{
    FILE *f = fopen("magic2.out", "wt");
    for (int k = 0; k < 2 * N; ++k)
    {
        int sx, sy;
        for (sx = startx[k], sy = starty[k]; sx < N && sy < N;
                sx += dx[k], sy += dy[k])
        {
            fprintf(f, "%c", mat[sx][sy] ? '9':'1');
        }
    }
    fprintf(f, "\n");
    fclose(f);
}

void afiso()
{
    FILE *f = fopen("magic2.out", "wt");
    fprintf(f, "%d\n", num_sol);
    fclose(f);
}

void back(int lev, int last)
{
    if (lev == 2 * N)
    {
        ++num_sol;
        if (first_sol)
        {
            afisprim();
            exit(0);
        }
        return;
    }

    int sx, sy;
    int num_free = 0;
    for (sx = startx[lev], sy = starty[lev]; sx < N && sy < N;
            sx += dx[lev], sy += dy[lev])
    {
        if (trace[sx][sy] == -1) ++num_free;
    }

    for (int cfg = 0; cfg < (1 << num_free); ++cfg)
    {
        int tmp = 0, current = 0, ind = 0;
        for (sx = startx[lev] + (N - 1) * dx[lev], sy = starty[lev] + (N - 1) * dy[lev];
                sx >= 0 && sy >= 0;
                sx -= dx[lev], sy -= dy[lev], ++ind)
        {
            if (trace[sx][sy] == -1)
            {
                mat[sx][sy] = (cfg & (1 << tmp)) != 0;
                trace[sx][sy] = lev;
                current += (1 << ind) * mat[sx][sy];
                ++tmp;
            }
            else
            {
                current += (1 << ind) * mat[sx][sy];
            }
        }
        if (current > last && viz[current] == 0)
        {
            viz[current] = 1;
            back(lev + 1, current);
            viz[current] = 0;
        }
        for (sx = startx[lev], sy = starty[lev]; sx < N && sy < N;
                sx += dx[lev], sy += dy[lev])
        {
            if (trace[sx][sy] == lev)
            {
                trace[sx][sy] = -1;
            }
        }
    }
}

void cit()
{
    int i, x, j;
    FILE *f = fopen("magic2.in", "rt");
    if (fscanf(f, "%d\n%d\n", &first_sol, &N)) ;
    if (first_sol == 2) first_sol = 1;
    else first_sol = 0;
    for (i = 0; i < N; ++i)
    {
        if (fscanf(f, "%d", &x)) ;
        --x;
        startx[x] = i;
        starty[x] = 0;
        dx[x] = 0;
        dy[x] = 1;
    }
    for (i = 0; i < N; ++i)
    {
        if (fscanf(f, "%d", &x)) ;
        --x;
        startx[x] = 0;
        starty[x] = i;
        dx[x] = 1;
        dy[x] = 0;
    }
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            trace[i][j] = -1;
        }
    }
    fclose(f);
}

int main()
{
    cit();
    back(0, -1);
    afiso();
    return 0;
}


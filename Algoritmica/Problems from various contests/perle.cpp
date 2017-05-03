#include <cstdio>
#define NMAX 10010
using namespace std;
int st[2][NMAX];
FILE* fin=fopen("perle.in","r");
FILE* fout=fopen("perle.out","w");
int niv[2];
int valid[2];

int main()
{
    int t,l,v,i;
    fscanf(fin,"%d",&t);
    while (t--)
    {
        fscanf(fin,"%d",&l);
        if (l == 1)
        {
            fscanf(fin,"%d",&v);
            fprintf(fout,"1\n");
            continue;
        }
        else
        {
            valid[1] = valid[0] = 1;
            niv[1] = niv[0] = 1;
            st[0][0] = 5;
            st[1][0] = 6;
            while (l--)
            {
                fscanf(fin,"%d",&v);
                for (i = 0; i < 2; i++)
                {
                    if (valid[i])
                    {
                        if (st[i][niv[i]-1] < 4)
                        {
                            valid[i] = (st[i][--niv[i]]==v);
                            continue;
                        }

                        if (st[i][niv[i]-1] == 4)
                        {
                            niv[i]--;
                            continue;
                        }

                        if (st[i][niv[i]-1]==5)
                        {
                            if (v == 3) valid[i] = 0;
                            if (v == 1)
                            {
                                niv[i]--;
                                st[i][niv[i]++] = 6;
                                st[i][niv[i]++] = 4;
                                st[i][niv[i]++] = 3;
                                st[i][niv[i]++] = 4;
                            }
                            continue;
                        }

                        if (v == 2) niv[i]--;
                        if (v == 1)
                        {
                            niv[i]--;
                            st[i][niv[i]++] = 4;
                            st[i][niv[i]++] = 2;
                        }
                        if (v == 3)
                        {
                            niv[i]--;
                            st[i][niv[i]++] = 6;
                            st[i][niv[i]++] = 5;
                        }
                    }
                    if (!niv[i] && l) valid[i] = 0;
                }
            }
            fprintf(fout,"%d\n",((!niv[0] && valid[0]) || (!niv[1] && valid[1])));
        }
    }
    return 0;
}

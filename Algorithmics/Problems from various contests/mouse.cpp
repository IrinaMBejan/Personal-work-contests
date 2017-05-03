#include <cstdio>
#define DMAX 101
using namespace std;
FILE* fin=fopen("mouse.in","r");
FILE* fout=fopen("mouse.out","w");

int a[DMAX][DMAX], poz[DMAX][DMAX];
int main(void) {

    int m, n, i, j, k, hra=0, cam=0, maximus, nord, sud, est, vest;
    fscanf(fin,"%d %d", &m, &n);
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            fscanf(fin,"%d", &a[i][j]);
    i = 1;
    j = 1;
    k = 1;
    while(!(i==m && j==n))
    {
        hra+=a[i][j];
        a[i][j]=0;
        poz[i][j]=k++;

        nord = i > 1 ? a[i - 1][j] : 0;
        sud = i < m ? a[i + 1][j] : 0;
        est = j > 1 ? a[i][j - 1] : 0;
        vest = j < n ? a[i][j + 1] : 0;

        maximus = nord;
        if(sud > maximus)
            maximus = sud;
        if(est > maximus)
            maximus = est;
        if(vest > maximus)
            maximus = vest;

        if(maximus == nord)
            i--;
        else if(maximus == sud)
            i++;
        else if(maximus == est)
            j--;
        else if(maximus == vest)
            j++;

        cam++;
    }
    hra+=a[i][j];
    a[i][j]=0;
    poz[i][j]=k;
    cam++;
    fprintf(fout,"%d %d\n", cam, hra);
    for(i=1; i<=cam; i++)
        for(j=1; j<=m; j++)
            for(k=1; k<=n; k++)
                if(poz[j][k] == i)
                    fprintf(fout,"%d %d\n", j, k);

    return 0;
}


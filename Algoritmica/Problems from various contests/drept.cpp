#include <fstream>
#include<cmath>
#define MAX 1001
using namespace std;
ifstream fin("drept.in");
ofstream fout("drept.out");

int mac[MAX][MAX];

int main()
{
    int n, aux, lat, lun, i, nmax=0, j;
    float x1,x2,y1,y2;
    fin>>n;
    for (i=1; i<=n; i++)
        {
            fin>>x1>>y1>>x2>>y2;
            lat=fabs(x1-x2);
            lun=fabs(y1-y2);
            if(lat>lun)
                mac[lun][lat]++;
            else mac[lat][lun]++;
        }
    for (i=0; i<MAX; i++)
        for(j=i+1;j<=MAX;j++)
            if(mac[i][j]>nmax) nmax=mac[i][j];
    fout<<nmax<<'\n';
    return 0;
}

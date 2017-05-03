#include<fstream>

using namespace std;
ifstream fin("joc15.in");
ofstream fout("joc15.out");

int n, k;
int a[2][5001],b[2][5001];

int main()
{
    int i,j;
    fin >> n >> k;
    for(i=0; i<n; i++)
        fin >> a[0][i];
    for(i=0; i<n; i++)
        fin >> a[1][i];

    b[0][0]=a[0][0];
    int s,max;
    for(i=1; i<n; i++)
        for(j=0; j<2; j++)
        {
            max=-100000;
            s=a[j][i];
            for(int q=1; q<k&&q<=i; q++)
            {
                s+=a[j][i-q];
                if(s+b[1-j][i-q]>max) max=s+b[1-j][i- q];
            }
            b[j][i]=max;
        }
    if(b[0][n-1]+a[1][n-1]>b[1][n-1]) b[1][n-1]=b[0][n-1]+a[1][n-1];
    fout<<b[1][n-1]<<'\n';
    return 0;
}

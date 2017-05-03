#include <fstream>
#define L 250
using namespace std;

ifstream fin("imagine.in");
ofstream fout("imagine.out");
char img[L][L];

bool Identic(int x1,int y1, int x2, int y2, char val)
{
    int i,j;
    for(i=x1; i<=x2; i++)
        for(j=y1; j<=y2; j++)
            if(img[i][j]!=val)
                return 0;
    return 1;
}

unsigned long long int Lg(int x1, int y1, int x2, int y2)
{
    int mijx, mijy;
    if(Identic(x1,y1,x2,y2,img[x1][y1]))
        return 2;
    else
    {
        mijx=(x1+x2)/2;
        mijy=(y1+y2)/2;
        return 1+Lg(x1,mijy+1,mijx,y2)+Lg(mijx+1,mijy+1,x2,y2)+Lg(x1,y1,mijx,mijy)+Lg(mijx+1,y1,x2,mijy);
    }
}

int main()
{
    int n,i,j;
    fin>>n;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            fin>>img[i][j];
    fout<<Lg(0,0,n-1,n-1)<<'\n';
    return 0;
}

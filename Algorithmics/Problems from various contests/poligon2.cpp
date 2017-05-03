#include<fstream>
using namespace std;
ifstream fin("poligon2.in");
ofstream fout("poligon2.out");
bool a[101][101],dir[9],x1[9],x2[9],x3[9];
int x[51],e[51];
long long int time=9999999999, timeinit;


int main()
{
    timeinit=time;

    nr=0;
    k=4;
    fin>>m>>n>>l;
     for (k=1;k<=l;k++)
     {
         fin>>i>>j>>v;
         a[i][j]=v;
         e[k]=(i-1)*m+j;
     }
    comb(1);
    fout<<nr<<'\n';
    return 0;
}


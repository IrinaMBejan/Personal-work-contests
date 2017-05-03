#include <fstream>

using namespace std;
ifstream fin("furnica.in");
ofstream fout("furnica.out");

int a[101][101];
int lin[10]={0,-1,-1,0,1, 1, 1, 0,-1};
int col[10]={0, 0, 1,1,1, 0,-1,-1,-1};
                //0, 1, 2,3,4,5,6,7,8

int main()
{
    int i,x=1,y=1,n,k,p,s=2,nr=0;
    fin>>n>>k;
    a[1][1]=1;
    int max=1;
    for(i=1;i<=k;i++)
    {
            fin>>p;
            x+=lin[p];
            y+=col[p];
            if(x>n||y>n)
                break;
            if(a[x][y]==0) s+=((x+y)%6);
            a[x][y]++;
            if(a[x][y]>max) {max=a[x][y]; nr=0;}
            else if(a[x][y]==max) nr++;
    }
    fout<<s<<" "<<nr+1<<'\n';
    return 0;
}

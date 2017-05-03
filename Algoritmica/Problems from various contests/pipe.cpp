#include <fstream>
#include <cstring>
#include<cmath>

using namespace std;
ifstream fin("pipe.in");
ofstream fout("pipe.out");

int A[100], R[100], p[29000], a, r;

int rezolva ( int V[] , int v , int d )
{
    int i,j;
    memset ( p , 0 , sizeof ( p ) );
    int max =0;
    p[0]=1;
    for ( i=0 ; i<v ; i++ )
        for ( j=max ; j+1 ; j-- )
            if (p[j])
            {
                p[j+V[i]]=1;
                if (j+V[i]>max) max=j+V[i];
            }
    for (i=0 ; i<=max-d && !(p[i]&&p[i+d]) ; i++ );
    return (i<=max-d)?(i*2+d):(-1);
}


int main ()
{
    int n,x1,x2,y1,y2,i;
    char c;
    fin>>n;
    fin>>x1>>y1;
    fin>>x2>>y2;

    for (i=0 ; i<n ; i++ )
    {
        fin>>c;
        if (c=='A') fin>>A[a++] ;
        else fin>>R[r++];
    }
    int solutieA,solutieB;
    solutieA = rezolva ( A , a , fabs ((double)x1-x2) );
    solutieB = rezolva ( R , r , fabs ((double)y1-y2) );

    if (solutieA>=0 && solutieB>=0) fout<<solutieA+solutieB<<'\n';
    else fout<<"imposibil"<<'\n';
    return 0;
}

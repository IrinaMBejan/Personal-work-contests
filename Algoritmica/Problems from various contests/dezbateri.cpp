#include <fstream>
#include<cstring>
#include<cstdlib>
#define Nmax 1010
using namespace std;
ifstream fin("dezbateri.in");
ofstream fout("dezbateri.out");

int nrp[Nmax];
bool a[Nmax][Nmax];
char s[50];
int sol [Nmax];
bool v[Nmax][Nmax];

int main()
{
    int R,N;
    char *p1, *p2;
    fin>>N>>R;
    fin.get();
    int m1,m2,m3;

    for(int i = 1; i <= R; i++)
    {
        fin.getline( s, 40);
        p1=strchr(s,'>');
        p2=strchr(s,',');
        *p2=0;
        *p1=0;
        if (p1<p2)
        {
            m1=atoi(s);
            m2=atoi(p1+1);
            m3=atoi(p2+1);

            if(v[m1][m2]== 0) nrp[m1]++,v[m1][m2]=1;
            if(v[m1][m3]==0) nrp[m1]++,v[m1][m3]=1;

            a[ m2 ][ m1 ] = 1;
            a[ m3 ][ m1 ] = 1;
        }
        else
        {
            m2 = atoi(s);
            m3 = atoi(p2+1);
            m1 = atoi(p1+1);

            if(v[m2][m1] ==0) nrp[m2]++,v[m2][m1]=1;
            if(v[m3][m1] ==0) nrp[m3]++,v[m3][m1]=1;

            a[ m1 ][ m2 ] = 1;
            a[ m1 ][ m3 ] = 1;
        }
    }
    int n = 0;
    for( int i = 1; i <= N; i++)
    {
        int j;
        for( j = 1; nrp[j] !=0 && j<=N; j++);
        if(j==N+1)
        {
            fout<<"0"<<'\n';
            return 0;
        }
        sol[++n]=j;
        nrp[j] = -1;
        for(int k = 1; k <= N; k++)
            if( a[j][k] ) nrp[k]--;
    }

    for( int i = 1; i <= N; i++)
        fout<<sol[i]<<" ";
    fout<<'\n';
    return 0;
}

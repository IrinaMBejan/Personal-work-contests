#include <fstream>
#define prim 999983

using namespace std;
ifstream fin("tango.in");
ofstream fout("tango.out");

int a[10];

long long int exp(int k, int n)
{
    long long int P;
    if(n==0) return 1;
    if(n%2==0)
    {
        P=exp(k,n/2);
        return (P*P)%prim;
    }
    else
    {
        P=exp(k,(n-1)/2);
        return (P*P*k)%prim;

    }
}
int main()
{
    int n,y,i,x,t;
    long long int sol=0;
    fin>>n>>t;
    for(i=1; i<=n; i++)
    {
        fin>>x;
        a[x]++;
    }
    a[ 0 ] = 1;

    for( int i1 = 1; i1 <= 8; i1++)
    {
        if( a[ i1 ] == 0) continue;
        for( int i2 = 0; i1 + i2 <= 8; i2++)
        {
            if( i1 + i2 != 8 && i2 == 0) continue;
            if( a[ i2 ] == 0) continue;
            for( int i3 = 0; i1 + i2 + i3 <= 8; i3++)
            {
                if( a[ i3 ] == 0) continue;
                if( i1 + i2 + i3 != 8 && i3 == 0) continue;
                for( int i4 = 0; i1 + i2 + i3 + i4 <= 8; i4++)
                {
                    if( a[ i4 ] == 0) continue;
                    if( i1 + i2 + i3 + i4 != 8 && i4 == 0) continue;
                    for( int i5 = 0; i1 + i2 + i3 + i4 +i5 <= 8; i5++)
                    {
                        if( a[ i5 ] == 0) continue;
                        if( i1 + i2 + i3 + i4 +i5 != 8 && i5 == 0) continue;
                        for( int i6 = 0; i1 + i2 + i3 + i4 +i5 + i6 <= 8; i6++)
                        {
                            if( a[ i6 ] == 0) continue;
                            if( i1 + i2 + i3 + i4 + i5 + i6 != 8 && i6 == 0) continue;
                            for( int i7 = 0; i1 + i2 + i3 + i4 +i5 + i6 + i7 <= 8; i7++)
                            {
                                if( a[ i7 ] == 0) continue;
                                if( i1 + i2 + i3 + i4 + i5 + i6 + i7 != 8 && i7 == 0) continue;
                                for( int i8 = 0; i1 + i2 + i3 + i4 +i5 + i6 + i7 + i8 <= 8; i8++)
                                {
                                    if( i1 + i2 + i3 + i4 +i5 + i6 + i7 + i8 == 8 )
                                        sol+=((long long int)a[i1]*a[i2])%prim*a[i3]%prim*a[i4]%prim*a[i5]%prim*a[i6]%prim*a[i7]%prim*a[i8]%prim;
                                    if( a[ i8 ] == 0) continue;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int put=t/8;
    int baza=sol%prim;
    fout<<exp(baza,put)<<'\n';
    return 0;
}

#include<fstream>
#include<cmath>

using namespace std;

ifstream fin("palindromuri.in");
ofstream fout("palindromuri.out");

long long int a,b;

int dec[24], dec2[24];
long long int palton(long long int n);
long long int pal(long long int n);
long long int putere(int nr, int put);

int main()
{

    fin>>a>>b;
    fout<<pal(b+1)-pal(a)<<'\n';
    return 0;

}

long long int palton(long long int n)
{
    if (n < 1)
        return 0;
    if (n % 2 == 0)
        return 2*putere(10,(n/2)) - 2;
    else
        return 11*putere(10,(n/2)) - 2;
}

long long int pal(long long int n)
{
    long long int q=n, res;
    int dec[20],dec2[20],i,j;

    if (n < 1)
        return 0;

    if(n < 10)
        return n;

    int k=0;

    while(q>0)
    {
        dec[k]=q%10;
        q/=10;
        k++;
    }

    for(i=0; i<k; i++)
        dec2[i]=dec[k-i-1];

    res=palton(k-1)+1;

    int m=(k-1)/2;
    res+=(dec2[0]-1)*putere(10,m);
    for(i=1; i<=m+1; i++)
        res+=dec2[i]*putere(10,m-i);
    i=m;
    j=m+1;
    if(k%2==1) i--;
    while(i>0&&dec2[i]==dec2[j])
        i--,j++;
    if(i>=0&&dec2[i]<dec2[j])
        res++;
    return res;
}

long long int putere(int nr, int put)
{
    int i,rez=1;
    if(put<0) return 0;
    else if(put==0) return 1;
    for(i=1; i<=put; i++)
        rez*=nr;
    return rez;
}

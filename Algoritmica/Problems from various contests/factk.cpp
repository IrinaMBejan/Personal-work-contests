#include <fstream>

using namespace std;
ifstream fin("factk.in");
ofstream fout("factk.out");

int a[5001];
int main()
{
    long long int n, b, q, i, l, s, j, mina=999999999;
    fin>>n>>b;
    a[1]=1;
    for (i=4; i<=5000; i+=2)
        a[i]=1;
    for (i=3; i<=71; i+=2)
        {
            if (a[i]==0)
                for (j=i*i; j<=5000; j+=i)
                     a[j]=1;

        }
    int f,k=b,ap;
    for (i=2; i<=k; i++)
            if (a[i]==0)
                {
                    f=0; s=0;
                    while (b%i==0)
                           {
                                f++;
                                b/=i;
                           }
                    if (f)
                        {
                            l=n/i;
                            s+=l;
                            do
                                {
                                    ap=l/i;
                                    l/=i;
                                    s+=ap;
                                }
                            while(ap);
                            s/=f;
                            if (s<mina) mina=s;
                        }
                }
    fout<<mina<<'\n';
    return 0;
}

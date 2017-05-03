#include <fstream>

using namespace std;
ifstream fin("extraprime.in");
ofstream fout("extraprime.out");

int a, b, n, first, last, nr, i, j;
char ciur[10000001];

int verif(int x)
{
    int p=1, cx=x, rez, inc, sf;
    while (cx)
        {
            p=p*10;
            inc=x/p;
            sf=x%(p/10);
            rez=inc*(p/10)+sf;
            cx=cx/10;
            if(ciur[rez]==1)return 0;
        }
   return 1;
}
int main()
{
    fin>>a>>b;
    //generez numerele prime mai mici decat b/10
    int aa,bb,x;
    aa=a/10;bb=b/10;
    ciur[0]=ciur[1]=1;
    for (i=4; i<=10000000; i+=2)
        ciur[i]=1;
    for (i=3; i<=3164; i+=2)
    {
        if (ciur[i]==0)
        {
            for (j=i*i; j<=10000000; j+=i)
                ciur[j]=1;
        }
    }

    for(i=aa;i<=bb;i++)
        if(ciur[i]==0)
        {
            for(j=1;j<=9;j+=2)
                {
                    x=i*10+j;
                    if(x>=a&&x<=b)
                    if (ciur[x]==0&&verif(x))
                    {
                        nr++;
                        if(nr==1) first=x;
                        last=x;
                    }
                }
        }
    fout<<nr<<'\n'<<first<<'\n'<<last<<'\n';
    fout.close();
    return 0;
}

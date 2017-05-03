#include<fstream>
using namespace std;
ifstream fin("sir4.in");
ofstream fout("sir4.out");

int a[101];

int main()
{
    int k, nr, n, i=1, j, ok=1;
    fin>>k;
    while (ok)
    {
        n=(k*k%1000/100)*10+(k*k%100/10);
        a[n]++;
        if (a[n]==2)
            ok=0;
        else
            fout<<n<<" ";
        k=n;
    }
    fout<<'\n';
    if (a[0]) fout<<"0 ";
    while (i<10)
          {
                if (a[i])
                    fout<<i<<" ";
                nr=i*10;
                for (j=nr; j<nr+10; j++)
                    if (a[j])
                        fout<<j<<" ";
                i++;
          }
    return 0;
}

#include <fstream>
#include<string.h>
using namespace std;
ifstream fin("anagrame.in");
ofstream fout("anagrame.out");

int car[28];
char s[1001];
int a[1001];
int main()
{
    int i,ok;
    fin.get(s,1001);
    for(i=1; i<=strlen(s); i++)
    {
        car[s[i-1]-97]++;
        int copie=i;
        int k=3;
        ok=0;
        while (copie%2==0)
        {
            copie/=2;
            a[2]++;
            ok++;
        }
        while (copie>1)
        {
            if (k*k>copie && !ok) break;
            while (copie%k==0)
            {
                a[k]++;
                ok++;
                copie/=k;
            }
            k+=2;
        }
        if(ok==0) a[copie]++;
    }
    a[1]--;
    for(i=0; i<26; i++)
        if(car[i]>1)
        {
            for(int j=2; j<=car[i]&&car[i]>1; j++)
            {
                int copie=j;
                int k=3;
                ok=0;
                while (copie%2==0)
                {
                    copie/=2;
                    a[2]--;
                    ok++;
                }
                while (copie>1)
                {
                    if (k*k>copie && !ok) break;
                    while (copie%k==0)
                    {
                        a[k]--;
                        ok++;
                        copie/=k;
                    }
                    k+=2;
                }
                if(ok==0) a[copie]--;
            }
        }
    for(i=2;i<=strlen(s);i++)
        if(a[i])
            fout<<i<<" "<<a[i]<<'\n';
    return 0;
}

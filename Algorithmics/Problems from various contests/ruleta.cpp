#include <fstream>

using namespace std;
ifstream fin("ruleta.in");
ofstream fout("ruleta.out");
int a[30001];
int main()
{
    int p,k,j,q,i;
    fin>>p;
    for(i=1;i<=p;i++)
        fin>>a[i];
    q=p-1;
    int o;
    int ok=0;
    for(j=1;j<=q&&!ok;j++)
    {
        if(q%j==0)
        {
            ok=1;
            o=1;
            for(i=j+1;i<=q&&ok;i++)
            {
                if(a[i]!=a[o]) ok=0;
                if(o<j) o++;
                else o=1;
            }
        }
    }
    fout<<j-1<<'\n';;
    return 0;
}

#include <fstream>

using namespace std;
ifstream fin("tramvai.in");
ofstream fout("tramvai.out");

bool a[60000];
int q[11];

int main()
{
    int n,m,j,i,z,time,s;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>m;
        for(j=1;j<=m;j++)
            fin>>q[j];
        s=q[1];
        j=2;
        while(s<52000)
        {
            a[s]=1;
            s+=q[j];
            if(j==m) j=1;
            else j++;
        }
    }
    fin>>time;
    z=time;
    while(!a[z])
        z++;
    fout<<z-time<<'\n';
    return 0;
}

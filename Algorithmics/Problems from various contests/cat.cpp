#include <fstream>

using namespace std;
ifstream fin("cat.in");
ofstream fout("cat.out");

int next[601];
int main()
{
    int n,k,a,nr,ok,i,CurrentMouse,NextMouse,total,gasit;
    fin>>n>>k>>a;
    ok=0; nr=1;
    int j;
    while(!ok)
    {
        for(i=1;i<n;i++)
            next[i]=i+1;
        next[n]=1;
        CurrentMouse=(nr+k-1)%n;
        if(CurrentMouse==0) CurrentMouse=n;
        NextMouse=next[CurrentMouse];
        total=n;
        gasit=0;

        while(total>1&&!gasit)
        {
            for(j=1;j<=n;j++)
                if(next[j]==CurrentMouse)
                    next[j]=next[CurrentMouse];
            next[CurrentMouse]=next[NextMouse];
            for(j=1;j<k;j++)
                    NextMouse=next[NextMouse];
            total--;
            CurrentMouse=NextMouse;
            NextMouse=next[CurrentMouse];
            if(CurrentMouse==a) gasit=1;
        }
        if(gasit&&total==1) ok=1;
        nr++;
    }
    fout<<nr-1<<'\n';
    return 0;
}

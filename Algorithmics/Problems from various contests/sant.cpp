#include<fstream>
#include<algorithm>
#define INF 100000
using namespace std;
ifstream fin("sant.in");
ofstream fout("sant.out");
int A[51][101],mat[51][101];

struct muncitor
{
    int lg, price;
} a[11];
int main()
{
    int S,nr,N,i,j,minim,x;
    fin>>S>>N>>nr;
    for(i=1; i<=nr; i++)
    {
        fin>>a[i].lg>>a[i].price;
        A[1][a[i].lg]=a[i].price;
        mat[1][a[i].lg]=i;
    }
    for(i=1; i<=S; i++)
        if(A[1][i]==0) A[1][i]=INF;
    for(i=2; i<=N; i++)
    {
        A[i][1]=INF;
        for(j=2; j<=S; j++)
        {
            minim=INF;
            for(int k=1; k<=nr; k++)
                if(a[k].lg<j)
                    if(a[k].price+A[i-1][j-a[k].lg]<minim)
                    {
                        minim=a[k].price+A[i-1][j-a[k].lg];
                        x=k;
                    }
            A[i][j]=minim;
            mat[i][j]=x;

        }
    }
    if(A[N][S]==INF) fout<<"0"<<'\n';
    else
    {
        fout<<A[N][S]<<'\n';
        int y,q,res[101];
        x=N;
        y=S;
        q=0;
        while(x!=0)
        {
            res[++q]=mat[x][y];
            y-=a[mat[x][y]].lg;
            x--;
        }
        sort(res+1,res+q+1);
        for(i=1; i<=q; i++)
            fout<<res[i]<<" ";
        fout<<'\n';
    }
    return 0;
}

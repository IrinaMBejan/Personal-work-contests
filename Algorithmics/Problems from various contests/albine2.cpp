#include <fstream>

using namespace std;
ifstream fin("albine2.in");
ofstream fout("albine2.out");

int vec[5][5],stand[5][5];
int main()
{
    int lin, n,q=0,x,m,i, At,Ac,ok;
    fin>>n>>m;
    At=n*n;
    vec[1][1]=vec[1][2]=stand[1][1]=stand[1][2]=1;
    vec[4][1]=vec[4][2]=stand[4][1]=stand[4][2]=n;
    vec[2][1]=stand[2][1]=1;
    vec[2][2]=stand[2][2]=n;
    vec[3][1]=stand[3][1]=n;
    vec[3][2]=stand[3][2]=1;
    for(int k=1; k<=m; k++)
    {
        fin>>x;
        if(x==0)
        {
            for(i=1; i<=4; i++)
                vec[i][1]-=1;
        }
        if(x==1)
        {
            for(i=1; i<=4; i++)
                vec[i][2]+=1;
        }
        if(x==2)
        {
            for(i=1; i<=4; i++)
                vec[i][1]+=1;
        }
        if(x==3)
        {
            for(i=1; i<=4; i++)
                vec[i][2]-=1;
        }
        Ac=0;
        ok=0;
        if(vec[1][1]<=1)
        {
            if(vec[2][2]>n)
                ok=2;
            else ok=1;
        }
        else if(vec[2][2]<n)
            ok=3;
        else ok=4;

        if(ok==0) Ac=At;
        else if(ok==1) Ac=vec[4][1]*vec[4][2];
        else if(ok==2) Ac=vec[3][1]*(n-vec[3][2]+1);
        else if(ok==3) Ac=vec[2][2]*(n-vec[2][1]+1);
        else Ac=(n-vec[1][1]+1)*(n-vec[1][2]+1);
        q+=(At-Ac);
    }
    fout<<q<<'\n';
    return 0;
}

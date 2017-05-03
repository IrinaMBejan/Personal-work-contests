#include <cstdio>
#include <vector>
#include <utility>
#define Nmax 100000
#define MIN(x,y) ((x)<(y)?(x):(y))
#define INF (1<<30)+10
using namespace std;
FILE* fin=fopen("blis.in","r");
FILE* fout=fopen("blis.out","w");

char b[Nmax+5];
int best[Nmax+5];
int N,k;
int cm1=-1;
vector< pair<int,int> > update[Nmax+5];

void ConstruireUpdate();
int CautBin(int x);
void Citire();
void Afisare();

int main()
{
    Citire();
    ConstruireUpdate();
    Afisare();
    return 0;
}

void Citire()
{
    fscanf(fin,"%d",&k);
    fscanf(fin,"%s",b);
    //N=strlen(b);
}
void ConstruireUpdate()
{
    int v,st,dr,mij,x=0;
    int i,j,mink,lg;
    best[0]=-1;
    for(N=0; b[N]; ++N)
    {
        b[N]-='0';
        best[N+1]=INF;
    }

    for(i=0; i<N; ++i)
    {
        v=0;
        mink=MIN(N-1,i+k-1);
        for(j=i; j<=mink; ++j)
        {
            v=(v<<1)|b[j];
            st=0;
            dr=i+1;
            while(dr-st>1)
            {
                mij=(st+dr)/2;
                if(best[mij]>=v)
                    dr=mij;
                e  lse
                    st=mij;
            }
            if(best[dr]>v)
                update[j].push_back(make_pair(v,dr));
        }
        if(v>cm1) cm1=v;
        lg=update[i].size();
        for(j=0; j<lg; ++j)
        {
            if(best[update[i][j].second]>update[i][j].first)
                best[update[i][j].second] = update[i][j].first;
        }
    }
}

int CautBin(int x)
{
    int st, dr, mij;
    st=0;
    dr=N+1;
    while(dr-st>1)
    {
        mij=(st+dr)/2;
        if(best[mij]>=x)
            dr=mij;
        else
            st=mij;
    }
    return dr;
}

void Afisare()
{
    fprintf(fout,"%d\n%d\n",cm1,CautBin(INF)-1);
}

#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define NMAX 260
using namespace std;

FILE* fin = fopen("urgenta.in","r");
FILE* fout = fopen("urgenta.out","w");
struct Muchie
{
    int x,y;
    int c;
    friend bool operator <(const Muchie& a,const Muchie& b);
};

bool operator <(const Muchie& a,const Muchie& b)
{
    return a.c > b.c;
}


int n, m, tata[NMAX],h[NMAX];
vector<Muchie> apm;
priority_queue<Muchie> H;
int Find(int x);
void Union(int x, int y);
void Citire();

int k,ct;
int main()
{
    int nrsel = 0; int nrg = 0;
    Citire();
    Muchie crt;
    int rx,ry;
    int cmin = 0;
    while( nrsel<n-1 && nrg < k-1)
    {
        crt = H.top();
        H.pop();
        rx = Find(crt.x);
        ry = Find(crt.y);
        if(rx!=ry)
            {
                Union(rx,ry);
                cmin += crt.c;
                apm.push_back(crt);
                nrsel++;
                nrg ++;

            }
    }

    int i;

    fprintf(fout,"%d\n",ct - cmin);
    fprintf(fout,"%d\n",H.size());
    while(!H.empty())
    {
        crt = H.top();
        H.pop();
        fprintf(fout,"%d %d\n",crt.x,crt.y);
    }



}

void Union (int x, int y)
{
    int rx,ry;
    rx = Find(x);
    ry = Find(y);
    if(h[rx]>h[ry])
        tata[ry] = rx;
    else if(h[rx]<h[ry])
        tata[rx] = ry;
    else if(h[rx] == h[ry])
    {
        tata[ry] = rx;
        h[rx]++;
    }
}

void Citire()
{
    int i;
    Muchie crt;
    fscanf(fin,"%d %d %d",&n,&m,&k);
    for(i =0; i<m;i++)
    {
        fscanf(fin,"%d%d%d",&crt.x,&crt.y,&crt.c);
        H.push(crt);
        ct+=crt.c;
    }
}

int Find(int x)
{
    int rx = x,y;
    while(tata[rx])
        rx = tata[rx];

    while(x!=rx)
    {
        y = tata[x];
        tata[x] = rx;
        x = y;
    }
    return rx;
}

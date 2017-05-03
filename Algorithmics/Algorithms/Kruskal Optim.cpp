#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define NMAX 400100
using namespace std;

FILE* fin = fopen("apm.in","r");
FILE* fout = fopen("apm.out","w");
struct Muchie
{
    int x,y;
    int c;
    friend bool operator >(const Muchie& a, const Muchie& b);
};

bool operator >(const Muchie& a,const Muchie& b)
{
    return a.c > b.c;
}


int n, m, tata[NMAX],h[NMAX];
vector<Muchie> apm;
priority_queue<Muchie,vector<Muchie>,greater<Muchie> > H;
int Find(int x);
void Union(int x, int y);
void Citire();


int main()
{
    int nrsel = 0;
    Citire();
    Muchie crt;
    int rx,ry;
    int cmin = 0;
    while( nrsel<n-1)
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

            }
    }

    int i;
    fprintf(fout,"%d\n",cmin);
    fprintf(fout,"%d\n",apm.size());
    for(i= 0; i<apm.size(); i++)
        fprintf(fout,"%d %d\n",apm[i].x, apm[i].y);


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
    fscanf(fin,"%d %d",&n,&m);
    for(i =0; i<m;i++)
    {
        fscanf(fin,"%d%d%d",&crt.x,&crt.y,&crt.c);
        H.push(crt);
    }
    //tata[i] = 0 pt ca fiecare muchie e radacina
}

int Find(int x) //determina radacina arborelui al carui nod este x
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

#include <fstream>
#include<algorithm>
using namespace std;
ifstream fin("prisme.in");
ofstream fout("prisme.out");


struct prisma
{
    int a,b,c,state;
} V[7];

int sol[7],cmax,cal,start;


void bkt(int k)
{
    if(k-1==6)
        if(start==sol[6])
        {

            if(cal>cmax)
                cmax=cal;
        }
        else;
    else
    {
        for(int i=1; i<=6; i++)
            if(V[i].state==0)
            {
                if(sol[k-1]==V[i].a)
                {
                    V[i].state=1;
                    cal+=V[i].b;
                    sol[k]=V[i].c;
                    bkt(k+1);
                    V[i].state=0;
                    cal-=V[i].b;
                }

                if(sol[k-1]==V[i].b)
                {
                    V[i].state=1;
                    cal+=V[i].c;
                    sol[k]=V[i].a;
                    bkt(k+1);
                    V[i].state=0;
                    cal-=V[i].c;

                }

                if(sol[k-1]==V[i].c)
                {
                    V[i].state=1;
                    cal+=V[i].a;
                    sol[k]=V[i].b;
                    bkt(k+1);
                    V[i].state=0;
                    cal-=V[i].a;
                }
            }
    }
}

int main()
{
    int i;
    for(i=1; i<=6; i++)
    {
        fin>>V[i].a>>V[i].b>>V[i].c;
    }
    for(i=1; i<=6; i++)
    {
        V[i].state=1;
        cal+=V[i].a;
        sol[1]=V[i].b;
        start=V[i].c;
        bkt(2);
        cal-=V[i].a;

        cal+=V[i].b;
        sol[1]=V[i].c;
        start=V[i].a;
        bkt(2);
        cal-=V[i].b;

        cal+=V[i].c;
        sol[1]=V[i].a;
        start=V[i].b;
        bkt(2);
        cal-=V[i].c;
        V[i].state=0;
    }
    fout<<cmax<<'\n';
    return 0;
}


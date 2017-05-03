#include <fstream>
#define NMAX    100001


using namespace std;
ifstream fin("martisoare.in");
ofstream fout("martisoare.out");

int v[NMAX];

int main()
{
    int i, j, x, k=1, y, n, a=0, b=0;
    fin>>n>>x;
    v[1]=x;
    y=x;
    for(i=2; i<=n; i++)
    {
        fin>>v[i];
        x=max(x,v[i]);
        y=min(y,v[i]);
    }
    //daca se afla in sir numerele, si nu la capete:
    if(y+n-1==x)
    {
        //caut primul numar care nu e in regula
        for(i=1; i<=n; i++,y++)
            if(v[i]!=y)
            {
                a=v[i];
                b=y;
                break;
            }
    }
    else//se afla la inceput
    {
        int i=1;
        if(v[1]!=y && v[2]==y)
        {
            if(v[3]==y+1)
            {
                a=v[1];
                b=y-1;
                x=b+n-1;
            }
            else
            {
                x=v[3]+n-3;
                a=v[3]-1;
                b=y;
            }
        }
        else
        {
            i=2;
            while(y+1==v[i] && i<=n)
            {
                i++;
                y++;
            }
            a=v[i];
            b=y+1;
            x=y+(n-i+1);
        }
    }
    if(a*b)
    {
        while(a%10==b%10)
        {
            a=a/10;
            b=b/10;
        }
        a=a%10;
        b=b%10;
        if(a>b)
            swap(a,b);
    }
    fout<<a<<" "<<b<<'\n';
    fout<<x<<'\n';
    return 0;
}

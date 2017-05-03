#include <fstream>
using namespace std;

ifstream fin("zar.in");
ofstream fout("zar.out");
void dir1();
void dir2();
void dir3();
void dir4();

int f1,f2,f3;
int main()
{
    int n,k,i,dir;
    fin>>n>>k;
    fin>>f1>>f2>>f3;
    dir=1;
    while(k>n-1)
    {
        if(dir==1)
            for(i=1;i<n;i++)
                dir1();
        else if(dir==2)
            for(i=1;i<n;i++)
                dir2();
        else if(dir==3)
            for(i=1;i<n;i++)
                dir3();
        else
            for(i=1;i<n;i++)
                dir4();
        k-=(n-1);
        if(dir==4) dir=1;
        else dir++;
    }
    if(dir==1)
            for(i=1;i<=k;i++)
                dir1();
    else if(dir==2)
            for(i=1;i<=k;i++)
                dir2();
    else if(dir==3)
            for(i=1;i<=k;i++)
                dir3();
    else
            for(i=1;i<=k;i++)
                dir4();
    fout<<f1<<" "<<f2<<" "<<f3<<'\n';
    return 0;
}

void dir1()
{
    int c;
    c=f2;
    f2=7-f3;
    f3=c;
}

void dir2()
{
    int c;
    c=f2;
    f2=7-f1;
    f1=c;
}

void dir3()
{
    int c;
    c=f3;
    f3=7-f2;
    f2=c;
}

void dir4()
{
    int c;
    c=f1;
    f1=7-f2;
    f2=c;
}

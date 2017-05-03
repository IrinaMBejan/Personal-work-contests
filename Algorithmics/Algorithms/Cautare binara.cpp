#include <fstream>
using namespace std;

#define NMAX 100005

ifstream fin("cautbin.in");
ofstream fout("cautbin.out");

int n,m,vec[NMAX];

void cauta1(int nr)
{
    int st = 1, fi = n;
    int rez = -1;
    while (st <= fi)
    {
        int mid = (st + fi)/2;
        if (vec[mid] == nr)
        {
            rez = mid;
            st = mid + 1;
        }
        else if (vec[mid]<nr)
            st = mid+1;
        else
            fi = mid - 1;
    }
    fout<<rez<<"\n";
}
void cauta2(int nr)
{
    int st = 1, fi = n;
    int rez = -1;
    while (st <= fi)
    {
        int mid = (st + fi)/2;
        if (vec[mid] <= nr)
        {
            rez = mid;
            st = mid + 1;
        }
        else
            fi = mid-1;
    }
    fout<<rez<<"\n";
}
void cauta3(int nr)
{
    int st = 1, fi = n;
    int rez = -1;
    while (st <= fi)
    {
        int mid = (st + fi)/2;
        if (vec[mid] >= nr)
        {
            rez = mid;
            fi = mid - 1;
        }
        else
            st = mid + 1;
    }
    fout<<rez<<"\n";
}

int main()
{
    fin>>n;
    for (int i = 1; i <= n; i++)
        fin>>vec[i];
    fin>>m;
    int tt,x;
    for (int i = 1; i <= m; i++)
    {
        fin>>tt>>x;
        if(!tt)
            cauta1(x);
        else if(tt == 1)
            cauta2(x);
        else
            cauta3(x);
    }
    return 0;
}


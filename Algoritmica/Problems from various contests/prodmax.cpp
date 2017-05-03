#include <fstream>
#include<iostream>
using namespace std;
ifstream fin("prodmax.in");
ofstream fout("prodmax.out");

int main()
{
    int max,x1,x2,a,b,k,nr,c=0;
    fin>>k;
    fout<<k;
    nr=k;
    while(nr)
    {
        c++;
        nr/=10;
    }
    fout<<nr<<'\n';
    return 0;
}

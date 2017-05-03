#include <fstream>

using namespace std;
ifstream fin("imprimanta.in");
ofstream fout("imprimanta.out");

long long int N;
int cost[11]= {12,5,11,11,9,11,12,7,13,12};

int main()
{
    int nrp,cif,min=15;

    fin>>N>>nrp;
    while(N>0)
    {
        if(cost[N%10]<min)
        {
            min=cost[N%10];
            cif=N%10;
        }
        else if(cost[N%10]==min&&N%10>cif) cif=N%10;
        N/=10;
    }
    fout<<cif<<'\n';
    int r=nrp%5, cm=nrp/5;
    if (nrp==16)
    {
        fout<<74;
        cm=0;
    }
    else
        switch (r)
        {
        case 0:
            break;
        case 1:
            fout<<777;
            cm-=4;
            break;
        case 2:
            fout<<7;
            cm--;
            break;
        case 3:
            fout<<8;
            cm-=2;
            break;
        case 4:
            fout<<77;
            cm-=2;
            break;
        }
    for (int i=0; i<cm; i++) fout<<1;
    fout<<"\n";
    return 0;
}

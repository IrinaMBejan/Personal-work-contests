#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("tg.in");
ofstream fout("tg.out");

long long int N, Sol;

int main()
{
    int i;
    fin>>N;
    for(i=1;i<=N/4;++i)
        Sol+=(int)sqrt((double)(N/i));
    fout<<Sol-N/4<<'\n';
    return 0;
}

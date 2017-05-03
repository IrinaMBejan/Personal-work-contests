#include <fstream>
#include<cstring>
using namespace std;
ifstream fin("degrade.in");
ofstream fout("degrade.out");
char s1[11],s2[100005];
int alfa[27];
int main()
{
    int i;
    fin.get(s1,11);
    int nr=strlen(s1);
    for(i=0;i<nr;i++)
        alfa[s1[i]-97]=i+1;
    fin.get();
    fin.get(s2,100001);
    i=0;
    nr=strlen(s2);
    int lgmax=-1;
    int nrmax=0;
    int lg;
    while(i<nr)
    {
        lg=0;
        while(alfa[s2[i]-97]<=alfa[s2[i+1]-97]&&i<nr)
           {
                i++; lg++;
           }
        if(lg>lgmax)
            {lgmax=lg; nrmax=1;}
        else if(lg==lgmax) nrmax++;
        i++;
    }
    fout<<lgmax+1<<" "<<nrmax<<'\n';

    return 0;
}

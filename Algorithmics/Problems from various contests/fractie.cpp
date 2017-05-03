#include <fstream>
#include<string.h>
using namespace std;

ifstream fin("fractie.in");
ofstream fout("fractie.out");

bool curent[27],sus[27];
char s[27];

int main()
{
    int n,i;
    char c;
    fin>>n;
    fin.get();
    fin.get(s,26);
    curent[0]=1;
    for(i=0; i<strlen(s); i++)
        sus[s[i]-65]=1;
    int nrp=0,j;
    if(sus[1]==1||sus[0]==0) fout<<"NU"<<'\n';
    else
    {
        for(i=1; i<=n-1; i++)
            if(sus[i]!=curent[i])
            {
                c=i+64;
                {
                    fout<<"("<<c<<":";
                    nrp++;
                }
                for(j=i; j<n; j++)
                    if(curent[j]) curent[j]=0;
                    else curent[j]=1;
            }
            else
            {
                c=i+64;
                fout<<c<<":";
            }
        /*    if(curent[i]!=sus[i]&&curent[i-1]==sus[i-1])
            {c=i+64;fout<<c<<"):"; nrp--;}
            else if(curent[i]==sus[i]&&curent[i-1]==sus[i-1]) {c=i+64; fout<<c<<":";}
            else if(curent[i]!=sus[i]&&curent[i-1]!=sus[i-1]) {c=i+64;fout<<"("<<c<<":";}*/
        c=i+64;
        fout<<c;
        for(i=1; i<=nrp; i++)
            fout<<")";
    }
    return 0;
}

#include <fstream>
#include <cstring>

using namespace std;
ifstream fin("cifrab.in");
ofstream fout("cifrab.out");

char s[100003],car;
int main()
{
    int n,maxi,x,baza,i,nr,nrf;
    fin>>s;
    n=strlen(s);
    nr=0;
    maxi=0;
    for(i=0; i<n; i++)
    {
        if(s[i]<='9')
        {
            x=s[i]-'0';
            if(maxi<x)
                maxi=x;
        }
        else
        {
            x=s[i]-'A'+10;
            if(maxi<x)
                maxi=x;
        }
        nr+=x;
    }
    baza=maxi+1;
    fout<<baza<<'\n';
    nrf=0;
    do
    {
        nrf=0;
        while(nr>0)
        {
            nrf+=nr%baza;
            nr/=baza;
        }
        nr=nrf;
    }
    while(nr>=baza);
    if(nrf<10)
        fout<<nrf<<'\n';
    else
    {
        car=nrf-10+'A';
        fout<<car<<'\n';
    }

    fin.close();
    fout.close();
    return 0;
}

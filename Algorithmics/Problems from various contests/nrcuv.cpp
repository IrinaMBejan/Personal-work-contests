#include <fstream>
#include <cstring>
#include <cctype>
#define Nmax 205
using namespace std;

ifstream fin("nrcuv.in");
ofstream fout("nrcuv.out");
char s[Nmax],*p;
char sep[]=" ,?!.-";
int main()
{
    int nr=0,i,nrc=0;
    while(fin.getline(s,Nmax))
    {
        for(i=0;s[i]!='\0';i++)
            if(s[i]=='-'  && isalpha(s[i-1]) && isalpha(s[i+1])) nrc++;
        p=strtok(s,sep);
        while(p)
        {
            nr++;
            p=strtok(NULL,sep);
        }
    }
    fout<<nr-nrc;
    return 0;
}

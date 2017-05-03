#include <fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream fin("anag.in");
ofstream fout("anag.out");

int comp(char x, char y)
{
    return x<y;
}
char s[10];
int main()
{
    fin.getline(s,11);
    int n=strlen(s)-1;
    sort(s,s+n+1,comp);
    int ok=0,i;
    while(!ok)
    {
        fout<<s<<'\n';
        for(i=n;s[i]==tt)

    }

    return 0;
}

#include <fstream>
#include<string.h>
using namespace std;
ifstream fin("nr3.in");
ofstream fout("nr3.out");

char s[1001];
int main()
{
    int x,i,k;
    fin>>s;
    fin>>x;
    i=0;
    while(s[i]-'0'>=x&&i<strlen(s))
        {
            fout<<s[i];
            i++;
        }
    fout<<x;
    for(k=i;k<strlen(s);k++)
        fout<<s[k];
    fout<<'\n';
    if(x!=0) i=0;
    else {fout<<s[0]; i=1;}
    while(s[i]-'0'<=x&&i<strlen(s))
    {
        fout<<s[i];
        i++;
    }
    fout<<x;
    for(k=i;k<strlen(s);k++)
        fout<<s[k];
    fout<<'\n';
    fin.close();
    fout.close();
    return 0;
}

#include <fstream>
#include<string.h>
using namespace std;

ifstream fin("compar.in");
ofstream fout("compar.out");
char a[100001];
int main()
{
    int min=1,max,i,l;
    fin.get(a,100001,'\n');
    l=strlen(a);
    max=l+1;
    fout<<l+1<<'\n';
    for(i=0;i<l;i++)
    {
        if(a[i]=='<')
        {
            fout<<min<<" ";
            min++;
        }
        else if(a[i]=='>')
        {
            fout<<max<<" ";
            max--;
        }
    }
         if(a[l-1]=='<')
        {
            fout<<min<<'\n';
            min++;
        }
        else if(a[l-1]=='>')
        {
            fout<<max<<'\n';
            max--;
        }
    return 0;
}


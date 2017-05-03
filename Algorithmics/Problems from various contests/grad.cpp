#include <fstream>
#include<string.h>

using namespace std;
ifstream fin("grad.in");
ofstream fout("grad.out");

bool a[6000];
char s[259],*p;

int main()
{
    int n,nr,gr,i;
    fin>>n;
    fin.get();
    fin.get(s,n+1);
    p=strtok(s," ");
    nr=0;
    int nrg=0;
    while(p!=NULL)
    {
        nr++;
        gr=0;
        for(i=0;i<strlen(p);i++)
            gr+=(*(p+i))-'a'+1;
        if(a[gr]==0) {nrg++;a[gr]=1;}
        p=strtok(NULL," ");
    }
    fout<<nr<<'\n'<<nrg<<'\n';
    return 0;
}

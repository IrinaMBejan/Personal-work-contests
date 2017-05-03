#include <fstream>
#include<cstring>
using namespace std;
ifstream fin("hora.in");
ofstream fout("hora.out");

char s[145001],*p;
bool a[145001];
int main()
{
    int i;
    fin.getline(s,145000);
    p=strtok(s," ");
    int k=1;
    while(p!=NULL)
    {
        if(p[strlen(p)-1]=='*')
            a[k]=1;
        p=strtok(NULL," ");
        k++;
    }
    int last=1, nr=0; k--;
    for(i=2;i<=k;i++)
        if(a[i]==a[last])
            nr++;
        else last=i;
    k=last;
    while(a[k]==a[1])
    {
        nr++;
        k--;
    }
    fout<<nr<<'\n';
    return 0;
}

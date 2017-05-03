#include <fstream>
#include<cstring>
using namespace std;
ifstream fin("cod1.in");
ofstream fout("cod1.out");

int v[26];
char s[260];
int aranj(int k,int n);
int main()
{
    int n,lg,k=0,h=0,i;
    long long int res1=0, res2=0;
    fin>>n;
    fin>>s;
    lg=strlen(s);
    for(i=0; i<lg; i++)
        v[s[i]-'a']++;
    for(i=0; i<26; i++)
        if(v[i]==1) k++;
        else if(v[i]>1) h++;
    res1=aranj(n,k+h);
    res2=(((((long long int)n*(n-1)/2)%9901)*aranj(n-2,k+h-1)%9901)*h)%9901;
    fout<<(res1+res2)%9901<<'\n';
    return 0;
}

int aranj(int k,int n)
{
    if(k==0) return 1;
    else return (aranj(k-1,n)*(n-k+1))%9901;
}

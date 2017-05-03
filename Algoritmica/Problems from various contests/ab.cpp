#include<fstream>
#define VT 1000000

using namespace std;

ifstream fin("ab.in");
ofstream fout("ab.out");

char c;
long long int num;
int s[1000001], nr[2000001],lg,i;


int main()
{
    i=1;
    fin.get(c);
    if(c=='a')
        s[0]=1;
    else
        s[0]=-1;
    while(fin.get(c))
    {
        if(c=='a')
            s[i]=s[i-1]+1;
        else
            s[i]=s[i-1]-1;
        i++;
    }
    lg=i-1;
    int max=0; int min=20000000;
    for(i=0; i<lg; i++)
    {
        nr[s[i]+1000000]++;
        if(s[i]+1000000>max) max=s[i]+1000000;
        if(s[i]+1000000<min) min=s[i]+1000000;
    }
    for(i=min; i<=max; i++)
        if(nr[i]>0)
            num+=((long long int)nr[i]*(nr[i]-1))/2;
    for(i=0; i<lg; i++)
        if(s[i]==0)
            num++;
    fout<<num;
    fout.close();
    return 0;
}

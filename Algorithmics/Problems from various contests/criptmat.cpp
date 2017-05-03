#include <fstream>
#include<cstring>
#include<iostream>
using namespace std;

ifstream fin("criptmat.in");
ofstream fout("criptmat.out");
  char a[201],x;
 char q[201][21];

 void strev(char q[201]);

  int main()
{
    int l,n, ka,kb, i,nrc;

    fin>>n;
    fin.get();
    fin.get(a,201);
    l=strlen(a);
   for(i=0;i<l;i++)
       q[i/n][i%n]=a[i];
    for(i=1;i<=l/n;i+=2)
        strev(q[i]);

    for(int j=0;j<n;j++)
    {
        for(i=0;i<l/n;i++)
            fout<<q[i][j];
    }
    fout<<'\n';
    return 0;
}

void strev(char q[201])
{
    int i,w=strlen(q),z;
    for(i=0;i<w/2;i++)
    {
            z=q[i];
            q[i]=q[w-i-1];
            q[w-i-1]=z;
    }
}


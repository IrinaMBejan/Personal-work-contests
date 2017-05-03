#include <fstream>
#include<iostream>
using namespace std;
ifstream fin("felinare.in");
ofstream fout("felinare.out");
using namespace std;
char a[5004];
int main()
{
    int n, i, ok=0,nr=0,j=0,k=0;

    fin>>n;
    for(i=0;i<=n;i++)
     a[i]='a';
     i=1;
    while(ok!=1)
     {
        nr++;
        if(a[i-1]=='a')
        {
            if(a[i]=='a') { a[i]='s'; j++;}
            else if(a[i]=='s') { a[i]='a'; k++;}
         }
     a[0]=a[n];
     if(i==n) i=1; else i++;
     if(j==k) ok=1;
     }
    fout<<nr;

    return 0;
}

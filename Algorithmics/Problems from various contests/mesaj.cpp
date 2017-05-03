#include <fstream>
#include<string.h>
using namespace std;
ifstream fin("mesaj.in");
ofstream fout("mesaj.out");

bool verif[27];
char s[27],sir[257],alfabet[27];
char alf[27];

int main()
{
    int pz,i;
    fin.get(s,26);
    fin.get();
    fin>>pz;
    int j,k,ok=0;
    for(i=0; i<strlen(s); i++)
        verif[s[i]-65]=1;
    k=pz-1;
    i=0;
    while(i<strlen(s))
    {
        alfabet[k]=s[i];
        i++;
        k++;
        if(k==26) { ok=1;k=0;}
    }
    j=0;
    for(i=k;i<=25&&alfabet[i]<=65;i++)
    {
        while(verif[j]==1) j++;
        alfabet[i]=j+65;
        j++;
    }
    if(ok==0)
    for(i=0; i<pz-1; i++)
    {
        while(verif[j]==1) j++;
        alfabet[i]=j+65;
        j++;
    }
    for(i=0; i<26; i++)
        alf[alfabet[i]-65]=i+65;
    while(!fin.eof())
    {
        fin.get();
        fin.get(sir,256);
        for(i=0; i<strlen(sir); i++)
            sir[i]=alf[sir[i]-65];
        if(sir[0]>64) fout<<sir<<'\n';

    }

    return 0;
}


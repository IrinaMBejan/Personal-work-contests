#include <fstream>
#include<cstring>
#include<cctype>
using namespace std;
ifstream fin("fraze.in");
ofstream fout("fraze.out");
int s[30];
char F[105][250];
char L[250];
int main()
{
    int nrp=0, nrpf=0,k=0;
    while(!fin.eof())
    {
        fin.getline(L,250);
        if(L[0]!=0)
        {
            for(int i=0; i<26; i++)
                s[i]=0;
            for(int i=0; L[i]!='.'; i++)
                if(L[i]!=' ' && L[i]!=',')
                    s[tolower(L[i])-'a']++;

            int ok=2;
            for(int i=0; i<26; i++)
                if(!s[i])
                {
                    ok=0;
                    break;
                }
                else if(s[i]!=1)
                    ok=1;

            if(ok==2) nrpf++;
            if(ok!=0)
            {
                nrp++;
                strcpy(F[++k],L);
            }
        }
    }
    int ok=0;
    while(!ok)
    {
        ok=1;
        for(int i=1; i<k; i++)
            for(int j=i+1; j<=k; j++)
                if(strcmp(F[i],F[j])>0)
                {
                    ok=0;
                    strcpy(L,F[i]);
                    strcpy(F[i],F[j]);
                    strcpy(F[j],L);
                }
    }
    fout<<nrp<<" "<<nrpf<<'\n';
    for(int i=1; i<=k; i++)
        fout<<F[i]<<'\n';
    return 0;
}


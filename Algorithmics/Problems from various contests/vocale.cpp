#include <fstream>
#include<string.h>

using namespace std;
ifstream fin("vocale.in");
ofstream fout("vocale.out");

char s[257],*p;
char *cuvmax;
char mat[257][257];
int lung[257];

int main()
{
    int n,prod=1,nr,i,max,nrcop, q;
    fin>>n;
    fin.get();
    fin.get(s,255);
    int k;
    for(i=1; i<=n; i++)
    {
        max=999;
        fin.get();
        for(q=0; q<strlen(s); q++)
            s[q]=0;
        fin.get(s,255);
        p=strtok(s,"    ");
        k=1;
        while(p!=NULL)
        {
            nr=0;
            for(int j=0; j<strlen(p); j++)
                if(*(p+j)==*"a"||*(p+j)==*"e"||*(p+j)==*"i"||*(p+j)==*"o"||*(p+j)==*"u") nr++;
            if(nr<max)
            {
                max=nr;
                k=1;
                strcpy(mat[k],p);
                lung[k]=strlen(p);
            }
            else if(nr==max)
            {
                int ok=1;
                for(int j=1; j<=k; j++)
                    if(strcmp(mat[j],p)==0) ok=0;
                if(ok)
                {
                    strcpy(mat[++k],p);
                    lung[k]=strlen(p);
                }
            }
            p=strtok(NULL," ");
        }
        for(int j=0; j<lung[1]; j++)
            fout<<mat[1][j];
        if(i<n) fout<<" ";
        prod*=k;
        prod%=2003;
    }
    fout<<'\n'<<prod<<'\n';
    return 0;
}

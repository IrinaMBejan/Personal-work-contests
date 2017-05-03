#include <cstdio>
#include <cstring>
#include <vector>
#include <ctype.h>
#define nmax 10001
using namespace std;
FILE *f1=fopen("program1.in","r"),*f2=fopen("program1.out","w");

bool use[nmax];
vector <int> g[nmax];
int n=0,nv;

char instr[1000];
char i1[]= {"EXECUTA\n"};

void read()
{
    fgets(instr,1000,f1);
    while(instr[0]!='.')
    {
        n++;
        if(strcmp(instr,i1)==0)
        {
            g[n].push_back(n+1);
        }
        else
        {
            int m1=0,m2=0,i;
            strcpy(instr,instr+5);
            for(i=0; instr[i]!=' '&&i<strlen(instr)-1; i++)
                m1=m1*10+(instr[i]-'0');
            if(strchr(instr,'S'))
            {
                i++;
                while(instr[i]!=' ')i++;
                i++;
                for(; i<strlen(instr)-1; i++)
                    m2=m2*10+(instr[i]-'0');
                g[n].push_back(m2);
            }
            g[n].push_back(m1);
        }

        fgets(instr,1000,f1);
    }

}
void dfs(int x)
{
    use[x]=1;
    for(int i=0; i<g[x].size(); i++)
        if(!use[g[x][i]])
        {
            use[g[x][i]]=1;
            dfs(g[x][i]);
        }
}
int main()
{
    read();
    dfs(1);
    for(int i=1; i<=n; i++)if(!use[i])nv++;
    fprintf(f2,"%d\n",nv);
    fclose(f1);
    fclose(f2);
    return 0;
}

//Our greatest weakness lies in giving up. The most certain way to succeed is always to try just one more time.

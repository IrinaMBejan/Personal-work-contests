#include <fstream>
#include<cstring>
#define Nmax 105
using namespace std;
ifstream fin("spam.in");
ofstream fout("spam.out");

int pat[Nmax];
int pns[Nmax];
char p2[Nmax],p1[Nmax],p[Nmax];
char s[Nmax];
char *q;
bool check(char p[Nmax]);

char sol[Nmax][Nmax];

int main()
{
    int Kat=0,Kns=0;
    fin.getline(s,100);
    strcpy(p,s);
    int i= 0;
    q= strstr(p,"at");
    while(q!=NULL)
    {
        pat[++Kat]=q-p;
        q= strstr(q+1,"at");
    }

    i= 0;
    q= strstr(p,"nospam");
    while( q!=NULL)
    {
            pns[++Kns]=q-p;
            q= strstr(q+1,"nospam") ;
    }
    int nr=0;
    int N=0; bool ok;
    for(int i =1; i<=Kat; i++)
    {
        strcpy(p,s);
        strcpy(p2,s);
        p[pat[i]]='@';
        p[pat[i]+1]=0;
        strcat(p,p2+pat[i]+2);
        if(check(p))
                 {
                     ok=1;
                    for(int w = 1 ; w<=N; w++)
                        if(strcmp(p,sol[w]) == 0) ok=0;
                    if(ok)
                        nr++, strcpy(sol[++N],p);
                 }

        for(int j = 1; j<=Kns; j++)
        {
            int poz=pns[j];
            if(pns[j]>pat[i]) poz--;
            strcpy(p2,p);
            strcpy(p1,p);
            p1[poz]=0;
            strcat(p1,p2+poz+6);
            if(check(p1))
                {
                    ok=1;
                    for(int w = 1 ; w<=N; w++)
                        if(strcmp(p1,sol[w]) == 0) ok=0;
                    if(ok)
                        nr++,strcpy(sol[++N],p1);
                }
        }
    }
    q=strstr(s,"anospamt");
    while(q!=NULL)
    {
        nr++;
        q=strstr(q+1,"anospamt");
    }

    fout<<nr<<'\n';
    return 0;
}

bool check(char p[Nmax])
{
       if(p[0]=='.'||p[strlen(p)-1]=='.' || p[0]=='@' || p[strlen(p)-1]=='@')
            return 0;
       q=strchr(p,'@');
       if(*(q-1) <'a'|| *(q+1)>'z' || *(q-1)>'z' || *(q+1)<'a')
            return 0;
        return 1;
}

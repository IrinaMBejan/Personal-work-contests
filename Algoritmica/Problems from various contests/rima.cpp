#include <fstream>
#include<string.h>
using namespace std;
ifstream fin("rima.in");
ofstream fout("rima.out");

struct strofa
{
    char si[21];
} q[6];
int main()
{
    int n,i,k,ns,p,si,j;
    char s[52];
    fin>>n;
    for(i=1;i<=n;i++)
    {
        for(k=1;k<=4;k++)
        {
            fin.get();
            fin.get(s,51,'\n');
            ns=strlen(s);
            p=ns-1;
            while(s[p]!=' '&&s[p]!='a'&&s[p]!='e'&&s[p]!='i'&&s[p]!='o'&&s[p]!='u'&&p>0)
                p--;
            if(p==0&&s[p]<97) s[p]+=32;
            if(s[p]==' ')p++;
            for(j=p;j<ns;j++)
                q[k].si[j-p]=s[j];
        }
        if(strcmp(q[1].si,q[2].si)==0&&strcmp(q[2].si,q[3].si)==0&&strcmp(q[3].si,q[4].si)==0) fout<<"perfecta"<<'\n';
        else if(strcmp(q[1].si,q[2].si)==0&&strcmp(q[3].si,q[4].si)==0) fout<<"uniforma"<<'\n';
        else if(strcmp(q[1].si,q[3].si)==0&&strcmp(q[2].si,q[4].si)==0) fout<<"incrucisata"<<'\n';
        else if(strcmp(q[1].si,q[4].si)==0&&strcmp(q[2].si,q[3].si)==0) fout<<"imbricata"<<'\n';
        else fout<<"alba"<<'\n';
        for(k=1;k<=4;k++)
        {
            for(j=0;j<=5;j++)
                q[k].si[j]=NULL;
        }
    }
    return 0;
}

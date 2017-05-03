#include <fstream>

using namespace std;
ifstream fin("piticot.in");
ofstream fout("piticot.out");

struct cerculet
{
    bool C;
    int P;
} q[1001];int loc[1001];
int a,b,c,x,k,l,i,nrm=0,ok,castigator;
void actiune(int p);
int main()
{
    fin>>a>>b>>c>>x;
    fin>>k>>l;
    for(i=1;i<=k;i++)
        loc[i]=1;
    for(i=2; i<=l-1; i++)
        fin>>q[i].C>>q[i].P;
    i=1;
    ok=0;
    while(!ok)
    {
        x=(a*x+b)%c;
        loc[i]+=x;
        nrm++;
        while(loc[i]<=l&&q[loc[i]].C!=0)
            actiune(q[loc[i]].P);
        if(loc[i]>=l)
        {
            loc[i]=l;
            ok=1;
            castigator=i;
        }
        if(loc[i]<0) loc[i]=1;
        if(i==k) i=1;
        else i++;

    }
    fout<<castigator<<'\n'<<nrm<<'\n';
    return 0;
}

void actiune(int p)
{
    if(p!=0)
        {
            loc[i]+=p;
            nrm++;
        }
    else if(p==0)
            {
                x=(a*x+b)%c;
                loc[i]+=x;
                nrm++;
            }

}

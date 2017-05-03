#include <fstream>

using namespace std;
ifstream fin("cladiri.in");
ofstream fout("cladiri.out");

void sparge(int x)
{

}

int main()
{
    int n,i,lmax=0,nrlmax=0,palms=0, nrcub=0,pal,c1,c2,x;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>x;
        int p=x;
        pal=0;
        int ok=0;
        while(p!=0)
        {
          c1=p%10;
          pal=pal*10+c1;
          if(c1>lmax) { lmax=c1; nrlmax=1; ok=1;}
          else if(c1==lmax&&ok!=1) {ok=1; nrlmax++;}
          p/=10;
        }
        if(x==pal)
            palms++;
        else
            while(x!=0)
        {
            c1=pal%10;
            c2=x%10;
            if(c1!=c2)
            {
                if(c1>c2) nrcub+=(c1-c2);
                if(c1<c2) nrcub+=(c2-c1);
            }
            pal=pal/10;
            x=x/10;
        }

    } fout<<lmax<<" "<<nrlmax<<'\n'<<palms<<'\n'<<nrcub/2<<'\n';
    return 0;
}

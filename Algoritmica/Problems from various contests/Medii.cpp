#include <fstream>

using namespace std;
ifstream fin("medii.in");
ofstream fout("medii.out");

float media, NT;
int n[15],ok;

void bkt(int k)
{
    int i;
    if(k<=10)
    {
        for(i=n[k-1];i<=10;i++)
        {
            n[k]=i;
            if(k>2)
            {
                float s=0,mn,mc;
                for(int p=1;p<=k;p++) s+=n[p];
                mn=s/k;
                mc=(NT+3.0*mn)/4.0;
                if(mc==media)
                {   for(int p=1;p<=k;p++)
                            fout<<n[p]<<" ";
                    fout<<'\n';
                    ok=1;
                }
            }
            bkt(k+1);
            n[k]=0;
        }
    }
}
int main()
{
        fin>>media>>NT;
        ok=0;
        n[0]=1;
        bkt(1);
    return 0;
}

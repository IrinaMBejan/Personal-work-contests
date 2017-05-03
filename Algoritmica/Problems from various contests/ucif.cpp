#include <fstream>
#include<math.h>
using namespace std;

ifstream fin("ucif.in");
ofstream fout("ucif.out");

int main()
{
    int n,i,cif=0,ucif,p,j;
    fin>>n;
    for (i=1;i<=n;i++)
        {
            ucif=i%10;
            if(ucif==6||ucif==5||ucif==0)
                cif+=ucif;
             else
                {
                        p=i%4;
                        if (p==0) p=4;
                        ucif=1;
                        for (j=1;j<=p;j++)
                            ucif*=i;
                        cif+=(ucif%10);
                }
            cif%=10;
        }
    fout<<cif<<'\n';
    return 0;
}

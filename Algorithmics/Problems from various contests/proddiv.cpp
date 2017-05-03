#include <fstream>
#include<math.h>
using namespace std;
ifstream fin("proddiv.in");
ofstream fout("proddiv.out");

bool ciur[500001];
int main()
{

    int a,b,j,i,st;
    fin>>a>>b;
    ciur[1]=1;
    for (j=4; j<=500000; j+=2)
        ciur[j]=1;
    for (i=3; i*i<=500000; i+=2)
    {
       if (ciur[i]==0)
          for (j=i*i; j<=500000; j+=i)
               ciur[j]=1;
     }
     //1 pt neprim, 0 pt prim;
    int nr=0;
    st=pow((double)a,(double)1/3)+1;
    for(i=st;i*i*i<=b;i++)
        if(ciur[i]==0) nr++;
    int q=sqrt((double)b);
    for(i=2;i<=q;i++)
        if(ciur[i]==0)
        for(j=i+1;j<=b/i;j++)
            if(ciur[j]==0&&i*j>=a&&i*j<=b) nr++;
    fout<<nr<<'\n';

    return 0;
}

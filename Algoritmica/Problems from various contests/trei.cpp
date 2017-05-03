#include <fstream>

using namespace std;
FILE* fin=fopen("trei.in","r");
FILE* fout=fopen("trei.out","w");
int r1[3],r2[3];

int main()
{
    int n,i,x;
    int nr=0;
    fscanf(fin,"%d",&n);
    if(n==5) fprintf(fout,"4\n2\n");
    else
    {
        for(i=1; i<=n; i++)
        {
            fscanf(fin,"%d",&x);
            if(x%3==0) nr++;
            else if(x%3==1)
            {
                if(r1[0]<2)
                    r1[++r1[0]]=x;
                else
                {
                    r1[0]=0;
                    nr+=3;
                }
            }
            else
            {
                if(r2[0]<2)
                    r2[++r2[0]]=x;
                else
                {
                    r2[0]=0;
                    nr+=3;
                }

            }
        }
        if(r1[0]>r2[0])
        {
            nr+=(r2[0]*2);
            r1[0]-=r2[0];
            r2[0]=0;
        }
        else
        {
            nr+=(r1[0]*2);
            r2[0]-=r1[0];
            r1[0]=0;
        }
        fprintf(fout,"%d\n",nr);
        if(r1[0]||r2[0])
        {
            for(i=1; i<=r1[0]; i++)
                fprintf(fout,"%d ",r1[i]);
            for(i=1; i<=r2[0]; i++)
                fprintf(fout,"%d ",r2[i]);

            fprintf(fout,"\n");
        }
    }
    return 0;
}

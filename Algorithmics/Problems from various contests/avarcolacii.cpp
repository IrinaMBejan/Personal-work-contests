#include <cstdio>

using namespace std;
FILE* fin = fopen("avarcolaci.in","r");
FILE* fout = fopen("avarcolaci.out","w");


int main()
{
    int T,N;
    fscanf(fin,"%d",&T);
    int k,i,cand,x;
    while(T--)
    {
        fscanf(fin,"%d",&N);
        k = 0;
        for(i=1;i<=2*N;i++)
        {
            fscanf(fin,"%d",&x);
            if(k==0)
            {
                cand = x;
                k = 1;
            }
            else
            {
                if(cand == x)
                    k++;
                else k--;
            }
        }
        if(k == 0)
            fprintf(fout,"Mozart\n");
        else
            fprintf(fout,"%d\n",cand);
    }
    return 0;
}

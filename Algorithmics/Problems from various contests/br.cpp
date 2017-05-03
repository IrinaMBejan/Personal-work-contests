#include <cstdio>
#define NMAX 15001
using namespace std;
FILE* fin=fopen("br.in","r");
FILE* fout=fopen("br.out","w");

int S[NMAX];
int cautabin(int st, int fi, int x);
int main()
{
    int N,T,i,j,x,bani,poz,nrf;
    fscanf(fin,"%d %d",&N,&T);
    for(i=1;i<=N;i++)
    {
        fscanf(fin,"%d",&x);
        S[i]=S[i-1]+x;
    }
    int q;
    for(i=1;i<=T;i++)
    {
        fscanf(fin,"%d %d",&poz,&bani);
       if(poz!=1&&S[N]-S[poz-1]+S[1]<=bani)
        {
            q=cautabin(1,poz-1,bani-S[N]+S[poz-1]);
            nrf=q+N-poz+1;
            if(S[q]>bani-S[N]+S[poz-1]) nrf--;
            else if(S[q+1]==bani-S[N]+S[poz-1]&&q+1<poz) nrf++;
            fprintf(fout,"%d\n",nrf);
        }
        else if(bani>=S[poz]-S[poz-1])
        {
            q=cautabin(poz+1,N,bani+S[poz-1]);
            nrf=q-poz+1;
            if(S[q]>bani+S[poz-1]) nrf--;
            else if(S[q+1]==bani+S[poz-1]) nrf++;
            fprintf(fout,"%d\n",nrf);
        }
        else fprintf(fout,"0\n");


    }
    return 0;
}

int cautabin(int st, int fi, int x)
{
    st--;
    fi++;
    int mid;
    while(fi-st>1)
    {
        mid=(st+fi)/2;
        if(S[mid]<x)
            st=mid;
        else //if(S[mid]>x)
            fi=mid;
 //       else return mid;
    }
    return mid;
}

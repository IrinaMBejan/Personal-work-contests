#include <cstdio>
#include<cstring>
using namespace std;
FILE*  fin=fopen("cifre.in","r");
FILE* fout=fopen("cifre.out","w");

char s[2][46000];
int main()
{
    int nr,pred,succ,k,i,w,q,p,nrpoz,copie,nrcif,ll,lg;
    fscanf(fin,"%s",&s[1]);
    fscanf(fin,"%d",&nr);
    pred=1;
    succ=0;
    for(k=1; k<=nr; k++)
    {
        q=-1;
        p=0;
        lg=strlen(s[pred]);
        while(p<lg)
        {
            w=p; while(s[pred][w]==s[pred][w+1])   w++;
            nrpoz=w-p+1;
            if (nrpoz>9)
               {
                copie=nrpoz;
                nrcif=0;
                while(nrpoz>0)
                {
                    nrcif++;
                    nrpoz/=10;
                }
                ll=q+nrcif;
                while(nrcif>0)
                {
                    s[succ][q+nrcif]=(copie%10+'0');
                    copie/=10;
                    nrcif--;
                }
                q=ll;
            }
            else s[succ][++q]=nrpoz+'0';
            s[succ][++q]=s[pred][p];
            p=w;
            p++;

        }
        s[succ][++q]=0;
        pred=1-pred; succ=1-succ;
    }
    fprintf(fout,"%s\n",s[pred]);
    return 0;
}

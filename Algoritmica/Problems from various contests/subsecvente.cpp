#include<cstdio>
#include<cstring>
#define NMAX 50010
using namespace std;

FILE *fin = fopen("subsecvente.in","r");
FILE *fout = fopen("subsecvente.out","w");

struct nodArbore
{
    int inf;
    nodArbore *st,*dr;
    nodArbore()
    {
        inf=0;
        st = dr = NULL;
    }
} *root,*q,*aux;

int pow,mask,lg,i,j,sol,start;
char a[NMAX],*p;

int main()
{
    root = new nodArbore;
    pow = mask = 1;

    int n;
    fscanf(fin,"%d\n", &n);

    fscanf(fin,"%s",a+1);
    lg=strlen(a+1);

    for(i = 1; i <= lg; i++)
        for(j=0, p=a+i,q = root; j<60 && *p; j++,p++)
        {
            if(*p == 'a')
            {
                if(!q->st)
                {
                    aux = new nodArbore;
                    aux->inf = 1;
                    q->st = aux;
                }
                q = q->st;
            }
            else
            {
                if(!q->dr)
                {
                    aux = new nodArbore;
                    aux->inf = 1;
                    q->dr = aux;
                }
                q = q-> dr;
            }
        }

    for(;fscanf(fin,"%s",a+1)+1;)
    {
        pow <<= 1;
        mask |= pow;
        sol = 0;
        lg = strlen(a+1);

        for(i=1;i<=lg;i++)
            for(j=0,p=a+i,q = root;j<60&&*p;j++,p++)
            {
                if(*p == 'a')
                {
                    if(!q->st ) break;
                    else q = q->st;
                }
                if(*p == 'b')
                {
                    if(!q->dr ) break;
                    else q = q->dr;
                }

                q->inf |= pow;
                if( q->inf != mask) break;
                if( j+1 > sol)
                {
                    start=i;
                    sol=j+1;
                }
            }
        if( !sol )break;
    }

    fprintf(fout,"%d\n",sol);

    //a[start+sol]=0;
    //fprintf(fout,"%s",a+start);
    return 0;

}

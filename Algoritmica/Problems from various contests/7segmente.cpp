#include<cstdio>
#include<cstring>

char s[30];
int p,w,pc,i,putere,j,ok,ok2;
int segm[10]= {0,2,5,5,4,5,6,3,7,6};

FILE* fin=fopen("7segmente.in", "r");
FILE* fout=fopen("7segmente.out", "w");

int main()
{

    fscanf(fin,"%s %d",s,&p);
    w=strlen(s);
    pc=0;
    for (i=0; i<w; i++)
        pc+=segm[s[i]-'0'];
    fprintf(fout,"%d ",pc);
    putere=p;
    ok=0;
    ok2=1;
    int st;
    for (i=0; i<w; i++)
    {
        if(ok2==0) st=9;
        else st=s[i]-'0';

        for (j=st; j>0; j--)
            if (segm[j]+(w-i-1)*2<=putere)
                break;
        if (j>0)
        {
            ok=1;
            fprintf(fout,"%d",j);
        }

        if (j==0 && ok==1)
            fprintf(fout,"%d",j);

        if (j<s[i]-'0')
            ok2=0;
        putere-=segm[j];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

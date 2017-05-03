#include <cstdio>
#include<string.h>
using namespace std;

FILE* fin=fopen("convert.in","r");
FILE* fout=fopen("convert.out","w");

char c,s;
int main()
{
    while (!feof(fin))
    {
        fscanf(fin,"%c",&s);
        if(s=='<')
            while(s!='>')
                {
                     fscanf(fin,"%c",&s);
                     if(s=='\n') fprintf(fout,"%c",s);
                }
       else
       {
           if(s=='\n')
                     {
                         c=fgetc(fin);
                         if(c!=-1) fprintf(fout,"%c",s);
                        ungetc(c, fin);
                     }
          else fprintf(fout,"%c",s);
       }
    }fprintf(fout,"\n");
    return 0;
}

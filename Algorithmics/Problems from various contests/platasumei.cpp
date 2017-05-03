#include <fstream>

using namespace std;

FILE* fin=fopen("platasumei.in","r");
FILE* fout=fopen("platasumei.out","w");

int main()
{
    int s, x, p=1, i=0,c;
    fscanf(fin,"%d %d", &s,&x);
    while(p<s)
        p*=x;
    p/=x;
    while(s!=0)
    {
        if(p<=s)
        {
            c=s/p;
            s-=(c*p);
            fprintf(fout,"%d %d\n", p, c);
        }
        p/=x;

    }

    return 0;
}

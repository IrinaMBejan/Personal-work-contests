#include <cstdio>
#define LGMAX 60000
using namespace std;
FILE* fin=fopen("paritate.in", "r");
FILE* fout=fopen("paritate.out", "w");

char c,x[LGMAX];
long i, j,error;
int bit1, Cod, bit, q;

int main()
{
  i=-1; error=0; c=0;
  fscanf(fin, "%c", &c);
  while (c!='\n')
    {
      i++; bit1=c-'0';Cod=0; q=0;
      for (j=1; j<=7; j++)
        {
          fscanf(fin, "%c", &c);
          bit=c-'0';
          if (bit==1) q++;
          Cod=Cod*2+bit;
        }
      if ((q+bit1)%2==0)
        x[i]=Cod;
      else
        {
          x[i]=1;
          error=i;
        }
      fscanf(fin, "%c", &c);
    }
  if (error==0)
    {
      fprintf(fout, "DA\n");
      for (j=0; j<=i; j++)
        if (x[j]==10)
          fprintf(fout, "\n");
        else
          fprintf(fout, "%c", x[j]);
    }
  else
    {
      fprintf(fout, "NU\n");
      for (j=0; j<error; j++)
        if (x[j]==1)
          fprintf(fout, "%ld ", j);
      fprintf(fout, "%ld\n", error);
    }
  return 0;
}

#include <cstdio>
using namespace std;

char s[55001];
long imax, jmax, Lmax, n, k;
long f[91];

FILE* fin=fopen("teatru.in","r");
FILE* fout=fopen("teatru.out","w");
void Calculeaza();

int main()
{
    fscanf(fin,"%d%d", &n, &k);
   fscanf(fin,"%c", &s[0]);
   for (long int i = 0; i < n; i++ )
		fscanf(fin,"%c", s + i);
   Calculeaza();


   fprintf(fout,"%d\n", Lmax);
   for (long int i = imax; i <= jmax; i++ )
      fprintf(fout,"%c", s[i]);
   fprintf(fout,"\n");
   return 0;
}

void Calculeaza()
{
   long int i = 0, j = 0, nr = 0;
   f[s[0]]++; nr++;
   do
   {
      while (nr <= k && j < n)
      {
         j++;
         if ( j >= n ) break;
         if (f[s[j]] == 0)
         {
            f[s[j]]++;
            nr++;
         }
         else f[s[j]]++;
      }
      if (j - i  > Lmax)
      {
         Lmax = j - i;
         imax = i; jmax = j - 1;

      }

      while ( nr > k )
      {
         f[s[i]]--;
         if ( f[s[i]] == 0 ) nr--;
         i++;
      }
   } while  (i < n   && j < n);
}



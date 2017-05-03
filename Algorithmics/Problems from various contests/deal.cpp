#include <cstdio>
#define MAXN 100008
using namespace std;

int nr[MAXN];
int n;
int sol[MAXN];

FILE* fin=fopen("deal.in","r");
FILE* fout=fopen("deal.out","w");

int main()
{
 int m = 0, i, a;
 fscanf(fin,"%d", &n);
 m=0;
 for (i = 0; i < n; ++i)
     {
      fscanf(fin,"%d", &a);
      ++nr[a];
      if (m<a) m=a;
     }
int k = -1;
 int jum=(n+1)/2;
 for (i=0; i <= m; ++i)
     if (nr[i] > jum)
         { k = i; break; }

 if (k != -1)
    {
    int l = 0;
    if (k != m)
       {
		for (i = m; i > k; --i)
            {
			 while (nr[i] > 0)
                   {
				   sol[l++] = k; --nr[i];
				   sol[l++] = i; --nr[k];
				   }
			}
		}
    int r = n - 1;
    for (i = 0; i <= k; ++i)
        {
		 while (nr[i] > 0)
            {
	        if (r < l){break;}
	        sol[r--] = k; --nr[k];
	        if (r < l) {break; }
	        sol[r--] = i; --nr[i];
			}
		}
    }
else
   {
	for (k=m,i=1; i<n; )
		if (nr[k]) {sol[i]=k; nr[k]--; i+=2;}
			else k--;
	for (i=0; i<n; )
		if (nr[k]) {sol[i]=k; nr[k]--; i+=2;}
			else k--;
   }

long long int rez = 0;
for (i = 0; i < n; ++i)
    {
     int j = i;
     while ((j < n) && (sol[j] <= sol[j + 1])) ++j;
     if (j-i+1>1) rez += sol[j];
     i = j;
    }

fprintf(fout,"%lld\n", rez);
return 0;
}


#include <fstream>

using namespace std;
 ifstream fin ("submdisj.in");
ofstream fout("submdisj.out");

int a[201][101], nr=1;

int main()
{

  int n, i, j, d;
  fin>>n;
  for (i=0; i<n; i++)
      for (j=0; j<n; j++)
      {
         a[i][j]=a[i+n][j]=nr;
         nr++;
      }

  for (d=0; d<n; d++)
      {
            for (j=0; j<n-1; j++) fout<<a[j+d][j]<<' ';
                fout<<a[n-1+d][n-1]<<'\n';
       }
  fin.close(); fout.close();
  return 0;
}


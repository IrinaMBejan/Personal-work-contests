#include <fstream>
using namespace std;

ifstream fin("control1.in");
ofstream fout("control1.out");
int a,b,x,cif,s,nr;

int main()
{

    fin>>a>>b>>cif;
    if (cif>b) fout<<"0";
    else
    {
        nr=a-1;
        do
          {
            x=++nr;
            do
              {
                s=0;
                while (x)
                    {
                        s += x % 10;
                        x /= 10;
                    }
                 x=s;
               }
             while (x>=10);
             a++;
            }
         while (x!= cif);
         fout<<(b-nr)/9+1<<'\n';
    }

    return 0;
}

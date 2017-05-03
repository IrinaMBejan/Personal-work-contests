#include <fstream>
#include<string.h>

using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
int nr[201], ep1[201], ep2[201],c[201];

int compare(int a[201], int b[201])
{

}
int main()
{
    int p=0,i,j;
    char s[201];
    fin.get(s,201,'\n');
    nr[0]=strlen(s)-1;
    for(i=0;i<=nr[0];i++)
        nr[i]=s[i]-'0';
  //  for(i=nr[0];i>=0;i--)
    //    fout<<nr[i];

    return 0;
}

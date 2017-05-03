#include <fstream>

using namespace std;

ifstream fin("jump.in");
ofstream fout("jump.out");

int main()
{
    long int an3=1,an2=2,an1=4,x;
    int i=4,n;
    fin>>n;
    if (n==1) fout<<"1";
            else if (n==2) fout<<"2";
                    else if(n==3) fout<<"4";
                            else
                                {
                                    while (i<=n)
                                        {
                                            x=an3+an2+an1;
                                            an3=an2;
                                            an2=an1;
                                            an1=x%666013;
                                            i++;
                                        }
                                     fout<<an1;
                                }
    return 0;
}

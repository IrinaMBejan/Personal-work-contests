#include <fstream>
#include <cstring>
#define Nmax 252
#define Cmax 20003
using namespace std;
ifstream fin("text3.in");
ofstream fout("text3.out");

char s[Nmax+5];
char text[Cmax][25];
int lgt[Cmax];
int LCS[2][Cmax];

int lg;

void Citire();
void LIS();
void RestaurareSol();

int main()
{
    Citire();
    LISOptim();
    RestaurareSol();
    return 0;
}

void Citire()
{
    char* p;
    while(!fin.eof())
    {
        fin.getline(s,Nmax);
        p = strtok(s," ");
        while(p!=NULL)
        {
            strcpy(text[++lg],p);
            lgt[lg] = strlen(text[lg])-1;
            p=strtok(NULL, " ");
        }
    }
    fout<<lg<<'\n';

}

void LIS()
{
    int lp = 0, lc = 1;
    int i,j;
    for(i=lg; i>=1; i--)
       {
            for(j=i-1; j>=1; j--)
            if(text[i][0] == text[j][lgt[j]])
                LCS[lp][j]=1+LCS[lc][j+1];
            else
            {
                if(LCS[lp][j+1]>LCS[lc][j])
                    LCS[lp][j]=LCS[lp][j+1];
                else
                    LCS[lp][j]=LCS[lc][j];
            }
            lp=1-lp;
            lc=1-lc;
       }
    LgMax=LCS[lp][1];
}

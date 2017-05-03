#include <fstream>
#include <cstring>
#define Nmax 105
using namespace std;
ifstream fin("telecomanda.in");
ofstream fout("telecomanda.out");

char X[Nmax],Y[Nmax];
int cm[Nmax][Nmax];
char o[Nmax][Nmax][3];
int n,m;

int main()
{
    fin.getline(X+1,Nmax);
    fin.getline(Y+1,Nmax);
    m=strlen(X+1);
    n=strlen(Y+1);

    int i,j;
    for(i=1;i<=m;i++)
    {
        cm[i][n+1]=1;
        strcpy(o[i][n+1],"#");
    }

    for(i=1;i<=n;i++)
    {
        cm[m+1][i]=2*(n-i+1);
        for(j=i; j<=n; j++)
        {
            o[m+1][j][0]='*';
            o[m+1][j][1]=Y[j];
            o[m+1][j][2]=0;
        }
    }

    char omin[3];
    int minim;
    for(i=m; i>0; i--)
        for(j=n; j>0; j--)
        {
            minim=1+cm[i+1][j]; strcpy(omin,"/");
            if(minim>2+cm[i][j+1])
            {
                minim=2+cm[i][j+1];
                omin[0]='*';
                omin[1]=Y[j];
                omin[2]=0;
            }

            if(X[i]>Y[j])
            {
                if(minim>2+cm[i+1][j+1])
                {
                    minim=2+cm[i+1][j+1];
                    omin[0]='-';
                    omin[1]=X[i]-Y[j]+'0';
                    omin[2]=0;
                }
            }
            else if(X[i]<Y[j])
            {
                     if(minim>2+cm[i+1][j+1])
                     {
                        minim=2+cm[i+1][j+1];
                        omin[0]='+';
                        omin[1]=Y[j]-X[i]+'0';
                        omin[2]=0;
                     }
            }
            else
            {
                    if(minim>1+cm[i+1][j+1])
                    {
                        minim=1+cm[i+1][j+1];
                        strcpy(omin,"=");
                    }
            }

            if(minim>1+cm[m+1][j])
            {
                minim=1+cm[m+1][j];
                strcpy(omin,"#");
            }
            cm[i][j]=minim;
            strcpy(o[i][j], omin);
    }
    fout<<cm[1][1]<<'\n';

    for(i=1,j=1;i<=m+1 && j<=n+1 && !(i==m+1 && j==n+1);)
    {
        fout<<o[i][j];
        if(o[i][j][0]=='+'||o[i][j][0]=='-'||o[i][j][0]=='=')
            {i++;j++;}
        else
        {
            if(o[i][j][0]=='*') j++;
            else
            {
                if(o[i][j][0]=='/') i++;
                else
                    i=m+1;
            }
        }
    }
    fout<<'\n';
    return 0;
}


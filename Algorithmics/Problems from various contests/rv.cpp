#include <fstream>
#include<cstring>
ofstream fout("rv.out");

char s[Nmax];
char rez[Nmax][Nmax][Nmax];
char sir1[Nmax],sir2[Nmax];

int main()
{
    int i,j;

    int n;
    fin.getline(s,Nmax);
    n=strlen(s)-1;
    for(i=0;i<n;i++)
        rez[i][i][0]=s[i];
    int st=0, fi=n, k=0, lg1, lg2;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            if(k%2==0)
                {
                    lg1=strlen(rez[i+1][j]);
                    strcpy(sir1,rez[i+1][j]);
                    sir1[lg1]=s[st];
                    sir1[lg1+1]=0;

                    lg2=strlen(rez[i][j-1]);
                    strcpy(sir2,rez[i][j-1]);
                    sir2[lg2]=s[fi];
                    sir2[lg2+1]=0;
                    if(strcmp(sir1,sir2)>0)
                        strcpy(rez[i][j],sir1), st++;
                    else
                        strcpy(rez[i][j],sir2), fi--;
                }
            else
                {
                     lg1=strlen(rez[i+1][j]);
                    strcpy(sir1,rez[i+1][j]);
                    sir1[lg1]=s[st];
                    sir1[lg1+1]=0;

                    lg2=strlen(rez[i][j-1]);
                    strcpy(sir2,rez[i][j-1]);
                    sir2[lg2]=s[fi];
                    sir2[lg2+1]=0;
                     if(strcmp(sir1,sir2)<0)
                        strcpy(rez[i][j],sir1), st++;
                    else
                        strcpy(rez[i][j],sir2), fi--;
                }
            k++;
        }
    fout<<rez[0][n-1]<<'\n';
    return 0;
}

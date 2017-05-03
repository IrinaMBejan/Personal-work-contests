#include <cstdio>

using namespace std;
FILE* fin=fopen("ceas2.in","r");
FILE* fout=fopen("ceas2.out","w");

int C[5][9];
int y[10];
int main()
{
    int i,j,t,orast, orafi,h,m,ss,s;
    char x;
    for(i=1; i<=4; i++)
    {
        for(j=1; j<=8; j++)
        {
            fscanf(fin,"%c",&x);
            if(x=='o') C[i][j]=1;
            else C[i][j]=0;
        }
        fscanf(fin,"%c",&x);
    }
    fscanf(fin,"%d",&t);
    t=t%8640000;
    for(j=1; j<=8; j++)
    {
        y[j]=0;
        for(i=1; i<=4; i++)
            y[j]=y[j]*2+C[i][j];
    }
    h=y[1]*10+y[2];
    m=y[3]*10+y[4];
    s=y[5]*10+y[6];
    ss=y[7]*10+y[8];
    orast=h*360000+m*6000+s*100+ss;
    orafi=orast+t;
    orafi=orafi%8640000;
    h=orafi/360000;
    orafi=orafi%360000;
    m = orafi/6000;
    orafi=orafi%6000;
    s=orafi/100;
    ss=orafi%100;
    y[8]= ss% 10;
    y[7]= ss/10;
    y[6]= s%10;
    y[5]= s/10;
    y[4]= m%10;
    y[3]= m/10;
    y[2]= h %10;
    y[1]= h/10;
    for(j= 1; j<=8; j++)
        for(i=4; i>=1; i--)
        {
            C[i][j]=y[j]%2;
            y[j]=y[j]/2;
        }
    for(i=1; i<=4; i++)
    {
        for(j=1; j<=8; j++)
            if(i==1&&(j==3||j==1||j==5)) fprintf(fout," ");
                    else if(i==2&&j==1) fprintf(fout," ");
                        else if(C[i][j]==0) fprintf(fout,"x");
                            else fprintf(fout,"o");
        fprintf(fout,"\n");
    }
        return 0;
}

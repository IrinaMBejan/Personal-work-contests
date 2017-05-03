#include <cstdio>
#include <cstring>
using namespace std;

FILE*fin=fopen("limbaj.in","r");
FILE* fout=fopen("limbaj.out","w");

int v[26];
int nivel[2500];
char sir[20];

int main()
{
    int niv=0;
    //citire
    for(int i=0; i<26; i++)
        fscanf(fin,"%d",&v[i]);

    int flag=1;
    while(fscanf(fin,"%s",&sir)>0)
    {
        if(flag==1 && strlen(sir)==3 && sir[1]=='=')
        {
            v[sir[0]-97]=v[sir[2]-97];
            continue;
        }

        if(strcmp(sir,"if")==0)
        {
            fscanf(fin,"%s",&sir);
            if(sir[0]=='=')
            {
                if(v[sir[1]-97]==v[sir[2]-97])
                    nivel[niv]=1;
            }
            if(sir[0]=='>')
            {
                if(v[sir[1]-97]>v[sir[2]-97])
                    nivel[niv]=1;
            }
            if(sir[0]=='<')
            {
                if(v[sir[1]-97]<v[sir[2]-97])
                    nivel[niv]=1;
            }
            niv++;
            continue;
        }

        if(strcmp(sir,"fi")==0)
            nivel[--niv]=0;

        //sar peste toate liniile din da, daca asta e fals
        if((strcmp(sir,"da")==0) && (nivel[niv-1]==0))
        {
            flag=0;
            char sir1[10];
            int niv1=0;
            while(flag==0)
            {
                fscanf(fin,"%s",&sir1);
                if(!strcmp(sir1,"if")) niv1++;
                if(!strcmp(sir1,"fi")&&(niv1>0)) niv1--;
                if(!strcmp(sir1,"fi")&&(niv1==0)) flag=1;
                if(!strcmp(sir1,"nu")&&(niv1==0)) flag=1;
            }
            continue;
        }
        //sar peste toate liniile din nu, daca asta e fals
        if((!strcmp(sir,"nu")) && (nivel[niv-1]==1))
        {
            flag=0;
            char sir1[10];
            int niv1=0;
            while(flag==0)
            {
                fscanf(fin,"%s",sir1);
                if(!strcmp(sir1,"if")) niv1++;
                if(!strcmp(sir1,"fi")&&(niv1>0)) niv1--;
                if(!strcmp(sir1,"fi")&&(niv1==0)) flag=1;
            }
            continue;
        }
    }

    for(int j=0; j<26; j++)
        fprintf(fout,"%d ",v[j]);
    fprintf(fout,"\n");
    return 0;
}

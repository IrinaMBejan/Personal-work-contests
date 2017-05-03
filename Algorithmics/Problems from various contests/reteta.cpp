#include <fstream>
#include<cstring>
using namespace std;
ifstream fin("reteta.in");
ofstream fout("reteta.out");
char s[1050];
char pro[25];
struct prod
{
    char sir[25];
    int nr;
} P[105];

int main()
{
    int i = 0;
    int S=0,x;
    int N=0;
    fin.getline(s,1005);
    while(s[i]!=0)
    {
        if(s[i] ==')')
        {
            while(!(s[i]>='0'&&s[i]<='9'))
                i++;
            x=0;
            while(s[i]>='0'&&s[i]<='9')
                x=x*10+s[i++]-'0';
            S=S+x;
        }
        else i++;
    }

    i=0;
    while(s[i]!=0)
    {
        if(s[i]>='a'&& s[i]<='z')
        {
            int k=0;
            do
                pro[k++] = s[i++];
            while(s[i]>='a'&& s[i]<='z');
            pro[k]='\0';
            while(s[i] ==' ') i++;
            x=0;
            while(s[i]>='0'&&s[i]<='9')
                x=x*10+s[i++]-'0';

            int poz = 0;
            while(strcmp(pro,P[poz].sir)>0&& poz <N) poz++;
            if(strcmp(pro,P[poz].sir)==0)
                P[poz].nr+=x;
            else
            {
                for( int j =N; j>poz; j--)
                    strcpy(P[j].sir,P[j-1].sir),P[j].nr=P[j-1].nr;
                strcpy(P[poz].sir,pro),P[poz].nr =x;
                N++;
            }
        }
        else i++;
    }

    fout<<S<<'\n';
    for( i =0; i<N; i++)
        fout<<P[i].sir<<" "<<P[i].nr<<'\n';
    return 0;
}

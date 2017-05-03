#include <fstream>
#include<cstring>
#define Lgmax 205
using namespace std;
ifstream fin("formule.in");
ofstream fout("formule.out");
int Nr;
char s[210];
bool formula(int& poz);
int get_bit(int decimal, int N);
int detnr();
int ech[3][3],imp[3][3];
int w[30], frecv[30];

int main()
{
    int N,i;
    fin>>N;
    fin.get();
    ech[0][0]=ech[1][1]=imp[0][0]=imp[0][1]=imp[1][1]=1;
    int poz;
    for(i=1;i<=N;i++)
    {
        fin.getline(s,Lgmax);
        int t=0;
        int nrv=1<<detnr();
        for (Nr=0; Nr<nrv;Nr++)
        {
            poz=0;
            if(formula(poz)== 1) t++;
        }
        if(t==nrv)
            fout<<"T";
        else if(t==0)
            fout<<"C";
        else fout<<"N";
        fout<<'\n';
    }
    return 0;
}

bool formula(int& poz)
{
    if(s[poz]>='a'&&s[poz]<='z')
            {
                ++poz;
                return get_bit(Nr,w[s[poz-1]-'a']);
            }
    else
        if(s[poz]=='(')
        {
            int p=0;
            ++poz;
            if(s[poz]=='!')
                    p= !formula(++poz);
            else
            {
                int p1=formula(poz);
                if(s[poz]=='&')
                {
                    int z=formula(++poz);
                    p= p1&&z;
                }
                if(s[poz]=='|')
                {
                    int z=formula(++poz);
                    p= p1||z;
                }
                if(s[poz]=='-')
                {
                    int z=formula(poz+=2);
                    p= imp[p1][z];
                }
                if(s[poz]=='<')
                {
                    int z=formula(poz+=3);
                    p= ech[p1][z];
                }
            }
            ++poz;
            return p;
        }
}

int get_bit(int decimal, int N)
{

int constant = 1 << (N-1);

 if( decimal & constant )
{
  return 1;
 }

 return 0;
}

int detnr()
{

    for(int i=0;i<=27;i++)
        w[i]=frecv[i]=0;
    int l = strlen(s);
    int contor=0;
    for (int i=0; i<l; i++)
        if(s[i]>='a'&&s[i]<='z')
            if(frecv[s[i]-'a']== 0)
            {
                frecv[s[i]-'a'] =1;
                w[s[i]-'a']=++contor;
            }
    return contor;
}

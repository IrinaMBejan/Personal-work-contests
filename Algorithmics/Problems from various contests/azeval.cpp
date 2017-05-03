#include <fstream>
#include <cstring>
#define Lgmax 255
using namespace std;
ifstream fin("azeval.in");
ofstream fout("azeval.out");
int Nr;
char s[Lgmax];
int p;
char u[30]="abcdefghijklmnopqrstuvwxyz";
int expresie(int& poz);
int termen(int& poz);
int factor(int& poz);
int tput(int& poz);


int main()
{
    int i;
    for(i = 1; i <= 3; i++)
    {
        fin.getline(s,Lgmax);
        int poz = 0;
        int t=expresie(poz);
        fout<<u[t%26]<<'\n';
    }
}

int expresie(int& poz)
{
    int R;
    R=termen(poz);
    while (s[poz] == '+' || s[poz]=='-')
    {
        if(s[poz]=='+')
            R=(R+termen(++poz))%26;
        else if(s[poz]=='-')
        {
            int r=termen(++poz);
            if( R>=r) R-=r;
            else R=R-r+26;
        }
    }
    return R;
}


int termen(int& poz)
{
    int R;
    R=tput(poz);

    while(s[poz]=='*' || s[poz]=='/'|| s[poz]=='%')
    {
        if(s[poz]=='*')
            R=(R*tput(++poz))%26;
        else if( s[poz]=='/')
            {
                int p=tput(++poz);
                if(p>0) R=R/p;
                else R=25;
            }
        else  if (s[poz] == '%' )
            {
                    p=tput(++poz);
                    if(p>0) R%=p;
                    else R=0;
            }
    }
    return R;
}

int tput(int& poz)
{
    int R,i,r;
    R=factor(poz);
    r=R;
   while(s[poz]=='^')
   {
       int k=factor(++poz);
       if(r!=0)
       {
           while (k)
            {
                if (k % 2) R = (R * r) % 26;
                r = (r * r) % 26;
                k /= 2;
            }
       }
   }
   return R;
}

int factor(int& poz)
{
    //variabila
    if(s[poz] >='a' && s[poz] <='z')
         return s[poz++]-'a';
    //expresie
    if(s[poz] =='(')
       {
           int x;
           x=expresie(++poz);
           ++poz;
           return x;
       }
       return -1;

}

#include <fstream>
#include <cstring>
#define Lgmax 255
using namespace std;
ifstream fin("azeval.in");
ofstream fout("azeval.out");
int Nr;
char s[Lgmax];
int p;

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
        fout<<expresie(poz)<<'\n';
    }
}

int expresie(int& poz)
{
    int R;
    R=termen(poz);
    if (s[poz] == '+')
        return (R+expresie(++poz))%26;

    if (s[poz] == '-')
    {
        int r = expresie(++poz);
        if( r<=R)
            return R-r;
        else
            return R-r+26;
    }

    return R;
}


int termen(int& poz)
{
    int R;
    R=tput(poz);
    if (s[poz] == '*' )
         return R*termen(++poz)%26;
     else if( s[poz]=='/')
        {
            int p=termen(++poz);
            if(p!=0)
                return R/p;
            else
                return 25;
        }
        else  if (s[poz] == '%' )
        {
            p=tput(++poz);
            if(p!=0)
                return R%p;
            else
                return 0;
        }
    return R;
}

int tput(int& poz)
{
    int R;
    R=factor(poz);
    if(R== 0)
        return 0;
   if(s[poz]=='^')
   {
       int k=tput(++poz);
       if(k!=R)
        for(int q=1;q<=k;q++)
            R=(R%26)*k;
       return R;
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

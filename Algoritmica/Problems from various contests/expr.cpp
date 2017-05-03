#include <fstream>
#include<cstring>
#define Nmax 1005
using namespace std;

ifstream fin("expr.in");
ofstream fout("expr.out");
char s[Nmax];
int val[30];
void Citire();
int expresie(int& poz);
int termen(int& poz);
int factor(int& poz);

int main()
{
    Citire();
    int poz = 0;
    int number = expresie(poz);
    fout<<number<<'\n';

    return 0;
}

void Citire()
{
    fin.get(s,1005);
    fin.get();
    int n,nr; char c; fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>c>>nr;
        val[c-'a']=nr;
    }
}

int expresie(int& poz)
{
    int R;
    R=termen(poz);
    if (s[poz] == '+')
        return R+expresie(++poz);
     return R;
   /*
    int R;
    R=termen(poz);
    while (s[poz] == '+')
               R+=termen(++poz);
     return R;   */

}


int termen(int& poz)
{
    int R;
    R=factor(poz);
    if (s[poz] == '*')
         return R*termen(++poz);
    return R;
}

int factor(int& poz)
{   //constanta cifra
    if(s[poz] >='0' && s[poz] <='9')
        return s[poz++]-'0';

    //variabila
    if(s[poz] >='a' && s[poz] <='z')
        return val[s[poz++]-'a'];
    //expresie
    if(s[poz] =='(')
       {
           int x;
           x=expresie(++poz);
           ++poz;
           return x;
       }
}
/*
int consta(int& poz)
{
    int x=0;
    while(s[poz] >='0' && s[poz]<='9')
        x=x*10+s[poz++]-'0';
    return x;
}
*/

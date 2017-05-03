#include <fstream>
#include<cstring>
#define Nmax 1005
using namespace std;

ifstream fin("expr.in");
ofstream fout("expr.out");
char s[Nmax];
int val[30];

void Citire();
bool expresie(int& poz);
bool termen(int& poz);
bool factor(int& poz);
int Lg;

int main()
{
    Citire();
    Lg=strlen(s);
    int poz = 0;
    if(expresie(poz))
        {
            if(poz != Lg)
                fout<<"Operatie lipsa intre expresii"<<'\n';
            else
                fout<<"DA"<<'\n';
        }
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

bool expresie(int& poz)
{
    bool ok;
    ok=termen(poz);
    if (s[poz] == '+'&&ok)
        return expresie(++poz);
     return ok;
}


bool termen(int& poz)
{
   bool ok;
    ok=factor(poz);
    if (s[poz] == '*'&&ok)
         return termen(++poz);
    return ok;
}

bool factor(int& poz)
{   //constanta cifra
    if(s[poz] >='0' && s[poz] <='9')
    {
        if(s[poz+1] != '+'&&s[poz+1]!='*'&&s[poz+1]!=')'&&poz+1<Lg)
           {
                fout<<"Constanta reprezentata gresit";
                return 0;
           }
        else
           {
               ++poz;
                return 1;
           }
    }

    //variabila
    if(s[poz] >='a' && s[poz] <='z')
    {
        if(s[poz+1] != '+'&&s[poz+1]!='*'&&s[poz+1]!=')'&&poz+1<Lg)
           {
               fout<<"Variabila reprezentata gresit";
                return 0;
           }
        else
           {
               ++poz;
               return 1;
           }
    }

    //expresie
    if(s[poz] =='(')
       {
           bool ok = expresie(++poz);
           if(s[poz]!=')'&&ok)
            {
                fout<<"Parantezare gresita"<<'\n';
                return 0;
            }
           ++poz;
           return ok;
       }

    if(s[poz] == ')')
            fout<<"Parantezare gresita"<<'\n';

    else if((s[poz] == '*' || s[poz]  == '+'))
            fout<<"Operatie imposibila"<<'\n';

    else if(poz == Lg)
            fout<<"Relatie neterminata"<<'\n';

    else fout<<"Caracterul de pe pozitia "<<poz<<" este neadecvat"<<'\n';
    return 0;
}

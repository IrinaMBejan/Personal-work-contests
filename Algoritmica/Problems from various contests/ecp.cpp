#include <fstream>
#define Lgmax 1005
using namespace std;
ifstream fin("ecp.in");
ofstream fout("ecp.out");

int e2,e3,e5;
char s[Lgmax];


void Expresie(int &poz);
int main()
{
    fin>>s;
    int poz=0;
    Expresie(poz);
    fout<<e2<<" "<<e3<<" "<<e5<<'\n';
    return 0;
}

void Expresie(int &poz)
{
    if(s[poz]=='(')
    {
        if(s[poz+1]==')')
            {
                e2++;
                poz+=2;
            }
        else
        {
            Expresie(++poz);
            poz++;
            e2+=2;
        }
    }

    if(s[poz]=='[')
    {
        if(s[poz+1]==']')
            {
                e3++;
                poz+=2;
            }
        else
        {
            Expresie(++poz);
            poz++;
            e3+=3;
        }
    }

    if(s[poz]=='{')
    {
        if(s[poz+1]=='}')
            {
                e5++;
                poz+=2;
            }
        else
        {
            Expresie(++poz);
            poz++;
            e5+=5;
        }
    }

    if(s[poz]=='(' || s[poz]=='[' || s[poz]=='{')
        Expresie(poz);
}

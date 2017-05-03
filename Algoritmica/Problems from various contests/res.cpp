#include <iostream>
#define LGMAX 21
using namespace std;

int p[LGMAX];
int b,n;
void afiseaza(int lg);
void gen(int k);

int main()
{
    int i;
    cin>>n>>b;
    //fixam fiecare vak posibila pt p[1] si generam toate conf. posibile care incep cu resp. valoare;
    for(i=1; i<=b-1; i++)
    {
        p[1]=i;
        gen(2);
    }
    return 0;
}

void gen(int k)
{
    int i;
    //base case
    if(k-1==(n+1)/2)
        afiseaza((n+1)/2);
    else//generare pentru fiecare val posibila a lui p[k], fiecare configuratie;
        for(i=0; i<=b-1; i++)
        {
            p[k]=i;
            gen(k+1);
        }
}

void afiseaza(int lg)
{
    int i;
    //prima parte din palindrom
    for(i=1; i<=lg; i++)
        cout<<p[i];

    //a doua parte in fnct de paritatea lui n
    if(n%2==0)
        for(i=lg; i>=1; i--)
            cout<<p[i];
    else
        for(i=lg-1; i>=1; i--)
            cout<<p[i];

    cout<<'\n';
}

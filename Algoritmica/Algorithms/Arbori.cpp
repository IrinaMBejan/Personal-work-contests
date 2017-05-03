#include <fstream>
#include<iostream>
using namespace std;
ifstream fin("fisier.in");
ofstream fout("fisier.out");
struct NodArbore
{
    int inf;
    NodArbore* st, *dr;
};

typedef struct NodArbore* Arbore;
Arbore R;
Arbore Reconstituie(int st, int dr, int& rad);
Arbore CreeazaInteractiv()
{
    char s;
    Arbore nod = new NodArbore;
    cout<<"Introdu informatia nodului curent";
    cin>>nod->inf;
    cout<<"Are fiu la stanga?";
    cin>>s;
    if(s == 'N')
        nod->st = NULL;
    else
        nod->st = CreeazaInteractiv();

    cout<<"Are fiu la dreapta?";
    cin>>s;

    if(s == 'N')
        nod->dr = NULL;
    else
        nod->dr = CreeazaInteractiv();
    return nod;
}

void Preordine(Arbore r)
{
    if(r!=NULL)
    {
    fout<<r->inf<<" ";
    Preordine(r->st);
    Preordine(r->dr);
    }
}

void Inordine(Arbore r)
{
    if(r!=NULL)
    {
    Inordine(r->st);
    fout<<r->inf<<" ";
    Inordine(r->dr);
    }
}

void Postordine(Arbore r)
{
    if(r!=NULL)
    {
    Postordine(r->st);
    Postordine(r->dr);
    fout<<r->inf<<" ";
    }
}
const int NMAX = 200;
int inordine[NMAX], N;
int Inaltime(Arbore r);
int main()
{
    //CREERE INTERACTIVA
    /*char s;
    cout << "Este vid?";
    cin>>s;
    if( s == 'N')
        R = CreeazaInteractiv();
    */

    //CREERE DIN INORDINE + PREORDINE (1-N)
    fin>>N;
    int i;
    for (i=1;i<=N;i++)
        fin>>inordine[i];
    int rad = 1;
    R = Reconstituie(1, N, rad);

    fout<<Inaltime(R)<<'\n';
    fout<<NotArboreStrict()
    Preordine(R);
    fout<<'\n';
    Inordine(R);
    fout<<'\n';
    Postordine(R);
    fout<<'\n';
    return 0;
}


Arbore Reconstituie(int st, int dr, int& rad)
{
    Arbore r = new NodArbore;
    r->inf = rad;
    int poz;
    for(poz = st; inordine[poz] != rad; poz++);
    if(poz == st)
        r->st = NULL;
    else
        r->st = Reconstituie(st, poz-1, ++rad);

    if(poz == dr)
        r->dr = NULL;
    else
        r->dr = Reconstituie(poz+1, dr, ++rad);

    return r;
}

int Inaltime(Arbore r)
{
    if(r == NULL)
        return -1;

    int hs = Inaltime(r->st);
    int hd = Inaltime(r->dr);

    int maxim;
    if(hs>hd) maxim = hs;
    else maxim = hd;

    return 1+maxim;
}

bool NotArboreStrict(Arbore r)
{
    if(r == NULL)
        return 1;

    return (ArboreStrict(r->dr)^ArboreStrict(r->st));
}

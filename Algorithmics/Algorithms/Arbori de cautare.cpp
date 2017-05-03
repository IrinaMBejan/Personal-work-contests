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
void Inserare(Arbore &a, int x);
void InserareIterativ(Arbore &a, int x);
void Stergere(Arbore &a, int x);
int main()
{
    fin>>N;
    int i;
    for (i=1;i<=N;i++)
        fin>>inordine[i];
    int rad = 1;
    R = Reconstituie(1, N, rad);

    int M,p;
    fin>>M;
    for(i=1;i<=M;i++)
    {
        fin>>p;
        Stergere(R, p);
    }
    Preordine(R);
    fout<<'\n';
    Inordine(R);
    fout<<'\n';
    Postordine(R);
    fout<<'\n';
    return 0;
}

void Inserare(Arbore &a, int x)
{
    if(a == NULL)
    {
        a = new NodArbore;
        a->inf = x;
        a->st=a->dr = NULL;
        return;
    }

    if(a->inf == x) return;
    if(a->inf < x)
        Inserare(a->dr, x);
    else
        Inserare(a->st, x);
}


void Stergere(Arbore&a, int x)
{
    if(a == NULL)
        return;
    Arbore p = a, tataP = NULL;

    while (p && p->inf!=x)
    if (x<p->inf) {tataP=p; p=p->st;}
       else {tataP=p; p=p->dr;}
    if (!p) return;

    if(p->st != NULL && p->dr != NULL)
    {

        Arbore mini, tmin;
        mini = p->dr;
        tmin = p;
        while(mini->st!=NULL)
        {
            tmin = mini;
            mini = mini->st;
        }

        p->inf = mini->inf;

        p = mini;
        tataP = tmin;
    }

    Arbore F;
    if (p->st) F=p->st;
       else F=p->dr;

    if(tataP != NULL)
    {if (p==tataP->st) tataP->st=F;
         else tataP->dr=F;
    }
    else
        a = F;
    delete p;
}
void InserareIterativ(Arbore& a, int x)
{
    Arbore q = new NodArbore, p = a;
    q->inf = x;
    q->st = q->dr = NULL;
    if(a == NULL)
        {
            a = q;
            return;
        }

    while(1)
    {
        if(p->inf == x)
        {
            delete q;
            return;
        }

        if(p->inf < x)
            if(p->st == NULL)
            {
                p->st = q; return;
            }
            else
                p = p->st;
        else
            if(p->dr == NULL)
            {
                p->dr = q; return;
            }
            else
                p = p->dr;
    }
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

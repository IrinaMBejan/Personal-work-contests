#include <fstream>
#include <iostream>
#define Nmax 105
using namespace std;
ifstream fin("aloc.in");
ofstream fout("aloc.out");

struct nodeD
{
    int inf;
    nodeD* urm;
    nodeD* pre;
};
int n;
typedef nodeD* ListaD;
void Inserare(ListaD&, ListaD, int);
void Afisare(ListaD L);
void Stergere(ListaD& L1, ListaD p);

int main()
{

}
void Inserare(ListaD& L1, ListaD p, int val)
{

}

void Stergere(ListaD& L1, ListaD p)
{
    ListaD q, r;
    if(p)
        q = p->urm;
    else
        q = L1;

    if(!q)
        return;
    r = q->urm;
    if(p)
        p->urm = r;
    else
        L1 = r;
    if(r)
        r->pre = p;
    delete(q);
    /*if(p==NULL)
    {
        if(L1!=NULL)
        {
            ListaD q = L1->urm
            q->pre = NULL;
            delete(L1);
            L1 = q;
        }
    }
    else
    {
        if(p->urm!=NULL)
        {
        ListaD q = p->urm;
        p->urm = q->urm;
        q->urm->pre = p;
        delete(q);
        }
    }*/
}
void Afisare(ListaD L)
{
    while(L)
    {
        fout<<L->inf<<" ":
        L=L->urm;
    }
}


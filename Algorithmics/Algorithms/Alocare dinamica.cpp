#include <fstream>
#include <iostream>
#define Nmax 105
using namespace std;
ifstream fin("aloc.in");
ofstream fout("aloc.out");

struct node
{
    int inf;
    node* urm;
};
int n;
typedef node* Lista;
void Inserare(Lista&, Lista, int);
void CreareStiva();
void CreareCoada();
void CreareOrd(Lista& Ord);
void Afisare(Lista L);
void Interclasare1(Lista L1, Lista L2, Lista& L3);
void Interclasare2(Lista& L1, Lista L2);
void Interclasare3(Lista L1, Lista L2, Lista& L3);
void Inversare(Lista& L1);
void Stergere(Lista& L1, Lista p);
Lista InversRec(Lista L1);
Lista Stiva;
Lista Coada, ultim;
Lista noua;
Lista L1, L2, L3;
int Mijloc(Lista L);

int main()
{
    CreareOrd(L1);
    Afisare(L1);

    Stergere(L1,L1);
    Afisare(L1);
    return 0;
}

void Inversare(Lista& L1)
{
    if(L1 == NULL || L1->urm == NULL)
        return;
    Lista p1=NULL, p2 = L1, p3=L1->urm;
    while(p2)
    {
        p2->urm = p1;
        p1 = p2;
        p2 = p3;
        if(p3) p3 = p3->urm;
    }
    L1 = p1;
}

Lista InversRec(Lista L1)
{
    if(L1 == NULL || L1->urm == NULL)
        return L1;
    Lista p0= L1, p1 = L1->urm ;
    Lista p2 = InversRec(L1->urm);
    p1->urm = p0;
    p0->urm = NULL;
    return p2;
}

void Interclasare3(Lista L1, Lista L2, Lista& L3)
{
    if(L1==NULL)
    { L3 = L2; return; }
    if(L2==NULL)
    { L3=L1; return; }

    Lista p = L1, q = L2;

    if(L1-> inf < L2->inf)
        L3 = L1, p = L1, q = L2;
    else
        L3 = L2, p = L2, q = L1;

// p indica un element mai mic decat cel din q
    Lista aux;
    while(p && q)
    {
        while(p->urm && (p->urm->inf<= q->inf))
            p = p->urm;
        aux = p->urm;
        p->urm = q;
        p=q;
        q=aux;
    }
}


void Interclasare1(Lista L1, Lista L2, Lista& L3)
{
    Lista p = L1;
    Lista q = L2;

    if(p->inf < q->inf)
    {
        Inserare(L3,NULL, p->inf);
        p=p->urm;
        ultim = L3;
    }
    else
    {
        Inserare(L3,NULL, q->inf);
        q=q->urm;
        ultim = L3;
    }

    while(p&&q)
    {
        if((p->inf)<(q->inf))
        {
            Inserare(L3,ultim,p->inf);
            p=p->urm;
            ultim = ultim->urm;

        }
        else
        {
            Inserare(L3,ultim,q->inf);
            q=q->urm;
            ultim = ultim->urm;
        }
    }
    while(p)
    {
        Inserare(L3,ultim,p->inf);
        p= p->urm;
        ultim = ultim->urm;
    }
    while(q)
    {
        Inserare(L3,ultim,q->inf);
        q= q->urm;
        ultim = ultim->urm;
    }
}

void Interclasare2(Lista&L1, Lista L2)
{
    Lista p = L1;
    Lista q = L2;

    //inversare
    while(q)
    {
        Inserare(noua, NULL, q->inf);
        q=q->urm;
    }
    q=noua;


    while(p->urm&&q->urm)
    {
        if(p->urm->inf < q->urm->inf)
        {
            p=p->urm;
        }
        else
        {
            Inserare(L1, p, q->inf);
            q=q->urm;
        }
    }
    while(q)
    {
        Inserare(L1,p,q->inf);
        q= q->urm;
    }
}
void Afisare(Lista L)
{
    Lista p = L;
    while(p)
    {
        fout<<(p->inf)<<" ";
        p = p->urm;
    }
    fout<<'\n';

}
void CreareStiva()
{
    fin>>n;
    int val;
    int i;
    for(i=1; i<=n; i++)
    {
        fin>>val;
        Inserare(Stiva, NULL , val);
    }
}

void CreareOrd(Lista& Ord)
{
    fin>>n;
    int val;
    int i;

    Lista p;
    fin>>val;
    Inserare(Ord, NULL, val);
    for(i=2; i<=n; i++)
    {
        fin>>val;
        if(val <= Ord->inf)
            Inserare(Ord, NULL, val);
        else
        {
            //caut poz
            for (p=Ord; p->urm && p->urm->inf < val; p=p->urm );
            Inserare(Ord, p, val);
        }
    }
}

int Mijloc(Lista L)
{
    Lista pas1, pas2;
    pas1 = L;
    pas2 = L;
    while(pas2)
    {
        pas1= pas1->urm;
        pas2 = pas2->urm;
        if(pas2)
            pas2 = pas2->urm;
    }
    return pas1->inf;
}

void CreareCoada()
{
    fin>>n;
    int val;
    int i;

    fin>>val;
    Inserare(Coada, NULL, val);
    ultim = Coada;

    for(i=2; i<=n; i++)
    {
        fin>>val;
        Inserare(Coada, ultim , val);
        ultim = ultim->urm;
    }
}

void Inserare(Lista &L, Lista p, int x)
{
    //Daca p este NULL, inserarea se va face la inceputul listei
    Lista q = new node;
    q->inf = x;
    if(p==NULL)
    {
        q->urm = L;
        L = q;
    }
    else
    {
        q->urm = p->urm;
        p->urm = q;
    }
}


void Stergere(Lista& L1, Lista p)
{
    if(p == NULL)
    {
        if(L1!= NULL)
        {
            Lista q = L1;
            L1 = L1->urm;
            delete(q);
        }
    }
    else
    {
        if(p->urm !=NULL)
        {
            Lista q = p->urm;
            p->urm = q->urm;
            delete(q);
        }
    }
}

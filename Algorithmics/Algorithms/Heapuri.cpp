#include <cstdio>
#include <iostream>
#define Nmax 200005
using namespace std;
FILE* fin = fopen("heapuri.in","r");
FILE* fout = fopen("heapuri.out","w");

int H[Nmax],N;
void Inserare(int inf);
void Creare_inserare();
void Creare_combinari();
void Combinare(int i);
int ExtragereMinim();
void heapsort();

int main()
{
   /* Creare_inserare();  */
    Creare_combinari();
    int i;
    for(i=1; i<=N; i++)
    {
        cout<<H[i]<<" ";
        //fprintf(fout,"%d ",H[i]);
    }
    //fprintf(fout,"\n%d\n",ExtragereMinim());

    for(i=1; i<=6; i++)
    {
        cout<<ExtragereMinim()<<"     ";

        //fprintf(fout,"%d ",H[i]);
        //cout<<H[i]<<" ";
    }
    /*fscanf(fin,"%d",&N);
    int i;
    for(i=1;i<=N;i++)
    {
        fscanf(fin,"%d %d",&cod,&nr);
        if(cod == 1)
            Inserare(nr);
        if(cod == 2)
            Stergere(nr);
        if(cod == 3)
            fprintf(fout,"%d\n",ExtrageMaxim());
    }*/
    return 0;
}

void Creare_inserare()
{
    int n,i,nr;
    //fscanf(fin,"%d",&n);
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>nr;
       // fscanf(fin,"%d",&nr);
        Inserare(nr);
    }
}

void Creare_combinari()
{
    int i;
    //fscanf(fin,"%d",&N);
    cin>>N;
    for(i=1;i<=N;i++)
        cin>>H[i];
        //fscanf(fin,"%d",&H[i]);
    for(i= N/2; i>0;i--)
        Combinare(i);
}

void Inserare(int inf)
{
    int fiu, tata;
    fiu = ++N;
    tata = fiu/2;
    while(inf < H[tata] && tata>0)
    {
        H[fiu] = H[tata];
        fiu = tata;
        tata = tata/2;
    }
    H[fiu] = inf;
}

void Combinare(int i)
{
    int inf = H[i], tata = i, fiu = 2*i;
    while(fiu<=N) //cat exista fii
    {

        if(fiu+1<=N && H[fiu]>H[fiu+1]) fiu++;
        //fiu e cel mai mic dintre fii
        if(H[fiu]<inf)
        {
            //promovez pe cel mai mic dintre fii
            H[tata] = H[fiu];
            tata = fiu;
            fiu = 2*tata;
        }
        else //am gasit locul
            break;
    }
    H[tata] = inf;
}

int ExtragereMinim()
{
    int x = H[1];
    H[1] = H[N--];
    Combinare(1);
    return x;
}

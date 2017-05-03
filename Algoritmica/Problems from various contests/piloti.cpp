#include <fstream.h>
#define InFile "piloti.in"
#define OutFile "piloti.out"
#define NMax 10001
int H[NMax], lg=0;

int maxheap_top()
{return H[1];}

void maxheap_push(int x)
{ int tata, fiu;
  lg++;
  fiu=lg; tata=lg/2;
  while (tata>0)
        if (x>H[tata])
           {H[fiu]=H[tata];
            fiu=tata;
            tata=tata/2;}
            else  break;
H[fiu]=x;
}

void maxheap_pop()
{
int tata, fiu, x;
x=H[lg--];;
tata=1; fiu=2;
while (fiu<=lg)
      {if (fiu<lg && H[fiu]<H[fiu+1]) fiu++;
       if (x<H[fiu])
          {H[tata]=H[fiu]; tata=fiu; fiu=2*fiu;}
          else
          break;
       }
H[tata]=x;
}

int main(void)
{int n, rez = 0, capitan, asistent;
 ofstream fout(OutFile);
 ifstream fin(InFile);
 for (fin>>n; n; --n )
     {
     fin >> capitan >> asistent;
     rez += capitan;
     maxheap_push (capitan-asistent);
     if ( n%2==0 )
        {rez -= maxheap_top(); maxheap_pop();}
     }
  fout << rez << endl;
  fout.close();
  return 0;
}
/*
Metoda de programare folosita este Greedy.

Primul pilot trebuie sa fie asistent.
Dintre pilotii 2 si 3 unul trebuie sa fie asistent.
Dintre pilotii 4, 5, si cel care a ramas dintre 2 si 3 unul trebuie sa fie asistent.
Deci la fiecare doi piloti cititi trebuie sa aleg unul care sa fie asistent.
(alegerea se face dintre toti cei cititi in prealabil si care nu au fost deja stabiliti ca asistenti);
Criteriul de alegere: diferenta dintre salariul sau de capitan si salariul sau de asistent sa fie maxima.

Voi utiliza variabila rez in care retinem suma totala cheltuita pentru salariile pilotilor.

Cand citesc un pilot voi considera ca el este capitan si voi adauga salariul lui de capitan la rez, iar
diferenta dintre salariul sau de capitan si salariul sau de asistent o voi insera intr-un maxheap H.

Dar dupa fiecare doua citiri trebuie sa aleg un asistent. Voi extrage maximul din maxheap-ul H.
Din rez voi scadea maximul (ceea ce inseamna ca pilotul corespunzator devine asistent).

*/

#include <fstream>

using namespace std;
int viz[2][10003],a[2][10003],b[2][10003];
int main()
{
    int n,i,j,p,nrmin,invers,l,poz,ant,aux,urmviz;
    ifstream fin("biperm.in");
    ofstream fout("biperm.out");
    fin>>n;
    for (i=0; i<2; ++i)
        for (j=1; j<=n; ++j)
        {
            fin>>a[i][j];
            if (viz[0][a[i][j]]==0)
                viz[0][a[i][j]]=j;
            else
                viz[1][a[i][j]]=j;
        }
    p=1;
    nrmin=0;
    for (i=1; i<=n; ++i)
        if (b[0][i]==0)
        {
            l=1;
            invers=0;
            poz=i;    // reconstruim ciclurile: l lungimea ciclului
            // invers= cate arce sunt in ciclu cu sensul invers
            b[0][poz]=a[0][poz];    // poz = pozitia curenta in ciclu
            b[1][poz]=a[1][poz];    // ant = pozitita anterioara in ciclu
            ant=poz;                // in b se construieste permutarea dubla ceruta
            urmviz=b[1][poz];        // urmatorul nod spre vizitare in lant
            if (viz[0][urmviz]==poz)   //
                poz=viz[1][urmviz];
            else
                poz=viz[0][urmviz]; // lant continua este muchia a[0][poz] si a[1][poz]
            while (!b[0][poz])
            {
                if (a[0][poz]==b[1][ant])
                {
                    b[0][poz]=a[0][poz];
                    b[1][poz]=a[1][poz];
                    l++;
                    ant=poz;
                    urmviz=b[1][poz];
                    if (viz[0][urmviz]==poz)
                        poz=viz[1][urmviz];
                    else
                        poz=viz[0][urmviz];
                }
                else
                {
                    b[0][poz]=a[1][poz];
                    b[1][poz]=a[0][poz];
                    l++;
                    invers++;          // am gasit un nou arc invers
                    ant=poz;               //
                    urmviz=b[1][poz];
                    if (viz[0][urmviz]==poz)
                        poz=viz[1][urmviz];
                    else
                        poz=viz[0][urmviz];
                }

            }
            if (l>1)
                p*=2;
            if (invers>l-invers)
                nrmin+=l-invers;
            else
                nrmin+=invers;
        }
    fout<<p<<" "<<nrmin<<"\n";
    for(i=0; i<2; ++i)
    {
        for(j=1; j<n; ++j)
            fout<<b[i][j]<<" ";
        fout<<b[i][n]<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}

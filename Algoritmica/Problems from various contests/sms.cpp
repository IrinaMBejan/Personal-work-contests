#include <fstream>
#include<cstring>

using namespace std;
ifstream fin("sms.in");
ofstream fout("sms.out");

char nr[27]="22233344455566677778889999";
struct cuvant
{
    char c[105];
    char met[105];
} Dic[105];
char p[105];

int main()
{
    int N,M,i,j;

    fin>>M;
    fin.get();
    for(i=1; i<=M; i++)
    {
        fin.getline(Dic[i].c,100);
        for( j = 0; Dic[i].c[j]!='\0'; j++)
            Dic[i].met[j] = nr[Dic[i].c[j]-'A'];
    }

    fin>>N;
    fin.get();
    for(i=0; i<N; i++)
        fin>>p[i];

    char *q;
    q=strtok(p,"1");
    while(q!=NULL)
    {
        i=1;
        while( strcmp(q,Dic[i].met) != 0&& i<=M) i++;
        if( strcmp(q, Dic[i].met) == 0 )
            fout<<Dic[i].c;
        else
            for (i=0; q[i]!='\0'; i++)
                fout<<'*';
        fout<<" ";
        q=strtok(NULL, "1");
    }
    fout<<'\n';
    return 0;
}

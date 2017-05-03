#include <fstream>
#include<cstring>
#define LgMax 30005

using namespace std;
ifstream fin("replace.in");
ofstream fout("replace.out");
char s1[LgMax], aux[LgMax];
struct cuv
{
    char q[100];
    char cuv[100];
}DIC[15];

int main()
{
    int N;
    fin>>N;
    fin.get();
    for( int i= 0; i < N; i++)
    {
            fin.getline(DIC[i].q,255);
            fin.getline(DIC[i].cuv,255);
    }
    fin.getline(s1,300);
    char *p;
    for( int i = 0; i  <N; i++ )
    {
        int lg = strlen(DIC[i].q);
        while(strstr(s1,DIC[i].q)!=NULL)
        {
            p = strstr(s1,DIC[i].q);
            while( p != NULL)
            {
                *p=0;
                strcpy(aux, p+lg);
                strcat(s1,DIC[i].cuv);
                strcat(s1, aux);
                p = strstr( p ,DIC[i].q);
            }
        }
    }
    fout<<s1<<'\n';
    return 0;
}

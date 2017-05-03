#include <fstream>
#include<cstring>
using namespace std;
ifstream fin("adun.in");
ofstream fout("adun.out");

char q[255], s[13005];
char *p;
int main()
{
    while(!fin.eof())
    {
        fin.getline(q,251);
        strcat(s,q);
    }
    p = strtok(s, ";");
    while(p!=NULL)
    {
        int lg = strlen(p);
        long long int t1 = -1, t2 = -1, rez = -1,pl,pe;
        for ( int i = 0; i < lg; i++)
            {
                if( p[i] == '+') pl = i;
                if( p[i] == '=') pe = i;
            }

        for (int i = 0; i<pl; i++)
            if(p[i] >='0' && p[i]<='9')
            {
                if(  t1 == -1)
                    t1= 0;
                t1= t1*10+p[i]-'0';
            }

        for (int i = pl+1; i<pe; i++)
            if(p[i] >='0' && p[i]<='9')
            {
                if( t2 == -1)
                    t2= 0;
                t2= t2*10+p[i]-'0';
            }

         for (int i = pe+1; i<lg; i++)
            if(p[i] >='0' && p[i]<='9')
            {
                if( rez == -1)
                    rez= 0;
                rez= rez*10+p[i]-'0';
            }

        if( t1 == -1)
            t1 = rez - t2;
        if( t2 == -1)
            t2 = rez - t1;
        if( rez == -1)
            rez = t1+t2;
        fout<<t1<<'+'<<t2<<'='<<rez<<';';
        fout<<'\n';
        p=strtok(NULL,";");
    }
    return 0;
}

#include <fstream>
#include<cstring>
using namespace std;
ifstream fin("zuma.in");
ofstream fout("zuma.out");
char s[250],*p;
int poz;

int main()
{
    fin>>poz;
    fin.get(
    fin.getline(s,200);
    poz--;
    if(s[poz-1] == s[poz]&& s[poz] == s[poz+1])
    {
        int st = poz-1, fi = poz+1;
        while( s[st] == s[poz]&& st >=0 )
            st -- ;
        while( s[fi] == s[poz] )
            fi++;
        while(fi-st -1 >=3)
        {
            p = s;
            *(p+st+1) = 0;
            if(*(p+fi) == *(p+st))
            {
                strcat(s, p + fi);
                strcpy(s,p);
                poz = st, fi = st;
                while( s[st] == s[poz]&& st >=0 )
                    st -- ;
                while( s[fi] == s[poz] )
                    fi++;
            }
            else
            {
                strcat(s, p + fi);
                strcpy(s,p);
                fi = st;
            }
        }
    }
    fout<<s<<'\n';
    return 0;
}

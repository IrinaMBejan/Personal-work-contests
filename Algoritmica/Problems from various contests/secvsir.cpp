#include <fstream>
#include<cstring>
#define Nmax 505
using namespace std;
ifstream fin("secvsir.in");
ofstream fout("secvsir.out");

bool o[Nmax];
int n;
char *p,s[Nmax*3];

int main()
{
    fin>>n;
    const int m=n;
    if(n==1)
        fout<<'1'<<'\n';
    if(n==2)
        fout<<'2'<<'\n';
    else
    {
        o[1]=o[2]=o[12]=1;
        strcpy(s,"12");
        fout<<"12";
        int k=2;
        for(int i=3; i<=m; i++)
            if(o[i]==0)
            {
                int j=i;
                if(i<10)
                {
                    o[i]=1;
                    o[(s[k-1]-'0')*10+i]=1;
                    o[(s[k-2]-'0')*100+(s[k-1]-'0')*10+i]=1;
                    s[k++]=i+'0';
                    fout<<s[k-1];
                }
                else if(i<100)
                {
                    //abcd
                    o[i]=1;
                    o[(s[k-1]-'0')*10+i/10]=1;
                    o[(s[k-2]-'0')*100+(s[k-1]-'0')*10+i/10]=1;
                    o[(s[k-1]-'0')*100+i]=1;
                    s[k++]=i/10+'0';
                    s[k++]=i%10+'0';
                    fout<<s[k-2]<<s[k-1];
                }
                else
                {
                    //abcde
                    o[i]=1;
                    o[(s[k-2]-'0')*100+(s[k-1]-'0')*10+i/100]=1;
                    o[(s[k-1]-'0')*100+i/10]=1;
                    s[k++]=i/100+'0';
                    s[k++]=i%100/10+'0';
                    s[k++]=i%10+'0';
                    fout<<s[k-3]<<s[k-2]<<s[k-1];
                }
                i=j;
                //abcbd
            }
    }
    return 0;
}

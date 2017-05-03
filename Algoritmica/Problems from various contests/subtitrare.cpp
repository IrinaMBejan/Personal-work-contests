#include <fstream>

using namespace std;
ifstream fin("subtitrare.in");
ofstream fout("subtitrare.out");
void citandtran();
int n;
double in,sf;

char s[30],q[101],c;
int main()
{
    do
    {
        fin>>n;
        citandtran();
        fout<<"{"<<in<<"}"<<"{"<<sf<<"}";
        fin.get();
        c=fin.peek();
        if(c!='\n') {fin.get(q,100); fin.get(); fout<<q;c=fin.peek();}
        while(c!='\n'&&c!=-1)
        {
            fin.get(q,100);
            fout<<"|"<<q;
            fin.get();
            c=fin.peek();
        }
   //     fin>>c;
        fout<<'\n';
    }while(!fin.eof());
    return 0;
}

void citandtran()
{
    int h1,h2,m1,m2,s1,s2,n;
    float f1,f2;
    fin.get();
    fin.get(s,30);
    h1=(s[0]-'0')*10+s[1]-'0';
    m1=(s[3]-'0')*10+s[4]-'0';
    s1=(s[6]-'0')*10+s[7]-'0';
    f1=((double)(s[9]-'0')/10)+((double)(s[10]-'0')/100))+((double)(s[11]-'0')/1000);
    in= (h1*3600+m1*60+s1+(double)f1);
    in= (double)in*25;
   h2=(s[17]-'0')*10+s[18]-'0';
    m2=(s[20]-'0')*10+s[21]-'0';
    s2=(s[23]-'0')*10+s[24]-'0';
    f2=(s[26]-'0')/10+(s[27]-'0')/100+(s[28]-'0')/1000;
    sf=(h2*3600+m2*60+s2+(double)f2);
    sf=(double) sf*25;
}

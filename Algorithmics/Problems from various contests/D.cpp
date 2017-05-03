#include <iostream>

using namespace std;
char s[50];
char a[20],b[20];

int main()
{
    int T;
    cin>>T;
    int i,k,q;
    int n;
    while(T)
    {
        cin>>s;
        k=0,q=0;
        for(i=1;s[i]!='+';i++)
            a[k++]=s[i];
        a[k]=0;
        i++;
        for(; s[i]!=')';i++)
            b[q++]=s[i];
        b[q]=0;
        i+=2;
        n=0;
        while(s[i]!='\0')
        {
            n=n*10+(s[i]-'0');
            i++;
        }

        for(i=0;i<n;i++)
        {
            cout<<"C("<<n<<","<<i<<")"<<"*";
            if(i==0)
                cout<<b<<"^"<<n<<"+";
            else
                cout<<a<<"^"<<i<<"*"<<b<<"^"<<n-i<<"+";
        }
        cout<<"C("<<n<<","<<n<<")*"<<a<<"^"<<n;
        cout<<'\n';
        T--;
    }
    return 0;
}

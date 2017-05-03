#include <iostream>
#include<string.h>
using namespace std;



int main()
{
        int in,sf,inmin,sfmin,lmin=99999,lu,i;
        char s[1001];
        cin.get(s,1000);
        in=0;
        for(i=1;i<strlen(s);i++)
        {
            if(s[i]==' ')
            {
                lu=i-in;
                if(lu<lmin)
                {
                    lmin=lu;
                    inmin=in;
                    sfmin=i-1;
                }
                in=i+1;
            }

        }
        for(i=inmin;i<=sfmin;i++)
            cout<<s[i];
}

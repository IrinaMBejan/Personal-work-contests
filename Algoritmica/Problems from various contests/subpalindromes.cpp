#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[15], a[30001],a2[30001],ch[]="change",y;
int n,m,i,j,x,in,sf,q;

int main()
{
    fscanf("%s",&a);
    fscanf("%d",&n);
    q=strlen(a);
    reverse_copy(a2,a+q,a);
    if(strcmp(a,a2)) printf("YES");
    else printf("NO");
    for(i=1; i<=n; i++)
    {
        scanf("%s %d %d",&s,&x,&y);
        if(strcmp(s,ch))
        {
            a[x]=y;
            reverse_copy(a2,a+q,a);
            if(strcmp(a,a2)) printf("YES");
            else printf("NO");
        }
        else
        {

            reverse_copy(a2,a+y-'0',a+x);
            if(strcmp(a,a2)) printf("YES");
            else printf("NO");

        }




    }

    return 0;
}

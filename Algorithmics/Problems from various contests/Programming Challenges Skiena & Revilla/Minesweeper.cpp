#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm> // std::min, std::max
using namespace std;

short a[105][105];
char c[105][105];
int dl[10]= {-1,-1,0,1,1,1,0,-1};
int dc[10]= {0,1,1,1,0,-1,-1,-1};
int main()
{
    int x, y,i,j,k, counter = 0;
    scanf("%d%d", &x, &y);
    while ( x!=0 || y!=0 )
    {
        counter++;
        for(i = 1; i<=x; i++)
            scanf("%s",c[i]+1);
        memset(a,0,sizeof(a));
        for(i = 1; i<=x; i++)
            for(j = 1; j<=y; j++)
                if(c[i][j] == '*')
                {
                    for(k = 0; k<8; k++)
                        a[i+dl[k]][j+dc[k]] ++;
                }

        if(counter>1)
            cout<<'\n';
        cout<<"Field #"<<counter<<":"<<'\n';
        for(i = 1; i<=x; i++)
        {
            for(j=1; j<=y; j++)
                if(c[i][j] == '*')
                    cout<<"*";
                else cout<<a[i][j]<<"";
            cout<<'\n';
        }
        scanf("%d%d", &x, &y);

    }
    return 0;
}

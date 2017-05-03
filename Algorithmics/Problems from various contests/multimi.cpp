#include <iostream>
#define VMAX 201
using namespace std;

int v1[VMAX],v2[VMAX],inter[2*VMAX];
int main()
{
    int n, i, x,m,p;
    cin>>n>>m;
    cin>>x;
    for(i=1;i<=n;i++)
    {
        cin>>p;
        v1[p]=1;
    }
    int k=0;
    for(i=1;i<=m;i++)
    {
        cin>>p;
        v2[p]=1;
    }
   /* INTERSECTIE
    for(i=0;i<=VMAX;i++)
        inter[i]=(v1[i]&&v2[i]);
*/
    for(i=0;i<=VMAX;i++)
        if(inter[i]) cout<<i<<" ";

  /*  REUNIUNE
    for(i=0;i<=VMAX;i++)
        inter[i]=(v1[i]||v2[i]);
        */
   /* DIFERENTA
    for(i=0;i<=VMAX;i++)
        inter[i]=(v1[i]&&!v2[i]);
   */
   /* APARTENENTA
    if(v1[x]) cout<<"x apartine";
    else cout<<"nu apartine";
    */

    return 0;
}

#include <cstdio>
#include <cmath>
#define Nmax 105
using namespace std;

struct node
{
    int inf;
    node* urm;
};

int n;
typedef node* Lista;
void InsertList(Lista&, Lista, int);
bool GetBit(int nr, int j);
void FindMissingInteger(Lista referenceList, int n);

int main()
{
    int val;
    Lista listRef;
    scanf("%d",&n);
    for(int i = 1; i<=n; i++)
    {
        scanf("%d",&val);
        InsertList(listRef,NULL,val);
    }
    FindMissingInteger(listRef,pow(2,log(n+1)-1));
    return 0;
}

bool GetBit(int nr, int j)
{
    return (nr & 1<<j);
}

void FindMissingInteger(Lista referenceList, int n)
{
    if(n == 1)
    {
        printf("0th bit of missing number is %d", referenceList->inf);
        return;
    }
    Lista leftList, rightList;
    int leftListSize = 0, rightListSize = 0;

    int msbPosition = ceil(log(n+1))-1;

    Lista p = referenceList;
    while(p)
    {
        if(!GetBit(p->inf,msbPosition))
        {
            InsertList(leftList,NULL,p->inf);
            leftListSize++;
        }
        else
        {
            InsertList(rightList,NULL,p->inf);
            rightListSize++;
        }
        p = p->urm;
    }
    int put = pow(2,msbPosition);
    if(leftListSize < put)
    {
        printf("%d bit of missing number is 0",msbPosition);
        FindMissingInteger(leftList,put-1);
    }
    else
    {
        printf("%d bit of missing number is 1",msbPosition);
        FindMissingInteger(rightList,n-put);
    }
}

void InsertList(Lista &L, Lista p, int x)
{
    Lista q = new node;
    q->inf = x;
    if(p==NULL)
    {
        q->urm = L;
        L = q;
    }
    else
    {
        q->urm = p->urm;
        p->urm = q;
    }
}

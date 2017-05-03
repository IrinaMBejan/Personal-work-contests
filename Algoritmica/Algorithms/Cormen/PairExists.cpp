#include <cstdio>
#define NMAX 200

int BinarySearch(int A[], int lg, int v);
bool PairExists(int A[], int n, int S);

int main()
{
    int vec[NMAX], i, n, S;

    scanf("%d%d",&n,&S);
    for(i = 0; i < n; i++)
        scanf("%d",&vec[i]);

    printf("%d\n", PairExists(vec, n, S));
    return 0;
}

bool PairExists(int A[], int n, int S)
{
    int i;
    for(i = 0 ; i < n; i++)
    {
        if(BinarySearch(A,n,S-A[i]))
            return true;
    }
    return false;
}
int BinarySearch(int A[], int lg, int v)
{
    int mid, st  = 0, fi = lg;

    while (st < fi)
    {
        mid = (st + fi) / 2;

        if (A[mid] == v)
            return mid;
        else if (A[mid] < v)
            st = mid + 1;
        else
            fi = mid;
    }

    return -1;
}

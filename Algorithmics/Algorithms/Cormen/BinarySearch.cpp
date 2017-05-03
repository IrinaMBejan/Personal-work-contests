#include <cstdio>
#define NMAX 200

int BinarySearch(int A[], int lg, int v);

int main()
{
    int vec[NMAX], i, n, nr;

    scanf("%d%d",&n,&nr);
    for(i = 0; i < n; i++)
        scanf("%d",&vec[i]);

    printf("%d\n", BinarySearch(vec, n, nr));
    return 0;
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

#include <cstdio>
#define NMAX 200
#define INSERTCONST 20

void Combine(int A[], int st, int m, int fi);
void MixedSort(int A[], int st, int fi);

int main()
{
    int vec[NMAX], i, n;

    scanf("%d",&n);
    for(i = 0; i < n; i++)
        scanf("%d",&vec[i]);
    MixedSort(vec, 0, n-1);

    for(i = 0; i < n; i++)
        printf("%d ",vec[i]);
    return 0;
}

void Combine(int A[], int st, int m, int fi)
{
    int i, j, k, n1 = m - st + 1, n2 = fi - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[st + i];

    for (j = 0; j < n2; j++)
        R[j] = A[m + j + 1];

    for(i = 0, j = 0, k = st; k <= fi; k++)
    {
        if (i == n1)
        {
            A[k] = R[j++];
        }
        else if (j == n2)
        {
            A[k] = L[i++];
        }
        else if (L[i] <= R[j])
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
        }
    }
}

void InsertionSort(int A[], int st, int fi)
{
    int i, j, pivot;

    for (j = st + 1; j <= fi; j++)
    {
        pivot = A[j];
        i = j - 1;
        while (i >= st && A[i] > pivot)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = pivot;
    }
}

void MixedSort(int A[], int st, int fi)
{
    if (st >= fi) return;

    if (fi - st < INSERTCONST)
    {
        InsertionSort(A,st,fi);
    }
    else
    {
        if (st < fi)
        {
            int m = (st + fi) / 2;
            MixedSort(A, st, m);
            MixedSort(A, m + 1, fi);
            Combine(A, st, m, fi);
        }
    }
}

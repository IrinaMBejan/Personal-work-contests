#include <cstdio>
#define NMAX 200

int Combine(int A[], int st, int m, int fi);
int MergeSort(int A[], int st, int fi);

int main()
{
    int vec[NMAX], i, n;

    scanf("%d",&n);
    for(i = 0; i < n; i++)
        scanf("%d",&vec[i]);

    printf("%d ", MergeSort(vec, 0, n-1));
    return 0;
}

int Combine(int A[], int st, int m, int fi)
{
    int i, j, k, n1 = m - st + 1, n2 = fi - m;

    int inversions = 0;

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
            inversions += n1 - i;
        }
    }
    return inversions;
}

int MergeSort(int A[], int st, int fi)
{
    if (st < fi)
    {
        int inversions = 0;
        int m = (st + fi) / 2;
        inversions += MergeSort(A, st, m);
        inversions += MergeSort(A, m + 1, fi);
        inversions += Combine(A, st, m, fi);
        return inversions;
    }
    else
        return 0;
}
